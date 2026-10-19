/*
 * main/npc: range (2 files, 001573D0-00157510)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_001573D0 */
#pragma push /* merge_units */
#pragma cplusplus on
class G2Sub157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(); virtual int IsB();
};
class G2Ctl157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void SetActive(int on);
};
class G2Npc157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void Deactivate(int v);
    char pad4[0x2C];
    G2Ctl157* ctl;
    char pad34[0x141 - 0x34];
    unsigned char lo : 7;
    unsigned char dead : 1;
};
typedef struct { char pad[0xC]; unsigned int id; char pad10[0x48]; G2Sub157* sub; } G2Gen157;
extern "C" {
extern unsigned char g_IsMultiplayer;
void func_00436C00(int* t);
int func_00434440(int* t, unsigned int* id);
void func_00436BA0(int* t, int f);
}
static inline unsigned char G2IsA(G2Gen157* g) { unsigned char r = 0; if (g->sub && g->sub->IsA()) r = 1; return r; }
static inline unsigned char G2IsB(G2Gen157* g) { unsigned char r = 0; if (g->sub && g->sub->IsB()) r = 1; return r; }
extern "C" void cNPC_Deactivate(G2Npc157* n, G2Gen157* g)
{
    if (n->dead) return;
    if (g_IsMultiplayer) {
        int v = -1;
        if (g) {
            if (G2IsA(g) || G2IsB(g)) {
                int tmp[1];
                func_00436C00(tmp);
                v = func_00434440(tmp, &g->id);
                func_00436BA0(tmp, -1);
            } else {
                v = ((g->id & 0x7F000000) >> 24) - 1;
            }
        }
        n->Deactivate(v);
    } else {
        n->ctl->SetActive(1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001573D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001573D0 */

/* merge_units: begin func_00157510 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { void* vt; char pad04[0x2C]; } Msg1_7510;
typedef struct { void* vt; char pad04[0x20]; int f24; signed char b28; char pad29[7]; } Msg2_7510;
extern "C" {
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_0055C780[];
extern char D_00572198[];
extern char D_00582760[];
extern char D_004E0E80[];
extern char D_004E0F00[];
void NpcAi_GetPlayerRecord(void* self, int a, int b);
void NetGame_InitLocalSlot(int* p, int v);
void NetObjectMgr_Remove(void* o);
void func_00429200(void* m, int a, int b);
void Event_Construct(void* m, void* type);
void Transport_Send(int a, void* m, int b, int c);
void cMessage_dtor(void* m, int f);
}
class Body_7510 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void SetActive(int on);
    VPAD4(d) VPAD2(e)
    virtual int IsLocal();
    char pad[0x8];
    int cC;
    char pad10[0x1C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
};
typedef struct { char pad[0x30]; Body_7510* body; } Npc_7510;
static inline int LocalId_7510(void)
{
    int a = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGame_InitLocalSlot(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}
static inline bool CanActivate_7510(Body_7510* b) { return b->b2D && b->b2C && !b->b2E; }
extern "C" void NpcAi_DeactivateAnon(Npc_7510* self)
{
    Body_7510* b;
    int i;
    unsigned char* p;
    NpcAi_GetPlayerRecord(self, -1, 0);
    b = self->body;
    if (CanActivate_7510(b))
        b->SetActive(1);
    NetObjectMgr_Remove(self->body);
    if (!self->body->IsLocal()) {
        for (i = 0, p = D_0055C780; i < 4; i++, p++) {
            if (*p == 2) {
                if (i != LocalId_7510()) {
                    Msg1_7510 m1;
                    Msg2_7510 m2;
                    Event_Construct(&m1, D_00572198);
                    m1.vt = D_004E0E80;
                    func_00429200(&m1, self->body->cC, i);
                    m1.vt = D_004E0E80;
                    cMessage_dtor(&m1, 0);
                    Event_Construct(&m2, D_00582760);
                    m2.vt = D_004E0F00;
                    m2.f24 = -1;
                    m2.b28 = 1;
                    Transport_Send(self->body->cC, &m2, -1, i);
                    m2.vt = D_004E0F00;
                    cMessage_dtor(&m2, 0);
                }
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00157510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00157510 */
