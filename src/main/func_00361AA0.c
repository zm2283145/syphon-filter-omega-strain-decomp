#pragma cplusplus on
#include "types.h"
struct W_361AA0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x5C - 0x16];
    int f5C;
};
typedef struct {
    char pad[0x100]; W_361AA0* f100; W_361AA0* f104; W_361AA0* f108; W_361AA0* f10C; W_361AA0* f110;
    W_361AA0* f114; W_361AA0* f118; W_361AA0* f11C; W_361AA0* f120;
} O_361AA0;
extern "C" {
extern char D_004BB978[]; extern char D_004BB988[]; extern char D_004BB998[]; extern char D_004BB9A8[];
extern char D_004BB9B8[]; extern char D_004BB9C8[]; extern char D_004BB9D0[]; extern char D_004BB9D8[];
extern char D_004A7520[]; extern char D_004ABAB0[]; extern char D_004A9870[]; extern char D_004B88F0[]; extern char D_004BBBB0[];
extern void* D_004FFC04;
void func_0033D3F0(O_361AA0* o);
W_361AA0* func_0041DB80(void* o, char* name);
void func_0041C0D0(W_361AA0* w, int v);
void func_00424820(W_361AA0* w, int v);
void func_002C9D50(void* p);
void func_00361AA0(O_361AA0* o);
}
static inline W_361AA0* Cast_361AA0(W_361AA0* w, void* t) { return w && w->IsA(t) ? w : 0; }

void func_00361AA0(O_361AA0* o)
{
    func_0033D3F0(o);
    o->f100 = Cast_361AA0(func_0041DB80(o, D_004BB978), D_004A7520);
    o->f104 = Cast_361AA0(func_0041DB80(o, D_004BB988), D_004A7520);
    o->f108 = Cast_361AA0(func_0041DB80(o, D_004BB998), D_004A7520);
    if (o->f108) func_0041C0D0(o->f108, 1);
    o->f10C = Cast_361AA0(func_0041DB80(o, D_004BB9A8), D_004ABAB0);
    o->f110 = Cast_361AA0(func_0041DB80(o, D_004BB9B8), D_004ABAB0);
    o->f114 = Cast_361AA0(func_0041DB80(o, D_004BB9C8), D_004A9870);
    o->f118 = Cast_361AA0(func_0041DB80(o, D_004BB9D0), D_004A9870);
    o->f11C = Cast_361AA0(func_0041DB80(o, D_004BB9D8), D_004B88F0);
    o->f120 = Cast_361AA0(func_0041DB80(o, "playercharacter"), D_004BBBB0);
    o->f10C->flags &= ~0x80;
    o->f110->flags &= ~0x80;
    func_00424820(o->f110, o->f110->f5C - 2);
    func_00424820(o->f10C, o->f10C->f5C - 4);
    func_002C9D50(D_004FFC04);
}