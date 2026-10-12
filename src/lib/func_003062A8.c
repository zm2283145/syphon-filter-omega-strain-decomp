typedef struct { unsigned int sec; unsigned int usec; } Tv62A8;
int func_003062A8(Tv62A8 *a, Tv62A8 *b, Tv62A8 *d)
{
    int ret = 2;
    if (a == 0) return ret;
    if (b == 0) return ret;
    if (d == 0) return ret;
    if (a->sec == b->sec) {
        if (a->usec > b->usec) goto zero;
        d->sec = 0;
        d->usec = b->usec - a->usec;
    } else {
        if (!(a->sec < b->sec)) goto zero;
        if (b->usec < a->usec) {
            d->sec = b->sec - a->sec - 1;
            d->usec = 1000000 - (a->usec - b->usec);
        } else {
            d->sec = b->sec - a->sec;
            d->usec = b->usec - a->usec;
        }
    }
    goto done;
zero:
    d->sec = 0;
    d->usec = 0;
    return 0;
done:
    return 0;
}
