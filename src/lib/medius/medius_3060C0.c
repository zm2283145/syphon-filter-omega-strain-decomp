extern int rt_time_get_time_stamp(void *tv);
int rt_time_start(void *tv)
{
    return rt_time_get_time_stamp(tv);
}