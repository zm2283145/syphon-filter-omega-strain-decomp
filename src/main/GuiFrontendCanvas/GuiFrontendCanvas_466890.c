/*
 * main/GuiFrontendCanvas: 2 files, 00466890-00466960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00466890 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004E1A20[]; extern char D_004E1940[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void GuiCanvas_ctor(void* self);
}
struct G00466890 { void* vtable; };
#define GW(off) (*(int*)((char*)p + (off)))
#define GB(off) (*(char*)((char*)p + (off)))
extern "C" G00466890* GuiGameCanvas_Create(void)
{
    G00466890* p;
    {
        AllocGuard guard;
        p = (G00466890*)Mem_Alloc(0, 0x78, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiCanvas_ctor(p);
        p->vtable = D_004E1A20; p->vtable = D_004E1940; GB(0x6C) = 0; GB(0x6D) = 0; GW(0x70) = 0; GW(0x74) = 0;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_00466890 */

/* merge_units: begin func_00466960 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004C2B38[];extern char D_004E19B0[];
}
struct G00466960 { void* vtable; };extern "C" G00466960* GuiFrontendCanvas_ctor(void)
{
    G00466960* p;
    {
        AllocGuard guard;
        p = (G00466960*)Mem_Alloc(0, 0x70, D_004C2B38, 0x2A);
    }
    if (p) {
        GuiCanvas_ctor(p);
        p->vtable = D_004E1A20; p->vtable = D_004E19B0; GW(0x6C) = 0;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_00466960 */
