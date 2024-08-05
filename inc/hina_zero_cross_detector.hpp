#pragma once

#include "hina_param.hpp"
#include "hina_port_hardware.hpp"

namespace hina {
class ZeroCrossDetector final {
public:
    explicit ZeroCrossDetector(portHardware &hardware):
        hardware_(hardware) {
    }
    ZeroCrossDetector() = delete;
    ~ZeroCrossDetector() = default;
    ZeroCrossDetector(const ZeroCrossDetector&) = delete; // not copyable or movable
    ZeroCrossDetector& operator=(const ZeroCrossDetector&) = delete; // not copyable or movable

    enum eMode {
        eUp,
        eDown,
        eUpDown,
    };

    void Select(ePhase phase, eMode mode);
    void EnableAll();
    void Disable();

private:
    portHardware &hardware_;

    inline void portSelect(ePhase phase, eMode mode);
    inline void portEnableAll();
    inline void portDisable();
};
}

