#include "hina_zero_cross_detector.hpp"
#include "hina_port_zero_cross_detector.hpp"

namespace hina {
__attribute__((weak)) void ZeroCrossDetector::Select(ePhase phase, eMode mode)
{
    portSelect(phase, mode);
}

__attribute__((weak)) void ZeroCrossDetector::EnableAll()
{
    portEnableAll();
}

__attribute__((weak)) void ZeroCrossDetector::Disable()
{
    portDisable();
}
}

