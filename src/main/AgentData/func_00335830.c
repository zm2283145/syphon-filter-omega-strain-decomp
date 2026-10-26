#pragma opt_strength_reduction off
#pragma cplusplus on
#include "types.h"
struct E5830 { int name; int idx; int pad[4]; };
struct V5830 { int a; int count; E5830 *data; };
struct Lvl5830 { int name; int pad[5]; };
struct Rec5830 { int t0; int t4; int pad8[2]; int i10; int i14; int pad18[2]; };
struct Game5830 { char pad[0x140]; char levelName[0x40]; };
struct Awd5830 { int a; int b; int c; unsigned char flag; char pad[3]; };
struct A5830 {
    char pad00[0x3C];
    int count3C;
    char pad40[0x6C - 0x40];
    int i6C;
    int i70;
    char pad74[0xA4 - 0x74];
    int bits[8];
    int padC4;
    int nLevels;
    Rec5830 *recs;
    char padD0[4];
    float fD4;
    char padD8[0x9A4 - 0xD8];
    void *p9A4;
    char pad9A8[0xB71 - 0x9A8];
    unsigned char bB71;
    char padB72[2];
    unsigned char bB74;
};
extern "C" {
extern char D_00532990[];
extern char D_00532991[];
extern char D_00532992[];
extern char D_00499C70[];
extern char D_00532998[];
extern char D_004B92B8[];
extern char D_004B92C0[];
extern char D_004B92D0[];
extern V5830 D_005329F0;
extern Lvl5830 *D_00532AF8;
extern Game5830 g_Game;
extern void *g_Hud;
extern unsigned char g_IsMultiplayer;
extern int D_00532A40[];
extern int D_00532A10[];
int strlen(const char *s);
int sprintf(char *buf, const char *fmt, ...);
E5830 **std_vector_deleter_Record_data(V5830 *v);
const char *Loc_GetStoredKey(int name);
int Awards_MatchKeyPattern(A5830 *agent, const char *a, const char *name, int c);
int String_CompareNoCase(const char *a, const char *b);
float Hud_GetMissionTime(void *ui);
void AgentData_SetObjectiveBit(A5830 *agent, char *name, int notify);
void awards_SetAwardsAndBonuses(A5830 *agent, int a, int b);
void std_vector_charPtr_ctor_void_2(Awd5830 *a);
void std_vector_charPtr_dtor_void_2(Awd5830 *a, int f);
void AgentData_FilterAwards(A5830 *agent, Awd5830 *a);
void Appearance_PatchParts(void *p, Awd5830 *a);
}
static inline bool Neq5830(E5830 *a, E5830 *b) { return !(a == b); }
static inline bool Bit5830(int *bits, int idx)
{
    int r;
    if (idx > -1) r = ((bits[idx / 32] >> (idx & 31)) & 1) != 0;
    else { r = 0; asm { .set reorder } } /* empty asm block: scheduling barrier that keeps retail's branch layout */
    return r;
}
static inline void Code5830(const char *s)
{
    int i;
    int len;
    char c;
    i = 0;
    len = strlen(s) - 1;
    { const char *p = s; D_00532990[0] = p[0]; D_00532991[0] = p[1]; D_00532992[0] = p[2]; }
    i += 3;
    c = s[len];
    if ((D_00499C70 + 1)[c] & 4) {
        D_00532990[i++] = c;
    }
    D_00532990[i] = 0;
}
extern "C" void AgentData_EndLevel(A5830 *self, unsigned char done)
{
    unsigned char ok;
    char *pat;
    const char *n2;
    Rec5830 *rec;
    E5830 *it;
    const char *name;
    int i;
    E5830 *end;
    char buf[32];
    Awd5830 awd;
    self->bB74 = done;
    if (self->fD4 < 0.0f) self->fD4 = Hud_GetMissionTime(g_Hud);
    for (i = 0; i < self->nLevels; i++) {
        rec = &self->recs[i];
        name = Loc_GetStoredKey(D_00532AF8[i].name);
        if (String_CompareNoCase(name, g_Game.levelName) == 0 && done) {
            ok = 1;
            self->count3C++;
            Code5830(name);
            sprintf(D_00532998, D_004B92B8, D_00532990);
            pat = D_00532998;
            it = *std_vector_deleter_Record_data(&D_005329F0);
            end = *std_vector_deleter_Record_data(&D_005329F0) + D_005329F0.count;
            for (; Neq5830(it, end); it++) {
                n2 = Loc_GetStoredKey(it->name);
                if (Awards_MatchKeyPattern(self, pat, n2, '*') && !Awards_MatchKeyPattern(self, D_004B92C0, n2, '*')) {
                    if (!Bit5830(self->bits, it->idx)) {
                        if ((g_IsMultiplayer && Bit5830(D_00532A40, it->idx)) ||
                            (!g_IsMultiplayer && Bit5830(D_00532A10, it->idx))) {
                            ok = 0;
                            break;
                        }
                    }
                }
            }
            if (ok) {
                int *t;
                self->bB71 = 1;
                t = &rec->t0;
                if (g_IsMultiplayer) t = &rec->t4;
                if (*t < 0 || self->fD4 < (float)*t) *t = (int)self->fD4;
            }
            if (rec->i14 < 0 || self->i70 < rec->i14) rec->i14 = self->i70;
            if (rec->i10 < 0 || self->i6C < rec->i10) rec->i10 = self->i6C;
            Code5830(g_Game.levelName);
            sprintf(buf, D_004B92D0, D_00532990);
            AgentData_SetObjectiveBit(self, buf, 0);
        }
    }
    awards_SetAwardsAndBonuses(self, 0, 1);
    std_vector_charPtr_ctor_void_2(&awd);
    awd.flag = 1;
    AgentData_FilterAwards(self, &awd);
    Appearance_PatchParts(self->p9A4, &awd);
    std_vector_charPtr_dtor_void_2(&awd, -1);
}



