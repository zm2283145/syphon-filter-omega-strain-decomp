typedef struct { unsigned char init; char pad[3]; int count; int owner; } Lock23D8;
extern int rt_mutex_platform_get_thread_id(int *tid);
extern int rt_mutex_platform_unlock(Lock23D8 *l);
int rt_mutex_unlock(Lock23D8 *l, int *left)
{
    int tid;
    int r;
    if (l == 0) return 2;
    if (l->init != 1) return 2;
    r = rt_mutex_platform_get_thread_id(&tid);
    if (r != 0) return r;
    if (tid != l->owner) return 4;
    if (l->count == 0) return 5;
    l->count--;
    if (left) *left = l->count;
    if (l->count == 0) {
        l->owner = 0;
        r = rt_mutex_platform_unlock(l);
        if (r != 0) return r;
    }
    return 0;
}
