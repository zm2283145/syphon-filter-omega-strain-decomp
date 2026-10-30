/*
 * Libs/SFOLib/Source/infobar: 13 files, 003F9E20-003FA190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F9E20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_10(char* self) {
    return self + 4;
}
static inline void merge_flush_func_003F9E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9E20 */

/* merge_units: begin func_003F9E30 */
#pragma push /* merge_units */
extern void cInterfaceElement_Activate(int, int);

void cInfoBar_SetVisible(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 1288);
    cond = a0 == 0;
    if (cond) goto L003F9E50;
    cInterfaceElement_Activate(a0, a1);
L003F9E50:;
    goto ret;
ret:;
}
static inline void merge_flush_func_003F9E30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9E30 */

/* merge_units: begin func_003F9E60 */
#pragma push /* merge_units */
#pragma enumsalwaysint off
enum TS_9E60 { TS0, TS1, TS2, TS3, TSMAX = 0x7F };
#pragma cplusplus on
struct Col_9E60 { float r, g, b, a; };
struct Item_9E60 {
    char text[0x80];
    Col_9E60 col;
    unsigned char pri;
    unsigned char active;
    char pad92[2];
    float shown;
    float age;
    char pad9C[4];
};
struct Text_9E60 {
    char pad0[0x10]; TS_9E60 state; char pad11[0x2B]; float x3C; char pad40[0x10]; float x50; char pad54[6]; unsigned char x5A;
    bool Done() { return state == TS3 && x5A; }
};
struct Ticker_9E60 {
    Item_9E60 items[8];
    Item_9E60* cur;
    unsigned char minPri;
    char pad505[7];
    Text_9E60* text;
    unsigned char fadingIn;
    unsigned char fadeOut1;
    unsigned char fadeOut2;
    char pad513;
    float fadeInTime;
    float fade1Time;
    float fade2Time;
    float limit1;
    float limit2;
};
extern "C" {
extern char D_004BE220[];
void cTextArea_SetText(void* t, const char* s);
void cTextArea_SetColor(void* t, void* c);
void cTextArea_FadeTo(void* t, float a, float b);
}

extern "C" void cInfoBar_NextFrame(Ticker_9E60* self, float dt)
{
    Item_9E60* best;
    float bestAge = -1.0f;
    Item_9E60* it;
    int bestPri = -1;
    int i;

    for (it = self->items, best = 0, i = 0; i < 8; i++, it++) {
        if (it != self->cur && it->active) {
            it->age += dt;
            if (it->pri >= self->minPri) {
                if (it->pri > bestPri || (it->pri == bestPri && it->age > bestAge)) {
                    bestPri = (unsigned char)it->pri;
                    bestAge = it->age;
                    best = it;
                }
            }
        }
    }
    for (it = self->items, i = 0; i < 8; i++, it++) {
        if (it != self->cur && it->active && it->pri == 0) {
            it->active = 0;
            if (best == it && self->cur)
                best = 0;
        }
    }
    if (!self->cur) {
        if (best) {
            Col_9E60 c;
            self->cur = best;
            c = best->col;
            *(int*)&c.a = 0;
            cTextArea_SetText(self->text, best->text);
            cTextArea_SetColor(self->text, &c);
            cTextArea_FadeTo(self->text, best->col.a, self->fadeInTime);
            self->fadingIn = 1;
        }
    } else {
    if (!self->fadingIn)
        self->cur->shown += dt;
    TS_9E60 st = self->text->state;
    if (st == TS3) {
        if (self->text->Done()) {
            self->cur->active = 0;
            self->cur = 0;
            cTextArea_SetText(self->text, D_004BE220);
        }
    } else if (best && self->cur->shown > self->limit1 && !self->fadeOut2) {
        self->fadeOut2 = 1;
        cTextArea_FadeTo(self->text, 0.0f, self->fade2Time);
    } else if (self->limit2 > 0.0f && self->cur->shown > self->limit2 && !self->fadeOut1) {
        self->fadeOut1 = 1;
        cTextArea_FadeTo(self->text, 0.0f, self->fade1Time);
    }
    if (self->fadingIn || self->fadeOut2 || self->fadeOut1) {
        if (self->text->x3C == self->text->x50) {
            self->fadingIn = 0;
            if (self->fadeOut2 || self->fadeOut1) {
                self->fadeOut2 = 0;
                self->fadeOut1 = 0;
                self->cur->active = 0;
                self->cur = 0;
                cTextArea_SetText(self->text, D_004BE220);
            }
        }
    }
    }
}
static inline void merge_flush_func_003F9E60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9E60 */

/* merge_units: begin func_003FA190 */
#pragma push /* merge_units */
#include "loose04_types.h"

/* Sets the float at +0x48 of the sub-object, if present. */
void cInfoBar_SetScrollDelay(Unk3FA190* self, float value) {
    Unk3FA190Sub* sub = self->unk50C;

    if (sub != 0) {
        sub->unk48 = value;
    }
}
static inline void merge_flush_func_003FA190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FA190 */

/* merge_units: begin func_003FA1B0 */
#pragma push /* merge_units */
typedef struct { char p[0x10]; unsigned char b10; } H3FA1B0;
typedef struct { char p[0x50C]; H3FA1B0* h; } M3FA1B0;
void cInfoBar_SetScrolling(M3FA1B0* m, int on)
{
    if (m->h) m->h->b10 = on ? 3 : 2;
}
static inline void merge_flush_func_003FA1B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FA1B0 */

/* merge_units: begin func_003FA1E0 */
#pragma push /* merge_units */
typedef struct { char p[0x91]; unsigned char b91; char p92[0xE]; } Sl3FA1E0;
typedef struct { Sl3FA1E0 s[8]; Sl3FA1E0* cur; char p504[8]; void* h; unsigned char b510, b511, b512; } M3FA1E0;
#if 0 /* merge_units */
extern void cTextArea_SetText(void* h, const char* c);
#endif /* merge_units */
#define cTextArea_SetText(a0, a1) (cTextArea_SetText((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cTextArea_FadeTo(void* h, float a, float b);
#endif /* merge_units */
#define cTextArea_FadeTo(a0, a1, a2) (cTextArea_FadeTo((a0), (a1), (a2))) /* merge_units */

void HudTicker_Reset(M3FA1E0* m)
{
    Sl3FA1E0* s = m->s;
    int i;
    for (i = 0; i < 8; i++, s++) {
        if (s == m->cur) {
            m->cur->b91 = 0;
            m->cur = 0;
            cTextArea_SetText(m->h, D_004BE220);
            cTextArea_FadeTo(m->h, 1.0f, 0.0f);
            m->b512 = 0;
            m->b511 = 0;
            m->b510 = 0;
        } else s->b91 = 0;
    }
}
#undef cTextArea_SetText /* merge_units */
#undef cTextArea_FadeTo /* merge_units */
static inline void merge_flush_func_003FA1E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FA1E0 */

/* merge_units: begin func_003FA280 */
#pragma push /* merge_units */
typedef struct { char p[0x90]; unsigned char b90; unsigned char b91; char p92[0xE]; } Sl3FA280;
typedef struct { Sl3FA280 s[8]; Sl3FA280* cur; char p504[8]; void* h; unsigned char b510, b511, b512; char p513[9]; float f51C; } M3FA280;
void cInfoBar_ClearPriorityMessages(M3FA280* m, unsigned char type, int flag)
{
    Sl3FA280* s = m->s;
    int i;
    for (i = 0; i < 8; i++, s++) {
        if (s->b91 && s->b90 == type) {
            if (s == m->cur) {
                if (flag) {
                    m->cur->b91 = 0;
                    m->cur = 0;
                    cTextArea_SetText(m->h, D_004BE220);
                    cTextArea_FadeTo(m->h, 1.0f, 0.0f);
                    m->b512 = 0;
                    m->b511 = 0;
                    m->b510 = 0;
                } else {
                    m->b511 = 0;
                    m->b510 = 0;
                    m->b512 = 1;
                    cTextArea_FadeTo(m->h, 0.0f, m->f51C);
                }
            } else s->b91 = 0;
        }
    }
}
static inline void merge_flush_func_003FA280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FA280 */

/* merge_units: begin func_003FA380 */
#pragma push /* merge_units */
typedef struct { char p[0x90]; unsigned char lvl; } L3FA380;
typedef struct { char p[0x500]; L3FA380* l; unsigned char b504; char p505[7]; void* h; unsigned char b510, b511, b512; char p513[0x9]; float f51C; } S3FA380;
void cInfoBar_SetMinPriority(S3FA380* s, unsigned char v)
{
    if (s->l && s->l->lvl < v) {
        s->b511 = 0;
s->b510 = 0;
s->b512 = 1;
        cTextArea_FadeTo(s->h, 0.0f, s->f51C);
    }
    s->b504 = v;
}
static inline void merge_flush_func_003FA380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FA380 */

/* merge_units: begin func_003FA3F0 */
#pragma push /* merge_units */
typedef struct { char name[0x80]; float v[4]; unsigned char kind; unsigned char used; short pad; int a94; int a98; int pad2; } C4Note3FA;
#if 0 /* merge_units */
extern void cInfoBar_ClearPriorityMessages(C4Note3FA* n, unsigned char kind, int z);
#endif /* merge_units */
#define cInfoBar_ClearPriorityMessages(a0, a1, a2) (cInfoBar_ClearPriorityMessages((M3FA280 *)(a0), (a1), (a2))) /* merge_units */



extern void Libc_Strcpy(char* d, const char* s);
void cInfoBar_AddMessage(C4Note3FA* n, const char* name, float* v, unsigned char kind, int flush) {
    int i;
    if (flush) cInfoBar_ClearPriorityMessages(n, kind, 0);
    for (i = 0; i < 8; i++, n++) {
        if (!n->used) {
            Libc_Strcpy(n->name, name);
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
#undef cInfoBar_ClearPriorityMessages /* merge_units */
static inline void merge_flush_func_003FA3F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FA3F0 */

/* merge_units: begin func_003FA4B0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cInfoBar_dtor)
static inline void merge_flush_func_003FA4B0(void) {} /* merge_units */
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
extern void cTextArea_SetText(void* s, const char* p);
#endif /* merge_units */
#define cTextArea_SetText(a0, a1) (cTextArea_SetText((a0), (a1))) /* merge_units */




Obj* cInfoBar_ctor(Obj* o, Sub* s, int v)
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
    cTextArea_SetText(o->x50C, D_004BE220);
    o->x50C->x20 = v;
    o->x512 = 0;
    o->x511 = 0;
    o->x510 = 0;
    { Pair* p; for (i = 0, p = o->pairs; i < 4; i++, p++) { p->e[0].flag = 0; p->e[1].flag = 0; } }
    return o;
}
#undef cTextArea_SetText /* merge_units */
static inline void merge_flush_func_003FA500(void) {} /* merge_units */
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
void* nGobjManager_GetGOBJList(void);
Vec_A5D0* cObjList_cGOBJPtr_GetList(void* arr);
void cArray_cGOBJPtr_Begin(It_A5D0* out, Vec_A5D0* v);
void cArray_cGOBJPtr_End(It_A5D0* out, Vec_A5D0* v);
void cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(It_A5D0* out, It_A5D0* in);
void printf(char* fmt, int i);
extern char D_004BE240[];
extern unsigned char D_0055C780[];
extern unsigned char D_005724B0;
}
static inline bool Ok_A5D0(O_A5D0* o) { bool r = false; C_A5D0* c = o->c58; if (c) { if (c->F54()) r = true; } return r; }
static inline int Ne_A5D0(It_A5D0* a, It_A5D0* b) { return (a->p == b->p) ^ 1; }
extern "C" void cNetObj_LoadNetworkData(void)
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
                arr = nGobjManager_GetGOBJList();
                cArray_cGOBJPtr_Begin(&tb, cObjList_cGOBJPtr_GetList(arr));
                cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&it, &tb);
                for (cArray_cGOBJPtr_End(&te, cObjList_cGOBJPtr_GetList(arr)), cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&end, &te); Ne_A5D0(&it, &end); cArray_cGOBJPtr_End(&te, cObjList_cGOBJPtr_GetList(arr)), cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&end, &te)) {
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
static inline void merge_flush_func_003FA5D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FA5D0 */

/* merge_units: begin func_003FA780 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Node3FA780 { char pad[0x14]; int a; unsigned char flag; char pad19[3]; int b; } Node3FA780;
extern "C" {
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_begin_void_2(Node3FA780** out, void* map);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node3FA780** out, void* in);
extern void std_red_black_tree_1_increment(Node3FA780** it);
}
static inline int Eq3FA780(Node3FA780* a, Node3FA780* b) { return a == b; }
static inline int Has3FA780(Node3FA780* n) { return n->b != 0; }
#pragma push
#pragma opt_propagation off
extern "C" bool cNetObj_GetDelayedMsgs(int* outA, unsigned char* outFlag, int* outB)
{
    bool found = false;
    if (D_005724B0 != 7) {
        Node3FA780* it[1];
        Node3FA780* end[1];
        Node3FA780* b[1];
        int tmp[1];
        std_tree_pair_int_value_compare_begin_void_2(b, D_0055C7A0);
        it[0] = b[0];
        for (std_map_int_netSystemField_end(tmp, D_0055C7A0), cAssocArray_int_netSystemField_Iterator_ctor(end, tmp); Eq3FA780(it[0], end[0]) ^ 1; std_map_int_netSystemField_end(tmp, D_0055C7A0), cAssocArray_int_netSystemField_Iterator_ctor(end, tmp)) {
            if (!(Has3FA780(it[0]) ^ 1)) {
                found = true;
                *outFlag = it[0]->flag;
                *outA = it[0]->a;
                *outB = it[0]->b;
                it[0]->b = 0;
                break;
            }
            std_red_black_tree_1_increment(it);
        }
    }
    return found;
}
#pragma pop
static inline void merge_flush_func_003FA780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FA780 */
