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
void Resource_Construct(FObj* o);
FObj* FileMan_Release(FObj* o, short del);
void* Mem_Alloc(int pool, int size, char* file, int line);
char* Archive_GetMemberName(Arc* a, int i);
void Appearance_RegistryKey(char* dst, int n, char* src);
void* Hog_GetMemberInPlace(Arc* a, int i);
int Hog_GetEntrySize(Arc* a, int i);
void Appearance_PackText(H2Pack* dst, void* text, int len);
int String_CompareN(char* a, char* b, int n);
int Appearance_GetBodyKind(H2Pack* p);
void SklRegistry_AddArchive(H2Registry* reg, Arc* arc);
}

static inline void* SAlloc(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BE7F0, line);
}

void SklRegistry_AddArchive(H2Registry* reg, Arc* arc)
{
    FObj fo;
    char* name;
    int nA = 0;
    int nB = 0;
    int i;
    int n;
    Resource_Construct(&fo);
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
        FileMan_Release(&fo, -1);
        return;
    }
    n = arc->list->n;
    reg->keys = (H2Key*)SAlloc(n * 32, 0xCE);
    reg->packs = (H2Pack*)SAlloc(n * 0x440, 0xCF);
    for (i = 0; i < n; i++) {
        name = Archive_GetMemberName(arc, i);
        Appearance_RegistryKey(reg->keys[i].s, 0x1F, name);
        Appearance_PackText(&reg->packs[i], Hog_GetMemberInPlace(arc, i), Hog_GetEntrySize(arc, i));
        String_CompareN(name, D_004BE970, 3);
        if (String_CompareN(name, D_004BE978, 8) == 0) {
            D_0055DE94++;
            if (Appearance_GetBodyKind(&reg->packs[i]) == 0) {
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
    FileMan_Release(&fo, -1);
}
