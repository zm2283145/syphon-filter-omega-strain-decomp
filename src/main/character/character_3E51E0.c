/*
 * main/character: 3 files, 003E51E0-003E5360
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E51E0 */
#pragma push /* merge_units */
#include "types.h"
extern int func_002E9A10(void* reg);
extern int func_003FF2C0(void);
extern int func_002E9A98(void* desc, void* field, int size, int count);
extern int func_002E9F08(void* type, void* factory);
extern int D_0055A208;
extern void func_003E49B0(void);
unsigned char func_003E51E0(void* reg)
{
    struct { long long file; int pad; char a[16]; int b; int c; char d; } L;
    unsigned char ok = 0;
    if (func_002E9A10(reg) == 0 && func_003FF2C0() != 0
        && func_002E9A98(&L.file, L.a, 0x10, 1) == 0
        && func_002E9A98(&L.file, &L.b, 4, 1) == 0
        && func_002E9A98(&L.file, &L.c, 4, 1) == 0
        && func_002E9A98(&L.file, &L.d, 1, 1) == 0
        && func_002E9F08(&D_0055A208, func_003E49B0) == 0)
        ok = 1;
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E51E0 */

/* merge_units: begin func_003E52A0 */
#pragma push /* merge_units */
extern int Event_UnpackHeader(void* desc);
extern int func_002E9F08(void* t, void* fn);
extern int D_0055A200;
extern void func_003E4AF0(void);
unsigned char func_003E52A0(void* reg)
{
    struct { long long file; char padC[4]; int fC; int f10; int f14; char f18; } L;
    unsigned char ok = 0;
    if (func_002E9A10(reg) == 0 && func_003FF2C0() != 0
        && func_002E9A98(&L.file, &L.fC, 4, 1) == 0
        && func_002E9A98(&L.file, &L.f10, 4, 1) == 0
        && func_002E9A98(&L.file, &L.f14, 4, 1) == 0
        && func_002E9A98(&L.file, &L.f18, 1, 1) == 0
        && func_002E9F08(&D_0055A200, func_003E4AF0) == 0)
        ok = 1;
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E52A0 */

/* merge_units: begin func_003E5360 */
#pragma push /* merge_units */
extern int D_0055A1F8;
extern void func_003E4BE0(void);
unsigned char func_003E5360(void* reg)
{
    struct { long long file; char padC[4]; int fC; int f10; } L;
    unsigned char ok = 0;
    if (func_002E9A10(reg) == 0 && func_003FF2C0() != 0
        && func_002E9A98(&L.file, &L.fC, 4, 1) == 0
        && func_002E9A98(&L.file, &L.f10, 4, 1) == 0
        && func_002E9F08(&D_0055A1F8, func_003E4BE0) == 0)
        ok = 1;
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E5360 */
