#pragma cplusplus on
#include "types.h"
struct W_0028ED60 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char pad4[0x44]; void* f48;
};
struct Self_0028ED60 { char pad0[0x48]; void* f48; W_0028ED60* f4C; W_0028ED60* f50; W_0028ED60* f54; W_0028ED60* f58; W_0028ED60* f5C; };
struct Aw_0028ED60 { char pad[0xC]; unsigned char bC; char padD[3]; };
extern "C" {
extern char D_004A9A50[];
extern char D_004A9BF0[];
extern Self_0028ED60* D_00506390;
extern char D_004A9988[];
extern char D_004A9870[];
extern char D_004A9990[];
extern char D_004A9C40[];
extern char D_004A7520[];
extern char D_004A9A40[];
extern char D_004FFB50[];
extern char D_0055DDA0[];
void func_0041F150(Self_0028ED60* self);
void* func_0041DB80(Self_0028ED60* self, char* name);
void func_00290BC0(void);
void func_0041BEB0(W_0028ED60* w, char* s, int a);
void func_002888C0(Aw_0028ED60* a);
void* Agent_GetSelected(void* a, int b);
void AgentData_FilterAwards(void* ag, Aw_0028ED60* a);
void func_00403040(void* p, Aw_0028ED60* a);
void func_002887C0(Aw_0028ED60* a, int flags);
}
static inline W_0028ED60* FindAs_0028ED60(Self_0028ED60* self, char* name, char* type)
{
    W_0028ED60* w = (W_0028ED60*)func_0041DB80(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void func_0028ED60(Self_0028ED60* self)
{
    W_0028ED60* w;
    Aw_0028ED60 a;
    func_0041F150(self);
    w = FindAs_0028ED60(self, D_004A9A50, D_004A9BF0);
    if (w) {
        D_00506390 = self;
        w->f48 = (void*)func_00290BC0;
    }
    self->f48 = func_0041DB80(self, "createagent_grp");
    self->f4C = FindAs_0028ED60(self, D_004A9988, D_004A9870);
    self->f50 = FindAs_0028ED60(self, D_004A9990, D_004A9870);
    self->f58 = FindAs_0028ED60(self, "selectindicator", D_004A9C40);
    self->f5C = FindAs_0028ED60(self, "value_slot", D_004A7520);
    self->f54 = FindAs_0028ED60(self, "beard", D_004A9870);
    if (self->f5C)
        func_0041BEB0(self->f5C, D_004A9A40, 0);
    func_002888C0(&a);
    a.bC = 1;
    AgentData_FilterAwards(Agent_GetSelected(D_004FFB50, -1), &a);
    func_00403040(D_0055DDA0, &a);
    func_002887C0(&a, -1);
}