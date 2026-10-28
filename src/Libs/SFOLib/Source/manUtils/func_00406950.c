/* SKL_AddAccessorySKL (00406950) - manUtils.cc */
#include "types.h"
typedef struct { __int128 partName; __int128 texName; } manAttribs;
typedef struct { char c[16]; } Name16;
typedef struct {
    Name16 boneScaleName;
    __int128 faceBaseName;
    __int128 gunOffsetPart;
    __int128 skeletonName128;
    manAttribs manAttribsTable[32];
} SKL;
typedef struct { char s[32]; } SKLKey;
typedef struct { SKLKey* keys; SKL* packs; int count; } SKLRegistry;
typedef struct {
    __int128 blank;
    __int128 none;
    __int128 RACE_MASK;
    __int128 pad30[3];
    __int128 TYPE_MASK;
    __int128 pad70[3];
    __int128 NAMEL_MASK;
} SKLMasks;
extern SKLRegistry D_0055D4F8;
extern SKLMasks g_AgentPartCache;
int SKL_FindSex(SKL* s);
int strlen(char* s);
int Libc_Strncmp(char* a, char* b, int n);

static inline int kmeq2(__int128 a, __int128 b, __int128 m) {
    __int128 y;
    long long x;
    asm {
        pand x, m, a
        pand y, m, b
        pceqw x, x, y
        ppach x, x, x
    }
    return x == -1;
}
static inline int kmeqm(__int128 m, __int128 b, __int128 a) {
    __int128 y;
    long long x;
    asm {
        pand x, m, a
        pand y, m, b
        pceqw x, x, y
        ppach x, x, x
    }
    return x == -1;
}
static inline int kmeq3(__int128 a, __int128 b, __int128 m) {
    long long x;
    asm {
        pand x, m, a
        pand m, m, b
        pceqw x, x, m
        ppach x, x, x
    }
    return x == -1;
}
static inline __int128 kmerge(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pnor n, m, m
 pand r, key, n
 pand c, cmp, m
 por r, r, c }
    return r;
}

static inline char FindRace(SKL* s) {
    char* t;
    int i;
    char c;
    for (i = 0; i < 32; i++) {
        c = ((char*)&s->manAttribsTable[i].partName)[9];
        if (c >= '0' && c <= '9')
            return c;
        t = (char*)&s->manAttribsTable[i].texName;
        c = t[9];
        if (c >= '0' && c <= '9')
            return c;
        if (t[0] == 0)
            return '_';
    }
    return '_';
}

int SKL_AddAccessorySKL(SKL* self, int identity, int manAttribsCount, char* SKLName) {
    __int128 raceTxt = 0;
    char* raceTxtPtr = (char*)&raceTxt;
    int i;
    int theRace;
    manAttribs* attrib;
    int coreLen;
    int start;
    int end;
    int choices;
    int found;
    SKL* pack;

    if (D_0055D4F8.count == 0)
        return 0;
    SKL_FindSex(self);
    coreLen = strlen(SKLName);
    for (start = 0; start < D_0055D4F8.count; start++) {
        if (Libc_Strncmp(SKLName, D_0055D4F8.keys[start].s, coreLen) == 0)
            break;
    }
    if (start == D_0055D4F8.count)
        return 0;
    for (end = start + 1; end < D_0055D4F8.count; end++) {
        if (Libc_Strncmp(SKLName, D_0055D4F8.keys[end].s, coreLen) != 0)
            break;
    }
    choices = end - start;
    if (choices == 1)
        return 0;
    identity = start + identity % choices;
    pack = &D_0055D4F8.packs[identity];
    theRace = FindRace(pack);
    raceTxtPtr[9] = theRace;
    if (theRace != '_' && theRace != FindRace(self)) {
        for (attrib = self->manAttribsTable; attrib->texName; attrib++) {
            if (!kmeq2(attrib->texName, g_AgentPartCache.none, g_AgentPartCache.RACE_MASK))
                attrib->texName = kmerge(attrib->texName, raceTxt, g_AgentPartCache.RACE_MASK);
        }
    }
    self->boneScaleName = pack->boneScaleName;
    self->faceBaseName = pack->faceBaseName;
    for (attrib = pack->manAttribsTable; attrib->partName; attrib++) {
        found = 0;
        for (i = 0; i < manAttribsCount; i++) {
            if (kmeq2(attrib->partName, self->manAttribsTable[i].partName, g_AgentPartCache.NAMEL_MASK)) {
                found = 1;
                break;
            }
        }
        if (!found) {
            self->manAttribsTable[manAttribsCount + 2].partName = self->manAttribsTable[manAttribsCount + 1].partName;
            self->manAttribsTable[manAttribsCount + 2].texName = self->manAttribsTable[manAttribsCount + 1].texName;
            self->manAttribsTable[manAttribsCount + 1].partName = self->manAttribsTable[manAttribsCount].partName;
            self->manAttribsTable[manAttribsCount + 1].texName = self->manAttribsTable[manAttribsCount].texName;
            manAttribsCount++;
        }
        if (!kmeq3(g_AgentPartCache.blank, self->manAttribsTable[i].partName, g_AgentPartCache.TYPE_MASK)) {
            self->manAttribsTable[i].texName = attrib->texName;
            self->manAttribsTable[i].partName = attrib->partName;
        }
    }
    if (attrib->texName)
        self->manAttribsTable[manAttribsCount].texName = attrib->texName;
    return identity;
}

