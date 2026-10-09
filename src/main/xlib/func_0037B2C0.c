/*
 * Matched functions (byte-identical with the retail executable).
 * xlib.cc
 */

#include "types.h"
#include "xlib_types.h"

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
