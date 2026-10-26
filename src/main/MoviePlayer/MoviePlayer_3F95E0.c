/*
 * main/MoviePlayer: 3 files, 003F95E0-003F96B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F95E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

Word* std_list_deleter_cHogFile_generic_iterator_ctor(Word* self, int value) {
    self->value = value;
    return self;
}

void* std_list_deleter_cHogFile_tail(char* self) {
    return self + 4;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F95E0 */

/* merge_units: begin func_003F9600 */
#pragma push /* merge_units */
typedef struct N9600 { int m0; struct N9600* next; char name[4]; } N9600;
extern N9600* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(void* list);
#if 0 /* merge_units */
extern void* std_list_deleter_cHogFile_tail(void* self);
#endif /* merge_units */
#define std_list_deleter_cHogFile_tail(a0) (std_list_deleter_cHogFile_tail((char *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void std_list_deleter_cHogFile_generic_iterator_ctor(N9600** out, void* v);
#endif /* merge_units */
#define std_list_deleter_cHogFile_generic_iterator_ctor(a0, a1) ((void)std_list_deleter_cHogFile_generic_iterator_ctor((Word *)(a0), (int)(a1))) /* merge_units */

extern int String_CompareNoCase(const char* a, const char* b);
char* cHogList_Get(char* self, const char* name)
{
    N9600* e;
    N9600* n;
    for (n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(self + 4)->next; std_list_deleter_cHogFile_generic_iterator_ctor(&e, std_list_deleter_cHogFile_tail(self)), n != e; n = n->next) {
        if (!String_CompareNoCase(n->name, name))
            return n->name;
    }
    return 0;
}
#undef std_list_deleter_cHogFile_tail /* merge_units */
#undef std_list_deleter_cHogFile_generic_iterator_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9600 */

/* merge_units: begin func_003F96B0 */
#pragma push /* merge_units */
extern L4Archive* Archive_Open(int, int, int, int);

/* Opens an archive and sets the byte at +0x168 on the returned handle. */
L4Archive* cHogList_OpenProtected(int a0, int a1, int a2) {
    L4Archive* ar = Archive_Open(a0, a1, a2, 0);

    ar->unk168 = 1;
    return ar;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F96B0 */
