#pragma cplusplus on
#include "types.h"
struct LvlE50 { int name; int pad[5]; };
struct PairE50 { int a; int b; };
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
extern "C" {
extern char D_00555070[];
extern char D_004B92E0[];
extern LvlE50 *D_00532AF8;
extern PairE50 *D_00532B98;
char *func_003FDAE0(int name);
void func_00335660(AE50 *agent, char *s, RecE50 *st);
void func_00335070(AE50 *agent, int x);
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
        char *name = func_003FDAE0(D_00532AF8[(unsigned)i].name);
        rec = &self->recs[(unsigned)i];
        func_00335660(self, name, rec);
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
    func_00335070(self, x);
    ScriptMgr_CallFunction(D_00555070, D_004B92E0, 1, self);
    func_00335070(self, x);
}
