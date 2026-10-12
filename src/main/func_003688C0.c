#pragma cplusplus on
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3688C0;
struct W_3688C0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x38 - 0x16];
    float f38;
    char pad3C[4];
    float f40;
    char pad44[0x5C - 0x44];
    int f5C;
    char pad60[0x88 - 0x60];
    W_3688C0* f88;
    char pad8C[0xB0 - 0x8C];
    V4_3688C0 cB0;
};
typedef struct {
    char pad[0x48]; W_3688C0* slots[3]; W_3688C0* f54; char pad58[8]; W_3688C0* f60; W_3688C0* f64;
    W_3688C0* f68; W_3688C0* f6C; W_3688C0* f70; W_3688C0* f74; int f78; int f7C; W_3688C0* f80; int f84;
} O_3688C0;
extern "C" {
extern char D_004BBC90[]; extern char D_004BBCB0[]; extern char D_004BBCC8[]; extern char D_004BBCD0[]; extern char D_004BBCE0[];
extern char D_004BBD00[]; extern char D_004BBD18[]; extern char D_004BBD20[]; extern char D_004BBD38[]; extern char D_004BBD48[];
extern char D_004BBD58[]; extern char D_004BBD68[]; extern char D_004BBC48[]; extern char D_004BBD70[]; extern char D_004BBD80[]; extern char D_004BBD88[];
extern char D_004A9870[]; extern char D_004AA640[]; extern char D_004A7520[];
extern char D_004FFC90[];
extern unsigned char D_005721C8;
static const unsigned int dat_00492F60[2] = { 0x3, 0x0 };
extern V4_3688C0 D_00587CE0; extern V4_3688C0 D_00587CC0;
void func_0041F150(O_3688C0* o);
W_3688C0* func_0041DB80(void* o, char* name);
int sprintf(char* buf, const char* fmt, ...);
void func_00421690(W_3688C0* w, char* s);
void func_00424820(W_3688C0* w, int v);
int func_00330C30(void* p, unsigned char f);
void String_Copy(void* d, char* s);
void func_0041BEB0(W_3688C0* w, char* s, int f);
char* Loc_LookupText(char* k);
void func_0041C0F0(W_3688C0* w, int v);
void func_003688C0(O_3688C0* o);
}
static inline W_3688C0* Cast_3688C0(W_3688C0* w, void* t) { return w && w->IsA(t) ? w : 0; }
static inline void SetC_3688C0(W_3688C0* w, V4_3688C0 c) { w->cB0.x = c.x; w->cB0.y = c.y; w->cB0.z = c.z; w->cB0.w = c.w; }

void func_003688C0(O_3688C0* o)
{
    int i;
    W_3688C0* t;
    func_0041F150(o);
    o->f60 = func_0041DB80(o, D_004BBC90);
    o->f64 = func_0041DB80(o, D_004BBCB0);
    if (o->f64) {
        o->f68 = Cast_3688C0(func_0041DB80(o, D_004BBCC8), D_004A9870);
        o->f6C = Cast_3688C0(func_0041DB80(o, D_004BBCD0), D_004A9870);
        if (o->f68) o->f68->flags &= ~0x80;
        if (o->f6C) o->f6C->flags &= ~0x80;
    } else {
        o->f68 = 0;
        o->f6C = 0;
    }
    o->f80 = func_0041DB80(o, D_004BBCE0);
    for (i = 0; i < 4; i++) {
        char name[32];
        sprintf(name, D_004BBD00, i);
        o->slots[i] = Cast_3688C0(func_0041DB80(o, name), D_004AA640);
        if (o->slots[i]) {
            func_00421690(o->slots[i], D_004BBD18);
            if (i == 0) {
                W_3688C0* w = func_0041DB80(o, D_004BBD20);
                if (w) w->flags &= ~2;
                SetC_3688C0(o->slots[i], D_00587CE0);
                o->slots[i]->f88 = w;
            } else {
                SetC_3688C0(o->slots[i], D_00587CC0);
            }
            o->slots[i]->flags &= ~0x80;
            func_00424820(o->slots[i], o->slots[i]->f5C - (*(int*)dat_00492F60));
        }
    }
    if (o->f54) {
        o->f78 = (int)o->f54->f38;
        o->f7C = (int)o->f54->f40;
        if (o->f80) o->f84 = (int)(o->f80->f38 - (float)o->f78);
    }
    o->f70 = Cast_3688C0(func_0041DB80(o, D_004BBD38), D_004A7520);
    o->f74 = Cast_3688C0(func_0041DB80(o, D_004BBD48), D_004A7520);
    t = Cast_3688C0(func_0041DB80(o, D_004BBD58), D_004A7520);
    if (t) {
        char buf[32];
        int r = func_00330C30(D_004FFC90, D_005721C8);
        if (r < 0) String_Copy(buf, D_004BBD68);
        else {
            int m = r / 60;
            r -= m * 60;
            sprintf(buf, D_004BBC48, m, r);
        }
        func_0041BEB0(t, buf, 0);
    }
    t = Cast_3688C0(func_0041DB80(o, D_004BBD70), D_004A7520);
    if (t) {
        char* s = Loc_LookupText(D_005721C8 ? D_004BBD80 : D_004BBD88);
        if (s) {
            func_0041BEB0(t, s, 0);
            func_0041C0F0(t, 1);
        }
    }
}