#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* Controller_IsEnemyTeam: true when this controller's team treats `other` as an enemy */
typedef struct { unsigned char enemy : 1; unsigned char rest : 7; } Pt1EtRel;
struct Pt1EtCtrl {
    VPAD16(a) VPAD8(b)
    virtual int GetTeam();
};
extern "C" Pt1EtRel (*D_004EE620)[16];
static inline int Pt1Et_IsEnemy(int a, int b)
{
    if (D_004EE620 && a > -1 && a < 16 && b > -1 && b < 16)
        return D_004EE620[a][b].enemy;
    return 0;
}
extern "C" unsigned char func_0022F440(Pt1EtCtrl* c, int other)
{
    unsigned char r = 0;
    if (c->GetTeam() >= 0 && other >= 0)
        r = Pt1Et_IsEnemy(c->GetTeam(), other);
    return r;
}