#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Str_1C01D0 { unsigned int word; unsigned int length; char* data; };
struct It_1C01D0 { char* p; };
struct Pair_1C01D0 { Str_1C01D0 key; void* val; };
struct Ins_1C01D0 { void* node; unsigned char inserted; };
struct Tbl_1C01D0 { int f0; int count; };
struct Arc_1C01D0 { char pad0[0x148]; Tbl_1C01D0* f148; };
struct Ska_1C01D0 {
    int f0;
    char v4[0x10];
    char v14[0x10];
    char v24[0x10];
    char v34[0x10];
    char v44[0x10];
    int f54;
    int f58;
};
extern "C" {
extern char D_0048B2F8[];
extern char D_004FFBC0[];
int sprintf(char* buf, const char* fmt, ...);
Arc_1C01D0* cHogList_Open(void* a, char* name, int b, int c);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cArray_cString4_ctor(void*);
void cArray_charPtr_ctor(void*);
void cAssocArray_cString16N_3_int_ctor(void*);
void cArray_cSkaNodePtr_ctor(void*);
void cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ctor(void*);
int cHogFile_GetBlock_int(Arc_1C01D0* a, int i);
int cHogFile_GetBlockSize(Arc_1C01D0* a, int i);
char* cHogFile_GetBlockName(Arc_1C01D0* a, int i);
void cSkaAnimationSet_InitWithSkasFile_And_AddAllAnimationsFromSkaHog(Ska_1C01D0* p, int a, int b, Arc_1C01D0* c);
void std_basic_string_char_char_traits_char_ctor_charP(Str_1C01D0* s, char* c);
void std_basic_string_char_char_traits_char_begin(It_1C01D0* out, Str_1C01D0* s);
void std_basic_string_char_char_traits_char_end(It_1C01D0* out, Str_1C01D0* s);
int std_opNe_wrapiteratorR_wrapiteratorR(It_1C01D0* a, It_1C01D0* b);
char* std_wrap_iterator_basic_string_char_charPtr_opMul(It_1C01D0* a);
void std_wrap_iterator_basic_string_char_charPtr_opInc(It_1C01D0* a);
int std_basic_string_char_char_traits_char_compare_charP(Str_1C01D0* a, char* b);
void nHumanAnimData_BuildAnimations(Ska_1C01D0* p);
void std_basic_string_char_char_traits_char_ctor_basicstringR(Str_1C01D0* d, Str_1C01D0* s);
void std_make_pair_cString_cSkaAnimationSetP(Pair_1C01D0* out, Str_1C01D0* k, Ska_1C01D0* v);
void std_tree_pair_cString_value_compare_insert_one_pairR_2(Ins_1C01D0* out, void* t, Pair_1C01D0* k);
void String_Dtor(void* s, int f);
}
extern "C" void cLoader_LoadCoreAnimations(void* self, void* fs)
{
    char buf[0x80];
    Arc_1C01D0* tex;
    Arc_1C01D0* a;
    int n;
    int i;
    sprintf(buf, "%s\\COMMON\\SKA.HOG", D_0048B2F8);
    tex = cHogList_Open(fs, buf, 0, 0);
    sprintf(buf, "%s\\COMMON\\SKAS.HOG", D_0048B2F8);
    a = cHogList_Open(fs, buf, 0, 0);
    n = a->f148->count;
    for (i = 0; i < n; i++) {
        Ska_1C01D0* p;
        {
            AllocGuard g;
            p = (Ska_1C01D0*)cMemMan_Allocate(0, 0x5C, "Loader.cc", 0x637);
        }
        if (p) {
            p->f0 = 0;
            cArray_cString4_ctor(p->v4);
            cArray_charPtr_ctor(p->v14);
            cAssocArray_cString16N_3_int_ctor(p->v24);
            cArray_cSkaNodePtr_ctor(p->v34);
            cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ctor(p->v44);
            p->f54 = 0;
            p->f58 = 0;
        }
        {
            int x = cHogFile_GetBlock_int(a, i);
            cSkaAnimationSet_InitWithSkasFile_And_AddAllAnimationsFromSkaHog(p, x, cHogFile_GetBlockSize(a, i), tex);
        }
        {
            Str_1C01D0 s;
            It_1C01D0 it;
            It_1C01D0 end;
            std_basic_string_char_char_traits_char_ctor_charP(&s, cHogFile_GetBlockName(a, i));
            std_basic_string_char_char_traits_char_begin(&it, &s);
            std_basic_string_char_char_traits_char_end(&end, &s);
            while (std_opNe_wrapiteratorR_wrapiteratorR(&it, &end)) {
                if (*std_wrap_iterator_basic_string_char_charPtr_opMul(&it) >= 'a' && *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) <= 'z') *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) -= 0x20;
                std_wrap_iterator_basic_string_char_charPtr_opInc(&it);
            }
            if (!std_basic_string_char_char_traits_char_compare_charP(&s, "FEMALE.SKAS") || !std_basic_string_char_char_traits_char_compare_charP(&s, "MALE.SKAS"))
                nHumanAnimData_BuildAnimations(p);
            {
                Ins_1C01D0 r;
                Str_1C01D0 t;
                Pair_1C01D0 pa;
                Pair_1C01D0 pb;
                std_basic_string_char_char_traits_char_ctor_basicstringR(&t, &s);
                std_make_pair_cString_cSkaAnimationSetP(&pa, &t, p);
                std_basic_string_char_char_traits_char_ctor_basicstringR(&pb.key, &pa.key);
                pb.val = pa.val;
                std_tree_pair_cString_value_compare_insert_one_pairR_2(&r, D_004FFBC0, &pb);
                String_Dtor(&pb, 0);
                String_Dtor(&pa, 0);
                String_Dtor(&t, 0);
            }
            String_Dtor(&s, 0);
        }
    }
}
