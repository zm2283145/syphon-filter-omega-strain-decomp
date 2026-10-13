typedef struct {
    unsigned int rd;
    unsigned int wr;
    unsigned int size;
    unsigned int count;
    unsigned char *buf;
    int flag;
} Ring2F5988;
extern int func_002F5898(Ring2F5988 *r, unsigned int *avail);
/* Returns a pointer to the ring buffer's write position if space is free. */
int func_002F5988(Ring2F5988 *r, unsigned char **out)
{
    int ret = 2;
    unsigned int avail = 0;
    if (r != 0) {
        if (out != 0) {
            ret = func_002F5898(r, &avail);
            if (ret != 0) return ret;
            if (avail != 0) {
                *out = r->buf + r->wr;
            } else return 1;
            ret = 0;
        }
    }
    return ret;
}
