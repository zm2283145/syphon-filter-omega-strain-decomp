/* vector<{float, u8}>::erase(first, last); template clone built with CW 3.0 b50 (mw38 unrolls the copy differently). */
typedef struct E { float f; unsigned char b; } E;
typedef struct Vec { int cap; int count; E* data; } Vec;
E* std_vector_imp_VisKey_erase(Vec* v, E* first, E* last)
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
            d->f = s->f;
            d->b = s->b;
            s++;
            d++;
        }
    }
    v->count -= last - first;
    return first;
}

