typedef struct { int sec; int usec; } ScfTime;
extern int rt_time_get_time_stamp(ScfTime *tv);
extern int rt_time_calc_diff(ScfTime *a, ScfTime *b, ScfTime *out);
int rt_time_elapsed_timestamp(ScfTime *in, ScfTime *out)
{
    ScfTime tv;
    int ret = 2;
    if (in == 0) return ret;
    if (out == 0) return ret;
    ret = rt_time_get_time_stamp(&tv);
    if (ret != 0) return ret;
    return rt_time_calc_diff(in, &tv, out);
}