/*
 * main/xlib: range (2 files, 0037B2C0-0037B2F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "xlib_types.h"

/* merge_units: begin func_0037B2C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * xlib.cc
 */


/* Construct from a single word. */
XlibWord* func_0037B2C0(XlibWord* self, int value) {
    self->value = value;
    return self;
}

/* Address of the payload following the header word. */
void* func_0037B2D0(XlibWord* self) {
    return self->data;
}

/* Identity accessor. */
void* func_0037B2E0(void* self) {
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0037B2C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0037B2C0 */

/* merge_units: begin func_0037B2F0 */
#pragma push /* merge_units */
typedef struct { int a; int b; int kind; } Request3;
extern void func_0037FCA0(int* out, void* list, void** slot, Request3* req);

/* Builds a kind-2 request (a, b) and submits it to the list at +0x1108 with slot +0x110C. */
void func_0037B2F0(char* self, int a, int b)
{
    void* slot;
    int result;
    Request3 req;
    req.a = a;
    req.b = b;
    req.kind = 2;
    slot = self + 0x110C;
    func_0037FCA0(&result, self + 0x1108, &slot, &req);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0037B2F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0037B2F0 */
