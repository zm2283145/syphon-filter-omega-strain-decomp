#include "types.h"

typedef union Name8E030 {
    __int128 q;
    char c[16];
} Name8E030;

typedef struct Part8E030 {
    Name8E030 name;
    char pad10[0x10];
} Part8E030;

typedef struct Obj8E030 {
    char pad0000[0x90];
    Part8E030 parts[0x111];
    char pad22B0[0x10];
    short texA[0x20];           /* 0x22C0 */
    short texB[0x20];           /* 0x2300 */
} Obj8E030;

extern int D_00539248;
extern short func_00381F30(int lib, __int128 name);
extern short TexCache_LoadErrorTexture(int lib);

void func_0038E030(Obj8E030* o)
{
    int lib = D_00539248;
    int i;
    for (i = 0; (long)o->parts[i].name.q != 0; i++) {
        Name8E030 n;
        n.q = o->parts[i].name.q;
        o->texA[i] = func_00381F30(lib, n.q);
        if (o->texA[i] == -1)
            o->texA[i] = TexCache_LoadErrorTexture(lib);
        n.c[14] = '1';
        o->texB[i] = func_00381F30(lib, n.q);
        if (o->texB[i] == -1)
            o->texB[i] = o->texA[i];
    }
}

