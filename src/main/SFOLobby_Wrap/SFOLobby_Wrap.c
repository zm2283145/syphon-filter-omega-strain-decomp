/*
 * main/SFOLobby_Wrap: 2 files, 00443EA0-00443F40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00443EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void func_00443EA0(void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, "SFOLobby_Wrap.cc", 0x3A);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00443EA0 */

/* merge_units: begin func_00443F40 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(int, int, char *, int);                      
int memset(int, int, int);                              
extern char D_004C0B20;
extern unsigned char D_00533880;
}
extern "C" int func_00443F40(int arg0) {
    int temp_s1;

    if (arg0 <= 0) {
        return 0;
    }
    {
        AllocGuard g;
    temp_s1 = Mem_Alloc(0, arg0, &D_004C0B20, 0x1D);
    }
    if (temp_s1 == 0) {
        return 0;
    }
    memset(temp_s1, 0, arg0);
    return temp_s1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00443F40 */
