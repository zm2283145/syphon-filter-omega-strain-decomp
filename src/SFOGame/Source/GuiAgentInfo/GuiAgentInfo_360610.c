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

extern void GuiAgentInfo_AgentInfo_Reset(char*);
extern int std_basic_string_char_char_traits_char_ctor_charP(char*, char*);
extern int String_Dtor(char*, int);
extern int std_basic_string_char_char_traits_char_assign_basicstringR(char*, char*);
extern char* cDME_GetLobby(void);
extern int SFOLobby_CellIsPlayerCellLeader(char*);
extern int SFOLobby_GetErrorDetails(char*, int);
extern char* SFOLobby_CellGetName(char*);
extern char* func_00448FF0(char*, int);
extern void* memset(void*, int, int);
extern void* memcpy(void*, void*, int);
extern void* cGameSystem_GetAgentData(void*, int);
extern void SKL_UncompressSKL(Blk*, char*);
extern void Monster_LoadMenSKLs(void*, char*, char*);
extern void GuiAgentInfo_SetupWidgets(char*);
extern char D_004BB868[];
extern char g_Game[];
extern char g_AgentPartCache[];
extern C16 D_0055D510;
extern __int128 D_0055D520;
extern C16 D_0055D530;
extern C16 D_0055D540;
extern Q64 D_0055D550;

typedef struct { unsigned char type, b1, b2, b3; unsigned short h4, h6, h8, hA, hC, hE; int x10, x14, x18, x1C, x20, mask; char data[0xC0]; int xE8; } Msg;
void GuiAgentInfo_DisplayRemoteAgent(char* self, int* arg1, Msg* arg2) {
    char s1[16];
    char s2[16];
    char s3[16];
    char s4[16];
    char buf[0x100];
    char* o;
    char* r;
    Blk* p;
    int i, j;

    GuiAgentInfo_AgentInfo_Reset(self + 0x88);
    F_(self, 0xD0, int) = arg2->b1;
    std_basic_string_char_char_traits_char_ctor_charP(s1, (char*)(arg1 + 1));
    std_basic_string_char_char_traits_char_assign_basicstringR(self + 0xB8, s1);
    String_Dtor(s1, 0);
    o = cDME_GetLobby();
    if (o) {
        F_(self, 0xF4, char) = SFOLobby_CellIsPlayerCellLeader(o);
        if (!(unsigned char)SFOLobby_GetErrorDetails(o, 0)) {
            if (arg1[0] == F_(o, 0x2480, int)) {
                F_(self, 0xF8, int) = -1;
                std_basic_string_char_char_traits_char_ctor_charP(s2, SFOLobby_CellGetName(o));
                std_basic_string_char_char_traits_char_assign_basicstringR(self + 0xC4, s2);
                String_Dtor(s2, 0);
            } else {
                F_(self, 0xF8, int) = arg1[0];
                std_basic_string_char_char_traits_char_ctor_charP(s3, D_004BB868);
                std_basic_string_char_char_traits_char_assign_basicstringR(self + 0xC4, s3);
                String_Dtor(s3, 0);
                if (arg2->xE8 != -1) {
                    r = func_00448FF0(o, arg2->xE8);
                    if (r) {
                        std_basic_string_char_char_traits_char_ctor_charP(s4, r);
                        std_basic_string_char_char_traits_char_assign_basicstringR(self + 0xC4, s4);
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
        cGameSystem_GetAgentData(g_Game, -1);
        p = (Blk*)(F_(self, 0x120, char*) + 0xA0);
        memset(p, 0, 0x440);
        SKL_UncompressSKL(p, buf);
    } else {
        Monster_LoadMenSKLs(g_AgentPartCache, "GAMEDATA\\FRONTEND\\MALE.SKL", "GAMEDATA\\FRONTEND\\FEMALE.SKL");
        p = (Blk*)(F_(self, 0x120, char*) + 0xA0);
        p->a = D_0055D510;
        p->b = D_0055D520;
        p->c = D_0055D530;
        p->d = D_0055D540;
        p->e = D_0055D550;
    }
    F_(self, 0xFC, int) = 1;
    GuiAgentInfo_SetupWidgets(self);
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
extern char g_Game;
#endif /* merge_units */
#define g_Game (*(char*)&g_Game) /* merge_units */

#if 0 /* merge_units */
Agent_09F0* cGameSystem_GetAgentData(void* list, int idx);
#endif /* merge_units */
#define cGameSystem_GetAgentData(a0, a1) ((Agent_09F0 *)cGameSystem_GetAgentData((a0), (a1))) /* merge_units */

char* cAgentData_GetUserName(Agent_09F0* a);
#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_ctor_charP(Str_09F0* s, const char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) ((void)std_basic_string_char_char_traits_char_ctor_charP((char *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_assign_basicstringR(void* dst, Str_09F0* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_assign_basicstringR(a0, a1) ((void)std_basic_string_char_char_traits_char_assign_basicstringR((char *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
void String_Dtor(Str_09F0* s, short f);
#endif /* merge_units */
#define String_Dtor(a0, a1) ((void)String_Dtor((char *)(a0), (int)(a1))) /* merge_units */

char* cDME_GetLobby(void);
void Libc_Strcpy(char* dst, char* src);
int cAgentData_GetStat(Agent_09F0* a, int id);
void func_00296FA0(Rel_09F0* r);
void func_00299360(Rel_09F0* r, short f);
void cAgentData_GetRatings(Agent_09F0* a, Rel_09F0* r);
void cAgentData_GetAchievements(Agent_09F0* a, int k, Rel_09F0* r);
#if 0 /* merge_units */
void GuiAgentInfo_AgentInfo_Reset(void* p);
#endif /* merge_units */
#define GuiAgentInfo_AgentInfo_Reset(a0) (GuiAgentInfo_AgentInfo_Reset((char *)(a0))) /* merge_units */

#if 0 /* merge_units */
void GuiAgentInfo_SetupWidgets(Panel_09F0* p);
#endif /* merge_units */
#define GuiAgentInfo_SetupWidgets(a0) (GuiAgentInfo_SetupWidgets((char *)(a0))) /* merge_units */

}

extern "C" void GuiAgentInfo_DisplayLocalAgent(Panel_09F0* p)
{
    Agent_09F0* a;
    char* g;
    Str_09F0 s1;
    Str_09F0 s2;
    Rel_09F0 r1;
    Rel_09F0 r2;
    Pal_09F0* src;

    GuiAgentInfo_AgentInfo_Reset(&p->s88);
    a = cGameSystem_GetAgentData(&g_Game, -1);
    std_basic_string_char_char_traits_char_ctor_charP(&s1, cAgentData_GetUserName(a));
    std_basic_string_char_char_traits_char_assign_basicstringR(p->strB8, &s1);
    String_Dtor(&s1, 0);
    g = cDME_GetLobby();
    if (g) Libc_Strcpy(a->name, g + 0xE8C);
    std_basic_string_char_char_traits_char_ctor_charP(&s2, a->name);
    std_basic_string_char_char_traits_char_assign_basicstringR(p->strC4, &s2);
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
    cAgentData_GetRatings(cGameSystem_GetAgentData(&g_Game, -1), &r1);
    int k = 0; for (int i = 0; i < 6; i++) {
        int j;
        for (j = 0; j < 4; j++) {
            p->flags[i][j] = r1[k++].on != 0;
        }
    }
    func_00296FA0(&r2);
    r2.own = 1;
    cAgentData_GetAchievements(a, 0, &r2);
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
    GuiAgentInfo_SetupWidgets(p);
    p->fFC = 0;
    func_00299360(&r2, 0);
    func_00299360(&r1, 0);
}
#undef g_Game /* merge_units */
#undef cGameSystem_GetAgentData /* merge_units */
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_basic_string_char_char_traits_char_assign_basicstringR /* merge_units */
#undef String_Dtor /* merge_units */
#undef GuiAgentInfo_AgentInfo_Reset /* merge_units */
#undef GuiAgentInfo_SetupWidgets /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003609F0 */
