/*
 * Libs/SFOLib/Source/globalization: 3 files, 003FE640-003FE800
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FE640 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc
 */

#include "types.h"
#include "globalization_types.h"

/* Getter for the first word. */
int func_003FE640(LocEntry* self) {
    return self->unk00;
}
static inline void merge_flush_func_003FE640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FE640 */

/* merge_units: begin func_003FE650 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef union { __int128 q; char c[16]; } GTag;
struct GPtr { __int128* p; __int128& operator[](int i) { return p[i]; } };
struct GLabels { int a; int count; GPtr items; int Size() { return count; } GPtr& Items() { return items; } };
extern "C" {
extern void* memset(void* d, int c, unsigned int n);
extern char* strncpy(char* d, const char* s, unsigned int n);
extern unsigned int strlen(const char* s);
extern char Libc_Tolower(char c);
extern int D_0055CA44;
extern GPtr D_0055CA48;
extern GLabels* D_0055CA50;
extern int D_0055CA80;
}

static inline __int128 MakeTag(const char* s)
{
    GTag tag;
    char* p;
    int n;
    int i;
    memset(tag.c, 0, 16);
    strncpy(tag.c, s, 16);
    p = tag.c;
    n = strlen(p);
    for (i = 0; i < n; i++, p++)
        *p = Libc_Tolower(*p);
    return tag.q;
}

static inline bool TagEq(const __int128& a, const __int128& b)
{
    __int128 y; __int128 x; unsigned int r; unsigned int m = 0xFFFFFFFFu;
    __asm__ volatile("lq %0, 0(%1)" : "=r"(x) : "r"(&a));
    __asm__ volatile("lq %0, 0(%1)" : "=r"(y) : "r"(&b));
    __asm__ volatile("pceqw %0, %1, %2" : "=r"(x) : "r"(x), "r"(y));
    __asm__ volatile("ppach %0, %1, %2" : "=r"(r) : "r"(x), "r"(x));
    bool res = !(r < m);
    return res;
}

extern "C" int GetIndexFromLabel(const char* label)
{
    if (!label)
        return -1;
    {
        __int128 lab;
        int i;
        int size;
        lab = MakeTag(label);
        size = D_0055CA44;
        for (i = 0; i < size; i++) {
            __int128 l = D_0055CA48[i];
            if (TagEq(l, lab))
                return i;
        }
        if (!D_0055CA50)
            return -1;
        size = D_0055CA50->Size();
        for (i = 0; i < size; i++) {
            __int128 l = D_0055CA50->Items().p[i];
            if (TagEq(l, lab))
                return i + D_0055CA80;
        }
        return -1;
    }
}
static inline void merge_flush_func_003FE650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FE650 */

/* merge_units: begin func_003FE800 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0)

struct E_003FE800 { __int128 m0; };
extern "C" char D_004BE4D0[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_CNT(insert__Q23std33__vector_impTFP1UiRC1, E_003FE800, 0x600000, 0x300000, D_004BE4D0, D_004BE530, 0x5C, std_swap_vectordeleterR_vectordeleterR_46, extern char D_004BE520[];, *tcount = 0; { E_003FE800* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004BE520, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
static inline void merge_flush_func_003FE800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FE800 */
