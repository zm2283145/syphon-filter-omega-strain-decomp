typedef struct { int a, b, c; } Str;
typedef struct { unsigned char v; int lo; int hi; } Rng;
typedef struct {
    Str name;
    unsigned char done;
    Rng r1, r2, r3, r4, r5;
    char pad[0x5C - 0x4C];
} Ent;
typedef struct { int r[8]; } Rec;
typedef struct { int a; int count; Rec* recs; } Sub;
typedef struct { char pad[0xC4]; Sub sub; } Agent;
typedef struct {
    char pad[0x6C];
    void* p6C;
    char pad70[4];
    int n;
    Ent* ents;
} Self;

extern char g_Game[];
extern char D_004BAAA8[];
extern char D_004BAAB8[];
extern char D_004BAAC0[];
extern char* D_0048C160[];
Agent* cGameSystem_GetAgentData(void* list, int idx);
char* nGlobalization_GetString_charP(const char* key);
int sprintf(char* buf, const char* fmt, ...);
void std_basic_string_char_char_traits_char_ctor_charP(Str* s, const char* c);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str* d, Str* s);
void String_Dtor(void* s, int f);
__int128 nGlobalization_MakeTag(const char* s);
unsigned char HasBonusLevel__10cAgentDataF1(Agent* a, __int128 k);
void GuiMissionStatList_StatsUpdated(void* p);

static inline void RngA(Rng* d, int lo, int hi) { if (lo == 0) lo = -1; d->v = lo != -1 && hi >= lo; d->lo = lo; d->hi = hi; }
static inline void RngB(Rng* d, int lo) { d->v = lo == 0; d->lo = lo; d->hi = 0; }
static inline void RngC(Rng* d, int hi, int lo) { if (hi == 0) { lo = -1; hi = lo; } d->v = lo == hi && lo != -1; d->lo = lo; d->hi = hi; }
#pragma opt_strength_reduction off
void GuiMissionStatistics_UpdateMissionStats(Self* self)
{
    Agent* ag;
    char* none;
    Sub* sub;
    int i;
    Ent* e;
    char** names;
    Agent* a2;
    if (self->n != 0x11) return;
    ag = cGameSystem_GetAgentData(g_Game, -1);
    sub = &ag->sub;
    if (ag->sub.count < 0x11) return;
    none = nGlobalization_GetString_charP(D_004BAAA8);
    if (!none) none = D_004BAAB8;
    i = 0; if (i < self->n) { names = D_0048C160; do {
        e = &self->ents[i];
        a2 = cGameSystem_GetAgentData(g_Game, -1);
        e->done = HasBonusLevel__10cAgentDataF1(a2, nGlobalization_MakeTag(*names));
        if (e->done) {
            char buf[0x80];
            Str t;
            char* s;
            int parTime; int time; int collateral; int total; int completed; int deaths;
            sprintf(buf, D_004BAAC0, i);
            s = nGlobalization_GetString_charP(buf);
            { Str* p = &t; std_basic_string_char_char_traits_char_ctor_charP(p, s ? s : D_004BAAB8); }
            std_basic_string_char_char_traits_char_assign_basicstringR(&e->name, &t);
            String_Dtor(&t, 0);

            parTime = sub->recs[i].r[2]; time = sub->recs[i].r[0]; if (time == 0) time = -1; e->r1.v = time != -1 && parTime >= time; e->r1.lo = time; e->r1.hi = parTime;
            parTime = sub->recs[i].r[3]; time = sub->recs[i].r[1]; if (time == 0) time = -1; e->r2.v = time != -1 && parTime >= time; e->r2.lo = time; e->r2.hi = parTime;
            collateral = sub->recs[i].r[4]; e->r3.v = collateral == 0; e->r3.lo = collateral; e->r3.hi = 0;
            completed = sub->recs[i].r[7]; total = sub->recs[i].r[6]; if (total == 0) { completed = -1; total = completed; } e->r4.v = completed == total && completed != -1; e->r4.lo = completed; e->r4.hi = total;
            deaths = sub->recs[i].r[5]; e->r5.v = deaths == 0; e->r5.lo = deaths; e->r5.hi = 0;
        } else {
            Str t2;
            std_basic_string_char_char_traits_char_ctor_charP(&t2, none);
            std_basic_string_char_char_traits_char_assign_basicstringR(&e->name, &t2);
            String_Dtor(&t2, 0);
        }
    } while (names++, ++i < self->n); }
    if (self->p6C) GuiMissionStatList_StatsUpdated(self->p6C);
}










