#pragma cplusplus on
#include "types.h"
struct Str_0029D120 { char d[0x10]; };
struct E_0029D120 { unsigned char b0; char pad1[0x33]; char name[4]; };
struct L_0029D120;
struct S_0029D120 {
    char pad0[0x88]; int f88; char pad8C[8]; unsigned char b94; char pad95[3]; char f98[4]; int f9C; char padA0[0x14];
    char fB4[0x1C]; char fD0[0x1C]; L_0029D120* pEC;
};
extern "C" {
extern void* D_004FFC04;
extern char D_004AABF0[];
void* func_004294C0(void);
void func_002CC260(void);
int func_0044C440(void* g, void* cb, void* a, void* b, void* c);
void func_00421070(L_0029D120* l);
E_0029D120* func_0044F290(void* v, int i);
void func_00421290(L_0029D120* l, char* s, int i, int a);
void func_00424430(L_0029D120* l, int a, int b);
void func_0029CBB0(S_0029D120* self, int a);
void func_0044C3C0(void* g);
unsigned char func_00452FF0(void* g, int a);
void func_002CA640(void* ui, int a);
char* func_0033CE30(S_0029D120* self, int a, int b, int c, int d, int e);
void String_CtorCStr_13B480(Str_0029D120* s, const char* c);
char* func_001692D0(Str_0029D120* s);
int func_002CAE30(void* ui, int a, char* b, char* c, S_0029D120* d, int e);
void func_00138B70(Str_0029D120* s, int flags);
}
extern "C" void func_0029D120(S_0029D120* self)
{
    void* g = func_004294C0();
    if (!g)
        return;
    if (func_0044C440(g, (void*)func_002CC260, self->f98, self->fB4, self->fD0)) {
        int sel;
        int i;
        self->b94 = 1;
        self->f88 = 5;
        func_00421070(self->pEC);
        sel = -1;
        for (i = 0; i < self->f9C; i++) {
            E_0029D120* e = func_0044F290(self->f98, i);
            func_00421290(self->pEC, e->name, i, 0);
            if (e->b0)
                sel = i;
        }
        if (sel != -1)
            func_00424430(self->pEC, 0, sel);
        func_0029CBB0(self, 0);
    } else {
        unsigned char r;
        func_0044C3C0(g);
        self->b94 = 0;
        r = func_00452FF0(g, 0);
        if (r == 0x2F || r == 0x30) {
            Str_0029D120 a;
            Str_0029D120 b;
            self->f88 = 3;
            func_002CA640(D_004FFC04, 1);
            String_CtorCStr_13B480(&a, func_0033CE30(self, 6, 0, 0, 0, 0));
            String_CtorCStr_13B480(&b, func_0033CE30(self, r == 0x2F ? 8 : 0x83, 0, 0, 0, 0));
            {
                char* tb = func_001692D0(&b);
                func_002CAE30(D_004FFC04, 5, func_001692D0(&a), tb, self, 0);
            }
            func_00138B70(&b, 0);
            func_00138B70(&a, 0);
        } else {
            void* ui;
            self->f88 = 4;
            ui = D_004FFC04;
            func_002CAE30(ui, 2, D_004AABF0, func_0033CE30(self, 5, 0, 0, 0, 0), self, 0);
        }
    }
}