/*
 * main/guiMLTextWidget: 6 files, 0043E0E0-0043E330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043E0E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Release the owned record at +0xA0 (string member at +0x14) under the allocator guard, clear +0xA0/+0xA4. */
extern "C" {
extern char D_004C0110[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_00138B70(void* self, short flags);
void func_0041F090(void* self);
}
struct O348AD0 { char pad[0x48]; char* aA0; int aA4; };
extern "C" void func_0043E0E0(O348AD0* o)
{
    char* p;
    func_0041F090(o);
    p = o->aA0;
    {
        AllocGuard guard;
        if (p) {
            char* s = p + 0x14;
            if (s)
                func_00138B70(s, 0);
        }
        Mem_Free(0, p, D_004C0110, 0x67);
    }
    o->aA0 = 0;

}
#pragma pop /* merge_units */
/* merge_units: end func_0043E0E0 */

/* merge_units: begin func_0043E1A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C0043E1A0 { float r, g, b, a; };
struct Q0043E1A0 { __int128 q; };
struct W0043E1A0 { char p[0x48]; void* h; char p4C[4]; C0043E1A0 c; };
extern "C" void func_003D0810(void* h, C0043E1A0* c);
static inline void Set0043E1A0(C0043E1A0* d, const C0043E1A0& s) { d->r = s.r; d->g = s.g; d->b = s.b; d->a = s.a; }
extern "C" void func_0043E1A0(W0043E1A0* w, Q0043E1A0* in)
{
    Q0043E1A0 t = *in;
    Set0043E1A0(&w->c, *(C0043E1A0*)&t);
    if (w->h) func_003D0810(w->h, &w->c);
}
#pragma pop /* merge_units */
/* merge_units: end func_0043E1A0 */

/* merge_units: begin func_0043E200 */
#pragma push /* merge_units */
typedef struct { char p0[0x20]; int f20; } C43E200;
typedef struct { char p0[0x40]; float f40; char p44[4]; C43E200* child; int value; char p50[0x10]; int f60; int f64; } W43E200;
extern int func_0036A2F0(int);
extern int Gui_GetScreenList(void);
extern int func_00418420(int, int);
#pragma push
#pragma opt_common_subs off
void func_0043E200(W43E200* w, int arg1)
{
    C43E200* c;
    w->value = func_00418420(Gui_GetScreenList(), arg1);
    c = w->child;
    if (c != 0) c->f20 = w->value;
    w->f60 = (int)w->f40 / func_0036A2F0(w->value);
    w->f64 = w->f60;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0043E200 */

/* merge_units: begin func_0043E290 */
#pragma push /* merge_units */
#include "loose05_types.h"

extern void func_0043BC70(GuiWidget43BEF0* self, unsigned char mode, int value,
                         int lower, int upper);

/* Synchronize the optional range widget with the text's current extent. */
void func_0043E290(MLTextWidget* self) {
    if (self->rangeWidget != 0) {
        func_0043BC70(self->rangeWidget, 0, self->unk68, 0,
                     self->unk70 - self->unk64);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043E290 */

/* merge_units: begin func_0043E2E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x64]; int start; int pos; int pad6C; int end; int pad74; int pad78; void* target; } O3E2E0;
extern void func_0041EFA0(O3E2E0* s, float x);
#if 0 /* merge_units */
extern void func_0043BC70(void* t, int a, int pos, int b, int len);
#endif /* merge_units */
#define func_0043BC70(a0, a1, a2, a3, a4) (func_0043BC70((GuiWidget43BEF0 *)(a0), (unsigned char)(a1), (a2), (a3), (a4))) /* merge_units */

void func_0043E2E0(O3E2E0* s, float x) {
    func_0041EFA0(s, x);
    if (s->target)
        func_0043BC70(s->target, 0, s->pos, 0, s->end - s->start);
}
#undef func_0043BC70 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043E2E0 */

/* merge_units: begin func_0043E330 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
struct W_43E330 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
};
typedef struct { char pad[0x10]; unsigned char b10; char pad11[0x47]; unsigned char b58; } T_43E330;
typedef struct {
    char pad[0x3C]; float f3C; float f40; char pad44[4]; T_43E330* f48; void* f4C; char pad50[0x10];
    int f60; int f64; char pad68[0x14]; W_43E330* f7C;
} O_43E330;
extern "C" {extern char D_004C0100[]; extern char D_004AAE00[];
extern int D_004976B8;
void func_0041F150(O_43E330* o);
void* Mem_Alloc(int pool, int size, char* file, int line);
#if 0 /* merge_units */
void* Gui_GetScreenList(void);
#endif /* merge_units */
#define Gui_GetScreenList() ((void *)Gui_GetScreenList()) /* merge_units */

#if 0 /* merge_units */
void* func_00418420(void* mgr, int name);
#endif /* merge_units */
#define func_00418420(a0, a1) ((void *)func_00418420((int)(a0), (a1))) /* merge_units */

T_43E330* func_003D0940(void* p, int a, int b, int c, int d, void* e, char* f);
W_43E330* func_0041DC70(void* o, int id);
#if 0 /* merge_units */
int func_0036A2F0(void* p);
#endif /* merge_units */
#define func_0036A2F0(a0) (func_0036A2F0((int)(a0))) /* merge_units */

void func_0043E330(O_43E330* o);
}
static inline void* Alloc_43E330(int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004C0110, line); }
static inline W_43E330* Cast_43E330(W_43E330* w, void* t) { return w && w->IsA(t) ? w : 0; }

void func_0043E330(O_43E330* o)
{
    T_43E330* t;
    func_0041F150(o);
    o->f4C = func_00418420(Gui_GetScreenList(), 0);
    t = (T_43E330*)Alloc_43E330(0x60, 0x33);
    if (t) t = func_003D0940(t, 0, 0, (int)o->f3C, (int)o->f40, o->f4C, D_004C0100);
    o->f48 = t;
    o->f48->b10 = 0;
    o->f48->b58 = 1;
    o->f60 = (int)o->f40 / func_0036A2F0(o->f4C);
    o->f64 = o->f60;
    o->f7C = Cast_43E330(func_0041DC70(o, D_004976B8), D_004AAE00);
}
#undef Gui_GetScreenList /* merge_units */
#undef func_00418420 /* merge_units */
#undef func_0036A2F0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043E330 */
