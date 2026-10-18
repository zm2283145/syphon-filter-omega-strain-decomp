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
/* AgentData_Load 00334790 - mw38 MATCH (c62lg) */
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
extern int D_00533870;
extern void *D_004FFC04;
extern Mc4110 D_0055A830;
extern int D_0052FE80;
extern Ent4110 D_0052FE90[];
extern char *D_004926D0;
extern char D_005329A0[];
extern char D_004B92B0[];
void FrontEnd_FlushMessages(void *p);
int func_00334780(void);
int AgentFile_EncodeName(const char *in, char *out, int digit, unsigned int max);
int MemCardWrap_Write(Mc4110 *mc, char *name, void *buf, int size, int flag);
int MemCardWrap_Read(Mc4110 *mc, char *name, void *buf, int size);
void AgentData_Reset(void *self);
void awards_SetAwardsAndBonuses(void *self, int a, int b);
extern char D_0052FE00[];
extern int D_004FFBBC;
}
static inline bool Idle4110(Mc4110 *m) { return !m->busy; }
static inline void WInt4110(int v) { *(int *)D_0052FDF0 = v; D_0052FDF0 += 4; }
static inline void WBuf4110(const void *p, int n) { memcpy(D_0052FDF0, p, n); D_0052FDF0 += n; }
static inline bool Ready4110(Mc4110 *m) { return m->cfg->b59D && m->cfg->b59E; }
static inline int RInt4110(void) { int v = *(int *)D_0052FDF0; D_0052FDF0 += 4; return v; }
static inline void RBuf4110(void *p, int n) { memcpy(p, D_0052FDF0, n); D_0052FDF0 += n; }
static inline void RStr4110(char *dst) { int n = RInt4110(); memcpy(D_0052FE00, D_0052FDF0, n); D_0052FDF0 = (char *)((int *)D_0052FDF0 + ((unsigned int)(n + 3) >> 2)); String_Copy(dst, D_0052FE00); }
extern "C" int AgentData_Load(A4110 *self, char *name, int digit)
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
    AgentData_Reset(self);
    mc = &D_0055A830;
    if (Idle4110(mc) && Ready4110(mc)) {
        D_0052FDF0 = (char *)D_0052AFD0;
        ok = MemCardWrap_Read(mc, fn, D_0052FDF0, 0x4E20) != 0;
        if (ok) {
            D_004FFBBC = mc->cfg->i5A8;
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
            for (a = 0; a < func_00334780(); a++) self->objectiveBits[a] = RInt4110();
            RBuf4110(self->name8AC, 0x10);
            RBuf4110(self->b8CC, 0x10);
            RBuf4110(self->b8BC, 0x10);
            if (*(int *)self->pad00 >= 0x10) {
                RBuf4110(tmp, 0x40);
                String_Copy(self->b8DC, tmp);
                RBuf4110(tmp, 0x80);
                String_Copy(self->b91C, tmp);
                self->i99C = RInt4110();
                RBuf4110(tmp, 0x40);
                String_Copy(self->b95C, tmp);
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
            if (*(int *)self->pad00 >= 3) awards_SetAwardsAndBonuses(self, 0, 1);
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
void AgentData_ApplyReachedRatings(O_3351E0* o, int force); /* gsynth: defined below */
typedef struct { char pad[0xB08]; unsigned int bits[1]; } A352C0;
void AgentData_UnlockById(A352C0* self, int id); /* gsynth: defined below */
typedef struct { char p0[4]; int count; unsigned char* data; } B335350;
typedef struct { unsigned char state; char p1[3]; B335350 b; } P335350;
typedef struct { char p0[0x10]; int arg; } Q335350;
void AgentData_StepAwardElement(void* self, P335350* p, Q335350* q, int force); /* gsynth: defined below */
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
extern DosDefVec070 D_00532B50;
#if 0 /* merge_units */
extern void AgentData_StepAwardElement(Agent070* self, RangeRec070* rec, RangeDef070* def, int x);
#endif /* merge_units */
#define AgentData_StepAwardElement(a0, a1, a2, a3) (AgentData_StepAwardElement((void *)(a0), (void *)(a1), (void *)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void AgentData_ApplyReachedRatings(Agent070* self, int x);
#endif /* merge_units */
#define AgentData_ApplyReachedRatings(a0, a1) (AgentData_ApplyReachedRatings((void *)(a0), (a1))) /* merge_units */

extern int AgentData_TotalPoints(Agent070* self);
#if 0 /* merge_units */
extern void AgentData_UnlockById(Agent070* self, int id);
#endif /* merge_units */
#define AgentData_UnlockById(a0, a1) (AgentData_UnlockById((void *)(a0), (a1))) /* merge_units */


void AgentData_AwardPass(Agent070* self, int x)
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
            AgentData_StepAwardElement(self, &rv->data[j], &tb->data[j], x);
        }
    }
    AgentData_ApplyReachedRatings(self, x);
    pts = AgentData_TotalPoints(self);
    dv = &D_00532B50;
    for (i = 0; i < dv->count; i++) {
        if (pts >= dv->data[i].need) {
            AgentData_UnlockById(self, dv->data[i].id);
            self->dossier = &dv->data[i];
        }
    }
}
#undef AgentData_StepAwardElement /* merge_units */
#undef AgentData_ApplyReachedRatings /* merge_units */
#undef AgentData_UnlockById /* merge_units */
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
void AgentData_UnlockById(O_3351E0* o, int arg);
#endif /* merge_units */
#define AgentData_UnlockById(a0, a1) (AgentData_UnlockById((void *)(a0), (a1))) /* merge_units */


void AgentData_ApplyReachedRatings(O_3351E0* o, int force)
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
            AgentData_UnlockById(o, e->arg);
        }
    }
}
#undef AgentData_UnlockById /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003351E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003351E0 */

/* merge_units: begin func_003352C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x80]; char name[1]; } W352C0;

extern void* D_004FFD30;
extern W352C0* WeaponDb_Get(void* db, int id);
extern void cAgentData_UnlockWeapon(A352C0* self, const char* name);
void AgentData_UnlockById(A352C0* self, int id)
{
    if (id > -1) {
        if (id < 10000) {
            cAgentData_UnlockWeapon(self, WeaponDb_Get(D_004FFD30, id)->name);
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
extern void AgentData_UnlockById(void* self, int arg);
#endif /* merge_units */
#define AgentData_UnlockById(a0, a1) (AgentData_UnlockById((void *)(a0), (a1))) /* merge_units */

#pragma opt_strength_reduction off
/* Marks the part complete when every sub-step is done, then notifies. */
void AgentData_StepAwardElement(void* self, P335350* p, Q335350* q, int force)
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
        AgentData_UnlockById(self, q->arg);
    }
}
#undef AgentData_UnlockById /* merge_units */
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
E **func_003305C0(V *v);
void *Loc_GetStoredKey(void *name);
int Awards_MatchKeyPattern(void *agent, char *a, void *name, int c);
unsigned char AgentData_IsObjectiveComplete(void *agent, void *name);
void func_00299500(IV *v);
char *Loc_LookupText(void *name);
int Loc_FindKeyThunk(int k);
int Awards_ResolveUnlock(int k);
void func_00337F90(IV *v, Item *pos, int n, Item *val);
}
static inline bool Neq(E *a, E *b) { return !(a == b); }
extern "C" void AgentData_GetLevelObjectives(void *agent, char *s, IV *out)
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
    it = *func_003305C0(&D_005329F0);
    end = *func_003305C0(&D_005329F0) + D_005329F0.count;
    for (; Neq(it, end); it++) {
        name = Loc_GetStoredKey(it->name);
        if (Awards_MatchKeyPattern(agent, pat, name, '*') && !Awards_MatchKeyPattern(agent, D_004B92C0, name, '*')) {
            Item item;
            char st = AgentData_IsObjectiveComplete(agent, name) ? 2 : 1;
            item.text = Loc_LookupText(name);
            item.name = name;
            item.state = st;
            void* k = 0;
            item.agent = k ? Awards_ResolveUnlock(Loc_FindKeyThunk(0)) : -1;
            item.a = 0;
            item.b = 0;
            item.c = 0;
            func_00337F90(out, &out->data[out->count], 1, &item);
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
extern "C" void AgentData_CountObjectives(void *agent, char *s, Stats *st)
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
    it = *func_003305C0(&D_005329F0);
    end = *func_003305C0(&D_005329F0) + D_005329F0.count;
    for (; Neq(it, end); it++) {
        void *name = Loc_GetStoredKey(it->name);
        if (Awards_MatchKeyPattern(agent, pat, name, '*') && !Awards_MatchKeyPattern(agent, D_004B92C0, name, '*')) {
            st->total++;
            if (AgentData_IsObjectiveComplete(agent, name))
                st->done++;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00335660(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00335660 */
