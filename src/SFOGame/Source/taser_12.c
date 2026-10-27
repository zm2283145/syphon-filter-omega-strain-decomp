/*
 * SFOGame/Source/taser: 2 files, 002665B0-00266630
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002665B0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void operator_delete(void* allocation);
struct TreeNode2;
struct TreeHolder { int head; int header; TreeNode2* first; };
extern "C" void std_list_deleter_TaserPulse_erase_listdeleter_listdeleter(TreeNode2** result, TreeHolder* self, TreeNode2** first, TreeNode2** last);
extern "C" TreeHolder* std_list_TaserPulse_dtor(TreeHolder* self, short deleteFlag) {
    if (self) {
        if (self) {
            if (self) {
                TreeNode2* result;
                TreeNode2* first;
                TreeNode2* last;
                last = (TreeNode2*)&self->header;
                first = self->first;
                std_list_deleter_TaserPulse_erase_listdeleter_listdeleter(&result, self, &first, &last);
            }
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_002665B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002665B0 */

/* merge_units: begin func_00266630 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Sub;
typedef struct {
    int unk0;           /* 0x00 */
    int owner;          /* 0x04 */
    unsigned char flag; /* 0x08 */
    char pad9[3];
    int unkC;           /* 0x0C */
    Sub sub;            /* 0x10 */
    char pad1D[3];
    char list[0xC];     /* 0x20 */
    int count;          /* 0x2C */
    int state;          /* 0x30 */
    char pad34[0x8C];
    int unkC0;          /* 0xC0 */
} S;
extern char D_004F8350[];
extern void std_vector_TaserPoint_ctor(Sub*);
extern void std_list_deleter_TaserPulse_ctor(void*);
extern void std_vector_cAirTaserPtr_push_back(void* registry, S** self);
/* Constructor: initialises members and registers the object in the global registry. */
S* cAirTaser_ctor(S* self, int owner)
{
    Sub* sub = &self->sub;
    std_vector_TaserPoint_ctor(sub);
    sub->ready = 1;
    std_list_deleter_TaserPulse_ctor(self->list);
    self->state = -2;
    self->count = 0;
    self->owner = owner;
    self->flag = 0;
    self->unk0 = 0;
    self->unkC = 0;
    self->unkC0 = 0;
    std_vector_cAirTaserPtr_push_back(D_004F8350, &self);
    return self;
}
static inline void merge_flush_func_00266630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00266630 */
