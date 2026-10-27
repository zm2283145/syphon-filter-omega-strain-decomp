/*
 * Libs/SFOLib/Source/materialProperties: 1 file, 004084D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin manUtils_4084D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a; int b; int c; } S4D0Str;
typedef struct { char pad[0x18]; unsigned char val; } S4D0Node;
typedef struct { S4D0Node* n; } S4D0It;
typedef struct { void* map; int b; unsigned char ready; } S4D0Obj;
extern void std_basic_string_char_char_traits_char_ctor_charP(S4D0Str* s, const char* c);
extern void String_Dtor(S4D0Str* s, int del);
extern void std_tree_pair_cString_value_compare_find_cStringR_3(S4D0It* out, void* map, S4D0Str* key);
extern void std_map_cString_char_end(S4D0It* out, void* map);
extern void cAssocArray_cString_char_Iterator_ctor(S4D0It* out, S4D0It* in);
/* Looks up name in the object's map and returns its byte value. */
int cMaterialPropertiesTable_Lookup_charP_ucharR(S4D0Obj* o, const char* name, unsigned char* out) {
    S4D0It e2;
    S4D0It it;
    S4D0It e1;
    S4D0Str s;
    S4D0Node* n;
    if (!o->ready)
        return 0;
    std_basic_string_char_char_traits_char_ctor_charP(&s, name);
    std_tree_pair_cString_value_compare_find_cStringR_3(&it, o->map, &s);
    n = it.n;
    String_Dtor(&s, 0);
    std_map_cString_char_end(&e1, o->map);
    cAssocArray_cString_char_Iterator_ctor(&e2, &e1);
    if (n == e2.n)
        return 0;
    *out = n->val;
    return 1;
}
static inline void merge_flush_manUtils_4084D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end manUtils_4084D0 */
