#pragma inline_depth(8)
#include "types.h"
typedef struct {
    char p0[0xC4]; char fC4[0x70]; char f134[0x1D4 - 0x134]; int f1D4;
    char p1D8[0x24C - 0x1D8]; int f24C; char p250[0xC24 - 0x250]; int fC24;
    char pC28[0xE84 - 0xC28]; int fE84; char pE88[0x2408 - 0xE88];
    signed char busy; char p2409[7]; int f2410; char p2414[4]; char name[0x68];
    int f2480; char p2484[0x255C - 0x2484]; int state; char p2560[0x2588 - 0x2560];
    int f2588; int f258C; char p2590[0x265C - 0x2590]; unsigned char f265C;
} S44A810;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00451AE0(void);
extern void func_00451B00(S44A810*, int, char*, int);
extern void func_00452F70(S44A810*, int, int);
extern int func_004534A0(S44A810*, int, int, int);
extern void func_00449A00(S44A810*);
extern void func_00449D20(S44A810*, int);
extern int func_00449180(S44A810*);
extern void func_0044A290(S44A810*);
extern int func_00450A90(void*, int, int);
extern int func_00466E08(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497800;
extern int D_00497818;
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_00448E30[];

static inline void Tick44A810(S44A810* s, int arg1)
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
static inline unsigned char Known44A810(S44A810* s, int key, int update)
{
    if (update) {
        func_00449A00(s);
        Tick44A810(s, 1);
    }
    if (func_00450A90(s->f134, key, 0)) return 1;
    return func_00450A90(s->fC4, key, 0) != 0;
}
static inline int Online44A810(S44A810* s)
{
    int last = s->f2588;
    int elapsed = func_00443E70() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(s);
    }
    return s->f265C;
}
int func_0044A810(S44A810* s, int id)
{
    struct { char f0[0x15]; char f15[0x13]; int f28; int f2C; } req;

    func_00451AE0();
    s->f2588 = 0;
    s->f258C = 0;
    func_00449A00(s);
    func_00449D20(s, 1);
    if (id < 0 || !Known44A810(s, id, 1)) {
        func_00451B00(s, 0x1D, D_004C0D10, 0x1E4);
        return 0;
    }
    if (id != s->f2480 && !Online44A810(s)) {
        func_00451B00(s, 0x1F, D_004C0D10, 0x1EB);
        return 0;
    }
    if (!Online44A810(s) || id != s->f2480) {
        memset(&req, 0, sizeof(req));
        String_Copy(req.f0, D_004C0D38);
        String_Copy(req.f15, s->name);
        req.f28 = id;
        req.f2C = s->fE84;
        s->f1D4 = 0;
        s->f2410 = func_00443E70();
        s->f24C = func_00466E08(&req, func_00448E30);
        if (s->f24C != 0) {
            func_00451B00(s, 1, D_004C0D10, 0x203);
            return 0;
        }
        s->busy = 1;
        while (s->f1D4 == 0) {
            func_00452F70(s, 0, 0);
            if (s->f24C != 0) {
                func_00451B00(s, 1, D_004C0D10, 0x20E);
                s->busy = 0;
                return 0;
            }
            if (func_004534A0(s, s->f2410, D_00497890, 0) == 0) {
                func_00451B00(s, 2, D_004C0D10, 0x216);
                s->busy = 0;
                return 0;
            }
        }
        s->busy = 0;
        if (s->fC24 != 0) {
            func_00451B00(s, 1, D_004C0D10, 0x21F);
            return 0;
        }
        s->f2588 = 0;
        s->f258C = 0;
        func_00449A00(s);
        func_00449D20(s, 0);
    } else if (Online44A810(s) && id == s->f2480 && !func_00449180(s)) {
        func_00451B00(s, 1, D_004C0D10, 0x231);
        return 0;
    }
    return 1;
}

