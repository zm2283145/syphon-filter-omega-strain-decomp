/*
 * main/manUtils: range (3 files, 00404060-004046F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
int strcmp(const void *, const void *);

/* merge_units: begin func_00404060 */
#pragma push /* merge_units */
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
extern char D_00493AF0[24][7];
extern int D_005712F0[2];
extern __int128* D_005712F8[2];
extern __int128* D_005714F0[2][2];
extern unsigned char D_00571500[2][2];
extern unsigned char D_00571510[2][2][24];
int Hog_GetEntrySize(Npc_S* npc, int i);
char* Archive_GetMemberName(Npc_S* npc, int i);
__int128* func_0036D4E0(Npc_S* npc, int i);
void Appearance_RegistryKey(char* dst, int n, char* src);
char* strrchr(char* s, int c);
unsigned int TexCache_FindOrAddSlot(Cache_S* c, __int128 key, int k);
void Skm_LoadPacket(Rec_S* r, void* pkt, int a, long long slot, long long k, long long z);

typedef union { __int128 q; char s[16]; } KU;

void Skf_Register(Cache_S* c, Npc_S* npc)
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
            Mem_Free(0, p, D_004BE7F0, 0x7D1);
        }
        p = c->bufD8;
        {
            AllocGuard g;
            Mem_Free(0, p, D_004BE7F0, 0x7D2);
        }
        c->bufD4 = 0;
        c->bufD8 = 0;
    }
    n = npc->list->n;
    for (i = 0; i < n; i++) {
        KU key;
        KU k2;
        char* ks = key.s;
        a = Hog_GetEntrySize(npc, i);
        if (!a) continue;
        name = Archive_GetMemberName(npc, i);
        pkt = func_0036D4E0(npc, i);
        Appearance_RegistryKey(ks, 15, name);
        ext = strrchr(name, '.');
        if (!ext) ext = name;
        if (strcmp(ext, D_004BE830) == 0 || strcmp(ext, D_004BE838) == 0) {
            k2.q = key.q;
            lod = *(k2.s + 14) - '0';
            if (lod >= 2 || lod < 0) lod = 0;
            slot = TexCache_FindOrAddSlot(c, key.q, lod);
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
            Skm_LoadPacket(&c->recs[slot][lod], pkt, a, slot, lod, z);
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
                nm = D_00493AF0[0];
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
unsigned int func_00404690(K690* s, __int128 key) {
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
unsigned int MeshCache_FindSlot(K6F0* s, __int128 key) {
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
