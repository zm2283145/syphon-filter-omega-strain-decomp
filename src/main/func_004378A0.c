typedef struct { int max; int ver; int flags; unsigned char mode; } Prm78A0;
extern int func_002E9B60(void);
extern int func_002E9BE8(int* db, int offset, int size, int count, int type, Prm78A0* prm);
extern int func_002E9CD0(int* table, char* name, int size);
extern int func_002E9D88(int table, void* a, void* b, void* c);
extern int D_00583868;
extern void func_00437830();
extern void func_00437640();
extern void func_004375D0();

unsigned char func_004378A0(void)
{
    int db;
    Prm78A0 prm;
    unsigned char ok;
    ok = 0;
    prm.max = 1000;
    prm.ver = 1;
    prm.mode = 0;
    prm.flags = 0;
    if (func_002E9B60() == 0 &&
        func_002E9BE8(&db, 0, 1, 1, 1, &prm) == 0 &&
        func_002E9CD0(&D_00583868, "HeadsetSemaphore", 1) == 0) {
        func_002E9D88(D_00583868, func_00437830, func_00437640, func_004375D0);
        ok = 1;
    }
    return ok;
}
