#pragma cplusplus on
#include "types.h"
struct Ev_002A12F0 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Pg_002A12F0 { char pad[0x14]; unsigned short flags; };
struct Ui_002A12F0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void Show(void* p, int a); virtual void Hide(void* p);
};
struct S_002A12F0 { char pad0[0x20]; void* f20; char pad24[0xDC - 0x24]; void* pDC; void* pE0; };
extern "C" {
extern char D_004AB000[];
void func_002A1590(S_002A12F0* self, int a);
void func_002A1600(S_002A12F0* self, int a);
void* func_00414790(void);
Pg_002A12F0* func_00418980(void* a, char* b);
Ui_002A12F0* func_004147A0(void);
void func_0033C320(S_002A12F0* self, int a);
void func_002A0F60(S_002A12F0* self);
int func_0033CEF0(S_002A12F0* self, Ev_002A12F0* ev);
}
static inline unsigned char Down_002A12F0(Ev_002A12F0* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_002A12F0(Ev_002A12F0* e, int b)
{
    unsigned char r = 0;
    if (Down_002A12F0(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_002A12F0(Ev_002A12F0* e, int b)
{
    unsigned char r = 0;
    if (Btn_002A12F0(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int func_002A12F0(S_002A12F0* self, Ev_002A12F0* ev)
{
    if (Press_002A12F0(ev, 0x8000)) {
        if (self->f20 == self->pDC)
            func_002A1590(self, 0);
        else if (self->f20 == self->pE0)
            func_002A1600(self, 0);
    } else {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x2000 && ev->f6 == 0;
        if (b) {
            if (self->f20 == self->pDC)
                func_002A1590(self, 1);
            else if (self->f20 == self->pE0)
                func_002A1600(self, 1);
        }
    }
    if (Press_002A12F0(ev, 0x10)) {
        Pg_002A12F0* p = func_00418980(func_00414790(), D_004AB000);
        if (p) {
            func_004147A0()->Hide(self);
            p->flags |= 2;
        } else {
            func_0033C320(self, 1);
        }
        return 1;
    } else {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x80 && ev->f6 == 0;
        if (b) {
            func_002A0F60(self);
            return 1;
        }
    }
    return func_0033CEF0(self, ev);
}