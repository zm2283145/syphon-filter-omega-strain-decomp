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
void Mem_Free(int pool, void* p, char* file, int line);
void Hog_Load(A60Hog* h, A60Hog* t, int a, int b);
void Hog_Unload(A60Hog* h);
char* Archive_GetMemberName(A60Hog* h, int i);
void Appearance_RegistryKey(char* dst, int n, char* src);
int String_CompareN(const char* a, const char* b, int n);
void func_00405E10(A60Obj* o, void* list, __int128* keys, int n);
void func_00406040(A60Obj* o, int idx, __int128* keys, int n);
void func_00405F10(A60Obj* o, int idx, __int128* keys, int n);
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
