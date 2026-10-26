#include "types.h"

extern int GetPlayerFromGroup(int, int);

int GetPlayerByID(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 108);
    return GetPlayerFromGroup(tmp0, a1);
}
