extern int rt_msg_client_get_connection(unsigned short);
extern int rt_msg_client_is_valid_connection(int);
int rt_msg_client_get_valid_connection(unsigned short a, int *p)
{
    if (p == 0) return 2;
    if (rt_msg_client_get_connection(a)) return 0xB;
    return rt_msg_client_is_valid_connection(*p) ? 0 : 0xB;
}