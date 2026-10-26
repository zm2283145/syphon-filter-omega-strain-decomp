typedef struct { unsigned long a; unsigned char b; } ScfClk_570;
extern ScfClk_570 D_00529818;
extern int rt_time_get_time_string(ScfClk_570 *c);
ScfClk_570 *rt_time_get_time_string_ptr(void)
{
    ScfClk_570 *c = &D_00529818;
    if (rt_time_get_time_string(c) != 0) {
        __builtin_memcpy(c, "00:00:00", 9);
    }
    return c;
}