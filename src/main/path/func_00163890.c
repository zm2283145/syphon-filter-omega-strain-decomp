/*
 * Matched functions (byte-identical with the retail executable).
 * Constructor that only installs vtables (base to derived).
 */

#include "types.h"
#include "path_types.h"

extern char D_004D9700[];
extern char D_004D9710[];
extern char D_004D9720[];

typedef struct PathPolyObj {
    void* vtable;
} PathPolyObj;

PathPolyObj* func_00163890(PathPolyObj* self) {
    self->vtable = D_004D9720;
    self->vtable = D_004D9700;
    self->vtable = D_004D9710;
    return self;
}
