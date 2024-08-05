#pragma once

#include <stdint.h>

namespace hina {
enum ePhase : const uint32_t {
    ePhaseA = 0,
    ePhaseB = 1,
    ePhaseC = 2,
    ePhaseNum = 3,
};

enum eDir : const int32_t {
    eCW = 1,
    eCCW = -1,
};

struct Param {
    const eDir dir;
    const uint32_t timer_cnt_max = 65535;
    const uint32_t timer_cnt_min = 50;
};
}

