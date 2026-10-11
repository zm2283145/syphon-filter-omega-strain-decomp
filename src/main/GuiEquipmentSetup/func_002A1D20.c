#pragma cplusplus on
#include "types.h"
struct Ev_002A1D20 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Ui_002A1D20 { char pad[0x20]; void* f20; };
struct S_002A1D20 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16();
    virtual void* Next(void* cur, int dir);
    char pad4[0xD8]; float fDC;
};
extern "C" {
extern void* D_004FFC04;
extern char D_004AB0E0[];
extern char D_004AB0F0[];
Ui_002A1D20* func_004147A0(void);
void func_0041E0F0(void* a, void* b, int c, int d, int e);
void func_00414B30(void* ui, void* w);
char* Loc_LookupText(char* key);
int func_002CAE30(void* ui, int a, char* b, char* c, S_002A1D20* d, int e);
}
static inline unsigned char Down_002A1D20(Ev_002A1D20* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_002A1D20(Ev_002A1D20* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_002A1D20(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_002A1D20(Ev_002A1D20* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_002A1D20(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int func_002A1D20(S_002A1D20* self, Ev_002A1D20* ev)
{
    if (Press_002A1D20(ev, 0x1000))
        return 1;
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x4000 && ev->f6 == 0;
        if (b)
            return 1;
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x8000 && ev->f6 == 0;
        if (b) {
            void* cur = func_004147A0()->f20;
            func_0041E0F0(cur, func_004147A0(), 0x10, 0, 0);
            {
                Ui_002A1D20* a = func_004147A0();
                Ui_002A1D20* u = func_004147A0();
                func_00414B30(u, self->Next(a->f20, 1));
            }
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x2000 && ev->f6 == 0;
        if (b) {
            void* cur = func_004147A0()->f20;
            func_0041E0F0(cur, func_004147A0(), 0x10, 0, 0);
            {
                Ui_002A1D20* a = func_004147A0();
                Ui_002A1D20* u = func_004147A0();
                func_00414B30(u, self->Next(a->f20, 1));
            }
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x10 && ev->f6 == 0;
        if (b) {
            char* a = Loc_LookupText(D_004AB0E0);
            char* c = Loc_LookupText(D_004AB0F0);
            if (a && c)
                func_002CAE30(D_004FFC04, 5, a, c, self, 0);
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 2;
        if (b) {
            bool s = ev->type == 1 && ev->f2 == 0 && ev->f6 == 0;
            self->fDC += s ? -1.0f : 1.0f;
            return 1;
        }
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 1;
        if (b) {
            bool s = ev->type == 1 && ev->f2 == 0 && ev->f6 == 0;
            self->fDC += s ? 1.0f : -1.0f;
            return 1;
        }
    }
    return 0;
}