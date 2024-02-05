#pragma once

namespace ardent
{
class i_output_pin
{
  public:
    virtual ~i_output_pin() = default;
    virtual void set_high() = 0;
    virtual void set_low() = 0;
};
} // namespace ardent