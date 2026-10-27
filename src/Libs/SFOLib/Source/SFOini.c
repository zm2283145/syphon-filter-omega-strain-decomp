/*
 * Libs/SFOLib/Source/SFOini: 2 files, 003CBA60-003CBA90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CBA60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* std_tree_pair_cSystemPtr_value_compare_node_alloc(char* self) {
    return self + 4;
}

void cAllocator_pair_cSystemPtr_destroy(void) {
}

void* std_tree_pair_cSystemPtr_value_compare_alloc(void* self) {
    return self;
}
static inline void merge_flush_func_003CBA60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CBA60 */

/* merge_units: begin func_003CBA90 */
#pragma push /* merge_units */
/* cSFOini_GetKeyValue (proto cSFOini::GetKeyValue): scans the loaded ini text line by line for
 * "key=value", skipping comment/section/blank lines, and returns the value with trailing newlines
 * stripped (an empty string when the key is missing, 0 when no ini is loaded). */
#pragma cplusplus on
typedef union String {
    struct {
        unsigned int cap;
        int size;
        char* data;
    } l;
    struct {
        unsigned char isLong : 1;
        unsigned char size : 7;
        char data[11];
    } s;
} String;
typedef struct Tag { signed char unused; } Tag;
extern "C" {
extern char* D_00543658;
extern int D_00543660;
extern unsigned char D_00543668;
extern String D_00543680;
extern String D_005436A0;
extern char D_005436A1[];
extern char* D_005436A8;
extern char D_004BD1F8[];
extern char D_004BD200[];
void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* c);
void std_basic_string_char_char_traits_char_assign_basicstringR(String* d, String* s);
void String_Dtor(String* s, int f);
void std_basic_string_char_char_traits_char_do_replace(String* s, int pos, int n, int first, int last, Tag tag);
int std_basic_string_char_char_traits_char_find_basicstringR_uint(String* s, String* what, unsigned int pos);
char* std_basic_string_char_char_traits_char_opIndex(String* s, int i);
void std_basic_string_char_char_traits_char_opAddAssign(String* s, char c);
int std_basic_string_char_char_traits_char_compare_charP(String* s, const char* c);
char* std_basic_string_char_char_traits_char_c_str(String* s);
char* cSFOini_GetKeyValue(char* key);
}
static inline void Init(String* s)
{
    unsigned int* p = (unsigned int*)s;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}
static inline bool IsLong(String* s)
{
    return s->l.cap & 1;
}
static inline int Size(String* s)
{
    return IsLong(s) ? s->l.size : (unsigned char)s->s.size;
}
static inline char* VData()
{
    bool l = D_005436A0.l.cap & 1;
    return !l ? D_005436A1 : D_005436A8;
}
static inline char& VAt(int i)
{
    return VData()[i];
}
static inline void Clear(String* s)
{
    Tag tag;
    std_basic_string_char_char_traits_char_do_replace(s, 0, -1, 0, 0, tag);
}
static inline int Max(int a, int b)
{
    return a < b ? b : a;
}
char* cSFOini_GetKeyValue(char* key)
{
    int lopIndex;
    String lStr;
    char* pBuf;
    int tLen;
    int i;
    int valLen;
    Init(&lStr);
    pBuf = D_00543658;
    tLen = 0;
    if (!D_00543668) {
        String_Dtor(&lStr, 0);
        return 0;
    }
    Clear(&D_00543680);
    Clear(&D_005436A0);
    while (tLen <= D_00543660) {
        int lineLen;
        {
            String t;
            std_basic_string_char_char_traits_char_ctor_charP(&t, pBuf);
            std_basic_string_char_char_traits_char_assign_basicstringR(&lStr, &t);
            String_Dtor(&t, 0);
        }
        {
            String t;
            std_basic_string_char_char_traits_char_ctor_charP(&t, D_004BD1F8);
            lineLen = Max(1, std_basic_string_char_char_traits_char_find_basicstringR_uint(&lStr, &t, 0));
            String_Dtor(&t, 0);
        }
        if (*pBuf == ';' || *pBuf == '[' || *pBuf == ' ' || *pBuf == '\t' || *pBuf == '\n') {
            lopIndex = lineLen;
        } else {
            String t;
            std_basic_string_char_char_traits_char_ctor_charP(&t, D_004BD200);
            lopIndex = std_basic_string_char_char_traits_char_find_basicstringR_uint(&lStr, &t, 0);
            String_Dtor(&t, 0);
        }
        if (lopIndex < lineLen) {
            Clear(&D_00543680);
            for (i = 0; i < lopIndex; i++)
                std_basic_string_char_char_traits_char_opAddAssign(&D_00543680, *std_basic_string_char_char_traits_char_opIndex(&lStr, i));
            if (!std_basic_string_char_char_traits_char_compare_charP(&D_00543680, key)) {
                char* r;
                {
                    String t;
                    std_basic_string_char_char_traits_char_ctor_charP(&t, pBuf + (lopIndex + 1));
                    std_basic_string_char_char_traits_char_assign_basicstringR(&lStr, &t);
                    String_Dtor(&t, 0);
                }
                lineLen -= lopIndex;
                for (i = 0; i < lineLen; i++)
                    std_basic_string_char_char_traits_char_opAddAssign(&D_005436A0, *std_basic_string_char_char_traits_char_opIndex(&lStr, i));
                valLen = Size(&D_005436A0) - 1;
                while (VAt(valLen) == '\n' || VAt(valLen) == '\r') {
                    VAt(valLen) = 0;
                    valLen--;
                }
                r = std_basic_string_char_char_traits_char_c_str(&D_005436A0);
                String_Dtor(&lStr, 0);
                return r;
            }
        }
        tLen += lineLen;
        pBuf += lineLen + 1;
    }
    {
        char* r = std_basic_string_char_char_traits_char_c_str(&D_005436A0);
        String_Dtor(&lStr, 0);
        return r;
    }
}
static inline void merge_flush_func_003CBA90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CBA90 */
