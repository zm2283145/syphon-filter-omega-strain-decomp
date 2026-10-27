/*
 * Libs/SFOLib/Source/materialProperties: 1 file, 004089F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004089F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

/* cMaterialPropertiesTable_Init_cHogFileR: for every property slot of every material, request its particle
 * effect and resolve its texture name to a texture id (loading each distinct texture once through a
 * local name -> id map), then clear both names. */

struct MStr { unsigned int word; unsigned int length; char* data; };
struct MProp { MStr name; int fx; int f10; MStr s14; MStr tex; int texId; float f30; signed char b34; char pad35[3]; };
struct Material { MStr name; MProp props[5]; };
struct MVec { int a; int count; Material* data; unsigned char owned; };
struct MProps { void* map; MVec* vec; unsigned char inited; };
struct TNode { char pad[0x18]; int id; };
struct TIt { TNode* n; };
struct MIt { Material* p; };
struct TMap { char c[0x10]; };
struct TPair { MStr key; int val; };
struct TIns { void* node; unsigned char inserted; };
struct Res { char c[0xA0]; };
struct Alloc { char c; };
struct Cmp { char c; };

extern "C" {
extern char D_0053B540[];
extern char D_004BEB78[];
extern void* g_TextureMgr;
void cMaterialPropertiesTable_Init_void(MProps* s);
void std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_4(TMap* m, Cmp* c, Alloc* a);
void std_map_cString_int_dtor(TMap* m, int f);
Material** std_vector_deleter_cMaterialProperties_data(MVec* v);
Material* std_vector_imp_cMaterialProperties_end(MVec* v);
void std_vector_cMaterialProperties_pointer2iterator(MIt* out, MVec* v, Material** p);
int cString_Length(MStr* s);
char* std_basic_string_char_char_traits_char_c_str(MStr* s);
void std_basic_string_char_char_traits_char_do_replace(MStr* s, int pos, int n, const char* a, const char* b, Alloc al);
void std_basic_string_char_char_traits_char_ctor_basicstringR(MStr* d, MStr* s);
void String_Dtor(void* s, int f);
void Libc_Strcpy(char* d, const char* s);
char* strstr(const char* a, const char* b);
void Libc_Strcat(char* d, const char* s);
void cParticleSystem_RequestEffectLoad(void* lib, char* name, int* out);
void std_tree_pair_cString_value_compare_find_cStringR_4(TIt* out, TMap* m, MStr* key);
void std_map_cString_int_end(TIt* out, TMap* m);
void cAssocArray_cString_int_Iterator_ctor(TIt* out, TIt* in);
void std_make_pair_cString_int(TPair* out, MStr* k, int v);
void std_tree_pair_cString_value_compare_insert_one_pairR_4(TIns* out, TMap* m, TPair* p);
void cFileMan_ctor_void(Res* r);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(Res* r, char* name, int a, int b);
int cTexMan_AddTextureFromFile_cFileManR(void* mgr, Res* r);
void cFileMan_dtor(Res* r, int f);
void cMaterialPropertiesTable_Init_cHogFileR(MProps* s, int arc);
}

static inline char First(MStr* s) { return ((s->word & 1) ? s->data : (char*)s + 1)[0]; }
/* vector end() iterator; one inline level below NotEnd so the temp gets the lowest slot */
static inline void VecEnd(MIt* e, MVec* v)
{
    Material* t = std_vector_imp_cMaterialProperties_end(v);
    std_vector_cMaterialProperties_pointer2iterator(e, v, &t);
}
static inline bool NotEnd(Material* m, MVec* v, MIt* e)
{
    VecEnd(e, v);
    return (m == e->p) ^ 1;
}
static inline void TexEnd0(TIt* out, TMap* m)
{
    TIt e1;
    std_map_cString_int_end(&e1, m);
    cAssocArray_cString_int_Iterator_ctor(out, &e1);
}
/* the extra inline level puts e1 below the Clear allocators (retail's slot order) */
static inline void TexEnd(TIt* out, TMap* m) { TexEnd0(out, m); }
static inline void Clear(MStr* s) { Alloc a; std_basic_string_char_char_traits_char_do_replace(s, 0, -1, 0, 0, a); }

void cMaterialPropertiesTable_Init_cHogFileR(MProps* s, int arc)
{
    TMap texs;
    Material* m;
    TIt e2;
    TIt f;
    Cmp c;
    Alloc a;
    MIt e;
    if (!s->inited) cMaterialPropertiesTable_Init_void(s);
    std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_4(&texs, &c, &a);
    for (m = *std_vector_deleter_cMaterialProperties_data(s->vec); NotEnd(m, s->vec, &e); m++) {
        int i;
        for (i = 0; i < 5; i++) {
            MProp* pr = &m->props[i];
            if (cString_Length(&pr->name) && First(&pr->name)) {
                cParticleSystem_RequestEffectLoad(D_0053B540, std_basic_string_char_char_traits_char_c_str(&pr->name), &pr->fx);
                Clear(&pr->name);
            }
            if (cString_Length(&pr->tex) && First(&pr->tex)) {
                TNode* n;
                std_tree_pair_cString_value_compare_find_cStringR_4(&f, &texs, &pr->tex);
                n = f.n;
                TexEnd(&e2, &texs);
                if ((n == e2.n) ^ 1) {
                    pr->texId = n->id;
                } else {
                    char buf[0x40];
                    Res r;
                    int id;
                    Libc_Strcpy(buf, std_basic_string_char_char_traits_char_c_str(&pr->tex));
                    if (!strstr(buf, D_004BEB78)) Libc_Strcat(buf, D_004BEB78);
                    cFileMan_ctor_void(&r);
                    cFileMan_EncodeFilename_charP_cHogFileR_bool(&r, buf, arc, 0);
                    id = cTexMan_AddTextureFromFile_cFileManR(g_TextureMgr, &r);
                    pr->texId = id;
                    {
                        TIns ins;
                        MStr k;
                        TPair pa;
                        TPair pb;
                        std_basic_string_char_char_traits_char_ctor_basicstringR(&k, &pr->tex);
                        std_make_pair_cString_int(&pa, &k, id);
                        std_basic_string_char_char_traits_char_ctor_basicstringR(&pb.key, &pa.key);
                        pb.val = pa.val;
                        std_tree_pair_cString_value_compare_insert_one_pairR_4(&ins, &texs, &pb);
                        String_Dtor(&pb, 0);
                        String_Dtor(&pa, 0);
                        String_Dtor(&k, 0);
                    }
                    cFileMan_dtor(&r, -1);
                }
                Clear(&pr->tex);
            }
        }
    }
    std_map_cString_int_dtor(&texs, -1);
}
static inline void merge_flush_func_004089F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004089F0 */
