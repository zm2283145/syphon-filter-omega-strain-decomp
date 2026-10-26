/*
 * lib/libnet: 3 files, 0034A360-0034A458
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034A360 */
typedef struct S {
    int x0;
    char pad4[0x1C - 4];
    int x1C;
    char pad20[0x3C - 0x20];
    int x3C;
} S;
extern int libnetb_get_valid_data_header_ptr(S *p, S **q, unsigned char *c);

int libnetb_is_data_waiting(S *p, unsigned char a, unsigned char b, unsigned char *out)
{
    S *q;
    unsigned char c;
    int r;

    if (!out)
        return 2;
    *out = 0;
    if (!p)
        return 2;
    if (a == 1) {
        q = 0;
        if (b == 0) {
            c = 0;
            r = libnetb_get_valid_data_header_ptr(p, &q, &c);
            if (r)
                return r;
            *out = c;
            return 0;
        }
        q = (S *)(p->x1C + p->x3C);
        if (q->x0 == 1 && q->x3C == 1)
            *out = 1;
        else
            *out = 0;
    } else {
        if (p->x0 > 0)
            *out = 1;
        else
            *out = 0;
    }
    return 0;
}
/* merge_units: end func_0034A360 */

/* merge_units: begin func_0034A418 */
typedef struct { volatile int f0; volatile int f4; volatile int f8; volatile int fC; char p[0x2C]; volatile int f3C; } H34A418;

/* Header init: returns 2 for a null pointer or a size below 0x80, else stores size-0x40 and zeroes the rest. */
int libnetb_block_init_buffer(H34A418 *p, unsigned int n) {
    H34A418 *h;
    if (p == 0) return 2;
    if (n < 0x80) return 2;
    if (n < 0x40) return 2;
    h = p;
    p = (H34A418 *)(n - 0x40);
    h->fC = (int)p;
    h->f3C = 0;
    h->f8 = (int)p;
    h->f4 = 0;
    h->f0 = 0;
    return 0;
}
/* merge_units: end func_0034A418 */

/* merge_units: begin func_0034A458 */
typedef struct { int next; int used; int size; int avail; int pad[11]; int busy; } NetBlk_458;
int libnetb_block_calc_avail(NetBlk_458 *p, unsigned int size, int *out)
{
    int total = 0;
    int n;
    if (out == 0) return 2;
    *out = 0;
    if (p == 0) return 2;
    while (size >= 0x40) {
        if (p->next != 0) break;
        if (p->busy != 0) break;
        n = p->size + 0x40;
        size -= n;
        total += n;
        p = (NetBlk_458 *)((char *)p + n);
    }
    *out = total;
    return 0;
}
/* merge_units: end func_0034A458 */
