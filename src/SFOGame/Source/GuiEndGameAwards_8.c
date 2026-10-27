/*
 * SFOGame/Source/GuiEndGameAwards: 2 files, 0045F860-0045FAB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045F860 */
#pragma push /* merge_units */
#include "types.h"

typedef struct F860W {
    char pad00[0x14];
    unsigned short flags;
} F860W;

typedef struct F860Slot {
    F860W* w;
    char pad04[0x14];
} F860Slot;

typedef struct F860X {
    char pad00[0x34];
    float x;
    float y;
} F860X;

typedef struct F860 {
    char pad00[0x48];
    F860Slot slots[15];
    F860X* anchor;
    int layout;
} F860;

extern int D_00497B20[][3];
extern void GuiWidget_SendMessage(F860* self, F860W* w, int a, int b, int c);
extern void GuiWidget_SetPosition(float x, float y, F860W* w);

void GuiEndGameAwards_PositionAwards(F860* self) {
    int i;
    F860Slot* s;
    F860X* a;
    float ax;
    float ay;
    int rows;
    int j;
    float y;
    int r;
    int n;
    float x;
    float yy;
    int c;
    int k;

    for (i = 0; i < 15; i++) {
        if (self->slots[i].w) {
            self->slots[i].w->flags &= ~2;
            GuiWidget_SendMessage(self, self->slots[i].w, 10, 0, 0);
        } else {
            return;
        }
    }
    if (self->layout <= 0 || self->layout >= 16 || (a = self->anchor) == 0)
        return;
    rows = 0;
    ax = a->x;
    ay = a->y;
    for (j = 0; j < 3; j++) {
        if (D_00497B20[self->layout - 1][j])
            rows++;
    }
    y = -120.0f;
    y = ((3 - rows) * y) / 2.0f;
    k = 0;
    for (r = 0; r < rows; r++) {
        n = D_00497B20[self->layout - 1][r];
        x = 120.0f;
        x = ((5 - n) * x) / 2.0f;
        for (c = 0; c < n; c++) {
            GuiWidget_SetPosition(ax + x, ay + y, self->slots[k].w);
            k++;
            x += 120.0f;
        }
        y += -120.0f;
    }
}
static inline void merge_flush_func_0045F860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045F860 */

/* merge_units: begin GuiNewParts_45FAB0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_GuiNewParts_45FAB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiNewParts_45FAB0 */
