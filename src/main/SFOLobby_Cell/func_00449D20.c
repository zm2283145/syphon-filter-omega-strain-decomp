#include "types.h"
typedef struct {
    char p0[0xC4];
    char fC4[0x188];
    int f24C;           /* 0x24C */
    char p250[0xC34];
    int fE84;           /* 0xE84 */
    char pE88[0x1C8];
    char f1050[0x1D8];  /* 0x1050 */
    signed char f1228;  /* 0x1228 */
    char p1229[0x11DF];
    signed char busy;   /* 0x2408 */
    char p2409[7];
    int f2410;          /* 0x2410 */
    char p2414[0x174];
    int f2588;          /* 0x2588 */
    char p258C[0xD1];
    unsigned char f265D;
} S449D20;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00449A00(S449D20*);
extern void func_0044F7E0(void*);
extern void func_0044F160(void*, int);
extern void func_00451B00(S449D20*, int, char*, int);
extern void func_00452F70(S449D20*, int, int);
extern int func_004534A0(S449D20*, int, int, int);
extern int func_00467BE0(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497800;
extern int D_00497890;
extern char D_004C0D10[];
extern char D_004C0D38[];
extern char func_004487A0[];
int func_00449D20(S449D20* s, int wait)
{
    struct { char a[0x18]; int x; int y; int z; } req;
    int last = s->f2588;
    int elapsed = func_00443E70() - last;

    if (last == 0 || D_00497800 < elapsed)
        func_00449A00(s);
    if (s->f265D == 0)
        return 1;
    func_0044F7E0(s->fC4);
    func_0044F160(s->fC4, 0);
    last = s->f2588;
    elapsed = func_00443E70() - last;
    if (last == 0 || D_00497800 < elapsed)
        func_00449A00(s);
    if (s->fE84 < 0) {
        func_00451B00(s, 1, D_004C0D10, 0x44D);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    memset(s->f1050, 0, 0x1DC);
    s->f2410 = func_00443E70();
    String_Copy(req.a, D_004C0D38);
    req.x = s->fE84;
    req.y = 0;
    req.z = 0;
    s->f24C = func_00467BE0(&req, func_004487A0);
    if (s->f24C != 0) {
        func_00451B00(s, 1, D_004C0D10, 0x460);
        return 0;
    }
    if (wait) {
        while (s->f1228 != 1) {
            func_00452F70(s, 0, 0);
            if (s->f24C != 0) {
                func_00451B00(s, 1, D_004C0D10, 0x46D);
                s->busy = 0;
                return 0;
            }
            if (func_004534A0(s, s->f2410, D_00497890, 0) == 0) {
                func_00451B00(s, 2, D_004C0D10, 0x475);
                s->busy = 0;
                return 0;
            }
        }
    }
    return 1;
}
