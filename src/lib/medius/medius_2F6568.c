/*
 * lib/medius: 4 files, 002F6568-002F66B8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F6568 */
extern int rt_comm_get_valid_channel(int, char **);
int rt_comm_get_interface_data(int a, int *out)
{
    char *p = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    *out = (int)(p + 4);
    return 0;
}
/* merge_units: end func_002F6568 */

/* merge_units: begin func_002F65C8 */
int rt_comm_get_local_port(int a, unsigned short *out)
{
    char *p = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    *out = *(unsigned short *)(p + 0x14);
    return 0;
}
/* merge_units: end func_002F65C8 */

/* merge_units: begin func_002F6628 */
extern int rt_comm_platform_is_connected(int, unsigned char *);
int rt_comm_is_connected(int a, unsigned char *out)
{
    char *p = 0;
    int r;
    if (out == 0) return 2;
    r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8)) return 0xC;
    if (((unsigned char *)p)[0x16] == 1) {
        *out = ((unsigned char *)p)[0x16];
    } else {
        r = rt_comm_platform_is_connected(*(int *)(p + 4), out);
        if (r) return r;
        p[0x16] = *out;
    }
    return 0;
}
/* merge_units: end func_002F6628 */

/* merge_units: begin func_002F66B8 */
extern int rt_memory_allocate_init_zero(char **, int);
int rt_comm_get_new_channel_id(char **out)
{
    char *p = 0;
    if (out == 0) return 2;
    *out = 0;
    if (rt_memory_allocate_init_zero(&p, 0x18)) return 9;
    if (p == 0) return 0xA;
    *p = 1;
    *out = p;
    return 0;
}
/* merge_units: end func_002F66B8 */
