#pragma once

#include "hina_port_hardware.hpp"

namespace hina {
class Timer final {
public:
    explicit Timer(portHardware &hardware, Param &param):
        hardware_(hardware), 
        param_(param) {
    }
    Timer() = delete;
    ~Timer() = default;
    Timer(const Timer&) = delete; // not copyable or movable
    Timer& operator=(const Timer&) = delete; // not copyable or movable

    void Disable();
    void Enable(uint32_t cnt);
    bool NeedContinue();
    uint32_t cnt() const;

private:
    portHardware &hardware_;
    Param &param_;
    uint32_t cnt_last_ = 0;
    uint32_t repeat_ = 0;
    uint32_t repeat_expected_ = 0;

    inline void portDisable();
    inline void portEnable(uint32_t cnt);
    inline uint32_t portGetCnt() const;
};
}
