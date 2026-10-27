/*
 * SFOGame/Source/NetLabelMsg: 5 files, 002D2850-002D2AB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D2850 */
#pragma push /* merge_units */
#include "types.h"
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern char D_0051F090[];
extern void cNetLabelMsg_NetLabelMsgCallback(void);
unsigned char cNetLabelMsg_InitNet(void)
{
    struct { long long file; unsigned char a; int b; int c; int d; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart() == 0 && cMessage_RegisterFields(&L.file) &&
        NetMessageField(&L.file, &L.a, 1, 1) == 0 &&
        NetMessageField(&L.file, &L.b, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.c, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.d, 4, 1) == 0 &&
        NetRegisterMessage(D_0051F090, 2, cNetLabelMsg_NetLabelMsgCallback) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_func_002D2850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2850 */

/* merge_units: begin func_002D2920 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; int flags; char pad2[4]; int a; signed char b; char pad3[3]; int c; int d; } Ev2920;
typedef struct { char pad[8]; signed char b; char pad2[3]; int a; int c; int d; } Buf2920;
#if 0 /* merge_units */
extern int D_0051F090;
#endif /* merge_units */
#define D_0051F090 (*(int*)&D_0051F090) /* merge_units */

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
#undef D_0051F090 /* merge_units */
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
extern char* nGobjManager_LookupGOBJ_cObjectIdR(unsigned short* id);
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
