#pragma once

#include "hina_port_hardware.hpp"
#include "hina_param.hpp"
#include "hina_inverter.hpp"
#include "hina_timer.hpp"
#include "hina_zero_cross_detector.hpp"

namespace hina {
class MotorBase {
public:
    explicit MotorBase() = default;
    MotorBase(const MotorBase&) = delete; // not copyable or movable
    MotorBase& operator=(const MotorBase&) = delete; // not copyable or movable

    float speed() const {
        return speed_;
    }

protected:
    ~MotorBase() = default;

private:
    enum eStatus : const uint32_t {
        eInit = 0, 
        eReady,
        eDetect,
        eAlign,
        eStart,
        eRun,
        eBlocked,
        eStop,
        eFault,
    };

    const portHardware &hardware;
    
    const Param &param_;

    eStatus status_;

    Inverter inverter_;

    float speed_ = 0.0f;

    void set_speed(const float speed) {
        speed_ = speed;
    }
};
}

