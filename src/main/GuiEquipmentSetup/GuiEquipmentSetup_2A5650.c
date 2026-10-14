/*
 * main/GuiEquipmentSetup: range (8 files, 002A5650-002A5C40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "v4_asm_copy.h"
#pragma push
#pragma cplusplus on
#include "name_tree_find.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_init_range.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "tree_find.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_resize.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_destroy_dtor.h"
#pragma pop
#include "short_string_compare.h"

/* merge_units: begin func_002A5650 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V2A5650 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q2A5650 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub2A5650 { char pad[0x10]; Q2A5650 pos; };
struct T2A5650 { V2A5650 v; char pad4[0xC]; Sub2A5650 sub; char pad40[0x20]; unsigned char b50; };
struct A2A5650 { char pad[0x50]; T2A5650* t; char pad54[0x10]; float heading; };
extern "C" {
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(A2A5650* a, float dt);
}
extern "C" void func_002A5650(A2A5650* a, float dt)
{
    T2A5650* t = a->t;
    Q2A5650 p;
    if (t->b50)
        t->v.v20();
    Sub2A5650* s = (Sub2A5650*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Math_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    Actor_BaseLogicUpdate(a, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A5650(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A5650 */

/* merge_units: begin func_002A56D0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Find a name key in a tree; end() when absent. */
DEFINE_NAME_TREE_FIND(func_002A56D0)
#pragma pop /* merge_units */
/* merge_units: end func_002A56D0 */

/* merge_units: begin func_002A57F0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct VRElem20 { float a; float b; unsigned char c; int d; int e; };
extern "C" {
char D_004AB2C0[] = "vector length error\n";
}
DEFINE_VECTOR_INIT_RANGE(func_002A57F0, VRElem20, 0x4CCCCC, D_004AB2C0, D_0049ED58, 0x5C)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A57F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A57F0 */

/* merge_units: begin func_002A5980 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Find a key in a tree; end() when absent. */
DEFINE_TREE_FIND(func_002A5980, func_0013C310)
#pragma pop /* merge_units */
/* merge_units: end func_002A5980 */

/* merge_units: begin func_002A5A50 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 60-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem60, 60)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_002A5A50, Elem60, AnimChannelVec_Grow, func_001BEB20)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_002A5A50 */

/* merge_units: begin func_002A5AE0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 8-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_002A5AE0, Elem8, func_001BF5A0, func_001BF440)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_002A5AE0 */

/* merge_units: begin func_002A5B50 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_002A5B50, func_001BFA20, D_0049ED38)
#pragma pop /* merge_units */
/* merge_units: end func_002A5B50 */

/* merge_units: begin func_002A5C40 */
#pragma push /* merge_units */
/* Compare two strings. */
DEFINE_SHORT_STRING_COMPARE(func_002A5C40)
#pragma pop /* merge_units */
/* merge_units: end func_002A5C40 */
