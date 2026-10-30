/*
 * Libs/SFOLib/Source/SFOini: 7 files, 003CBA60-003CBE70
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
#include "sfoini_string.h"
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
int std_basic_string_char_char_traits_char_find_basicstringR_uint(const String* s, const String* what, unsigned int pos);
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

/* merge_units: begin func_003CBE70 */
#pragma push /* merge_units */
/*
 * Libs/SFOLib/Source/SFOini: 5 files, 003CBE70-003CBE90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

char* std_basic_string_char_char_traits_char_opIndex(String* s, int i)
{
    return ((s->l.cap & 1) ? s->l.data : (char*)s + 1) + i;
}
static inline void merge_flush_func_003CBE70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CBE70 */

/* merge_units: begin func_003CBE90 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int std_basic_string_char_char_traits_char_reserve(char *, int);
int cFileMan_Read_charPP_int(char *, int *, int);
char * func_0036DD80(char *);
int cFileMan_Close(char *);
int cFileMan_Open(char *);
int cFileMan_dtor(char *, int);
int cFileMan_ctor_charP_cFileIOP_bool(char *, int, int, int);
#if 0 /* merge_units */
extern int D_00543658;
#endif /* merge_units */
#define D_00543658 (*(int*)&D_00543658) /* merge_units */

#if 0 /* merge_units */
extern char D_00543680;
#endif /* merge_units */
#define D_00543680 (*(char*)&D_00543680) /* merge_units */

#if 0 /* merge_units */
extern char D_005436A0;
#endif /* merge_units */
#define D_005436A0 (*(char*)&D_005436A0) /* merge_units */


int cSFOini_Load(int arg0) {
    int sp10[40];

    if (D_00543668 == 0) {
        cFileMan_ctor_charP_cFileIOP_bool(sp10, arg0, 0, 0);
        if (!(cFileMan_Open(sp10) & 0xFF)) {
            D_00543660 = F_(func_0036DD80(sp10), 0x2C, int);
            D_00543658 = 0;
            cFileMan_Read_charPP_int(sp10, &D_00543658, 0);
            cFileMan_Close(sp10);
            D_00543668 = 1;
            std_basic_string_char_char_traits_char_reserve(&D_00543680, 0x40);
            std_basic_string_char_char_traits_char_reserve(&D_005436A0, 0x40);
            cFileMan_dtor(sp10, -1);
            return 1;
        }
        cFileMan_dtor(sp10, -1);
        goto block_5;
    }
block_5:
    return 0;
}
#undef D_00543658 /* merge_units */
#undef D_00543680 /* merge_units */
#undef D_005436A0 /* merge_units */
static inline void merge_flush_func_003CBE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CBE90 */

/* merge_units: begin func_003CBF70 */
#pragma push /* merge_units */
extern int std_basic_string_char_char_traits_char_find_charP_uint_uint(const String* self, const char* s, unsigned int pos, unsigned int n);
static inline unsigned char SBF70_ShortLen(const String* s) { return s->s.size; }
int std_basic_string_char_char_traits_char_find_basicstringR_uint(const String* self, const String* str, unsigned int pos)
{
    const char* d;
    unsigned int n;
    if (!(str->l.cap & 1)) {
        d = str->s.data;
        n = SBF70_ShortLen(str);
    } else {
        d = str->l.data;
        n = str->l.size;
    }
    return std_basic_string_char_char_traits_char_find_charP_uint_uint(self, d, pos, n);
}
static inline void merge_flush_func_003CBF70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CBF70 */

/* merge_units: begin func_003CBFB0 */
#pragma push /* merge_units */
int std_basic_string_char_char_traits_char_find_charP_uint_uint(const String* self, const char* s, unsigned int pos, unsigned int n)
{
    const char* d;
    unsigned int size;
    unsigned int rem;
    const char* end;
    const char* p;
    if (!(self->l.cap & 1)) {
        d = self->s.data;
        size = SBF70_ShortLen(self);
    } else {
        d = self->l.data;
        size = self->l.size;
    }
    if (pos <= size) {
        p = d + pos;
        end = s + n;
        rem = size - pos;
        for (; rem >= n; rem--, p++) {
            const char* b = p;
            const char* a = s;
            for (; a < end; a++, b++) {
                if (*a != *b) goto next;
            }
            return p - d;
        next:;
        }
    }
    return -1;
}
static inline void merge_flush_func_003CBFB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CBFB0 */

/* merge_units: begin func_003CC060 */
#pragma push /* merge_units */
typedef struct { unsigned char m0; int m4; int m8; int mC; } TC060;
#if 0 /* merge_units */
extern int cFileMan_Open(void* src);
#endif /* merge_units */
#define cFileMan_Open(a0) (cFileMan_Open((char *)(a0))) /* merge_units */



extern int cFileMan_GetSize(void* src);
#if 0 /* merge_units */
extern void cFileMan_Read_charPP_int(void* src, int* out, int z);
#endif /* merge_units */
#define cFileMan_Read_charPP_int(a0, a1, a2) ((void)cFileMan_Read_charPP_int((char *)(a0), (a1), (a2))) /* merge_units */



#if 0 /* merge_units */
extern void cFileMan_Close(void* src);
#endif /* merge_units */
#define cFileMan_Close(a0) ((void)cFileMan_Close((char *)(a0))) /* merge_units */



unsigned char cDB_LoadDB(TC060* self, void* src)
{
    if (!(unsigned char)cFileMan_Open(src)) {
        self->mC = cFileMan_GetSize(src);
        self->m8 = 0;
        cFileMan_Read_charPP_int(src, &self->m8, 0);
        cFileMan_Close(src);
        self->m4 = self->m8;
        self->m0 = 1;
        return 1;
    }
    return 0;
}
#undef cFileMan_Open /* merge_units */
#undef cFileMan_Read_charPP_int /* merge_units */
#undef cFileMan_Close /* merge_units */
static inline void merge_flush_func_003CC060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CC060 */
