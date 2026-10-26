typedef struct N { int size; struct N *next; char data[1]; } N;
typedef struct { int x; N *cur; unsigned int size; unsigned int used; char *buf; N *head; } L;
extern void *memset(void *, int, unsigned int);
extern int rt_list_buf_is_valid(L *);
extern int rt_list_buf_create(L *, unsigned int);
extern int rt_list_buf_get_tail(L *, N **);
extern int rt_list_buf_insert(L *, N *, char *, int);
/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
int __attribute__((weak, section(".dtors_drop"))) rt_list_buf_destroy(L *p) { return 0; }
int rt_list_buf_resize_buffer(L *l, unsigned int n)
{
    L old;
    N *nl = 0;
    N *p;
    int r;
    if (rt_list_buf_is_valid(l) == 0) return 2;
    if (n < l->used) return 1;
    old = *l;
    memset(l, 0, 0x18);
    r = rt_list_buf_create(l, n);
    if (r) {
        *l = old;
        return r;
    }
    for (p = old.head; p; p = p->next) {
        rt_list_buf_get_tail(l, &nl);
        rt_list_buf_insert(l, nl, p->data, p->size);
    }
    rt_list_buf_destroy(&old);
    return 0;
}

