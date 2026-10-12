#include "types.h"
typedef struct { char p0[0x1F0]; int done; char p1F4[0x58]; int f24C; char p250[0xC34]; int fE84; char pE88[0xE7C]; int f1D04; char p1D08[0x700]; signed char busy; char p2409[0xF]; char name[0x170]; int f2588; int f258C; char p2590[0xCC]; unsigned char f265C; unsigned char f265D; } S449180;
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int func_00443E70(void);
extern void func_00449A00(S449180*);
extern void func_00451B00(S449180*, int, char*, int);
extern void func_00452F70(S449180*, int, int);
extern int func_004534A0(S449180*, int, int, int);
extern int func_00466AD0(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497800;
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_00447E30[];
int func_00449180(S449180* s)
{
    struct { char a[0x15]; char b[0x13]; int x; } req;
    int h;
    int last = s->f2588;
    int elapsed = func_00443E70() - last;

    if (last == 0 || D_00497800 < elapsed)
        func_00449A00(s);
    if (s->f265C == 0) {
        func_00451B00(s, 0x1F, D_004C0D10, 0x623);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0D38);
    strncpy(req.b, s->name, 0x11);
    req.x = s->fE84;
    s->done = 0;
    s->f1D04 = -0x3C6;
    s->f24C = func_00466AD0(&req, func_00447E30);
    if (s->f24C != 0) {
        func_00451B00(s, 1, D_004C0D10, 0x638);
        return 0;
    }
    s->busy = 1;
    h = func_00443E70();
    while (s->done == 0) {
        func_00452F70(s, 0, 0);
        if (s->f24C != 0) {
            func_00451B00(s, 1, D_004C0D10, 0x645);
            s->busy = 0;
            return 0;
        }
        if (func_004534A0(s, h, D_00497890, 0) == 0) {
            func_00451B00(s, 2, D_004C0D10, 0x64D);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    if (s->f1D04 != 0) return 0;
    s->f2588 = 0;
    s->f258C = 0;
    s->f265D = 0;
    s->f265C = 0;
    return 1;
}


