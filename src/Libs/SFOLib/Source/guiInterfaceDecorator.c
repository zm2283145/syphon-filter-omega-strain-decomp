/*
 * Libs/SFOLib/Source/guiInterfaceDecorator: 1 file, 00416D10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin guiManager_416D10 */
#pragma push /* merge_units */
#include "types.h"

typedef struct E_416D10 { char name[0xC]; unsigned char kind; char pad[3]; int x; int y; } E_416D10;
typedef struct O_416D10 { char pad[0x24]; void* inst; char pad28[0x58]; E_416D10* cur; } O_416D10;

extern E_416D10* GuiInterfaceDecorator_FindEvent(O_416D10* o, char* name);
extern void cAnimator_SetFrame(void* i, float t);
extern void cAnimator_AnimateTo(void* i, float t);
extern void cAnimator_StartAnimation(void* i, float a, float b, int f);

int GuiInterfaceDecorator_StartAnimation(O_416D10* o, char* name)
{
    E_416D10* e;
    if (o->inst == 0) return 0;
    e = GuiInterfaceDecorator_FindEvent(o, name);
    if (e != 0) {
    switch (e->kind) {
    case 1:
        cAnimator_SetFrame(o->inst, e->x);
        cAnimator_AnimateTo(o->inst, e->y);
        break;
    case 2:
        cAnimator_SetFrame(o->inst, e->x);
        cAnimator_StartAnimation(o->inst, e->x, e->y, 1);
        break;
    case 3:
        cAnimator_SetFrame(o->inst, e->x);
        cAnimator_StartAnimation(o->inst, e->x, e->y, 0);
        break;
    }
    o->cur = e;
    return 1;
    }
    return 0;
}
static inline void merge_flush_guiManager_416D10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end guiManager_416D10 */
