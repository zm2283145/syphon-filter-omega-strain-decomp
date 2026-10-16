/*
 * main/GuiKeyboard: 5 files, 0032ADE0-0032AF70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032ADE0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(GuiKeyboard_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0032ADE0 */

/* merge_units: begin func_0032AED0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiKeyboard class-name getter (vtable D_004DE790 slot 19).
 */

#include "loose03_types.h"

char D_004B8D80[] = "GuiKeyboard";       /* "GuiKeyboard" */

/* Returns the class name string "GuiKeyboard". */
const char* GuiKeyboard_GetClassName(void) {
    return D_004B8D80;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032AED0 */

/* merge_units: begin func_0032AEE0 */
#pragma push /* merge_units */
#include "types.h"

/* strcmp */
extern int strcmp(const char* a, const char* b);
/* "GuiKeyboard" */

/* GuiKeyboard type check: true when name equals the class name "GuiKeyboard". */
int GuiKeyboard_IsType(void* self, const char* name) {
    return strcmp("GuiKeyboard", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032AEE0 */

/* merge_units: begin func_0032AF10 */
#pragma push /* merge_units */
typedef struct { unsigned char lng : 1; unsigned char len : 7; } SS32;
typedef struct { union { SS32 s; unsigned int w; } h; unsigned int size; } Str32;
typedef struct { char p[0x48]; Str32 name; } Obj32;
typedef struct { char p[0x4C]; Obj32 *o; } Own32;
static inline unsigned int size32(Str32 *s) { return (s->h.w & 1) ? s->size : (unsigned char)s->h.s.len; }
int GuiKeyboard_IsCharAllowed(Own32 *arg0, int c) {
    if ((unsigned char)c == 0x20 && size32(&arg0->o->name) == 0) return 0;
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032AF10 */

/* merge_units: begin func_0032AF70 */
#pragma push /* merge_units */
extern int GuiKeyboard_FindKey(int, int);

int GuiKeyboard_IsSpecialKey(int a0, int a1) {
    int s0, s1, v0;
    int cond;

    s1 = a0;
    s0 = a1;
    a1 = 0 + 1002;
    v0 = GuiKeyboard_FindKey(a0, a1);
    cond = s0 == v0;
    a0 = s1;
    if (cond) goto L0032AFC0;
    a1 = 0 + 1032;
    v0 = GuiKeyboard_FindKey(a0, a1);
    cond = s0 == v0;
    a0 = s1;
    if (cond) goto L0032AFC0;
    a1 = 0 + 57;
    v0 = GuiKeyboard_FindKey(a0, a1);
    cond = s0 == v0;
    if (cond) goto L0032AFC0;
    v0 = 0;
    goto L0032AFC8;
L0032AFC0:;
    v0 = 0 + 1;
L0032AFC8:;
    goto ret;
ret:
    return v0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032AF70 */
