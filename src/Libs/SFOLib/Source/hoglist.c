/*
 * Libs/SFOLib/Source/hoglist: 5 files, 003F9520-003F95E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F9520 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(void* self) {
    return self;
}
static inline void merge_flush_func_003F9520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9520 */

/* merge_units: begin func_003F9530 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int String_CompareNoCase(int, int);
int cHogFile_CloseHog(int);
#if 0 /* merge_units */
int details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(int);
#endif /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(a0) ((int)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
int std_list_deleter_cHogFile_generic_iterator_ctor(int *, int);
#endif /* merge_units */
Word * std_list_deleter_cHogFile_generic_iterator_ctor(); /* merge_units */

#if 0 /* merge_units */
int std_list_deleter_cHogFile_tail(int);
#endif /* merge_units */
void * std_list_deleter_cHogFile_tail(); /* merge_units */


void cHogList_Close(int arg0, int arg1) {
    int sp4C;
    int var_s0;

    var_s0 = F_(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(arg0 + 4), 0x4, int);
    std_list_deleter_cHogFile_generic_iterator_ctor(&sp4C, std_list_deleter_cHogFile_tail(arg0));
    if (var_s0 != sp4C) {
        do {
            if (String_CompareNoCase(var_s0 + 8, arg1) == 0) {
                cHogFile_CloseHog(var_s0 + 8);
            }
            var_s0 = F_(var_s0, 0x4, int);
            std_list_deleter_cHogFile_generic_iterator_ctor(&sp4C, std_list_deleter_cHogFile_tail(arg0));
        } while (var_s0 != sp4C);
    }
}
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11 /* merge_units */
static inline void merge_flush_func_003F9530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9530 */

/* merge_units: begin func_003F95E0 */
#pragma push /* merge_units */
#include "loose04_types.h"

Word* std_list_deleter_cHogFile_generic_iterator_ctor(Word* self, int value) {
    self->value = value;
    return self;
}

void* std_list_deleter_cHogFile_tail(char* self) {
    return self + 4;
}
static inline void merge_flush_func_003F95E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F95E0 */

/* merge_units: begin func_003F9600 */
#pragma push /* merge_units */
typedef struct N9600 { int m0; struct N9600* next; char name[4]; } N9600;
#if 0 /* merge_units */
extern N9600* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(void* list);
#endif /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(a0) ((N9600 *)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11((a0))) /* merge_units */

#if 0 /* merge_units */
extern void* std_list_deleter_cHogFile_tail(void* self);
#endif /* merge_units */
#define std_list_deleter_cHogFile_tail(a0) (std_list_deleter_cHogFile_tail((char *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void std_list_deleter_cHogFile_generic_iterator_ctor(N9600** out, void* v);
#endif /* merge_units */
#define std_list_deleter_cHogFile_generic_iterator_ctor(a0, a1) ((void)std_list_deleter_cHogFile_generic_iterator_ctor((Word *)(a0), (int)(a1))) /* merge_units */


#if 0 /* merge_units */
extern int String_CompareNoCase(const char* a, const char* b);
#endif /* merge_units */
#define String_CompareNoCase(a0, a1) (String_CompareNoCase((int)(a0), (int)(a1))) /* merge_units */

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
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11 /* merge_units */
#undef std_list_deleter_cHogFile_tail /* merge_units */
#undef std_list_deleter_cHogFile_generic_iterator_ctor /* merge_units */
#undef String_CompareNoCase /* merge_units */
static inline void merge_flush_func_003F9600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9600 */

/* merge_units: begin func_003F96B0 */
#pragma push /* merge_units */
extern L4Archive* cHogList_Open(int, int, int, int);

/* Opens an archive and sets the byte at +0x168 on the returned handle. */
L4Archive* cHogList_OpenProtected(int a0, int a1, int a2) {
    L4Archive* ar = cHogList_Open(a0, a1, a2, 0);

    ar->unk168 = 1;
    return ar;
}
static inline void merge_flush_func_003F96B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F96B0 */
