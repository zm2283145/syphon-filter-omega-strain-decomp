#include "types.h"
typedef struct {
    char p0[0x70]; char f70[0xE84 - 0x70]; int fE84; char pE88[0x1B38 - 0xE88];
    int f1B38; char p1B3C[0x1B80 - 0x1B3C]; int f1B80; char p1B84[0x1EA4 - 0x1B84];
    int f1EA4; char p1EA8[0x23E4 - 0x1EA8]; void* f23E4; int p23E8; void* f23EC;
    char p23F0[0x255C - 0x23F0]; int state; char p2560[0x2588 - 0x2560];
    int f2588; int f258C; char p2590[0x265C - 0x2590]; unsigned char f265C; unsigned char f265D;
    char p265E[0x26A8 - 0x265E]; int f26A8;
} SLB;
extern void String_Copy(char*, char*);
extern int sprintf(char*, const char*, ...);
extern int func_00443E70(void);
extern void func_00451AE0(void);
extern void func_00451B00(SLB*, int, char*, int);
extern int func_00449A00(SLB*);
extern void func_00449D20(SLB*, int);
extern void func_0044A290(SLB*);
extern void func_00452FC0(SLB*, int);
extern void func_00453FB0(SLB*);
extern void func_0044F810(void*);
extern void func_0044F6B0(void*);
extern void func_0044F880(void*, int, int, int);
extern int func_00451ED0(SLB*, char*);
extern int func_004524C0(SLB*, char*, char*);
extern int func_00452050(SLB*, int, char*);
extern void func_00454010(char*);
extern void func_00454050(SLB*);
extern int D_00497800;
extern char D_004C0D10[];
extern char D_004C0D30[];
extern char D_004C0D40[];
static inline void ClearLists(SLB* s)
{
    if (s->f23E4) func_0044F6B0(s->f23E4);
    s->f23E4 = 0;
    if (s->f23EC) func_0044F6B0(s->f23EC);
    s->f23EC = 0;
}static inline int Online2(SLB* s)
{
    int last = s->f2588;
    int elapsed = func_00443E70() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(s);
    }
    return s->f265D;
}
int func_0044B420(SLB* s, int mode, void* a, void* b)
{
    char key[0x60];
    char name[0x100];
    char path[0x40];

    func_00451AE0();
    if (s->state != 9) {
        func_00451B00(s, 1, D_004C0D10, 0x27);
        return 0;
    }
    func_00452FC0(s, mode);
    s->f23E4 = a;
    s->f23EC = b;
    func_0044F880(s->f23EC, s->f1EA4, 0, 0x68);
    func_0044F880(s->f23E4, 0x40, 0x20, 0x50);
    s->f2588 = 0;
    if (!func_00449A00(s)) {
        ClearLists(s);
        return 0;
    }
    func_00449D20(s, 1);
    func_0044A290(s);
    s->f2588 = 0;
    s->f258C = 0;
    if (Online2(s) && s->f26A8 != 3) {
        s->f26A8 = 0;
        func_00454010(key);
        String_Copy(name, D_004C0D30);
        sprintf(path, D_004C0D40, s->fE84);
        if (!func_00451ED0(s, path)) {
            if (!func_004524C0(s, path, name)) {
                func_00451B00(s, 0x17, D_004C0D10, 0x59);
                ClearLists(s);
                return 0;
            }
            if (!func_00452050(s, s->f1B38, key)) {
                func_00451B00(s, 0x16, D_004C0D10, 0x60);
                ClearLists(s);
                return 0;
            }
        } else if (!func_00452050(s, s->f1B80, key)) {
            if (!func_004524C0(s, path, name)) {
                func_00451B00(s, 0x17, D_004C0D10, 0x6C);
                ClearLists(s);
                return 0;
            }
            if (!func_00452050(s, s->f1B38, key)) {
                func_00451B00(s, 0x16, D_004C0D10, 0x73);
                ClearLists(s);
                return 0;
            }
        }
        s->f26A8 = 3;
    }
    func_00454050(s);
    s->state = 7;
    return 1;
}
