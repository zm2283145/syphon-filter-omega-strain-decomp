#pragma cplusplus on
#include "types.h"
typedef __int128 u128;

typedef struct { char p[16]; } Str_09F0;
typedef struct { char pad[8]; unsigned char on; char pad2[0xB]; } Item_09F0;
struct Rel_09F0 { int a0; int count; Item_09F0* data; unsigned char own; char pad[3]; int Size() { return count; } Item_09F0& operator[](unsigned int i) { return data[i]; } };
struct Pair_09F0 { signed char a, b; Pair_09F0() {} };
struct Blk_09F0 { u128 a, b; Blk_09F0() {} };
struct Pal_09F0 {
    Pair_09F0 p0[8];
    u128 q;
    Pair_09F0 p1[8];
    Pair_09F0 p2[8];
    Blk_09F0 blk[32];
};
typedef struct {
    char pad0[0x8BC];
    char name[0x9A4 - 0x8BC];
    Pal_09F0* pal;
    char pad1[0xB50 - 0x9A8];
    int* team;
} Agent_09F0;
struct Obj_09F0 { char pad[0xA0]; Pal_09F0 pal; void SetPal(const Pal_09F0& s) { pal = s; } };
typedef struct {
    char pad0[0x88];
    int s88, s8C, s90, s94, s98, s9C;
    int pA0, pA4;
    int sA8, sAC, sB0, sB4;
    char strB8[0xC];
    char strC4[0xC];
    int team;
    unsigned char flags[6][4];
    unsigned char slots[8];
    char padF4[8];
    int fFC;
    char pad100[0x20];
    struct Obj_09F0* dst;
} Panel_09F0;

extern "C" {
extern char D_004FFB50;
Agent_09F0* Agent_GetSelected(void* list, int idx);
char* func_00336170(Agent_09F0* a);
void String_CtorCStr_13B480(Str_09F0* s, const char* c);
void func_0013D680(void* dst, Str_09F0* s);
void String_Dtor(Str_09F0* s, short f);
char* DME_GetLobby(void);
void String_Copy(char* dst, char* src);
int cAgentData_GetStat(Agent_09F0* a, int id);
void func_00296FA0(Rel_09F0* r);
void func_00299360(Rel_09F0* r, short f);
void func_00333600(Agent_09F0* a, Rel_09F0* r);
void func_003334C0(Agent_09F0* a, int k, Rel_09F0* r);
void func_00360510(void* p);
void func_00361000(Panel_09F0* p);
}

extern "C" void func_003609F0(Panel_09F0* p)
{
    Agent_09F0* a;
    char* g;
    Str_09F0 s1;
    Str_09F0 s2;
    Rel_09F0 r1;
    Rel_09F0 r2;
    Pal_09F0* src;

    func_00360510(&p->s88);
    a = Agent_GetSelected(&D_004FFB50, -1);
    String_CtorCStr_13B480(&s1, func_00336170(a));
    func_0013D680(p->strB8, &s1);
    String_Dtor(&s1, 0);
    g = DME_GetLobby();
    if (g) String_Copy(a->name, g + 0xE8C);
    String_CtorCStr_13B480(&s2, a->name);
    func_0013D680(p->strC4, &s2);
    String_Dtor(&s2, 0);
    p->team = a->team[1];
    p->s88 = cAgentData_GetStat(a, 0xD);
    p->s8C = cAgentData_GetStat(a, 9);
    p->s90 = cAgentData_GetStat(a, 0xA);
    p->s94 = cAgentData_GetStat(a, 2);
    p->s98 = cAgentData_GetStat(a, 1);
    p->s9C = cAgentData_GetStat(a, 4);
    p->pA0 = (cAgentData_GetStat(a, 0xC) && cAgentData_GetStat(a, 0xB)) ? (int)(100.0f * ((float)cAgentData_GetStat(a, 0xC) / (float)cAgentData_GetStat(a, 0xB))) : 0;
    p->pA4 = (cAgentData_GetStat(a, 0xA) && cAgentData_GetStat(a, 9)) ? (int)(100.0f * ((float)cAgentData_GetStat(a, 0xA) / (float)cAgentData_GetStat(a, 9))) : 0;
    p->sA8 = cAgentData_GetStat(a, 6);
    p->sAC = cAgentData_GetStat(a, 7);
    p->sB0 = cAgentData_GetStat(a, 8);
    p->sB4 = cAgentData_GetStat(a, 0);
    func_00296FA0(&r1);
    r1.own = 1;
    func_00333600(Agent_GetSelected(&D_004FFB50, -1), &r1);
    int k = 0; for (int i = 0; i < 6; i++) {
        int j;
        for (j = 0; j < 4; j++) {
            p->flags[i][j] = r1[k++].on != 0;
        }
    }
    func_00296FA0(&r2);
    r2.own = 1;
    func_003334C0(a, 0, &r2);
    for (int i = 0; i < 8; i++) {
        if (i < r2.Size()) {
            p->slots[i] = r2[i].on != 0;
        } else {
            p->slots[i] = 0;
        }
    }
    if (a->pal) {
        p->dst->SetPal(*a->pal);
    }
    func_00361000(p);
    p->fFC = 0;
    func_00299360(&r2, 0);
    func_00299360(&r1, 0);
}












