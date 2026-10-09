/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiGameScreen_types.h"

extern void* GObj_IdentityB(void* obj);
extern int Global_ClearInteract(void* obj);
extern void Global_DisplayInteract(int text, int flag);
extern int Global_DisplayInteract_2(void* obj, int text, int flag);
extern void func_0045EC60(void);

/* Script native: ClearInteract(obj). */
int Script_ClearInteract_2(ScriptArg* args) {
    Global_ClearInteract(GObj_IdentityB(args[0].p));
    return 0;
}

/* Script native: ClearInteract(). */
int Script_ClearInteract(void) {
    func_0045EC60();
    return 0;
}

/* Script native: DisplayInteract(obj, text, flag). */
int Script_DisplayInteract_4(ScriptArg* args) {
    int text[1];
    int flag = (unsigned char)args[2].i;

    text[0] = args[1].i;
    Global_DisplayInteract_2(GObj_IdentityB(args[0].p), STACK_COPY(text), flag);
    return 0;
}

/* Script native: DisplayInteract(obj, text). */
int Script_DisplayInteract_3(ScriptArg* args) {
    int text[1];

    text[0] = args[1].i;
    Global_DisplayInteract_2(GObj_IdentityB(args[0].p), STACK_COPY(text), 1);
    return 0;
}

/* Script native: DisplayInteract(text, flag). */
int Script_DisplayInteract_2(ScriptArg* args) {
    int text[1];
    int flag = (unsigned char)args[1].i;

    text[0] = args[0].i;
    Global_DisplayInteract(STACK_COPY(text), flag);
    return 0;
}

/* Script native: DisplayInteract(text). */
int Script_DisplayInteract(ScriptArg* args) {
    int text[1];

    text[0] = args[0].i;
    Global_DisplayInteract(STACK_COPY(text), 1);
    return 0;
}
