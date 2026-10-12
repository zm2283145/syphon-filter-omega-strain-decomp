#pragma cplusplus on
#include "types.h"
struct M_454B10 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(void* o);
};
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_454B10;
typedef struct { char pad[0x33E7]; unsigned char b33E7; char pad33E8[0x3524 - 0x33E8]; void* f3524; } A_454B10;
typedef struct { char pad[0x30]; A_454B10* f30; } G_454B10;
typedef struct { char pad[0x48]; int f48; } S_454B10;
typedef struct { char pad[0x48]; S_454B10* f48; void* f4C; } O_454B10;
extern "C" {
extern G_454B10* D_004FFC0C;
extern void* D_004FFD30;
extern void* D_004FFC2C;
extern char D_004FFB50[];
void func_0043D820(void* p, int v);
void func_0043D760(void* p, int v);
int WeaponInv_SlotOfItem(int id);
void* WeaponDb_Get(void* db, int id);
void* WeaponInv_GetHeldItem(void* p);
void func_00175FF0(G_454B10* g, int id);
void Goggles_Toggle(A_454B10* a);
M_454B10* func_004147A0(void);
void func_0041E0F0(void* a, void* b, int kind, int v, int f);
void func_00454F80(O_454B10* o, bool f);
void func_00456160(O_454B10* o);
void func_00242900(void* p);
void func_00131470(void* p, int v);
int func_00454B10(O_454B10* o, Ev_454B10* ev);
}
static inline unsigned char Down_454B10(Ev_454B10* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_454B10(Ev_454B10* e, int b) { unsigned char r = 0; if (Down_454B10(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_454B10(Ev_454B10* e, int b) { unsigned char r = 0; if (Btn_454B10(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_454B10(Ev_454B10* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_454B10(Ev_454B10* e, int b) { return Down2_454B10(e) && e->btn == b; }
static inline bool Plain2_454B10(Ev_454B10* e, int b) { return Btn2_454B10(e, b) && e->b6 == 0; }

int func_00454B10(O_454B10* o, Ev_454B10* ev)
{
    if (Plain_454B10(ev, 0x1000) && o->f4C) {
        func_0043D820(o->f4C, 0);
        return 1;
    }
    if (Plain2_454B10(ev, 0x4000) && o->f4C) {
        func_0043D760(o->f4C, 0);
        return 1;
    }
    if (Plain2_454B10(ev, 0x40)) {
        int wid = o->f48 ? o->f48->f48 : -1;
        if (wid != -1) {
            unsigned char sent;
            A_454B10* a = D_004FFC0C->f30;
            sent = 0;
            unsigned char kind = WeaponInv_SlotOfItem(wid);
            if (kind < 6) {
                void* wd = WeaponDb_Get(D_004FFD30, wid);
                if (wd && wd != WeaponInv_GetHeldItem(a->f3524)) {
                    sent = 1;
                    func_00175FF0(D_004FFC0C, wid);
                }
            } else if (kind == 6 && !a->b33E7) {
                sent = 1;
                Goggles_Toggle(a);
            } else if (kind == 7 && a->b33E7) {
                sent = 1;
                Goggles_Toggle(a);
            }
            if (sent) func_0041E0F0(o->f48, func_004147A0(), 0x10, 1, 0);
        }
    }
    if (Plain_454B10(ev, 1) || Plain2_454B10(ev, 2)) {
        func_00454F80(o, Btn2_454B10(ev, 2));
        return 1;
    }
    if (Plain2_454B10(ev, 0x10)) {
        func_00456160(o);
        return 1;
    }
    if (Plain2_454B10(ev, 0x800)) {
        func_004147A0()->v24(o);
        func_00242900(D_004FFC2C);
        func_00131470(D_004FFB50, 0);
        return 1;
    }
    return 0;
}