/*
 * main/human: 4 files, 001BFE90-001BFF40
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
#pragma pop /* merge_units */
/* merge_units: end func_001BFEE0 */

/* merge_units: begin func_001BFF20 */
#pragma push /* merge_units */
typedef struct { unsigned int w0; int w4; char* ptr; } Str_1BFF20;
void std_basic_string_char_char_traits_char_begin(char** out, Str_1BFF20* s)
{
    *out = (s->w0 & 1) ? s->ptr : (char*)s + 1;
}
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
extern void String_CtorCStr_13B480(Str_1BFF40* s, char* c);
extern void opAdd_cStringR_charP(Str_1BFF40* out, Str_1BFF40* a, char* b);
extern char* String_CStr(Str_1BFF40* s);
extern void cFileMan_ctor_charP_cHogFileR_bool(File_1BFF40* f, char* name, void* h, int x);
extern void String_Dtor(Str_1BFF40* s, int f);
extern void* cLoader_AllocateAndFillAnimationBuffer(void* mgr, File_1BFF40* f);
extern void std_tree_pair_cString_value_compare_begin(It_1BFF40* out, void* tree);
extern void std_tree_pair_cString_value_compare_end(It_1BFF40* out, void* tree);
extern void Skas_AppendAnimation(void* anim, Str_1BFF40* name, void* r);
extern void Tree_Successor(It_1BFF40* it);
extern void FileMan_Release(File_1BFF40* f, int x);
extern char D_0048B2F8[];
extern char D_004FFB8C[];
extern char D_004FFBC0[];
static inline int Eq_1BFF40(void* a, void* b) { return a == b; }
void SkaRegistry_LoadAnimation(void* mgr, char* name)
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
    String_CtorCStr_13B480(&s1, name);
    opAdd_cStringR_charP(&s2, &s1, ".ska");
    cFileMan_ctor_charP_cHogFileR_bool(&file, String_CStr(&s2), h, 0);
    String_Dtor(&s2, 0);
    String_Dtor(&s1, 0);
    r = cLoader_AllocateAndFillAnimationBuffer(mgr, &file);
    if (r) {
        std_tree_pair_cString_value_compare_begin(&b, D_004FFBC0);
        it.n = b.n;
        std_tree_pair_cString_value_compare_end(&e, D_004FFBC0);
        h = e.n;
        while (Eq_1BFF40(it.n, h) ^ 1) {
            String_CtorCStr_13B480(&s3, name);
            Skas_AppendAnimation(it.n->anim, &s3, r);
            String_Dtor(&s3, 0);
            Tree_Successor(&it);
        }
    }
    FileMan_Release(&file, -1);
}
#pragma pop /* merge_units */
/* merge_units: end func_001BFF40 */
