#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* Controller_IsEnemy: true when this controller's team treats `other`'s team as an enemy */
typedef struct { unsigned char enemy : 1; unsigned char rest : 7; } IsEnRel;
struct IsEnCtrl {
    VPAD16(a) VPAD8(b)
    virtual int GetTeam();
};
extern "C" IsEnRel (*D_004EE620)[16];
extern "C" int Controller_NotifySeen(void* other);
static inline int IsEn_IsEnemy(int a, int b)
{
    if (D_004EE620 && a > -1 && a < 16 && b > -1 && b < 16)
        return D_004EE620[a][b].enemy;
    return 0;
}
extern "C" unsigned char Controller_IsEnemy(IsEnCtrl* c, void* other)
{
    unsigned char r = 0;
    if (c->GetTeam() >= 0 && other && Controller_NotifySeen(other) >= 0) {
        int t = Controller_NotifySeen(other);
        r = IsEn_IsEnemy(c->GetTeam(), t);
    }
    return r;
}
