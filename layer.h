#pragma once

#include "seal/seal.h"

namespace HENets
{
  class Layer
  {
    private:
    std::vector<int32_t> shape;
    std::vector<double> weights;
    std::vector<seal::Plaintext> weights_pt;
    
    public:
    Layer(const std::vector<int32_t>& shape);
    Layer(const std::vector<int32_t>& shape, const std::string& weights_file);
    bool import_weights(std::string weights_file);
    virtual void set_network_parms();
    virtual void prepare_weights();
    virtual std::vector<seal::Ciphertext> inference(const std::vector<seal::Ciphertext>& input_ct, const seal::SEALContext& context, int slot_count, int scale); 
  }
}
