/*
 * Libs/SFOLib/Source/xlib: 5 files, 0037F670-0037F950
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0037F670 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char p0[0x1C]; int w; int h; int bpp; int clut; char p2C[0x100]; int f12C; int f130; int f134; int f138; int f13C; int f140; } T37F670;
/* Computes the texture's VRAM page layout (page counts for image and CLUT). */
void XLib_CalcVramAddrs(T37F670* t)
{
    int bw; unsigned char big; int bh; int pages; int cl; int ch;
    bw = (t->w + 63) >> 6;
    big = 1;
    if (t->bpp != 32 && t->bpp != 24) big = 0;
    if (big) bh = (t->h + 31) >> 5;
    else bh = (t->h + 63) >> 6;
    pages = bw * bh;
    if (t->clut == 16) ch = (t->h + 63) >> 6;
    else ch = (t->h + 31) >> 5;
    cl = t->clut > 0 ? bw * ch : 0;
    t->f12C = 0;
    t->f130 = t->f12C + pages;
    t->f138 = t->f130 + pages;
    t->f134 = t->f138;
    t->f13C = (t->f134 + cl) << 5;
    t->f140 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0037F670(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0037F670 */

/* merge_units: begin func_0037F740 */
#pragma push /* merge_units */
typedef struct { float w, h; } Res;
typedef struct {
    unsigned int flags;
    char pad4[0x10 - 4];
    int dispw;
    int disph;
    char pad18[0x1C - 0x18];
    int w;
    int h;
    char pad24[0x3C - 0x24];
    float f3C, f40, f44, f48, sx, sy, f54, f58, f5C, f60;
    char pad64[0xF80 - 0x64];
    int iF80, iF84;
    float resw, resh;
    float aspect, aspect2;
} Rnd;
extern Res D_004BC1D0[];

void XLib_InitScreenSpace(Rnd* r)
{
    int sel;
    int iw;
    int ih;
    int i;
    Res* p;
    int dw;
    int dh;
    dw = r->dispw;
    dh = r->disph;
    iw = 0;
    ih = 0;

    for (i = 0, p = D_004BC1D0; i < 6; i++, p++) {
        if ((float)dw <= p->w) iw = i;
        if ((float)dh <= p->h) ih = i;
        if (iw != i || ih != i) {
            sel = i - 1;
            break;
        }
    }
    r->iF80 = 0;
    r->iF84 = 0;
    r->resw = D_004BC1D0[sel].w;
    r->resh = D_004BC1D0[sel].h;
    r->sx = r->w / r->resw;
    r->sy = r->h / r->resh;
    r->f54 = 0.0f;
    r->f58 = 0.0f;
    r->f5C = 1.0f;
    r->f60 = 1.0f;
    if (r->flags & 4) {
        r->f60 *= r->w / 720.0f;
    } else if (r->flags & 2) {
        r->f60 *= 1.0666667f;
    }
    r->f44 = 1.0f;
    r->f48 = 1.0f;
    r->f3C = 0.0f;
    r->f40 = 0.0f;
    r->aspect2 = r->aspect = r->resw / r->resh;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0037F740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0037F740 */

/* merge_units: begin func_0037F8D0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: list member at +0x1108, array of 6 20-byte elements at +0x1068. */
extern "C" {
#if 0 /* merge_units */
void* std_list_tDataDelRec_dtor(void* self, short flags);
#endif /* merge_units */
struct L37F950; /* merge_units */
L37F950* std_list_tDataDelRec_dtor(L37F950* self, short deleteFlag); /* merge_units */
#define std_list_tDataDelRec_dtor(a0, a1) ((void *)std_list_tDataDelRec_dtor((L37F950 *)(a0), (a1))) /* merge_units */

void* cUserFrameEnv_dtor(void* self, short flags);
void __destroy_array(void* array, void* dtor, unsigned int size, unsigned int count);
void operator_delete(void* allocation);
}
extern "C" void* XLib_dtor(void* self, short deleteFlag)
{
    if (self) {
        char* l = (char*)self + 0x1108;
        if (l)
            std_list_tDataDelRec_dtor(l, 0);
        __destroy_array((char*)self + 0x1068, (void*)cUserFrameEnv_dtor, 0x14, 6);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef std_list_tDataDelRec_dtor /* merge_units */
static inline void merge_flush_func_0037F8D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037F8D0 */

/* merge_units: begin func_0037F950 */
#pragma push /* merge_units */
#pragma cplusplus on

/* List destructor (three inlined null tests): erase [first, sentinel), then delete. */
struct N37F950;
struct L37F950 { int count; N37F950* sentinelPrev; N37F950* first; };
extern "C" {
void std_list_deleter_tDataDelRec_erase_listdeleter_listdeleter(N37F950** result, L37F950* self, N37F950** first, N37F950** last);
}
extern "C" L37F950* std_list_tDataDelRec_dtor(L37F950* self, short deleteFlag)
{
    if (self) {
        if (self) {
            if (self) {
                N37F950* result;
                N37F950* first;
                N37F950* last;
                last = (N37F950*)&self->sentinelPrev;
                first = self->first;
                std_list_deleter_tDataDelRec_erase_listdeleter_listdeleter(&result, self, &first, &last);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_0037F950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037F950 */

/* merge_units: begin func_0037F9D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Runtime array constructor: (array, ctor, dtor, element size, count). */
extern int __construct_array(void* array, void* ctor, void* dtor, int size, int count);
extern int cXViewport_ctor(void*);
extern List* std_list_deleter_tDataDelRec_ctor(List*);
#if 0 /* merge_units */
extern int cUserFrameEnv_dtor(int, int);
#endif /* merge_units */
#define cUserFrameEnv_dtor(a0, a1) ((int)cUserFrameEnv_dtor((void *)(a0), (short)(a1))) /* merge_units */

extern int cUserFrameEnv_ctor(int);

/* Constructor: 8 sub-objects, two counters, six Slot20 entries. */
Manager37F9D0* XLib_ctor(Manager37F9D0* self) {
    char* item;

    self->unk00 = -1;
    item = self->items[0];
    do {
        cXViewport_ctor(item);
        item += 272;
    } while (item != self->items[8]);
    self->unk1058 = 0;
    self->unk105C = 0;
    __construct_array(self->slots, cUserFrameEnv_ctor, cUserFrameEnv_dtor, 20, 6);
    std_list_deleter_tDataDelRec_ctor(&self->unk1108);
    return self;
}
#undef cUserFrameEnv_dtor /* merge_units */
static inline void merge_flush_func_0037F9D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037F9D0 */
