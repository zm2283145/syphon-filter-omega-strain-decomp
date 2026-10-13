#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}
#pragma inline_depth(10)
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_45DFD0;
struct W_45DFD0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0xB0 - 0x16];
    V4_45DFD0 cB0;
    char padC0[0x20];
    V4_45DFD0 cE0;
    unsigned char bF0;
};
typedef struct { char pad[0x10]; unsigned char b10; unsigned char b11; } T_45DFD0;
typedef struct {
    char pad[0x48]; T_45DFD0* f48; W_45DFD0* f4C; W_45DFD0* f50; char pad54[0x14]; W_45DFD0* f68; W_45DFD0* f6C;
    char pad70[0x30]; W_45DFD0* fA0; W_45DFD0* fA4; char padA8[0x38]; W_45DFD0* fE0; W_45DFD0* fE4; W_45DFD0* fE8;
    char padEC[0x28]; W_45DFD0* f114; W_45DFD0* f118; W_45DFD0* f11C; W_45DFD0* f120; W_45DFD0* f124;
} O_45DFD0;
extern "C" {
extern char D_004C2290[];extern char D_00587D80[];
extern char D_004C2268[];
extern char D_004C2430[]; extern char D_004A7520[]; extern char D_004C1D10[]; extern char D_004AA640[];
extern char D_004FFB50[];
extern V4_45DFD0 D_00587CA0; extern V4_45DFD0 D_00587CB0;
void func_0041F150(O_45DFD0* o);
void* Mem_Alloc(int pool, int size, char* file, int line);
void* Gui_GetScreenList(void);
void* func_00418420(void* mgr, char* name);
T_45DFD0* func_003D0940(void* p, int a, int b, int c, int d, void* e, char* f);
W_45DFD0* func_0041DB80(void* o, char* name);
void func_0041C0F0(W_45DFD0* w, int v);
char* func_0012F5D0(void* p, int id);
void func_0041BEB0(W_45DFD0* w, char* s, int f);
void func_0045CC90(O_45DFD0* o);
void func_0045DFD0(O_45DFD0* o);
}
static inline void* Alloc_45DFD0(int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004C2290, line); }
static inline W_45DFD0* Cast_45DFD0(W_45DFD0* w, void* t) { return w && w->IsA(t) ? w : 0; }
static inline void SetB0_45DFD0(W_45DFD0* w, V4_45DFD0 c) { w->cB0.x = c.x; w->cB0.y = c.y; w->cB0.z = c.z; w->cB0.w = c.w; }
static inline void SetE0_45DFD0(W_45DFD0* w, V4_45DFD0 c) { w->cE0.x = c.x; w->cE0.y = c.y; w->cE0.z = c.z; w->cE0.w = c.w; }

void func_0045DFD0(O_45DFD0* o)
{
    T_45DFD0* t;
    func_0041F150(o);
    t = (T_45DFD0*)Alloc_45DFD0(0x60, 0x107);
    if (t) t = func_003D0940(t, 0, 0, 10, 10, func_00418420(Gui_GetScreenList(), "callout"), D_00587D80);
    o->f48 = t;
    o->f48->b10 = 2;
    o->f48->b11 = 1;
    o->f4C = Cast_45DFD0(func_0041DB80(o, "quickchat"), D_004C2430);
    o->f50 = Cast_45DFD0(func_0041DB80(o, "interact"), D_004A7520);
    o->f68 = Cast_45DFD0(func_0041DB80(o, "subtitles"), D_004C1D10);
    o->fE0 = func_0041DB80(o, "choosemenu");
    if (o->fE0) {
        o->fE4 = Cast_45DFD0(func_0041DB80(o->fE0, "title"), D_004A7520);
        func_0041C0F0(o->fE4, 1);
        o->fE8 = Cast_45DFD0(func_0041DB80(o->fE0, "choices"), D_004AA640);
        SetB0_45DFD0(o->fE8, D_00587CA0);
        SetE0_45DFD0(o->fE8, D_00587CB0);
        o->fE8->bF0 = 1;
    }
    if (!o->fE0 || !o->fE4 || !o->fE8) o->fE0 = 0;
    o->f114 = Cast_45DFD0(func_0041DB80(o, "value_codename"), D_004A7520);
    if (o->f114) {
        if (D_005721C8) {
            char* s = func_0012F5D0(D_004FFB50, NetLocalId());
            func_0041BEB0(o->f114, s ? s : D_004C2268, 0);
            o->f114->flags |= 2;
        } else {
            o->f114->flags &= ~2;
        }
    }
    o->f118 = Cast_45DFD0(func_0041DB80(o, "value_timer_description"), D_004A7520);
    o->f11C = Cast_45DFD0(func_0041DB80(o, "value_timer"), D_004A7520);
    o->f118->flags &= ~2;
    o->f11C->flags &= ~2;
    o->f120 = Cast_45DFD0(func_0041DB80(o, "headset_playing"), D_004A7520);
    o->f124 = func_0041DB80(o, "label_talking");
    o->f6C = func_0041DB80(o, "weaponselect");
    o->fA4 = func_0041DB80(o, "lines_arrows");
    o->fA0 = func_0041DB80(o, "brackets");
    func_0045CC90(o);
}