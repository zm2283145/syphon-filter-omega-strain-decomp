typedef struct {
    unsigned int rd;
    unsigned int wr;
    unsigned int size;
    unsigned int count;
    unsigned char *buf;
    int flag;
} Ring2F5460;

extern int func_002F5898(Ring2F5460 *r, unsigned int *avail);
extern int func_002F56F8(Ring2F5460 *r, unsigned char flag);

/* Commits n written bytes to a ring buffer (advances the write index with wrap). */
int NetRing_Commit(Ring2F5460 *r, unsigned int n)
{
    int ret = 2;
    unsigned int avail = 0;
    unsigned int rem;

    if (r != 0) {
        if (n != 0) {
            ret = func_002F5898(r, &avail);
            if (ret != 0) return ret;
            if (avail >= n) {
                do {
                    rem = r->size - r->wr;
                    if (n < rem) r->wr += n;
                    else r->wr = n - rem;
                    r->count += n;
                } while (0);
                ret = func_002F56F8(r, 0);
                if (ret != 0) return ret;
            } else return 1;
        }
        ret = 0;
    }
    return ret;
}
