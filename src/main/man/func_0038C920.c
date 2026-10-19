#include "types.h"

typedef struct {
    int id;
    unsigned short flags;
    unsigned char a;
    unsigned char b;
    int x;
    int y;
} PartRec;

typedef struct {
    __int128 a;
    __int128 b;
} NamePair;

typedef struct {
    char pad0[0x40];
    char appearance[0x10];
    __int128 name;                  /* 0x50 */
    char pad60[0x20];
    NamePair pairs[(0x1EC0 - 0x80) / 0x20];
    PartRec recs[2][32];            /* 0x1EC0 */
    short h22C0[0x40];              /* 0x22C0 */
    void* x2340[0x20];              /* 0x2340 */
    unsigned short nPairs;          /* 0x23C0 */
    char pad23C2[0x16];
    int x23D8;
    int x23DC;
    char pad23E0[8];
    int x23E8;
    int x23EC;
    float scale;                    /* 0x23F0 */
    char pad23F4[0x2BC0 - 0x23F4];
    unsigned char b2BC0;
    char pad2BC1;
    unsigned char shape;            /* 0x2BC2 */
    char pad2BC3[0x15];
    short h2BD8;
    unsigned char b2BDA;
    unsigned char b2BDB;
    char pad2BDC[0x30];
    unsigned char bodyKind;         /* 0x2C0C */
    char pad2C0D;
    signed char mouth;              /* 0x2C0E */
    signed char stra;               /* 0x2C0F */
} ActorModel;

typedef struct {
    char pad[0x5C10];
    PartRec recs[1][2];
} PartCache;

extern PartCache g_AgentPartCache;
extern int D_005712F0[];
extern __int128* D_005712F8[];
extern char D_004BC318[], D_004BC328[], D_004BC330[];
extern int MeshCache_FindSlot(PartCache* cache, __int128 name);
extern void func_00400140(PartRec* r, int a, int b, int c, int d);
extern int Appearance_GetBodyKind(void* a);
extern void Equip_SwapSlots(ActorModel* m, int a, int b);
extern int strcmp(const char* a, const char* b);
extern int Appearance_FindPairByType(void* a, const char* t);

static inline int Eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}

/* Model setup after the part list is filled: resolve each part pair in the agent part cache
 * (copy its two records or reset them), count pairs, body kind, equipment reset, look up
 * the shape index of the model name in the per-body-kind table, STRA_/MOUT_ pairs. */
void ActorModel_Setup(ActorModel* m)
{
    __int128* tbl;
    int n;
    int cnt;
    unsigned int k;
    m->b2BDB = 1;
    for (n = 0; m->pairs[n].a; n++) {
        int slot;
        if (m->h22C0[n] == -1) m->h22C0[n] = 0;
        slot = MeshCache_FindSlot(&g_AgentPartCache, m->pairs[n].a);
        if (slot == -1) {
            func_00400140(&m->recs[0][n], 0, 0, 0, 0);
            func_00400140(&m->recs[1][n], 0, 0, 1, 0);
        } else {
            int j;
            for (j = 0; j < 2; j++) {
                m->recs[j][n].id = g_AgentPartCache.recs[slot][j].id;
                m->recs[j][n].flags = g_AgentPartCache.recs[slot][j].flags;
                m->recs[j][n].a = g_AgentPartCache.recs[slot][j].a;
                m->recs[j][n].b = g_AgentPartCache.recs[slot][j].b;
                m->recs[j][n].x = g_AgentPartCache.recs[slot][j].x;
                m->recs[j][n].y = g_AgentPartCache.recs[slot][j].y;
            }
        }
    }
    m->nPairs = n;
    m->bodyKind = Appearance_GetBodyKind(m->appearance);
    for (n = 0; n < m->nPairs; n++) m->x2340[n] = 0;
    m->x23D8 = 0;
    m->x23DC = 0;
    m->x23E8 = 0;
    m->x23EC = 0;
    Equip_SwapSlots(m, 0, 0);
    m->h2BD8 = 255;
    m->b2BDA = 2;
    m->b2BC0 = 1;
    cnt = D_005712F0[m->bodyKind];
    tbl = D_005712F8[m->bodyKind];
    for (k = 0; k < cnt; k++) {
        if (Eq(tbl[k], m->name)) break;
    }
    if (k == cnt) {
        m->b2BC0 = 0;
        k = 0;
    }
    if (strcmp((char*)&m->name, D_004BC318) == 0) m->b2BC0 = 0;
    m->shape = k;
    m->scale = 1.0f;
    m->stra = Appearance_FindPairByType(m->appearance, D_004BC328);
    m->mouth = Appearance_FindPairByType(m->appearance, D_004BC330);
    if (m->mouth != -1) {
        m->recs[1][m->mouth].id = 0;
        m->recs[1][m->mouth].flags = 0;
    }
}
