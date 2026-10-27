/*
 * main/gameFrontEnd: range (2 files, 002CC730-002CC7B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002CC730 */
#pragma push /* merge_units */
typedef struct { int size; char hdr[4]; void* first; } ListC730;
extern void std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter(void** res, ListC730* l, void** first, void** last);
extern void operator_delete(void* p);
ListC730* std_list_imp_MessageBoxEntry_dtor(ListC730* self, short deleteFlag)
{
    if (self) {
        if (self) {
            {
                void* res;
                void* first;
                void* last;
                last = self->hdr;
                first = self->first;
                std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter(&res, self, &first, &last);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC730(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC730 */

/* merge_units: begin func_002CC7B0 */
#pragma push /* merge_units */
typedef struct { int size; char hdr[4]; void* first; } ListC7B0;
#if 0 /* merge_units */
extern void std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter(void** res, ListC7B0* l, void** first, void** last);
#endif /* merge_units */
#define std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter(a0, a1, a2, a3) (std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter((a0), (void *)(a1), (a2), (a3))) /* merge_units */

ListC7B0* std_list_deleter_MessageBoxEntry_dtor(ListC7B0* self, short deleteFlag)
{
    if (self) {
        {
            {
                void* res;
                void* first;
                void* last;
                last = self->hdr;
                first = self->first;
                std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter(&res, self, &first, &last);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC7B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC7B0 */
