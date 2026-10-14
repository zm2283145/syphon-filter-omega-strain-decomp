/*
 * main/gameFrontEnd: range (3 files, 002CCE80-002CD030)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop

/* merge_units: begin func_002CCE80 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V2CCE80 { float x, y, z, w; } __attribute__((aligned(16)));
struct Sp2CCE80 { char pad[0x10]; V2CCE80 c0; V2CCE80 c1; V2CCE80 c2; };
extern "C" {
extern V2CCE80 D_00587B50;
extern V2CCE80 D_00587B60;
extern V2CCE80 D_00587B70;
}
static inline void SetA2CCE80(Sp2CCE80* p, V2CCE80 a) { p->c0 = a; }
static inline void SetB2CCE80(Sp2CCE80* p, V2CCE80 b) { p->c1 = b; }
static inline void SetC2CCE80(Sp2CCE80* p, V2CCE80 c) { p->c2 = c; }
/* Resets the sprite's three colours to the defaults. */
extern "C" void func_002CCE80(Sp2CCE80* sp)
{
    if (sp) {
        SetA2CCE80(sp, D_00587B50);
        SetB2CCE80(sp, D_00587B60);
        SetC2CCE80(sp, D_00587B70);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CCE80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CCE80 */

/* merge_units: begin func_002CCF30 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
void* Mem_Alloc(int pool, int size, char* file, int line);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) ((void *)Mem_Alloc((a0), (a1), (a2), (a3))) /* merge_units */

extern char D_004DFD80[];
extern char D_004DE200[];
}
struct MsgCF30 { void* vtable; int a, b, c, d, e, f, g; char h; };
extern "C" MsgCF30* func_002CCF30(MsgCF30* src)
{
    MsgCF30* p;
    {
        AllocGuard guard;
        p = (MsgCF30*)Mem_Alloc(0, 0x24, "game_msg.hh", 0x2D);
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
        p->vtable = D_004DE200;
    }
    return p;
}
#undef Mem_Alloc /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CCF30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CCF30 */

/* merge_units: begin func_002CD030 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004DE220[];

struct Msg_0020E560 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004DE220;

extern "C" {
char D_004AD1D8[] = "game_msg.hh";
}
DEFINE_MESSAGE_CLONE(func_002CD030, Msg_0020E560, 0x24, D_004AD1D8, 0x1C, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CD030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CD030 */
