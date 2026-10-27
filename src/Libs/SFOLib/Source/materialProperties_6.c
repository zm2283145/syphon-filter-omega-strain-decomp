/*
 * Libs/SFOLib/Source/materialProperties: 1 file, 00409020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00409020 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

/* cMaterialPropertiesTable_Init_void: build the material table once (a vector of materials and a name -> index
 * map) and register the default material. */

struct MVec { int a; int b; int c; unsigned char owned; };
struct MProps { void* map; MVec* vec; unsigned char inited; };
struct Material { char name[0xC]; char props[5][0x38]; };
struct It { int p; };

extern "C" {
extern char D_004BEB80[];
extern char D_004BEB98[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void details_compressed_pair_imp_cAllocator_cMaterialProperties_int_1_ctor(MVec* v, int n);
void std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_3(void* m, void* cmp, void* alloc);
void cAllocator_char_ctor(Material* m);
int* details_compressed_pair_imp_rep_s_2_first_void_2(Material* m);
void cMaterialProperties_MatPropInfo_ctor_void(void);
void cMaterialProperties_MatPropInfo_dtor(void);
void __construct_array(void* arr, void* ctor, void* dtor, int size, int count);
void __destroy_array(void* arr, void* dtor, int size, int count);
void std_basic_string_char_char_traits_char_ctor_charP(char* s, char* c);
void std_basic_string_char_char_traits_char_assign_basicstringR(void* d, char* s);
void String_Dtor(void* s, int flag);
void cAssocArray_cString_char_Find(It* out, void* map, Material* key);
void cAssocArray_cString_char_End(It* out, void* map);
int cAssocArray_cString_char_Iterator_opNe(It* a, It* b);
unsigned char* cAssocArray_cString_char_Iterator_opMul(It* it);
Material* cArray_cMaterialProperties_opIndex(MVec* v, int i);
void func_004093E0(Material* d, Material* s);
int cArray_cMaterialProperties_Size(MVec* v);
void cArray_cMaterialProperties_PushBackActual(MVec* v, Material* m);
Material* cArray_cMaterialProperties_Back(MVec* v);
void cAssocArray_cString_char_Add(void* map, Material* m, signed char* idx);
void cMaterialPropertiesTable_Init_void(MProps* s);
}

static inline void Add(MProps* s, Material* m)
{
    It it;
    It end;
    signed char idx;
    if (!s->inited) cMaterialPropertiesTable_Init_void(s);
    cAssocArray_cString_char_Find(&it, s->map, m);
    cAssocArray_cString_char_End(&end, s->map);
    if (cAssocArray_cString_char_Iterator_opNe(&it, &end)) {
        func_004093E0(cArray_cMaterialProperties_opIndex(s->vec, *cAssocArray_cString_char_Iterator_opMul(&it)), m);
    } else if (cArray_cMaterialProperties_Size(s->vec) < 0x80) {
        cArray_cMaterialProperties_PushBackActual(s->vec, m);
        idx = cArray_cMaterialProperties_Size(s->vec) - 1;
        cAssocArray_cString_char_Add(s->map, cArray_cMaterialProperties_Back(s->vec), &idx);
    }
}

void cMaterialPropertiesTable_Init_void(MProps* s)
{
    if (s->inited) return;
    s->inited = 1;
    {
        MVec* v;
        {
            AllocGuard g;
            v = (MVec*)cMemMan_Allocate(0, 0x10, D_004BEB80, 0x64);
        }
        if (v) {
            details_compressed_pair_imp_cAllocator_cMaterialProperties_int_1_ctor(v, 0);
            v->b = 0;
            v->c = 0;
            v->owned = 1;
        }
        s->vec = v;
    }
    {
        void* m;
        {
            AllocGuard g;
            m = cMemMan_Allocate(0, 0x10, D_004BEB80, 0x65);
        }
        if (m) {
            char cmp[4];   /* empty comparator / allocator temporaries */
            char alloc[4];
            std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_3(m, cmp, alloc);
        }
        s->map = m;
    }
    {
        Material mat;
        int* z;
        /* the constructor's this pointer stays in s1 (the int round trip stops MW folding it) */
        Material* pm = (Material*)(int)&mat;
        cAllocator_char_ctor(pm);
        z = details_compressed_pair_imp_rep_s_2_first_void_2(pm);
        z[0] = 0;
        z[1] = 0;
        z[2] = 0;
        __construct_array(pm->props, cMaterialProperties_MatPropInfo_ctor_void, cMaterialProperties_MatPropInfo_dtor, 0x38, 5);
        {
            char t[0xC];
            std_basic_string_char_char_traits_char_ctor_charP(t, D_004BEB98);
            std_basic_string_char_char_traits_char_assign_basicstringR(pm, t);
            String_Dtor(t, 0);
        }
        Add(s, &mat);
        __destroy_array(mat.props, cMaterialProperties_MatPropInfo_dtor, 0x38, 5);
        String_Dtor(&mat, 0);
    }
}
static inline void merge_flush_func_00409020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00409020 */
