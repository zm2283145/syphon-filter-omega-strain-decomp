/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo virtual (vtable D_004DF350 slot 2); calls the GuiWidget
 * implementation GuiWidget_Deinit, then func_002C9C80(D_004FFC04, 0).
 */

#include "loose03_types.h"

extern int D_004FFC04;
extern int func_002C9C80(int, int);
extern int GuiWidget_Deinit(GuiAgentInfo*);

int func_00361A70(GuiAgentInfo* self) {
    GuiWidget_Deinit(self);
    return func_002C9C80(D_004FFC04, 0);
}
