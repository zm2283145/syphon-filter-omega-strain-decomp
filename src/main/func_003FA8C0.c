#include "types.h"

typedef struct { char pad[8]; int a; unsigned char flag; char pad2[3]; int b; } MapEntry;

extern char D_0055C7A0[];
extern MapEntry* NetRecvMap_Insert(void* map, int* key);

/* Looks up key in the global map and stores a, b and flag in the entry. */
void func_003FA8C0(int a, int key, int b, unsigned char flag)
{
    NetRecvMap_Insert(D_0055C7A0, &key)->a = a;
    NetRecvMap_Insert(D_0055C7A0, &key)->b = b;
    NetRecvMap_Insert(D_0055C7A0, &key)->flag = flag;
}
