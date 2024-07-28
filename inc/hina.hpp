#pragma once

#include "hina_port_hardware.hpp"
#include "hina_param.hpp"
#include "hina_driver.hpp"

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
    enum eStatus : uint32_t {
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

    eStatus status_;

    Inverter inverter_;

    float speed_;

    void set_speed(const float speed) {
        speed_ = speed;
    }
};
}

