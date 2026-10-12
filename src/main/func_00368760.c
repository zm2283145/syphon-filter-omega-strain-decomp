#include "types.h"
typedef struct { char pad[0xD4]; float time; char padD8[0xB71 - 0xD8]; unsigned char flagB71; } AgentT;
typedef struct { char pad[0x64]; int a64; char pad68[0x70 - 0x68]; void* text; void* text2; char pad78[0x89 - 0x78]; unsigned char useTimer; } S368620;
extern AgentT* Agent_GetSelected(void* list, int idx);
extern float func_00245890(int id);
extern void func_00367D60(S368620* self);
extern void func_0041BEB0(void* text, char* str, int flag);
extern void func_0041C070(void* text, void* color);
extern void func_0041EFA0(S368620* self);
extern void func_00367B20(S368620* self, int a, int b);
extern int sprintf(char* buf, const char* fmt, ...);
extern char D_004BBC48[];
extern char D_004FFB50[];
extern int D_004FFC2C;
extern char D_00587D00[];
extern char D_00587D10[];

void func_00368760(S368620* self) {
    char buf[32];
    float f;

    func_0041EFA0(self);
    if (self->text != 0) {
        if (self->useTimer) {
            f = func_00245890(D_004FFC2C);
        } else {
            f = Agent_GetSelected(D_004FFB50, -1)->time;
            asm { .set reorder } /* scheduling barrier: keeps cvt at the join, not in the b delay slot */
        }
        { int t = f; int m = t / 60; sprintf(buf, D_004BBC48, m, t - m * 60); }
        if (!self->useTimer) {
            if (Agent_GetSelected(D_004FFB50, -1)->flagB71) {
                func_0041C070(self->text, D_00587D00);
                func_0041C070(self->text2, D_00587D00);
            } else {
                func_0041C070(self->text, D_00587D10);
                func_0041C070(self->text2, D_00587D10);
            }
        }
        func_0041BEB0(self->text, buf, 0);
    }
    func_00367D60(self);
    func_00367B20(self, 0, !self->a64);
}

