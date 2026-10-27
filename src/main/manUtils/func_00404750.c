#include "types.h"
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
