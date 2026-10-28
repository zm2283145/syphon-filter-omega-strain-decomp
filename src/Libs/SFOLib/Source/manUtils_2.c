/*
 * Libs/SFOLib/Source/manUtils: 8 files, 00400160-00401970
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00400160 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char* data; unsigned short free; unsigned char used; unsigned char type; char* base; int size; } SkmEnt;
typedef struct { char* buf0; int f4; char* buf8; } SkmSrc;
extern SkmEnt D_005639B0[][2];
extern void Parts_SetManData(SkmEnt* b, char* buf, unsigned int size, long a, long c, char flag);
void Parts_PartStreamReturn(SkmSrc* src, SkmEnt* e, int ok)
{
    int id = e->free;
    int slot;
    if (ok) {
        slot = e->used;

        Parts_SetManData(e, src->buf8 ? src->buf8 : src->buf0, e->size, id, slot, 0);
        if (D_005639B0[id][slot ^ 1].free == 0) {
            D_005639B0[id][slot ^ 1].data = D_005639B0[id][slot].data;
            D_005639B0[id][slot ^ 1].free = D_005639B0[id][slot].free;
            D_005639B0[id][slot ^ 1].used = D_005639B0[id][slot].used;
            D_005639B0[id][slot ^ 1].type = D_005639B0[id][slot].type;
            D_005639B0[id][slot ^ 1].base = D_005639B0[id][slot].base;
            D_005639B0[id][slot ^ 1].size = D_005639B0[id][slot].size;
        }
    } else {
        e->data = 0;
        e->free = 0;
        e->used = 0;
        e->type = 0;
        e->base = 0;
        e->size = 0;
    }
}
static inline void merge_flush_func_00400160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00400160 */

/* merge_units: begin func_004002B0 */
#pragma push /* merge_units */
typedef struct { short a; short b; } KTex;
typedef struct {
    char pad0[0x20];
    __int128 m20;
    __int128 m30;
    __int128 m40;
    __int128 m50;
    __int128 m60;
    char pad70[0x20];
    __int128 m90;
    char padA0[0x10];
    __int128 mB0;
    char padC0[0xC];
    unsigned int count;
    char padD0[0x1410 - 0xD0];
    KTex tex[0x2A00];
    __int128 keys[0x600];
} KState;
typedef struct { __int128 a; __int128 key; } KOut;
typedef struct { char pad0[9]; signed char c9; } KB;
static inline __int128 kand(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 kor(__int128 a, __int128 b) {
    __int128 r;
    asm { por r, a, b }
    return r;
}
static inline __int128 knot(__int128 a) {
    __int128 r;
    asm { pnor r, a, a }
    return r;
}
static inline __int128 kxor(__int128 a, __int128 b) {
    __int128 r;
    asm { pxor r, a, b }
    return r;
}
static inline __int128 kfrom(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline __int128 kpair(__int128 hi, __int128 lo) {
    __int128 r;
    asm { pcpyld r, hi, lo }
    return r;
}
static inline int keq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 kmerge(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pand c, cmp, m
 pnor n, m, m
 pand r, key, n
 por r, r, c }
    return r;
}
static inline int kmeq(__int128 m, __int128 a, __int128 b) {
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
static inline int flagok(__int128 k, int flag) {
    signed char* p = (signed char*)&k;
    int ok;
    if (flag == 0) ok = 1;
    else if (p[9] == '_') ok = 1;
    else if (p[9] == flag) ok = 1;
    else ok = 0;
    return ok;
}
int AgentPacking_StepTexture(KState* s, int step, __int128 key, __int128 cmp, unsigned int start, int idx, int mode, int flag, KOut* out, short* sh)
{
    __int128 K = kpair(0x4C, 0x4C410000LL << 32);
    __int128 m50;
    __int128 mask;
    start += step;
    m50 = s->m50;
    {
        __int128 m20 = s->m20;
        key = kmerge(key, cmp, m20);
    }
    key = kmerge(key, cmp, s->m40);
    mask = kand(s->m90, key);
    if (((signed char*)&key)[4] == 'X')
        m50 = kxor(s->mB0, m50);
    if (mode == 1)
        cmp = kfrom(50);
    if (mode == 0)
        cmp = kfrom(49);
    for (; start < s->count; start += step) {
        if (kmeq(m50, s->keys[start], mask)
            && (kmeq(s->m60, s->keys[start], mask) || kmeq(s->m60, s->keys[start], K))
            && !kmeq(s->m30, s->keys[start], cmp)) {
            int ok;
            ok = flagok(s->keys[start], flag);
            if (ok) {
                out[idx + 2].key = s->keys[start];
                sh[idx + 0x200] = s->tex[start].a;
                sh[idx + 0x220] = s->tex[start].b;
                return start;
            }
        }
    }
    start = 0;
    if (step == -1)
        start = s->count - 1;
    for (; start < s->count; start += step) {
        if (kmeq(m50, s->keys[start], mask)
            && (kmeq(s->m60, s->keys[start], mask) || kmeq(s->m60, s->keys[start], K))
            && !kmeq(s->m30, s->keys[start], cmp)) {
            int ok;
            ok = flagok(s->keys[start], flag);
            if (ok) {
                out[idx + 2].key = s->keys[start];
                sh[idx + 0x200] = s->tex[start].a;
                sh[idx + 0x220] = s->tex[start].b;
                return start;
            }
        }
    }
    return -1;
}
static inline void merge_flush_func_004002B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004002B0 */

/* merge_units: begin func_00400620 */
#pragma push /* merge_units */
static inline __int128 kmerge0(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pnor n, m, m
 pand c, cmp, m
 pand key, n, key
 por r, key, c }
    return r;
}
static inline int kmeq2(__int128 m, __int128 a, __int128 b) {
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
#if 0 /* merge_units */
void SwapDependencies__7MonsterFR3SKLR8ManParts11(KState* s, KOut* out, short* sh, __int128 key, __int128 k);
#endif /* merge_units */
void SwapDependencies__7MonsterFR3SKLR8ManParts11(); /* merge_units */

int FindNextAnyTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(KState* s, int step, __int128 key, __int128 cmp, unsigned int start, int idx, int mode, int flag, KOut* out, short* sh)
{
    __int128 m50;
    __int128 mask;
    __int128 K;
    __int128 v;
    m50 = s->m50;
    key = kmerge(key, cmp, s->m20);
    key = kmerge(key, cmp, s->m40);
    K = kfrom(0x5F00LL << 32);
    mask = kand(s->m90, key);
    start += step;
    if (((signed char*)&key)[4] == 'X')
        m50 = kxor(s->mB0, m50);
    if (mode == 1)
        v = kfrom(50);
    if (mode == 0)
        v = kfrom(49);
    for (; start < s->count; start += step) {
        if (kmeq(m50, s->keys[start], mask) && !kmeq(s->m30, s->keys[start], v)) {
            int ok;
            ok = flagok(s->keys[start], flag);
            if (ok) {
                out[idx + 2].key = s->keys[start];
                sh[idx + 0x200] = s->tex[start].a;
                sh[idx + 0x220] = s->tex[start].b;
                if (!kmeq2(s->m40, K, key))
                    SwapDependencies__7MonsterFR3SKLR8ManParts11(s, out, sh, key, s->keys[start]);
                return start;
            }
        }
    }
    start = 0;
    if (step == -1)
        start = s->count - 1;
    for (; start < s->count; start += step) {
        if (kmeq(m50, s->keys[start], mask) && !kmeq(s->m30, s->keys[start], v)) {
            int ok;
            ok = flagok(s->keys[start], flag);
            if (ok) {
                out[idx + 2].key = s->keys[start];
                sh[idx + 0x200] = s->tex[start].a;
                sh[idx + 0x220] = s->tex[start].b;
                if (!kmeq2(s->m40, K, key))
                    SwapDependencies__7MonsterFR3SKLR8ManParts11(s, out, sh, key, s->keys[start]);
                return start;
            }
        }
    }
    return -1;
}
static inline void merge_flush_func_00400620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00400620 */

/* merge_units: begin func_00400990 */
#pragma push /* merge_units */
/* FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts (00400990) - manUtils.cc; KState layout shared with manUtils_2 FindNextAnyTexture */

#if 0 /* merge_units */
void SwapDependencies__7MonsterFR3SKLR8ManParts11(KState* s, KOut* out, short* sh, __int128 key, __int128 k);
#endif /* merge_units */
void SwapDependencies__7MonsterFR3SKLR8ManParts11(); /* merge_units */

int FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(KState* s, int step, __int128 key, __int128 cmp, unsigned int start, int idx, int mode, int flag, KOut* out, short* sh)
{
    __int128 m50;
    __int128 mask;
    __int128 K;
    __int128 K2;
    __int128 v;
    unsigned int start0;
    m50 = s->m50;
    key = kmerge(key, cmp, s->m20);
    key = kmerge(key, cmp, s->m40);
    K = kfrom(0x5F00LL << 32);
    K2 = kpair(0x4C, 0x4C410000LL << 32);
    start += step;
    mask = kand(s->m90, key);
    start0 = start;
    if (((signed char*)&key)[4] == 'X')
        m50 = kxor(s->mB0, m50);
    if (mode == 1)
        v = kfrom(50);
    if (mode == 0)
        v = kfrom(49);
    for (; start < s->count; start += step) {
        if (kmeq(m50, s->keys[start], mask)
            && (kmeq(s->m60, s->keys[start], mask) || kmeq(s->m60, s->keys[start], K2))
            && !kmeq2(s->m30, s->keys[start], v)) {
            out[idx + 2].key = s->keys[start];
            sh[idx + 0x200] = s->tex[start].a;
            sh[idx + 0x220] = s->tex[start].b;
            if (!kmeq2(s->m20, s->keys[start], key) || !kmeq2(s->m40, K, key))
                SwapDependencies__7MonsterFR3SKLR8ManParts11(s, out, sh, key, s->keys[start]);
            return start;
        }
    }
    start = 0;
    if (step == -1)
        start = s->count - 1;
    for (; start < s->count; start += step) {
        if (kmeq(m50, s->keys[start], mask)
            && (kmeq(s->m60, s->keys[start], mask) || kmeq(s->m60, s->keys[start], K2))
            && !kmeq2(s->m30, s->keys[start], v)) {
            out[idx + 2].key = s->keys[start];
            sh[idx + 0x200] = s->tex[start].a;
            sh[idx + 0x220] = s->tex[start].b;
            if (!kmeq2(s->m20, s->keys[start], key) || !kmeq2(s->m40, K, key))
                SwapDependencies__7MonsterFR3SKLR8ManParts11(s, out, sh, key, s->keys[start]);
            return start;
        }
    }
    for (start = start0; start < s->count; start += step) {
        if (kmeq(m50, s->keys[start], mask) && !kmeq2(s->m30, s->keys[start], v)) {
            out[idx + 2].key = s->keys[start];
            sh[idx + 0x200] = s->tex[start].a;
            sh[idx + 0x220] = s->tex[start].b;
            if (!kmeq2(s->m20, s->keys[start], key) || !kmeq2(s->m40, K, key))
                SwapDependencies__7MonsterFR3SKLR8ManParts11(s, out, sh, key, s->keys[start]);
            return start;
        }
    }
    start = 0;
    if (step == -1)
        start = s->count - 1;
    for (; start < s->count; start += step) {
        if (kmeq(m50, s->keys[start], mask) && !kmeq2(s->m30, s->keys[start], v)) {
            out[idx + 2].key = s->keys[start];
            sh[idx + 0x200] = s->tex[start].a;
            sh[idx + 0x220] = s->tex[start].b;
            if (!kmeq2(s->m20, s->keys[start], key) || !kmeq2(s->m40, K, key))
                SwapDependencies__7MonsterFR3SKLR8ManParts11(s, out, sh, key, s->keys[start]);
            return start;
        }
    }
    return -1;
}
static inline void merge_flush_func_00400990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00400990 */

/* merge_units: begin func_00400F20 */
#pragma push /* merge_units */
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
static inline __int128 kor_00400F20(__int128 a, __int128 b) { asm { por b, a, b } return b; }
static inline int kmeq_00400F20(__int128 a, __int128 b, __int128 m) {
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
static inline int kmeq2_00400F20(__int128 a, __int128 b, __int128 m) {
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
static inline __int128 kmerge_00400F20(__int128 key, __int128 cmp, __int128 m) {
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
    if (kmeq_00400F20(self->blank, partRace, self->RACE_MASK))
        pr[9] = FindRace(skl);
    for (i = 0; i < parts->manAttribsCount; i++) {
        found = 0;
        for (j = 0; j < self->swapRuleCount; j++) {
            if (kmeq2_00400F20(oldPart, self->swapRules[j].m[0], self->swapRules[j].m[1])
                && kmeq2_00400F20(newPart, self->swapRules[j].m[2], self->swapRules[j].m[3])
                && !keq(newPart, skl->attr[i].tex)
                && kmeq_00400F20(skl->attr[i].tex, oldPart, self->swapRules[j].m[1])) {
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
                    if (!keq(skl->attr[i].tex, self->texNames[k]) && kmeq_00400F20(self->texNames[k], key, x)) {
                        if (kmeq_00400F20(self->texNames[k], partRace, self->RACE_MASK) || kmeq3(self->texNames[k], self->blank, self->RACE_MASK)) {
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
            if (!kmeq5(partRace, skl->attr[i].tex, self->RACE_MASK) && !kmeq2_00400F20(skl->attr[i].tex, self->blank, self->RACE_MASK)) {
                Monster_FindTheTexture(self, kmerge_00400F20(skl->attr[i].tex, partRace, self->RACE_MASK), &skl->attr[i], &parts->manTexID[i], &parts->manTexID2[i], SKL_FindSex(skl), pr[9]);
            }
        }
    }
}
static inline void merge_flush_func_00400F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00400F20 */

/* merge_units: begin func_00401290 */
#pragma push /* merge_units */
/* SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi (00401290) - manUtils.cc; mw38 args evaluate right-to-left into asm helpers */

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
} Monster_00401290;
void DELAY_DELETE_ARRAY(void* p);
#if 0 /* merge_units */
void Monster_FindTheTexture(Monster_00401290* s, __int128 key, manAttribs* a, short* pa, short* pb, unsigned int sex, char race);
#endif /* merge_units */
#define Monster_FindTheTexture(a0, a1, a2, a3, a4, a5, a6) (Monster_FindTheTexture((Monster *)(a0), (a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */

static inline __int128 kor_00401290(__int128 a, __int128 b) { asm { por b, a, b } return b; }
static inline __int128 kor2(__int128 a, __int128 b) { __int128 r; asm { por r, b, a } return r; }
static inline int kmeq_00401290(__int128 a, __int128 b, __int128 m) {
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
static inline int kmeq2_00401290(__int128 a, __int128 b, __int128 m) {
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
static inline __int128 kmerge_00401290(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pnor n, m, m
 pand c, cmp, m
 pand r, key, n
 por r, r, c }
    return r;
}
void SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi(Monster_00401290* self, SKL* skl, ManParts* parts, __int128 oldPart, __int128 newPart, unsigned int sex, unsigned int race)
{
    int i, j, k, found;
    if (!D_00493AB0) return;
    for (i = 0; i < parts->manAttribsCount; i++) {
        found = 0;
        for (j = 0; j < self->swapRuleCount; j++) {
            if (kmeq_00401290(oldPart, self->swapRules[j].m[0], self->swapRules[j].m[1])
                && kmeq2_00401290(newPart, self->swapRules[j].m[2], self->swapRules[j].m[3])
                && !keq(newPart, skl->attr[i].part)
                && kmeq_00401290(skl->attr[i].part, oldPart, self->swapRules[j].m[1])) {
                __int128 t = kand(newPart, self->swapRules[j].m[7]);
                __int128 x = kxor(self->swapRules[j].m[7], self->swapRules[j].m[5]);
                __int128 key = kor_00401290(kand(self->swapRules[j].m[5], skl->attr[i].part), t);
                for (k = 0; k < self->monsterPartCount; k++) {
                    if (kmeq_00401290(self->names[k], key, x)) {
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
                            Monster_FindTheTexture(self, kmerge_00401290(skl->attr[i].part, skl->attr[i].tex, self->TYPE_MASK), &skl->attr[i], &parts->manTexID[i], &parts->manTexID2[i], sex, (char)race);
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
#undef Monster_FindTheTexture /* merge_units */
static inline void merge_flush_func_00401290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00401290 */

/* merge_units: begin func_00401570 */
#pragma push /* merge_units */
/* Monster_FindNextSamePart (00401570) - manUtils.cc; badSex=0 initialised before mask build steers mask temp to t0; (int) casts on top assignment defeat CSE */

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
} Monster_00401570;
#if 0 /* merge_units */
void Monster_FindTheTexture(Monster_00401570* s, __int128 key, manAttribs* a, short* pa, short* pb, unsigned int sex, char race);
#endif /* merge_units */
#define Monster_FindTheTexture(a0, a1, a2, a3, a4, a5, a6) (Monster_FindTheTexture((Monster *)(a0), (a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */

static inline __int128 kor_00401570(__int128 a, __int128 b) { asm { por b, a, b } return b; }
static inline int kmeq_00401570(__int128 a, __int128 b, __int128 m) {
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
static inline int kmeq2_00401570(__int128 a, __int128 b, __int128 m) {
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
static inline __int128 kmerge_00401570(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pnor n, m, m
 pand c, cmp, m
 pand r, key, n
 por r, r, c }
    return r;
}
int Monster_FindNextSamePart(Monster_00401570* self, int direction, __int128 fullPartName, unsigned int partNumber, unsigned int bodyPart, unsigned int sex, unsigned int race, SKL* skl, ManParts* parts)
{
    __int128 badSex = 0;
    __int128 mask = kpair(0xFFFFFFFF0000LL, 0xFFFFFFFFFF00LL);
    partNumber += direction;
    fullPartName = kand(mask, fullPartName);
    if (sex == 1) badSex = 50;
    if (sex == 0) badSex = 49;
    for (; partNumber < self->monsterPartCount; partNumber += direction) {
        if (kmeq_00401570(self->names[partNumber], fullPartName, mask) && !kmeq2_00401570(self->names[partNumber], badSex, self->SEX_MASK)) {
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
            Monster_FindTheTexture(self, kmerge_00401570(kmerge_00401570(self->names[partNumber], skl->attr[bodyPart].part, self->RACE_MASK), skl->attr[bodyPart].tex, self->TYPE_MASK), &skl->attr[bodyPart], &parts->manTexID[bodyPart], &parts->manTexID2[bodyPart], sex, (char)race);
            return partNumber;
        }
    }
    partNumber = 0;
    if (direction == -1) partNumber = self->monsterPartCount - 1;
    for (; partNumber < self->monsterPartCount; partNumber += direction) {
        if (kmeq_00401570(self->names[partNumber], fullPartName, mask) && !kmeq2_00401570(self->names[partNumber], badSex, self->SEX_MASK)) {
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
            Monster_FindTheTexture(self, kmerge_00401570(kmerge_00401570(self->names[partNumber], skl->attr[bodyPart].part, self->RACE_MASK), skl->attr[bodyPart].tex, self->TYPE_MASK), &skl->attr[bodyPart], &parts->manTexID[bodyPart], &parts->manTexID2[bodyPart], sex, (char)race);
            return partNumber;
        }
    }
    return -1;
}
#undef Monster_FindTheTexture /* merge_units */
static inline void merge_flush_func_00401570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00401570 */

/* merge_units: begin func_00401970 */
#pragma push /* merge_units */
/* Monster_FindNextPart (00401970) - manUtils.cc; sibling of FindNextSamePart (00401570) */

typedef struct {
    __int128 blank;
    __int128 none;
    __int128 RACE_MASK;
    __int128 SEX_MASK;
    char pad40[0x30];
    __int128 TYPE_MASK;
    char pad80[0x20];
    __int128 NAMEL_MASK;
    char padB0[0x10];
    unsigned int monsterPartCount;
    char padC4[0x20];
    unsigned int swapRuleCount;
    SwapRule* swapRules;
    char padEC[0x2C10 - 0xEC];
    __int128 names[0x300];
    Parts table[0x300][2];
} Monster_00401970;
#if 0 /* merge_units */
void Monster_FindTheTexture(Monster_00401970* s, __int128 key, manAttribs* a, short* pa, short* pb, unsigned int sex, char race);
#endif /* merge_units */
#define Monster_FindTheTexture(a0, a1, a2, a3, a4, a5, a6) (Monster_FindTheTexture((Monster *)(a0), (a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */

static inline __int128 kor_00401970(__int128 a, __int128 b) { asm { por b, a, b } return b; }
static inline int kmeq_00401970(__int128 a, __int128 b, __int128 m) {
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
static inline int kmeq2_00401970(__int128 a, __int128 b, __int128 m) {
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
static inline __int128 kmerge_00401970(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pnor n, m, m
 pand c, cmp, m
 pand r, key, n
 por r, r, c }
    return r;
}
static inline __int128 kmergeB(__int128 key, __int128 cmp, __int128 m) {
    __int128 c, r, n;
    asm { pand c, cmp, m
 pnor n, m, m
 pand r, key, n
 por r, r, c }
    return r;
}
#if 0 /* merge_units */
void SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi(Monster_00401970* self, SKL* skl, ManParts* parts, __int128 oldPart, __int128 newPart, unsigned int sex, unsigned int race);
#endif /* merge_units */
#define SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi(a0, a1, a2, a3, a4, a5, a6) (SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi((Monster_00401290 *)(a0), (a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */

int Monster_FindNextPart(Monster_00401970* self, int direction, __int128 fullPartName, unsigned int partNumber, unsigned int bodyPart, unsigned int sex, unsigned int race, SKL* skl, ManParts* parts)
{
    __int128 badSex = 0;
    __int128 search;
    partNumber += direction;
    search = kand(self->NAMEL_MASK, fullPartName);
    if (sex == 1) badSex = 50;
    if (sex == 0) badSex = 49;
    for (; partNumber < self->monsterPartCount; partNumber += direction) {
        if (kmeq_00401970(self->names[partNumber], search, self->NAMEL_MASK) && !kmeq2_00401970(self->names[partNumber], badSex, self->SEX_MASK)) {
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
            {
                __int128 nameWithRace = self->names[partNumber];
                ((char*)&nameWithRace)[9] = race;
                nameWithRace = kmergeB(nameWithRace, skl->attr[bodyPart].tex, self->TYPE_MASK);
                Monster_FindTheTexture(self, nameWithRace, &skl->attr[bodyPart], &parts->manTexID[bodyPart], &parts->manTexID2[bodyPart], sex, (char)race);
            }
            if (!kmeq2_00401970(self->names[partNumber], self->none, self->TYPE_MASK))
                SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi(self, skl, parts, fullPartName, self->names[partNumber], sex, race);
            return partNumber;
        }
    }    partNumber = 0;
    if (direction == -1) partNumber = self->monsterPartCount - 1;
    for (; partNumber < self->monsterPartCount; partNumber += direction) {
        if (kmeq_00401970(self->names[partNumber], search, self->NAMEL_MASK) && !kmeq2_00401970(self->names[partNumber], badSex, self->SEX_MASK)) {
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
            {
                __int128 nameWithRace = self->names[partNumber];
                ((char*)&nameWithRace)[9] = race;
                nameWithRace = kmergeB(nameWithRace, skl->attr[bodyPart].tex, self->TYPE_MASK);
                Monster_FindTheTexture(self, nameWithRace, &skl->attr[bodyPart], &parts->manTexID[bodyPart], &parts->manTexID2[bodyPart], sex, (char)race);
            }
            if (!kmeq2_00401970(self->names[partNumber], self->none, self->TYPE_MASK))
                SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi(self, skl, parts, fullPartName, self->names[partNumber], sex, race);
            return partNumber;
        }
    }    return -1;
}
#undef Monster_FindTheTexture /* merge_units */
#undef SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi /* merge_units */
static inline void merge_flush_func_00401970(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00401970 */
