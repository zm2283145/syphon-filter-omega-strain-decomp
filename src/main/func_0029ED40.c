#pragma cplusplus on
#include "types.h"
struct Str_0029ED40 { char d[0x10]; };
struct Ui_0029ED40 { char pad[0x2A]; unsigned char b2A; char pad2B[0x265 - 0x2B]; unsigned char b265; };
struct Ag_0029ED40 { char pad[0x9A0]; int f9A0; };
struct G_0029ED40 { char pad[0x68]; int f68; };
struct S_0029ED40 {
    char pad0[0x10]; int f10; char pad14[0x34]; int f48; char pad4C[0x3C]; int f88; float f8C; char pad90[4]; unsigned char b94;
};
extern "C" {
extern Ui_0029ED40* D_004FFC04;
extern char D_004AABF0[];
extern char D_004FFB50[];
extern char D_0055A830[];
void func_0033D3A0(void);
void func_0040D5D0(void* p);
void func_0029CBB0(S_0029ED40* self, int a);
char* func_0033CE30(S_0029ED40* self, int a, int b, int c, int d, int e);
int func_002CAE30(void* ui, int a, char* b, char* c, S_0029ED40* d, int e);
Ag_0029ED40* Agent_GetSelected(void* mgr, int idx);
void String_CtorCStr_13B480(Str_0029ED40* s, const char* c);
char* func_001692D0(Str_0029ED40* s);
void func_00138B70(Str_0029ED40* s, int flags);
G_0029ED40* func_004147A0(void);
}
extern "C" void func_0029ED40(S_0029ED40* self)
{
    func_0033D3A0();
    D_004FFC04->b2A = 0;
    func_0040D5D0(D_0055A830);
    self->b94 = 0;
    func_0029CBB0(self, 4);
    if (self->f10 == 1)
        self->f88 = 6;
    else
        self->f88 = 0;
    if (self->f88 == 0) {
        void* ui = D_004FFC04;
        self->f48 = func_002CAE30(ui, 0, D_004AABF0, func_0033CE30(self, 0, 0, 0, 0, 0), 0, 0);
        self->f8C = 15.0f;
        func_0029CBB0(self, 4);
        D_004FFC04->b265 = Agent_GetSelected(D_004FFB50, -1)->f9A0 == -1;
    } else if (Agent_GetSelected(D_004FFB50, -1)->f9A0 == -1) {
        Str_0029ED40 a;
        Str_0029ED40 b;
        String_CtorCStr_13B480(&a, func_0033CE30(self, 3, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, func_0033CE30(self, 0x84, 0, 0, 0, 0));
        {
            char* tb = func_001692D0(&b);
            func_002CAE30(D_004FFC04, 2, func_001692D0(&a), tb, self, 0);
        }
        self->f88 = 4;
        func_00138B70(&b, 0);
        func_00138B70(&a, 0);
    } else {
        self->f88 = 7;
    }
    func_004147A0()->f68 |= 0xC;
}
