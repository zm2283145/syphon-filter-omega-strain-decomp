#include "types.h"
typedef struct { char pad[5]; unsigned char state; } E4380;
extern void func_004355D0(int a);
extern E4380* func_004361C0(int key, int b);
int func_00434380(int a, int key) {
    E4380* p;
    func_004355D0(a);
    p = func_004361C0(key, 0);
    if (p != 0 && p->state != 0xFF) return p->state;
    return -1;
}
