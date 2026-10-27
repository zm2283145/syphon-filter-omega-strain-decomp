/*
 * SFOGame/Source/NetNPC: 4 files, 002D5EE0-002D6250
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D5EE0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x14]; unsigned char b14; } C2D5EE0;
typedef struct { char pad[0x30]; C2D5EE0* x30; } M2D5EE0;
typedef struct { char pad[0x58]; M2D5EE0* x58; } A2D5EE0;
typedef struct { char pad[0xC]; unsigned short hC; } D2D5EE0;
typedef struct { char pad[0x30]; D2D5EE0* x30; char pad34[0x150 - 0x34]; unsigned short id; } S2D5EE0;
typedef struct { char pad[0x30]; char x30[4]; } X2D5EE0;
typedef struct { char* p; int n; } B2D5EE0;
extern A2D5EE0* cNPC_Human(S2D5EE0* s, X2D5EE0* x);
extern void cNPC_RemoveFromActiveList(D2D5EE0* d);
extern char* nGobjManager_LookupGOBJ_cObjectIdR(unsigned short* id);
extern void cHuman_CreateGobjController(A2D5EE0* a, int n, B2D5EE0* b, int c);
extern void func_00148CD0(M2D5EE0* m, void* p);
void cNetNPC_ConvertToNpc(S2D5EE0* s, X2D5EE0* x)
{
    A2D5EE0* a = cNPC_Human(s, x);
    cNPC_RemoveFromActiveList(s->x30);
    if (s->id) {
        B2D5EE0 b;
        char* o = nGobjManager_LookupGOBJ_cObjectIdR(&s->id);
        b.n = s->x30->hC - 1;
        b.p = o + 0xC;
        cHuman_CreateGobjController(a, 2, &b, 0);
    } else {
        cHuman_CreateGobjController(a, 2, 0, 0);
    }
    {
        M2D5EE0* m = a->x58;
        m->x30->b14 = 1;
        func_00148CD0(m, x);
    }
}
static inline void merge_flush_func_002D5EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D5EE0 */

/* merge_units: begin func_002D5FA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct Npc2D5FA0 { VPAD16(a) VPAD1(b) virtual void Release(); char pad[0x14C]; int f150; char p154[5]; unsigned char b159; };
extern "C" {
extern char D_004DE2A0[];
void cNPC_dtor(Npc2D5FA0* p, int f);
void operator_delete(void* p);
}
extern "C" Npc2D5FA0* cNetNPC_dtor(Npc2D5FA0* self, short del)
{
    if (self) {
        *(void**)self = D_004DE2A0;
        if (!self->b159) {
            self->f150 = -1;
            self->Release();
        }
        cNPC_dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_002D5FA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D5FA0 */

/* merge_units: begin func_002D6030 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Path2D6030 { char pad[0x4C]; volatile int f4C; int f50; int f54; };
struct Bits141 { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1; unsigned char b5 : 1; unsigned char b6 : 1; unsigned char b7 : 1; };
struct Npc2D6030 {
    VPAD32(a) virtual unsigned char IsActive(); VPAD32(b) VPAD16(c) VPAD4(d) VPAD2(e) virtual int Slot87();
    char p4[0x10]; unsigned char f14; char p15[0x43]; Npc2D6030* f58; char p5C[0x3C]; float f98;
    char p9C[0xA5]; Bits141 f141; char p142[0xE]; int f150; char p154[0x5C]; Path2D6030* f1B0;
};
struct Owner2D6030 { char p0[0x14]; unsigned char f14; char p15[0x43]; Npc2D6030* f58; char p5C[0x34EC]; int f3548; char p354C[0x38]; char* f3584; };
struct Self2D6030 {
    void* vt; char p4[0x10]; unsigned char f14; char p15[0x83]; float f98; char p9C[0xA5]; Bits141 f141; char p142[0xE]; int f150;
    char p154[0x8C]; int f1E0; char* f1E4; int f1E8; short f1EC; char p1EE[0x12]; int f200; char p204[4]; int f208; char p20C[4]; int f210; Bits141 f214;
};
extern "C" {
void cNPC_ctor_cGOBJP(Self2D6030* self, Owner2D6030* owner);
int cAIPathData_GetNode(int n);
}
static inline int PathNode(Path2D6030* p) { int n = p->f4C; return n >= 0 ? n : p->f54; }
static inline void ResetFlags(Self2D6030* self, bool v) {
    self->f14 = 0;
    self->f214.b0 = v;
    self->f200 = 0;
    self->f214.b1 = v;
    self->f214.b2 = v;
}
extern "C" Self2D6030* cNetNPC_ctor(Self2D6030* self, int id, Owner2D6030* owner)
{
    cNPC_ctor_cGOBJP(self, owner);
    self->vt = D_004DE2A0;
    self->f1E0 = id;
    self->f1E4 = 0;
    self->f1E8 = 0;
    self->f1EC = 0;
    if (owner) {
        if (owner->f3584) {
            if (!self->f1E0) self->f1E0 = (int)owner->f3584;
            char* q = owner->f3584; if (q) q += 0x1C; self->f1E4 = q;
        }
        owner->f14 = 0;
        int node = owner->f3548;
        if (owner->f58 && owner->f58->IsActive() == 1) {
            Npc2D6030* o = owner->f58;
            float f = o->f98; self->f141.b7 = o->f141.b7;
            self->f98 = f;
            self->f210 = 0;
            Path2D6030* p = o->f1B0;
            if (PathNode(p) >= 0) {
                node = PathNode(p);
            } else if (p->f50 >= 0) {
                node = p->f50;
                self->f210 = cAIPathData_GetNode(node);
            }
            self->f150 = o->f150;
            self->f141.b2 = o->Slot87();
        }
        if (node >= 0) self->f1E8 = cAIPathData_GetNode(node);
        self->f208 = node;
    } else {
        self->f208 = -1;
    }
    ResetFlags(self, false);
    return self;
}
static inline void merge_flush_func_002D6030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D6030 */

/* merge_units: begin func_002D6250 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DE4D0[];
}
union V4_E100 { struct { float x, y, z, w; } f; struct { char c[16]; } s; };
union V2_6250 { struct { float x, y; } f; struct { char c[8]; } s; };
struct Msg2530 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; V4_E100 v; V2_6250 w; };
extern "C" Msg2530* cNetNPCMsgs_Clone(Msg2530* src)
{
    Msg2530* p;
    {
        AllocGuard guard;
        p = (Msg2530*)cMemMan_Allocate(0, 0x3C, "NetNPCMsgs.hh", 0x26);
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
        p->vtable = D_004DE4D0;
        p->v = src->v;
        p->w = src->w;
    }
    return p;
}
static inline void merge_flush_func_002D6250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D6250 */
