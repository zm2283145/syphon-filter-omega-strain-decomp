#pragma cplusplus on
#include "types.h"
struct Str_00288E90 { char d[0x10]; };
struct Txt_00288E90 { char pad[0x48]; char s48[4]; };
struct S_00288E90 { char pad0[0x8C]; Txt_00288E90* p8C; char pad90[4]; Txt_00288E90* p94; char pad98[0x10]; int fA8; };
extern "C" {
extern void* D_004FFC04;
const unsigned int D_004A9730[4] = { 0x0, 0x0, 0x0, 0x0 };
void* func_004294C0(void);
char* func_001692D0(void* s);
int strlen(const char* s);
char* func_0033CE30(S_00288E90* self, unsigned char a, char* b, int c, int d, int e);
void String_CtorCStr_13B480(Str_00288E90* s, const char* c);
int func_002CAE30(void* ui, int a, char* b, char* c, S_00288E90* d, int e);
void func_00138B70(Str_00288E90* s, int flags);
int func_00445B90(void* g, char* a, char* b);
unsigned char func_00452FF0(void* g, int a);
int func_004459D0(void* g, char* a, char* b);
void func_002CAC80(void* ui, int id);
}
extern "C" void func_00288E90(S_00288E90* self)
{
    void* g = func_004294C0();
    char* pw;
    if (!func_001692D0(self->p94->s48) || !strlen(func_001692D0(self->p94->s48))) {
        Str_00288E90 a;
        Str_00288E90 b;
        String_CtorCStr_13B480(&a, func_0033CE30(self, 0x20, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, func_0033CE30(self, 0x8C, 0, 0, 0, 0));
        {
            char* tb = func_001692D0(&b);
            func_002CAE30(D_004FFC04, 2, func_001692D0(&a), tb, 0, 0);
        }
        func_00138B70(&b, 0);
        func_00138B70(&a, 0);
        return;
    }
    {
        void* ui = D_004FFC04;
        self->fA8 = func_002CAE30(ui, 0, ((char*)D_004A9730), func_0033CE30(self, 0x26, 0, 0, 0, 0), 0, 0);
    }
    pw = func_001692D0(self->p94->s48);
    if ((unsigned char)func_00445B90(g, func_001692D0(self->p8C->s48), pw)) {
        void* ui = D_004FFC04;
        func_002CAE30(ui, 2, ((char*)D_004A9730), func_0033CE30(self, 0x25, 0, 0, 0, 0), self, 0x23);
    } else {
        int cb;
        int code;
        unsigned char r = func_00452FF0(g, 0);
        cb = -1;
        if (r == 0x3D) {
            char* pw2 = func_001692D0(self->p94->s48);
            if (func_004459D0(g, func_001692D0(self->p8C->s48), pw2)) {
                code = 0x24;
                cb = code;
            } else {
                code = 0x23;
            }
        } else if (r == 3) {
            code = 0x21;
        } else {
            code = 0x22;
        }
        if (code != -1) {
            Str_00288E90 c;
            Str_00288E90 d;
            S_00288E90* tgt;
            String_CtorCStr_13B480(&c, func_0033CE30(self, 0x20, 0, 0, 0, 0));
            String_CtorCStr_13B480(&d, func_0033CE30(self, code, func_001692D0(self->p8C->s48), 0, 0, 0));
            tgt = cb == -1 ? 0 : self;
            {
                pw = func_001692D0(&d);
                func_002CAE30(D_004FFC04, 2, func_001692D0(&c), pw, tgt, cb);
            }
            func_00138B70(&d, 0);
            func_00138B70(&c, 0);
        }
    }
    func_002CAC80(D_004FFC04, self->fA8);
}