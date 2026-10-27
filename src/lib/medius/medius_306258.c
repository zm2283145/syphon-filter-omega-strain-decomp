/*
 * lib/medius: 3 files, 00306258-00306380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00306258 */
typedef struct { int sec; int usec; } ScfTime;
const unsigned int D_00491300[2] = { 0x0, 0x0 };
extern ScfTime D_00529828;
extern int rt_time_get_time_stamp(ScfTime *tv);
int rt_time_initialize(void)
{
    unsigned char *flag = &(*(unsigned char*)D_00491300);
    int ret = 1;
    if (*flag == 1) return ret;
    ret = rt_time_get_time_stamp(&D_00529828);
    if (ret == 0) *flag = 1;
    return ret;
}
/* merge_units: end func_00306258 */

/* merge_units: begin func_003062A8 */
typedef struct { unsigned int sec; unsigned int usec; } Tv62A8;
int rt_time_calc_diff(Tv62A8 *a, Tv62A8 *b, Tv62A8 *d)
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
/* merge_units: end func_003062A8 */

/* merge_units: begin func_00306380 */
typedef struct { unsigned int sec; unsigned int usec; } ScfTime_00306380;
int rt_time_timestamp_to_secs(ScfTime_00306380 *tv, unsigned int *out)
{
    int ret = 2;
    if (tv == 0) return ret;
    if (out == 0) return ret;
    *out = tv->sec;
    *out += tv->usec / 1000000;
    return 0;
}
/* merge_units: end func_00306380 */
