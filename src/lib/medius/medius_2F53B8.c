/*
 * lib/medius: 3 files, 002F53B8-002F5508
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F53B8 */
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
/* merge_units: end func_002F53B8 */

/* merge_units: begin func_002F5460 */
typedef struct {
    unsigned int rd;
    unsigned int wr;
    unsigned int size;
    unsigned int count;
    unsigned char *buf;
    int flag;
} Ring2F5460;

extern int func_002F5898(Ring2F5460 *r, unsigned int *avail);
#if 0 /* merge_units */
extern int func_002F56F8(Ring2F5460 *r, unsigned char flag);
#endif /* merge_units */
#define func_002F56F8(a0, a1) (func_002F56F8((Ring2F53B8 *)(a0), (a1))) /* merge_units */


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
#undef func_002F56F8 /* merge_units */
/* merge_units: end func_002F5460 */

/* merge_units: begin func_002F5508 */
typedef struct { unsigned int rd; unsigned int wr; unsigned int size; unsigned int count; char *buf; } Ring;
#if 0 /* merge_units */
extern int func_002F5898(Ring *, unsigned int *);
#endif /* merge_units */
#define func_002F5898(a0, a1) (func_002F5898((Ring2F5460 *)(a0), (a1))) /* merge_units */

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
#undef func_002F5898 /* merge_units */
/* merge_units: end func_002F5508 */
