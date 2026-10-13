#include "types.h"
typedef struct { int priority; int count; int flags; unsigned char attr; } Prm_002120D0;
typedef struct { int x0; int x4; char pad8[4]; unsigned char xC; char padD[0x20 - 0xD]; int x20; int x24; int x28; int x2C; } Rec_002120D0;
extern int D_004F5478;
extern char D_004A4580[];
extern int func_002E9B60(void);
extern int func_002E9BE8(int* out, int off, int size, int count, int type, Prm_002120D0* prm);
extern int func_002E9CD0(int* out, const char* name, int size);
extern int func_002E9D88(int handle, void* f1, void* f2, void* f3);
extern unsigned char func_002129A0(Rec_002120D0* r);
extern void func_00211DE0(void);
extern void func_00211DB0(void);
extern void func_00212040(void);
void func_002120D0(void)
{
    int db;
    int handle;
    Prm_002120D0 prm;
    Rec_002120D0 rec;
    Rec_002120D0* r;
    int* p24 = &rec.x24;
    int* p2C = &rec.x2C;
    rec.x0 = 0;
    rec.x4 = 0;
    rec.xC = 0;
    rec.x20 = 0;
    *p24 = 0;
    rec.x28 = 0;
    *p2C = 0;
    prm.priority = 500;
    prm.count = 1;
    prm.attr = 0x40;
    prm.flags = 0;
    if (func_002E9B60() == 0 &&
        func_002129A0(&rec) &&
        (r = &rec, func_002E9BE8(&db, (char*)&rec.x20 - (char*)r, 4, 4, 1, &prm) == 0) &&
        func_002E9BE8(&db, (char*)p24 - (char*)r, 4, 4, 1, &prm) == 0 &&
        func_002E9BE8(&db, (char*)p2C - (char*)r, 4, 4, 1, &prm) == 0 &&
        func_002E9CD0(&handle, D_004A4580, 0x30) == 0) {
        D_004F5478 = handle;
        func_002E9D88(handle, func_00211DE0, func_00211DB0, func_00212040);
    }
}
