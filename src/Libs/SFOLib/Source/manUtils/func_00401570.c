/* Monster_FindNextSamePart (00401570) - manUtils.cc; badSex=0 initialised before mask build steers mask temp to t0; (int) casts on top assignment defeat CSE */
#include "types.h"
typedef struct { int a; unsigned short b; unsigned char c; unsigned char d; int e; int f; } Parts;
typedef struct { __int128 part; __int128 tex; } manAttribs;
typedef struct { char raw[0x40]; manAttribs attr[32]; } SKL;
typedef struct { Parts bodyParts[2][32]; short manTexID[32]; short manTexID2[32]; __int128* bloodData[32]; unsigned short manAttribsCount; } ManParts;
typedef struct { __int128 m[8]; } SwapRule;
typedef struct {
    __int128 blank;
    __int128 none;
    __int128 RACE_MASK;
    __int128 SEX_MASK;
    char pad40[0x30];
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
static inline __int128 kfrom(__int128 v) { __int128 r; asm { pcpyld r, zero, v } return r; }
static inline __int128 kpair(__int128 hi, __int128 lo) { __int128 r; asm { pcpyld r, hi, lo } return r; }
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
int Monster_FindNextSamePart(Monster* self, int direction, __int128 fullPartName, unsigned int partNumber, unsigned int bodyPart, unsigned int sex, unsigned int race, SKL* skl, ManParts* parts)
{
    __int128 badSex = 0;
    __int128 mask = kpair(0xFFFFFFFF0000LL, 0xFFFFFFFFFF00LL);
    partNumber += direction;
    fullPartName = kand(mask, fullPartName);
    if (sex == 1) badSex = 50;
    if (sex == 0) badSex = 49;
    for (; partNumber < self->monsterPartCount; partNumber += direction) {
        if (kmeq(self->names[partNumber], fullPartName, mask) && !kmeq2(self->names[partNumber], badSex, self->SEX_MASK)) {
            int m;
            skl->attr[(int)bodyPart].part = self->names[(int)partNumber];
            for (m = 0; m < 2; m++) {
                Parts* src = &self->table[partNumber][m];
                Parts* d = &parts->bodyParts[m][bodyPart];
                d->a = src->a; d->b = src->b; d->c = src->c; d->d = src->d; d->e = src->e; d->f = src->f;
                if (parts->bloodData[bodyPart]) {
                    DELAY_DELETE_ARRAY(parts->bloodData[bodyPart]);
                    parts->bloodData[bodyPart] = 0;
                }
            }
            Monster_FindTheTexture(self, kmerge(kmerge(self->names[partNumber], skl->attr[bodyPart].part, self->RACE_MASK), skl->attr[bodyPart].tex, self->TYPE_MASK), &skl->attr[bodyPart], &parts->manTexID[bodyPart], &parts->manTexID2[bodyPart], sex, (char)race);
            return partNumber;
        }
    }
    partNumber = 0;
    if (direction == -1) partNumber = self->monsterPartCount - 1;
    for (; partNumber < self->monsterPartCount; partNumber += direction) {
        if (kmeq(self->names[partNumber], fullPartName, mask) && !kmeq2(self->names[partNumber], badSex, self->SEX_MASK)) {
            int m;
            skl->attr[(int)bodyPart].part = self->names[(int)partNumber];
            for (m = 0; m < 2; m++) {
                Parts* src = &self->table[partNumber][m];
                Parts* d = &parts->bodyParts[m][bodyPart];
                d->a = src->a; d->b = src->b; d->c = src->c; d->d = src->d; d->e = src->e; d->f = src->f;
                if (parts->bloodData[bodyPart]) {
                    DELAY_DELETE_ARRAY(parts->bloodData[bodyPart]);
                    parts->bloodData[bodyPart] = 0;
                }
            }
            Monster_FindTheTexture(self, kmerge(kmerge(self->names[partNumber], skl->attr[bodyPart].part, self->RACE_MASK), skl->attr[bodyPart].tex, self->TYPE_MASK), &skl->attr[bodyPart], &parts->manTexID[bodyPart], &parts->manTexID2[bodyPart], sex, (char)race);
            return partNumber;
        }
    }
    return -1;
}