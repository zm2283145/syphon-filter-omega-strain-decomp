#include "types.h"
typedef struct {
    int a[5];
    char pad0[0x12C - 0x14];
    int b[4];
    char pad1[0x258 - 0x13C];
    char c;
    char pad2[0x2A4 - 0x259];
} Data7A00;
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm7A00;
extern int func_002E9B60(void);
extern int func_002E9BE8(int* db, int offset, int size, int count, int type, Prm7A00* prm);
extern int func_002E9CD0(int* table, char* name, int size);
extern int func_002E9D88(int table, void* a, void* b, void* c);
extern char D_004AC9A0[];
extern int D_0051EE80;
extern void func_002C7BA0(void);
extern void func_002C7B30(void);
extern void func_002C7B20(void);
unsigned char func_002C7A00(void)
{
    int db;
    int table;
    Prm7A00 prm;
    Data7A00 data;
    Data7A00* d;
    unsigned char ok;
    int err;
    ok = 0;
    prm.max = 0x64;
    prm.ver = 1;
    prm.mode = 0;
    prm.flags = 0;
    if (func_002E9B60() == 0 &&
        func_002E9BE8(&db, 0, 4, 5, 0x4B, &prm) == 0) {
        d = &data;
        if (func_002E9BE8(&db, (char*)data.b - (char*)d, 4, 4, 0x4B, &prm) == 0 &&
            (err = func_002E9BE8(&db, (char*)&data.c - (char*)d, 1, 0, 0x4B, &prm)) == 0 &&
            err == 0 &&
            func_002E9CD0(&table, D_004AC9A0, 0x2A4) == 0 &&
            func_002E9D88(table, func_002C7BA0, func_002C7B30, func_002C7B20) == 0) {
            ok = 1;
            D_0051EE80 = table;
        }
    }
    return ok;
}