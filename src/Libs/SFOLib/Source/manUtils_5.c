/*
 * Libs/SFOLib/Source/manUtils: 8 files, 00404060-00404FD0
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
#if 0 /* merge_units */
int cHogFile_GetBlockSize(Npc_S* npc, int i);
#endif /* merge_units */
int cHogFile_GetBlockSize(void*, int); /* merge_units */
#define cHogFile_GetBlockSize(a0, a1) (cHogFile_GetBlockSize((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
char* cHogFile_GetBlockName(Npc_S* npc, int i);
#endif /* merge_units */
char* cHogFile_GetBlockName(void*, int); /* merge_units */
#define cHogFile_GetBlockName(a0, a1) (cHogFile_GetBlockName((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
__int128* cHogFile_GetBlock_int(Npc_S* npc, int i);
#endif /* merge_units */
void* cHogFile_GetBlock_int(void*, int); /* merge_units */
#define cHogFile_GetBlock_int(a0, a1) ((__int128 *)cHogFile_GetBlock_int((void *)(a0), (a1))) /* merge_units */

void strCpyPad(char* dst, int n, char* src);
char* strrchr(char* s, int c);
unsigned int Monster_AddMonsterPart(Cache_S* c, __int128 key, int k);
#if 0 /* merge_units */
void Parts_SetManData(Rec_S* r, void* pkt, int a, long long slot, long long k, long long z);
#endif /* merge_units */
void Parts_SetManData(void*, void*, int, long long, long long, long long); /* merge_units */
#define Parts_SetManData(a0, a1, a2, a3, a4, a5) (Parts_SetManData((void *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */


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
#undef cHogFile_GetBlockSize /* merge_units */
#undef cHogFile_GetBlockName /* merge_units */
#undef cHogFile_GetBlock_int /* merge_units */
#undef Parts_SetManData /* merge_units */
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
#if 0 /* merge_units */
int cFileMan_Open(Hog_4750* h);
#endif /* merge_units */
int cFileMan_Open(void*); /* merge_units */
#define cFileMan_Open(a0) (cFileMan_Open((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cFileMan_GetSize(Hog_4750* h);
#endif /* merge_units */
int cFileMan_GetSize(void*); /* merge_units */
#define cFileMan_GetSize(a0) (cFileMan_GetSize((void *)(a0))) /* merge_units */

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
#undef cFileMan_Open /* merge_units */
#undef cFileMan_GetSize /* merge_units */
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
#define cHogFile_GetBlockSize(a0, a1) (cHogFile_GetBlockSize((void *)(a0), (a1))) /* merge_units */



#if 0 /* merge_units */
char* cHogFile_GetBlockName(Npc_404AA0* npc, int i);
#endif /* merge_units */
#define cHogFile_GetBlockName(a0, a1) (cHogFile_GetBlockName((void *)(a0), (a1))) /* merge_units */



#if 0 /* merge_units */
void* cHogFile_GetBlock_int(Npc_404AA0* npc, int i);
#endif /* merge_units */
#define cHogFile_GetBlock_int(a0, a1) (cHogFile_GetBlock_int((void *)(a0), (a1))) /* merge_units */



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
#define Parts_SetManData(a0, a1, a2, a3, a4, a5) (Parts_SetManData((void *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */




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

/* merge_units: begin func_00404D90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Monster_FreePart: drop one reference to cached part i; on the last release of a part above the
 * static range, release its two loaded streams ("<name><suffix>1", "<name><suffix>0"), clear their
 * slots and the part's key. */

struct Res { char c[0xA0]; };
struct Slot { int a; int b; int stream; int d; };
struct Cache {
    char pad0[0xC8];
    unsigned int nStatic;
    char padCC[0x210 - 0xCC];
    short refs[0x1500];
    __int128 names[0x300];
    Slot slots[0x100][2];
};

extern "C" {
extern __int128 D_005716E0;
#if 0 /* merge_units */
void cFileMan_ctor_void(Res* r);
#endif /* merge_units */
void cFileMan_ctor_void(void*); /* merge_units */
#define cFileMan_ctor_void(a0) (cFileMan_ctor_void((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void Libc_Strcpy(char* d, const char* s);
#endif /* merge_units */
char* Libc_Strcpy(void* dst, const void* src); /* merge_units */
#define Libc_Strcpy(a0, a1) ((void)Libc_Strcpy((void *)(a0), (const void *)(a1))) /* merge_units */

void Libc_Strcat(char* d, const char* s);
#if 0 /* merge_units */
void cFileMan_EncodeFilename_charP_cFileIOP_bool(Res* r, char* name, int a, int b);
#endif /* merge_units */
void cFileMan_EncodeFilename_charP_cFileIOP_bool(void*, void*, int, int); /* merge_units */
#define cFileMan_EncodeFilename_charP_cFileIOP_bool(a0, a1, a2, a3) (cFileMan_EncodeFilename_charP_cFileIOP_bool((void *)(a0), (void *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void* GetFileStreamMan(void);
#endif /* merge_units */
#define GetFileStreamMan() ((void *)GetFileStreamMan()) /* merge_units */


#if 0 /* merge_units */
void cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(void* l, Res* r, int f);
#endif /* merge_units */
void cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(void*, void*, int); /* merge_units */
#define cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(a0, a1, a2) (cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode((a0), (void *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cFileMan_dtor(Res* r, int flags);
#endif /* merge_units */
void cFileMan_dtor(void* f, int del); /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((void *)(a0), (a1))) /* merge_units */

void Monster_FreePart(Cache* c, unsigned int i);
}

/* quad/byte clear loop with addi counters and hand-placed nops (retail shape); no C equivalent */
static inline void MemClear(void* d0, int n0)
{
    int n = n0;
    void* dst = d0;
    asm volatile {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v1, n, 0xF
        or $a0, $a0, $v1
        nop
        bgtz $a0, bytes
        srl $v1, n, 4
        nop
        blez $v1, bytes
        nop
        nop
    quads:
        addi $v1, $v1, -1
        sq $zero, 0(dst)
        bgtz $v1, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}


void Monster_FreePart(Cache* c, unsigned int i)
{
    c->refs[i]--;
    if (i < c->nStatic) return;
    if (c->refs[i]) return;
    {
        Res r;
        char name[0x20];
        int k;
        cFileMan_ctor_void(&r);
        Libc_Strcpy(name, (char*)&c->names[i]);
        Libc_Strcat(name, D_004BE830);
        for (k = 1; k > 0; k--) {
            if (c->slots[i][k].stream != c->slots[i][k - 1].stream && c->slots[i][k].stream) {
                name[0xE] = '0' + k;
                cFileMan_EncodeFilename_charP_cFileIOP_bool(&r, name, 0, 0);
                cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), &r, 1);
            }
            MemClear(&c->slots[i][k], 16);
        }
        if (c->slots[i][0].stream) {
            name[0xE] = '0';
            cFileMan_EncodeFilename_charP_cFileIOP_bool(&r, name, 0, 0);
            cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), &r, 1);
        }
        MemClear(&c->slots[i][0], 16);
        c->names[i] = D_005716E0;
        cFileMan_dtor(&r, -1);
    }
}
#undef cFileMan_ctor_void /* merge_units */
#undef Libc_Strcpy /* merge_units */
#undef cFileMan_EncodeFilename_charP_cFileIOP_bool /* merge_units */
#undef GetFileStreamMan /* merge_units */
#undef cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode /* merge_units */
#undef cFileMan_dtor /* merge_units */
static inline void merge_flush_func_00404D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00404D90 */

/* merge_units: begin func_00404FD0 */
#pragma push /* merge_units */
#include "canonical_key_copy.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"

#if 0 /* merge_units */
int sprintf(void *, const void *, ...);
#endif /* merge_units */


#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
typedef struct { int f0; int f4; int h; int fC; } MC_Lod;
typedef struct { short a; short b; } MC_Tex;
typedef struct { __int128 x[11]; } MC_File;
typedef struct {
    char pad0[0xC0];
    unsigned int meshCount;
    int meshC4;
    unsigned int meshLoaded;
    unsigned int texCount;
    int texD0;
    void* bufD4;
    void* bufD8;
    char padDC[0xE4 - 0xDC];
    int hasE8;
    void* bufE8;
    char padEC[0x1410 - 0xEC];
    MC_Tex tex[0x600];
    char names[0x300][16];
    MC_Lod lods[0x300][2];
    char pad1[0x13410 - 0xBC10];
    MC_File sub0;
} MC_State;
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void EnableIntc(int id);
extern int g_TextureMgr;
#if 0 /* merge_units */
extern int D_00571300;
#endif /* merge_units */
#define D_00571300 (*(int*)&D_00571300) /* merge_units */

#if 0 /* merge_units */
void Libc_Strcat(char* d, char* s);
#endif /* merge_units */
#define Libc_Strcat(a0, a1) (Libc_Strcat((a0), (const char *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cFileMan_ctor_void(MC_File* f);
#endif /* merge_units */
#define cFileMan_ctor_void(a0) (cFileMan_ctor_void((void *)(a0))) /* merge_units */

void cFileMan_dtor(void* f, int del);
#if 0 /* merge_units */
void cFileMan_EncodeFilename_charP_cFileIOP_bool(MC_File* f, char* name, int a, int b);
#endif /* merge_units */
#define cFileMan_EncodeFilename_charP_cFileIOP_bool(a0, a1, a2, a3) (cFileMan_EncodeFilename_charP_cFileIOP_bool((void *)(a0), (void *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void* GetFileStreamMan(void);
#endif /* merge_units */
#define GetFileStreamMan() ((void *)GetFileStreamMan()) /* merge_units */

#if 0 /* merge_units */
void cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(void* m, MC_File* f, int a);
#endif /* merge_units */
#define cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(a0, a1, a2) (cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode((a0), (void *)(a1), (a2))) /* merge_units */

void cTexMan_RemoveTexture(int lib, int h, int keep);
void operator_delete(void* p);
MC_State* Monster_dtor(MC_State* s, short del);
}
/* Mesh/texture cache destructor: releases cached LOD meshes and textures, frees buffers. */
MC_State* Monster_dtor(MC_State* s, short del)
{
    MC_File fm;
    char name[32];
    unsigned int i;
    int j;
    void* p;
    if (s) {
        cFileMan_ctor_void(&fm);
        for (i = s->meshLoaded; i < s->meshCount; i++) {
            Libc_Strcpy(name, s->names[i]);
            Libc_Strcat(name, D_004BE830);
            for (j = 1; j > 0; j--) {
                MC_Lod* l = (MC_Lod*)((char*)s->lods + i * 32 + j * 16);
                int h = l->h;
                if (h != l[-1].h && h != 0) {
                    name[14] = j + '0';
                    cFileMan_EncodeFilename_charP_cFileIOP_bool(&fm, name, 0, 0);
                    cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), &fm, 1);
                }
            }
            if (s->lods[i][0].h) {
                name[14] = '0';
                cFileMan_EncodeFilename_charP_cFileIOP_bool(&fm, name, 0, 0);
                cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), &fm, 1);
            }
        }
        ckc_qzero(s->names, 0x300);
        ckc_qzero(s->lods, 0x600);
        s->meshCount = 0;
        s->meshC4 = 0;
        s->meshLoaded = 0;
        for (i = 0; i < s->texCount; i++) {
            {
                MC_Tex* t = (MC_Tex*)((char*)s->tex + i * 4);
                int b = t->b;
                if (b != t->a)
                    cTexMan_RemoveTexture(g_TextureMgr, b, 0);
            }
            {
                /* loading the library first orders lui before the index add */
                int lib = g_TextureMgr;
                cTexMan_RemoveTexture(lib, s->tex[i].a, 0);
            }
        }
        s->texCount = 0;
        s->texD0 = 0;
        p = s->bufD4;
        if (p) {
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            cMemMan_Deallocate(0, p, D_004BE7F0, 0x52C);
            if (g_ProfileLockEnabled) EnableIntc(9);
            g_ProfileLockDepth--;
            p = s->bufD8;
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            cMemMan_Deallocate(0, p, D_004BE7F0, 0x52D);
            if (g_ProfileLockEnabled) EnableIntc(9);
            g_ProfileLockDepth--;
            s->bufD4 = 0;
            s->bufD8 = 0;
        }
        if (s->hasE8) {
            p = s->bufE8;
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            cMemMan_Deallocate(0, p, D_004BE7F0, 0x532);
            if (g_ProfileLockEnabled) EnableIntc(9);
            g_ProfileLockDepth--;
        }
        s->bufE8 = 0;
        s->hasE8 = 0;
        D_00571300 = 1;
        cFileMan_dtor(&fm, -1);
        cFileMan_dtor((char*)s + 0x134AC, -1);
        cFileMan_dtor((char*)s + 0x13410, -1);
        if (del > 0)
            operator_delete(s);
    }
    return s;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00404FD0(void) {}
#undef D_00571300 /* merge_units */
#undef Libc_Strcat /* merge_units */
#undef cFileMan_ctor_void /* merge_units */
#undef cFileMan_EncodeFilename_charP_cFileIOP_bool /* merge_units */
#undef GetFileStreamMan /* merge_units */
#undef cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00404FD0 */

/* merge_units: begin func_004053B0 */
#pragma push /* merge_units */
/* 0x004053B0 Monster_MonsterInit (mw38). Quad copies use lq/sq GCC asm; operator= decl order
   reproduces the dead duplicate addiu pair. Empty asm barrier (no code) keeps axis on the stack. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V { float x, y, z, w; };
struct M;
extern "C" void cMatrix_ctor_void(M*);
extern "C" void cMatrix_SetWithAxisAngle(M*, float, float, float, float);
struct M {
    union { float m[4][4]; __int128 q[4]; };
    M() {}
    M& operator=(const M& o) { void* xx = (void*)&o; xx = this; __int128 t0; __int128 t1; M* d = this; const M* s = &o; asm volatile("lq %0,0(%2)\n\tlq %1,16(%2)\n\tsq %0,0(%3)\n\tlq %0,32(%2)\n\tsq %1,16(%3)\n\tlq %1,48(%2)\n\tsq %0,32(%3)\n\tsq %1,48(%3)" : "=&r"(t0), "=&r"(t1) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct File {
    int x0;
    char name[0x9C];
};
extern "C" {
#if 0 /* merge_units */
void cFileMan_ctor_void(File* f);
#endif /* merge_units */
#define cFileMan_ctor_void(a0) (cFileMan_ctor_void((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
void cFileMan_EncodeFilename_charP_cFileIOP_bool(File* f, const char* path, int a, int b);
#endif /* merge_units */
#define cFileMan_EncodeFilename_charP_cFileIOP_bool(a0, a1, a2, a3) (cFileMan_EncodeFilename_charP_cFileIOP_bool((void *)(a0), (void *)(a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
int cFileMan_Open(File* f);
#endif /* merge_units */
#define cFileMan_Open(a0) (cFileMan_Open((void *)(a0))) /* merge_units */

void cFileMan_Close(File* f);
#if 0 /* merge_units */
void cFileMan_dtor(File* f, int flags);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((void *)(a0), (a1))) /* merge_units */


}
struct Man {
    char pad0[0x160];
    M m160;
    char pad1A0[0x40];
    float m1E0[3][4];
};
extern "C" {
void Monster_ReadSortTable(Man*, const char*);
void Monster_LoadLights(Man*, const char*, void*, M*);
void cMatrix_Rotate(M*, M*);
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
M* cMatrix_Transpose(M* m);
#if 0 /* merge_units */
int cFileMan_GetSize(File*);
#endif /* merge_units */
#define cFileMan_GetSize(a0) (cFileMan_GetSize((void *)(a0))) /* merge_units */

char* cFileMan_Read_void(File*);
void SKL_ConvertSKL(void*, char*, int);
extern const char D_004BE860[];
extern const char D_004BE880[];
extern const char D_004BE8A0[];
extern const char D_004BE8C0[];
extern const char D_004BE8E0[];
extern const char D_004BE770[];
extern char D_00493A60;
extern char D_0055D510[];
extern char D_0055D950[];
}
static inline void RotMul(M* a, const V& ax, float ang) { M rot; cMatrix_ctor_void(&rot); cMatrix_SetWithAxisAngle(&rot, ax.x, ax.y, ax.z, ang); cMatrix_Rotate(a, &rot); }
static inline M* TransCopy(M* d, const M* s) { M tmp; return cMatrix_ctor_cMatrixR(d, cMatrix_Transpose(cMatrix_ctor_cMatrixR(&tmp, s))); }
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
extern "C" void Monster_MonsterInit(Man* self)
{
    M a;
    V axis;
    M b;
    int i, j;
    Monster_ReadSortTable(self, D_004BE860);
    Monster_LoadLights(self, D_004BE880, (char*)self + 0x120, &a);
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    axis.w = 0.0f;
    asm volatile("" : : "r"(&axis) : "memory"); /* barrier: no code */
    RotMul(&a, axis, 3.1415927f);
    {
        M* d = &self->m160;
        __int128 t0, t1;
        M* s = &a;
        asm volatile("lq %0,0(%2)\n\tlq %1,16(%2)\n\tsq %0,0(%3)\n\tlq %0,32(%2)\n\tsq %1,16(%3)\n\tlq %1,48(%2)\n\tsq %0,32(%3)\n\tsq %1,48(%3)" : "=&r"(t0), "=&r"(t1) : "r"(s), "r"(d) : "memory");
    }
    Monster_LoadLights(self, D_004BE8A0, (char*)self + 0x1A0, &a);
    TransCopy(&b, &a);
    a = b;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            self->m1E0[i][j] = a.m[i][j];
        }
    }
    D_00493A60 = 0;
    {
        File f;
        cFileMan_ctor_void(&f);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&f, D_004BE8C0, 0, 0);
        if ((unsigned char)cFileMan_Open(&f)) {
            char buf[0x80];
            sprintf(buf, D_004BE770, f.name);
            cFileMan_dtor(&f, -1);
            goto next1;
        }
        int size = cFileMan_GetSize(&f);
        SKL_ConvertSKL(D_0055D510, cFileMan_Read_void(&f), size);
        cFileMan_Close(&f);
        cFileMan_dtor(&f, -1);
    }
next1:;
    {
        File f;
        cFileMan_ctor_void(&f);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&f, D_004BE8E0, 0, 0);
        if ((unsigned char)cFileMan_Open(&f)) {
            char buf[0x80];
            sprintf(buf, D_004BE770, f.name);
            cFileMan_dtor(&f, -1);
            return;
        }
        int size = cFileMan_GetSize(&f);
        SKL_ConvertSKL(D_0055D950, cFileMan_Read_void(&f), size);
        cFileMan_Close(&f);
        cFileMan_dtor(&f, -1);
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004053B0(void) {}
#undef cFileMan_ctor_void /* merge_units */
#undef cFileMan_EncodeFilename_charP_cFileIOP_bool /* merge_units */
#undef cFileMan_Open /* merge_units */
#undef cFileMan_dtor /* merge_units */
#undef cFileMan_GetSize /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004053B0 */
