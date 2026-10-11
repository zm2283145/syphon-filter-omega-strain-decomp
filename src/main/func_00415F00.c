#pragma cplusplus on
#include "types.h"
class V415F00 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24(int);
};
typedef struct { char pad[8]; int arg; } N415F00;
typedef struct { void* vt; char p0[0x24]; int count; N415F00* head; char p1[0x54 - 0x30]; char sub[4]; } T415F00;
extern "C" {
extern char D_004E08D0[];
void func_002CCD80(void* p, int f);
void func_0041F370(T415F00* p, int f);
void operator_delete(void* p);
}
extern "C" T415F00* func_00415F00(T415F00* self, short flag) {
    if (self) {
        self->vt = D_004E08D0;
        while (self->count) ((V415F00*)self)->s24(self->head->arg);
        if (self->sub) func_002CCD80(self->sub, 0);
        func_0041F370(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}