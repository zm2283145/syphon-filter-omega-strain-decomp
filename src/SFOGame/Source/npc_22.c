/*
 * SFOGame/Source/npc: 4 files, 0014D610-0014D730
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014D610 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"

#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cAIMessage_dtor, D_004D9340, cMessage_dtor)
static inline void merge_flush_func_0014D610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D610 */

/* merge_units: begin func_0014D670 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; float x60; } NpcB1;
int cNPC_GetTravelSpeed_void(NpcB1* n) {
    float f = n->x60;
    int r;
    if (f >= 0.0005f) {
        if (f < 0.25f) r = 1;
        else if (f > 0.75f) r = 3;
        else r = 2;
    } else r = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D670(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D670 */

/* merge_units: begin func_0014D6F0 */
#pragma push /* merge_units */
typedef struct {
    char pad[0x60];
    float value;
    int level;
    char pad2[0x141 - 0x68];
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 1;
    unsigned char flag5 : 1;
    unsigned char flag6 : 1;
    unsigned char flag7 : 1;
} cNPC;

/* cNPC virtual slot 0x4E: when level <= 100, stores v, sets level to 100 and clears flag bit 6 at +0x141. */
void cNPC_SetTravelSpeed(cNPC* npc, float v)
{
    if (npc->level <= 100) {
        npc->value = v;
        npc->level = 100;
        npc->flag6 = 0;
    }
}
static inline void merge_flush_func_0014D6F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D6F0 */

/* merge_units: begin func_0014D730 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_0014D730(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D730 */
