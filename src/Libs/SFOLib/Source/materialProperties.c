/*
 * Libs/SFOLib/Source/materialProperties: 3 files, 004084D0-004085A0
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
#if 0 /* merge_units */
extern void std_map_cString_char_end(S4D0It* out, void* map);
#endif /* merge_units */
void std_map_cString_char_end(); /* merge_units */


#if 0 /* merge_units */
extern void cAssocArray_cString_char_Iterator_ctor(S4D0It* out, S4D0It* in);
#endif /* merge_units */
Word * cAssocArray_cString_char_Iterator_ctor(); /* merge_units */


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

/* merge_units: begin func_00408580 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Word* cAssocArray_cString_char_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cString_char_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_00408580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00408580 */

/* merge_units: begin func_004085A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

struct MStr { int a; int b; int c; };
extern "C" {
void cString_ctor_void(MStr* s);
#if 0 /* merge_units */
void String_Dtor(void* s, int flag);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((S4D0Str *)(a0), (a1))) /* merge_units */

void cMaterialProperties_MatPropInfo_ctor_void(void);
void cMaterialProperties_MatPropInfo_dtor(void);
void __construct_array(void* arr, void* ctor, void* dtor, int size, int count);
void __destroy_array(void* arr, void* dtor, int size, int count);
}
struct CStr { int a; int b; int c;
    CStr() { cString_ctor_void((MStr*)this); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~CStr() { String_Dtor(this, 0); }
};
struct MatPropInfo {
    MStr mParticleName;
    int mParticleID;
    int mSoundBankID;
    MStr mSoundName;
    MStr mDecalName;
    int mDecalID;
    float mDecalSize;
    signed char mDecalBlendMode;
    MatPropInfo& operator=(const MatPropInfo& s);
};
struct Material {
    CStr name;
    MatPropInfo props[5];
    Material() { __construct_array(props, cMaterialProperties_MatPropInfo_ctor_void, cMaterialProperties_MatPropInfo_dtor, 0x38, 5); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Material() { __destroy_array(props, cMaterialProperties_MatPropInfo_dtor, 0x38, 5); }
};struct MatRaw { MStr name; MatPropInfo props[5]; };
struct MVec { int a; int count; Material* data; };
struct MNode { char pad[0x18]; unsigned char val; };
struct MProps { void* map; MVec* vec; unsigned char inited; };
struct MIt { MNode* p; };
struct MPair { MStr key; unsigned char val; };
struct MRes { void* it; unsigned char ok; };

extern "C" {
void cMaterialPropertiesTable_Init_void(MProps* s);
#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_ctor_charP(MStr* s, const char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((S4D0Str *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_tree_pair_cString_value_compare_find_cStringR_3(MIt* out, void* map, MStr* key);
#endif /* merge_units */
#define std_tree_pair_cString_value_compare_find_cStringR_3(a0, a1, a2) (std_tree_pair_cString_value_compare_find_cStringR_3((S4D0It *)(a0), (a1), (S4D0Str *)(a2))) /* merge_units */

#if 0 /* merge_units */
void String_Dtor(void* s, int flag);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((S4D0Str *)(a0), (a1))) /* merge_units */

void String_Dtor_138350(void* s, int flag);
#if 0 /* merge_units */
void std_map_cString_char_end(MIt* out, void* map);
#endif /* merge_units */
#define std_map_cString_char_end(a0, a1) (std_map_cString_char_end((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cAssocArray_cString_char_Iterator_ctor(MIt* out, MIt* src);
#endif /* merge_units */
#define cAssocArray_cString_char_Iterator_ctor(a0, a1) ((void)cAssocArray_cString_char_Iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

void std_basic_string_char_char_traits_char_assign_basicstringR(MStr* d, const MStr* s);
void cString_ctor_charP(MStr* s, const char* c);
void cString_opAssign(MStr* d, MStr* s);
void std_vector_imp_cMaterialProperties_insert(MVec* v, Material* pos, int n, Material* value);
void std_basic_string_char_char_traits_char_ctor_basicstringR(MStr* d, const MStr* s);
void std_make_pair_cString_uchar(MPair* out, MStr* key, unsigned char val);
void std_tree_pair_cString_value_compare_insert_one_pairR_3(MRes* out, void* map, MPair* p);
}

inline MatPropInfo& MatPropInfo::operator=(const MatPropInfo& s0)
{
    std_basic_string_char_char_traits_char_assign_basicstringR(&mParticleName, &s0.mParticleName);
    mParticleID = s0.mParticleID;
    mSoundBankID = s0.mSoundBankID;
    std_basic_string_char_char_traits_char_assign_basicstringR(&mSoundName, &s0.mSoundName);
    std_basic_string_char_char_traits_char_assign_basicstringR(&mDecalName, &s0.mDecalName);
    mDecalID = s0.mDecalID;
    mDecalSize = s0.mDecalSize;
    mDecalBlendMode = s0.mDecalBlendMode;
    return *this;
}

static inline void Find(MIt* out, void* map, MStr* key)
{
    MIt tmp;
    std_tree_pair_cString_value_compare_find_cStringR_3(&tmp, map, key);
    out->p = tmp.p;
}

static inline void End(MIt* out, void* map)
{
    MIt tmp;
    std_map_cString_char_end(&tmp, map);
    cAssocArray_cString_char_Iterator_ctor(out, &tmp);
}

static inline bool Ne(MIt* a, MIt* b) { return !(a->p == b->p); }
static inline unsigned char* Deref(MIt* it) { return &it->p->val; }
static inline Material* At(MVec* v, int i) { return &v->data[i]; }
static inline int Size(MVec* v) { return v->count; }
static inline Material* Back(MVec* v) { return &v->data[v->count] - 1; }

static inline void SetName(Material* m, const char* name)
{
            MStr t;
            cString_ctor_charP(&t, name);
            cString_opAssign((MStr*)&m->name, &t);
            String_Dtor_138350(&t, -1);
}
static inline unsigned char AddMap(void* map, const MStr* name, unsigned char val)
{
    MRes r;
    MStr k;
    MPair p1;
    MPair p2;
    std_basic_string_char_char_traits_char_ctor_basicstringR(&k, name);
    std_make_pair_cString_uchar(&p1, &k, val);
    std_basic_string_char_char_traits_char_ctor_basicstringR(&p2.key, &p1.key);
    p2.val = p1.val;
    std_tree_pair_cString_value_compare_insert_one_pairR_3(&r, map, &p2);
    String_Dtor(&p2.key, 0);
    String_Dtor(&p1.key, 0);
    String_Dtor(&k, 0);
    return r.ok;
}

extern "C" unsigned char cMaterialPropertiesTable_AddPropertyInfo(MProps* s, const char* name, int propName, MatPropInfo& info)
{
    MIt it;
    Material* pp;

    if (!s->inited) cMaterialPropertiesTable_Init_void(s);
    {
        MStr key;
        std_basic_string_char_char_traits_char_ctor_charP(&key, name);
        Find(&it, s->map, &key);
        String_Dtor(&key, 0);
    }
    {
        MIt e;
        End(&e, s->map);
        if (Ne(&it, &e)) {
            unsigned int i9 = *Deref(&it) * 9;
            unsigned int i = *Deref(&it);
            ((Material*)((char*)s->vec->data + ((i9 << 3) + i) * 4))->props[(unsigned char)propName] = info;
            return 1;
        }
    }
    if (Size(s->vec) >= 0x80) return 0;
    {
        Material properties;
        
        SetName(&properties, name);
        properties.props[(unsigned char)propName] = info;
        std_vector_imp_cMaterialProperties_insert(s->vec, s->vec->data + s->vec->count, 1, &properties);
        {
            void* map = s->map;
            unsigned char val = (signed char)(unsigned char)(Size(s->vec) - 1);
            MStr* nm = (MStr*)&(&s->vec->data[*(volatile int*)&s->vec->count] - 1)->name;
            MRes r;
            MStr k;
            MPair p1;
            MPair p2;
            std_basic_string_char_char_traits_char_ctor_basicstringR(&k, nm);
            std_make_pair_cString_uchar(&p1, &k, val);
            std_basic_string_char_char_traits_char_ctor_basicstringR(&p2.key, &p1.key);
            p2.val = p1.val;
            std_tree_pair_cString_value_compare_insert_one_pairR_3(&r, map, &p2);
            String_Dtor(&p2.key, 0);
            String_Dtor(&p1.key, 0);
            String_Dtor(&k, 0);
        }

    }
    return 1;
}
#undef String_Dtor /* merge_units */
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_tree_pair_cString_value_compare_find_cStringR_3 /* merge_units */
#undef String_Dtor /* merge_units */
#undef std_map_cString_char_end /* merge_units */
#undef cAssocArray_cString_char_Iterator_ctor /* merge_units */
static inline void merge_flush_func_004085A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004085A0 */
