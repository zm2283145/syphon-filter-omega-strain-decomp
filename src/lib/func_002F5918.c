typedef struct {
    unsigned int rd;
    unsigned int wr;
    unsigned int size;
    unsigned int count;
    unsigned char *buf;
    int flag;
} Ring2F5918;
extern int func_002F5818(Ring2F5918 *r, unsigned int *avail);
int func_002F5918(Ring2F5918 *r, unsigned char **out)
{
    int ret = 2;
    unsigned int avail = 0;    if (r != 0) {
        if (out != 0) {
            ret = func_002F5818(r, &avail);
            if (ret != 0) return ret;
            if (avail != 0) {
                *out = r->buf + r->rd;
            } else return 1;
            ret = 0;
        }
    }
    return ret;
}