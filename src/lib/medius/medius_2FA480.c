/*
 * lib/medius: 7 files, 002FA480-002FA830
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FA480 */
extern int RemoveIntcHandler(int, int);
int get_n_intc(int a, int b, int *c)
{
    if (b >= 0) {
        int n = RemoveIntcHandler(a, b);
        if (n > 0) *c += n;
    }
    return 0;
}
/* merge_units: end func_002FA480 */

/* merge_units: begin func_002FA4C8 */
extern void *memset(void *, int, unsigned int);
extern int func_002FB2D8(int *, unsigned long);
extern int rt_list_buf_place_list_head(char *);
int rt_list_buf_create(char *s, unsigned int n)
{
    if (s == 0) return 2;
    if (n < 9) return 2;
    memset(s, 0, 0x18);
    if (func_002FB2D8((int *)(s + 0x10), n)) return 3;
    if (*(int *)(s + 0x10) == 0) return 3;
    *(int *)(s + 8) = n;
    n = rt_list_buf_place_list_head(s);
    __asm__ __volatile__("");
    return n;
}
/* merge_units: end func_002FA4C8 */

/* merge_units: begin func_002FA550 */
extern int rt_list_buf_is_valid(int *);
extern int rt_memory_free(int *);
int rt_list_buf_destroy(int *p)
{
    if (rt_list_buf_is_valid(p) == 0) return 2;
    if (p[4]) rt_memory_free(p + 4);
    memset(p, 0, 0x18);
    return 0;
}
/* merge_units: end func_002FA550 */

/* merge_units: begin func_002FA5B0 */
#if 0 /* merge_units */
extern int rt_list_buf_place_list_head(int *);
#endif /* merge_units */
#define rt_list_buf_place_list_head(a0) (rt_list_buf_place_list_head((char *)(a0))) /* merge_units */

int rt_list_buf_clear(int *p)
{
    int r;
    if (rt_list_buf_is_valid(p) == 0) return 2;
    p[0] = 0;
    p[1] = 0;
    p[3] = 0;
    r = rt_list_buf_place_list_head(p);
    __asm__ __volatile__("");
    return r;
}
#undef rt_list_buf_place_list_head /* merge_units */
/* merge_units: end func_002FA5B0 */

/* merge_units: begin func_002FA5F8 */
typedef struct N { unsigned int size; struct N *next; char data[1]; } N;
typedef struct { int x; int cur; int size; int used; char *buf; N *head; } L;
extern void *memcpy(void *, const void *, unsigned int);
#if 0 /* merge_units */
extern int rt_list_buf_is_valid(L *);
#endif /* merge_units */
#define rt_list_buf_is_valid(a0) (rt_list_buf_is_valid((int *)(a0))) /* merge_units */

extern int rt_list_buf_calc_free_contiguous_space(L *, unsigned int *);
extern int rt_list_buf_space_available(L *, N **, unsigned int);
int rt_list_buf_insert(L *l, N *n, char *data, unsigned int size)
{
    unsigned int avail = 0;
    N *m;
    int r;
    if (rt_list_buf_is_valid(l) == 0) return 2;
    if (n == 0) return 2;
    if (data == 0) return 2;
    if (size == 0) return 2;
    if (n->size == 0) {
        r = rt_list_buf_calc_free_contiguous_space(l, &avail);
        if (r) return r;
        if (avail >= size) {
        n->size = size;
        n->next = 0;
        memcpy(n->data, data, size);
        l->cur = l->cur + ((size + 3) & ~3);
        l->used = l->used + ((size + 3) & ~3);
        } else return 3;
    } else {
        r = rt_list_buf_space_available(l, &n, size + 8);
        if (r) return r;
        m = (N *)(l->buf + l->cur);
        m->next = n->next;
        m->size = size;
        memcpy(m->data, data, size);
        l->cur = l->cur + ((size + 3) & ~3) + 8;
        l->used = l->used + ((size + 3) & ~3) + 8;
        n->next = m;
    }
    if (l->cur == l->size) l->cur = 0;
    return 0;
}
#undef rt_list_buf_is_valid /* merge_units */
/* merge_units: end func_002FA5F8 */

/* merge_units: begin func_002FA758 */
typedef struct N_002FA758 { int a; struct N_002FA758 *next; } N_002FA758;
typedef struct { int x; N_002FA758 *cur; N_002FA758 *end; int p3, p4; N_002FA758 *f14; } L_002FA758;
#if 0 /* merge_units */
extern int rt_list_buf_is_valid(L_002FA758 *);
#endif /* merge_units */
#define rt_list_buf_is_valid(a0) (rt_list_buf_is_valid((int *)(a0))) /* merge_units */

extern int rt_list_buf_get_head(L_002FA758 *, N_002FA758 **);
#if 0 /* merge_units */
extern int rt_list_buf_insert(L_002FA758 *, N_002FA758 *, int, int);
#endif /* merge_units */
#define rt_list_buf_insert(a0, a1, a2, a3) (rt_list_buf_insert((L *)(a0), (N *)(a1), (char *)(a2), (unsigned int)(a3))) /* merge_units */

extern N_002FA758 *rt_list_buf_get_next(N_002FA758 *);
int rt_list_buf_set_new_head(L_002FA758 *l, int b, int c)
{
    N_002FA758 *n[1];
    N_002FA758 *m;
    int r;
    n[0] = 0;
    if (rt_list_buf_is_valid(l) == 0) return 2;
    if (b == 0) return 2; if (c == 0) return 2;
    r = rt_list_buf_get_head(l, n);
    if (r) return r;
    r = rt_list_buf_insert(l, n[0], b, c);
    if (r) return r;
    r = rt_list_buf_get_head(l, n);
    if (r) return r;
    m = rt_list_buf_get_next(n[0]);
    if (m) {
        l->f14 = m;
        n[0]->next = m->next;
        m->next = n[0];
    }
    if (l->cur == l->end) l->cur = 0;
    return 0;
}
#undef rt_list_buf_is_valid /* merge_units */
#undef rt_list_buf_insert /* merge_units */
/* merge_units: end func_002FA758 */

/* merge_units: begin func_002FA830 */
typedef struct N_002FA830 { int size; struct N_002FA830 *next; } N_002FA830;
typedef struct { int x; N_002FA830 *cur; N_002FA830 *end; int free; int p4; N_002FA830 *last; } L_002FA830;
#if 0 /* merge_units */
extern int rt_list_buf_is_valid(L_002FA830 *);
#endif /* merge_units */
#define rt_list_buf_is_valid(a0) (rt_list_buf_is_valid((int *)(a0))) /* merge_units */

extern int rt_list_buf_find_previous_node(L_002FA830 *, N_002FA830 *, N_002FA830 **);
#if 0 /* merge_units */
extern int rt_list_buf_place_list_head(L_002FA830 *);
#endif /* merge_units */
#define rt_list_buf_place_list_head(a0) (rt_list_buf_place_list_head((char *)(a0))) /* merge_units */

extern int rt_list_buf_recalculate_start_index(L_002FA830 *);
extern int rt_list_buf_recalculate_end_index(L_002FA830 *);
int rt_list_buf_remove(L_002FA830 *l, N_002FA830 *n)
{
    N_002FA830 *prev[1];
    int r;
    prev[0] = 0;
    if (rt_list_buf_is_valid(l) == 0) return 2;
    if (n == 0) return 2;
    if (n != l->last) {
        r = rt_list_buf_find_previous_node(l, n, prev);
        if (r) return r;
        prev[0]->next = n->next;
        l->free = l->free - ((n->size + 3) & ~3) - 8;
    } else {
        N_002FA830 *nx = n->next;
        if (nx == 0) {
            l->x = 0;
            l->cur = 0;
            l->free = 0;
            r = rt_list_buf_place_list_head(l);
            if (r) return r;
        } else {
            l->last = nx;
            l->free = l->free - ((n->size + 3) & ~3) - 8;
        }
    }
    r = rt_list_buf_recalculate_start_index(l);
    if (r) return r;
    return rt_list_buf_recalculate_end_index(l);
}
#undef rt_list_buf_is_valid /* merge_units */
#undef rt_list_buf_place_list_head /* merge_units */
/* merge_units: end func_002FA830 */
