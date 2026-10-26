/*
 * lib/medius: 2 files, 00307DD8-00308048
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00307DD8 */
typedef struct { int state; char pad4[0x30]; char q34[0x50]; int f84; char pad88[8]; } RtPeer;
typedef struct {
    int f0; RtPeer *peers; int f8; char q[0x20]; unsigned int npeers;
} RtUdp;
typedef struct {
    unsigned char flags; unsigned char b1;
    unsigned short len; unsigned int seq4; unsigned int seq;
} RtHdr;
extern int rt_list_buf_get_head(void *list, void **pkt);
extern char *rt_list_buf_get_data_ptr(void *pkt);
extern int rt_list_buf_get_data_size(void *pkt);
extern void *rt_list_buf_get_next(void *pkt);
extern void rt_list_buf_remove(void *list, void *pkt);
extern void *memcpy(void *d, const void *s, unsigned int n);
int RtUdp_Read(RtUdp *r, unsigned int idx, void *dst, unsigned int max, unsigned int *out)
{
    void *p = 0;
    RtHdr h;
    RtPeer *e;
    int ret = 1;
    if (r == 0) return ret;
    if (dst == 0) return ret;
    if (max == 0) return ret;
    if (out == 0) return ret;
    *out = 0;
    if (idx == (unsigned)-2) {
        if (rt_list_buf_get_head(r->q, &p) != 0) return 10;
        if (p == 0 || rt_list_buf_get_data_size(p) == 0) { *out = 0; return 0; }
        memcpy(&h, rt_list_buf_get_data_ptr(p) + 0x12, sizeof(h));
        *out = (h.len >= max) ? max : h.len;
        memcpy(dst, rt_list_buf_get_data_ptr(p) + 0x1E, *out);
        rt_list_buf_remove(r->q, p);
        return 0;
    }
    if (idx < r->npeers) {
    e = &r->peers[idx];
    if (e->state != 12) return 4;
    if (rt_list_buf_get_head(e->q34, &p) != 0) return 10;
    while (p != 0) {
        if (rt_list_buf_get_data_size(p) != 0) {
            memcpy(&h, rt_list_buf_get_data_ptr(p), sizeof(h));
            if ((*(unsigned int *)&h & 6) == 6 || (h.flags & 4)) {
                if (h.seq == e->f84 + 1 || e->f84 == 0) {
                *out = (h.len >= max) ? max : h.len;
                memcpy(dst, rt_list_buf_get_data_ptr(p) + 0xC, *out);
                rt_list_buf_remove(e->q34, p);
                e->f84 = h.seq;
                if (e->f84 == (unsigned)-1) e->f84 = 0;
                return 0;
                }
            } else {
            *out = (h.len >= max) ? max : h.len;
            memcpy(dst, rt_list_buf_get_data_ptr(p) + 0xC, *out);
            rt_list_buf_remove(e->q34, p);
            return 0;
            }
        }
        p = rt_list_buf_get_next(p);
    }
    *out = 0;
    return 0;
    }
    return 1;
}
/* merge_units: end func_00307DD8 */

/* merge_units: begin func_00308048 */
int rt_udp_peek(RtUdp *r, unsigned int idx, void *dst, unsigned int max, unsigned int *out)
{
    void *p = 0;
    RtHdr h;
    RtPeer *e;
    int ret = 1;
    if (r == 0) return ret;
    if (dst == 0) return ret;
    if (max == 0) return ret;
    if (out == 0) return ret;
    *out = 0;
    if (idx == (unsigned)-2) {
        if (rt_list_buf_get_head(r->q, &p) != 0) return 10;
        if (p == 0 || rt_list_buf_get_data_size(p) == 0) { *out = 0; return 0; }
        memcpy(&h, rt_list_buf_get_data_ptr(p) + 0x12, sizeof(h));
        *out = (h.len >= max) ? max : h.len;
        memcpy(dst, rt_list_buf_get_data_ptr(p) + 0x1E, *out);
        return 0;
    }
    if (idx < r->npeers) {
    e = &r->peers[idx];
    if (e->state != 12) return 4;
    if (rt_list_buf_get_head(e->q34, &p) != 0) return 10;
    while (p != 0) {
        if (rt_list_buf_get_data_size(p) != 0) {
            memcpy(&h, rt_list_buf_get_data_ptr(p), sizeof(h));
            if ((*(unsigned int *)&h & 6) == 6 || (h.flags & 4)) {
                if (h.seq == e->f84 + 1 || e->f84 == 0) {
                *out = (h.len >= max) ? max : h.len;
                memcpy(dst, rt_list_buf_get_data_ptr(p) + 0xC, *out);
                return 0;
                }
            } else {
            *out = (h.len >= max) ? max : h.len;
            memcpy(dst, rt_list_buf_get_data_ptr(p) + 0xC, *out);
            return 0;
            }
        }
        p = rt_list_buf_get_next(p);
    }    *out = 0;
    return 0;
    }
    return 1;
}
/* merge_units: end func_00308048 */
