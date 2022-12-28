#pragma once

#include "seal/seal.h"

namespace HENets
{
  class Layer
  {
    protected:
    std::vector<int32_t> shape;
    std::vector<double> weights;
    
    public:
    Layer(const std::vector<int32_t>& shape);
    Layer(const std::vector<int32_t>& shape, const std::string& weights_file);
    virtual ~Layer();
    bool import_weights(const std::string& path);
    //virtual void set_network_parms();
    //virtual void prepare_weights();
    virtual std::vector<seal::Ciphertext> inference(const std::vector<seal::Ciphertext>& input_ct, const seal::SEALContext& context, int slot_count, int scale); 
  };
}
