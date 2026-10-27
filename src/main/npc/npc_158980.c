/*
 * main/npc: range (2 files, 00158980-001589D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00158980 */
#pragma push /* merge_units */
typedef struct { int unk0; int begin; int end; int unkC; int unk10; } Obj00158980;
extern void std_list_deleter_cLookAtListItem_erase(int* result, Obj00158980* obj, int* end, int** begin);
/* Clear the range [begin, end) and reset fields 0xC and 0x10. */
void cNPC_cActiveSlot_Init(Obj00158980* obj)
{
    int* begin = &obj->begin;
    int end = obj->end;
    int result;
    std_list_deleter_cLookAtListItem_erase(&result, obj, &end, &begin);
    obj->unkC = 0;
    obj->unk10 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00158980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00158980 */

/* merge_units: begin func_001589D0 */
#pragma push /* merge_units */
extern void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int* out, int* key, int* value, int** ref);
extern int g_NpcThinkList;
extern int D_004EA194;
extern int D_004EA198;
extern int g_NpcDeadList;
extern int D_004EA374;
extern int D_004EA378;
extern int D_004EA1B0;
extern int D_004EA1B4;
extern int D_004EA1B8;

/* Registers three static (key, value, ref) triples via std_list_deleter_voidPtr_erase_listdeleter_listdeleter. */
void cNPC_SystemClear(void) {
    int* ref3;
    int value3;
    int out3;
    int* ref2;
    int value2;
    int out2;
    int* ref1;
    int value1;
    int out1;

    ref1 = &D_004EA194;
    value1 = D_004EA198;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&out1, &g_NpcThinkList, &value1, &ref1);
    ref2 = &D_004EA374;
    value2 = D_004EA378;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&out2, &g_NpcDeadList, &value2, &ref2);
    ref3 = &D_004EA1B4;
    value3 = D_004EA1B8;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&out3, &D_004EA1B0, &value3, &ref3);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001589D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001589D0 */
