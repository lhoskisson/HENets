#pragma once

#include "layer.h"

namespace HENets
{
  class Dense : public Layer
  {
    public:
    Dense(std::vector<int32_t> dimensions);
    std::vector<seal::Ciphertext> inference(const std::vector<seal::Ciphertext& input_ct, const seal::SEALContext& context);
  }
}
