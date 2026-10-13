typedef struct {
    unsigned int rd;
    unsigned int wr;
    unsigned int size;
    unsigned int count;
    unsigned char *buf;
    int flag;
} Ring2F53B8;

extern int func_002F5818(Ring2F53B8 *r, unsigned int *avail);
extern int func_002F56F8(Ring2F53B8 *r, unsigned char flag);

/* Consumes n bytes from a ring buffer (advances the read index with wrap). */
int func_002F53B8(Ring2F53B8 *r, unsigned int n)
{
    int ret = 2;
    unsigned int avail = 0;
    unsigned int rem;

    if (r != 0) {
        if (n != 0) {
            ret = func_002F5818(r, &avail);
            if (ret != 0) return ret;
            if (avail >= n) {
                do {
                    rem = r->size - r->rd;
                    if (n < rem) r->rd += n;
                    else r->rd = n - rem;
                    r->count -= n;
                } while (0);
                ret = func_002F56F8(r, 0);
                if (ret != 0) return ret;
            } else return 1;
        }
        ret = 0;
    }
    return ret;
}
