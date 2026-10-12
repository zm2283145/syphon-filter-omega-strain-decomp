#include "types.h"
typedef unsigned long u64_7D90;
typedef struct { char pad[8]; char* src; unsigned int len; long f10; long f18; } Pkt_7D90;
typedef struct { char data[0x50008]; int end; } Ring_7D90;
extern char D_0055C480[];
extern void func_003F5D50(void* s, int* a, int* sz, int* b, int* bsz);
extern void func_003F5C90(void* s, long a, long b, int c, int n);
extern void func_003F5D40(void* s, int n);
extern void* memcpy(void* d, const void* s, unsigned int n);
int func_003F7D90(void* self, Pkt_7D90* p, Ring_7D90* r)
{
    int sz;
    unsigned int n1;
    int n2;
    char* d1;
    int total;
    char* src;
    char* d2;
    unsigned int len;
    int a, b, asz, bsz;
    src = p->src;
    len = p->len;
    n1 = (unsigned int)((char*)r + r->end - src);
    n1 = n1 < len ? n1 : len;
    n2 = len - n1;
    func_003F5D50(D_0055C480, &a, &asz, &b, &bsz);
    total = n1 + n2;
    sz = asz;
    d1 = (char*)(((unsigned int)a & 0x0FFFFFFF) | 0x20000000);
    d2 = (char*)(((unsigned int)b & 0x0FFFFFFF) | 0x20000000);
    if (sz + bsz < total) {
        total = 0;
    } else if ((int)n1 >= sz) {
        memcpy(d1, src, sz);
        memcpy(d2, src + sz, n1 - sz);
        memcpy(d2 + n1 - sz, r, n2);
    } else {
        int rest = sz - n1;
        if (n2 >= rest) {
            memcpy(d1, src, n1);
            memcpy(d1 + n1, r, rest);
            memcpy(d2, (char*)r + sz - n1, n2 - rest);
        } else {
            memcpy(d1, src, n1);
            memcpy(d1 + n1, r, n2);
        }
    }
    if (total > 0)
        func_003F5C90(D_0055C480, p->f10, p->f18, a, total);
    func_003F5D40(D_0055C480, total);
    return total > 0;
}
