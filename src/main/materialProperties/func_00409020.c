#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

/* MaterialProps_Init: build the material table once (a vector of materials and a name -> index
 * map) and register the default material. */

struct MVec { int a; int b; int c; unsigned char owned; };
struct MProps { void* map; MVec* vec; unsigned char inited; };
struct Material { char name[0xC]; char props[5][0x38]; };
struct It { int p; };

extern "C" {
extern char D_004BEB80[];
extern char D_004BEB98[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void details_compressed_pair_imp_cAllocator_cMaterialProperties_int_1_ctor(MVec* v, int n);
void std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_3(void* m, void* cmp, void* alloc);
void cAllocator_char_ctor(Material* m);
int* details_compressed_pair_imp_rep_s_2_first_void_2(Material* m);
void MaterialProp_SetDefaults(void);
void cMaterialProperties_MatPropInfo_dtor(void);
void __construct_array(void* arr, void* ctor, void* dtor, int size, int count);
void __destroy_array(void* arr, void* dtor, int size, int count);
void String_CtorCStr_13B480(char* s, char* c);
void String_AssignString(void* d, char* s);
void String_Dtor(void* s, int flag);
void cAssocArray_cString_char_Find(It* out, void* map, Material* key);
void cAssocArray_cString_char_End(It* out, void* map);
int cAssocArray_cString_char_Iterator_opNe(It* a, It* b);
unsigned char* cAssocArray_cString_char_Iterator_opMul(It* it);
Material* cArray_cMaterialProperties_opIndex(MVec* v, int i);
void func_004093E0(Material* d, Material* s);
int cArray_cMaterialProperties_Size(MVec* v);
void MaterialVec_PushBack(MVec* v, Material* m);
Material* MaterialVec_Back(MVec* v);
void cAssocArray_cString_char_Add(void* map, Material* m, signed char* idx);
void MaterialProps_Init(MProps* s);
}

static inline void Add(MProps* s, Material* m)
{
    It it;
    It end;
    signed char idx;
    if (!s->inited) MaterialProps_Init(s);
    cAssocArray_cString_char_Find(&it, s->map, m);
    cAssocArray_cString_char_End(&end, s->map);
    if (cAssocArray_cString_char_Iterator_opNe(&it, &end)) {
        func_004093E0(cArray_cMaterialProperties_opIndex(s->vec, *cAssocArray_cString_char_Iterator_opMul(&it)), m);
    } else if (cArray_cMaterialProperties_Size(s->vec) < 0x80) {
        MaterialVec_PushBack(s->vec, m);
        idx = cArray_cMaterialProperties_Size(s->vec) - 1;
        cAssocArray_cString_char_Add(s->map, MaterialVec_Back(s->vec), &idx);
    }
}

void MaterialProps_Init(MProps* s)
{
    if (s->inited) return;
    s->inited = 1;
    {
        MVec* v;
        {
            AllocGuard g;
            v = (MVec*)Mem_Alloc(0, 0x10, D_004BEB80, 0x64);
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
            m = Mem_Alloc(0, 0x10, D_004BEB80, 0x65);
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
        __construct_array(pm->props, MaterialProp_SetDefaults, cMaterialProperties_MatPropInfo_dtor, 0x38, 5);
        {
            char t[0xC];
            String_CtorCStr_13B480(t, D_004BEB98);
            String_AssignString(pm, t);
            String_Dtor(t, 0);
        }
        Add(s, &mat);
        __destroy_array(mat.props, cMaterialProperties_MatPropInfo_dtor, 0x38, 5);
        String_Dtor(&mat, 0);
    }
}
