extern void **D_004908F4;
extern unsigned short D_004908F0;
int rt_msg_client_get_connection(unsigned short i, void **out)
{
    if (out == 0) return 2;
    if (D_004908F4 == 0) return 1;
    if (D_004908F0 == 0) return 1;
    if (i >= D_004908F0) return 2;
    *out = D_004908F4[i];
    return 0;
}
