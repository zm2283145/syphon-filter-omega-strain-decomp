/*
 * Libs/SFOLib/Source/manUtils: 4 files, 00406750-00406950
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00406750 */
#pragma push /* merge_units */
#include "types.h"

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
#define Libc_Strncmp(a0, a1, a2) (Libc_Strncmp((char *)(a0), (char *)(a1), (a2))) /* merge_units */


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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004068B0(void) {}
#undef Libc_Strncmp /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004068B0 */

/* merge_units: begin func_00406950 */
#pragma push /* merge_units */
/* SKL_AddAccessorySKL (00406950) - manUtils.cc */
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
#if 0 /* merge_units */
int SKL_FindSex(SKL* s);
#endif /* merge_units */
#define SKL_FindSex(a0) (SKL_FindSex((H2Pack *)(a0))) /* merge_units */

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
#undef SKL_FindSex /* merge_units */
static inline void merge_flush_func_00406950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00406950 */
