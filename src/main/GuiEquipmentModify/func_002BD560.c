/* GuiEquipmentModify_onMessage: equipment-modify screen events (slot pick, window preload, back,
 * category buttons, quit). */
#include "types.h"

typedef struct { char p0[0x14]; unsigned short flags; } W_D560;
typedef struct { char p0[4]; char name[0x34]; float f38; } Wid_D560;
typedef struct { char p0[0x2410]; int slots[10]; char p2438[0x247C - 0x2438]; int x247C; int x2480; } EqSub_D560;
typedef struct { char p0[0x60]; EqSub_D560 eq; } Eq_D560;
typedef struct { char p0[0x13C]; int value; } Weapon_D560;
typedef struct {
    char p0[0x48];
    Eq_D560* src;           /* +0x48 */
    Eq_D560* dst;           /* +0x4C */
    char p50[0x84 - 0x50];
    int mode;               /* +0x84 */
    int cat;                /* +0x88 */
    int active;             /* +0x8C */
    char p90[0x94 - 0x90];
    void* list;             /* +0x94 */
    char p98[0xA0 - 0x98];
    int scroll;             /* +0xA0 */
    char pA4[0xCC - 0xA4];
    W_D560* wCC;            /* +0xCC */
    char pD0[0xFC - 0xD0];
    int curSlot;            /* +0xFC */
    int prevSlot;           /* +0x100 */
    int count;              /* +0x104 */
    int sel;                /* +0x108 */
    short items[0x400];     /* +0x10C */
    short selByCat[16];     /* +0x90C */
} Self_D560;

extern void* g_WeaponDatabase;
extern char g_Game[];
extern char D_004AC2F0[], D_004AC300[], D_004AC310[], D_004AC320[], D_004AC330[], D_004AC340[], D_004AC350[], D_004AC360[];

extern char* std_basic_string_char_char_traits_char_c_str(void* str);
extern int String_CompareNoCase(char* a, char* b);
extern int strcmp(const char* a, const char* b);
extern Weapon_D560* cWeaponDB_GetEntry(void* table, int id);
extern void* cGameSystem_GetAgentData(void* a, int b);
extern int cAgentData_HasSpecialBonus(void* ag, int which);
extern void cMan_UpdateHandMorphs(EqSub_D560* e);
extern void GuiEquipmentModify_UpdateCurrent(Self_D560* self);
extern void GuiEquipmentModify_UpdateSelection(Self_D560* self);
extern void GuiEquipmentModify_UpdateSelectionList(Self_D560* self);
extern void GuiEquipmentModify_UpdateSelectionHand(Self_D560* self);
extern void GuiEquipmentModify_PrefetchQue(Self_D560* self, int n);
extern void GuiEquipmentModify_UpdateEmpty(Self_D560* self);
extern void GuiTextListWidget_Clear(void* l);
extern void* Gui_Canvas(void);
extern void GuiCanvas_SetFocus(void* ui, void* w);
extern void GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);
extern void GuiCanvas_Transition(void* a, void* b, void* c);
extern void cGameSystem_Restart(void* g, int how);
extern int GuiWidget_onMessage(Self_D560* self, Wid_D560* w, unsigned short msg, int a3, int param);

static inline EqSub_D560* GetEq_D560(Eq_D560* e) { return &e->eq; }

int GuiEquipmentModify_onMessage(Self_D560* self, Wid_D560* w, unsigned short msg, int a3, int param)
{
    char* name = std_basic_string_char_char_traits_char_c_str(w->name);
    if (msg == 0x13 && self->active) {
        int val;
        int c;
        self->sel = param;
        self->selByCat[self->cat] = param;
        val = 0;
        if (self->sel < self->count)
            val = cWeaponDB_GetEntry(g_WeaponDatabase, self->items[self->sel])->value;
        c = self->cat;
        if (c != 0 && c != self->curSlot) {
            self->dst->eq.slots[c] = val;
        } else if (c != 0) {
            self->dst->eq.slots[0] = val;
        } else {
            int i;
            Eq_D560* d = self->dst;
            EqSub_D560* e = &d->eq;
            int old = d->eq.slots[0];
            if (old)
                e->slots[self->curSlot] = old;
            for (i = 1; i < 10; i++) {
                if (i != 1 && i != 4 && i != 6 && i != 7 && val == GetEq_D560(self->dst)->slots[i])
                    self->curSlot = i;
            }
            self->dst->eq.slots[0] = val;
            if (val)
                self->dst->eq.slots[self->curSlot] = 0;
        }
        if (cAgentData_HasSpecialBonus(cGameSystem_GetAgentData(g_Game, -1), 1)) {
            if (self->curSlot == 3)
                self->dst->eq.slots[1] = self->dst->eq.slots[0];
            else
                self->dst->eq.slots[1] = 0;
            self->dst->eq.slots[4] = self->dst->eq.slots[3];
        }
        cMan_UpdateHandMorphs(&self->dst->eq);
        GuiEquipmentModify_UpdateCurrent(self);
        GuiWidget_SendMessage(w, Gui_Canvas(), 0x10, 1, 0);
    }
    if (msg == 0x14 && self->active) {
        self->sel = param;
        self->selByCat[self->cat] = param;
        GuiEquipmentModify_PrefetchQue(self, 3);
        GuiEquipmentModify_UpdateSelection(self);
    }
    if (msg == 0x10 && a3 == 1 && String_CompareNoCase(std_basic_string_char_char_traits_char_c_str(w->name), D_004AC350))
        return 1;
    if (msg == 2) {
        if (self->mode > 0) {
            self->active = 1;
            GuiCanvas_SetFocus(Gui_Canvas(), self->list);
            self->wCC->flags |= 2;
            self->wCC->flags |= 8;
            GuiWidget_SendMessage(self, w, 6, (int)D_004AC360, 0);
            GuiWidget_SendMessage(w, Gui_Canvas(), 0x10, 0, 0);
        } else if (!strcmp(name, D_004AC350)) {
            int i;
            for (i = 0; i < 10; i++)
                GetEq_D560(self->dst)->slots[i] = GetEq_D560(self->src)->slots[i];
            self->curSlot = self->prevSlot;
            GuiEquipmentModify_UpdateCurrent(self);
        }
    }
    if (msg == 0) {
        if (!strcmp(name, D_004AC2F0)) {
            self->mode = 1;
            self->cat = 2;
            self->sel = self->selByCat[self->cat];
            self->scroll = (int)w->f38;
            GuiEquipmentModify_UpdateSelectionList(self);
        }
        if (!strcmp(name, D_004AC300)) {
            self->mode = 2;
            self->cat = 3;
            self->sel = self->selByCat[self->cat];
            self->scroll = (int)w->f38;
            GuiEquipmentModify_UpdateSelectionList(self);
        }
        if (!strcmp(name, D_004AC310)) {
            self->mode = 3;
            self->cat = 5;
            self->sel = self->selByCat[self->cat];
            self->scroll = (int)w->f38;
            GuiEquipmentModify_UpdateSelectionList(self);
        }
        if (!strcmp(name, D_004AC320)) {
            self->mode = 4;
            self->cat = 8;
            self->sel = self->selByCat[self->cat];
            self->scroll = (int)w->f38;
            GuiEquipmentModify_UpdateSelectionList(self);
        }
        if (!strcmp(name, D_004AC330)) {
            self->mode = 5;
            self->cat = 9;
            self->sel = self->selByCat[self->cat];
            self->scroll = (int)w->f38;
            GuiEquipmentModify_UpdateSelectionList(self);
        }
        if (!strcmp(name, D_004AC340)) {
            self->mode = 6;
            self->cat = 0;
            self->sel = self->selByCat[self->cat];
            self->scroll = (int)w->f38;
            GuiEquipmentModify_UpdateSelectionHand(self);
        }
        if (!strcmp(name, D_004AC350)) {
            self->mode = 0;
            GuiEquipmentModify_UpdateEmpty(self);
            if (self->list)
                GuiTextListWidget_Clear(self->list);
        }
    }
    if (msg == 0x1A && a3 == 0) {
        GuiCanvas_Transition(Gui_Canvas(), self, 0);
        cGameSystem_Restart(g_Game, 3);
        return 1;
    }
    return GuiWidget_onMessage(self, w, msg, a3, param);
}
