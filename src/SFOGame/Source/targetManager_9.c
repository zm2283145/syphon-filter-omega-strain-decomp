/*
 * SFOGame/Source/targetManager: 4 files, 0022D4F0-0022D740
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022D4F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "targetManager_types.h"
typedef struct { void* vt; char p4[0x1C]; void* arr[29]; char p94[0x7C]; char a110[0xC]; char a11C[4]; } M22D4F0;
extern "C" {
void cSystem_ctor(M22D4F0*, void*);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void* func_001005E0(void* p, void* ctor, int dtor, int size, int n);
void std_list_deleter_cSafePtr_cGOBJ_ctor(void*);
void cTargetManager_Reset(M22D4F0*);
void std_list_deleter_LosReqElem_ctor(void*);
extern char D_004DB850[];
extern char D_004F77A8[];
TargetSlot* cTargetManager_LosElem_ctor(TargetSlot* self);
}
#pragma push

#pragma opt_strength_reduction off

extern "C" M22D4F0* cTargetManager_ctor(M22D4F0* m) {
    int i;
    int n;
    int off;
    void* p;
    cSystem_ctor(m, D_004F77A8);
    m->vt = D_004DB850;
    std_list_deleter_LosReqElem_ctor(m->a110);
    std_list_deleter_cSafePtr_cGOBJ_ctor(m->a11C);
    for (i = 0, off = 0; i < 29; i++, off += 4) {
        n = 29 - i;
        { AllocGuard g; p = cMemMan_Allocate(0, (n << 4) + 0x10, "targetManager.cc", 0x2B); }
        *(void**)((char*)m + off + 0x20) = func_001005E0(p, (void*)cTargetManager_LosElem_ctor, 0, 0x10, n);
    }
    cTargetManager_Reset(m);
    return m;
}
#pragma pop
static inline void merge_flush_func_0022D4F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022D4F0 */

/* merge_units: begin func_0022D630 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

/* Constructor: clears the slot. */
TargetSlot* cTargetManager_LosElem_ctor(TargetSlot* self) {
    self->unk4 = 0;
    self->unk0 = 0;
    self->unkC = 0;
    self->unkD = 0;
    return self;
}
static inline void merge_flush_func_0022D630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022D630 */

/* merge_units: begin func_0022D650 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Node22D650 {
    Node22D650* prev;
    Node22D650* next;
    char name[16];
};

struct List22D650 {
    int size;
    Node22D650* sentinelPrev;
    Node22D650* first;
};

extern "C" {
int Libc_Memcmp(const char* a, const char* b, int n);
void std_list_deleter_LosReqElem_erase(Node22D650** result, List22D650* list, Node22D650** first, Node22D650** last);
}

struct NamePred22D650 {
    int pad;
    const char* name;
};

static inline bool NameEq22D650(Node22D650* n, const char* name) {
    bool r = !Libc_Memcmp(n->name, name, 16);
    return r;
}

#pragma push
#pragma opt_common_subs off
extern "C" void std_list_imp_LosReqElem_remove_if(List22D650* self, NamePred22D650 pred) {
    Node22D650* end = (Node22D650*)&self->sentinelPrev;
    Node22D650* i = self->first;
    const char* name = pred.name;
    while (i != end) {
        if (NameEq22D650(i, name)) {
            Node22D650* j = i->next;
            while (j != end) {
                if (!NameEq22D650(j, name)) {
                    break;
                }
                j = j->next;
            }
            {
                Node22D650* result;
                Node22D650* first;
                Node22D650* last;
                last = j;
                first = i;
                std_list_deleter_LosReqElem_erase(&result, self, &first, &last);
                i = result;
                if (result == end) {
                    break;
                }
            }
        }
        i = i->next;
    }
}
#pragma pop
static inline void merge_flush_func_0022D650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022D650 */

/* merge_units: begin func_0022D740 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Handle22D740 {
    void* obj;
    int id;
};

struct Node22D740 {
    Node22D740* prev;
    Node22D740* next;
    Handle22D740 value;
};

struct List22D740 {
    int size;
    Node22D740* sentinelPrev;
    Node22D740* first;
};

struct Pred22D740 {
    int pad;
    Handle22D740* target;
};

extern "C" {
bool std_equal_to_cSafePtr_cGOBJ_opCall(Pred22D740* self, Handle22D740* x, Handle22D740* y);
void std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(Node22D740** result, List22D740* list, Node22D740** first, Node22D740** last);
}

#pragma push
#pragma opt_common_subs off
extern "C" void std_list_imp_cSafePtr_cGOBJ_remove_if(List22D740* self, Pred22D740 pred) {
    Node22D740* end = (Node22D740*)&self->sentinelPrev;
    Node22D740* i = self->first;
    Handle22D740** tp;
    if (i != end) {
    tp = &pred.target;
    do {
        if (std_equal_to_cSafePtr_cGOBJ_opCall(&pred, &i->value, *tp)) {
            Node22D740* j = i->next;
            while (j != end) {
                if (!std_equal_to_cSafePtr_cGOBJ_opCall(&pred, &j->value, *tp)) {
                    break;
                }
                j = j->next;
            }
            {
                Node22D740* result;
                Node22D740* first;
                Node22D740* last;
                last = j;
                first = i;
                std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(&result, self, &first, &last);
                i = result;
                if (result == end) {
                    break;
                }
            }
        }
        i = i->next;
    } while (i != end);
    }
}
#pragma pop
static inline void merge_flush_func_0022D740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022D740 */
