/*
 * main/NetObj: 9 files, 003FA1B0-003FA780
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FA1B0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char p[0x10]; unsigned char b10; } H3FA1B0;
typedef struct { char p[0x50C]; H3FA1B0* h; } M3FA1B0;
void HudTicker_SetStyle(M3FA1B0* m, int on)
{
    if (m->h) m->h->b10 = on ? 3 : 2;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FA1B0 */

/* merge_units: begin func_003FA1E0 */
#pragma push /* merge_units */
typedef struct { char p[0x91]; unsigned char b91; char p92[0xE]; } Sl3FA1E0;
typedef struct { Sl3FA1E0 s[8]; Sl3FA1E0* cur; char p504[8]; void* h; unsigned char b510, b511, b512; } M3FA1E0;
extern void TextObj_SetText(void* h, void* c);
extern void TextObj_StartFade(void* h, float a, float b);
extern char D_004BE220[];
void HudTicker_Reset(M3FA1E0* m)
{
    Sl3FA1E0* s = m->s;
    int i;
    for (i = 0; i < 8; i++, s++) {
        if (s == m->cur) {
            m->cur->b91 = 0;
            m->cur = 0;
            TextObj_SetText(m->h, D_004BE220);
            TextObj_StartFade(m->h, 1.0f, 0.0f);
            m->b512 = 0;
            m->b511 = 0;
            m->b510 = 0;
        } else s->b91 = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003FA1E0 */

/* merge_units: begin func_003FA280 */
#pragma push /* merge_units */
typedef struct { char p[0x90]; unsigned char b90; unsigned char b91; char p92[0xE]; } Sl3FA280;
typedef struct { Sl3FA280 s[8]; Sl3FA280* cur; char p504[8]; void* h; unsigned char b510, b511, b512; char p513[9]; float f51C; } M3FA280;
void HudTicker_Clear(M3FA280* m, unsigned char type, int flag)
{
    Sl3FA280* s = m->s;
    int i;
    for (i = 0; i < 8; i++, s++) {
        if (s->b91 && s->b90 == type) {
            if (s == m->cur) {
                if (flag) {
                    m->cur->b91 = 0;
                    m->cur = 0;
                    TextObj_SetText(m->h, D_004BE220);
                    TextObj_StartFade(m->h, 1.0f, 0.0f);
                    m->b512 = 0;
                    m->b511 = 0;
                    m->b510 = 0;
                } else {
                    m->b511 = 0;
                    m->b510 = 0;
                    m->b512 = 1;
                    TextObj_StartFade(m->h, 0.0f, m->f51C);
                }
            } else s->b91 = 0;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003FA280 */

/* merge_units: begin func_003FA380 */
#pragma push /* merge_units */
typedef struct { char p[0x90]; unsigned char lvl; } L3FA380;
typedef struct { char p[0x500]; L3FA380* l; unsigned char b504; char p505[7]; void* h; unsigned char b510, b511, b512; char p513[0x9]; float f51C; } S3FA380;
void HudTicker_GetLevel(S3FA380* s, unsigned char v)
{
    if (s->l && s->l->lvl < v) {
        s->b511 = 0;
s->b510 = 0;
s->b512 = 1;
        TextObj_StartFade(s->h, 0.0f, s->f51C);
    }
    s->b504 = v;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FA380 */

/* merge_units: begin func_003FA3F0 */
#pragma push /* merge_units */
typedef struct { char name[0x80]; float v[4]; unsigned char kind; unsigned char used; short pad; int a94; int a98; int pad2; } C4Note3FA;
#if 0 /* merge_units */
extern void HudTicker_Clear(C4Note3FA* n, unsigned char kind, int z);
#endif /* merge_units */
#define HudTicker_Clear(a0, a1, a2) (HudTicker_Clear((M3FA280 *)(a0), (a1), (a2))) /* merge_units */

extern void String_Copy(char* d, const char* s);
void Notify_Insert(C4Note3FA* n, const char* name, float* v, unsigned char kind, int flush) {
    int i;
    if (flush) HudTicker_Clear(n, kind, 0);
    for (i = 0; i < 8; i++, n++) {
        if (!n->used) {
            String_Copy(n->name, name);
            n->v[0] = v[0];
            n->v[1] = v[1];
            n->v[2] = v[2];
            n->v[3] = v[3];
            n->kind = kind;
            n->a98 = 0;
            n->a94 = 0;
            n->used = 1;
            return;
        }
    }
}
#undef HudTicker_Clear /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FA3F0 */

/* merge_units: begin func_003FA4B0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_003FA4B0)
#pragma pop /* merge_units */
/* merge_units: end func_003FA4B0 */

/* merge_units: begin func_003FA500 */
#pragma push /* merge_units */
#pragma opt_propagation off

typedef struct {
    char pad0[0x91];
    unsigned char flag;
    char pad92[0xE];
} Ent;

typedef struct {
    char pad0[0x20];
    int x20;
    char pad24[0x50];
    int x74;
} Sub;

typedef struct { Ent e[2]; } Pair;
typedef struct {
    Pair pairs[4];
    int x500;
    unsigned char x504;
    char pad505[3];
    Sub* x508;
    Sub* x50C;
    unsigned char x510;
    unsigned char x511;
    unsigned char x512;
    char pad513;
    float x514;
    float x518;
    float x51C;
    float x520;
    float x524;
} Obj;

extern float D_004BE210;
extern float D_004BE218;
#if 0 /* merge_units */
extern int D_004BE220[];
#endif /* merge_units */
#define D_004BE220 ((int*)&D_004BE220) /* merge_units */

#if 0 /* merge_units */
extern void TextObj_SetText(Sub* s, void* p);
#endif /* merge_units */
#define TextObj_SetText(a0, a1) (TextObj_SetText((void *)(a0), (a1))) /* merge_units */


Obj* HudTicker_Init(Obj* o, Sub* s, int v)
{
    int i;
    o->x508 = s;
    o->x50C = (Sub*)o->x508->x74;
    o->x504 = 0;
    o->x514 = 0.5f;
    o->x518 = D_004BE210;
    o->x51C = 0.5f;
    o->x520 = 1.5f;
    o->x524 = D_004BE218;
    o->x500 = 0;
    TextObj_SetText(o->x50C, D_004BE220);
    o->x50C->x20 = v;
    o->x512 = 0;
    o->x511 = 0;
    o->x510 = 0;
    { Pair* p; for (i = 0, p = o->pairs; i < 4; i++, p++) { p->e[0].flag = 0; p->e[1].flag = 0; } }
    return o;
}
#undef D_004BE220 /* merge_units */
#undef TextObj_SetText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FA500 */

/* merge_units: begin func_003FA5D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct C_A5D0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int F54(); };
struct O_A5D0 { VPAD4(a) VPAD1(b) virtual void F1C(int i); char pad[0x10]; unsigned char b14; char pad2[0x43]; C_A5D0* c58; };
struct It_A5D0 { O_A5D0** p; };
struct Vec_A5D0;
extern "C" {
void* World_GetActorArray(void);
Vec_A5D0* func_001339A0(void* arr);
void PtrVec_Begin(It_A5D0* out, Vec_A5D0* v);
void PtrVec_End(It_A5D0* out, Vec_A5D0* v);
void func_00133980(It_A5D0* out, It_A5D0* in);
void printf(char* fmt, int i);
extern char D_004BE240[];
extern unsigned char D_0055C780[];
extern unsigned char D_005724B0;
}
static inline bool Ok_A5D0(O_A5D0* o) { bool r = false; C_A5D0* c = o->c58; if (c) { if (c->F54()) r = true; } return r; }
static inline int Ne_A5D0(It_A5D0* a, It_A5D0* b) { return (a->p == b->p) ^ 1; }
extern "C" void NetObj_LoadNetworkData(void)
{
    int i;
    void* arr;
    unsigned char* s;
    if (D_005724B0 != 7) {
        for (i = 0, s = D_0055C780; i < 4; i++, s++) {
            if (*s == 1) {
                It_A5D0 it;
                It_A5D0 end;
                It_A5D0 tb;
                It_A5D0 te;
                arr = World_GetActorArray();
                PtrVec_Begin(&tb, func_001339A0(arr));
                func_00133980(&it, &tb);
                for (PtrVec_End(&te, func_001339A0(arr)), func_00133980(&end, &te); Ne_A5D0(&it, &end); PtrVec_End(&te, func_001339A0(arr)), func_00133980(&end, &te)) {
                    if (Ok_A5D0(*it.p)) {
                        O_A5D0* o = *it.p;
                        if (o->b14) {
                            o->F1C(i);
                            break;
                        }
                    }
                    it.p++;
                }
            } else {
                printf(D_004BE240, i);
            }
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003FA5D0 */

/* merge_units: begin func_003FA780 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Node3FA780 { char pad[0x14]; int a; unsigned char flag; char pad19[3]; int b; } Node3FA780;
extern "C" {
extern char D_0055C7A0[];
extern void func_003FA8B0(Node3FA780** out, void* map);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(Node3FA780** out, void* in);
extern void Tree_Successor(Node3FA780** it);
}
static inline int Eq3FA780(Node3FA780* a, Node3FA780* b) { return a == b; }
static inline int Has3FA780(Node3FA780* n) { return n->b != 0; }
#pragma push
#pragma opt_propagation off
extern "C" bool func_003FA780(int* outA, unsigned char* outFlag, int* outB)
{
    bool found = false;
    if (D_005724B0 != 7) {
        Node3FA780* it[1];
        Node3FA780* end[1];
        Node3FA780* b[1];
        int tmp[1];
        func_003FA8B0(b, D_0055C7A0);
        it[0] = b[0];
        for (func_0021D360(tmp, D_0055C7A0), func_0021D350(end, tmp); Eq3FA780(it[0], end[0]) ^ 1; func_0021D360(tmp, D_0055C7A0), func_0021D350(end, tmp)) {
            if (!(Has3FA780(it[0]) ^ 1)) {
                found = true;
                *outFlag = it[0]->flag;
                *outA = it[0]->a;
                *outB = it[0]->b;
                it[0]->b = 0;
                break;
            }
            Tree_Successor(it);
        }
    }
    return found;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003FA780 */
