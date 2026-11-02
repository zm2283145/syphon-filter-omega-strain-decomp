/*
 * Libs/SFOLib/Source/fileman: 3 files, 0036E310-0036E4B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin fileman_36E310 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { unsigned int flags; char name[0x80]; char pad[0x14]; char* a98; } F36DFB0;
#if 0 /* merge_units */
void cFSHandle_ctor(void*);
#endif /* merge_units */
int cFSHandle_ctor(void*); /* merge_units */
#define cFSHandle_ctor(a0) ((void)cFSHandle_ctor((a0))) /* merge_units */

char* strncpy(char*, const char*, int);
static inline int Kind(F36DFB0* f)
{
    if (f->flags & 2) return 2;
    if (f->flags & 1) return 1;
    return 0;
}
static inline char* Data(F36DFB0* f)
{
    if (*(int*)f & 2) return f->a98 + 0x80;
    if (*(int*)f & 1) return f->a98;
    return 0;
}
static inline int Init(F36DFB0* d, const char* name, F36DFB0* s)
{
    if ((unsigned char)Kind(s) == 1) {
        int c = (*(int*)s & 4) != 0;
        char* p = Data(s);
        d->flags = 0;
        strncpy(d->name, name, 0x80);
        d->a98 = p;
        d->flags |= 1;
        if (c) d->flags |= 4;
    } else if ((unsigned char)Kind(s) == 2) {
        int c = (*(int*)s & 4) != 0;
        strncpy(d->name, name, 0x80);
        d->a98 = s->a98;
        d->flags = 0;
        d->flags |= 2;
        if (c) d->flags |= 4;
    } else return 5;
    return 0;
}

F36DFB0* cFileMan_ctor_charP_cFileManR(F36DFB0* d, const char* name, F36DFB0* s)
{
    cFSHandle_ctor((char*)d + 0x88);
    d->flags = 0;
    Init(d, name, s);
    return d;
}
#undef cFSHandle_ctor /* merge_units */
static inline void merge_flush_fileman_36E310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end fileman_36E310 */

/* merge_units: begin func_0036E4B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (code follows the fileman.cc
 * range); functions are named by address until real names are known.
 */

#include "loose03_types.h"

#if 0 /* merge_units */
extern int strncpy(char* dst, const char* src, int n); /* bounded string copy */
#endif /* merge_units */
#define strncpy(a0, a1, a2) ((int)strncpy((a0), (a1), (a2))) /* merge_units */

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
#undef strncpy /* merge_units */
static inline void merge_flush_func_0036E4B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036E4B0 */

/* merge_units: begin func_0036E600 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_0036E600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036E600 */
