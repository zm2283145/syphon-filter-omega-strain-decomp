/*
 * main/game: 4 files, 0013BF00-0013C030
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013BF00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "member0_dtor.h"
DEFINE_NESTED_MEMBER0_DTOR(cKeyedRegistry_cString_cConsCommand_dtor, std_map_cString_cConsCommandPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0013BF00 */

/* merge_units: begin func_0013BF60 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" { void* cKeyedAutoRegisterObject_cString_cConsCommand_GetNonConstRegistry(void); void cKeyedRegistry_cString_cConsCommand_Unregister(void* a, void* b, void* c); void String_Dtor(void* p, short f); void operator_delete(void* p); }
extern "C" void* cConsCommand_dtor(void* self, short del)
{
    if (self) {
        if (self) {
            cKeyedRegistry_cString_cConsCommand_Unregister(cKeyedAutoRegisterObject_cString_cConsCommand_GetNonConstRegistry(), self, self);
            if (self) String_Dtor(self, 0);
        }
        if (del > 0) operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013BF60 */

/* merge_units: begin func_0013BFE0 */
#pragma push /* merge_units */
/* Short-string-optimized string: bit 0 of the first byte marks heap storage. */
typedef struct SsoString {
    union {
        struct { unsigned char isLong : 1; unsigned char shortLen : 7; } s;
        int flags;
    } h;
    int longLen;
    char* longData;
} SsoString;

typedef struct { char unused; } Allocator; /* empty allocator object passed by value */

/* Replaces count characters at pos with the range [first, last). */
extern void* std_basic_string_char_char_traits_char_do_replace(SsoString* str, int pos, int count, const char* first, const char* last, Allocator alloc);

/* Assigns the range [first, last) to the string (replaces the whole contents). */
void* std_basic_string_char_char_traits_char_assign_charP_charP_intP(SsoString* str, const char* first, const char* last)
{
    Allocator alloc;
    int len;
    if (!(str->h.flags & 1))
        len = (unsigned char)str->h.s.shortLen;
    else
        len = str->longLen;
    return std_basic_string_char_char_traits_char_do_replace(str, 0, len, first, last, alloc);
}
#pragma pop /* merge_units */
/* merge_units: end func_0013BFE0 */

/* merge_units: begin func_0013C030 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct N_0013C030 { N_0013C030* left; N_0013C030* right; int f8; char val[4]; };
extern "C" {
void cMemMan_Deallocate(int pool, void* p, const char* file, int line);
}
extern "C" void std_tree_pair_cString_value_compare_destroy_nodeP_2(void* t, N_0013C030* n)
{
    if (n->left) std_tree_pair_cString_value_compare_destroy_nodeP_2(t, n->left);
    if (n->right) std_tree_pair_cString_value_compare_destroy_nodeP_2(t, n->right);
    if (n->val) { if (n->val) String_Dtor(n->val, 0); }
    if (n) {
        AllocGuard g;
        cMemMan_Deallocate(0, n, "allocator.hh", 0x64);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0013C030 */
