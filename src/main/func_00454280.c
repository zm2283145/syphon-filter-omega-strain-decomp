#pragma opt_strength_reduction off
enum OnOff { ON0, ON1 };
typedef struct Item { unsigned char flag; char name[0x20]; } Item;
typedef struct List { int pad0; int count; Item* items; } List;
typedef struct Box { char pad[0x94]; unsigned int size; } Box;
typedef struct Self { char pad[0x48]; Box* box; } Self;
extern List* g_Hud;
extern void GuiArrayWidget_GetSelected(Box*, int*, unsigned int*);
extern void GuiTextListWidget_Clear(Box*);
extern void GuiTextListWidget_AddItem(Box*, char*, int, int);
extern void GuiArrayWidget_SetSelected(Box*, int, unsigned int);
extern char* nGlobalization_GetString_charP(char*);
void GuiRadioLog_UpdateRadioLogList(Self* self)
{
    int a;
    unsigned int b;
    List* l;
    int i;
    if (self->box == 0) return;
    GuiArrayWidget_GetSelected(self->box, &a, &b);
    l = g_Hud;
    if (l == 0) return;
    GuiTextListWidget_Clear(self->box);
    for (i = 0; i < l->count; i++) {
        char* t = nGlobalization_GetString_charP(l->items[i].name);
        GuiTextListWidget_AddItem(self->box, t ? t : l->items[i].name, 0, l->items[i].flag ? ON1 : ON0);
    }
    if (b < self->box->size) GuiArrayWidget_SetSelected(self->box, 0, b);
}



