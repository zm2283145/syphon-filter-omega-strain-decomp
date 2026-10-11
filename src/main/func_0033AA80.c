#include "types.h"
typedef struct { int a, b, c, d, e, f, g, h; } E_0033AA80;
typedef struct { int cap; int count; E_0033AA80* data; } V_0033AA80;
E_0033AA80* func_0033AA80(V_0033AA80* v, E_0033AA80* first, E_0033AA80* last)
{
    E_0033AA80* end;
    E_0033AA80* s;
    E_0033AA80* d;
    if (first == last)
        return first;
    end = v->data + v->count;
    if (end - last != 0) {
        d = first;
        s = last;
        while (s < end) {
            d->a = s->a; d->b = s->b; d->c = s->c; d->d = s->d; d->e = s->e; d->f = s->f; d->g = s->g; d->h = s->h;
            s++;
            d++;
        }
    }
    v->count -= last - first;
    return first;
}