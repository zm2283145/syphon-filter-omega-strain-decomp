/*
 * main/specfx: 2 files, 003EBF10-003EBFB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EBF10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void func_003EBF10(void* node)
{
    AllocGuard guard;
    Mem_Free(0, node, "specfx.cc", 0xE9);
}
#pragma pop /* merge_units */
/* merge_units: end func_003EBF10 */

/* merge_units: begin func_003EBFB0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" { extern char D_004BE020[]; void* Mem_Alloc(int pool, int size, char* file, int line); }
extern "C" void* EffectService_Create(int size)
{
    AllocGuard guard;
    return Mem_Alloc(0, size, D_004BE020, 0xE3);
}
#pragma pop /* merge_units */
/* merge_units: end func_003EBFB0 */
