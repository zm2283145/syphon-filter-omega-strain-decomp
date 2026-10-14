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
extern void* func_002A1A50(void* list, int a1, int a2, void* item);
extern void func_002A1670(Obj2A* self);
extern void* Gui_GetScreenStack(void);
extern void func_0041E0F0(void* widget, void* ctx, int a2, int a3, int a4);

/* Adds item to the owner's list, refreshes self and pokes the widget with event 0x10. */
void func_002A1590(Obj2A* self, void* item)
{
    self->owner->list = func_002A1A50(self->owner->list, 2, 4, item);
    func_002A1670(self);
    func_0041E0F0(self->widget, Gui_GetScreenStack(), 0x10, 0, 0);
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
extern int func_002A1A50(int mode, int a, int b, int c);
#endif /* merge_units */
#define func_002A1A50(a0, a1, a2, a3) ((int)func_002A1A50((void *)(a0), (a1), (a2), (void *)(a3))) /* merge_units */

#if 0 /* merge_units */
extern void func_002A1670(Obj2A1* self);
#endif /* merge_units */
#define func_002A1670(a0) (func_002A1670((Obj2A *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((int)Gui_GetScreenStack()) /* merge_units */

#if 0 /* merge_units */
extern void func_0041E0F0(int target, int value, int a, int b, int c);
#endif /* merge_units */
#define func_0041E0F0(a0, a1, a2, a3, a4) (func_0041E0F0((void *)(a0), (void *)(a1), (a2), (a3), (a4))) /* merge_units */


/* Advances the state's mode byte, refreshes, then notifies the target. */
void func_002A1600(Obj2A1* self, int arg) {
    self->state->mode = func_002A1A50(self->state->mode, 0, 2, arg);
    func_002A1670(self);
    func_0041E0F0(self->target, Gui_GetScreenStack(), 0x10, 0, 0);
}
#undef func_002A1A50 /* merge_units */
#undef func_002A1670 /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#undef func_0041E0F0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A1600 */
