volatile int D_0049089C = 0;
extern int rt_comm_platform_startup(void);
extern int rt_comm_metric_init(void);
int rt_comm_startup(void)
{
    volatile int *p = &D_0049089C;
    int r;
    if (*p == 0) {
        r = rt_comm_platform_startup();
        if (r) return r;
        r = rt_comm_metric_init();
        if (r) return r;
    }
    (*p)++;
    return 0;
}

