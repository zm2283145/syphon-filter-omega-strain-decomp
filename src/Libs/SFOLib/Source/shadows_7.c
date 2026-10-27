/*
 * Libs/SFOLib/Source/shadows: 1 file, 003D5750
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D5750 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int head; int value; } ListHead;
extern void std_list_deleter_int_erase_listdeleter_listdeleter(int* out, void* list, int* value, ListHead** head);

/* Calls std_list_deleter_int_erase_listdeleter_listdeleter on the list at +0x1175C with the head at +0x11760 and its value. */
void cShadowMan_Purge(char* self)
{
    ListHead* headp;
    int value;
    int result;
    ListHead* head = (ListHead*)(self + 0x11760);
    headp = head;
    value = head->value;
    std_list_deleter_int_erase_listdeleter_listdeleter(&result, self + 0x1175C, &value, &headp);
}
static inline void merge_flush_func_003D5750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D5750 */
