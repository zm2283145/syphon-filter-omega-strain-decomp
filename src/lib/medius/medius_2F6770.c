extern int rt_comm_get_channel(int);
extern int rt_comm_is_valid_channel(int);
int rt_comm_get_valid_channel(int a, int *p)
{
    if (p == 0) return 2;
    if (rt_comm_get_channel(a)) return 0xB;
    return rt_comm_is_valid_channel(*p) ? 0 : 0xB;
}