/*
 * SFOGame/Source/Loader: 10 files, 001C3C30-001C40F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C3C30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

/* v.back(): address of the last element. */
int* std_vector_charPtr_back(PtrVec* v) {
    return v->data + v->count - 1;
}
static inline void merge_flush_func_001C3C30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C3C30 */

/* merge_units: begin func_001C3C50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* load a file member into a fresh buffer and hand it to the owner's buffer list (creating the list on first use) */
struct Buf_3C50 { char* p; };
typedef struct { int a; char name[1]; } File_3C50;
struct List_3C50 { char pad[0xC]; unsigned char owned; };
typedef struct { char pad[0x10]; List_3C50* list; } Self_3C50;
extern "C" {
int cFileMan_Open(File_3C50* f);
int cFileMan_GetSize(File_3C50* f);
int cFileMan_Read_charPP_int(File_3C50* f, char** buf, int size);
void cFileMan_Close(File_3C50* f);
void* cMemMan_Allocate(int a, int size, char* file, int line);
void std_vector_charPtr_ctor_void(List_3C50* l);
void std_vector_charPtr_push_back_charPR(List_3C50* list, Buf_3C50* buf);
extern char D_0049EE88;
char* cLoader_AllocateAndFillAnimationBuffer(Self_3C50* self, File_3C50* f);
}
static inline void MemCopy_3C50(void* dst, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
char* cLoader_AllocateAndFillAnimationBuffer(Self_3C50* self, File_3C50* f)
{
    Buf_3C50 buf;
    Buf_3C50 tmp;
    int size;
    int r;
    r = cFileMan_Open(f);
    if (!(r & 0xFF)) {
        size = cFileMan_GetSize(f);
        { char* p; { AllocGuard g; p = (char*)cMemMan_Allocate(0, size, &D_0049EE88, 0xDB); } buf.p = p; }
        if (buf.p) {
            tmp = buf;
            r = cFileMan_Read_charPP_int(f, &tmp.p, size);
            cFileMan_Close(f);
            if (!(r & 0xFF)) {
                { char* dst; char* src = tmp.p; dst = buf.p; if (src != dst) MemCopy_3C50(dst, src, size); }
                if (!self->list) {
                    List_3C50* l;
                    { AllocGuard g; l = (List_3C50*)cMemMan_Allocate(0, 0x10, &D_0049EE88, 0xF1); }
                    if (l) { std_vector_charPtr_ctor_void(l); l->owned = 1; }
                    self->list = l;
                }
                std_vector_charPtr_push_back_charPR(self->list, &buf);
            }
        }
    }
    if (r & 0xFF) buf.p = 0;
    return buf.p;
}
static inline void merge_flush_func_001C3C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C3C50 */

/* merge_units: begin func_001C3E90 */
#pragma push /* merge_units */
#include "canonical_key_copy.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

typedef struct { char c[0x30]; } __attribute__((aligned(16))) Key_1C3E90;
typedef struct { char pad[0x24]; int tree; } Map_1C3E90;
typedef struct { char pad[0xC]; Map_1C3E90* second; } Val_1C3E90;
typedef struct { char pad[0xC]; Val_1C3E90 v; } Node_1C3E90;
typedef struct { Node_1C3E90* n; } It_1C3E90;
extern char D_004FFBC0[];
extern void std_tree_pair_cString_value_compare_begin(It_1C3E90* out, void* tree);
extern void std_tree_pair_cString_value_compare_end(It_1C3E90* out, int tree);
extern void std_red_black_tree_1_increment(It_1C3E90* it);
extern void cAssocArray_cString16N_3_int_Find(It_1C3E90* out, int* tree, Key_1C3E90* key);
extern void cAssocArray_cString16N_3_int_End(It_1C3E90* out, int* tree);
extern int cAssocArray_cString16N_3_int_ConstIterator_opNe(It_1C3E90* a, It_1C3E90* b);
static inline unsigned char EqB_1C3E90(void* a, void* b) { return a == b; }
static inline int Eq_1C3E90(void* a, void* b) { return a == b; }
#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
unsigned char SkaRegistry_AllModelsHaveKey(void* mgr, char* name)
{
    It_1C3E90 it;
    It_1C3E90 end;
    It_1C3E90 b;
    It_1C3E90 e;
    It_1C3E90 f;
    It_1C3E90 g;
    Key_1C3E90 key;
    unsigned char ok = 1;
    std_tree_pair_cString_value_compare_begin(&b, D_004FFBC0);
    it.n = b.n;
    std_tree_pair_cString_value_compare_end(&e, (int)D_004FFBC0);
    end.n = e.n;
    while ((Eq_1C3E90(it.n, end.n) != 0) ^ 1) {
        Val_1C3E90* v = &it.n->v;
        Map_1C3E90** pm = &v->second;
        Map_1C3E90* m;
        CANONICAL_KEY_INIT_IX(key.c, name)
        m = *pm;
        cAssocArray_cString16N_3_int_Find(&f, &m->tree, &key);
        cAssocArray_cString16N_3_int_End(&g, &m->tree);
        if (!cAssocArray_cString16N_3_int_ConstIterator_opNe(&f, &g)) { ok = 0; break; }
        std_red_black_tree_1_increment(&it);
    }
    return ok;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C3E90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C3E90 */

/* merge_units: begin func_001C4000 */
#pragma push /* merge_units */
typedef struct { int* p; } It_1C4000;
typedef struct { int cap; int count; int* data; } Vec_1C4000;
typedef struct { char pad[0xC]; Vec_1C4000* vec; } Obj_1C4000;
#if 0 /* merge_units */
extern char D_0049EE88[];
#endif /* merge_units */
#define D_0049EE88 ((char*)&D_0049EE88) /* merge_units */


#if 0 /* merge_units */
extern int* std_vector_imp_cTerrainPtr_1_begin(Vec_1C4000* v);
#endif /* merge_units */
int * std_vector_imp_cTerrainPtr_1_begin(); /* merge_units */

#if 0 /* merge_units */
extern int* std_vector_imp_cTerrainPtr_1_end(Vec_1C4000* v);
#endif /* merge_units */
int * std_vector_imp_cTerrainPtr_1_end(); /* merge_units */

#if 0 /* merge_units */
extern void std_vector_cTerrainPtr_pointer2iterator(It_1C4000* out, Vec_1C4000* v, int** src);
#endif /* merge_units */
void std_vector_cTerrainPtr_pointer2iterator(); /* merge_units */

extern void cTerrain_FinalizeActivation(int id);
extern void cTimerDisable_ctor(int* g);
extern void cTimerDisable_dtor(int* g, int f);
#if 0 /* merge_units */
extern void cArray_cTerrainPtr_dtor(Vec_1C4000* v, int f);
#endif /* merge_units */
void* cArray_cTerrainPtr_dtor(void* self, short deleteFlag); /* merge_units */
#define cArray_cTerrainPtr_dtor(a0, a1) ((void)cArray_cTerrainPtr_dtor((void *)(a0), (short)(a1))) /* merge_units */

void cLoader_FinalizeActivation(Obj_1C4000* o)
{
    It_1C4000 it;
    It_1C4000 end;
    int* tb;
    int* te;
    int g[1];
    Vec_1C4000* v;
    int* p;
    int* e;
    v = o->vec;
    tb = std_vector_imp_cTerrainPtr_1_begin(v);
    std_vector_cTerrainPtr_pointer2iterator(&it, v, &tb);
    v = o->vec;
    p = it.p;
    te = std_vector_imp_cTerrainPtr_1_end(v);
    std_vector_cTerrainPtr_pointer2iterator(&end, v, &te);
    e = end.p;
    if ((p == *(int* volatile*)&end.p) ^ 1) {
        do {
            cTerrain_FinalizeActivation(*p++);
        } while ((p == e) ^ 1);
    }
    v = o->vec;
    cTimerDisable_ctor(g);
    cArray_cTerrainPtr_dtor(v, -1);
    cMemMan_Deallocate(0, v, D_0049EE88, 0xAC);
    cTimerDisable_dtor(g, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C4000(void) {}
#undef D_0049EE88 /* merge_units */
#undef cArray_cTerrainPtr_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C4000 */

/* merge_units: begin func_001C40F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"
DEFINE_BASE_DTOR_CHAIN(cArray_cTerrainPtr_dtor, std_vector_imp_cTerrainPtr_1_dtor)
static inline void merge_flush_func_001C40F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C40F0 */

/* merge_units: begin func_001C4150 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc: pointer-vector helpers.
 */


/* End pointer. */
int* std_vector_imp_cTerrainPtr_1_end(PtrVec* v) {
    return v->data + v->count;
}

/* Copy an iterator. */
void std_vector_cTerrainPtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* Data pointer. */
int* std_vector_imp_cTerrainPtr_1_begin(PtrVec* v) {
    return v->data;
}
static inline void merge_flush_func_001C4150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C4150 */

/* merge_units: begin func_001C4190 */
#pragma push /* merge_units */
typedef struct { int w[8]; } Pop_1C4190;
extern char D_0048B2F8[];
extern char g_Game[];
extern char g_LevelDirName[];
extern void cMachine_ShowLoadingScreen(void* a, char* name, int x);
extern void* GetMachine(void);
extern int sprintf(char* buf, const char* fmt, ...);
extern int cHogList_Open(void* a, char* name, int b, int c);
extern void cPopulation_ctor(Pop_1C4190* p, char* name, int h);
extern void cGameSystem_LoadWeaponDB(void* w, Pop_1C4190* p, void* arc);
extern void cLoader_PreAllocLights(void* l, Pop_1C4190* p);
extern void cLoader_LoadLights(void* l, Pop_1C4190* p);
extern void cLoader_LoadCameras(void* l, Pop_1C4190* p);
extern void cLoader_LoadEffects(void* l, Pop_1C4190* p, void* arc);
extern void cLoader_LoadModels(void* l, int h, Pop_1C4190* p, void* arc);
extern void cLoader_ProcessLightsActivation(void* l, Pop_1C4190* p);
extern void cLoader_LoadEnvSettings(void* l, Pop_1C4190* p);
extern void cLoader_LoadGenerators(void* l, Pop_1C4190* p);
extern void cLoader_LoadWeaponCrates(void* l, Pop_1C4190* p);
extern void cMemMan_DisallowConsolidation(void);
extern void cLoader_LoadNodeGroups(void* l, Pop_1C4190* p);
extern void cMemMan_AllowConsolidation(void);
extern void cLoader_LoadHotboxes(void* l, Pop_1C4190* p);
extern void cLoader_LoadFireObjs(void* l, Pop_1C4190* p);
#if 0 /* merge_units */
extern void cLoader_FinalizeActivation(void* l);
#endif /* merge_units */
#define cLoader_FinalizeActivation(a0) (cLoader_FinalizeActivation((Obj_1C4000 *)(a0))) /* merge_units */

extern void cPopulation_dtor(Pop_1C4190* p, int f);
void cLoader_LoadPop(void* l, void* arc)
{
    char name[128];
    Pop_1C4190 pop;
    int h;
    cMachine_ShowLoadingScreen(GetMachine(), "Loading Level Data...", 0);
    sprintf(name, "%s\\%s\\DATA.HOG", D_0048B2F8, g_LevelDirName, g_LevelDirName);
    h = cHogList_Open(arc, name, 1, 0);
    cPopulation_ctor(&pop, g_LevelDirName, h);
    cGameSystem_LoadWeaponDB(g_Game, &pop, arc);
    cLoader_PreAllocLights(l, &pop);
    cLoader_LoadLights(l, &pop);
    cLoader_LoadCameras(l, &pop);
    cLoader_LoadEffects(l, &pop, arc);
    cLoader_LoadModels(l, h, &pop, arc);
    cLoader_ProcessLightsActivation(l, &pop);
    cLoader_LoadEnvSettings(l, &pop);
    cLoader_LoadGenerators(l, &pop);
    cLoader_LoadWeaponCrates(l, &pop);
    cMemMan_DisallowConsolidation();
    cLoader_LoadNodeGroups(l, &pop);
    cMemMan_AllowConsolidation();
    cLoader_LoadHotboxes(l, &pop);
    cLoader_LoadFireObjs(l, &pop);
    cLoader_FinalizeActivation(l);
    cPopulation_dtor(&pop, -1);
}
#undef cLoader_FinalizeActivation /* merge_units */
static inline void merge_flush_func_001C4190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C4190 */

/* merge_units: begin func_001C4300 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int strlen(const char *);

typedef struct { int w0, w4, w8; } String;
#if 0 /* merge_units */
String* std_basic_string_char_char_traits_char_replace_uint_uint_charP(String* str, int pos, int count, const char* s); /* gsynth: defined below */
#endif /* merge_units */
String * std_basic_string_char_char_traits_char_replace_uint_uint_charP(); /* merge_units */

/* Short/long string header: bit 0 = long form, bits 1-7 = inline length. */
typedef struct StrHdr {
    unsigned isLong : 1;
    unsigned shortLen : 7;
    int longLen;
} StrHdr;

#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_replace_uint_uint_charP(StrHdr* str, int len, int start, int arg);
#endif /* merge_units */
String * std_basic_string_char_char_traits_char_replace_uint_uint_charP(); /* merge_units */




/* Forwards to std_basic_string_char_char_traits_char_replace_uint_uint_charP with the string's current length and start 0. */
void std_basic_string_char_char_traits_char_append_charP(StrHdr* str, int arg) {
    int len;
    if (*(int*)str & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->shortLen;
    }
    std_basic_string_char_char_traits_char_replace_uint_uint_charP(str, len, 0, arg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C4300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C4300 */

/* merge_units: begin func_001C4330 */
#pragma push /* merge_units */
typedef struct { char unused; } Alloc; /* empty allocator object passed by value */

extern String* std_basic_string_char_char_traits_char_do_replace(String* str, int pos, int count, const char* first, const char* last, Alloc alloc);
/* Replaces count characters at pos with the C string s. */
String* std_basic_string_char_char_traits_char_replace_uint_uint_charP(String* str, int pos, int count, const char* s)
{
    Alloc alloc;
    return std_basic_string_char_char_traits_char_do_replace(str, pos, count, s, s + strlen(s), alloc);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C4330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C4330 */

/* merge_units: begin func_001C43A0 */
#pragma push /* merge_units */
typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; char* longData; } SsoString;

extern int std_basic_string_char_char_traits_char_compare_uint_uint_charP_uint(SsoString* self, int pos, int n, const char* s, int len);

/* Compare the entire string with a C string; retain the legacy symbol name. */
int std_basic_string_char_char_traits_char_compare_charP(SsoString* self, const char* s)
{
    int len = strlen(s);
    return std_basic_string_char_char_traits_char_compare_uint_uint_charP_uint(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, s, len);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C43A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C43A0 */
