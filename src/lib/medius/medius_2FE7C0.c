extern void **D_004908F4;
extern unsigned short D_004908F0;
/* Weak stub of the same-file callee (section discarded at link): reproduces beqz vs beql. */
int __attribute__((weak, section(".dtors_drop"))) rt_msg_client_is_valid_connection(void *o) { return 0; }

int rt_msg_client_is_valid_connection_id(unsigned short i)
{
    int r;
    if (D_004908F4 == 0) return 0;
    if (i >= D_004908F0) return 0;
    r = rt_msg_client_is_valid_connection(D_004908F4[i]);
    __asm__ __volatile__(""); /* stops the sibling-call optimisation */
    return r;
}
