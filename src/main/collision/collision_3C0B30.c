/*
 * main/collision: range (6 files, 003C0B30-003C0D80)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003C0B30 */
#pragma push /* merge_units */
typedef struct { long long a; int b; } S;
/* Stores an 8-byte value and an int. */
void func_003C0B30(S* dst, long long* src, int b) { dst->a = *src; dst->b = b; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0B30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0B30 */

/* merge_units: begin func_003C0B40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Byte copy-assign. */
unsigned char* func_003C0B40(unsigned char* dst, unsigned char* src) {
    *dst = *src;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0B40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0B40 */

/* merge_units: begin func_003C0B50 */
#pragma push /* merge_units */
typedef struct { char pad[3]; unsigned char format; char pad2[0x14]; int offset; } ImageHdr;
typedef struct { int unk0; ImageHdr** image; } ImageRef;
extern unsigned char* func_00183B20(ImageHdr* hdr, int* offset);

/* Reads one texel byte at (x, y) from an image whose row stride depends on its format. */
void func_003C0B50(unsigned char* out, ImageRef* ref, int* coord)
{
    int off16;
    int off32;
    int off64;
    ImageHdr* hdr;
    int y;
    int x;
    unsigned char* row;
    x = coord[1];
    hdr = *ref->image;
    y = coord[0];
    if (hdr->format < 4) {
        off64 = hdr->offset;
        row = func_00183B20(hdr, &off64) + y * 64;
    } else if (hdr->format < 5) {
        off32 = hdr->offset;
        row = func_00183B20(hdr, &off32) + y * 32;
    } else {
        off16 = hdr->offset;
        row = func_00183B20(hdr, &off16) + y * 16;
    }
    row += x;
    *out = row[0xB];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0B50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0B50 */

/* merge_units: begin func_003C0C10 */
#pragma push /* merge_units */
typedef struct { char pad[3]; unsigned char format; char pad2[0x14]; int data; } Obj3C0;
char* func_003C0CF0(Obj3C0* o, int idx); /* gsynth: defined below */int func_003C0D80(char* self); /* gsynth: defined below */typedef struct { int unk0; unsigned short verts[1]; } TriData;
typedef struct { void* mesh; } MeshRef;
typedef struct { int unk0; MeshRef* ref; } ColTri;
extern void func_003C0D90(void* ctx, int* a, int* b, int* c);
#if 0 /* merge_units */
extern int func_003C0D80(void* ctx);
#endif /* merge_units */
#define func_003C0D80(a0) (func_003C0D80((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern TriData* func_003C0CF0(void* mesh, int index);
#endif /* merge_units */
#define func_003C0CF0(a0, a1) ((TriData *)func_003C0CF0((void *)(a0), (a1))) /* merge_units */

extern void* func_00231EC0(void* mesh, unsigned short vert);
/* Looks up the three vertex pointers of the triangle referenced by ctx. */
void ColTri_GetVertices(ColTri* tri, void** v0, void** v1, void** v2, void* ctx)
{
    int i2, i1, i0;
    void* mesh = tri->ref->mesh;
    TriData* data;
    func_003C0D90(ctx, &i0, &i1, &i2);
    data = func_003C0CF0(mesh, func_003C0D80(ctx));
    *v0 = func_00231EC0(mesh, data->verts[i0]);
    *v1 = func_00231EC0(mesh, data->verts[i1]);
    *v2 = func_00231EC0(mesh, data->verts[i2]);
}
#undef func_003C0D80 /* merge_units */
#undef func_003C0CF0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0C10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0C10 */

/* merge_units: begin func_003C0CF0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char* func_00183B20(Obj3C0* o, int* ref);
#endif /* merge_units */
#define func_00183B20(a0, a1) ((char *)func_00183B20((void *)(a0), (a1))) /* merge_units */


/* Returns the address of element idx; the element size (64/32/16 bytes) depends on the format byte. */
char* func_003C0CF0(Obj3C0* o, int idx)
{
    int r16;
    int r32;
    int r64;
    if (o->format < 4) {
        r64 = o->data;
        return func_00183B20(o, &r64) + idx * 64;
    } else if (o->format < 5) {
        r32 = o->data;
        return func_00183B20(o, &r32) + idx * 32;
    } else {
        r16 = o->data;
        return func_00183B20(o, &r16) + idx * 16;
    }
}
#undef func_00183B20 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0CF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0CF0 */

/* merge_units: begin func_003C0D80 */
#pragma push /* merge_units */
int func_003C0D80(char* self) {
    return *(int*)(self + 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0D80 */
