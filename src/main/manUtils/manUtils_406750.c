/*
 * main/manUtils: range (3 files, 00406750-004068B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00406750 */
#pragma push /* merge_units */
typedef struct { char first[16]; char second[16]; } H2Pair;
typedef struct { char hdr[0x40]; H2Pair pairs[32]; } H2Pack;
/* Returns the first tone digit found in the manifest pairs, '_' when none. */
int SKL_FindRace(H2Pack* p) {
    char* s;
    int i;
    for (i = 0; i < 32; i++) {
        char c = p->pairs[i].first[9];
        if (c >= '0' && c <= '9')
            return c;
        s = p->pairs[i].second;
        c = s[9];
        if (c >= '0' && c <= '9')
            return c;
        if (s[0] == 0)
            return '_';
    }
    return '_';
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00406750(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00406750 */

/* merge_units: begin func_004067E0 */
#pragma push /* merge_units */
extern int Libc_Strncmp(char* a, char* b, int n);
/* Body kind from the mesh family of the first part pair. */
int SKL_FindSex(H2Pack* p) {
    char* name;
    int i;
    char c;
    for (i = 0; i < 32; i++) {
        name = p->pairs[i].first;
        if (Libc_Strncmp(name + 1, "BODY", 4) == 0)
            return 2;
        c = name[0];
        if (c == '1')
            return 1;
        if (c == '2')
            return 0;
        if (c == 0)
            return i > 0 ? 2 : 1;
    }
    return 2;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004067E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004067E0 */

/* merge_units: begin func_004068B0 */
#pragma push /* merge_units */
typedef union { __int128 q; struct { char tag; char name[15]; } s; } P8B0Name;
typedef struct { P8B0Name a; P8B0Name b; } P8B0Pair;
typedef struct { char pad[0x40]; P8B0Pair pairs[1]; } P8B0Obj;
#if 0 /* merge_units */
extern int Libc_Strncmp(const char* a, const char* b, int n);
#endif /* merge_units */
#define Libc_Strncmp(a0, a1, a2) (Libc_Strncmp((void *)(a0), (void *)(a1), (a2))) /* merge_units */

/* Pair index by type prefix. */
int SKL_FindPartIndex(P8B0Obj* o, const char* key) {
    P8B0Pair* p = o->pairs;
    int i = 0;
    while ((long long)p->a.q != 0) {
        if (Libc_Strncmp(p->a.s.name, key, 5) == 0)
            return i;
        p++;
        i++;
    }
    if (Libc_Strncmp(p->b.s.name, key, 5) == 0)
        return i;
    i = -1;
    return i;
}
#undef Libc_Strncmp /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004068B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004068B0 */
