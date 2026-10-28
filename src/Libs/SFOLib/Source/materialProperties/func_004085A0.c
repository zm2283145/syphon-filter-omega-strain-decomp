#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct MStr { int a; int b; int c; };
extern "C" {
void cString_ctor_void(MStr* s);
void String_Dtor(void* s, int flag);
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
void std_basic_string_char_char_traits_char_ctor_charP(MStr* s, const char* c);
void std_tree_pair_cString_value_compare_find_cStringR_3(MIt* out, void* map, MStr* key);
void String_Dtor(void* s, int flag);
void String_Dtor_138350(void* s, int flag);
void std_map_cString_char_end(MIt* out, void* map);
void cAssocArray_cString_char_Iterator_ctor(MIt* out, MIt* src);
void std_basic_string_char_char_traits_char_assign_basicstringR(MStr* d, const MStr* s);
void cString_ctor_void(MStr* s);
void cString_ctor_charP(MStr* s, const char* c);
void cString_opAssign(MStr* d, MStr* s);
void cMaterialProperties_MatPropInfo_ctor_void(void);
void cMaterialProperties_MatPropInfo_dtor(void);
void __construct_array(void* arr, void* ctor, void* dtor, int size, int count);
void __destroy_array(void* arr, void* dtor, int size, int count);
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






