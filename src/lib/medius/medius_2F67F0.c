typedef struct { char b[8]; } B2F67F0;
typedef struct { B2F67F0 a; int z[12]; } S2F67F0;
extern S2F67F0 D_00525508;
extern B2F67F0 D_00525540;
extern int rt_time_start(S2F67F0 *);
int rt_comm_metric_init(void)
{
    S2F67F0 *s = &D_00525508;
    s->z[0] = 0;
    s->z[1] = 0;
    s->z[2] = 0;
    s->z[3] = 0;
    s->z[4] = 0;
    s->z[5] = 0;
    s->z[6] = 0;
    s->z[7] = 0;
    s->z[8] = 0;
    s->z[9] = 0;
    s->z[10] = 0;
    s->z[11] = 0;
    if (rt_time_start(s)) return 1;
    D_00525540 = s->a;
    return 0;
}
