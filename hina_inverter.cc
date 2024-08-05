#include "hina_inverter.hpp"
#include "hina_port_inverter.hpp"

namespace hina {
__attribute__((weak)) void Inverter::FloatAll(void)
{
    portSetDuty(0, 0, 0);
    portSetFloat(ePhaseA);
    portSetFloat(ePhaseB);
    portSetFloat(ePhaseC);
}

__attribute__((weak)) void Inverter::Brake(void)
{
    portSetDuty(0, 0, 0);
    portUnsetFloat(ePhaseA);
    portUnsetFloat(ePhaseB);
    portUnsetFloat(ePhaseC);
}

__attribute__((weak)) void Inverter::SixStepChangePhase(int32_t &step)
{
    Brake();
    
    step += param_.dir;
    if (step < 0) {
        step = 5;
    } else if (step > 5) {
        step = 0;
    }

    portSetFloat(six_step[step].float_phase);
}

__attribute__((weak)) void Inverter::SixStepSetDuty(int32_t &step, float duty)
{
    portSetDuty(six_step[step].upper_on_phase, duty);
}
}
