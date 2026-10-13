#pragma cplusplus on
typedef struct { void* src; void* dest; int size; int attr; } Dma3F6630;
extern "C" {
void FlushCache(int);
int sceSifSetDma(Dma3F6630*, int);
}
static inline void Send3F6630(void* src, void* dest, int size)
{
    Dma3F6630 t;
    FlushCache(0);
    t.src = src;
    t.dest = dest;
    t.size = size;
    t.attr = 0;
    while (sceSifSetDma(&t, 1) == 0) {
    }
}
extern "C" int func_003F6630(void* self, char* dst, int len, char* dst2, int len2, char* src, int n1, char* src2, int n2)
{
    if (len + len2 < n1 + n2) {
        int over = (n1 + n2) - (len + len2);
        if (over >= n2) {
            n1 -= over - n2;
            n2 = 0;
        } else {
            n2 -= over;
        }
    }
    if (n1 >= len) {
        int r;
        if (len > 0) Send3F6630(src, dst, len);
        r = n1 - len;
        if (r > 0) Send3F6630(src + len, dst2, r);
        if (n2 > 0) Send3F6630(src2, dst2 + n1 - len, n2);
    } else {
        int r = len - n1;
        if (n2 >= r) {
            int r2;
            if (n1 > 0) Send3F6630(src, dst, n1);
            if (r > 0) Send3F6630(src2, dst + n1, r);
            r2 = n2 - r;
            if (r2 > 0) Send3F6630(src2 + len - n1, dst2, r2);
        } else {
            if (n1 > 0) Send3F6630(src, dst, n1);
            if (n2 > 0) Send3F6630(src2, dst + n1, n2);
        }
    }
    return n1 + n2;
}