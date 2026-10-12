typedef struct N { unsigned int size; struct N *next; char data[1]; } N;
typedef struct { int x; int cur; int size; int used; char *buf; N *head; } L;
extern void *memcpy(void *, const void *, unsigned int);
extern int func_002FAF18(L *);
extern int func_002FAFB0(L *, unsigned int *);
extern int func_002FB058(L *, N **, unsigned int);
int func_002FA5F8(L *l, N *n, char *data, unsigned int size)
{
    unsigned int avail = 0;
    N *m;
    int r;
    if (func_002FAF18(l) == 0) return 2;
    if (n == 0) return 2;
    if (data == 0) return 2;
    if (size == 0) return 2;
    if (n->size == 0) {
        r = func_002FAFB0(l, &avail);
        if (r) return r;
        if (avail >= size) {
        n->size = size;
        n->next = 0;
        memcpy(n->data, data, size);
        l->cur = l->cur + ((size + 3) & ~3);
        l->used = l->used + ((size + 3) & ~3);
        } else return 3;
    } else {
        r = func_002FB058(l, &n, size + 8);
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

