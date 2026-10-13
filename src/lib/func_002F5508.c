typedef struct { unsigned int rd; unsigned int wr; unsigned int size; unsigned int count; char *buf; } Ring;
extern int func_002F5898(Ring *, unsigned int *);
extern void *memcpy(void *, const void *, unsigned int);
int func_002F5508(Ring *r, char *src, unsigned int n)
{
    int ret = 2;
    unsigned int space = 0;
    unsigned int tail;
    if (r == 0) return ret;
    if (src == 0) return ret;
    if (n == 0) return ret;
    ret = func_002F5898(r, &space);
    if (ret != 0) return ret;
    if (space >= n) {
        tail = r->size - r->wr;
        if (tail >= n) {
            memcpy(r->buf + r->wr, src, n);
            r->count += n;
            r->wr += n;
            if (r->wr == r->size) r->wr = 0;
        } else {
            memcpy(r->buf + r->wr, src, tail);
            n -= tail;
            r->count += tail;
            memcpy(r->buf, src + tail, n);
            r->count += n;
            r->wr = n;
        }
        return 0;
    }
    return 1;
}
