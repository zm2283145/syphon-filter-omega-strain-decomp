#pragma cplusplus on
#include "types.h"
#pragma opt_strength_reduction off

typedef struct {
    void *obj;
    int val;
    char name[16];
} EntFAB0;

typedef struct {
    char pad0[0x48];
    EntFAB0 e[15];
    int pad1B0;
    int n;
} ObjFAB0;

typedef struct {
    int text;
    int unk4;
    unsigned char type;
    char pad9[0xB];
} ItemFAB0;

struct ListFAB0 {
    int unk0;
    int count;
    ItemFAB0 *items;
    unsigned char flag;
    int Count() const { return count; }
};

typedef struct {
    int text;
    int idx;
} CurFAB0;

typedef struct {
    char pad0[0xB50];
    CurFAB0 *cur;
    CurFAB0 *b54;
} AgentFAB0;

typedef struct {
    char pad[0x25C];
    int f25C;
} GFAB0;

extern "C" {
extern char D_004C24A8[];
extern char D_004C24B0[];
extern char D_004C24B8[];
extern char D_004C24C0[];
extern char D_004C24C8[];
extern char D_004C24D8[];
extern char g_Game[];
extern GFAB0 *D_004FFC04;
int sprintf(char *buf, const char *fmt, ...);
void Libc_Strcpy(char *d, const char *s);
void Libc_Strcat(char *d, const char *s);
void GuiBitmapWidget_SetBitmap(void *obj, char *name, int x);
AgentFAB0 *cGameSystem_GetAgentData(void *a, int i);
int nGlobalization_GetString_charP(void *key);
int cAgentData_HasSpecialBonus(AgentFAB0 *a, unsigned char i);
int cAgentData_HadSpecialBonus(AgentFAB0 *a, unsigned char i);
void cAgentData_GetAchievements(AgentFAB0 *a, unsigned char type, ListFAB0 *out);
void cAgentData_GetRatings(AgentFAB0 *a, ListFAB0 *out);
void func_00296FA0(ListFAB0 *l);
void func_00299360(ListFAB0 *l, short f);
void GuiEndGameAwards_PopulateAwards(ObjFAB0 *o);
}

static inline void AddEntry(ObjFAB0 *o, int x, int type, int sub, int val)
{
    char buf[256];
    EntFAB0 *e;
    if (o->n < 15) {
        e = &o->e[o->n];
        sprintf(buf, D_004C24A8, type, sub);
        Libc_Strcpy(e->name, D_004C24B0);
        if (type != 7)
            Libc_Strcat(buf, D_004C24B8);
        Libc_Strcat(buf, D_004C24C0);
        if (e->obj)
            GuiBitmapWidget_SetBitmap(e->obj, buf, x);
        e->val = val;
        o->n++;
    }
}

static inline bool HasCur(AgentFAB0 *a)
{
    bool ok = false;
    if (a->b54 != 0 && a->cur != a->b54)
        ok = true;
    return ok;
}

void GuiEndGameAwards_PopulateAwards(ObjFAB0 *o)
{
    int x = D_004FFC04->f25C;
    o->n = 0;
    if (x != 0) {
        AgentFAB0 *agent = cGameSystem_GetAgentData(g_Game, -1);
        ListFAB0 list;
        char *key;
        func_00296FA0(&list);
        list.flag = 1;
        if (HasCur(agent)) {
            CurFAB0 *cur = agent->cur;
            AddEntry(o, x, 6, cur->idx + 1, nGlobalization_GetString_charP((void *)cur->text));
            AddEntry(o, x, 7, 7, nGlobalization_GetString_charP(D_004C24C8));
        }
        {
        int i;
        key = D_004C24D8;
        for (i = 0; i < 6; i++) {
            if (cAgentData_HasSpecialBonus(agent, i) && !cAgentData_HadSpecialBonus(agent, i)) {
                key[11] = i + '0';
                AddEntry(o, x, 7, i + 1, nGlobalization_GetString_charP(key));
            }
        }
        }
        cAgentData_GetAchievements(agent, 2, &list);
        {
        int i;
        for (i = 0; i < list.Count(); i++) {
            if (list.items[i].type == 1)
                AddEntry(o, x, 2, i + 1, list.items[i].text);
        }
        }
        cAgentData_GetAchievements(agent, 1, &list);
        {
        int i;
        for (i = 0; i < list.Count(); i++) {
            if (list.items[i].type == 1)
                AddEntry(o, x, 4, i + 1, list.items[i].text);
        }
        }
        cAgentData_GetRatings(agent, &list);
        {
        int i;
        for (i = 0; i < list.Count(); i++) {
            if (list.items[i].type == 1)
                AddEntry(o, x, 3, i + 1, list.items[i].text);
        }
        }
        cAgentData_GetAchievements(agent, 0, &list);
        {
        int i;
        for (i = 0; i < list.Count(); i++) {
            if (list.items[i].type == 1)
                AddEntry(o, x, 3, i + 0x1A, list.items[i].text);
        }
        }
        func_00299360(&list, 0);
    }
}
