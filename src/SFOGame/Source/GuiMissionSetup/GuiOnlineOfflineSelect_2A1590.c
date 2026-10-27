/*
 * main/GuiOnlineOfflineSelect: 2 files, 002A1590-002A1600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A1590 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0x40]; void* list; } Owner40;
typedef struct { char pad[0xDC]; void* widget; char padE0[0xF4 - 0xE0]; Owner40* owner; } Obj2A;
extern void* GetNext(void* list, int a1, int a2, void* item);
extern void GuiMissionSetup_UpdateTextLabels(Obj2A* self);
extern void* Gui_Canvas(void);
extern void GuiWidget_SendMessage(void* widget, void* ctx, int a2, int a3, int a4);

/* Adds item to the owner's list, refreshes self and pokes the widget with event 0x10. */
void GuiMissionSetup_CycleNumAgents(Obj2A* self, void* item)
{
    self->owner->list = GetNext(self->owner->list, 2, 4, item);
    GuiMissionSetup_UpdateTextLabels(self);
    GuiWidget_SendMessage(self->widget, Gui_Canvas(), 0x10, 0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_002A1590 */

/* merge_units: begin func_002A1600 */
#pragma push /* merge_units */
typedef struct State2A1 {
    char pad[0x45];
    unsigned char mode;
} State2A1;

typedef struct Obj2A1 {
    char pad[0xE0];
    int target;
    char pad2[0x10];
    State2A1* state;
} Obj2A1;

#if 0 /* merge_units */
extern int GetNext(int mode, int a, int b, int c);
#endif /* merge_units */
#define GetNext(a0, a1, a2, a3) ((int)GetNext((void *)(a0), (a1), (a2), (void *)(a3))) /* merge_units */

#if 0 /* merge_units */
extern void GuiMissionSetup_UpdateTextLabels(Obj2A1* self);
#endif /* merge_units */
#define GuiMissionSetup_UpdateTextLabels(a0) (GuiMissionSetup_UpdateTextLabels((Obj2A *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((int)Gui_Canvas()) /* merge_units */

#if 0 /* merge_units */
extern void GuiWidget_SendMessage(int target, int value, int a, int b, int c);
#endif /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) (GuiWidget_SendMessage((void *)(a0), (void *)(a1), (a2), (a3), (a4))) /* merge_units */


/* Advances the state's mode byte, refreshes, then notifies the target. */
void GuiMissionSetup_CycleJoinFilter(Obj2A1* self, int arg) {
    self->state->mode = GetNext(self->state->mode, 0, 2, arg);
    GuiMissionSetup_UpdateTextLabels(self);
    GuiWidget_SendMessage(self->target, Gui_Canvas(), 0x10, 0, 0);
}
#undef GetNext /* merge_units */
#undef GuiMissionSetup_UpdateTextLabels /* merge_units */
#undef Gui_Canvas /* merge_units */
#undef GuiWidget_SendMessage /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A1600 */
