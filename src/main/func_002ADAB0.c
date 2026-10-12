#pragma cplusplus on
#include "types.h"
struct S_002ADAB0 {
    char pad0[0x88]; void* p88; char pad8C[0xC]; void* p98; char pad9C[0x64]; int f100; char s104[0x5C]; void* p160;
};
extern "C" {
extern void* D_004FFC04;
extern char D_004ABB08[];
void* func_00414790(void);
void* func_00418A80(void* a, char* b, char* c);
int func_0033CE30(S_002ADAB0* self, int a, char* b, int c, int d, int e);
void func_0032B4F0(void* pg, int a, char* b, S_002ADAB0* c, int d, int e, int f);
void* func_004294C0(void);
char* func_001692D0(void* s);
int func_002CAE30(void* ui, int a, char* b, int c, S_002ADAB0* d, int e);
int func_0044D9C0(void* g, int a);
void func_002CAC80(void* ui, int id);
int func_00451370(void* g, char* t);
int func_00452FF0(void* g, int a);
void func_0033C7C0(S_002ADAB0* self, int r, char* t);
void func_0033D8E0(S_002ADAB0* self, int a);
int func_0033DF00(S_002ADAB0* self, void* w, int msg, int sub, char* text);
}
extern "C" int func_002ADAB0(S_002ADAB0* self, void* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 2 && w == self->p160) {
        void* pg = func_00418A80(func_00414790(), "GuiKeyboard", "KEYBOARD");
        if (pg)
            func_0032B4F0(pg, func_0033CE30(self, 0x40, 0, 0, 0, 0), D_004ABB08, self, 0xF, 0xC, 0);
        return 1;
    }
    if (m == 0x1A) {
        if (sub == 0xD) {
            void* g = func_004294C0();
            if (g) {
                int h;
                char* nm = func_001692D0(self->s104);
                void* ui = D_004FFC04;
                h = func_002CAE30(ui, 0, D_004ABB08, func_0033CE30(self, 0x36, nm, 0, 0, 0), 0, 0);
                if (func_0044D9C0(g, self->f100)) {
                    char* nm2 = func_001692D0(self->s104);
                    void* ui2 = D_004FFC04;
                    func_002CAE30(ui2, 2, D_004ABB08, func_0033CE30(self, 0x37, nm2, 0, 0, 0), 0, 0);
                } else {
                    char* nm3 = func_001692D0(self->s104);
                    void* ui3 = D_004FFC04;
                    func_002CAE30(ui3, 2, D_004ABB08, func_0033CE30(self, 0x38, nm3, 0, 0, 0), 0, 0);
                }
                func_002CAC80(D_004FFC04, h);
            }
            return 1;
        }
        if (sub == 0xC) {
            if (text && *text) {
                void* g = func_004294C0();
                if (g) {
                    int r = func_00451370(g, text);
                    if ((unsigned char)func_00452FF0(g, 0)) {
                        void* ui = D_004FFC04;
                        func_002CAE30(ui, 2, D_004ABB08, func_0033CE30(self, 0x17, text, 0, 0, 0), 0, 0);
                    } else {
                        func_0033C7C0(self, r, text);
                    }
                }
            }
            return 1;
        }
    }
    if (m == 0 && w != self->p88) {
        if (w == self->p98)
            func_0033D8E0(self, 3);
        else if (w == self->p160)
            func_0033D8E0(self, 4);
        else
            func_0033D8E0(self, 1);
    }
    return func_0033DF00(self, w, msg, sub, text);
}