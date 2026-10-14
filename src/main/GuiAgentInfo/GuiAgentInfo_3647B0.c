/*
 * main/GuiAgentInfo: range (7 files, 003647B0-00364870)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003647B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


int func_003647B0(void) {
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003647B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003647B0 */

/* merge_units: begin func_003647C0 */
#pragma push /* merge_units */
/* Returns 1.0f. */
float func_003647C0(void)
{
    return 1.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003647C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003647C0 */

/* merge_units: begin func_003647D0 */
#pragma push /* merge_units */
int func_003647D0(void) {
    return 0;
}

int func_003647E0(void) {
    return 1;
}

int func_003647F0(void) {
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003647D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003647D0 */

/* merge_units: begin func_00364800 */
#pragma push /* merge_units */
typedef struct { char pad[0x58]; void* other; } Obj58;
/* Returns the linked object at +0x58, or the object itself. */
void* func_00364800(Obj58* p) { if (p->other) return p->other; return p; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364800(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364800 */

/* merge_units: begin func_00364820 */
#pragma push /* merge_units */
void func_00364820(void) {
}

int func_00364830(void) {
    return 1;
}

int func_00364840(void) {
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364820(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364820 */

/* merge_units: begin func_00364850 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; float f40; } FObj;

/* Returns 3 if the float at +0x40 truncates to 0, else 0. */
int func_00364850(FObj* self)
{
    return (int)self->f40 ? 0 : 3;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364850 */

/* merge_units: begin func_00364870 */
#pragma push /* merge_units */
void* func_00364870(char* self) {
    return self + 12;
}

int func_00364880(void) {
    return 1;
}

void func_00364890(void) {
}

void func_003648A0(void) {
}

int func_003648B0(void) {
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364870 */
