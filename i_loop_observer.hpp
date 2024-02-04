#pragma once

namespace ardent
{
    class i_loop_observer
    {
    public:
        virtual ~i_loop_observer() = default;
        virtual void update() = 0;
    };
}