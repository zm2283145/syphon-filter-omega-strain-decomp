/*
 * Libs/SFOLib/Source/manUtils: 2 files, 00407830-00407BE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00407830 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

typedef union { long long q[4]; char s[32]; __int128 v[2]; } H2Key;
typedef struct { char b[0x440]; } H2Pack;
typedef struct { H2Key* keys; H2Pack* packs; int count; } H2Registry;
typedef struct { int pad; int n; } Lst;
typedef struct { char pad[0x148]; Lst* list; unsigned char loaded; } Arc;
typedef struct { int flags; char pad[0x94]; void* p98; } FObj;
typedef struct {
    char pad[0xF8];
    H2Pack* a[4];
    H2Pack* b[4];
} BodyTab;

extern "C" {
extern int D_0055DE94;
extern BodyTab g_AgentPartCache;
extern char D_004BE7F0[];
extern char D_004BE970[];
extern char D_004BE978[];
void cFileMan_ctor_void(FObj* o);
FObj* cFileMan_dtor(FObj* o, short del);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
char* cHogFile_GetBlockName(Arc* a, int i);
void strCpyPad(char* dst, int n, char* src);
void* cHogFile_GetBlock_int(Arc* a, int i);
int cHogFile_GetBlockSize(Arc* a, int i);
void SKL_ConvertSKL(H2Pack* dst, void* text, int len);
int Libc_Strncmp(char* a, char* b, int n);
int SKL_FindSex(H2Pack* p);
void SKLHog_LoadSKLHog(H2Registry* reg, Arc* arc);
}

static inline void* SAlloc(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004BE7F0, line);
}

void SKLHog_LoadSKLHog(H2Registry* reg, Arc* arc)
{
    FObj fo;
    char* name;
    int nA = 0;
    int nB = 0;
    int i;
    int n;
    cFileMan_ctor_void(&fo);
    D_0055DE94 = 0;
    reg->count = 0;
    g_AgentPartCache.a[0] = 0;
    g_AgentPartCache.b[0] = 0;
    g_AgentPartCache.a[1] = 0;
    g_AgentPartCache.b[1] = 0;
    g_AgentPartCache.a[2] = 0;
    g_AgentPartCache.b[2] = 0;
    g_AgentPartCache.a[3] = 0;
    g_AgentPartCache.b[3] = 0;
    if (!arc->loaded) {
        cFileMan_dtor(&fo, -1);
        return;
    }
    n = arc->list->n;
    reg->keys = (H2Key*)SAlloc(n * 32, 0xCE);
    reg->packs = (H2Pack*)SAlloc(n * 0x440, 0xCF);
    for (i = 0; i < n; i++) {
        name = cHogFile_GetBlockName(arc, i);
        strCpyPad(reg->keys[i].s, 0x1F, name);
        SKL_ConvertSKL(&reg->packs[i], cHogFile_GetBlock_int(arc, i), cHogFile_GetBlockSize(arc, i));
        Libc_Strncmp(name, D_004BE970, 3);
        if (Libc_Strncmp(name, D_004BE978, 8) == 0) {
            D_0055DE94++;
            if (SKL_FindSex(&reg->packs[i]) == 0) {
                if (nA < 4)
                    g_AgentPartCache.a[nA] = &reg->packs[i];
                nA++;
            } else {
                if (nB < 4)
                    g_AgentPartCache.b[nB] = &reg->packs[i];
                nB++;
            }
        }
    }
    if (nB != 0 && nB < 4) {
        i = nB;
        do {
            g_AgentPartCache.b[i] = g_AgentPartCache.b[nB - 1];
        } while (++i < 4);
    }
    if (nA != 0 && nA < 4) {
        i = nA;
        do {
            g_AgentPartCache.a[i] = g_AgentPartCache.a[nA - 1];
        } while (++i < 4);
    }
    reg->count = n;
    cFileMan_dtor(&fo, -1);
}
static inline void merge_flush_func_00407830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00407830 */

/* merge_units: begin func_00407BE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int cMemMan_Deallocate(int, int, char *, int);                         
#if 0 /* merge_units */
extern char D_004BE7F0;
#endif /* merge_units */
#define D_004BE7F0 (*(char*)&D_004BE7F0) /* merge_units */

extern unsigned char g_ProfileLockEnabled;
extern int D_0055D4F8;
extern int D_0055D4FC;
extern int D_0055D500;
}
extern "C" void SKLHog_DeleteIdentities(void) {
    int temp_s0;
    int temp_s0_2;

    if (D_0055D500 != 0) {
        temp_s0 = D_0055D4F8;
        {
            AllocGuard g;
        cMemMan_Deallocate(0, temp_s0, &D_004BE7F0, 0xB0);
        }
        temp_s0_2 = D_0055D4FC;
        {
            AllocGuard g;
        cMemMan_Deallocate(0, temp_s0_2, &D_004BE7F0, 0xB1);
        }
        D_0055D500 = 0;
    }
}
#undef D_004BE7F0 /* merge_units */
static inline void merge_flush_func_00407BE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00407BE0 */
