#include "types.h"
typedef struct { char pad[4]; unsigned char state; } E4440;
extern void func_004355D0(int a);
extern E4440* func_004361C0(int key, int b);
int func_00434440(int a, int key) {
    E4440* p;
    func_004355D0(a);
    p = func_004361C0(key, 0);
    if (p != 0 && p->state != 0xFF) return p->state;
    return -1;
}
