/*
 * SFOGame/Source/GuiEquipmentSetup: 10 files, 002A55D0-002A5650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A55D0 */
#pragma push /* merge_units */
#include "types.h"
#include "grid16_flag_test.h"

DEFINE_GRID16_FLAG_TEST(TeamEnemy_int_int, D_004EE620)
static inline void merge_flush_func_002A55D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A55D0 */

/* merge_units: begin func_002A5630 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */


void func_002A5630(void) {
}

void func_002A5640(void) {
}
static inline void merge_flush_func_002A5630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5630 */

/* merge_units: begin func_002A5650 */
#pragma push /* merge_units */
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

#pragma cplusplus on
struct V2A5650 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q2A5650 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub2A5650 { char pad[0x10]; Q2A5650 pos; };
struct T2A5650 { V2A5650 v; char pad4[0xC]; Sub2A5650 sub; char pad40[0x20]; unsigned char b50; };
struct A2A5650 { char pad[0x50]; T2A5650* t; char pad54[0x10]; float heading; };
extern "C" {
float Libc_Atan2f(float y, float x);
void cGOBJ_NextFrame(A2A5650* a, float dt);
}
extern "C" void func_002A5650(A2A5650* a, float dt)
{
    T2A5650* t = a->t;
    Q2A5650 p;
    if (t->b50)
        t->v.v20();
    Sub2A5650* s = (Sub2A5650*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Libc_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    cGOBJ_NextFrame(a, dt);
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
static inline void merge_flush_func_002A56D0(void) {} /* merge_units */
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
DEFINE_TREE_FIND(func_002A5980, std_basic_string_char_char_traits_char_compare_basicstringR)
static inline void merge_flush_func_002A5980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5980 */

/* merge_units: begin func_002A5A50 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 60-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem60, 60)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_002A5A50, Elem60, std_vector_imp_cSkaSliderValue_insert, std_vector_imp_cSkaSliderValue_erase)
#pragma opt_common_subs reset
static inline void merge_flush_func_002A5A50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5A50 */

/* merge_units: begin func_002A5AE0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 8-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_002A5AE0, Elem8, std_vector_imp_cSkaSwitchValue_insert, std_vector_imp_cSkaSwitchValue_erase)
#pragma opt_common_subs reset
static inline void merge_flush_func_002A5AE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5AE0 */

/* merge_units: begin func_002A5B50 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_002A5B50, func_001BFA20, D_0049ED38)
static inline void merge_flush_func_002A5B50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5B50 */

/* merge_units: begin func_002A5C40 */
#pragma push /* merge_units */
/* Compare two strings. */
DEFINE_SHORT_STRING_COMPARE(func_002A5C40)
static inline void merge_flush_func_002A5C40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5C40 */
