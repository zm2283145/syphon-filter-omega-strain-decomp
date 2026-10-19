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
extern void* GuiMissionSetup_WrapStep(void* list, int a1, int a2, void* item);
extern void GuiMissionSetup_UpdateTexts(Obj2A* self);
extern void* Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(void* widget, void* ctx, int a2, int a3, int a4);

/* Adds item to the owner's list, refreshes self and pokes the widget with event 0x10. */
void GuiMissionSetup_StepNumAgents(Obj2A* self, void* item)
{
    self->owner->list = GuiMissionSetup_WrapStep(self->owner->list, 2, 4, item);
    GuiMissionSetup_UpdateTexts(self);
    GuiWidget_SendEvent(self->widget, Gui_GetScreenStack(), 0x10, 0, 0);
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
extern int GuiMissionSetup_WrapStep(int mode, int a, int b, int c);
#endif /* merge_units */
#define GuiMissionSetup_WrapStep(a0, a1, a2, a3) ((int)GuiMissionSetup_WrapStep((void *)(a0), (a1), (a2), (void *)(a3))) /* merge_units */

#if 0 /* merge_units */
extern void GuiMissionSetup_UpdateTexts(Obj2A1* self);
#endif /* merge_units */
#define GuiMissionSetup_UpdateTexts(a0) (GuiMissionSetup_UpdateTexts((Obj2A *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((int)Gui_GetScreenStack()) /* merge_units */

#if 0 /* merge_units */
extern void GuiWidget_SendEvent(int target, int value, int a, int b, int c);
#endif /* merge_units */
#define GuiWidget_SendEvent(a0, a1, a2, a3, a4) (GuiWidget_SendEvent((void *)(a0), (void *)(a1), (a2), (a3), (a4))) /* merge_units */


/* Advances the state's mode byte, refreshes, then notifies the target. */
void GuiMissionSetup_StepJoinFilter(Obj2A1* self, int arg) {
    self->state->mode = GuiMissionSetup_WrapStep(self->state->mode, 0, 2, arg);
    GuiMissionSetup_UpdateTexts(self);
    GuiWidget_SendEvent(self->target, Gui_GetScreenStack(), 0x10, 0, 0);
}
#undef GuiMissionSetup_WrapStep /* merge_units */
#undef GuiMissionSetup_UpdateTexts /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#undef GuiWidget_SendEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A1600 */
