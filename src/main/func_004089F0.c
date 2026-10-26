#pragma cplusplus on
#include "types.h"

/* MaterialProps_ResolveEffects: for every property slot of every material, request its particle
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
void MaterialProps_Init(MProps* s);
void std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_4(TMap* m, Cmp* c, Alloc* a);
void std_map_cString_int_dtor(TMap* m, int f);
Material** std_vector_deleter_cMaterialProperties_data(MVec* v);
Material* std_vector_imp_cMaterialProperties_end(MVec* v);
void std_vector_cMaterialProperties_pointer2iterator(MIt* out, MVec* v, Material** p);
int String_Length(MStr* s);
char* String_CStr(MStr* s);
void String_Replace(MStr* s, int pos, int n, const char* a, const char* b, Alloc al);
void String_CopyCtor(MStr* d, MStr* s);
void String_Dtor(void* s, int f);
void String_Copy(char* d, const char* s);
char* strstr(const char* a, const char* b);
void Libc_Strcat(char* d, const char* s);
void ParticleLib_Request(void* lib, char* name, int* out);
void std_tree_pair_cString_value_compare_find_cStringR_4(TIt* out, TMap* m, MStr* key);
void std_map_cString_int_end(TIt* out, TMap* m);
void cAssocArray_cString_int_Iterator_ctor(TIt* out, TIt* in);
void std_make_pair_cString_int(TPair* out, MStr* k, int v);
void std_tree_pair_cString_value_compare_insert_one_pairR_4(TIns* out, TMap* m, TPair* p);
void Resource_Construct(Res* r);
void Hog_Register(Res* r, char* name, int a, int b);
int TexMan_FindOrLoad(void* mgr, Res* r);
void FileMan_Release(Res* r, int f);
void MaterialProps_ResolveEffects(MProps* s, int arc);
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
static inline void Clear(MStr* s) { Alloc a; String_Replace(s, 0, -1, 0, 0, a); }

void MaterialProps_ResolveEffects(MProps* s, int arc)
{
    TMap texs;
    Material* m;
    TIt e2;
    TIt f;
    Cmp c;
    Alloc a;
    MIt e;
    if (!s->inited) MaterialProps_Init(s);
    std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_4(&texs, &c, &a);
    for (m = *std_vector_deleter_cMaterialProperties_data(s->vec); NotEnd(m, s->vec, &e); m++) {
        int i;
        for (i = 0; i < 5; i++) {
            MProp* pr = &m->props[i];
            if (String_Length(&pr->name) && First(&pr->name)) {
                ParticleLib_Request(D_0053B540, String_CStr(&pr->name), &pr->fx);
                Clear(&pr->name);
            }
            if (String_Length(&pr->tex) && First(&pr->tex)) {
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
                    String_Copy(buf, String_CStr(&pr->tex));
                    if (!strstr(buf, D_004BEB78)) Libc_Strcat(buf, D_004BEB78);
                    Resource_Construct(&r);
                    Hog_Register(&r, buf, arc, 0);
                    id = TexMan_FindOrLoad(g_TextureMgr, &r);
                    pr->texId = id;
                    {
                        TIns ins;
                        MStr k;
                        TPair pa;
                        TPair pb;
                        String_CopyCtor(&k, &pr->tex);
                        std_make_pair_cString_int(&pa, &k, id);
                        String_CopyCtor(&pb.key, &pa.key);
                        pb.val = pa.val;
                        std_tree_pair_cString_value_compare_insert_one_pairR_4(&ins, &texs, &pb);
                        String_Dtor(&pb, 0);
                        String_Dtor(&pa, 0);
                        String_Dtor(&k, 0);
                    }
                    FileMan_Release(&r, -1);
                }
                Clear(&pr->tex);
            }
        }
    }
    std_map_cString_int_dtor(&texs, -1);
}
