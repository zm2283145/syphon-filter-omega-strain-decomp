/*
 * main/texman: 7 files, 00380250-00380370
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00380250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator helpers.
 */

#include "types.h"
#include "texman_types.h"

TexListIter* std_list_deleter_int_generic_iterator_ctor_nodebaseP(TexListIter* it, TexListNode* node) {
    it->node = node;
    return it;
}

void* std_list_deleter_int_tail(char* self) {
    return self + 4;
}

void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_10(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00380250 */

/* merge_units: begin func_00380280 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
extern "C" void cTexture_dtor(void* p, int flags);
extern "C" void opDelete_cTextureP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy)
        cTexture_dtor(allocation, -1);
    cMemMan_Deallocate(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_00380280 */

/* merge_units: begin func_00380360 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Texture entry reference count accessor.
 */


int cTexture_GetRefCount(TexEntry* e) {
    return e->refCount;
}
#pragma pop /* merge_units */
/* merge_units: end func_00380360 */

/* merge_units: begin func_00380370 */
#pragma push /* merge_units */
int cTexMan_PatchupTDX_charP_intR(void* tdx, int data, unsigned int* fl); /* gsynth: defined below */
/* Read a TDX resource from a stream and relocate it. */
int cFileMan_GetSize(void* stream);
void cFileMan_Read_charPP_int(void* stream, int* out, int size);
void cFileMan_Close(void* stream);
#if 0 /* merge_units */
int cTexMan_PatchupTDX_charP_intR(void* tdx, int data, void* arg);
#endif /* merge_units */
#define cTexMan_PatchupTDX_charP_intR(a0, a1, a2) (cTexMan_PatchupTDX_charP_intR((a0), (a1), (unsigned int *)(a2))) /* merge_units */



int cTexMan_PatchupTDX_cFileManR_intR(void* tdx, void* stream, void* arg)
{
    int data = 0;
    cFileMan_Read_charPP_int(stream, &data, cFileMan_GetSize(stream));
    cFileMan_Close(stream);
    if (data == 0)
        return 0;
    else {
        int r = cTexMan_PatchupTDX_charP_intR(tdx, data, arg);
        return r;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00380370(void) {}
#undef cTexMan_PatchupTDX_charP_intR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00380370 */

/* merge_units: begin func_003803F0 */
#pragma push /* merge_units */
typedef struct { int a[5]; int b[1]; int o0; int o1; } T_00380570;
void tTDXImageFrame_Patchup(T_00380570* t, char* base, int n1, int n2, int x, int y); /* gsynth: defined below */typedef struct { char pad[0x38]; int stride; int pad2; } TdxHdr_e1;
char* tTDXHeader_GetFrameData(TdxHdr_e1* t, unsigned int n); /* gsynth: defined below */
typedef struct TdxH {
    unsigned short magic;
    unsigned short flags;
    char pad4[0x22 - 4];
    unsigned short nframes;
    unsigned short w;
    unsigned short h;
    char pad28[0x38 - 0x28];
    int stride;
    int relocated;
} TdxH;
extern int tTDXHeader_OffToImageData(TdxH* t);
extern int tTDXHeader_OffToMapData(TdxH* t);
#if 0 /* merge_units */
extern char* tTDXHeader_GetFrameData(TdxH* t, unsigned int n);
#endif /* merge_units */
#define tTDXHeader_GetFrameData(a0, a1) (tTDXHeader_GetFrameData((TdxHdr_e1 *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void tTDXImageFrame_Patchup(char* f, char* base, int w, int h, int pix, int pal);
#endif /* merge_units */
#define tTDXImageFrame_Patchup(a0, a1, a2, a3, a4, a5) (tTDXImageFrame_Patchup((T_00380570 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */



int cTexMan_PatchupTDX_charP_intR(void* tdx, int data, unsigned int* fl)
{
    TdxH* t = (TdxH*)data;
    if (t->magic != 5) return 0;
    if (!t->relocated) {
        char* base;
        int pix;
        int i;
        unsigned int pal;
        base = (char*)t + 0x40;
        pix = tTDXHeader_OffToImageData(t);
        pal = tTDXHeader_OffToMapData(t);
        for (i = 0; i < t->nframes; i++) {
            tTDXImageFrame_Patchup(tTDXHeader_GetFrameData(t, i), base, t->w, t->h, pix, pal);
            base += t->stride;
        }
        t->relocated = 1;
    }
    *fl |= 0x400;
    if (t->flags & 1) *fl |= 2;
    if (t->flags & 4) *fl |= 0x100;
    if (t->flags & 2) *fl |= 0x200;
    if (t->nframes > 1) *fl |= 0x800;
    return (int)t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003803F0(void) {}
#undef tTDXHeader_GetFrameData /* merge_units */
#undef tTDXImageFrame_Patchup /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003803F0 */

/* merge_units: begin func_00380570 */
#pragma push /* merge_units */
extern void SyncDCache(char* a, char* b);
typedef struct { char pad[0x54]; int v; } F_00380570;

void tTDXImageFrame_Patchup(T_00380570* t, char* base, int n1, int n2, int x, int y) {
    int i, j;
    t->o0 = (int)((int)base + (int)t->o0);
    for (i = 0; i < n1; i++) {
        t->a[i] = (int)((int)t->o0 + (int)t->a[i]);
        ((F_00380570*)t->a[i])->v += (int)t->o0 + x;
    }
    if (n2) {
        t->o1 = (int)((int)base + (int)t->o1);
        for (j = 0; j < n2; j++) {
            t->b[j] = (int)((int)t->o1 + (int)t->b[j]);
            ((F_00380570*)t->b[j])->v += (int)t->o1 + y;
        }
    } else {
        t->o1 = 0;
    }
    SyncDCache(base, base + 0x300);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00380570(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00380570 */

/* merge_units: begin func_00380920 */
#pragma push /* merge_units */
char* tTDXHeader_GetFrameData(TdxHdr_e1* t, unsigned int n)
{
    char* p = (char*)t + 0x40;
    unsigned int i;
    for (i = 0; i < n; i++) {
        p += t->stride;
    }
    return p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00380920(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00380920 */
