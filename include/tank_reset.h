#ifndef TANK_RESET_H
#define TANK_RESET_H

/*
 * cTank reset: reset the tank's controller (+0x60, virtual slot 0x11C)
 * and clear the turret's aim target (+0x6C -> +0x64) when present.
 * C++ only (#pragma cplusplus on before including).
 */
#include "vslot_pad.h"

class TankResetPart {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD1(d)
    virtual void Reset();
};

struct TankResetAim { char pad[0x64]; int target; };

struct TankResetTank {
    char pad[0x60];
    TankResetPart* part;
    char pad64[8];
    TankResetAim* aim;
};

static inline void TankReset_Do(TankResetTank* t)
{
    t->part->Reset();
    if (t->aim)
        t->aim->target = 0;
}

#endif /* TANK_RESET_H */