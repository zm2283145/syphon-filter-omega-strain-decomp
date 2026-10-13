typedef struct {
    unsigned int rd;
    unsigned int wr;
    unsigned int size;
    unsigned int count;
    unsigned char *buf;
    int flag;
} Ring2F59F8;
/* Reports whether the ring buffer is full (read position caught up with a non-empty buffer). */
int func_002F59F8(Ring2F59F8 *r, unsigned char *full)
{
    int ret = 2;
    int valid = r != 0;
    if (r != 0) {
        if (full != 0) {
            if (r->rd < r->wr) *full = 0;
            else if (r->count == 0) *full = 0;
            else if (r->rd == 0) *full = 0;
            else *full = valid;
            ret = 0;
        }
    }
    return ret;
}
