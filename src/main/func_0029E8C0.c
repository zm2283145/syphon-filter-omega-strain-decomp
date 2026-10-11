#pragma cplusplus on
#include "types.h"
struct Ev_0029E8C0 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Str_0029E8C0 { char d[0x10]; };
struct Fl_0029E8C0 { char pad[0x14]; unsigned short flags; };
struct S_0029E8C0 {
    char pad0[0x88]; int f88; char pad8C[0xF4 - 0x8C]; void* pF4; char padF8[8]; void* p100; char pad104[0xC]; Fl_0029E8C0* p110; Fl_0029E8C0* p114;
};
extern "C" {
extern void* D_004FFC04;
extern char D_004AABF0[];
void func_0029DE70(S_0029E8C0* self, int a);
char* func_0033CE30(S_0029E8C0* self, int a, int b, int c, int d, int e);
int func_002CAE30(void* ui, int a, char* b, char* c, S_0029E8C0* d, int e);
void String_CtorCStr_13B480(Str_0029E8C0* s, const char* c);
char* func_001692D0(Str_0029E8C0* s);
void func_00138B70(Str_0029E8C0* s, int flags);
void func_0043D820(void* p, int a);
void func_0043D760(void* p, int a);
int func_0033CEF0(S_0029E8C0* self, Ev_0029E8C0* ev);
}
static inline unsigned char Down_0029E8C0(Ev_0029E8C0* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_0029E8C0(Ev_0029E8C0* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_0029E8C0(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_0029E8C0(Ev_0029E8C0* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_0029E8C0(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int func_0029E8C0(S_0029E8C0* self, Ev_0029E8C0* ev)
{
    if (Press_0029E8C0(ev, 0x10)) {
        if (self->f88 == 5 || self->f88 == 1) {
            func_0029DE70(self, 0);
        } else {
            void* ui = D_004FFC04;
            func_002CAE30(ui, 5, D_004AABF0, func_0033CE30(self, 0xE, 0, 0, 0, 0), self, 0x1E);
        }
        return 1;
    } else {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x20 && ev->f6 == 0;
        if (b) {
            if (self->f88 == 5) {
                Str_0029E8C0 a;
                Str_0029E8C0 c;
                self->f88 = 3;
                String_CtorCStr_13B480(&a, func_0033CE30(self, 7, 0, 0, 0, 0));
                String_CtorCStr_13B480(&c, func_0033CE30(self, 8, 0, 0, 0, 0));
                {
                    char* tc = func_001692D0(&c);
                    func_002CAE30(D_004FFC04, 5, func_001692D0(&a), tc, self, 0x1F);
                }
                func_00138B70(&c, 0);
                func_00138B70(&a, 0);
            }
            return 1;
        } else {
            bool d = ev->type == 1 && ev->f2 == 0 && ev->btn == 8 && ev->f6 == 0;
            if (d) {
                if (self->p110 && (self->p110->flags & 2))
                    func_0043D820(self->pF4, 0);
                else if (self->p114 && (self->p114->flags & 2))
                    func_0043D820(self->p100, 0);
                return 1;
            } else {
                bool e = ev->type == 1 && ev->f2 == 0 && ev->btn == 4 && ev->f6 == 0;
                if (e) {
                    if (self->p110 && (self->p110->flags & 2))
                        func_0043D760(self->pF4, 0);
                    else if (self->p114 && (self->p114->flags & 2))
                        func_0043D760(self->p100, 0);
                    return 1;
                }
            }
        }
    }
    return func_0033CEF0(self, ev);
}