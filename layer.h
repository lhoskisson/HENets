#pragma once

#include "seal/seal.h"

namespace HENets
{
  class Layer
  {
    private:
    std::string type;
    std::vector<int32_t> shape;
    std::vector<double> weights;
    
    public:
    Layer(const std::string& type, const std::vector<int32_t>& shape);
    Layer(const std::string& type, const std::vector<int32_t>& shape, const std::string& weights_file);
    bool import_weights(std::string weights_file);
    virtual std::vector<seal::Ciphertext> inference(const std::vector<seal::Ciphertext>& input_ct, const seal::SEALContext& context); 
  }
}
