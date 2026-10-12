#include "types.h"

typedef struct Ring3F5 {
    char pad[0x48];
    char ring[0x60]; /* 0x48 */
    int state;       /* 0xA8 */
} Ring3F5;

extern void func_003F53B0(void* ring, unsigned int* p1, int* n1, unsigned int* p2, int* n2);
extern void func_003F5350(void* ring, int n);
extern void func_003F4A10(void* ring);
extern void* memcpy(void* d, const void* s, unsigned int n);
typedef struct { float f; } F4; extern F4 D_004939E8;

static inline int Ring_Write2(void* ring, char* d1, int n1, char* d2, int n2,
                              const char* a, int alen, const char* b, int blen)
{
    int written;
    if (n1 + n2 < alen + blen) {
        written = 0;
    } else {
        if (n1 <= alen) {
            memcpy(d1, a, n1);
            memcpy(d2, a + n1, alen - n1);
            memcpy(d2 + alen - n1, b, blen);
        } else if (!(blen < n1 - alen)) {
            memcpy(d1, a, alen);
            memcpy(d1 + alen, b, n1 - alen);
            memcpy(d2, b + n1 - alen, blen - (n1 - alen));
        } else {
            memcpy(d1, a, alen);
            memcpy(d1 + alen, b, blen);
        }
        written = alen + blen;
    }
    func_003F5350(ring, written);
    return written;
}

int func_003F5AE0(Ring3F5* self)
{
    unsigned int p1;
    unsigned int p2;
    F4 val;
    int n1;
    int n2;
    char* d1;
    char* d2;

    val = D_004939E8;
    func_003F53B0(self->ring, &p1, &n1, &p2, &n2);
    if (n1 + n2 < 4) {
        return 0;
    }
    d1 = (char*)((p1 & 0x0FFFFFFF) | 0x20000000);
    d2 = (char*)((p2 & 0x0FFFFFFF) | 0x20000000);
    Ring_Write2(self->ring, d1, n1, d2, n2, (const char*)&val, 4, 0, 0);
    func_003F4A10(self->ring);
    if (self->state == 0) {
        self->state = 2;
    }
    return 1;
}


