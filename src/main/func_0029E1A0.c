#pragma cplusplus on
#include "types.h"
struct Str_0029E1A0 { char d[0x10]; };
struct S_0029E1A0 { char pad0[0x48]; int f48; char pad4C[0x3C]; int f88; char pad8C[0x120 - 0x8C]; int f120; };
extern "C" {
extern void* D_004FFC04;
extern unsigned char D_0051EEB0;
extern char D_004AABF0[];
void func_0033D310(S_0029E1A0* self);
void func_002C82F0(void* ui);
void func_002C9AA0(void* ui);
void* func_004294C0(void);
int func_002CA710(void* ui);
char* func_0033CE30(S_0029E1A0* self, int a, int b, int c, int d, int e);
void String_CtorCStr_13B480(Str_0029E1A0* s, const char* c);
char* String_CStr(Str_0029E1A0* s);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, S_0029E1A0* d, int e);
void func_002C9AF0(void* ui, int a);
void FrontEnd_ClosePopup(void* ui, int id);
void func_002C81D0(void* ui);
void func_00138B70(Str_0029E1A0* s, int flags);
void func_0029D120(S_0029E1A0* self);
void func_0029DE70(S_0029E1A0* self, int a);
void func_002CA350(void* ui);
void func_00445570(void* g);
int func_004456D0(void* g);
void func_004456C0(void* g);
void func_0029DFC0(S_0029E1A0* self);
}
extern "C" void func_0029E1A0(S_0029E1A0* self)
{
    func_0033D310(self);
    if (D_0051EEB0)
        return;
    if (!self->f88) {
        func_002C82F0(D_004FFC04);
        self->f88 = 2;
    }
    if (self->f88 == 2) {
        func_002C9AA0(D_004FFC04);
        if (!func_004294C0() && !func_002CA710(D_004FFC04)) {
            Str_0029E1A0 a;
            Str_0029E1A0 b;
            self->f88 = 4;
            String_CtorCStr_13B480(&a, func_0033CE30(self, 1, 0, 0, 0, 0));
            String_CtorCStr_13B480(&b, func_0033CE30(self, 4, 0, 0, 0, 0));
            {
                char* tb = String_CStr(&b);
                FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a), tb, self, 0);
            }
            func_002C9AF0(D_004FFC04, 0);
            FrontEnd_ClosePopup(D_004FFC04, self->f48);
            func_002C81D0(D_004FFC04);
            func_00138B70(&b, 0);
            func_00138B70(&a, 0);
            return;
        }
        func_0029D120(self);
        func_002C81D0(D_004FFC04);
        FrontEnd_ClosePopup(D_004FFC04, self->f48);
        func_002C9AF0(D_004FFC04, 0);
    }
    if (self->f88 == 7) {
        unsigned char done;
        void* g = func_004294C0();
        if (!g) {
            func_0029DE70(self, 1);
            done = 0;
        } else {
            void* ui = D_004FFC04;
            int h = FrontEnd_OpenPopup(ui, 0, D_004AABF0, func_0033CE30(self, 0xD, 0, 0, 0, 0), 0, 0);
            if (self->f120 != -1)
                FrontEnd_ClosePopup(D_004FFC04, self->f120);
            func_002CA350(D_004FFC04);
            func_00445570(g);
            if (func_004456D0(g))
                func_004456C0(g);
            FrontEnd_ClosePopup(D_004FFC04, h);
            done = 1;
        }
        if (done)
            func_0029DFC0(self);
    }
}