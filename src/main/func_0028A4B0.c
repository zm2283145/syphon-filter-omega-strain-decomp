#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } W;
typedef struct { char pad0[0x10]; int state; char pad14[0x8C - 0x14]; W* p8C; int pad90; W* p94; int pad98; char* p9C; char padA0[4]; unsigned char bA4; } S;
extern char D_00506340[];
extern char D_00506350[];
extern unsigned char D_00506360;
char* AgentData_GetName(char* a);
void GuiScreen_Wake(S* s);
void func_0041BEB0(W* w, char* s, int a);
void func_0028A4B0(S* self)
{
    if (self->state == 1) {
        if (self->p8C) {
            self->p8C->flags &= ~4;
            func_0041BEB0(self->p8C, D_00506350, 0);
        }
        if (self->p94) {
            self->p94->flags &= ~4;
            func_0041BEB0(self->p94, D_00506340, 0);
        }
        self->bA4 = D_00506360;
        self->state = -1;
    } else {
        if (self->p8C) {
            self->p8C->flags &= ~4;
            func_0041BEB0(self->p8C, AgentData_GetName(self->p9C), 0);
        }
        if (self->p94) {
            self->p94->flags &= ~4;
            func_0041BEB0(self->p94, self->p9C + 0x8CC, 0);
        }
        self->bA4 = 0;
    }
    GuiScreen_Wake(self);
}
