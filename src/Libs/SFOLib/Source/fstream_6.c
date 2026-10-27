/*
 * Libs/SFOLib/Source/fstream: 4 files, 003EB8E0-003EB960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EB8E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */

#include "types.h"

/* List iterator dereference: address of the node payload at node +0x08. */
char* std_list_cFSDataPtr_generic_iterator_opMul(char** self) {
    return *self + 8;
}
static inline void merge_flush_func_003EB8E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB8E0 */

/* merge_units: begin func_003EB8F0 */
#pragma push /* merge_units */
typedef struct G7N { struct G7N* prev; struct G7N* next; } G7N;
void std_advance_listR_int(G7N** pp, int n)
{
    if (n >= 0) {
        while (n > 0) { *pp = (*pp)->next; n--; }
    } else {
        while (n < 0) { *pp = (*pp)->prev; n++; }
    }
}
static inline void merge_flush_func_003EB8F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB8F0 */

/* merge_units: begin func_003EB950 */
#pragma push /* merge_units */
/* begin() iterator of a pointer vector. */
void std_list_cFSDataPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003EB950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB950 */

/* merge_units: begin func_003EB960 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: own cleanup, then the base destructor. */
extern "C" void operator_delete(void* allocation);
extern "C" void cFileStreamMan_Purge(void* self);
extern "C" void* std_list_cFSDataPtr_dtor(void* self, short deleteFlag);

extern "C" void* cFileStreamMan_dtor(void* self, short deleteFlag)
{
    if (self) {
        cFileStreamMan_Purge(self);
        if (self)
            std_list_cFSDataPtr_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003EB960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB960 */
