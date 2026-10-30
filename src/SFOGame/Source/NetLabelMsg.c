/*
 * SFOGame/Source/NetLabelMsg: 7 files, 002D2530-002D2850
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

/* merge_units: begin func_002D2850 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern int D_0051F090;
#if 0 /* merge_units */
extern int cNetLabelMsg_NetLabelMsgCallback(void*, void*, void*, void*);
#endif /* merge_units */
#define cNetLabelMsg_NetLabelMsgCallback(a0, a1, a2, a3) (cNetLabelMsg_NetLabelMsgCallback((a0), (a1), (a2), (a3))) /* merge_units */

unsigned char cNetLabelMsg_InitNet(void)
{
    struct { long long file; unsigned char a; int b; int c; int d; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart() == 0 && cMessage_RegisterFields(&L.file) &&
        NetMessageField(&L.file, &L.a, 1, 1) == 0 &&
        NetMessageField(&L.file, &L.b, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.c, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.d, 4, 1) == 0 &&
        NetRegisterMessage(&D_0051F090, 2, cNetLabelMsg_NetLabelMsgCallback) == 0)
        ok = 1;
    return ok;
}
#undef cNetLabelMsg_NetLabelMsgCallback /* merge_units */
static inline void merge_flush_func_002D2850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2850 */

/* merge_units: begin func_002D2920 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; int flags; char pad2[4]; int a; signed char b; char pad3[3]; int c; int d; } Ev2920;
typedef struct { char pad[8]; signed char b; char pad2[3]; int a; int c; int d; } Buf2920;

extern void Event_PackHeader(Ev2920* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
int cNetLabelMsg_Pack(Ev2920* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf)
{
    int r = -1;
    if (size >= 0x18 && buf) {
        Buf2920* b = (Buf2920*)buf;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        b->a = e->a; b->b = e->b; b->c = e->c; b->d = e->d;
        e->flags = 0x40;
        if (type) { r = 0x18; *type = D_0051F090; }
    }
    return r;
}
static inline void merge_flush_func_002D2920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2920 */

/* merge_units: begin func_002D29C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned char b14; } C2D29C0;
typedef struct { char pad[0x30]; C2D29C0* x30; } M2D29C0;
typedef struct { char pad[0x58]; M2D29C0* x58; } A2D29C0;
typedef struct { char pad[0xC]; unsigned short hC; } D2D29C0;
typedef struct { char pad[0x30]; D2D29C0* x30; char pad34[0x150 - 0x34]; unsigned short id; } S2D29C0;
typedef struct { char pad[0x30]; char x30[4]; } X2D29C0;
typedef struct { char* p; int n; } B2D29C0;
extern A2D29C0* cNPC_Human(S2D29C0* s, X2D29C0* x);
extern void cNPC_RemoveFromActiveList(D2D29C0* d);
#if 0 /* merge_units */
extern char* nGobjManager_LookupGOBJ_cObjectIdR(unsigned short* id);
#endif /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((char *)nGobjManager_LookupGOBJ_cObjectIdR((int *)(a0))) /* merge_units */

extern void cHuman_CreateGobjController(A2D29C0* a, int n, B2D29C0* b, int c);
extern void func_00148CD0(M2D29C0* m, void* p);
void func_002D29C0(S2D29C0* s, X2D29C0* x)
{
    A2D29C0* a;
    void* p = x->x30;
    a = cNPC_Human(s, x);
    cNPC_RemoveFromActiveList(s->x30);
    if (s->id) {
        B2D29C0 b;
        char* o = nGobjManager_LookupGOBJ_cObjectIdR(&s->id);
        b.n = s->x30->hC - 1;
        b.p = o + 0xC;
        cHuman_CreateGobjController(a, 2, &b, 0);
    } else {
        cHuman_CreateGobjController(a, 2, 0, 0);
    }
    {
        M2D29C0* m = a->x58;
        m->x30->b14 = 1;
        func_00148CD0(m, p);
    }
}
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
static inline void merge_flush_func_002D29C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D29C0 */

/* merge_units: begin func_002D2A80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cNetNPC_GetControllerType(void) {
    return 2;
}

int cNetNPC_IsPlayer(void) {
    return 0;
}

int cNetNPC_IsNPC(void) {
    return 0;
}
static inline void merge_flush_func_002D2A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2A80 */

/* merge_units: begin func_002D2AB0 */
#pragma push /* merge_units */
/* Returns 1 when the attached object's flag bytes 0x2D and 0x2C are set and 0x2E is clear. */
typedef struct { char p0[0x2C]; unsigned char b2C, b2D, b2E; } C2D2AB0;
typedef struct { char p0[0x60]; C2D2AB0* c; } B2D2AB0;
typedef struct { char p0[0x1E8]; B2D2AB0* b; } A2D2AB0;
#pragma push
#pragma optimization_level 1
#pragma schedule on
unsigned char cNetNPC_IsNodeInActiveTerrain(A2D2AB0* a)
{
    B2D2AB0* b = a->b;
    if (b) {
        C2D2AB0* c;
        unsigned char r;
        r = 0;
        c = b->c;
        if (c) { int ok = c->b2D && c->b2C && !c->b2E; if (ok) r = 1; }
        return r;
    }
    return 0;
}
#pragma pop
static inline void merge_flush_func_002D2AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2AB0 */
