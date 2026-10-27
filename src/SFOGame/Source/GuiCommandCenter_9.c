/*
 * SFOGame/Source/GuiCommandCenter: 2 files, 00296A80-00296B70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiCommandCenter_296A80 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x88]; int h; } F296A80_Obj;
extern int GuiWidget_SendMessage(void* o, int a, int b, int c, int d);
extern int Gui_Canvas(void);
void GuiCommandCenter_UpdateBackground(F296A80_Obj* o, float t) {
    float tab[11] = { 34.0f, 159.0f, 280.0f, 397.0f, 509.0f, 621.0f, 723.0f, 824.0f, 928.0f, 1009.0f, 1108.0f };
    if (o->h != 0) {
        float cur = 0.0f;
        int i;
        GuiWidget_SendMessage(o, o->h, 9, (int)&cur, 0);
        for (i = 0; i < 11; i++) {
            if (cur < tab[i] && !(cur + t < tab[i])) {
                GuiWidget_SendMessage(o, Gui_Canvas(), 16, 8, 0);
                return;
            }
        }
    }
}
static inline void merge_flush_GuiCommandCenter_296A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiCommandCenter_296A80 */

/* merge_units: begin func_00296B70 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[4]; char* name; unsigned char kind; char pad9[3]; int a; int b; int c; int d; } Item_96B70;
typedef struct { char pad[8]; unsigned char kind; char pad9[0xB]; } Row_96B70;
typedef struct { char pad[0x14]; unsigned short flags; } W_96B70;
typedef struct { char pad[0x190]; W_96B70* panel; void* list; } Scr_96B70;
struct Rows_96B70;
struct AwardVec_96B70;
extern "C" {
extern char g_Game[];
extern char D_004AA200[];
extern void func_00296FA0(Rows_96B70*);
extern void func_00299360(Rows_96B70*, int);
extern void func_00296F20(AwardVec_96B70*);
extern void std_vector_deleter_tRequirementInfo_dtor(AwardVec_96B70*, int);
extern void* cGameSystem_GetAgentData(char*, int);
extern void cAgentData_GetAchievements(void*, int, Rows_96B70*);
extern void cAgentData_GetRequirements(void*, int, int, AwardVec_96B70*);
extern void GuiTextListWidget_Clear(void*);
extern char* nGlobalization_GetString_charP(char*);
extern void Libc_Strcpy(char*, char*);
extern void GuiTextListWidget_AddItem(void*, char*, int, int);
void GuiCommandCenter_DisplayBonusMissionInfo(Scr_96B70* s, int idx);
}
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
struct Rows_96B70 {
    int x0; int count; Row_96B70* data; unsigned char owns;
    Rows_96B70() { func_00296FA0(this); owns = 1; }
    /* out-of-line copy is weak and dropped at link (as include/alloc_guard.h) */
    __declspec(weak) __declspec(DROPDTOR) ~Rows_96B70() { func_00299360(this, 0); }
};
struct AwardVec_96B70 {
    int x0; int count; Item_96B70* data; unsigned char owns;
    AwardVec_96B70() { func_00296F20(this); owns = 1; }
    int Count() const { return count; }
    /* out-of-line copy is weak and dropped at link (as include/alloc_guard.h) */
    __declspec(weak) __declspec(DROPDTOR) ~AwardVec_96B70() { std_vector_deleter_tRequirementInfo_dtor(this, 0); }
};
#pragma opt_strength_reduction off
void GuiCommandCenter_DisplayBonusMissionInfo(Scr_96B70* s, int idx)
{
    if (!s->panel || !s->list) return;
    if (idx == -1) {
        s->panel->flags &= ~2;
        return;
    }
    {
        void* agent = cGameSystem_GetAgentData(g_Game, -1);
        Rows_96B70 rows;
        cAgentData_GetAchievements(agent, 3, &rows);
        if (((Row_96B70*)((char*)rows.data + idx * (int)sizeof(Row_96B70)))->kind == 1) {
            s->panel->flags &= ~2;
        } else {
            s->panel->flags |= 2;
            GuiTextListWidget_Clear(s->list);
            {
                AwardVec_96B70 v;
                int i;
                cAgentData_GetRequirements(agent, 3, idx, &v);
                for (i = 0; i < v.Count(); i++) {
                    char buf[0x80];
                    int c = 2;
                    Item_96B70* it = (Item_96B70*)((char*)v.data + i * (int)sizeof(Item_96B70));
                    switch (it->kind) {
                    case 0: c = 2; break;
                    case 1: c = 1; break;
                    case 2: c = 0; break;
                    }
                    Libc_Strcpy(buf, nGlobalization_GetString_charP(it->kind == 0 ? D_004AA200 : it->name));
                    GuiTextListWidget_AddItem(s->list, buf, i, c);
                }
            }
        }
    }
}
static inline void merge_flush_func_00296B70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00296B70 */
