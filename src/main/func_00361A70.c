/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo virtual (vtable D_004DF350 slot 2); calls the GuiWidget
 * implementation func_0041F090, then func_002C9C80(D_004FFC04, 0).
 */

#include "loose03_types.h"

extern int D_004FFC04;
extern int func_002C9C80(int, int);
extern int func_0041F090(GuiAgentInfo*);

int func_00361A70(GuiAgentInfo* self) {
    func_0041F090(self);
    return func_002C9C80(D_004FFC04, 0);
}
