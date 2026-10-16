#include "types.h"
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
extern char D_004BE830[];
extern char D_004BE858[];
int Hog_GetEntrySize(Npc_404AA0* npc, int i);
char* Archive_GetMemberName(Npc_404AA0* npc, int i);
void* func_0036D4E0(Npc_404AA0* npc, int i);
void Appearance_RegistryKey(char* dst, int n, char* src);
char* strrchr(char* s, int c);
int strcmp(char* a, char* b);
unsigned int TexCache_FindOrAddSlot(Cache_404AA0* c, __int128 key, int k);
void Skm_LoadPacket(Rec_404AA0* r, void* pkt, int a, long long slot, long long k, long long z);

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

void MeshCache_RegisterNpcSkm(Cache_404AA0* c, Npc_404AA0* npc)
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
        a = Hog_GetEntrySize(npc, i);
        name = Archive_GetMemberName(npc, i);
        Appearance_RegistryKey(key.s, 15, name);
        ext = strrchr(name, '.');
        if (!ext) ext = name;
        if (strcmp(ext, D_004BE830) == 0) {
            union { __int128 q; char s[16]; } k2;
            __int128 o;
            __int128 m;
            k2.q = key.q;
            lod = *(k2.s + 14) - '0';
            if (lod >= 2 || lod < 0) lod = 0;
            slot = TexCache_FindOrAddSlot(c, key.q, lod);
            Skm_LoadPacket(&c->recs[slot][lod], func_0036D4E0(npc, i), a, slot, lod, 0);
            c->h210[slot] = 0;
            m = c->mask;
            o = c->m10;
            if (k4AA0eq(k4AA0and(m, c->keys[slot]), k4AA0and(m, o))) {
                c->recs[slot][lod].h = 0;
                c->recs[slot][lod].b7 = 0;
            }
        } else if (strcmp(ext, D_004BE858) == 0 && a) {
            D_00571300.vals[D_00571300.n] = func_0036D4E0(npc, i);
            Appearance_RegistryKey(D_00571300.keys[D_00571300.n], 15, name);
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
