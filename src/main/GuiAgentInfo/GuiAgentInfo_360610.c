/*
 * main/GuiAgentInfo: 2 files, 00360610-003609F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00360610 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on

typedef struct { char c[16]; } C16;
typedef struct { Q q[64]; } Q64;
typedef struct { C16 a; __int128 b; C16 c; C16 d; Q64 e; } Blk;

extern void func_00360510(char*);
extern int String_CtorCStr_13B480(char*, char*);
extern int String_Dtor(char*, int);
extern int func_0013D680(char*, char*);
extern char* DME_GetLobby(void);
extern int func_0044A1D0(char*);
extern int func_00452FF0(char*, int);
extern char* func_0044A070(char*);
extern char* func_00448FF0(char*, int);
extern void* memset(void*, int, int);
extern void* memcpy(void*, void*, int);
extern void* Agent_GetSelected(void*, int);
extern void func_00406EC0(Blk*, char*);
extern void Skl_Load(void*, char*, char*);
extern void func_00361000(char*);
extern char D_004BB868[];
extern char D_004FFB50[];
extern char D_0055DDA0[];
extern C16 D_0055D510;
extern __int128 D_0055D520;
extern C16 D_0055D530;
extern C16 D_0055D540;
extern Q64 D_0055D550;

typedef struct { unsigned char type, b1, b2, b3; unsigned short h4, h6, h8, hA, hC, hE; int x10, x14, x18, x1C, x20, mask; char data[0xC0]; int xE8; } Msg;
void func_00360610(char* self, int* arg1, Msg* arg2) {
    char s1[16];
    char s2[16];
    char s3[16];
    char s4[16];
    char buf[0x100];
    char* o;
    char* r;
    Blk* p;
    int i, j;

    func_00360510(self + 0x88);
    F_(self, 0xD0, int) = arg2->b1;
    String_CtorCStr_13B480(s1, (char*)(arg1 + 1));
    func_0013D680(self + 0xB8, s1);
    String_Dtor(s1, 0);
    o = DME_GetLobby();
    if (o) {
        F_(self, 0xF4, char) = func_0044A1D0(o);
        if (!(unsigned char)func_00452FF0(o, 0)) {
            if (arg1[0] == F_(o, 0x2480, int)) {
                F_(self, 0xF8, int) = -1;
                String_CtorCStr_13B480(s2, func_0044A070(o));
                func_0013D680(self + 0xC4, s2);
                String_Dtor(s2, 0);
            } else {
                F_(self, 0xF8, int) = arg1[0];
                String_CtorCStr_13B480(s3, D_004BB868);
                func_0013D680(self + 0xC4, s3);
                String_Dtor(s3, 0);
                if (arg2->xE8 != -1) {
                    r = func_00448FF0(o, arg2->xE8);
                    if (r) {
                        String_CtorCStr_13B480(s4, r);
                        func_0013D680(self + 0xC4, s4);
                        String_Dtor(s4, 0);
                    }
                }
            }
        }
    }
    if (arg2->type == 11) {
        F_(self, 0x88, int) = arg2->h4;
        F_(self, 0x8C, int) = arg2->x10;
        F_(self, 0x90, int) = arg2->x14;
        F_(self, 0x94, int) = arg2->x18;
        F_(self, 0x98, int) = arg2->h6;
        F_(self, 0x9C, int) = arg2->h8;
        F_(self, 0xA0, int) = arg2->b2;
        F_(self, 0xA4, int) = arg2->b3;
        F_(self, 0xA8, int) = arg2->hA;
        F_(self, 0xAC, int) = arg2->hC;
        F_(self, 0xB0, int) = arg2->x20;
        F_(self, 0xB4, int) = arg2->x1C;
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 4; j++) {
                if (arg2->mask & (1 << (j + i * 4))) {
                    (self + i * 4)[0xD4 + j] = 1;
                }
            }
        }
        for (i = 0; i < 8; i++) {
            if (arg2->mask & (1 << (i + 24))) {
                (self + 0xEC)[i] = 1;
            }
        }
        memset(buf, 0, 0x100);
        memcpy(buf, arg2->data, 0xC0);
        Agent_GetSelected(D_004FFB50, -1);
        p = (Blk*)(F_(self, 0x120, char*) + 0xA0);
        memset(p, 0, 0x440);
        func_00406EC0(p, buf);
    } else {
        Skl_Load(D_0055DDA0, "GAMEDATA\\FRONTEND\\MALE.SKL", "GAMEDATA\\FRONTEND\\FEMALE.SKL");
        p = (Blk*)(F_(self, 0x120, char*) + 0xA0);
        p->a = D_0055D510;
        p->b = D_0055D520;
        p->c = D_0055D530;
        p->d = D_0055D540;
        p->e = D_0055D550;
    }
    F_(self, 0xFC, int) = 1;
    func_00361000(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_00360610 */

/* merge_units: begin func_003609F0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
#if 0 /* merge_units */
extern char D_004FFB50;
#endif /* merge_units */
#define D_004FFB50 (*(char*)&D_004FFB50) /* merge_units */

#if 0 /* merge_units */
Agent_09F0* Agent_GetSelected(void* list, int idx);
#endif /* merge_units */
#define Agent_GetSelected(a0, a1) ((Agent_09F0 *)Agent_GetSelected((a0), (a1))) /* merge_units */

char* AgentData_GetName(Agent_09F0* a);
#if 0 /* merge_units */
void String_CtorCStr_13B480(Str_09F0* s, const char* c);
#endif /* merge_units */
#define String_CtorCStr_13B480(a0, a1) ((void)String_CtorCStr_13B480((char *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
void func_0013D680(void* dst, Str_09F0* s);
#endif /* merge_units */
#define func_0013D680(a0, a1) ((void)func_0013D680((char *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
void String_Dtor(Str_09F0* s, short f);
#endif /* merge_units */
#define String_Dtor(a0, a1) ((void)String_Dtor((char *)(a0), (int)(a1))) /* merge_units */

char* DME_GetLobby(void);
void String_Copy(char* dst, char* src);
int cAgentData_GetStat(Agent_09F0* a, int id);
void func_00296FA0(Rel_09F0* r);
void func_00299360(Rel_09F0* r, short f);
void AgentData_GetRatings(Agent_09F0* a, Rel_09F0* r);
void AgentData_GetAwardRows(Agent_09F0* a, int k, Rel_09F0* r);
#if 0 /* merge_units */
void func_00360510(void* p);
#endif /* merge_units */
#define func_00360510(a0) (func_00360510((char *)(a0))) /* merge_units */

#if 0 /* merge_units */
void func_00361000(Panel_09F0* p);
#endif /* merge_units */
#define func_00361000(a0) (func_00361000((char *)(a0))) /* merge_units */

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
    String_CtorCStr_13B480(&s1, AgentData_GetName(a));
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
    AgentData_GetRatings(Agent_GetSelected(&D_004FFB50, -1), &r1);
    int k = 0; for (int i = 0; i < 6; i++) {
        int j;
        for (j = 0; j < 4; j++) {
            p->flags[i][j] = r1[k++].on != 0;
        }
    }
    func_00296FA0(&r2);
    r2.own = 1;
    AgentData_GetAwardRows(a, 0, &r2);
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
#undef D_004FFB50 /* merge_units */
#undef Agent_GetSelected /* merge_units */
#undef String_CtorCStr_13B480 /* merge_units */
#undef func_0013D680 /* merge_units */
#undef String_Dtor /* merge_units */
#undef func_00360510 /* merge_units */
#undef func_00361000 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003609F0 */
