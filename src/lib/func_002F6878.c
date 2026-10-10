#include "types.h"
typedef struct { int pad0[2]; int count; int padC[2]; int bytes; } Counter;
typedef struct { Counter a; Counter b; } Stats;
extern Stats D_00525508;
extern void func_002F68F0(void);
/* Accounts one transfer of (len + overhead) bytes in the send and/or receive counters. */
void func_002F6878(int sendLen, int recvLen, int overhead)
{
    if (sendLen != 0) {
        D_00525508.a.count++;
        D_00525508.a.bytes += sendLen + overhead;
    }
    if (recvLen != 0) {
        D_00525508.b.count++;
        D_00525508.b.bytes += recvLen + overhead;
    }
    func_002F68F0();
}
