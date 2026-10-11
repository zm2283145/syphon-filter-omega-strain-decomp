#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { int id; float weight; unsigned char active; char pad[7]; Vec4 v; } AC_3B14A0;
AC_3B14A0* func_003B14A0(AC_3B14A0* self, AC_3B14A0* o) {
    self->id = o->id;
    self->weight = o->weight;
    self->active = o->active;
    { typedef char uf_chk_[sizeof(self->v) == 16 ? 1 : -1]; VCopyF(&(self->v), &(o->v)); }
    return self;
}
#pragma peephole reset
