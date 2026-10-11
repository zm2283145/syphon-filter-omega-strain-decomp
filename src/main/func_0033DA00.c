#include "types.h"
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_33DA00;
typedef struct { char pad[0x20]; void* f20; } M_33DA00;
typedef struct { char pad[0x88]; void* f88; void* f8C; int f90; char pad94[4]; void* f98; void* f9C; void* fA0; void* fA4; } O_33DA00;
M_33DA00* func_004147A0(void);
void func_00414B30(void* mgr, void* w);
void func_0041E0F0(void* a, void* b, int kind, int v, int f);
void func_0033C320(O_33DA00* o, int v);
void func_0043D820(void* p, int v);
void func_0043D760(void* p, int v);
void func_002AEC60(void* p);
int func_0033E2A0(O_33DA00* o, void* w, int v);
int func_0033CEF0(O_33DA00* o, Ev_33DA00* ev);
static inline unsigned char Down_33DA00(Ev_33DA00* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_33DA00(Ev_33DA00* e, int b) { unsigned char r = 0; if (Down_33DA00(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_33DA00(Ev_33DA00* e, int b) { unsigned char r = 0; if (Btn_33DA00(e, b) && e->b6 == 0) r = 1; return r; }
static inline int Down2_33DA00(Ev_33DA00* e) { return e->type == 1 && e->b2 == 0; }
static inline int Btn2_33DA00(Ev_33DA00* e, int b) { return Down2_33DA00(e) && e->btn == b; }
static inline int Plain2_33DA00(Ev_33DA00* e, int b) { return Btn2_33DA00(e, b) && e->b6 == 0; }

int func_0033DA00(O_33DA00* o, Ev_33DA00* ev)
{
    if (Plain_33DA00(ev, 0x10) || Plain2_33DA00(ev, 0x8000)) {
        if (func_004147A0()->f20 == o->f88) {
            void* t = 0;
            switch (o->f90) {
            case 0: t = o->f9C; break;
            case 1: t = o->fA0; break;
            case 2: t = o->f98; break;
            case 3: t = o->fA4; break;
            }
            if (t) {
                func_00414B30(func_004147A0(), t);
                { void* w = func_004147A0()->f20; func_0041E0F0(w, func_004147A0(), 0x10, 0, 0); }
                return 1;
            }
        } else if (!Plain2_33DA00(ev, 0x8000)) {
            func_0033C320(o, 1);
            return 1;
        }
    }
    if (Plain_33DA00(ev, 2)) {
        func_0043D820(o->f8C, 0);
        return 1;
    }
    if (Plain2_33DA00(ev, 1)) {
        func_0043D760(o->f8C, 0);
        return 1;
    }
    if (Plain2_33DA00(ev, 0x100)) {
        func_002AEC60(o->f8C);
        return 1;
    }
    if (Plain2_33DA00(ev, 0x2000) && func_0033E2A0(o, func_004147A0()->f20, 0)) {
        { void* w = func_004147A0()->f20; func_0041E0F0(w, func_004147A0(), 0x10, 0, 0); }
        return 1;
    }
    return func_0033CEF0(o, ev);
}