/*
 * main/gameGobjController: range (2 files, 0022F2D0-0022F340)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "npc_auth.h"
#include "vslot_pad.h"

/* merge_units: begin func_0022F2D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; char pad34[4]; float skill; } Npc0022F2D0;
void cNPC_SetSkill(Npc0022F2D0* self, float skill)
{
    self->skill = skill;
    if (g_IsMultiplayer && NpcAuth_IsLocal())
        NetEvent_Send(self->net, 0x37, 4, *(volatile int*)&skill, 0, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022F2D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022F2D0 */

/* merge_units: begin func_0022F340 */
#pragma push /* merge_units */
#pragma cplusplus on
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022F340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022F340 */
