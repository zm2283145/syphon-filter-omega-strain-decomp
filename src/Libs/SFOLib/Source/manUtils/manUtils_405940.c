/*
 * main/manUtils: range (5 files, 00405940-00406040)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int cMemMan_Deallocate();

/* merge_units: begin func_00405940 */
#pragma push /* merge_units */
typedef struct { __int128 a; __int128 b; } HM_Pair;
typedef struct { __int128 slot0; __int128 slot1; __int128 q20; __int128 q30; HM_Pair pairs[32]; } HM_Pack;
extern char D_004BE910[];
extern char D_004BE920[];
extern char g_AgentPartCache[];
extern char D_0057124C[];
extern int Libc_Strncmp(char* a, char* b, int n);
extern int SKL_FindSex(HM_Pack* p);
extern int Monster_LoadAPart(void* cache, __int128 name, void* ctx, void* arg);
/* Requests the hard mesh (slot 2) when asked, then every pair's part mesh; returns the part count. */
int SKL_LoadSKLParts(HM_Pack* p, int hard, void* arg)
{
    int i;
    if (hard) {
        if (Libc_Strncmp((char*)&p->q20 + 1, D_004BE910, 4) == 0) {
            Monster_LoadAPart(g_AgentPartCache, p->q20, D_0057124C, arg);
        } else {
            Libc_Strcpy(&p->q20, D_004BE920);
            if (SKL_FindSex(p) == 0)
                *(char*)&p->q20 = '2';
            else
                *(char*)&p->q20 = '1';
            Monster_LoadAPart(g_AgentPartCache, p->q20, D_0057124C, arg);
        }
    }
    for (i = 0; p->pairs[i].a; i++)
        Monster_LoadAPart(g_AgentPartCache, p->pairs[i].a, D_0057124C, arg);
    return i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00405940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00405940 */

/* merge_units: begin func_00405A60 */
#pragma push /* merge_units */
typedef struct { int pad; int count; char** names; } List5E10;
void SKL_HideLockedTex(void* self, List5E10* list, __int128* keys, int n); /* gsynth: defined below */
typedef struct { __int128 name; char pad[0x10]; } Ent5F10;
typedef struct { char pad[0x50]; Ent5F10 ent[1]; } Obj5F10;
void SKL_UpgradeBigPatch(Obj5F10* o, int idx, __int128* keys, int n); /* gsynth: defined below */
typedef struct { __int128 name; char pad[0x10]; } Ent6040;
typedef struct { char pad[0x50]; Ent6040 ent[1]; } Obj6040;
void SKL_UpgradeSmallPatch(Obj6040* o, int idx, __int128* keys, int n); /* gsynth: defined below */
#pragma cplusplus on
#include "alloc_guard.h"
typedef union { __int128 q; struct { char tag; char name[15]; } s; } A60Name;
typedef struct { A60Name a; A60Name b; } A60Pair;
typedef struct { char pad[0x40]; A60Pair pairs[1]; } A60Obj;
typedef struct { int pad; int count; } A60Dir;
typedef struct { char pad[0x148]; A60Dir* dir; unsigned char loaded; } A60Hog;
extern "C" {
extern char D_004BE7F0[];
extern char D_004BE930[];
extern char D_004BE938[];
extern char D_004BE940[];
extern A60Hog* D_00571248;
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cHogFile_OpenHog(A60Hog* h, A60Hog* t, int a, int b);
void cHogFile_CloseHog(A60Hog* h);
char* cHogFile_GetBlockName(A60Hog* h, int i);
void strCpyPad(char* dst, int n, char* src);
#if 0 /* merge_units */
int Libc_Strncmp(const char* a, const char* b, int n);
#endif /* merge_units */
#define Libc_Strncmp(a0, a1, a2) (Libc_Strncmp((char *)(a0), (char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void SKL_HideLockedTex(A60Obj* o, void* list, __int128* keys, int n);
#endif /* merge_units */
#define SKL_HideLockedTex(a0, a1, a2, a3) (SKL_HideLockedTex((void *)(a0), (List5E10 *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void SKL_UpgradeSmallPatch(A60Obj* o, int idx, __int128* keys, int n);
#endif /* merge_units */
#define SKL_UpgradeSmallPatch(a0, a1, a2, a3) (SKL_UpgradeSmallPatch((Obj6040 *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void SKL_UpgradeBigPatch(A60Obj* o, int idx, __int128* keys, int n);
#endif /* merge_units */
#define SKL_UpgradeBigPatch(a0, a1, a2, a3) (SKL_UpgradeBigPatch((Obj5F10 *)(a0), (a1), (a2), (a3))) /* merge_units */

void SKL_UpgradePatches(A60Obj* o, void* list);
}
static inline int a60find(A60Obj* o, const char* key) {
    int i = 0;
    A60Pair* p = o->pairs;
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
/* Builds the registry key list from the appearance HOG and applies the three typed variant merges. */
void SKL_UpgradePatches(A60Obj* o, void* list)
{
    int n;
    A60Hog* h;
    int i;
    __int128* keys;
    int unload; /* left uninitialised as in retail (s7 is only set on the load path) */
    int k0, k1, k2;
    h = D_00571248;
    if (!h->loaded) {
        unload = 1;
        cHogFile_OpenHog(h, h, unload, 0);
    }
    n = h->dir->count;
    {
        AllocGuard g;
        keys = (__int128*)cMemMan_Allocate(0, n * 16, D_004BE7F0, 0x40B);
    }
    for (i = 0; i < n; i++)
        strCpyPad((char*)&keys[i], 15, cHogFile_GetBlockName(h, i));
    SKL_HideLockedTex(o, list, keys, n);
    if (unload)
        cHogFile_CloseHog(h);
    k0 = a60find(o, D_004BE930);
    k1 = a60find(o, D_004BE938);
    k2 = a60find(o, D_004BE940);
    if (k0 != -1) SKL_UpgradeSmallPatch(o, k0, keys, n);
    if (k1 != -1) SKL_UpgradeSmallPatch(o, k1, keys, n);
    if (k2 != -1) SKL_UpgradeBigPatch(o, k2, keys, n);
    {
        AllocGuard g;
        cMemMan_Deallocate(0, keys, D_004BE7F0, 0x41F);
    }
}
#undef Libc_Strncmp /* merge_units */
#undef SKL_HideLockedTex /* merge_units */
#undef SKL_UpgradeSmallPatch /* merge_units */
#undef SKL_UpgradeBigPatch /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00405A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00405A60 */

/* merge_units: begin func_00405E10 */
#pragma push /* merge_units */
typedef union { __int128 q; char s[16]; } Key5E10;

extern __int128 D_005716E0;
extern char* strchr(const char*, int);
extern void strCpyPad(char* dst, int n, char* src);
static inline int k5e10eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline void k5e10clear(__int128* keys, int n, __int128 key) {
    int j;
    __int128* p;
    j = 0;
    if (j < n) {
        p = keys;
        do {
            if (k5e10eq(key, *p)) {
                keys[j] = D_005716E0;
                return;
            }
            j++;
            p++;
        } while (j < n);
    }
}
#pragma push
#pragma opt_strength_reduction off
void SKL_HideLockedTex(void* self, List5E10* list, __int128* keys, int n) {
    int i;
    int total = list->count;
    for (i = 0; i < total; i++) {
        if (strchr(list->names[i], '.') == 0) {
            Key5E10 key;
            strCpyPad(key.s, 15, list->names[i]);
            k5e10clear(keys, n, key.q);
        }
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00405E10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00405E10 */

/* merge_units: begin func_00405F10 */
#pragma push /* merge_units */
static inline int k5f10eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline int k5f10find(__int128* keys, int n, __int128 key) {
    int j;
    __int128* p;
    j = 0;
    if (j < n) {
        p = keys;
        do {
            if (k5f10eq(key, *p))
                return j;
            j++;
            p++;
        } while (j < n);
    }
    return -1;
}
void SKL_UpgradeBigPatch(Obj5F10* o, int idx, __int128* keys, int n) {
    __int128 key;
    char* s;
    char* lo;
    char* hi;
    int k;
    key = o->ent[idx].name;
    if (k5f10find(keys, n, key) != -1)
        return;
    s = (char*)&key;
    lo = s + 12;
    hi = s + 11;
    for (k = 0; k < 32; k++) {
        if (*lo == '9') {
            (*hi)++;
            *lo = '0';
        } else {
            (*lo)++;
        }
        if (k5f10find(keys, n, key) != -1) {
            o->ent[idx].name = key;
            return;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00405F10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00405F10 */

/* merge_units: begin func_00406040 */
#pragma push /* merge_units */
static inline int k6040eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline int k6040find(__int128* keys, int n, __int128 key) {
    int j;
    __int128* p;
    j = 0;
    if (j < n) {
        p = keys;
        do {
            if (k6040eq(key, *p))
                return j;
            j++;
            p++;
        } while (j < n);
    }
    return -1;
}
void SKL_UpgradeSmallPatch(Obj6040* o, int idx, __int128* keys, int n) {
    __int128 key;
    char* s;
    char* lo;
    char* hi;
    int k;
    key = o->ent[idx].name;
    if (k6040find(keys, n, key) != -1)
        return;
    s = (char*)&key;
    lo = s + 13;
    hi = s + 12;
    for (k = 0; k < 32; k++) {
        if (*lo == '-') {
            if (*hi == '9') {
                *hi = '1';
                *lo = '0';
            } else {
                (*hi)++;
            }
        } else if (*lo == '9') {
            (*hi)++;
            *lo = '0';
        } else {
            (*lo)++;
        }
        if (k6040find(keys, n, key) != -1) {
            o->ent[idx].name = key;
            return;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00406040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00406040 */
