/*
 * main/GuiSaveAgentWidget: 4 files, 00290B90-00290C30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00290B90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int D_00506390;
extern int GuiAgentCreate_ManRender(int);

Rel* std_vector_imp_cSkeletonBBoxContributionPtr_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Word* cArrayCapacity_ctor(Word* self, int value) {
    self->value = value;
    return self;
}

int ManRenderWrapper(void) {
    return GuiAgentCreate_ManRender(D_00506390);
}
#pragma pop /* merge_units */
/* merge_units: end func_00290B90 */

/* merge_units: begin func_00290BD0 */
#pragma push /* merge_units */
int PartCompare(char* a, char* b) {
    int i;
    for (i = 0; i < 4; i++) {
        if (*++a != *++b) return 0;
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00290BD0 */

/* merge_units: begin func_00290C10 */
#pragma push /* merge_units */
void func_00290C10(void) {
}

void func_00290C20(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_00290C10 */

/* merge_units: begin func_00290C30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "v4_asm_copy.h"
struct V290C30 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q290C30 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub290C30 { char pad[0x10]; Q290C30 pos; };
struct T290C30 { V290C30 v; char pad4[0xC]; Sub290C30 sub; char pad40[0x20]; unsigned char b50; };
struct A290C30 { char pad[0x50]; T290C30* t; char pad54[0x10]; float heading; };
extern "C" {
float Libc_Atan2f(float y, float x);
void cGOBJ_NextFrame(A290C30* a, float dt);
}
extern "C" void func_00290C30(A290C30* a, float dt)
{
    T290C30* t = a->t;
    Q290C30 p;
    if (t->b50)
        t->v.v20();
    Sub290C30* s = (Sub290C30*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Libc_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    cGOBJ_NextFrame(a, dt);
}
#pragma pop /* merge_units */
/* merge_units: end func_00290C30 */
