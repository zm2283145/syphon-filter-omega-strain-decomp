#include "types.h"
typedef struct { int id; unsigned int a : 4; unsigned int b : 4; } T_438AE0;
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm_38AE0;
extern int func_002E9B60(void);
extern int func_002E9BE8(int* db, int offset, int size, int count, int type, Prm_38AE0* prm);
extern int func_002E9CD0(int* table, char* name, int size);
extern int func_002E9D88(int table, void* a, void* b, void* c);
extern int D_00497570;
extern void func_00439560();
extern void func_00439390();
extern void func_00438C20();

static inline void Reset_38AE0(T_438AE0* r)
{
    r->id = -1;
    r->a = 15;
    r->b = 0;
}

unsigned char func_00438AE0(void)
{
    int db;
    Prm_38AE0 prm;
    T_438AE0 arr[55];
    unsigned char ok = 0;
    T_438AE0* p;
    int i;
    int err;
    p = arr;
    do { Reset_38AE0(p); p++; } while (p != arr + 55);
    prm.flags = 0;
    prm.max = 500;
    prm.ver = 1;
    prm.mode = 0x40;
    if (func_002E9B60() == 0) {
        T_438AE0* q = arr;
        T_438AE0* base = q;
        for (i = 0; i < 55; i++, q++)
            err = func_002E9BE8(&db, (char*)q - (char*)base, 1, 1, 8, &prm);
        if (err == 0 && func_002E9CD0(&D_00497570, "tGenInfoStruct", 0x1B8) == 0) {
            func_002E9D88(D_00497570, func_00439560, func_00439390, func_00438C20);
            ok = 1;
        }
    }
    return ok;
}
