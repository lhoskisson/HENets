#include "dense.h"

using namespace std;
using namespace seal;

namespace HENets
{
  Dense::Dense(vector<int32_t>& shape) : Layer(shape) {}

  Dense::Dense(vector<int32_t>& shape, const string& weights_file) : Layer(shape, weights_file)
  {
    import_weights(weights_file);
  }

  void Dense::set_network_parms()
  {
  }

  void Dense::prepare_weights()
  {
     
  }

  //currently assuming 1D or 2D input
  //TODO: get slot count and scale from context 
  vector<Ciphertext> Dense::inference(const vector<Ciphertext>& input_ct, const SEALContext& context, int slot_count, int scale)
  {
    //setup seal objects
    Evaluator evaluator(context);
    CKKSEncoder encoder(context);
    KeyGenerator key_gen(context);
    GaloisKeys gal_keys;
    RelinKeys relin_keys;
    key_gen.create_relin_keys(relin_keys);
    key_gen.create_galois_keys(gal_keys);

    int input_size = shape[0];
    int output_size = shape[1];
    int inputs_per_ct = slot_count/input_size; //vector size / input size

    /* GENERAL DENSE LAYER */
    vector<Ciphertext> output_ct(input_ct.size());
    int cur_weight_idx = 0;
    for(int i=0; i<input_ct.size(); i++) //for each ct 
    {
      //calculate the amount of slots used in the given ct
      int slots_used = inputs_per_ct*input_size;
      int dif = 0;
      //         total slots to be used - slots that have been used    < slots per ct
      if((dif = (input_size*output_size)-(i*inputs_per_ct*input_size)) < slot_count) 
        slots_used = dif;	

      //prepare weights
      Plaintext weights_pt;
      vector<double> node_weights(slot_count, 0.0);
      for(int j=cur_weight_idx; j<cur_weight_idx+slots_used; j++) //for each input copy per ct 
      {
	node_weights[j-cur_weight_idx] = weights[j];
      }
      encoder.encode(node_weights, scale, weights_pt);

      //multiplication step
      Ciphertext product_ct;
      evaluator.multiply_plain(input_ct[i], weights_pt, product_ct); 
      evaluator.rescale_to_next_inplace(product_ct);

      //rotation step

    }
    /* DENSE LAYER FOR POWER OF 2 */
    
    //dummy return
    return vector<Ciphertext>();
  }
}
