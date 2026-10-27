/*
 * main/AgentData: range (7 files, 00334790-00335660)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
void *memcpy();
void *memset(void *, int, int);
int sprintf(void *, const void *, ...);
int strlen(const char *);

/* merge_units: begin func_00334790 */
#pragma push /* merge_units */
/* cAgentData_Load 00334790 - mw38 MATCH (c62lg) */
#pragma cplusplus on
struct Cfg4110 { char pad[0x59D]; unsigned char b59D; unsigned char b59E; char pad59F[0x5A8-0x59F]; int i5A8; };
struct Mc4110 { Cfg4110 *cfg; unsigned char busy; };
struct Ent4110 { int a, b, c; char s1[0x20]; char s2[0x80]; };
struct Rec4110 { int v[8]; };
struct A4110 {
    char pad00[4];
    int i4;
    char stats[0x38];
    char pad40[0x84 - 0x40];
    int objectiveBits[8];
    char padA4[0xC8 - 0xA4];
    int nLevels;
    Rec4110 *recs;
    char padD0[0xD8 - 0xD0];
    int iD8;
    char bufDC[0x7D0];
    char name8AC[0x10];
    char b8BC[0x10];
    char b8CC[0x10];
    char b8DC[0x40];
    char b91C[0x40];
    char b95C[0x40];
    int i99C;
    int i9A0;
    void *p9A4;
    char b9A8[0x100];
    char padAA8[0xB68 - 0xAA8];
    unsigned char bB68;
    char padB69[0xB70 - 0xB69];
    unsigned char bB70;
    char padB71;
    unsigned char bB72;
    unsigned char bB73;
};
extern "C" {
extern char *D_0052FDF0;
extern int D_0052AFD0[];
extern int g_TimerAccum;
extern void *D_004FFC04;
extern Mc4110 g_MemCard;
extern int D_0052FE80;
extern Ent4110 D_0052FE90[];
extern char *D_004926D0;
extern char D_005329A0[];
extern char D_004B92B0[];
void FrontEnd_FlushMessages(void *p);
int cBitArray_224_NumChunks(void);
int AgentFile_EncodeName(const char *in, char *out, int digit, unsigned int max);
int cMemCard_SaveFile(Mc4110 *mc, char *name, void *buf, int size, int flag);
int cMemCard_LoadFile(Mc4110 *mc, char *name, void *buf, int size);
void cAgentData_Reset(void *self);
void cAgentData_SetBonusBits(void *self, int a, int b);
extern char D_0052FE00[];
extern int g_CardSlotId;
}
static inline bool Idle4110(Mc4110 *m) { return !m->busy; }
static inline void WInt4110(int v) { *(int *)D_0052FDF0 = v; D_0052FDF0 += 4; }
static inline void WBuf4110(const void *p, int n) { memcpy(D_0052FDF0, p, n); D_0052FDF0 += n; }
static inline bool Ready4110(Mc4110 *m) { return m->cfg->b59D && m->cfg->b59E; }
static inline int RInt4110(void) { int v = *(int *)D_0052FDF0; D_0052FDF0 += 4; return v; }
static inline void RBuf4110(void *p, int n) { memcpy(p, D_0052FDF0, n); D_0052FDF0 += n; }
static inline void RStr4110(char *dst) { int n = RInt4110(); memcpy(D_0052FE00, D_0052FDF0, n); D_0052FDF0 = (char *)((int *)D_0052FDF0 + ((unsigned int)(n + 3) >> 2)); Libc_Strcpy(dst, D_0052FE00); }
extern "C" int cAgentData_Load(A4110 *self, char *name, int digit)
{
    char tmp[0x80];
    Ent4110 blank;
    bool ok;
    int r;
    Mc4110 *mc;
    int cnt;
    int a;
    char *fn;
    int q;
    int d;
    Ent4110 *e;
    int n;
    int len;
    int sum;
    int y;
    int *end;
    char *buf;
    int j;
    char k;
    char step;
    int i;
    d = digit;
    if (name == 0) name = self->name8AC;
    if (d < 0) d = self->i4;
    if (AgentFile_EncodeName(name, D_005329A0, d, 0x20)) fn = D_005329A0;
    else fn = D_004B92B0;
    r = 1;
    cAgentData_Reset(self);
    mc = &g_MemCard;
    if (Idle4110(mc) && Ready4110(mc)) {
        D_0052FDF0 = (char *)D_0052AFD0;
        ok = cMemCard_LoadFile(mc, fn, D_0052FDF0, 0x4E20) != 0;
        if (ok) {
            g_CardSlotId = mc->cfg->i5A8;
            *(int *)self->pad00 = RInt4110();
            if (*(int *)self->pad00 >= 0xC) {
                D_0052FDF0 += 4;
                len = strlen(D_004926D0);
                y = 0;
                buf = (char *)D_0052AFD0;
                k = buf[4];
                step = buf[5];
                for (i = 8; i < 20000; i++) {
                    buf[i] ^= (char)(k + D_004926D0[y]);
                    y++;
                    if (y >= len) {
                        y = 0;
                        k += step;
                    }
                }
            }
            if (*(int *)self->pad00 >= 0xB) RBuf4110(self->stats, 0x38);
            else RBuf4110(self->stats, 0x1C);
            for (a = 0; a < cBitArray_224_NumChunks(); a++) self->objectiveBits[a] = RInt4110();
            RBuf4110(self->name8AC, 0x10);
            RBuf4110(self->b8CC, 0x10);
            RBuf4110(self->b8BC, 0x10);
            if (*(int *)self->pad00 >= 0x10) {
                RBuf4110(tmp, 0x40);
                Libc_Strcpy(self->b8DC, tmp);
                RBuf4110(tmp, 0x80);
                Libc_Strcpy(self->b91C, tmp);
                self->i99C = RInt4110();
                RBuf4110(tmp, 0x40);
                Libc_Strcpy(self->b95C, tmp);
                self->i9A0 = RInt4110();
            } else {
                RStr4110(self->b8DC);
                RStr4110(self->b91C);
                self->i99C = RInt4110();
                RStr4110(self->b95C);
                self->i9A0 = RInt4110();
            }
            if (*(int *)self->pad00 >= 4) RBuf4110(self->p9A4, 0x440);
            if (*(int *)self->pad00 >= 0xA) RBuf4110(self->b9A8, 0x100);
            if (*(int *)self->pad00 >= 6) self->iD8 = RInt4110();
            else self->iD8 = 0;
            if (*(int *)self->pad00 >= 5) RBuf4110(self->bufDC, 0x7D0);
            else memset(self->bufDC, 0, 0x7D0);
            if (*(int *)self->pad00 >= 8) {
                for (i = 0; i < self->nLevels; i++) RBuf4110(&self->recs[(unsigned int)i], 0x20);
            }
            if (*(int *)self->pad00 >= 0xD) {
                memcpy(&self->bB68, D_0052FDF0, 1);
                D_0052FDF0 += 4;
            }
            if (*(int *)self->pad00 >= 0xE) {
                cnt = RInt4110();
                if (cnt > 0x40) return 2;
                D_0052FE80 = cnt;
                for (q = 0, e = D_0052FE90; q < 0x40; q++, e++) {
                    if (q < cnt) RBuf4110(e, sizeof(Ent4110));
                    else RBuf4110(&blank, sizeof(Ent4110));
                }
            }
            if (*(int *)self->pad00 >= 0x11) {
                sum = 0;
                end = (int *)D_0052FDF0;
                n = end - D_0052AFD0;
                for (j = 0; j < n; j++) sum ^= (D_0052AFD0)[j];
                if (sum != RInt4110()) return 2;
            }
            self->i4 = digit;
            if (*(int *)self->pad00 >= 3) cAgentData_SetBonusBits(self, 0, 1);
            self->bB72 = 0;
            self->bB73 = 0;
            self->bB70 = 1;
            r = 0;
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00334790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00334790 */

/* merge_units: begin func_00335070 */
#pragma push /* merge_units */
typedef struct {
    char pad0[8];
    int v[(0xB00 - 8) / 4];
    unsigned char* flags;
} O_3351E0;
void cAgentData_UpdateRatings(O_3351E0* o, int force); /* gsynth: defined below */
typedef struct { char pad[0xB08]; unsigned int bits[1]; } A352C0;
void cAgentData_UnlockPrize(A352C0* self, int id); /* gsynth: defined below */
typedef struct { char p0[4]; int count; unsigned char* data; } B335350;
typedef struct { unsigned char state; char p1[3]; B335350 b; } P335350;
typedef struct { char p0[0x10]; int arg; } Q335350;
void cAgentData_UpdateAchievement(void* self, P335350* p, Q335350* q, int force); /* gsynth: defined below */
#pragma opt_strength_reduction off

typedef struct RangeDef070 {
    int key;
    int unk04;
    int start;
    int len;
    int value;
    int unk14;
} RangeDef070;

typedef struct RangeTable070 {
    int unk00;
    int count;
    RangeDef070* data;
    int unk0C;
} RangeTable070;

typedef struct RangeRec070 {
    char pad[0x14];
} RangeRec070;

typedef struct RangeRecVec070 {
    int unk00;
    int count;
    RangeRec070* data;
    int unk0C;
} RangeRecVec070;

typedef struct DosDef070 {
    const char* name;
    int unk04;
    int need;
    int id;
    char pad10[0x14];
} DosDef070;

typedef struct DosDefVec070 {
    int unk00;
    int count;
    DosDef070* data;
} DosDefVec070;

typedef struct Agent070 {
    char pad00[0xAA8];
    RangeRecVec070 recs[5];
    char padAF8[0xB50 - 0xAF8];
    DosDef070* dossier;
} Agent070;

extern RangeTable070 D_00532A70[5];
extern DosDefVec070 g_RankRows;
#if 0 /* merge_units */
extern void cAgentData_UpdateAchievement(Agent070* self, RangeRec070* rec, RangeDef070* def, int x);
#endif /* merge_units */
#define cAgentData_UpdateAchievement(a0, a1, a2, a3) (cAgentData_UpdateAchievement((void *)(a0), (void *)(a1), (void *)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cAgentData_UpdateRatings(Agent070* self, int x);
#endif /* merge_units */
#define cAgentData_UpdateRatings(a0, a1) (cAgentData_UpdateRatings((void *)(a0), (a1))) /* merge_units */

extern int cAgentData_GetClearancePoints(Agent070* self);
#if 0 /* merge_units */
extern void cAgentData_UnlockPrize(Agent070* self, int id);
#endif /* merge_units */
#define cAgentData_UnlockPrize(a0, a1) (cAgentData_UnlockPrize((void *)(a0), (a1))) /* merge_units */


void cAgentData_UpdateAchievements(Agent070* self, int x)
{
    int t;
    int pts;
    DosDefVec070* dv;
    int i;
    RangeRecVec070* rv;
    int j;
    Agent070* p;
    RangeTable070* tb;
    p = self;
    tb = D_00532A70;
    for (t = 0; t < 5; t++, p = (Agent070*)((char*)p + 16), tb++) {
        rv = &p->recs[0];
        for (j = 0; j < rv->count; j++) {
            cAgentData_UpdateAchievement(self, &rv->data[j], &tb->data[j], x);
        }
    }
    cAgentData_UpdateRatings(self, x);
    pts = cAgentData_GetClearancePoints(self);
    dv = &g_RankRows;
    for (i = 0; i < dv->count; i++) {
        if (pts >= dv->data[i].need) {
            cAgentData_UnlockPrize(self, dv->data[i].id);
            self->dossier = &dv->data[i];
        }
    }
}
#undef cAgentData_UpdateAchievement /* merge_units */
#undef cAgentData_UpdateRatings /* merge_units */
#undef cAgentData_UnlockPrize /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00335070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00335070 */

/* merge_units: begin func_003351E0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct {
    char pad0[8];
    unsigned char idx;
    char pad9[7];
    int need;
    int arg;
} E_3351E0;

extern int D_00532AD4;
extern E_3351E0* D_00532AD8;
#if 0 /* merge_units */
void cAgentData_UnlockPrize(O_3351E0* o, int arg);
#endif /* merge_units */
#define cAgentData_UnlockPrize(a0, a1) (cAgentData_UnlockPrize((void *)(a0), (a1))) /* merge_units */


void cAgentData_UpdateRatings(O_3351E0* o, int force)
{
    int i;
    for (i = 0; i < D_00532AD4; i++) {
        E_3351E0* e = &D_00532AD8[i];
        if (o->v[e->idx] >= e->need) {
            if (force) {
                o->flags[i] = 2;
            } else if (o->flags[i] == 0) {
                o->flags[i] = 1;
            }
            cAgentData_UnlockPrize(o, e->arg);
        }
    }
}
#undef cAgentData_UnlockPrize /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003351E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003351E0 */

/* merge_units: begin func_003352C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x80]; char name[1]; } W352C0;

extern void* g_WeaponDatabase;
extern W352C0* cWeaponDB_GetEntry(void* db, int id);
extern void cAgentData_UnlockWeapon(A352C0* self, const char* name);
void cAgentData_UnlockPrize(A352C0* self, int id)
{
    if (id > -1) {
        if (id < 10000) {
            cAgentData_UnlockWeapon(self, cWeaponDB_GetEntry(g_WeaponDatabase, id)->name);
        } else {
            int i = (unsigned char)(id - 10000);
            if (i > -1)
                self->bits[i / 32] |= 1 << (i & 31);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003352C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003352C0 */

/* merge_units: begin func_00335350 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cAgentData_UnlockPrize(void* self, int arg);
#endif /* merge_units */
#define cAgentData_UnlockPrize(a0, a1) (cAgentData_UnlockPrize((void *)(a0), (a1))) /* merge_units */

#pragma opt_strength_reduction off
/* Marks the part complete when every sub-step is done, then notifies. */
void cAgentData_UpdateAchievement(void* self, P335350* p, Q335350* q, int force)
{
    B335350* b;
unsigned char all;
int i;
    b = &p->b;
all = 1;
    for (i = 0; i < *(volatile int*)&b->count; i++) {
        if (b->data[i] != 2) { all = 0; break; }
    }
    if (all) {
        if (force) p->state = 2;
        else if (p->state == 0) p->state = 1;
        cAgentData_UnlockPrize(self, q->arg);
    }
}
#undef cAgentData_UnlockPrize /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00335350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00335350 */

/* merge_units: begin func_003353F0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E { void *name; int pad[5]; };
struct V { int a; int count; E *data; };
struct Item { char *text; void *name; char state; int a; int b; int c; int agent; };
struct IV { int a; int count; Item *data; };
extern "C" {
extern char D_00532990[];
extern char D_00532991[];
extern char D_00532992[];
extern char D_00499C71[];
extern char D_00532998[];
extern char D_004B92B8[];
extern char D_004B92C0[];
extern V D_005329F0;
E **std_vector_deleter_Record_data(V *v);
void *nGlobalization_GetStringTag(void *name);
int cAgentData_WildcardCompare(void *agent, char *a, void *name, int c);
unsigned char cAgentData_IsObjectiveComplete(void *agent, void *name);
void func_00299500(IV *v);
char *nGlobalization_GetString_charP(void *name);
int nGlobalization_GetStringIndex(int k);
int cAgentData_GetWpnIndex(int k);
void std_vector_imp_tRequirementInfo_insert(IV *v, Item *pos, int n, Item *val);
}
static inline bool Neq(E *a, E *b) { return !(a == b); }
extern "C" void cAgentData_GetLevelRequirements(void *agent, char *s, IV *out)
{
    int i;
    int len;
    char c;
    char *pat;
    void *name;
    E *it;
    E *end;
    if (s == 0 || out == 0) return;
    func_00299500(out);
    i = 0;
    len = strlen(s) - 1;
    D_00532990[0] = s[0];
    D_00532991[0] = s[1];
    D_00532992[0] = s[2];
    i += 3;
    c = s[len];
    if (D_00499C71[c] & 4) {
        D_00532990[i++] = c;
    }
    D_00532990[i] = 0;
    sprintf(D_00532998, D_004B92B8, D_00532990);
    pat = D_00532998;
    it = *std_vector_deleter_Record_data(&D_005329F0);
    end = *std_vector_deleter_Record_data(&D_005329F0) + D_005329F0.count;
    for (; Neq(it, end); it++) {
        name = nGlobalization_GetStringTag(it->name);
        if (cAgentData_WildcardCompare(agent, pat, name, '*') && !cAgentData_WildcardCompare(agent, D_004B92C0, name, '*')) {
            Item item;
            char st = cAgentData_IsObjectiveComplete(agent, name) ? 2 : 1;
            item.text = nGlobalization_GetString_charP(name);
            item.name = name;
            item.state = st;
            void* k = 0;
            item.agent = k ? cAgentData_GetWpnIndex(nGlobalization_GetStringIndex(0)) : -1;
            item.a = 0;
            item.b = 0;
            item.c = 0;
            std_vector_imp_tRequirementInfo_insert(out, &out->data[out->count], 1, &item);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003353F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003353F0 */

/* merge_units: begin func_00335660 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Stats { char pad[0x18]; int total; int done; };
extern "C" {
}
extern "C" void cAgentData_UpdateLevelObjectives(void *agent, char *s, Stats *st)
{
    int i;
    int len;
    char c;
    char *pat;
    E *it;
    E *end;
    st->total = 0;
    st->done = 0;
    i = 0;
    len = strlen(s) - 1;
    D_00532990[0] = s[0];
    D_00532991[0] = s[1];
    D_00532992[0] = s[2];
    i += 3;
    c = s[len];
    if (D_00499C71[c] & 4) {
        D_00532990[i++] = c;
    }
    D_00532990[i] = 0;
    sprintf(D_00532998, D_004B92B8, D_00532990);
    pat = D_00532998;
    it = *std_vector_deleter_Record_data(&D_005329F0);
    end = *std_vector_deleter_Record_data(&D_005329F0) + D_005329F0.count;
    for (; Neq(it, end); it++) {
        void *name = nGlobalization_GetStringTag(it->name);
        if (cAgentData_WildcardCompare(agent, pat, name, '*') && !cAgentData_WildcardCompare(agent, D_004B92C0, name, '*')) {
            st->total++;
            if (cAgentData_IsObjectiveComplete(agent, name))
                st->done++;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00335660(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00335660 */
