/*
 * main/manUtils: range (5 files, 00405940-00406040)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int Mem_Free();

/* merge_units: begin func_00405940 */
#pragma push /* merge_units */
typedef struct { __int128 a; __int128 b; } HM_Pair;
typedef struct { __int128 slot0; __int128 slot1; __int128 q20; __int128 q30; HM_Pair pairs[32]; } HM_Pack;
extern char D_004BE910[];
extern char D_004BE920[];
extern char D_0055DDA0[];
extern char D_0057124C[];
extern int String_CompareN(char* a, char* b, int n);
extern int Appearance_GetBodyKind(HM_Pack* p);
extern int MeshCache_Load(void* cache, __int128 name, void* ctx, void* arg);
/* Requests the hard mesh (slot 2) when asked, then every pair's part mesh; returns the part count. */
int Appearance_RequestHardMesh(HM_Pack* p, int hard, void* arg)
{
    int i;
    if (hard) {
        if (String_CompareN((char*)&p->q20 + 1, D_004BE910, 4) == 0) {
            MeshCache_Load(D_0055DDA0, p->q20, D_0057124C, arg);
        } else {
            String_Copy(&p->q20, D_004BE920);
            if (Appearance_GetBodyKind(p) == 0)
                *(char*)&p->q20 = '2';
            else
                *(char*)&p->q20 = '1';
            MeshCache_Load(D_0055DDA0, p->q20, D_0057124C, arg);
        }
    }
    for (i = 0; p->pairs[i].a; i++)
        MeshCache_Load(D_0055DDA0, p->pairs[i].a, D_0057124C, arg);
    return i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00405940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00405940 */

/* merge_units: begin func_00405A60 */
#pragma push /* merge_units */
typedef struct { int pad; int count; char** names; } List5E10;
void func_00405E10(void* self, List5E10* list, __int128* keys, int n); /* gsynth: defined below */
typedef struct { __int128 name; char pad[0x10]; } Ent5F10;
typedef struct { char pad[0x50]; Ent5F10 ent[1]; } Obj5F10;
void func_00405F10(Obj5F10* o, int idx, __int128* keys, int n); /* gsynth: defined below */
typedef struct { __int128 name; char pad[0x10]; } Ent6040;
typedef struct { char pad[0x50]; Ent6040 ent[1]; } Obj6040;
void func_00406040(Obj6040* o, int idx, __int128* keys, int n); /* gsynth: defined below */
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
void* Mem_Alloc(int pool, int size, char* file, int line);
void Hog_Load(A60Hog* h, A60Hog* t, int a, int b);
void Hog_Unload(A60Hog* h);
char* Archive_GetMemberName(A60Hog* h, int i);
void Appearance_RegistryKey(char* dst, int n, char* src);
#if 0 /* merge_units */
int String_CompareN(const char* a, const char* b, int n);
#endif /* merge_units */
#define String_CompareN(a0, a1, a2) (String_CompareN((char *)(a0), (char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void func_00405E10(A60Obj* o, void* list, __int128* keys, int n);
#endif /* merge_units */
#define func_00405E10(a0, a1, a2, a3) (func_00405E10((void *)(a0), (List5E10 *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void func_00406040(A60Obj* o, int idx, __int128* keys, int n);
#endif /* merge_units */
#define func_00406040(a0, a1, a2, a3) (func_00406040((Obj6040 *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void func_00405F10(A60Obj* o, int idx, __int128* keys, int n);
#endif /* merge_units */
#define func_00405F10(a0, a1, a2, a3) (func_00405F10((Obj5F10 *)(a0), (a1), (a2), (a3))) /* merge_units */

void func_00405A60(A60Obj* o, void* list);
}
static inline int a60find(A60Obj* o, const char* key) {
    int i = 0;
    A60Pair* p = o->pairs;
    while ((long long)p->a.q != 0) {
        if (String_CompareN(p->a.s.name, key, 5) == 0)
            return i;
        p++;
        i++;
    }
    if (String_CompareN(p->b.s.name, key, 5) == 0)
        return i;
    i = -1;
    return i;
}
/* Builds the registry key list from the appearance HOG and applies the three typed variant merges. */
void func_00405A60(A60Obj* o, void* list)
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
        Hog_Load(h, h, unload, 0);
    }
    n = h->dir->count;
    {
        AllocGuard g;
        keys = (__int128*)Mem_Alloc(0, n * 16, D_004BE7F0, 0x40B);
    }
    for (i = 0; i < n; i++)
        Appearance_RegistryKey((char*)&keys[i], 15, Archive_GetMemberName(h, i));
    func_00405E10(o, list, keys, n);
    if (unload)
        Hog_Unload(h);
    k0 = a60find(o, D_004BE930);
    k1 = a60find(o, D_004BE938);
    k2 = a60find(o, D_004BE940);
    if (k0 != -1) func_00406040(o, k0, keys, n);
    if (k1 != -1) func_00406040(o, k1, keys, n);
    if (k2 != -1) func_00405F10(o, k2, keys, n);
    {
        AllocGuard g;
        Mem_Free(0, keys, D_004BE7F0, 0x41F);
    }
}
#undef String_CompareN /* merge_units */
#undef func_00405E10 /* merge_units */
#undef func_00406040 /* merge_units */
#undef func_00405F10 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00405A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00405A60 */

/* merge_units: begin func_00405E10 */
#pragma push /* merge_units */
typedef union { __int128 q; char s[16]; } Key5E10;

extern __int128 D_005716E0;
extern char* strchr(const char*, int);
extern void Appearance_RegistryKey(char* dst, int n, char* src);
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
void func_00405E10(void* self, List5E10* list, __int128* keys, int n) {
    int i;
    int total = list->count;
    for (i = 0; i < total; i++) {
        if (strchr(list->names[i], '.') == 0) {
            Key5E10 key;
            Appearance_RegistryKey(key.s, 15, list->names[i]);
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
void func_00405F10(Obj5F10* o, int idx, __int128* keys, int n) {
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
void func_00406040(Obj6040* o, int idx, __int128* keys, int n) {
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
