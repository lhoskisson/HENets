#pragma once

#include "layer.h"

namespace HENets
{
  class Conv2D : public Layer
  {
    public:
    Conv2D(std::vector<int32_t> dimensions);
    std::vector<seal::Ciphertext> inference(const std::vector<seal::Ciphertext>& input_ct, const seal::SEALContext& context);
  }
}
