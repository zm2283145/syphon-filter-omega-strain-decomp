/* SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi (00401290) - manUtils.cc; mw38 args evaluate right-to-left into asm helpers */
#include "types.h"
typedef struct { int a; unsigned short b; unsigned char c; unsigned char d; int e; int f; } Parts;
typedef struct { __int128 part; __int128 tex; } manAttribs;
typedef struct { char raw[0x40]; manAttribs attr[32]; } SKL;
typedef struct { Parts bodyParts[2][32]; short manTexID[32]; short manTexID2[32]; __int128* bloodData[32]; unsigned short manAttribsCount; } ManParts;
typedef struct { __int128 m[8]; } SwapRule;
typedef struct {
    char pad0[0x70];
    __int128 TYPE_MASK;
    char pad80[0x40];
    unsigned int monsterPartCount;
    char padC4[0x20];
    unsigned int swapRuleCount;
    SwapRule* swapRules;
    char padEC[0x2C10 - 0xEC];
    __int128 names[0x300];
    Parts table[0x300][2];
} Monster;
extern int D_00493AB0;
void DELAY_DELETE_ARRAY(void* p);
void Monster_FindTheTexture(Monster* s, __int128 key, manAttribs* a, short* pa, short* pb, unsigned int sex, char race);
static inline __int128 kand(__int128 a, __int128 b) { __int128 r; asm { pand r, a, b } return r; }
static inline __int128 kor(__int128 a, __int128 b) { asm { por b, a, b } return b; }
static inline __int128 kor2(__int128 a, __int128 b) { __int128 r; asm { por r, b, a } return r; }
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
static inline __int128 kmerge(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pnor n, m, m
 pand c, cmp, m
 pand r, key, n
 por r, r, c }
    return r;
}
void SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi(Monster* self, SKL* skl, ManParts* parts, __int128 oldPart, __int128 newPart, unsigned int sex, unsigned int race)
{
    int i, j, k, found;
    if (!D_00493AB0) return;
    for (i = 0; i < parts->manAttribsCount; i++) {
        found = 0;
        for (j = 0; j < self->swapRuleCount; j++) {
            if (kmeq(oldPart, self->swapRules[j].m[0], self->swapRules[j].m[1])
                && kmeq2(newPart, self->swapRules[j].m[2], self->swapRules[j].m[3])
                && !keq(newPart, skl->attr[i].part)
                && kmeq(skl->attr[i].part, oldPart, self->swapRules[j].m[1])) {
                __int128 t = kand(newPart, self->swapRules[j].m[7]);
                __int128 x = kxor(self->swapRules[j].m[7], self->swapRules[j].m[5]);
                __int128 key = kor(kand(self->swapRules[j].m[5], skl->attr[i].part), t);
                for (k = 0; k < self->monsterPartCount; k++) {
                    if (kmeq(self->names[k], key, x)) {
                        if (!keq(skl->attr[i].part, self->names[k])) {
                            int m;
                            skl->attr[i].part = self->names[k];
                            for (m = 0; m < 2; m++) {
                                Parts* src = &self->table[k][m];
                                Parts* d = &parts->bodyParts[m][i];
                                d->a = src->a; d->b = src->b; d->c = src->c; d->d = src->d; d->e = src->e; d->f = src->f;
                                if (parts->bloodData[i]) {
                                    DELAY_DELETE_ARRAY(parts->bloodData[i]);
                                    parts->bloodData[i] = 0;
                                }
                            }
                            Monster_FindTheTexture(self, kmerge(skl->attr[i].part, skl->attr[i].tex, self->TYPE_MASK), &skl->attr[i], &parts->manTexID[i], &parts->manTexID2[i], sex, (char)race);
                        }
                        found = 1;
                        break;
                    }
                }
            }
            if (found) break;
        }
    }
}
