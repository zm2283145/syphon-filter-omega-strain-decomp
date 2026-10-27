/*
 * Libs/SFOLib/Source/manUtils: 5 files, 00404060-00404AA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00404060 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
int strcmp(const void *, const void *);

#pragma cplusplus on
extern "C" {
typedef struct {
    int p;
    unsigned short h;
    unsigned char b6;
    unsigned char b7;
    int f8;
    void* fC;
} Rec_S;
typedef struct {
    char pad0[0xC0];
    unsigned int count;
    unsigned int fC4;
    unsigned int fC8;
    char padCC[0xD4 - 0xCC];
    void* bufD4;
    void* bufD8;
    char padDC[0x210 - 0xDC];
    short h210[1];
    char pad212[0x2C10 - 0x212];
    __int128 keys[0x300];
    Rec_S recs[1][2];
} Cache_S;
typedef struct { int pad; int n; } Lst_S;
typedef struct { char pad[0x148]; Lst_S* list; } Npc_S;
extern char D_004BE7F0[];
extern char D_004BE830[];
extern char D_004BE838[];
extern char D_004BE840[];
extern char D_004BE848[];
extern char g_MorphGripKeys[24][7];
extern int D_005712F0[2];
extern __int128* D_005712F8[2];
extern __int128* D_005714F0[2][2];
extern unsigned char D_00571500[2][2];
extern unsigned char D_00571510[2][2][24];
int cHogFile_GetBlockSize(Npc_S* npc, int i);
char* cHogFile_GetBlockName(Npc_S* npc, int i);
__int128* cHogFile_GetBlock_int(Npc_S* npc, int i);
void strCpyPad(char* dst, int n, char* src);
char* strrchr(char* s, int c);
unsigned int Monster_AddMonsterPart(Cache_S* c, __int128 key, int k);
void Parts_SetManData(Rec_S* r, void* pkt, int a, long long slot, long long k, long long z);

typedef union { __int128 q; char s[16]; } KU;

void Monster_LoadFaceHog(Cache_S* c, Npc_S* npc)
{
    unsigned int j;
    void* p;
    int n;
    int i;
    int a;
    char* name;
    __int128* pkt;
    char* ext;
    int lod;
    int slot;

    j = c->count;
    p = c->bufD4;
    if (p) {
        {
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_004BE7F0, 0x7D1);
        }
        p = c->bufD8;
        {
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_004BE7F0, 0x7D2);
        }
        c->bufD4 = 0;
        c->bufD8 = 0;
    }
    n = npc->list->n;
    for (i = 0; i < n; i++) {
        KU key;
        KU k2;
        char* ks = key.s;
        a = cHogFile_GetBlockSize(npc, i);
        if (!a) continue;
        name = cHogFile_GetBlockName(npc, i);
        pkt = cHogFile_GetBlock_int(npc, i);
        strCpyPad(ks, 15, name);
        ext = strrchr(name, '.');
        if (!ext) ext = name;
        if (strcmp(ext, D_004BE830) == 0 || strcmp(ext, D_004BE838) == 0) {
            k2.q = key.q;
            lod = *(k2.s + 14) - '0';
            if (lod >= 2 || lod < 0) lod = 0;
            slot = Monster_AddMonsterPart(c, key.q, lod);
        }
        if (strcmp(ext, D_004BE830) == 0) {
            long long z;
            if (lod == 0) {
                char ch = ks[5];
                if (ch == '1') z = 2;
                else if (ch == '2') z = 1;
                else z = 3;
            } else {
                z = 0;
            }
            Parts_SetManData(&c->recs[slot][lod], pkt, a, slot, lod, z);
            c->h210[slot] = 0;
        } else if (strcmp(ext, D_004BE838) == 0) {
            c->recs[slot][lod].fC = pkt;
        } else if (strcmp(ext, D_004BE840) == 0) {
            char ch = *ks;
            int idx = 1;
            if (ch == '1' || ch == '2') {
                int x = (ch - '0') & 1;
                int y = (ks[5] - '0') & 1;
                __int128* q;
                unsigned char cnt;
                int k;
                __int128* e;
                int m;
                unsigned char* out;
                char* nm;
                D_005714F0[x][y] = pkt;
                q = pkt;
                if (*(__int128*)pkt) {
                    do {
                        q++;
                        D_00571500[x][y]++;
                    } while (*q);
                }
                cnt = D_00571500[x][y];
                k = 0;
                out = D_00571510[x][y];
                nm = g_MorphGripKeys[0];
                for (; k < 24; k++) {
                    *out = 0;
                    e = pkt;
                    for (m = 0; m < cnt; m++) {
                        if (strcmp(nm, (char*)e) == 0) {
                            *out = m;
                            break;
                        }
                        e++;
                    }
                    out++;
                    nm += 7;
                }
            } else {
                __int128* q;
                if (strcmp(ks, D_004BE848) == 0) idx = 0;
                D_005712F8[idx] = pkt;
                q = D_005712F8[idx];
                D_005712F0[idx] = 0;
                while (*q) {
                    q++;
                    D_005712F0[idx]++;
                }
            }
        }
    }
    c->fC4 = c->count;
    c->fC8 = c->count;
    for (; j < c->count; j++) {
        if (c->recs[j][1].f8 == 0) {
            c->recs[j][1].p = c->recs[j][0].p;
            c->recs[j][1].h = c->recs[j][0].h;
            c->recs[j][1].b6 = c->recs[j][0].b6;
            c->recs[j][1].b7 = c->recs[j][0].b7;
            c->recs[j][1].f8 = c->recs[j][0].f8;
            c->recs[j][1].fC = c->recs[j][0].fC;
        }
        if (c->recs[j][0].f8 == 0) {
            c->recs[j][0].p = c->recs[j][1].p;
            c->recs[j][0].h = c->recs[j][1].h;
            c->recs[j][0].b6 = c->recs[j][1].b6;
            c->recs[j][0].b7 = c->recs[j][1].b7;
            c->recs[j][0].f8 = c->recs[j][1].f8;
            c->recs[j][0].fC = c->recs[j][1].fC;
        }
    }
}

}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00404060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00404060 */

/* merge_units: begin func_00404690 */
#pragma push /* merge_units */
typedef struct { char pad0[0xC0]; unsigned int count; char pad1[0x2C10 - 0xC4]; __int128 keys[1]; } K690;
static inline int k690eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
unsigned int FindPartNumber__7MonsterF1(K690* s, __int128 key) {
    unsigned int i;
    for (i = 0; i < s->count; i++) {
        if (k690eq(key, s->keys[i]))
            return i;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00404690(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00404690 */

/* merge_units: begin func_004046F0 */
#pragma push /* merge_units */
typedef struct { char pad0[0x80]; __int128 mask; char pad1[0xC0 - 0x90]; unsigned int count; char pad2[0x2C10 - 0xC4]; __int128 keys[1]; } K6F0;
static inline __int128 k6f0and(__int128 a, __int128 b) {
    __int128 t;
    asm { pand t, a, b }
    return t;
}
static inline int k6f0eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
unsigned int FindPart__7MonsterF1(K6F0* s, __int128 key) {
    unsigned int i;
    for (i = 0; i < s->count; i++) {
        if (k6f0eq(k6f0and(s->mask, s->keys[i]), k6f0and(s->mask, key)))
            return i;
    }
    return -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004046F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004046F0 */

/* merge_units: begin func_00404750 */
#pragma push /* merge_units */
/* Monster_LoadAPart: reference an agent part mesh in the cache, or claim a slot for it and queue
 * its two LOD files (<key><lod suffix>) for streaming. Missing LOD 1 reuses the LOD 0 record.
 * Layout as in Monster_LoadParts (Monster_LoadParts.c) and FindPart__7MonsterF1. */
typedef struct {
    int p;
    unsigned short h;
    unsigned char b6;
    unsigned char b7;
    int f8;
    int fC;
} Rec_4750;
typedef struct {
    char pad0[0x80];
    __int128 mask;
    char pad90[0xC0 - 0x90];
    unsigned int count;
    int padC4;
    int fC8;
    char padCC[0x210 - 0xCC];
    short h210[0x300];
    char pad810[0x2C10 - 0x810];
    __int128 keys[0x300];
    Rec_4750 recs[1][2];
} Cache_4750;
typedef struct { char pad0[0x98]; int x98; } Hog_4750;
typedef union { __int128 q; char s[16]; } Key_4750;
extern __int128 g_AgentPartCache;
extern __int128 D_0055DE00;
extern __int128 D_00493A70[2];
extern Key_4750 D_00493AE0;
extern char D_004BE850[];
int sprintf(char* d, const char* f, ...);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(Hog_4750* h, char* name, int a, int b);
int cFileMan_Open(Hog_4750* h);
int cFileMan_GetSize(Hog_4750* h);
int GetFileStreamMan(void);
void cFileStreamMan_StreamRequest(int q, Hog_4750* h, void* cb, Rec_4750* r, int a, int b, int c);
void Parts_PartStreamReturn(void);

/* 128-bit key helpers (MMI pand/por/pceqw), as in FindPart__7MonsterF1 */
static inline __int128 k4750and(__int128 a, __int128 b) {
    __int128 t;
    asm { pand t, a, b }
    return t;
}
static inline __int128 k4750or(__int128 a, __int128 b) {
    __int128 t;
    asm { por t, a, b }
    return t;
}
static inline int k4750eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline long KEq_4750(__int128 b, __int128 a, __int128 m)
{
    __int128 t, r;
    asm {
        pand t, m, b
        pand r, m, a
        pceqw r, r, t
        ppach r, r, r
    }
    return r;
}
/* pand with the operands in the other order (retail's register order for the LOD key mask) */
static inline __int128 k4750andr(__int128 a, __int128 b) {
    __int128 t;
    asm { pand t, b, a }
    return t;
}
static inline void Clear_4750(Rec_4750* r) {
    r->p = 0;
    r->h = 0;
    r->b6 = 0;
    r->b7 = 0;
    r->f8 = 0;
    r->fC = 0;
}

void Monster_LoadAPart(Cache_4750* c, __int128 key, Hog_4750* hog)
{
    char buf[32];
    char t[16];
    unsigned int i;
    int slot;
    int queued;
    int lod;
    i = 0;
    slot = 0;
    queued = 0;
    for (i = 0; i < c->count; i++) {
        if (k4750eq(k4750and(c->mask, c->keys[i]), k4750and(c->mask, key))) {
            c->h210[i]++;
            return;
        }
    }
    if (c->count < 0x300) {
        slot = c->count;
        c->count++;
    } else {
        int j;
        /* free-slot scan whose result is never used (kept: retail has the loop) */
        for (j = c->fC8; j < 0x300; j++) {
            if ((int)c->keys[j] == 0) break;
        }
    }
    /* the blank part key needs no mesh */
    if (KEq_4750(g_AgentPartCache, key, D_0055DE00) == -1) {
        Clear_4750(&c->recs[slot][0]);
        Clear_4750(&c->recs[slot][1]);
        return;
    }
    for (lod = 0; lod < 2; lod++) {
        key = k4750andr(key, c->mask);
        key = k4750or(D_00493A70[lod], key);
        sprintf(buf, D_004BE850, &key);
        cFileMan_EncodeFilename_charP_cHogFileR_bool(hog, buf, hog->x98, 1);
        if (!(unsigned char)cFileMan_Open(hog)) {
            int size;
            c->keys[slot] = key;
            size = cFileMan_GetSize(hog);
            c->recs[slot][lod].p = 0;
            c->recs[slot][lod].h = slot;
            c->recs[slot][lod].b6 = lod;
            c->recs[slot][lod].b7 = 0;
            c->recs[slot][lod].f8 = 0;
            c->recs[slot][lod].fC = size;
            cFileStreamMan_StreamRequest(GetFileStreamMan(), hog, (void*)Parts_PartStreamReturn, &c->recs[slot][lod], 0, 1, 1);
            queued++;
        } else {
            c->keys[slot] = key;
            if (lod == 0) {
                Clear_4750(&c->recs[slot][lod]);
                break;
            }
            if (c->recs[slot][lod - 1].p) {
                c->recs[slot][lod].p = c->recs[slot][lod - 1].p;
                c->recs[slot][lod].h = c->recs[slot][lod - 1].h;
                c->recs[slot][lod].b6 = c->recs[slot][lod - 1].b6;
                c->recs[slot][lod].b7 = c->recs[slot][lod - 1].b7;
                c->recs[slot][lod].f8 = c->recs[slot][lod - 1].f8;
                c->recs[slot][lod].fC = c->recs[slot][lod - 1].fC;
            } else {
                c->recs[slot][lod].p = 0;
                c->recs[slot][lod].h = 0;
                c->recs[slot][lod].b6 = 0;
                c->recs[slot][lod].b7 = 0;
                c->recs[slot][lod].f8 = 0;
                c->recs[slot][lod].fC = 0;
            }
        }
        if (lod == 0) c->h210[slot] = 1;
    }
    /* dead copy of the "_MAKE_BLA_NONE" key into a local; retail keeps the store */
    if (!queued) *(Key_4750*)t = D_00493AE0;
}
static inline void merge_flush_func_00404750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00404750 */

/* merge_units: begin func_00404AA0 */
#pragma push /* merge_units */
typedef struct {
    int p;
    unsigned short h;
    unsigned char b6;
    unsigned char b7;
    int f8;
    int fC;
} Rec_404AA0;
typedef struct {
    char pad0[0x10];
    __int128 m10;
    char pad20[0x60 - 0x20];
    __int128 mask;
    char pad70[0xC0 - 0x70];
    unsigned int count;
    int pad0C4;
    unsigned int fC8;
    char pad0CC[0x210 - 0xCC];
    short h210[1];
    char pad212[0x2C10 - 0x212];
    __int128 keys[0x300];
    Rec_404AA0 recs[1][2];
} Cache_404AA0;
typedef struct { int pad; int n; } Lst_404AA0;
typedef struct { char pad[0x148]; Lst_404AA0* list; } Npc_404AA0;
typedef struct {
    int n;
    char keys[24][16];
    void* vals[1];
} Reg_404AA0;
extern Reg_404AA0 D_00571300;
extern char D_004BE858[];
#if 0 /* merge_units */
int cHogFile_GetBlockSize(Npc_404AA0* npc, int i);
#endif /* merge_units */
#define cHogFile_GetBlockSize(a0, a1) (cHogFile_GetBlockSize((Npc_S *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
char* cHogFile_GetBlockName(Npc_404AA0* npc, int i);
#endif /* merge_units */
#define cHogFile_GetBlockName(a0, a1) (cHogFile_GetBlockName((Npc_S *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void* cHogFile_GetBlock_int(Npc_404AA0* npc, int i);
#endif /* merge_units */
#define cHogFile_GetBlock_int(a0, a1) ((void *)cHogFile_GetBlock_int((Npc_S *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int strcmp(char* a, char* b);
#endif /* merge_units */
#define strcmp(a0, a1) (strcmp((const void *)(a0), (const void *)(a1))) /* merge_units */

#if 0 /* merge_units */
unsigned int Monster_AddMonsterPart(Cache_404AA0* c, __int128 key, int k);
#endif /* merge_units */
#define Monster_AddMonsterPart(a0, a1, a2) (Monster_AddMonsterPart((Cache_S *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void Parts_SetManData(Rec_404AA0* r, void* pkt, int a, long long slot, long long k, long long z);
#endif /* merge_units */
#define Parts_SetManData(a0, a1, a2, a3, a4, a5) (Parts_SetManData((Rec_S *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */


static inline __int128 k4AA0and(__int128 a, __int128 b) {
    __int128 t;
    asm { pand t, a, b }
    return t;
}
static inline int k4AA0eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}

static inline int k4AA0eq2(__int128 b, __int128 a) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}

void Monster_LoadParts(Cache_404AA0* c, Npc_404AA0* npc)
{
    char* name;
    unsigned int j;
    int slot;
    int a;
    int n;
    char* ext;
    int i;
    int lod;
    j = c->count;
    n = npc->list->n;
    for (i = 0; i < n; i++) {
        union { __int128 q; char s[16]; } key;
        a = cHogFile_GetBlockSize(npc, i);
        name = cHogFile_GetBlockName(npc, i);
        strCpyPad(key.s, 15, name);
        ext = strrchr(name, '.');
        if (!ext) ext = name;
        if (strcmp(ext, D_004BE830) == 0) {
            union { __int128 q; char s[16]; } k2;
            __int128 o;
            __int128 m;
            k2.q = key.q;
            lod = *(k2.s + 14) - '0';
            if (lod >= 2 || lod < 0) lod = 0;
            slot = Monster_AddMonsterPart(c, key.q, lod);
            Parts_SetManData(&c->recs[slot][lod], cHogFile_GetBlock_int(npc, i), a, slot, lod, 0);
            c->h210[slot] = 0;
            m = c->mask;
            o = c->m10;
            if (k4AA0eq(k4AA0and(m, c->keys[slot]), k4AA0and(m, o))) {
                c->recs[slot][lod].h = 0;
                c->recs[slot][lod].b7 = 0;
            }
        } else if (strcmp(ext, D_004BE858) == 0 && a) {
            D_00571300.vals[D_00571300.n] = cHogFile_GetBlock_int(npc, i);
            strCpyPad(D_00571300.keys[D_00571300.n], 15, name);
            D_00571300.n++;
        }
    }
    for (; j < c->count; j++) {
        if (c->recs[j][1].f8 == 0) {
            c->recs[j][1].p = c->recs[j][0].p;
            c->recs[j][1].h = c->recs[j][0].h;
            c->recs[j][1].b6 = c->recs[j][0].b6;
            c->recs[j][1].b7 = c->recs[j][0].b7;
            c->recs[j][1].f8 = c->recs[j][0].f8;
            c->recs[j][1].fC = c->recs[j][0].fC;
        }
        if (c->recs[j][0].f8 == 0) {
            c->recs[j][0].p = c->recs[j][1].p;
            c->recs[j][0].h = c->recs[j][1].h;
            c->recs[j][0].b6 = c->recs[j][1].b6;
            c->recs[j][0].b7 = c->recs[j][1].b7;
            c->recs[j][0].f8 = c->recs[j][1].f8;
            c->recs[j][0].fC = c->recs[j][1].fC;
        }
    }
    c->fC8 = c->count;
}
#undef cHogFile_GetBlockSize /* merge_units */
#undef cHogFile_GetBlockName /* merge_units */
#undef cHogFile_GetBlock_int /* merge_units */
#undef strcmp /* merge_units */
#undef Monster_AddMonsterPart /* merge_units */
#undef Parts_SetManData /* merge_units */
static inline void merge_flush_func_00404AA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00404AA0 */
