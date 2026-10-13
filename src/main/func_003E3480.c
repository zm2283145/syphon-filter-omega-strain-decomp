typedef struct Int3E3 { int x; int y; int z; } Int3E3;
typedef struct { int capacity; int count; Int3E3 *data; } Int3E3Vector;
Int3E3 *func_003E3480(Int3E3Vector *v, Int3E3 *first, Int3E3 *last)
{
    Int3E3 *end;
    Int3E3 *s;
    Int3E3 *d;
    if (first == last)
        return first;
    end = v->data + v->count;
    if (end - last != 0) {
        d = first;
        s = last;
        while (s < end) {
            d->x = s->x;
            d->y = s->y;
            d->z = s->z;
            s++;
            d++;
        }
    }
    v->count -= last - first;
    return first;
}

