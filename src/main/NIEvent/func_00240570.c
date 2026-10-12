/* vector<{float x,y,z,w}>::erase(first, last); template clone built with CW 3.0 b50. */
typedef struct E { float x, y, z, w; } E;
typedef struct Vec { int cap; int count; E* data; } Vec;
E* func_00240570(Vec* v, E* first, E* last)
{
    E* end;
    E* s;
    E* d;
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
            d->w = s->w;
            s++;
            d++;
        }
    }
    v->count -= last - first;
    return first;
}


