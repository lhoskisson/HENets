#pragma once

#include "layer.h"

namespace HENets
{
  class Dense : public Layer
  {
    private:
    
    public:
    Dense(std::vector<int32_t>& shape);
    Dense(std::vector<int32_t>& shape, const std::string& weights_file);
    void set_network_parms();
    void prepare_weights();
    std::vector<seal::Ciphertext> inference(const std::vector<seal::Ciphertext& input_ct, const seal::SEALContext& context, int slot_count, int scale);
  }
}
