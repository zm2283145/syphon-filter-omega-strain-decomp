#include "types.h"

typedef struct LockedBuf {
    char pad00[0x14];
    int size;   /* 0x14 */
    char pad18[0x28];
    void* lock; /* 0x40 */
} LockedBuf;

extern void WaitSema(void* lock);
extern void SignalSema(void* lock);

/* Under the lock, rounds the size up to a multiple of 0x800. */
void viBufFlush(LockedBuf* buf) {
    WaitSema(buf->lock);
    buf->size = (buf->size + 0x7FF) / 0x800 * 0x800;
    SignalSema(buf->lock);
}
