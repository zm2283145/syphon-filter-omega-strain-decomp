typedef struct { unsigned int count; float rate; float peak; } Rate2F68F0;
typedef struct { int timer[2]; Rate2F68F0 r[4]; } Stats2F68F0;
extern Stats2F68F0 D_00525508;
extern int rt_time_elapsed_msecs(void *t, unsigned int *elapsed);
extern int rt_comm_metric_update_single(Rate2F68F0 *p, unsigned int ms);
extern int rt_time_start(void *t);
/* Recomputes the four transfer-rate counters once more than a second has elapsed. */
int rt_comm_metric_update(void)
{
    Stats2F68F0 *s = &D_00525508;
    unsigned int ms;
    int r;

    if (rt_time_elapsed_msecs(s, &ms) != 0) return 1;
    if (ms > 1000) {
        r = rt_comm_metric_update_single(&s->r[0], ms); if (r) return r;
        r = rt_comm_metric_update_single(&s->r[1], ms); if (r) return r;
        r = rt_comm_metric_update_single(&s->r[2], ms); if (r) return r;
        r = rt_comm_metric_update_single(&s->r[3], ms); if (r) return r;
        if (rt_time_start(s) != 0) return 1;
    }
    return 0;
}
