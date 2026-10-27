/*
 * SFOGame/Source/NetLabelMsg: 2 files, 002D2530-002D2650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D2530 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DE280[];
}
struct Msg2530 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; int i; signed char j; char p2[3]; int k; int l; };
extern "C" Msg2530* cNetLabelMsg_Clone(Msg2530* src)
{
    Msg2530* p;
    {
        AllocGuard guard;
        p = (Msg2530*)cMemMan_Allocate(0, 0x34, "NetLabelMsg.hh", 0x2A);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->a = src->a;
        p->b = src->b;
        p->c = src->c;
        p->d = src->d;
        p->e = src->e;
        p->f = src->f;
        p->g = src->g;
        p->h = src->h;
        p->vtable = D_004DE280;
        p->i = src->i;
        p->j = src->j;
        p->k = src->k;
        p->l = src->l;
    }
    return p;
}
static inline void merge_flush_func_002D2530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2530 */

/* merge_units: begin func_002D2650 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } Msg_2D2650;
typedef struct { char pad0[8]; signed char b8; char pad9[3]; int wC; int k10; int k14; } Pkt_2D2650;
extern "C" {
extern unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern char D_0051F098[];
extern void cMessage_ctor_cMessageNameR(Msg_2D2650* m, void* type);
extern void cMessage_dtor(Msg_2D2650* m, int f);
extern char* nGlobalization_GetStringTag(int);
extern void* ObjMan_GetService(void);
extern void cObjectiveMan_SetDisplayLabel(void* mgr, char* key, void* obj, int quiet);
extern void* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
extern void nHudTargets_AddHudObjective(void* obj, char* a, char* b, int c);
extern void nGameSound_AddPDAQuip(char* name, char* text0, int silent);
}
/* scoped re-entrancy flag; the out-of-line dtor copy is dropped like AllocGuard's (see alloc_guard.h) */
#pragma define_section GUARD_2D2650_DTOR ".dtors_drop" far_absolute RX
struct Guard_2D2650 {
    Guard_2D2650() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(GUARD_2D2650_DTOR) ~Guard_2D2650() { D_005723C8 = 0; }
};
static inline char* Name_2D2650(int id) { return id != -1 ? nGlobalization_GetStringTag(id) : 0; }

extern "C" int cNetLabelMsg_NetLabelMsgCallback(void* a0, void* a1, void* a2, void* data)
{
    Guard_2D2650 g;
    if (D_005721D0) {
        Pkt_2D2650* pkt = (Pkt_2D2650*)data;
        Msg_2D2650 m;
        cMessage_ctor_cMessageNameR(&m, D_0051F098);
        m.vt = D_004DE280;
        m.w24 = pkt->wC;
        m.b28 = pkt->b8;
        m.key0 = pkt->k10;
        m.key1 = pkt->k14;
        switch ((unsigned char)m.b28) {
        case 0:
            cObjectiveMan_SetDisplayLabel(ObjMan_GetService(), Name_2D2650(m.key0), 0, 1);
            break;
        case 1: {
            int id = m.w24;
            void* obj = nGobjManager_LookupGOBJ_cObjectIdR(&id);
            if (obj) {
                nHudTargets_AddHudObjective(obj, Name_2D2650(m.key0), Name_2D2650(m.key1), 1);
            }
            break;
        }
        case 2:
            nGameSound_AddPDAQuip(Name_2D2650(m.key0), Name_2D2650(m.key1), 1);
            break;
        }
        m.vt = D_004DE280;
        cMessage_dtor(&m, 0);
    }
    return 0x18;
}
static inline void merge_flush_func_002D2650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2650 */
