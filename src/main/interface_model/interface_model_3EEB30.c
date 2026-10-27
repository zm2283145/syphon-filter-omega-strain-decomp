/*
 * main/interface_model: 2 files, 003EEB30-003EEBE0
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
#pragma pop /* merge_units */
/* merge_units: end func_003EEBE0 */
