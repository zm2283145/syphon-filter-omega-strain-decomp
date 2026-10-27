/*
 * Matched functions (byte-identical with the retail executable).
 * xlib.cc
 */

#include "types.h"
#include "xlib_types.h"

/* Set flag unkA78. */
void XLib_Restore(XlibObj* self) {
    self->unkA78 = 1;
}
