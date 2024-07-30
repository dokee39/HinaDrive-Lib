#pragma once

#include "hina_param.hpp"
#include "hina_port_hardware.hpp"

namespace hina {
class Inverter final {
public:
    explicit Inverter(const Param &param, const portHardware &hardware):
        hardware_(hardware),
        param_(param) {
    }
    Inverter() = delete;
    ~Inverter() = default;
    Inverter(const Inverter&) = delete; // not copyable or movable
    Inverter& operator=(const Inverter&) = delete; // not copyable or movable

    void FloatAll(void);
    void Brake(void);
    void SixStepChangePhase(int32_t &step);
    void SixStepSetDuty(int32_t &step, float duty);
    // void Spwm();
    // void Svpwm();
    
private:
    struct SixStep {
        ePhase upper_on_phase;
        ePhase lower_on_phase;
        ePhase float_phase;
    };

    static constexpr SixStep six_step[6] = {
        { ePhaseA, ePhaseC, ePhaseB },
        { ePhaseA, ePhaseB, ePhaseC },
        { ePhaseC, ePhaseB, ePhaseA },
        { ePhaseC, ePhaseA, ePhaseB },
        { ePhaseB, ePhaseA, ePhaseC },
        { ePhaseB, ePhaseC, ePhaseA },
    };

    const portHardware &hardware_;
    const Param &param_;

    inline void portSetFloat(ePhase phase);
    inline void portUnsetFloat(ePhase phase);
    inline void portSetDuty(ePhase phase, float duty);
    inline void portSetDuty(float duty_a, float duty_b, float duty_c);
    inline float portGetDuty(ePhase phase);
};
}

