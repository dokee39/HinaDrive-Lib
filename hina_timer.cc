#include "hina_timer.hpp"
#include "hina_port_timer.hpp"

namespace hina {
__attribute__((weak)) void Timer::Disable()
{
    portDisable();
    repeat_expected_ = 0;
    repeat_ = 0;
    cnt_last_ = 0;
}

__attribute__((weak)) void Timer::Enable(uint32_t cnt)
{
    repeat_expected_ = cnt / param_.timer_cnt_max;
    repeat_ = 0;
    cnt_last_ = cnt % param_.timer_cnt_max;
    if (cnt_last_ < param_.timer_cnt_min) {
        cnt_last_ = param_.timer_cnt_max;
        repeat_expected_ --;  
    }
    portEnable(cnt);
}

__attribute__((weak)) bool Timer::NeedContinue()
{
    repeat_ ++;
    if (repeat_ == repeat_expected_) {
        portEnable(cnt_last_);
        return true;
    } else if (repeat_ > repeat_expected_) {
        portDisable();
        return false;
    } else {
        portEnable(param_.timer_cnt_max);
        return true;
    }
}
uint32_t Timer::cnt() const {
    return portGetCnt() + param_.timer_cnt_max * repeat_;
}
}
