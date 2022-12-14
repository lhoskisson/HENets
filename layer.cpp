#include "layer.h"
#include "cnpy.h"

using namespace std;

namespace HENets
{
  Layer::Layer(const vector<int32_t>& shape) : type(type), shape(shape)
  {
  }

  Layer::Layer(const vector<int32_t>& shape, const string& path) : type(type), shape(shape)
  {
    import_weights(weights_file);
  }

  bool Layer::import_weights(const string& path);
  {
    const cnpy::NpyArray weights_npy = cnpy::npy_load(path);
    shape = weights_npy.shape;
    weights = weights_npy.as_vec<double>();
  }

  vector<seal::Ciphertext> Layer::inference(const vector<seal::Ciphertext>& input_ct, const seal::SEALContext& context, int slot_count, int scale); 
  {
    return vector<seal::Ciphertext>(input_ct);
  }
}
