/*
 * Libs/SFOLib/Source/globalization: 5 files, 003FDA40-003FDB80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FDA40 */
#pragma push /* merge_units */
#include "types.h"
typedef union { __int128 q; char c[16]; } NA40;
extern void* memset(void* d, int c, unsigned int n);
extern char* strncpy(char* d, const char* s, unsigned int n);
extern unsigned int strlen(const char* s);
extern char Libc_Tolower(char c);
__int128 nGlobalization_MakeTag(const char* s)
{
    NA40 r;
    char* p;
    int n;
    int i;
    memset(r.c, 0, 16);
    strncpy(r.c, s, 16);
    p = r.c;
    n = strlen(p);
    for (i = 0; i < n; i++, p++)
        *p = Libc_Tolower(*p);
    return r.q;
}
static inline void merge_flush_func_003FDA40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FDA40 */

/* merge_units: begin globalization_3FDAE0 */
#pragma push /* merge_units */
typedef struct { int a; int b; char* items; } T3FDAE0;
extern char D_004BE400[];
extern int D_0055CA80;
extern char* D_0055CA48;
extern T3FDAE0* D_0055CA50;
char* nGlobalization_GetStringTag(int i)
{
    if (i < 0) return D_004BE400;
    if (i < D_0055CA80) return D_0055CA48 + i * 16;
    return D_0055CA50->items + (i - D_0055CA80) * 16;
}
static inline void merge_flush_globalization_3FDAE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end globalization_3FDAE0 */

/* merge_units: begin func_003FDB40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc: localized text lookup.
 */


extern int GetIndexFromLabel(int key);
extern int nGlobalization_GetString_int(int id);

int nGlobalization_GetStringIndex(int key) {
    return GetIndexFromLabel(key);
}

/* Resolve a key to a string id, then to its text. */
int nGlobalization_GetString_charP(int key) {
    return nGlobalization_GetString_int(GetIndexFromLabel(key));
}
static inline void merge_flush_func_003FDB40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FDB40 */

/* merge_units: begin func_003FDB80 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

extern int* D_0055CA78;
int nGlobalization_GetString_int(int id)
{
    return id >= 0 ? D_0055CA78[id] : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FDB80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FDB80 */

/* merge_units: begin func_003FDBB0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int std_vector_pod_int_resize(char *, int, int *);                
int std_vector_deleter_1_dtor(int, int);                            
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
#if 0 /* merge_units */
extern int D_0055CA50;
#endif /* merge_units */
#define D_0055CA50 (*(int*)&D_0055CA50) /* merge_units */

extern char D_0055CA70;
extern int D_0055D460;
extern int D_0055D468;

void nGlobalization_UnloadLevelStrings(void) {
    int sp2C;
    int temp_s0;

    temp_s0 = D_0055CA50;
    if (temp_s0 != 0) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        if ((temp_s0 != 0) && (temp_s0 != 0) && (temp_s0 != 0)) {
            std_vector_deleter_1_dtor(temp_s0, 0);
        }
        cMemMan_Deallocate(0, temp_s0, "globalization.cc", 0x9B);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        D_0055CA50 = 0;
        g_ProfileLockDepth -= 1;
    }
    sp2C = 0;
    std_vector_pod_int_resize(&D_0055CA70, D_0055CA80, &sp2C);
    D_0055D460 = D_0055D468;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FDBB0(void) {}
#undef D_0055CA50 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FDBB0 */
