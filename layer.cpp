#include "layer.h"
#include "cnpy.h"

using namespace std;

namespace HENets
{
  Layer::Layer(const vector<int32_t>& shape) : shape(shape)
  {
  }

  Layer::Layer(const vector<int32_t>& shape, const string& path) : shape(shape)
  {
    import_weights(path);
  }

  Layer::~Layer()
  {
  }

  bool Layer::import_weights(const string& path)
  {
    //TODO: add trycatch and return false when file DNE 
    const cnpy::NpyArray weights_npy = cnpy::npy_load(path);
    for(int i=0; i<weights_npy.shape.size(); i++)
      shape.push_back(weights_npy.shape[i]);
    weights = weights_npy.as_vec<double>();
    return true;
  }

  vector<seal::Ciphertext> Layer::inference(const vector<seal::Ciphertext>& input_ct, const seal::SEALContext& context, int slot_count, int scale)
  {
    return vector<seal::Ciphertext>(input_ct);
  }
}
