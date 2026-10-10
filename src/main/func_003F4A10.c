#include "types.h"

typedef struct LockedBuf {
    char pad00[0x14];
    int size;   /* 0x14 */
    char pad18[0x28];
    void* lock; /* 0x40 */
} LockedBuf;

extern void func_0010D1A0(void* lock);
extern void func_0010D180(void* lock);

/* Under the lock, rounds the size up to a multiple of 0x800. */
void func_003F4A10(LockedBuf* buf) {
    func_0010D1A0(buf->lock);
    buf->size = (buf->size + 0x7FF) / 0x800 * 0x800;
    func_0010D180(buf->lock);
}
