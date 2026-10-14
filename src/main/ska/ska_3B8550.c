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
int Name_Compare48(const char* a, const char* b, int n);
Node_3B8550* func_003B99D0(Tree_3B8550* t, Node_3B8550* y, bool comp, bool leftmost, const char* key);
static bool D_00493508 = true;
extern const bool D_00493510;
}
static inline bool Less_3B8550(const char* a, const char* b)
{
    return !(a[0] == 0 && b[0] == 0) && Name_Compare48(a, b, 0x20) < 0;
}
extern "C" void MotionRegistry_MapInsert(Res_3B8550* out, Tree_3B8550* t, const char* key)
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
        out->node = func_003B99D0(t, y, comp, leftmost, key);
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
extern void func_00397840(C6It_3B86D0*, C6Arr_3B86D0*, int);
extern void Array_DestroyRange(C6Arr_3B86D0*, C6It_3B86D0*, C6It_3B86D0*);
extern void func_00396810(void*, int, int, char*, int);
extern void func_003B92E0(C6Arr_3B86D0*);
extern char D_004BC4D0[];
void func_003B86D0(C6Arr_3B86D0* self) {
    C6It_3B86D0 first;
    C6It_3B86D0 last;
    func_00397840(&last, self, self->live);
    func_00397840(&first, self, 0);
    Array_DestroyRange(self, &first, &last);
    self->live = 0;
    if (self->state > 1) {
        while (self->state > 2) {
            void* p = self->items[self->index];
            if (p) func_00396810(p, 0, 0, D_004BC4D0, 100);
            func_003B92E0(self);
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
extern void func_003B86D0(Deq_3B87A0*);
#endif /* merge_units */
#define func_003B86D0(a0) (func_003B86D0((void *)(a0))) /* merge_units */

extern void* func_003AC450(Deq_3B87A0*);
extern void func_00397400(void*, int);
#if 0 /* merge_units */
extern void func_003B92E0(Deq_3B87A0*);
#endif /* merge_units */
#define func_003B92E0(a0) (func_003B92E0((void *)(a0))) /* merge_units */

void func_003B87A0(Deq_3B87A0* self) {
    if (self->size == 1) {
        func_003B86D0(self);
    } else {
        func_00397400(func_003AC450(self), -1);
        self->size--;
        self->pos++;
        while (self->pos >= 0x10) {
            void* p = self->blocks[self->first];
            if (p) func_00396810(p, 0, 0, D_004BC4D0, 100);
            func_003B92E0(self);
            self->pos -= 8;
        }
    }
}
#undef func_003B86D0 /* merge_units */
#undef func_003B92E0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B87A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B87A0 */
