#include "types.h"

typedef struct LockedBuf {
    char pad00[0x10];
    int index;  /* 0x10 */
    int base;   /* 0x14 */
    char pad18[0x28];
    void* lock; /* 0x40 */
} LockedBuf;

extern void WaitSema(void* lock);
extern void SignalSema(void* lock);

/* Under the lock, returns base + index * 0x800. */
int func_003F4A60(LockedBuf* buf) {
    int addr;
    WaitSema(buf->lock);
    addr = buf->base + (buf->index << 11);
    SignalSema(buf->lock);
    return addr;
}
