#pragma cplusplus on

#include "types.h"
#include "label_text_refresh.h"

struct L367D60 {
    char pad[0x34];
    float x;
    char pad38[0x3C - 0x38];
    float w;
    float h;
    char pad44[0x5C - 0x44];
    unsigned int rowH;
    char pad60[0x94 - 0x60];
    int count;
};
struct O367D60 { char pad[0x20]; int a20; char pad24[0x60 - 0x24]; int a60; };
struct S367D60 {
    char pad[0x48];
    void* lists[3];
    L367D60* list;
    char pad58[0x5C - 0x58];
    int sel;
    char pad60[0x78 - 0x60];
    int top;
    int minH;
    L367D60* w80;
    int a84;
    unsigned char b88;
};

extern "C" {
extern char D_004BBC70[];
extern char D_004BBC80[];
void* ObjMan_GetService(void);
int cObjectiveMan_GetObjectiveCount(void* mgr);
int cObjectiveMan_GetFailedObjectives(void* mgr, O367D60** out, int max);
int cObjectiveMan_GetSucceededObjectives(void* mgr, O367D60** out, int max, unsigned char flag);
int cObjectiveMan_GetParameters(void* mgr, O367D60** out, int max);
int cObjectiveMan_GetCurrentObjectives(void* mgr, O367D60** out, int max);
void GuiTextListWidget_Clear(void* list);
void GuiTextListWidget_AddItem(void* list, int a, int b, int c);
int GuiTextListWidget_FindItem_int(void* list, int sel);
void GuiArrayWidget_SetSelected(void* list, int a, int b);
void GuiWidget_SetPosition(L367D60* w, float x, float y);
void GuiArrayWidget_SetVisibleSize(L367D60* w, int a, int b);
int sprintf(char* buf, const char* fmt, ...);
}

static inline void SetSize(L367D60* w, float ww, float hh)
{
    w->w = ww;
    w->h = hh;
}

/* Refresh the object list tabs and resize the list widget to its rows. */
extern "C" void GuiObjectives_UpdateObjectives(S367D60* self)
{
    void* mgr;
    char buf[0x20];
    O367D60* tmp[0x14];
    O367D60* objs[0x20];
    int sel;
    int i;

    mgr = ObjMan_GetService();
    if (mgr == 0) return;
    {
        LtrWidget* w = Ltr_Cast(GuiWidget_FindChild_charP(self, D_004BBC70));
        if (w) {
            int n = cObjectiveMan_GetSucceededObjectives(mgr, tmp, 0x14, 1);
            sprintf(buf, D_004BBC80, n, cObjectiveMan_GetObjectiveCount(mgr));
            GuiTextWidget_SetText(w, buf, 0);
        }
    }
    sel = self->sel;
    for (i = 0; i < 4; i++) {
        if (self->lists[i] != 0) {
            int n;
            int j;
            switch (i) {
            case 0: n = cObjectiveMan_GetCurrentObjectives(mgr, objs, 0x20); break;
            case 1: n = cObjectiveMan_GetParameters(mgr, objs, 0x20); break;
            case 2: n = cObjectiveMan_GetSucceededObjectives(mgr, objs, 0x20, self->b88); break;
            case 3: n = cObjectiveMan_GetFailedObjectives(mgr, objs, 0x20); break;
            default: return;
            }
            GuiTextListWidget_Clear(self->lists[i]);
            for (j = 0; j < n; j++) {
                if (objs[j]->a60 != 0)
                    GuiTextListWidget_AddItem(self->lists[i], objs[j]->a60, objs[j]->a20, 0);
            }
        }
    }
    if (self->lists[0] != 0 && sel != -1) {
        int idx = GuiTextListWidget_FindItem_int(self->lists[0], sel);
        if (idx != -1) GuiArrayWidget_SetSelected(self->lists[0], 0, idx);
    }
    {
        L367D60* l = self->list;
        if (l != 0) {
            int count;
            unsigned int rowH;
            int rows;
            rowH = l->rowH;
            count = l->count;
            rows = l->h / (float)rowH;
            if (rows != count) {
                int total = count * rowH;
                int y = self->top + (total - self->minH);
                if (total < self->minH) {
                    total = self->minH;
                    y = self->top;
                }
                GuiWidget_SetPosition(l, l->x, (float)y);
                SetSize(self->list, self->list->w, (float)total);
                if (self->w80 != 0)
                    GuiWidget_SetPosition(self->w80, self->w80->x, (float)(y + self->a84));
            }
            GuiArrayWidget_SetVisibleSize(self->list, 1, self->list->count);
        }
    }
}
