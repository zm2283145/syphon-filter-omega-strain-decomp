typedef struct Vec3AD { float x; float y; float z; } Vec3AD;
typedef struct { int capacity; int count; Vec3AD *data; } Vec3ADVector;
Vec3AD *std_vector_imp_cBoneScale_erase(Vec3ADVector *v, Vec3AD *first, Vec3AD *last)
{
    Vec3AD *end;
    Vec3AD *s;
    Vec3AD *d;
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
