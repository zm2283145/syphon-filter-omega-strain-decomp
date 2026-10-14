/*
 * lib/medius: 3 files, 002F5918-002F59F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F5918 */
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
/* merge_units: end func_002F5918 */

/* merge_units: begin func_002F5988 */
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
/* merge_units: end func_002F5988 */

/* merge_units: begin func_002F59F8 */
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
/* merge_units: end func_002F59F8 */
