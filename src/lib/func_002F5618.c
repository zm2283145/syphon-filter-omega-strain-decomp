typedef struct {
    unsigned int rd;
    unsigned int wr;
    unsigned int size;
    unsigned int count;
    unsigned char *buf;
    int flag;
} Ring2F5618;
extern int func_002F5818(Ring2F5618 *r, unsigned int *avail);
extern int func_002F5840(Ring2F5618 *r, unsigned int *avail);
extern void *memcpy(void *, const void *, unsigned int);
int func_002F5618(unsigned char *dst, Ring2F5618 *r, unsigned int n)
{
    int ret = 2;
    unsigned int avail = 0;
    unsigned int cont = 0;    if (dst != 0) {
        if (r != 0) {
            if (n != 0) {
            ret = func_002F5818(r, &avail);
            if (ret != 0) return ret;
            if (avail >= n) {
                ret = func_002F5840(r, &cont);
                if (ret != 0) return ret;
                if (cont >= n) {
                    memcpy(dst, r->buf + r->rd, n);
                } else {
                    memcpy(dst, r->buf + r->rd, cont);
                    memcpy(dst + cont, r->buf, n - cont);
                }
            } else return 1;
            ret = 0;            }
        }
    }
    return ret;
}
