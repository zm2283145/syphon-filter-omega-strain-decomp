#include "types.h"

typedef struct Counter48 {
    char pad00[0x14];
    int count;          /* 0x14 */
    char pad18[0x28];
    void* lock;         /* 0x40 */
    char pad44[4];
    long long total;    /* 0x48 */
} Counter48;

extern void WaitSema(void* lock);
extern void SignalSema(void* lock);

/* Under the lock, adds n to both counters. */
void func_003F5350(Counter48* c, int n) {
    WaitSema(c->lock);
    c->count += n;
    c->total += n;
    SignalSema(c->lock);
}
