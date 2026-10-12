#include "types.h"
#include "npc_info_rec.h"
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm_335F0;
extern int func_002E9B60(void);
extern int func_002E9BE8(int* db, int offset, int size, int count, int type, Prm_335F0* prm);
extern int func_002E9CD0(int* table, char* name, int size);
extern int func_002E9D88(int table, void* a, void* b, void* c);
extern int D_00582A70;
extern void func_00433160();
extern void func_00432230();
extern void func_004321D0();

static inline void Reset_335F0(NpcInfoRec* r)
{
    int j;
    r->key = -1;
    r->b4 = 0xFF;
    r->state = 0xFF;
    for (j = 0; j < 4; j++) { r->a6[j] = 0; r->aA[j] = 1; }
}

unsigned char func_004335F0(void)
{
    int db;
    Prm_335F0 prm;
    NpcInfoRec def;
    NpcInfoRec arr[29];
    unsigned char ok = 0;
    NpcInfoRec* p;
    int i;
    int err;
    Reset_335F0(&def);
    p = arr;
    do { Reset_335F0(p); p++; } while (p != arr + 29);
    prm.ver = 1;
    prm.flags = 0;
    prm.max = 100;
    prm.mode = 0x40;
    if (func_002E9B60() == 0) {
        NpcInfoRec* q = arr;
        NpcInfoRec* base = q;
        for (i = 0; i < 29; i++, q++)
            err = func_002E9BE8(&db, (char*)q - (char*)base, 1, 1, 0x10, &prm);
        if (err == 0 && func_002E9CD0(&D_00582A70, "tNPCInfoStruct", 0x1D0) == 0) {
            func_002E9D88(D_00582A70, func_00433160, func_00432230, func_004321D0);
            ok = 1;
        }
    }
    return ok;
}



