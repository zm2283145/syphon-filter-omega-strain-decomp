/*
 * main/GuiGameScreen: range (2 files, 0045E540-0045E5F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "GuiGameScreen_types.h"

/* merge_units: begin func_0045E540 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char flag; char padD[3]; } List0045E540;
typedef struct {
    void* vtable;
    char pad4[0x50];
    unsigned char b54, b55;
    char pad56[2];
    int unk58, unk5C, unk60;
    unsigned char b64;
    char pad65[0xB];
    List0045E540 listA;
    List0045E540 listB;
    char pad90[0x48];
    int unkD8;
    int padDC;
    int unkE0, unkE4, unkE8, unkEC;
} Widget0045E540;
extern char D_004E1620[];
extern void GuiWidget_ctor(Widget0045E540* w);
extern void std_vector_int_ctor_void(List0045E540* list);
extern void std_vector_pod_int_reserve(List0045E540* list, int n);
/* Constructor. */
Widget0045E540* GuiGameScreen_ctor(Widget0045E540* w)
{
    List0045E540* b;
    List0045E540* a;
    GuiWidget_ctor(w);
    w->vtable = D_004E1620;
    w->unk58 = 0;
    w->unk5C = 0;
    w->unk60 = 0;
    a = &w->listA;
    std_vector_int_ctor_void(a);
    a->flag = 1;
    b = &w->listB;
    std_vector_int_ctor_void(b);
    b->flag = 1;
    w->b55 = 0;
    w->b54 = 0;
    w->b64 = 1;
    w->unkE0 = 0;
    w->unkE4 = 0;
    w->unkE8 = 0;
    w->unkEC = 0;
    std_vector_pod_int_reserve(b, 8);
    std_vector_pod_int_reserve(a, 8);
    w->unkD8 = 0;
    return w;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045E540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045E540 */

/* merge_units: begin func_0045E5F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */


extern void* cGOBJ_SOBJ_convert(void* obj);
extern int ClearInteract_cGOBJP(void* obj);
extern void DisplayInteract_charP_eJoystickButton(int text, int flag);
extern int DisplayInteract_cGOBJP_charP_eJoystickButton(void* obj, int text, int flag);
extern void ClearInteract_void(void);

/* Script native: ClearInteract(obj). */
int Script_ClearInteract_2(ScriptArg* args) {
    ClearInteract_cGOBJP(cGOBJ_SOBJ_convert(args[0].p));
    return 0;
}

/* Script native: ClearInteract(). */
int Script_ClearInteract(void) {
    ClearInteract_void();
    return 0;
}

/* Script native: DisplayInteract(obj, text, flag). */
int Script_DisplayInteract_4(ScriptArg* args) {
    int text[1];
    int flag = (unsigned char)args[2].i;

    text[0] = args[1].i;
    DisplayInteract_cGOBJP_charP_eJoystickButton(cGOBJ_SOBJ_convert(args[0].p), STACK_COPY(text), flag);
    return 0;
}

/* Script native: DisplayInteract(obj, text). */
int Script_DisplayInteract_3(ScriptArg* args) {
    int text[1];

    text[0] = args[1].i;
    DisplayInteract_cGOBJP_charP_eJoystickButton(cGOBJ_SOBJ_convert(args[0].p), STACK_COPY(text), 1);
    return 0;
}

/* Script native: DisplayInteract(text, flag). */
int Script_DisplayInteract_2(ScriptArg* args) {
    int text[1];
    int flag = (unsigned char)args[1].i;

    text[0] = args[0].i;
    DisplayInteract_charP_eJoystickButton(STACK_COPY(text), flag);
    return 0;
}

/* Script native: DisplayInteract(text). */
int Script_DisplayInteract(ScriptArg* args) {
    int text[1];

    text[0] = args[0].i;
    DisplayInteract_charP_eJoystickButton(STACK_COPY(text), 1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045E5F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045E5F0 */
