#pragma cplusplus on
#include "types.h"
struct W_002A8410 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
struct Row_002A8410 { void* text; W_002A8410* a; W_002A8410* b; W_002A8410* c; W_002A8410* d; };
struct Self_002A8410 { char pad0[0x58]; Row_002A8410 rows[3]; };
extern "C" {
extern char D_004AB5B0[];
extern char* D_0048BB58;
extern char* D_0048BB60;
extern char* D_0048BB68;
extern char* D_0048BB70;
extern char* D_0048BB78;
extern char D_004A7520[];
extern char D_004A9880[];
extern char D_004A9870[];
int sprintf(char* buf, const char* fmt, ...);
void* func_0041DC70(Self_002A8410* self, char* name);
void* func_0041DB80(Self_002A8410* self, char* name);
void func_0041C110(W_002A8410* w, int a);
void func_0041F150(Self_002A8410* self);
}
static inline W_002A8410* FindAs_002A8410(Self_002A8410* self, char* name, char* type)
{
    W_002A8410* w = (W_002A8410*)func_0041DB80(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void func_002A8410(Self_002A8410* self)
{
    char buf[0x80];
    int i;
    for (i = 0; i < 3; i++) {
        sprintf(buf, D_004AB5B0, D_0048BB58, i);
        self->rows[i].text = func_0041DC70(self, buf);
        sprintf(buf, D_004AB5B0, D_0048BB60, i);
        self->rows[i].a = FindAs_002A8410(self, buf, D_004A7520);
        if (i == 2) {
            sprintf(buf, D_004AB5B0, D_0048BB68, i);
            self->rows[i].b = FindAs_002A8410(self, buf, D_004A9880);
        } else {
            sprintf(buf, D_004AB5B0, D_0048BB68, i);
            self->rows[i].b = FindAs_002A8410(self, buf, D_004A7520);
        }
        if (i == 1 && self->rows[i].b)
            func_0041C110(self->rows[i].b, 0);
        sprintf(buf, D_004AB5B0, D_0048BB70, i);
        self->rows[i].c = FindAs_002A8410(self, buf, D_004A9870);
        sprintf(buf, D_004AB5B0, D_0048BB78, i);
        self->rows[i].d = FindAs_002A8410(self, buf, D_004A9870);
    }
    func_0041F150(self);
}