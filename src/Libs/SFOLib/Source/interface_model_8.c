/*
 * Libs/SFOLib/Source/interface_model: 3 files, 003EEB30-003EEE70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EEB30 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x6E]; unsigned short count; char p1[0x84 - 0x70]; void** list; } T3EEB30;
extern int std_basic_string_char_char_traits_char_compare_charP(void* s, const char* name);
void* cInterfaceModel_GetChild(T3EEB30* t, const char* name) {
    int i;
    for (i = 0; i < t->count; i++) {
        if (std_basic_string_char_char_traits_char_compare_charP(t->list[i], name) == 0) return t->list[i];
    }
    return 0;
}
static inline void merge_flush_func_003EEB30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EEB30 */

/* merge_units: begin func_003EEBE0 */
#pragma push /* merge_units */
#pragma inline_depth(8)
typedef struct Node_3EEBE0 {
    char pad0[0x60];
    char flag;
    char pad61[0xD];
    unsigned short count;
    char pad70[0x14];
    struct Node_3EEBE0 **children;
} Node_3EEBE0;

/* The recursive flag propagation as CodeWarrior inlined it into itself five levels deep. */
void cInterfaceModel_Activate(Node_3EEBE0 *n, char v, int recurse);

static inline void L5_3EEBE0(Node_3EEBE0 *n, char v)
{
    int i;
    n->flag = v;
    for (i = 0; i < n->count; i++) cInterfaceModel_Activate(n->children[i], v, 1);
}
static inline void L4_3EEBE0(Node_3EEBE0 *n, char v)
{
    int i;
    n->flag = v;
    for (i = 0; i < n->count; i++) L5_3EEBE0(n->children[i], v);
}
static inline void L3_3EEBE0(Node_3EEBE0 *n, char v)
{
    int i;
    n->flag = v;
    for (i = 0; i < n->count; i++) L4_3EEBE0(n->children[i], v);
}
static inline void L2_3EEBE0(Node_3EEBE0 *n, char v)
{
    int i;
    n->flag = v;
    for (i = 0; i < n->count; i++) L3_3EEBE0(n->children[i], v);
}
static inline void L1_3EEBE0(Node_3EEBE0 *n, char v)
{
    int i;
    n->flag = v;
    for (i = 0; i < n->count; i++) L2_3EEBE0(n->children[i], v);
}

void cInterfaceModel_Activate(Node_3EEBE0 *n, char v, int recurse)
{
    int i;
    n->flag = v;
    if (recurse) {
        for (i = 0; i < n->count; i++) L1_3EEBE0(n->children[i], v);
    }
}
static inline void merge_flush_func_003EEBE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EEBE0 */

/* merge_units: begin func_003EEE70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct VC_EE70 { virtual int v0(int); };
struct Raw_EE70 { int p; };
extern "C" {
void cMemMan_Deallocate(int, void*, char*, int);
void std_list_deleter_voidPtr_erase_listdeleter(int*, char*, int*);
Raw_EE70 std_list_deleter_voidPtr_begin_void(void*);
Raw_EE70 std_list_cInterfaceElementPtr_end(void*);
void std_list_cInterfaceElementPtr_generic_iterator_ctor(char**, const Raw_EE70&);
void cLListIterator_cInterfaceElementPtr_ctor(char**, const Raw_EE70&);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(int*, char**);
}
extern "C" void cInterfaceModel_DestroyInstance(char* self, VC_EE70* obj) {
    char* end;
    {
        VC_EE70* e;
        char* n;
        char* cur;
        char* it;
        std_list_cInterfaceElementPtr_generic_iterator_ctor(&it, std_list_deleter_voidPtr_begin_void(self + 0x8C));
        n = it;
        while ((cLListIterator_cInterfaceElementPtr_ctor(&end, std_list_cInterfaceElementPtr_end(self + 0x8C)), n != end)) {
            e = F_(n, 0x8, VC_EE70*);
            if (e == obj) {
                cur = n;
                n = F_(n, 0x4, char*);
                {
                    AllocGuard g;
                    e->v0(-1);
                    cMemMan_Deallocate(0, e, "interface_model.cc", 0x218);
                }
                {
                    char* c;
                    int res;
                    int pos;
                    c = cur;
                    std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos, &c);
                    std_list_deleter_voidPtr_erase_listdeleter(&res, self + 0x8C, &pos);
                }
            } else {
                n = F_(n, 0x4, char*);
            }
        }
    }
    if (F_(self, 0x8C, int) == 0) F_(self, 0x60, unsigned char) = 0;
}
static inline void merge_flush_func_003EEE70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EEE70 */
