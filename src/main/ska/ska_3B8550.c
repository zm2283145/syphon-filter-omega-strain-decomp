/*
 * main/ska: range (3 files, 003B8550-003B87A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003B8550 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Node_3B8550 { struct Node_3B8550* left; struct Node_3B8550* right; int pad[2]; char name[0x20]; } Node_3B8550;
typedef struct { int pad; Node_3B8550* root; } Tree_3B8550;
typedef struct { Node_3B8550* node; bool inserted; } Res_3B8550;
extern "C" {
int Libc_Memcmp(const char* a, const char* b, int n);
Node_3B8550* std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_node_at_nodeP_bool_bool_pairR_2(Tree_3B8550* t, Node_3B8550* y, bool comp, bool leftmost, const char* key);
static bool D_00493508 = true;
extern const bool D_00493510;
}
static inline bool Less_3B8550(const char* a, const char* b)
{
    return !(a[0] == 0 && b[0] == 0) && Libc_Memcmp(a, b, 0x20) < 0;
}
extern "C" void std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_one_pairR_2(Res_3B8550* out, Tree_3B8550* t, const char* key)
{
    Node_3B8550* lb = 0;
    Node_3B8550* y = (Node_3B8550*)&t->root;
    Node_3B8550* x;
    bool comp = true;
    bool leftmost = comp;
    x = t->root;
    while (x != 0) {
        y = x;
        if (Less_3B8550(key, x->name)) {
            x = x->left;
            comp = true;
        } else {
            lb = x;
            x = x->right;
            comp = false;
            leftmost = false;
        }
    }
    if (lb == 0 || Less_3B8550(lb->name, key)) {
        out->node = std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_node_at_nodeP_bool_bool_pairR_2(t, y, comp, leftmost, key);
        out->inserted = D_00493508;
    } else {
        out->node = lb;
        out->inserted = D_00493510;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B8550(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B8550 */

/* merge_units: begin func_003B86D0 */
#pragma push /* merge_units */
typedef struct C6It_3B86D0 { Q q[2]; } C6It_3B86D0;
typedef struct C6Arr_3B86D0 { int pad0; unsigned int state; int index; void** items; int result; int live; } C6Arr_3B86D0;
extern void std_deque_deleter_common_cSkaSystem_Request_make_iterator(C6It_3B86D0*, C6Arr_3B86D0*, int);
extern void std_deque_deleter_cSkaSystem_Request_destroy(C6Arr_3B86D0*, C6It_3B86D0*, C6It_3B86D0*);
extern void opDelete_cSkaSystemRequestP_int_bool_charP_etc(void*, int, int, char*, int);
extern void _cdeque_deleter_int_1_pop_front(C6Arr_3B86D0*);
extern char D_004BC4D0[];
void std_deque_deleter_cSkaSystem_Request_clear(C6Arr_3B86D0* self) {
    C6It_3B86D0 first;
    C6It_3B86D0 last;
    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&last, self, self->live);
    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&first, self, 0);
    std_deque_deleter_cSkaSystem_Request_destroy(self, &first, &last);
    self->live = 0;
    if (self->state > 1) {
        while (self->state > 2) {
            void* p = self->items[self->index];
            if (p) opDelete_cSkaSystemRequestP_int_bool_charP_etc(p, 0, 0, D_004BC4D0, 100);
            _cdeque_deleter_int_1_pop_front(self);
        }
        self->result = 4;
    } else {
        self->result = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B86D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B86D0 */

/* merge_units: begin func_003B87A0 */
#pragma push /* merge_units */
typedef struct Deq_3B87A0 { unsigned int count; int unk4; unsigned int first; void** blocks; unsigned int pos; int size; } Deq_3B87A0;
#if 0 /* merge_units */
extern void std_deque_deleter_cSkaSystem_Request_clear(Deq_3B87A0*);
#endif /* merge_units */
#define std_deque_deleter_cSkaSystem_Request_clear(a0) (std_deque_deleter_cSkaSystem_Request_clear((void *)(a0))) /* merge_units */

extern void* std_deque_deleter_common_cSkaSystem_Request_front(Deq_3B87A0*);
extern void func_00397400(void*, int);
#if 0 /* merge_units */
extern void _cdeque_deleter_int_1_pop_front(Deq_3B87A0*);
#endif /* merge_units */
#define _cdeque_deleter_int_1_pop_front(a0) (_cdeque_deleter_int_1_pop_front((void *)(a0))) /* merge_units */

void std_deque_deleter_cSkaSystem_Request_pop_front(Deq_3B87A0* self) {
    if (self->size == 1) {
        std_deque_deleter_cSkaSystem_Request_clear(self);
    } else {
        func_00397400(std_deque_deleter_common_cSkaSystem_Request_front(self), -1);
        self->size--;
        self->pos++;
        while (self->pos >= 0x10) {
            void* p = self->blocks[self->first];
            if (p) opDelete_cSkaSystemRequestP_int_bool_charP_etc(p, 0, 0, D_004BC4D0, 100);
            _cdeque_deleter_int_1_pop_front(self);
            self->pos -= 8;
        }
    }
}
#undef std_deque_deleter_cSkaSystem_Request_clear /* merge_units */
#undef _cdeque_deleter_int_1_pop_front /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B87A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B87A0 */
