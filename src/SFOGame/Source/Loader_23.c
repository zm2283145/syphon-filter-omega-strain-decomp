/*
 * SFOGame/Source/Loader: 6 files, 001C40F0-001C4300
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C40F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
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
extern void cLoader_FinalizeActivation(void* l);
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
static inline void merge_flush_func_001C4190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C4190 */

/* merge_units: begin func_001C4300 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int strlen(const char *);

typedef struct { int w0, w4, w8; } String;
String* std_basic_string_char_char_traits_char_replace_uint_uint_charP(String* str, int pos, int count, const char* s); /* gsynth: defined below */
/* Short/long string header: bit 0 = long form, bits 1-7 = inline length. */
typedef struct StrHdr {
    unsigned isLong : 1;
    unsigned shortLen : 7;
    int longLen;
} StrHdr;

#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_replace_uint_uint_charP(StrHdr* str, int len, int start, int arg);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_replace_uint_uint_charP(a0, a1, a2, a3) ((void)std_basic_string_char_char_traits_char_replace_uint_uint_charP((String *)(a0), (a1), (a2), (const char *)(a3))) /* merge_units */



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
#undef std_basic_string_char_char_traits_char_replace_uint_uint_charP /* merge_units */
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
