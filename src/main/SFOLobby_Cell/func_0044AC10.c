#pragma inline_depth(8)
#include "types.h"
typedef struct {
    char p0[0x74]; int f74; char p78[0xC4 - 0x78]; char fC4[0x70]; char f134[0x1D4 - 0x134]; int f1D4;
    int f1D8; char p1DC[0x24C - 0x1DC]; int f24C; char p250[0xC08 - 0x250]; int fC08; char pC0C[0xC24 - 0xC0C]; int fC24;
    char pC28[0xE84 - 0xC28]; int fE84; char pE88[4]; char fE8C[0x2408 - 0xE8C];
    signed char busy; char p2409[7]; int f2410; char p2414[4]; char name[0x68];
    int f2480; char p2484[0x255C - 0x2484]; int state; char p2560[0x2588 - 0x2560];
    int f2588; int f258C; char p2590[0x265C - 0x2590]; unsigned char f265C;
} S44AC10;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00451AE0();
extern void func_00451B00(S44AC10*, int, char*, int);
extern void func_00452F70(S44AC10*, int, int);
extern int func_004534A0(S44AC10*, int, int, int);
extern void func_00449A00(S44AC10*);
extern void func_00449D20(S44AC10*, int);
extern void func_00449510(S44AC10*);
extern unsigned char func_00452FF0(S44AC10*, int);
extern char* strncpy(char*, const char*, int);
extern void func_0044A290(S44AC10*);
extern int func_00450A90(void*, int, int);
extern int func_00466EA8(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497800;
extern int D_00497818;
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_00448D10[];

static inline void Tick44AC10(S44AC10* s, int arg1)
{
    int last = s->f258C;
    int dt = func_00443E70() - last;
    if (s->state == 7) {
        if (last == 0 || dt > D_00497800) {
            func_00449D20(s, arg1);
            func_0044A290(s);
            s->f258C = func_00443E70();
        }
    } else if (last == 0 || dt > D_00497818) {
        func_00449D20(s, arg1);
        s->f258C = func_00443E70();
    }
}
static inline unsigned char Known44AC10(S44AC10* s, int key, int update)
{
    if (update) {
        func_00449A00(s);
        Tick44AC10(s, 1);
    }
    if (func_00450A90(s->f134, key, 0)) return 1;
    return func_00450A90(s->fC4, key, 0) != 0;
}
static inline int Online44AC10(S44AC10* s)
{
    int last = s->f2588;
    int elapsed = func_00443E70() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(s);
    }
    return s->f265C;
}
int func_0044AC10(S44AC10* s, int id)
{
    struct { char f0[0x15]; char f15[0x13]; int f28; char f2C[0xC8]; } req;

    func_00451AE0();
    func_00449A00(s);
    if (id < 0) {
        func_00451B00(s, 0x1D, D_004C0D10, 0x161);
        return 0;
    }
    if (!Online44AC10(s)) {
        func_00451B00(s, 0x1F, D_004C0D10, 0x169);
        return 0;
    }
    if (Known44AC10(s, id, 1)) {
        func_00451B00(s, 0x1E, D_004C0D10, 0x170);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.f0, D_004C0D38);
    String_Copy(req.f15, s->name);
    req.f28 = id;
    strncpy(req.f2C, s->fE8C, 0xC8);
    s->f1D8 = 0;
    s->f2410 = func_00443E70();
    s->f24C = func_00466EA8(&req, func_00448D10);
    if (s->f24C != 0) {
        func_00451B00(s, 1, D_004C0D10, 0x183);
        return 0;
    }
    while (s->f1D8 == 0) {
        func_00452F70(s, 0, 0);
        if (s->f24C != 0) {
            func_00451B00(s, 1, D_004C0D10, 0x18E);
            s->busy = 0;
            return 0;
        }
        if (func_004534A0(s, s->f2410, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0D10, 0x196);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    if (s->fC08 < 0) {
        if (func_00452FF0(s, 0) == 0x2A) {
            func_00449510(s);
            if (s->f74 != 0) {
                func_00451B00(s, 0x3F, D_004C0D10, 0x1A6);
            }
            return 0;
        }
        func_00451B00(s, 1, D_004C0D10, 0x1AB);
        return 0;
    }
    func_00451AE0(s);
    return 1;
}
