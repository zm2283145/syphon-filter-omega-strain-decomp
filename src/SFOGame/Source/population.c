/*
 * SFOGame/Source/population: 5 files, 00178B80-00178BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00178B80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Build a Vec4 from an xyz vector and w. */
Vec4* tRGBA_ctor_tRGBR_float(Vec4* d, Vec4* xyz, float w) {
    d->x = xyz->x;
    d->y = xyz->y;
    d->z = xyz->z;
    d->w = w;
    return d;
}
static inline void merge_flush_func_00178B80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00178B80 */

/* merge_units: begin func_00178BB0 */
#pragma push /* merge_units */
typedef struct E3PopReader {
    int unk0;
    int size;      /* 0x4: buffer size in bytes */
    unsigned int base;    /* 0x8 */
    int* cur;      /* 0xC */
} E3PopReader;

/* Scans the population buffer for a tag word; leaves the cursor just after it. */
int cPopulation_SeekBlock(E3PopReader* r, int tag) {
    int off;
    int v;
    v = *r->cur;
    r->cur++;
    if (v == tag) {
        return 1;
    }
    r->cur = (int*)r->base;
    off = 0;
    v = *r->cur;
    r->cur++;
    if (v != tag) {
        do {
            r->cur = (int*)(r->base + off);
            off += 4;
            if (r->cur > (int*)(r->base + r->size)) {
                r->cur = (int*)(r->size + r->base);
                return 0;
            }
            v = *r->cur;
            r->cur++;
        } while (v != tag);
    }
    return 1;
}
static inline void merge_flush_func_00178BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00178BB0 */

/* merge_units: begin func_00178C50 */
#pragma push /* merge_units */
/* Subtract from the word at +0x0C. */
void cPopulation_Rewind(Unk0013BDE0* self, int amount) {
    self->unk0C = self->unk0C - amount;
}
static inline void merge_flush_func_00178C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00178C50 */

/* merge_units: begin func_00178C60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void operator_delete(void* p);
}
#include "population.h"
/* flag > 0: also delete the object (-1 = destroy in place). */
extern "C" Population* cPopulation_dtor(Population* self, short flag)
{
    if (self) {
        if (self->ownsData) {
            void* b = self->data;
            AllocGuard g;
            cMemMan_Deallocate(1, b, "population.cc", 0x43);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00178C60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00178C60 */

/* merge_units: begin func_00178D40 */
#pragma push /* merge_units */
#pragma cplusplus on
/* FileManEntry (fileman_entry.h) on the stack; kept as a 0xA0-byte local type. */
typedef struct { int a[0x28]; } H178;
extern "C" {
extern int sprintf(char*, const char*, ...);
extern void cFileMan_ctor_charP_cHogFileR_bool(H178*, char*, void*, int);
extern int cFileMan_Open(H178*);
extern void cFileMan_EncodeFilename_charP_cFileIOP_bool(H178*, char*, int, int);
extern int cFileMan_GetSize(H178*);
extern void* cMemMan_Allocate(int, int, char*, int);
extern char D_0049CDA0[];
extern char D_0048B2F8[];
extern void cFileMan_Read_charPP_int(H178*, void**, int);
extern void cFileMan_Close(H178*);
extern void* cFileMan_Read_void(H178*);
extern void cFileMan_dtor(H178*, int);
}
extern "C" Population* cPopulation_ctor(Population* p, char* name, void* arg) {
    char buf[0x90];
    H178 h;
    sprintf(buf, "%s.pop", name);
    cFileMan_ctor_charP_cHogFileR_bool(&h, buf, arg, 0);
    if ((unsigned char)cFileMan_Open(&h)) {
        void* m;
        sprintf(buf, "%s\\%s\\DATA.POP", D_0048B2F8, name, name);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&h, buf, 0, 0);
        cFileMan_Open(&h);
        p->size = cFileMan_GetSize(&h);
        p->ownsData = 1;
        {
        int sz = p->size;
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        m = cMemMan_Allocate(1, sz, D_0049CDA0, 0x27);
        }
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        p->data = m;
        cFileMan_Read_charPP_int(&h, &p->data, p->size);
        cFileMan_Close(&h);
    } else {
        p->ownsData = 0;
        p->data = cFileMan_Read_void(&h);
        p->size = cFileMan_GetSize(&h);
    }
    p->cursor = p->data;
    p->count = *(int*)p->cursor;
    p->cursor = (char*)p->cursor + 4;
    cFileMan_dtor(&h, -1);
    return p;
}
static inline void merge_flush_func_00178D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00178D40 */
