/*
 * SFOGame/Source/Loader: 8 files, 001BFE90-001C00C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BFE90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

int std_opNe_wrapiteratorR_wrapiteratorR(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Advance a byte iterator. */
ByteIter* std_wrap_iterator_basic_string_char_charPtr_opInc(ByteIter* it) {
    it->p = it->p + 1;
    return it;
}

unsigned char* std_wrap_iterator_basic_string_char_charPtr_opMul(ByteIter* it) {
    return it->p;
}
static inline void merge_flush_func_001BFE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BFE90 */

/* merge_units: begin func_001BFEE0 */
#pragma push /* merge_units */
typedef struct { unsigned char len : 7; unsigned char isLong : 1; } SB_1BFEE0;
typedef union { unsigned int word; SB_1BFEE0 b; } SW_1BFEE0;
typedef struct { SW_1BFEE0 h; unsigned int length; char* data; } SS_1BFEE0;
void std_basic_string_char_char_traits_char_end(char** out, SS_1BFEE0* s)
{
    char* d;
    unsigned int n;
    if (!(s->h.word & 1)) { d = (char*)s + 1; n = (unsigned char)(((unsigned long long)*(unsigned char*)s << 56) >> 57); }
    else { d = s->data; n = s->length; }
    *out = d + n;
}
static inline void merge_flush_func_001BFEE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BFEE0 */

/* merge_units: begin func_001BFF20 */
#pragma push /* merge_units */
typedef struct { unsigned int w0; int w4; char* ptr; } Str_1BFF20;
void std_basic_string_char_char_traits_char_begin(char** out, Str_1BFF20* s)
{
    *out = (s->w0 & 1) ? s->ptr : (char*)s + 1;
}
static inline void merge_flush_func_001BFF20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BFF20 */

/* merge_units: begin func_001BFF40 */
#pragma push /* merge_units */
typedef struct { unsigned int word; unsigned int length; char* data; } Str_1BFF40;
typedef struct { char pad[0x18]; void* anim; } TN_1BFF40;
typedef struct { TN_1BFF40* n; } It_1BFF40;
typedef struct { char d[0xA0]; } __attribute__((aligned(16))) File_1BFF40;
extern int SkaRegistry_AllModelsHaveKey(void* mgr, char* name);
extern int sprintf(char* buf, const char* fmt, ...);
extern void* cHogList_Get(void* fs, char* path);
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_1BFF40* s, char* c);
#if 0 /* merge_units */
extern void opAdd_cStringR_charP(Str_1BFF40* out, Str_1BFF40* a, char* b);
#endif /* merge_units */
int opAdd_cStringR_charP(); /* merge_units */

extern char* std_basic_string_char_char_traits_char_c_str(Str_1BFF40* s);
extern void cFileMan_ctor_charP_cHogFileR_bool(File_1BFF40* f, char* name, void* h, int x);
extern void String_Dtor(Str_1BFF40* s, int f);
extern void* cLoader_AllocateAndFillAnimationBuffer(void* mgr, File_1BFF40* f);
extern void std_tree_pair_cString_value_compare_begin(It_1BFF40* out, void* tree);
#if 0 /* merge_units */
extern void std_tree_pair_cString_value_compare_end(It_1BFF40* out, void* tree);
#endif /* merge_units */
void std_tree_pair_cString_value_compare_end(); /* merge_units */

extern void cSkaAnimationSet_AddAnimation_cStringR_cSkaAnimDataR(void* anim, Str_1BFF40* name, void* r);
extern void std_red_black_tree_1_increment(It_1BFF40* it);
extern void cFileMan_dtor(File_1BFF40* f, int x);
extern char D_0048B2F8[];
extern char D_004FFB8C[];
extern char D_004FFBC0[];
static inline int Eq_1BFF40(void* a, void* b) { return a == b; }
void cLoader_LoadSingleAnimation_FromHogWithLevelSpecificAnimations(void* mgr, char* name)
{
    It_1BFF40 it;
    It_1BFF40 b;
    It_1BFF40 e;
    Str_1BFF40 s1;
    Str_1BFF40 s2;
    Str_1BFF40 s3;
    char buf[0x88];
    File_1BFF40 file;
    void* h;
    void* r;
    if (SkaRegistry_AllModelsHaveKey(mgr, name)) return;
    sprintf(buf, "%s\\COMMON\\SKALEVEL.HOG", D_0048B2F8);
    h = cHogList_Get(D_004FFB8C, buf);
    if (!h) return;
    std_basic_string_char_char_traits_char_ctor_charP(&s1, name);
    opAdd_cStringR_charP(&s2, &s1, ".ska");
    cFileMan_ctor_charP_cHogFileR_bool(&file, std_basic_string_char_char_traits_char_c_str(&s2), h, 0);
    String_Dtor(&s2, 0);
    String_Dtor(&s1, 0);
    r = cLoader_AllocateAndFillAnimationBuffer(mgr, &file);
    if (r) {
        std_tree_pair_cString_value_compare_begin(&b, D_004FFBC0);
        it.n = b.n;
        std_tree_pair_cString_value_compare_end(&e, D_004FFBC0);
        h = e.n;
        while (Eq_1BFF40(it.n, h) ^ 1) {
            std_basic_string_char_char_traits_char_ctor_charP(&s3, name);
            cSkaAnimationSet_AddAnimation_cStringR_cSkaAnimDataR(it.n->anim, &s3, r);
            String_Dtor(&s3, 0);
            std_red_black_tree_1_increment(&it);
        }
    }
    cFileMan_dtor(&file, -1);
}
static inline void merge_flush_func_001BFF40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BFF40 */

/* merge_units: begin func_001C00C0 */
#pragma push /* merge_units */
void std_tree_pair_cString_value_compare_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_001C00C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C00C0 */

/* merge_units: begin func_001C00D0 */
#pragma push /* merge_units */
typedef struct { int w[3]; } String;
extern void std_basic_string_char_char_traits_char_ctor_basicstringR(String* dst, String* src);
extern void std_basic_string_char_char_traits_char_append_charP(String* s, int arg);
#if 0 /* merge_units */
extern void String_Dtor(String* s, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_1BFF40 *)(a0), (a1))) /* merge_units */

/* Copies src, transforms the copy with arg, and assigns it to dst. */
int opAdd_cStringR_charP(String* dst, String* src, int arg)
{
    String tmp;
    std_basic_string_char_char_traits_char_ctor_basicstringR(&tmp, src);
    std_basic_string_char_char_traits_char_append_charP(&tmp, arg);
    std_basic_string_char_char_traits_char_ctor_basicstringR(dst, &tmp);
    String_Dtor(&tmp, 0);
    return 0;
}
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_001C00D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C00D0 */

/* merge_units: begin func_001C0130 */
#pragma push /* merge_units */
extern char D_0049EE30[]; /* format string */
extern void cHogList_Close(void* target, const char* text);

/* Formats D_0048B2F8 into a local buffer and passes it to cHogList_Close. */
void cLoader_CloseHogWithLevelSpecificAnimations(void* self, void* target)
{
    char buf[0x80];
    sprintf(buf, D_0049EE30, D_0048B2F8);
    cHogList_Close(target, buf);
}
static inline void merge_flush_func_001C0130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C0130 */

/* merge_units: begin func_001C0180 */
#pragma push /* merge_units */
extern void cHogList_Open(void* target, char* text, int a, int b);

/* Formats D_0048B2F8 with the D_0049EE30 format and passes the text to cHogList_Open. */
void cLoader_OpenHogWithLevelSpecificAnimations_ForAccessByInitScript(void* self, void* target)
{
    char buf[0x80];
    sprintf(buf, D_0049EE30, D_0048B2F8);
    cHogList_Open(target, buf, 1, 0);
}
static inline void merge_flush_func_001C0180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C0180 */
