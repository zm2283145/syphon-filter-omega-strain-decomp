typedef struct N { unsigned int size; struct N *next; char data[1]; } N;
typedef struct { int x; int cur; int size; int used; char *buf; N *head; } L;
extern void *memcpy(void *, const void *, unsigned int);
extern int func_002FAF18(L *);
extern int func_002FAFB0(L *, unsigned int *);
extern int func_002FB058(L *, N **, unsigned int);
extern int func_002FA5F8(L *l, N *n, char *data, unsigned int size);
extern void func_002FA830(L *l, N *n);
int func_002FA930(L *l, N *n, char *data, unsigned int size)
{
    unsigned int avail = 0;
    N *m;
    int r;
    if (func_002FAF18(l) == 0) return 2;
    if (n == 0) return 2;
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
        if (l->cur == n->data + ((n->size + 3) & ~3) - l->buf) {
            avail = 0;
            r = func_002FAFB0(l, &avail);
            if (r) return r;
            if (avail >= size) {
                memcpy(l->buf + l->cur + n->size - ((n->size + 3) & ~3), data, size);
                l->cur += ((n->size + size + 3) & ~3) - ((n->size + 3) & ~3);
                l->used += ((n->size + size + 3) & ~3) - ((n->size + 3) & ~3);
                n->size += size;
                /* duplicated tail (cross-jumped after reload); the extra l uses give l s0 like retail */
                if (l->cur == l->size) l->cur = 0;
                return 0;
            }
        }
        r = func_002FB058(l, &n, size + n->size + 8);
        if (r) return r;
        r = func_002FA5F8(l, n, n->data, n->size);
        if (r) return r;
        m = n->next;
        if (!m) return 3;
        memcpy(m->data + m->size, data, size);
        l->cur += ((m->size + size + 3) & ~3) - ((m->size + 3) & ~3);
        l->used += ((m->size + size + 3) & ~3) - ((m->size + 3) & ~3);
        m->size += size;
        func_002FA830(l, n);
    }
done:
    if (l->cur == l->size) l->cur = 0;
    return 0;
}
