#pragma once

#include "hina_param.hpp"
#include "hina_port_hardware.hpp"

namespace hina {
class Inverter final {
public:
    explicit Inverter(const portHardware &hardware):
        hardware(hardware) {
    }
    Inverter() = delete;
    ~Inverter() = default;
    Inverter(const Inverter&) = delete; // not copyable or movable
    Inverter& operator=(const Inverter&) = delete; // not copyable or movable

    void FloatAll(void);
    void Brake(void);
    void SixStepChangePhase(uint32_t step);
    void SixStepSetDuty(float duty);
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

    const portHardware &hardware;

    inline void portSetFloat(ePhase phase);
    inline void portSetDuty(ePhase phase, float duty);
    inline void portSetDuty(float duty_a, float duty_b, float duty_c);
    inline float portGetDuty(ePhase phase);
};
}

