#pragma cplusplus on
#include "types.h"
struct W_002BDF90 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
extern "C" {
extern char D_004AC370[];
extern char D_004AC390[];
extern char D_004AC3A0[];
extern char D_004AC3B0[];
extern char D_004AC3D0[];
extern char D_004AC3F0[];
extern char D_004AC410[];
extern char D_004AC420[];
extern char D_004AC430[];
extern char D_004AC450[];
extern char D_004A7520[];
extern char D_004AC388[];
void* func_0041DB80(void* self, char* name);
void func_0041BEB0(W_002BDF90* w, char* s, int a);
}
static inline W_002BDF90* FindAs_002BDF90(void* self, char* name, char* type)
{
    W_002BDF90* w = (W_002BDF90*)func_0041DB80(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
static inline void Clear_002BDF90(void* self, char* name)
{
    W_002BDF90* w = FindAs_002BDF90(self, name, D_004A7520);
    if (w)
        func_0041BEB0(w, D_004AC388, 0);
}
extern "C" void func_002BDF90(void* self)
{
    Clear_002BDF90(self, D_004AC370);
    Clear_002BDF90(self, D_004AC390);
    Clear_002BDF90(self, D_004AC3A0);
    Clear_002BDF90(self, D_004AC3B0);
    Clear_002BDF90(self, D_004AC3D0);
    Clear_002BDF90(self, D_004AC3F0);
    Clear_002BDF90(self, D_004AC410);
    Clear_002BDF90(self, D_004AC420);
    Clear_002BDF90(self, D_004AC430);
    Clear_002BDF90(self, D_004AC450);
}