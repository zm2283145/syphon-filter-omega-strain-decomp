#include "types.h"
/* GuiEquipmentModify_BuildCategoryList: collects the weapon ids of the
 * selected category: every weapon in the database (D_0051EE38 set),
 * otherwise the agent's unlocked weapons plus the screen's extra entries of
 * that category not already listed; then places the list widget and
 * rebuilds the columns. Layout and placement as in
 * GuiEquipmentModify_BuildEquipList (GuiEquipmentModify_BuildEquipList.c); id list as in
 * GuiEndGameStatistics_QueueVoices (GuiEndGameStatistics_QueueVoices.c). */
typedef struct { int a0; int n; int* data; unsigned char owned; char pad[3]; } IntVec_F090;
typedef struct { char pad[0x30]; unsigned char cls; } Wpn_F090;
typedef struct { int pad; int n; } WpnList_F090;
typedef struct { int pad; WpnList_F090* list; } WpnDb_F090;
typedef struct {
    char pad0[0x88];
    int cat;
    char pad8C[0x94 - 0x8C];
    void* list;
    int x;
    int total;
    int base;
    int step;
    int max;
    char padAC[0xD8 - 0xAC];
    int nExtra;
    short extra[10];
    unsigned char extraCat[20];
    int count;
    int sel;
    short ids[1];
} Self_F090;
extern char g_Game[];
extern WpnDb_F090* g_WeaponDatabase;
extern unsigned char D_0051EE38;
void* Agent_GetSelected(void* mgr, int idx);
void std_vector_int_ctor_void(IntVec_F090* v);
void func_0013A040(IntVec_F090* v, int flags);
void AgentData_GetUnlockedWeapons(void* agent, IntVec_F090* v);
Wpn_F090* WeaponDb_Get(WpnDb_F090* db, int id);
void GuiEquipmentModify_PreloadWindow(Self_F090* self, int f);
void GuiWidget_SetPos(void*, float, float);
void GuiEquipmentModify_BuildList(Self_F090*);
void GuiEquipmentModify_BuildCurrentColumn(Self_F090*);
void GuiEquipmentModify_BuildSelectionColumn(Self_F090*);

void GuiEquipmentModify_BuildCategoryList(Self_F090* self)
{
    int i;
    int lim;
    int off;
    int span;
    int q;
    int first;
    self->count = 0;
    if (!D_0051EE38) {
        void* a = Agent_GetSelected(g_Game, -1);
        IntVec_F090 list;
        int n;
        int j;
        std_vector_int_ctor_void(&list);
        list.owned = 1;
        AgentData_GetUnlockedWeapons(a, &list);
        n = list.n;
        for (j = 0; j < n; j++) {
            Wpn_F090* w = WeaponDb_Get(g_WeaponDatabase, list.data[(unsigned)j]);
            if (w->cls == self->cat) {
                self->ids[self->count] = list.data[(unsigned)j];
                self->count++;
            }
        }
        for (i = 0; i < self->nExtra; i++) {
            if (self->extraCat[i] == self->cat) {
                int found = 0;
                int k;
                for (k = 0; k < self->count; k++) {
                    if (self->ids[k] == self->extra[i]) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    self->ids[self->count] = self->extra[i];
                    self->count++;
                }
            }
        }
        func_0013A040(&list, -1);
    } else {
        int n = g_WeaponDatabase->list->n;
        for (i = 0; i < n; i++) {
            Wpn_F090* w = WeaponDb_Get(g_WeaponDatabase, i);
            if (w->cls == self->cat) {
                self->ids[self->count] = i;
                self->count++;
            }
        }
    }
    GuiEquipmentModify_PreloadWindow(self, 1);
    span = self->total - self->base;
    q = span / self->step;
    first = q - (self->count >> 1);
    off = span - q * self->step - 1;
    if (first < 0)
        first = 0;
    lim = self->max - self->count;
    if (lim < 0)
        lim = 0;
    if (lim < first)
        first = lim;
    GuiWidget_SetPos(self->list, (float)self->x, (float)(self->total - off - first * self->step));
    GuiEquipmentModify_BuildList(self);
    GuiEquipmentModify_BuildCurrentColumn(self);
    GuiEquipmentModify_BuildSelectionColumn(self);
}
