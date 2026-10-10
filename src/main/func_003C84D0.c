#include "types.h"

extern char D_00537F80[];
extern unsigned long long* func_00375C30(void* q, int a, int b, int c, int d, int e);
extern void func_00375770(void* q, int a);

/* Queues a 64-bit packet built from table[index] | 0x14000000 and flushes it. */
void func_003C84D0(unsigned int* table, int index) {
    unsigned long long* p = func_00375C30(D_00537F80, 0, 1, 0, 0, 1);
    *p = table[index] | 0x14000000;
    func_00375770(D_00537F80, 0);
}
