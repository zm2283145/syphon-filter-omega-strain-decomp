#include "types.h"
typedef struct { char name[0x15]; char id[0x13]; int mode; } R445;
typedef struct { char pad[0x1B8]; int f1b8; char pad2[0x90]; int f24c; char pad3[0x234]; char f484[0x11C]; signed char c5a0; char pad4[0x1E6F]; int f2410; char p2414[4]; char f2418[0x20]; } O445;
extern void func_00452F70(O445*, int, int);
extern void* memset(void*, int, int);
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern int func_0046A8F8(R445*, void*);
extern void func_004473C0();
extern void func_00451B00(O445*, int, char*, int);
extern int func_004534A0(O445*, int, int, int);
extern char D_004C0B60[];
extern int D_00497890;
int func_004456E0(O445* o, int mode) {
    R445 rec;
    char* s;
    func_00452F70(o, 2, 5);
    memset(&rec, 0, 0x2C);
    memset(o->f484, 0, 0x120);
    if (mode == 0) s = "USAGE";
    else s = "PRIVACY";
    String_Copy(rec.name, s);
    String_Copy(rec.id, o->f2418);
    rec.mode = mode;
    o->f1b8 = 0;
    o->f2410 = func_00443E70();
    o->f24c = func_0046A8F8(&rec, func_004473C0);
    while (o->c5a0 != 1) {
        func_00452F70(o, 0, 0);
        if (o->f24c != 0) {
            func_00451B00(o, 0x15, D_004C0B60, 0x22C);
            return 0;
        }
        if (!func_004534A0(o, o->f2410, D_00497890, 0)) {
            func_00451B00(o, 2, D_004C0B60, 0x233);
            return 0;
        }
    }
    func_00451B00(o, 0, D_004C0B60, 0x237);
    return 1;
}
