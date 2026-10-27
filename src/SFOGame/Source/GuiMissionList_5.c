/*
 * main/GuiMissionList: range (7 files, 002ABF40-002AC7E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int strcmp(const void *, const void *);

/* merge_units: begin func_002ABF40 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_002ABF40 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void SetCount(int n, int a);
};
struct S_002ABF40 : W_002ABF40 {
    char pad4[0x90 - 4]; char* f90[7]; unsigned char bAC; char padAD[3]; W_002ABF40* pB0;
};
struct T_002ABF40 { int count; int ids[3]; };
static char* const D_0048BC40[8] = { (char*)0xE0, (char*)0x8C, (char*)0x3C, (char*)0xE0, (char*)0x50, (char*)0x46, (char*)0x0, (char*)0x0 };
static const T_002ABF40 D_0048BC60[5] = { { 3, { 3, 4, 5 } }, { 3, { 0, 1, 2 } }, { 1, { 0, -1, -1 } }, { 3, { 0, 1, 5 } }, { 0, { -1, -1, -1 } } };
extern "C" {
extern char D_004AB9D0[];
void GuiArrayWidget_SetColumnWidth(void* w, int i, char* s);
void GuiTextArrayWidget_SetText(void* w, int i, int a, char* s);
}
extern "C" void GuiMissionList_SetDisplayMode(S_002ABF40* self, unsigned char idx)
{
    int n;
    int i;
    const T_002ABF40* t;
    t = &D_0048BC60[idx];
    n = t->count;
    self->SetCount(n, 0);
    self->pB0->SetCount(n, 1);
    for (i = 0; i < n; i++) {
        int id = t->ids[i];
        GuiArrayWidget_SetColumnWidth(self, i, D_0048BC40[id]);
        GuiArrayWidget_SetColumnWidth(self->pB0, i, D_0048BC40[id]);
        GuiTextArrayWidget_SetText(self->pB0, i, 0, self->f90[id] ? self->f90[id] : D_004AB9D0);
    }
    self->bAC = idx;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002ABF40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002ABF40 */

/* merge_units: begin func_002AC070 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0xAC]; unsigned char bAC; unsigned char bAD; char padAE[0xB5 - 0xAE]; unsigned char bB5;
    char padB6[0xBC - 0xB6]; unsigned char bBC; char padBD[0x120 - 0xBD]; int f120;
} S_002AC470;
typedef struct {
    int id; char name[0x20]; int f24; char pad28[0x30 - 0x28]; int f30; int f34; int f38; char pad3C[0x40 - 0x3C];
    int f40; int f44;
} E_002AC470;
int GuiMissionList_CanSelectAgent(S_002AC470* self, E_002AC470* e); /* gsynth: defined below */
typedef struct { int id; int idx; int fl; } It_002AC6F0;
typedef struct {
    char pad0[0xAC]; unsigned char bAC; char padAD[0xBC - 0xAD]; unsigned char bBC; char padBD[0x110 - 0xBD];
    int count; It_002AC6F0* data; int f118; void* p11C;
} S_002AC6F0;
void GuiMissionList_SortSelectList(S_002AC6F0* self); /* gsynth: defined below */
#pragma cplusplus on
struct W_002AC070 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void SetCount(int n, int a);
};
struct It_002AC070 { int id; int idx; int fl; };
struct Vec_002AC070 { int f0; int count; It_002AC070* data; int f118; };
struct L_002AC070 { int f0; int count; };
struct E_002AC070 { int id; };
struct S_002AC070 : W_002AC070 {
    char pad4[0x48 - 4]; int f48; char pad4C[0xC0 - 0x4C];
    int fC0; int fC4; int fC8; int fCC; char padD0[0x10C - 0xD0];
    Vec_002AC070 list; L_002AC070* p11C;
};
extern "C" {
static int D_0048BCB0 = -1;
void std_vector_deleter_SelectElem_clear(Vec_002AC070* v);
void* cDME_GetLobby(void);
#define SFOLobbyList_GetSlot(a0, a1) ((E_002AC070 *)SFOLobbyList_GetSlot((a0), (a1))) /* merge_units */
#if 0 /* merge_units */
int GuiMissionList_CanSelectAgent(S_002AC070* self, E_002AC070* e);
#endif /* merge_units */
#define GuiMissionList_CanSelectAgent(a0, a1) (GuiMissionList_CanSelectAgent((S_002AC470 *)(a0), (E_002AC470 *)(a1))) /* merge_units */

void std_vector_imp_SelectElem_insert(Vec_002AC070* v, It_002AC070* pos, int n, It_002AC070* it);
#if 0 /* merge_units */
void GuiMissionList_SortSelectList(S_002AC070* self);
#endif /* merge_units */
#define GuiMissionList_SortSelectList(a0) (GuiMissionList_SortSelectList((S_002AC6F0 *)(a0))) /* merge_units */

}
static inline int Size_002AC070(Vec_002AC070* v) { return v->count; }
static inline It_002AC070* At_002AC070(Vec_002AC070* v, int i) { return &v->data[i]; }
static inline void Upd_(S_002AC070* s, int n) { s->SetCount(s->f48, n); }
#pragma opt_strength_reduction off
#pragma opt_dead_assignments off
extern "C" void GuiMissionList_UpdateSelectList(S_002AC070* self)
{
    void* g;
    int n;
    int i;
    int sel;
    std_vector_deleter_SelectElem_clear(&self->list);
    g = cDME_GetLobby();
    if (!self->p11C || !g)
        return;
    n = self->p11C->count;
    for (i = 0; i < n; i++) {
        E_002AC070* e = SFOLobbyList_GetSlot(self->p11C, i);
        if (e) {
            int fl = GuiMissionList_CanSelectAgent(self, e);
            if (fl & 2) {
                It_002AC070 it;
                if ((fl & 4) && e->id == 0) {
                    e->id = D_0048BCB0;
                    D_0048BCB0 = D_0048BCB0 - 1;
                }
                it.id = e->id;
                it.idx = i;
                it.fl = fl;
                std_vector_imp_SelectElem_insert(&self->list, &self->list.data[self->list.count], 1, &it);
            }
        }
    }
    GuiMissionList_SortSelectList(self);
    sel = -1;
    if (self->fC0 != -1) {
        int j;
        for (j = 0; j < *(volatile int*)&self->list.count; j++) {
            if (self->fC0 == At_002AC070(&self->list, j)->id) {
                self->fCC = j;
                sel = j;
                break;
            }
        }
    }
    Upd_(self, self->list.count);
    if (sel == -1) {
        if (self->fCC == -1)
            self->fCC = 0;
        if (self->fCC >= self->list.count)
            self->fCC = self->list.count - 1;
    }
    if (self->fCC == -1) {
        self->fC0 = self->fC4 = self->fCC = -1;
    } else {
        int k = At_002AC070(&self->list, self->fCC)->idx;
        E_002AC070* e = SFOLobbyList_GetSlot(self->p11C, k);
        if (e) {
            self->fC0 = e->id;
            self->fC4 = k;
        } else {
            self->fC0 = self->fC4 = self->fCC = -1;
        }
    }
    if (self->fCC >= self->list.count)
        self->fCC = self->list.count - 1;
    if (self->fCC < 0)
        self->fCC = 0;
}
#undef SFOLobbyList_GetSlot /* merge_units */
#undef GuiMissionList_CanSelectAgent /* merge_units */
#undef GuiMissionList_SortSelectList /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002AC070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002AC070 */

/* merge_units: begin func_002AC300 */
#pragma push /* merge_units */
typedef struct { int x0; int x4; int x8; } I2AC300;
typedef struct {
    char pad0[0x74];
    int x74;
    int pad78;
    int x7C;
    char pad80[0xAC - 0x80];
    unsigned char bAC;
    char padAD[0xBC - 0xAD];
    unsigned char bBC;
    char padBD[3];
    I2AC300 cur;
    int xCC;
    char padD0[0x110 - 0xD0];
    int count;
    I2AC300* items;
} S2AC300;
extern void GuiArrayWidget_onElementGainFocus(S2AC300* s, int a, int b);
extern void* cDME_GetLobby(void);
extern void func_00450590(void* p, int a, int b);
void func_002AC300(S2AC300* s, int a, int sel)
{
    GuiArrayWidget_onElementGainFocus(s, a, sel);
    s->xCC = sel;
    if (s->xCC >= 0 && s->xCC < s->count)
    {
        I2AC300* it = &s->items[s->xCC];
        s->cur.x0 = it->x0;
        s->cur.x4 = it->x4;
        s->cur.x8 = it->x8;
    }
    if (s->bBC && !s->bAC) {
        void* p = cDME_GetLobby();
        if (p) {
            int v = s->x7C;
            if (v < 0 || v >= s->count) {
                v = 0;
                if (0 < s->count)
                    v = s->items[0].x4;
            }
            if (s->bBC)
                func_00450590(p, v, v + s->x74);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002AC300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002AC300 */

/* merge_units: begin func_002AC400 */
#pragma push /* merge_units */
typedef struct { int x0; int x4; int x8; } I2AC400;
typedef struct { char pad[0x110]; int count; I2AC400* items; int pad118; void* w; } S2AC400;
#define SFOLobbyList_GetSlot(a0, a1) ((int)SFOLobbyList_GetSlot((a0), (a1))) /* merge_units */
int GuiMissionList_GetAgentElemFromIndex(S2AC400* s, int i)
{
    if (!s->w || i < 0 || !(i < s->count))
        return 0;
    return SFOLobbyList_GetSlot(s->w, ((I2AC400*)((char*)s->items + i * sizeof(I2AC400)))->x4);
}
#undef SFOLobbyList_GetSlot /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002AC400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002AC400 */

/* merge_units: begin func_002AC470 */
#pragma push /* merge_units */
typedef struct { char pad0[0x248]; int f248; } U_002AC470;
extern U_002AC470* D_004FFC04;
extern unsigned char D_004FFBB5;
extern char g_Game[];
extern int g_OnlineMissionTable[];
extern const char* D_0048C160[];
extern void* cGameSystem_GetAgentData(void* list, int idx);
extern __int128 nGlobalization_MakeTag(const char* s);
extern int HasBonusLevel__10cAgentDataF1(void* agent, __int128 key);
extern unsigned char SFOLobby_CellContainsAgent(void* g, int id, int a);
extern unsigned char SFOLobby_ContactListContainsAgent(void* g, int id, int a);
int GuiMissionList_CanSelectAgent(S_002AC470* self, E_002AC470* e)
{
    void* g;
    unsigned char ok;
    int same;
    if (!e)
        return 0;
    g = cDME_GetLobby();
    if (!g)
        return 0;
    same = e->id == self->f120;
    ok = 0;
    switch (self->bAD) {
    case 0:
        if (!same && e->f24 == 2)
            ok = 1;
        break;
    case 1:
        ok = 1;
        break;
    case 3:
        if (!same)
            ok = 1;
        break;
    case 2:
        if ((self->bB5 && e->f24 == 1) || (e->f24 == 0 && e->f30 == 1)) {
            int k = e->f40;
            if (k >= 0 && k <= 16) {
                int cur = D_004FFC04->f248;
                if (cur == -1 || k == cur) {
                    if (D_004FFBB5) {
                        void* ag = cGameSystem_GetAgentData(g_Game, -1);
                        if (!HasBonusLevel__10cAgentDataF1(ag, nGlobalization_MakeTag(D_0048C160[g_OnlineMissionTable[k]])))
                            goto check;
                    }
                    if (e->f34 && e->f34 < e->f38) {
                        if (e->f44 == 2)
                            ok = SFOLobby_CellContainsAgent(g, e->id, 0);
                        else if (e->f44 == 1)
                            ok = SFOLobby_ContactListContainsAgent(g, e->id, 0);
                        else
                            ok = 1;
                    }
                }
            }
        }
    check:
        if (self->bBC && !self->bAC && !ok)
            return e->name[0] ? 2 : 6;
        break;
    }
    return ok ? 3 : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002AC470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002AC470 */

/* merge_units: begin func_002AC6F0 */
#pragma push /* merge_units */
typedef int (*Cmp_002AC6F0)(const void*, const void*);
extern S_002AC6F0* D_005065C0;
extern int GuiMissionList_Sort_DisplayGames(const void* a, const void* b);
extern int GuiMissionList_Sort_Agents(const void* a, const void* b);
extern int GuiMissionList_Sort_AgentNames(const void* a, const void* b);
extern int GuiMissionList_Sort_AgentGames(const void* a, const void* b);
extern void qsort(void* base, int n, int size, Cmp_002AC6F0 cmp);
#pragma opt_dead_assignments off
void GuiMissionList_SortSelectList(S_002AC6F0* self)
{
    Cmp_002AC6F0 cmp;
    if (!self->count || !self->p11C)
        return;
    cmp = 0;
    switch (self->bAC) {
    case 0:
        cmp = self->bBC ? 0 : GuiMissionList_Sort_DisplayGames;
        break;
    case 1:
        cmp = GuiMissionList_Sort_Agents;
        break;
    case 2:
        cmp = GuiMissionList_Sort_AgentNames;
        break;
    case 3:
        cmp = GuiMissionList_Sort_AgentGames;
        break;
    case 4:
        break;
    }
    if (cmp) {
        D_005065C0 = self;
        { int n = self->count; qsort(self->data, n, 12, cmp); }
    }
}


#pragma opt_dead_assignments reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002AC6F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002AC6F0 */

/* merge_units: begin func_002AC7E0 */
#pragma push /* merge_units */
typedef struct { int id; int idx; int fl; } It_002AC7E0;
typedef struct { char pad0[0x11C]; void* p11C; } S_002AC7E0;
typedef struct {
    int f0; char name[0x20]; int f24; char pad28[0x34 - 0x28]; int f34; int f38;
} E_002AC7E0;
#if 0 /* merge_units */
extern S_002AC7E0* D_005065C0;
#endif /* merge_units */
#define D_005065C0 (*(S_002AC7E0 **)&D_005065C0) /* merge_units */

#define SFOLobbyList_GetSlot(a0, a1) ((E_002AC7E0 *)SFOLobbyList_GetSlot((a0), (a1))) /* merge_units */
int GuiMissionList_Sort_AgentGames(const void* a, const void* b)
{
    E_002AC7E0* e1 = SFOLobbyList_GetSlot(D_005065C0->p11C, ((It_002AC7E0*)a)->idx);
    E_002AC7E0* e2 = SFOLobbyList_GetSlot(D_005065C0->p11C, ((It_002AC7E0*)b)->idx);
    int r1;
    int r2;
    if (!e1 || !e2)
        return 0;
    r2 = r1 = 3;
    if (e1->f24 == 0)
        r1 = 1;
    if (e2->f24 == 0)
        r2 = 1;
    if (e1->f24 == 1)
        r1 = 2;
    if (e2->f24 == 1)
        r2 = 2;
    if (r1 != r2)
        return r1 - r2;
    r1 += e1->f38 - 4;
    r2 += e2->f38 - 4;
    if (r1 != r2)
        return r1 - r2;
    r1 += e1->f34 - 4;
    r2 += e2->f34 - 4;
    if (r1 != r2)
        return r1 - r2;
    return strcmp(e1->name, e2->name);
}
#undef SFOLobbyList_GetSlot /* merge_units */
#undef D_005065C0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002AC7E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002AC7E0 */
