/*
 * main/AgentData: range (4 files, 00335D50-00336110)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
int strlen(const char *);

/* merge_units: begin func_00335D50 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct RecE50 { int t0; int t4; int t8; int tC; int i10; int i14; int pad18[2]; };
struct AE50 {
    char pad00[0x40];
    int n40;
    int n44;
    int n48;
    int n4C;
    char pad50[0xC8 - 0x50];
    int nLevels;
    RecE50 *recs;
    char padD0[0xB08 - 0xD0];
    int unkB08[9];
    char padB2C[0xB5C - 0xB2C];
    int iB5C;
};
extern "C" void awards_SetAwardsAndBonuses(AE50* self, int x, int reset); /* gsynth: defined below */
#pragma pop
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
#if 0 /* merge_units */
int awards_SetAwardsAndBonuses(char * , int, int);
#endif /* merge_units */
#define awards_SetAwardsAndBonuses(a0, a1, a2) (awards_SetAwardsAndBonuses((void *)(a0), (a1), (a2))) /* merge_units */
         
int AgentData_CopyShownUnlocks();                                

void AgentData_StartLevel(char * arg0, int arg1) {
    int var_a0;
    int var_s2;
    char * var_s1;
    char * var_v1;

    var_a0 = 0x12;
    var_v1 = arg0 + 0x48;
    do {
        F_(var_v1, 0x8, int) = 0;
        F_(var_v1, 0xC, int) = 0;
        var_a0 += 6;
        F_(var_v1, 0x10, int) = 0;
        F_(var_v1, 0x14, int) = 0;
        F_(var_v1, 0x18, int) = 0;
        F_(var_v1, 0x1C, int) = 0;
        var_v1 += 0x18;
    } while (var_a0 < 0x19);
    F_(((char *)(var_a0 * 4) + (int)(arg0)), 0x8, int) = 0;
    awards_SetAwardsAndBonuses(arg0, 1, arg1);
    F_(arg0, 0xA4, int) = 0;
    var_s2 = 0;
    F_(arg0, 0xA8, int) = 0;
    F_(arg0, 0xAC, int) = 0;
    F_(arg0, 0xB0, int) = 0;
    F_(arg0, 0xB4, int) = 0;
    F_(arg0, 0xB8, int) = 0;
    F_(arg0, 0xBC, int) = 0;
    F_(arg0, 0xC0, int) = 0;
    for (var_s2 = 0; var_s2 < AgentData_CopyShownUnlocks(); var_s2++) F_(arg0 + var_s2 * 4, 0xB2C, int) = F_(arg0 + var_s2 * 4, 0xB08, int);
    F_(arg0, 0xB70, signed char) = 1;
    F_(arg0, 0xB71, signed char) = 0;
    F_(arg0, 0xB54, int) = F_(arg0, 0xB50, int);
    F_(arg0, 0xD4, int) = 0xBF800000;
}
#undef awards_SetAwardsAndBonuses /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00335D50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00335D50 */

/* merge_units: begin func_00335E50 */
#pragma push /* merge_units */
#pragma cplusplus on
struct LvlE50 { int name; int pad[5]; };
struct PairE50 { int a; int b; };


extern "C" {
extern char D_00555070[];
extern char D_004B92E0[];
extern LvlE50 *D_00532AF8;
extern PairE50 *D_00532B98;
char *Loc_GetStoredKey(int name);
void AgentData_CountObjectives(AE50 *agent, char *s, RecE50 *st);
void AgentData_AwardPass(AE50 *agent, int x);
int ScriptMgr_CallFunction(void *mgr, char *name, int n, ...);
}
extern "C" void awards_SetAwardsAndBonuses(AE50 *self, int x, int reset)
{
    int i;
    RecE50 *rec;
    if (reset) {
        self->n44 = 0;
        self->n40 = 0;
        self->n4C = 0;
        self->n48 = 0;
    }
    for (i = 0; i < self->nLevels - 1; i++) {
        char *name = Loc_GetStoredKey(D_00532AF8[(unsigned)i].name);
        rec = &self->recs[(unsigned)i];
        AgentData_CountObjectives(self, name, rec);
        rec->tC = D_00532B98[(unsigned)i].b;
        rec->t8 = D_00532B98[(unsigned)i].a;
        if (rec->tC <= 0) rec->t4 = -1;
        if (reset) {
            if (rec->t0 > 0 && rec->t0 <= rec->t8) self->n40++;
            if (rec->t4 > 0 && rec->t4 <= rec->tC) self->n44++;
            if (rec->i14 == 0) self->n48++;
            if (rec->i10 == 0) self->n4C++;
        }
    }
    { int j; for (j = 0; j < 9; j++) self->unkB08[j] = 0; }
    self->iB5C = 0;
    ScriptMgr_CallFunction(D_00555070, D_004B92E0, 1, self);
    AgentData_AwardPass(self, x);
    ScriptMgr_CallFunction(D_00555070, D_004B92E0, 1, self);
    AgentData_AwardPass(self, x);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00335E50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00335E50 */

/* merge_units: begin func_00336060 */
#pragma push /* merge_units */
extern char D_00532990[];
extern char D_00532991[];
extern char D_00532992[];
extern char D_00499C71[];
char *AgentData_GetLevelShortName(int unused, char *s)
{
    int i = 0;
    int len = strlen(s) - 1;
    char c;
    D_00532990[0] = s[0];
    D_00532991[0] = s[1];
    D_00532992[0] = s[2];
    i += 3;
    c = s[len];
    if (D_00499C71[c] & 4) {
        D_00532990[i++] = c;
    }
    D_00532990[i] = 0;
    return D_00532990;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336060 */

/* merge_units: begin func_00336110 */
#pragma push /* merge_units */
typedef struct { char pad[0xB50]; int* p; } T36110;
extern void* D_004FFC04;
extern char* App_GetAgentRankGate(void* p);
extern char* Loc_LookupText(char* key);
char* AgentData_GetRankText(T36110* self)
{
    char buf[16];
    char* r = App_GetAgentRankGate(D_004FFC04);
    if (r)
        return r;
    sprintf(buf, "S_%s", *self->p);
    return Loc_LookupText(buf);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336110 */
