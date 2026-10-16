#include "types.h"
typedef struct { char pad[0xD4]; float time; char padD8[0xB71 - 0xD8]; unsigned char flagB71; } AgentT;
typedef struct { char pad[0x64]; int a64; char pad68[0x70 - 0x68]; void* text; void* text2; char pad78[0x89 - 0x78]; unsigned char useTimer; } S368620;
extern AgentT* Agent_GetSelected(void* list, int idx);
extern float Hud_GetMissionTime(int id);
extern void GuiObjectives_FillList(S368620* self);
extern void GuiTextWidget_SetText(void* text, char* str, int flag);
extern void GuiTextWidget_SetColour(void* text, void* color);
extern void func_0041EFA0(S368620* self);
extern void func_00367B20(S368620* self, int a, int b);
extern int sprintf(char* buf, const char* fmt, ...);
extern char D_004BBC48[];
extern char D_004FFB50[];
extern int D_004FFC2C;
extern char D_00587D00[];
extern char D_00587D10[];

void GuiObjectives_Wake(S368620* self) {
    char buf[32];
    float f;

    func_0041EFA0(self);
    if (self->text != 0) {
        if (self->useTimer) {
            f = Hud_GetMissionTime(D_004FFC2C);
        } else {
            f = Agent_GetSelected(D_004FFB50, -1)->time;
            asm { .set reorder } /* scheduling barrier: keeps cvt at the join, not in the b delay slot */
        }
        { int t = f; int m = t / 60; sprintf(buf, D_004BBC48, m, t - m * 60); }
        if (!self->useTimer) {
            if (Agent_GetSelected(D_004FFB50, -1)->flagB71) {
                GuiTextWidget_SetColour(self->text, D_00587D00);
                GuiTextWidget_SetColour(self->text2, D_00587D00);
            } else {
                GuiTextWidget_SetColour(self->text, D_00587D10);
                GuiTextWidget_SetColour(self->text2, D_00587D10);
            }
        }
        GuiTextWidget_SetText(self->text, buf, 0);
    }
    GuiObjectives_FillList(self);
    func_00367B20(self, 0, !self->a64);
}

