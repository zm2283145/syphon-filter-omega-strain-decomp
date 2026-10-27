/*
 * main/fileman: 2 files, 0036E4B0-0036E600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036E4B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (code follows the fileman.cc
 * range); functions are named by address until real names are known.
 */

#include "loose03_types.h"

extern int strncpy(char* dst, const char* src, int n); /* bounded string copy */
extern int cFSHandle_ctor(void*);

/* Constructor, kind bit 0x1; sets 0x4 when `extra` is non-zero. */
NamedEntry36E4B0* cFileMan_ctor_charP_cFileIOP_bool(NamedEntry36E4B0* self, const char* name, int a2, int extra) {
    cFSHandle_ctor(self->unk88);
    self->flags = 0;
    self->flags = 0;
    strncpy(self->name, name, 128);
    self->unk98 = a2;
    self->flags = self->flags | 1;
    if (extra != 0) {
        self->flags = self->flags | 4;
    }
    return self;
}

/* Constructor, kind bit 0x2; sets 0x4 when `extra` is non-zero. */
NamedEntry36E4B0* cFileMan_ctor_charP_cHogFileR_bool(NamedEntry36E4B0* self, const char* name, int a2, int extra) {
    cFSHandle_ctor(self->unk88);
    self->flags = 0;
    self->flags = 0;
    strncpy(self->name, name, 128);
    self->unk98 = a2;
    self->flags = self->flags | 2;
    if (extra != 0) {
        self->flags = self->flags | 4;
    }
    return self;
}

/* Default constructor. */
NamedEntry36E4B0* cFileMan_ctor_void(NamedEntry36E4B0* self) {
    cFSHandle_ctor(self->unk88);
    self->flags = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036E4B0 */

/* merge_units: begin func_0036E600 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Obj36E600 { VPAD16(a) VPAD1(b) virtual void Clear(int f); virtual void s18(); virtual void Remove(void* e, int f);
    char pad[0xA0]; char mA4[4]; int count; void** items; };
extern "C" {
extern char D_004DF640[];
extern char D_004DF6A0[];
void std_vector_cXformNodePtr_dtor(void* p, int f);
void operator_delete(void* p);
}
static inline void Base36E600(Obj36E600* p) { if (p) *(void**)p = D_004DF6A0; }
extern "C" Obj36E600* cXformNode_dtor(Obj36E600* self, short del)
{
    if (self) {
        *(void**)self = D_004DF640;
        self->Clear(1);
        while (self->count) self->Remove(self->items[*(volatile int*)&self->count - 1], 1);
        if (self->mA4) std_vector_cXformNodePtr_dtor(self->mA4, -1);
        Base36E600(self);
        if (del > 0) operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036E600 */
