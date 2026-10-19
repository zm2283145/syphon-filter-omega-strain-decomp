/*
 * main/human: range (2 files, 001B4EF0-001B4F40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_001B4EF0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_001B4EF0)
#pragma pop /* merge_units */
/* merge_units: end func_001B4EF0 */

/* merge_units: begin func_001B4F40 */
#pragma push /* merge_units */
#pragma cplusplus on
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
    VPAD8(d) VPAD4(e)
    virtual unsigned char Kind();
};
struct Act {
    char pad0[0xC];
    int wC;
    int w10;
    char pad14[0x2C - 0x14];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x58 - 0x2F];
    Vis* p58;
    char pad5C[0x3268 - 0x5C];
    unsigned char b3268;
    char pad3269[0x3584 - 0x3269];
    void* p3584;
};
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_0049D8D0[];
extern int D_00494178;
extern char g_TargetVisMgr;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
void Alloc_Lock(int);
void Alloc_Unlock(int);
void* Mem_Alloc(int, int, char*, int);
void* func_002D6030(void*, void*, Act*);
void Npc_CreatePhysical(Act*);
void Actor_InitComponents(Act*, int, int, void*);
void func_00392900(Act*);
void Human_ApplyBoundSpheres(Act*);
void Human_ApplyCentroidWeights(Act*);
void TargetVis_Register(char*, Act*);
int Player_GetIndex(int);
void NetGame_InitLocalSlot(int*, int);
void NetMap_BindReceiver(int, int, Act*);
void func_00436C00(int*);
void func_004341F0(int*, int*);
void func_00436BA0(int*, int);
}
static inline bool Ready(Act* a)
{
    return a->b2D && a->b2C && !a->b2E;
}
static inline int LocalId()
{
    int a = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGame_InitLocalSlot(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}
static inline int Fix(int i)
{
    if (i == -1) return LocalId();
    return i;
}
extern "C" void Npc_Enable(Act* a)
{
    int loc;
    int idx;
    if (Ready(a)) return;
    Npc_CreatePhysical(a);
    {
        bool on = 0;
        if (a->p58 && a->p58->IsOn()) on = 1;
        if (!on) {
            Vis* p = a->p58;
            if (!p || (p && p->Kind() != 2)) {
                void* m;
                if (g_ProfileLockEnabled) Alloc_Lock(9);
                g_ProfileLockDepth++;
                m = Mem_Alloc(0, 0x220, D_0049D8D0, 0x4BA);
                if (g_ProfileLockEnabled) Alloc_Unlock(9);
                g_ProfileLockDepth--;
                if (m) m = func_002D6030(m, a->p3584 ? a->p3584 : 0, a);
                Actor_InitComponents(a, 4, 0, m);
            }
        }
    }
    func_00392900(a);
    Human_ApplyBoundSpheres(a);
    Human_ApplyCentroidWeights(a);
    TargetVis_Register(&g_TargetVisMgr, a);
    {
        int w;
        idx = Player_GetIndex(a->wC);
        w = a->w10;
        idx = Fix(idx);
        NetMap_BindReceiver(w, idx, a);
    }
    a->b3268 = 1;
    func_00436C00(&loc);
    func_004341F0(&loc, &a->wC);
    func_00436BA0(&loc, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B4F40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B4F40 */
