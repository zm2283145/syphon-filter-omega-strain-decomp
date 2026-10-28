#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

typedef signed char eTravelSpeed;

struct cPathNavigator;

extern "C" {
float cPathNavigator_DistanceToDestination(cPathNavigator* p);
int Libc_Rand(void);
extern float D_00489DF0;
extern eTravelSpeed D_00489DF8[4];
extern eTravelSpeed D_00489E00[4];
extern eTravelSpeed D_00489E08[4];
extern eTravelSpeed D_00489E10[4];
extern eTravelSpeed D_00489E18[4];
}

class cNPC_D730 {
public:
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD1(d)
    virtual void SetActionState(int a, int b);
    VPAD32(e) VPAD2(f)
    virtual float GetTravelSpeed(eTravelSpeed s);
    char pad4[0x60 - 4];
    float travelSpeed;
    int travelSpeedPriority;
    int losCheckFlag;
    float aggressiveness;
    char pad70[0x141 - 0x70];
    unsigned char b0 : 6;
    unsigned char usingPathTravelSpeed : 1;
    unsigned char b7 : 1;
    char pad142[0x1B0 - 0x142];
    cPathNavigator* pathNavigator;

    inline void SetSpeed(float speed, int priority, bool usingPath) {
        if (priority >= travelSpeedPriority) {
            travelSpeed = speed;
            travelSpeedPriority = priority;
            usingPathTravelSpeed = usingPath;
        }
    }
};


extern "C" void cNPC_SelectTravelMode(cNPC_D730* self, int mode)
{
    eTravelSpeed speed = 1;
    float distance = cPathNavigator_DistanceToDestination(self->pathNavigator);
    float p = D_00489DF0 * Libc_Rand();
    float r = self->aggressiveness;
    r += p;
    int i = (int)((r - 0.33f) * distance / 5.0f);
    i = (i > 3) ? 3 : i;
    i = (0 > i) ? 0 : i;
    switch (mode) {
    case 2:
        speed = D_00489DF8[i];
        break;
    case 3:
        speed = D_00489E00[i];
        break;
    case 4:
        speed = D_00489E08[i];
        break;
    case 1:
        speed = D_00489E10[i];
        break;
    case 5:
    case 6:
        speed = D_00489E18[i];
        break;
    }
    self->SetSpeed(self->GetTravelSpeed(speed), 0, 0);
    self->SetActionState(1, 20);
}
