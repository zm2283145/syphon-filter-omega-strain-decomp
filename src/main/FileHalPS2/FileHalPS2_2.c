/*
 * main/FileHalPS2: 4 files, 003695C0-00369820
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003695C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct S3695C0 { int x0; char pad4[0x24]; int x28; char pad2C[0x10]; int x3C; unsigned char b40; unsigned char b41; char pad42[0xC4 - 0x42]; void* pC4; };
extern "C" {
extern char D_004BBDD0[];
void func_003A6F10(S3695C0* s);
void Mem_Free(int pool, void* p, char* file, int line);
void operator_delete(void* p);
}
static inline void Close3695C0(S3695C0* s)
{
    if (s->x0 >= 0) {
        func_003A6F10(s);
        if (s->b40) {
            void* p = s->pC4;
            if (p) {
                {
                    AllocGuard g;
                    Mem_Free(0, p, D_004BBDD0, 0x1DD);
                }
                s->x3C = 0;
            }
        }
        s->x0 = -1;
        s->x28 = 0;
        s->pC4 = 0;
        s->b41 = 0;
        s->b40 = 0;
        s->x3C = 0;
    }
}extern "C" void func_003695C0(S3695C0* s)
{
    Close3695C0(s);
}
#pragma pop /* merge_units */
/* merge_units: end func_003695C0 */

/* merge_units: begin func_003696B0 */
#pragma push /* merge_units */
extern int func_00369050(int, int, int);

int func_003696B0(int a0, int a1, int a2) {
    int v0;
    int cond;

    v0 = *(int*)(char*)a0;
    cond = v0 < 0;
    if (cond) goto L003696D0;
    *(int*)((char*)a0 + 40) = a2;
    goto L003696E0;
L003696D0:;
    v0 = func_00369050(a0, a1, a2);
    goto L003696E8;
L003696E0:;
    v0 = 0 + 1;
L003696E8:;
    goto ret;
ret:
    return v0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003696B0 */

/* merge_units: begin func_00369700 */
#pragma push /* merge_units */
#pragma cplusplus on
struct S369700 { int x0; char pad4[0x24]; int x28; char pad2C[0x10]; int x3C; unsigned char b40; unsigned char b41; char pad42[0xC4 - 0x42]; void* pC4; };
extern "C" {
#if 0 /* merge_units */
void func_003A6F10(S369700* s);
#endif /* merge_units */
#define func_003A6F10(a0) (func_003A6F10((S3695C0 *)(a0))) /* merge_units */

}
static inline void Close369700(S369700* s)
{
    if (s->x0 >= 0) {
        func_003A6F10(s);
        if (s->b40) {
            void* p = s->pC4;
            if (p) {
                {
                    AllocGuard g;
                    Mem_Free(0, p, D_004BBDD0, 0x1DD);
                }
                s->x3C = 0;
            }
        }
        s->x0 = -1;
        s->x28 = 0;
        s->pC4 = 0;
        s->b41 = 0;
        s->b40 = 0;
        s->x3C = 0;
    }
}extern "C" S369700* func_00369700(S369700* self, short del)
{
    if (self) {
        Close369700(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef func_003A6F10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00369700 */

/* merge_units: begin func_00369820 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * FileHalPS2.cc: PS2 file HAL handle construction.
 */

#include "FileHalPS2_types.h"

extern FileHalFile* D_00533860;
#if 0 /* merge_units */
extern int func_00369050(FileHalFile* file, int a1, int a2);
#endif /* merge_units */
#define func_00369050(a0, a1, a2) (func_00369050((int)(a0), (a1), (a2))) /* merge_units */


/* Construct a closed handle, then initialise it from (a1, a2). */
FileHalFile* func_00369820(FileHalFile* file, int a1, int a2) {
    file->handle = -1;
    file->unk28 = 0;
    file->unkC4 = 0;
    file->unk41 = 0;
    file->unk40 = 0;
    file->unk3C = 0;
    func_00369050(file, a1, a2);
    return file;
}

/* Default constructor: closed handle with cleared state. */
FileHalFile* func_00369870(FileHalFile* file) {
    file->handle = -1;
    file->unk28 = 0;
    file->unkC4 = 0;
    file->unk41 = 0;
    file->unk40 = 0;
    file->unk3C = 0;
    return file;
}

/* Store the global file HAL pointer. */
void func_003698A0(FileHalFile* file) {
    D_00533860 = file;
}
#undef func_00369050 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00369820 */
