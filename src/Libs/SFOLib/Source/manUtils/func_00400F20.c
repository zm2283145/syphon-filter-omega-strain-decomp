#include "types.h"
typedef struct { int a; unsigned short b; unsigned char c; unsigned char d; int e; int f; } Parts;
typedef struct { __int128 part; __int128 tex; } manAttribs;
typedef struct { char raw[0x40]; manAttribs attr[32]; } SKL;
typedef struct { Parts bodyParts[2][32]; short manTexID[32]; short manTexID2[32]; __int128* bloodData[32]; unsigned short manAttribsCount; } ManParts;
typedef struct { __int128 m[8]; } SwapRule;
typedef struct { short a; short b; } TexIDs;
typedef struct {
    __int128 blank;
    __int128 none;
    __int128 RACE_MASK;
    char pad30[0x40];
    __int128 TYPE_MASK;
    char pad80[0x40];
    unsigned int monsterPartCount;
    unsigned int monsterHandFaceCount;
    unsigned int monsterCoreCount;
    unsigned int manTexCount;
    char padD0[0x14];
    unsigned int swapRuleCount;
    SwapRule* swapRules;
    char padEC[0x1410 - 0xEC];
    TexIDs texIDs[0x600];
    __int128 names[0x300];
    Parts table[0x300][2];
    __int128 texNames[0x400];
} Monster;
extern int D_00493AB0;
unsigned int SKL_FindSex(SKL* s);
void Monster_FindTheTexture(Monster* s, __int128 key, manAttribs* a, short* pa, short* pb, unsigned int sex, char race);
static inline __int128 kand(__int128 a, __int128 b) { __int128 r; asm { pand r, a, b } return r; }
static inline __int128 kor(__int128 a, __int128 b) { asm { por b, a, b } return b; }
static inline __int128 kxor(__int128 a, __int128 b) { __int128 r; asm { pxor r, a, b } return r; }
static inline int keq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline int kmeq(__int128 a, __int128 b, __int128 m) {
    __int128 y;
    long long x;
    asm {
        pand y, m, b
        pand x, m, a
        pceqw x, x, y
        ppach x, x, x
    }
    return x == -1;
}
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
static inline int kmeq3(__int128 a, __int128 b, __int128 m) {
    __int128 x, y;
    long long r;
    asm {
        pand x, m, a
        pand y, m, b
        pceqw x, x, y
        ppach r, x, x
    }
    return r == -1;
}
static inline int kmeq5(__int128 a, __int128 b, __int128 m) {
    __int128 x, y;
    long long r;
    asm {
        pand y, m, b
        pand x, m, a
        pceqw y, y, x
        ppach r, y, y
    }
    return r == -1;
}
static inline __int128 kmerge(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pnor n, m, m
 pand c, m, cmp
 pand r, key, n
 por r, r, c }
    return r;
}
static inline char FindRace(SKL* skl) {
    char* t = 0;
    int n;
    for (n = 0; n < 32; n++) {
        char c = ((char*)&skl->attr[n].part)[9];
        if (c >= '0' && c <= '9') return c;
        t = (char*)&skl->attr[n].tex;
        c = t[9];
        if (c >= '0' && c <= '9') return c;
        if (t[0] == 0) return '_';
    }
    return '_';
}
void SwapDependencies__7MonsterFR3SKLR8ManParts11(Monster* self, SKL* skl, ManParts* parts, __int128 oldPart, __int128 newPart)
{
    int i, j, k;
    __int128 partRace;
    char* pr = (char*)&partRace;
    int found;
    if (!D_00493AB0) return;
    partRace = newPart;
    if (kmeq(self->blank, partRace, self->RACE_MASK))
        pr[9] = FindRace(skl);
    for (i = 0; i < parts->manAttribsCount; i++) {
        found = 0;
        for (j = 0; j < self->swapRuleCount; j++) {
            if (kmeq2(oldPart, self->swapRules[j].m[0], self->swapRules[j].m[1])
                && kmeq2(newPart, self->swapRules[j].m[2], self->swapRules[j].m[3])
                && !keq(newPart, skl->attr[i].tex)
                && kmeq(skl->attr[i].tex, oldPart, self->swapRules[j].m[1])) {
                __int128 key;
                __int128 tx = skl->attr[i].tex;
                __int128 m5 = self->swapRules[j].m[5];
                __int128 m7 = self->swapRules[j].m[7];
                __int128 x;
                asm {
                    pand key, newPart, m7
                    pxor x, m7, m5
                    pand m7, m5, tx
                    por key, m7, key
                }
                for (k = 0; k < self->manTexCount; k++) {
                    if (!keq(skl->attr[i].tex, self->texNames[k]) && kmeq(self->texNames[k], key, x)) {
                        if (kmeq(self->texNames[k], partRace, self->RACE_MASK) || kmeq3(self->texNames[k], self->blank, self->RACE_MASK)) {
                            skl->attr[i].tex = self->texNames[k];
                            parts->manTexID[i] = self->texIDs[k].a;
                            parts->manTexID2[i] = self->texIDs[k].b;
                            found = 1;
                            break;
                        }
                    }
                }
            }
            if (found) break;
        }
        if (!found) {
            if (!kmeq5(partRace, skl->attr[i].tex, self->RACE_MASK) && !kmeq2(skl->attr[i].tex, self->blank, self->RACE_MASK)) {
                Monster_FindTheTexture(self, kmerge(skl->attr[i].tex, partRace, self->RACE_MASK), &skl->attr[i], &parts->manTexID[i], &parts->manTexID2[i], SKL_FindSex(skl), pr[9]);
            }
        }
    }
}
