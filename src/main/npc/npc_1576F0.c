/*
 * main/npc: range (6 files, 001576F0-00157A40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_001576F0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cNetTerrainActivation_dtor, D_004E0F00, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001576F0 */

/* merge_units: begin func_00157750 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cDeactivateMsg_dtor, D_004E0E80, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00157750 */

/* merge_units: begin func_001577B0 */
#pragma push /* merge_units */
#pragma cplusplus on
class NPC_77B0 {
public:
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d)
    virtual void Reset();
};
extern "C" void NpcAi_GetPlayerRecord(NPC_77B0* self, int a, int b);
extern "C" int cNPC_GetEnabled(NPC_77B0* self, int a);
extern "C" void cNPC_v2F(NPC_77B0* self, int a)
{
    NpcAi_GetPlayerRecord(self, a, 0);
    if (!cNPC_GetEnabled(self, -1))
        self->Reset();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001577B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001577B0 */

/* merge_units: begin func_00157800 */
#pragma push /* merge_units */
#pragma cplusplus on
class G3Sub157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(); virtual int IsB();
};
class G3Ctl157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void SetActive(int on);
};
class G3Npc157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual int IsAlive();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47();
    virtual void Activate(int v);
    char pad4[0x2C];
    G3Ctl157* ctl;
};
typedef struct { char pad[0xC]; unsigned int id; char pad10[0x48]; G3Sub157* sub; } G3Gen157;
extern "C" {
extern unsigned char g_IsMultiplayer;
void cNPCInfoObject_ctor(int* t);
int cNPCInfoObject_GetOwner_cObjectIdR(int* t, unsigned int* id);
void cNPCInfoObject_dtor(int* t, int f);
}
static inline unsigned char G3IsA(G3Gen157* g) { unsigned char r = 0; if (g->sub && g->sub->IsA()) r = 1; return r; }
static inline unsigned char G3IsB(G3Gen157* g) { unsigned char r = 0; if (g->sub && g->sub->IsB()) r = 1; return r; }
extern "C" void NpcAi_ActivateForPlayer(G3Npc157* n, G3Gen157* g)
{
    if (g_IsMultiplayer) {
        if (n->IsAlive()) {
            int v = -1;
            if (g) {
                if (G3IsA(g) || G3IsB(g)) {
                    int tmp[1];
                    cNPCInfoObject_ctor(tmp);
                    v = cNPCInfoObject_GetOwner_cObjectIdR(tmp, &g->id);
                    cNPCInfoObject_dtor(tmp, -1);
                } else {
                    v = ((g->id & 0x7F000000) >> 24) - 1;
                }
            }
            n->Activate(v);
        }
    } else {
        n->ctl->SetActive(1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00157800(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00157800 */

/* merge_units: begin func_00157940 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern int D_00494178;
extern int D_005721A8;
#if 0 /* merge_units */
int cNPC_GetEnabled(void* self, int a);
#endif /* merge_units */
#define cNPC_GetEnabled(a0, a1) (cNPC_GetEnabled((NPC_77B0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void NpcAi_GetPlayerRecord(void* self, int a, int b);
#endif /* merge_units */
#define NpcAi_GetPlayerRecord(a0, a1, a2) (NpcAi_GetPlayerRecord((NPC_77B0 *)(a0), (a1), (a2))) /* merge_units */

void NetGame_InitLocalSlot(int* p, int v);
void cNetObjectMgr_AddActivate(void* ctl, int v);
}
typedef struct { char pad[0xC]; unsigned int flags; } Obj_7940;
class NPC_7940 {
public:
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d)
    virtual Obj_7940* GetBody();
    char pad[0x2C];
    void* ctl;
};
static inline int DefaultBody()
{
    int a = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGame_InitLocalSlot(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}
extern "C" void NpcAi_ActivateMultiplayer(NPC_7940* self, int v)
{
    int r = cNPC_GetEnabled(self, -1);
    if (v >= 0) {
        NpcAi_GetPlayerRecord(self, v, 1);
    } else {
        Obj_7940* o;
        NpcAi_GetPlayerRecord(self, -1, 1);
        o = self->GetBody();
        if (o) {
            v = ((o->flags & 0x7F000000) >> 24) - 1;
        } else {
            v = DefaultBody();
        }
    }
    if (!r)
        cNetObjectMgr_AddActivate(self->ctl, v);
}
#undef cNPC_GetEnabled /* merge_units */
#undef NpcAi_GetPlayerRecord /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00157940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00157940 */

/* merge_units: begin func_00157A40 */
#pragma push /* merge_units */
#pragma cplusplus on
/* NpcAi_IsAliveOrEligible: false while the actor is in state 2/3 and the NPC is busy */
struct Pt1SbActor {
    VPAD32(a) VPAD32(b)
    virtual unsigned char GetMoveState();
};
struct Pt1SbNpc {
    VPAD32(a) VPAD32(b) VPAD16(c) VPAD4(d) VPAD2(e) VPAD1(f)
    virtual int IsBusy();
    char pad4[0x30 - 4];
    Pt1SbActor* actor;
};
static inline unsigned char Pt1Sb_Moving(Pt1SbNpc* n)
{
    unsigned char s = n->actor->GetMoveState();
    return s == 2 || s == 3;
}
static inline int Pt1Sb_Not(bool x) { return x ^ 1; }
static inline int Pt1Sb_NotI(int x) { return (x != 0) ^ 1; }
extern "C" unsigned char NpcAi_IsAliveOrEligible(Pt1SbNpc* n)
{
    unsigned char r = 1;
    if (!Pt1Sb_Not(Pt1Sb_Moving(n)))
        if (!Pt1Sb_NotI(n->IsBusy()))
            r = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00157A40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00157A40 */
