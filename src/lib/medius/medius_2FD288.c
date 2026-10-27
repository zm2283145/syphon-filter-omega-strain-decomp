/*
 * lib/medius: 7 files, 002FD288-002FD670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FD288 */
typedef struct { unsigned char flag; char pad[3]; int x4; int x8; } S2FD288;
extern unsigned char D_004908EC;
extern S2FD288 D_005297E0;
extern unsigned int strlen(const char *);
extern int rt_comm_send_echo(int, unsigned char *, char *, unsigned short);
extern int rt_msg_client_map_comm_error(int);
int rt_msg_client_isend_echo(unsigned char *out, char *name, unsigned short x)
{
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (D_004908EC != 1) return 5;
    if (D_005297E0.flag != 1) return 5;
    if (name == 0) return 2;
    if (strlen(name) >= 0x10) return 2;
    r = rt_msg_client_map_comm_error(rt_comm_send_echo(D_005297E0.x4, out, name, x));
    __asm__ __volatile__("");
    return r;
}
/* merge_units: end func_002FD288 */

/* merge_units: begin func_002FD338 */
typedef struct { char pad[0x48]; unsigned int f48; unsigned int f4C; char q50[0x18]; char q68[4]; } S;
typedef struct { char pad[0x78]; S *sub[2]; } O;
extern int rt_msg_client_get_valid_connection(unsigned short, O **);
extern int rt_circ_buf_get_used(void *, unsigned int *);
int rt_msg_client_iget_buffer_status(unsigned short id, unsigned int *a, unsigned int *b, unsigned int *pa, unsigned int *pb)
{
    unsigned int x = 0; unsigned int y = 0;
    O *o = 0;
    unsigned int s4c = 0;
    unsigned int s48 = 0;
    unsigned int sx = 0;
    unsigned int sy = 0;
    unsigned int i;
    int r;
    S *s;
    if (D_004908EC != 1) return 5;
    r = rt_msg_client_get_valid_connection(id, &o);
    if (r) return r;
    for (i = 0; i < 2; i++) {
        s = o->sub[i];
        if (s) {
            if (rt_circ_buf_get_used(s->q68, &x)) return 0x15;
            sx += x;
            s48 += s->f48;
            if (rt_circ_buf_get_used(s->q50, &y)) return 0x15;
            s4c += s->f4C;
            sy += y;
        }
    }
    if (a) *a = sx;
    if (b) *b = sy;
    if (pa) {
        if (s48 == 0) return 1;
        *pa = sx * 100 / s48;
        if (*pa > 100) *pa = 100;
    }
    if (pb) {
        if (s4c != 0) {
            *pb = sy * 100 / s4c;
            if (*pb > 100) *pb = 100;
        } else return 1;
    }
    return 0;
}
/* merge_units: end func_002FD338 */

/* merge_units: begin func_002FD518 */
extern int rt_comm_get_local_ip(void *p);
int rt_msg_client_iget_local_ip(void *p)
{
    int r;
    if (D_004908EC != 1) return 5;
    if (p == 0) return 2;
    r = rt_msg_client_map_comm_error(rt_comm_get_local_ip(p));
    __asm__ __volatile__(""); /* barrier: retail keeps jal + return, no sibling call */
    return r;
}
/* merge_units: end func_002FD518 */

/* merge_units: begin func_002FD560 */
extern int rt_comm_get_broadcast_ip(void *p);
int rt_msg_client_iget_broadcast_ip(void *p)
{
    int r;
    if (D_004908EC != 1) return 5;
    if (p == 0) return 2;
    r = rt_msg_client_map_comm_error(rt_comm_get_broadcast_ip(p));
    __asm__ __volatile__(""); /* barrier: retail keeps jal + return, no sibling call */
    return r;
}
/* merge_units: end func_002FD560 */

/* merge_units: begin func_002FD5A8 */
extern int rt_comm_get_host_by_name(int, int);
int rt_msg_client_iget_host_by_name(int a, int b)
{
    if (D_004908EC != 1) return 5;
    if (a == 0) return 2;
    if (b == 0) return 2;
    {
        int r = rt_msg_client_map_comm_error(rt_comm_get_host_by_name(a, b));
        __asm__ __volatile__("");
        return r;
    }
}
/* merge_units: end func_002FD5A8 */

/* merge_units: begin func_002FD5F8 */
#if 0 /* merge_units */
extern int rt_msg_client_get_valid_connection(unsigned short, char **);
#endif /* merge_units */
#define rt_msg_client_get_valid_connection(a0, a1) (rt_msg_client_get_valid_connection((a0), (O * *)(a1))) /* merge_units */

extern void Libc_Strcpy(char *, char *);
int rt_msg_client_iget_connection_ip(unsigned short id, char *dst)
{
    char *p = 0;
    int r;
    if (D_004908EC != 1) return 5;
    if (dst == 0) return 2;
    r = rt_msg_client_get_valid_connection(id, &p);
    if (r) return r;
    if (*(int *)(p + 8) != 8) return 0x17;
    Libc_Strcpy(dst, p + 0x5C);
    return 0;
}
#undef rt_msg_client_get_valid_connection /* merge_units */
/* merge_units: end func_002FD5F8 */

/* merge_units: begin func_002FD670 */
#if 0 /* merge_units */
extern int rt_msg_client_get_valid_connection(unsigned short, char **);
#endif /* merge_units */
#define rt_msg_client_get_valid_connection(a0, a1) (rt_msg_client_get_valid_connection((a0), (O * *)(a1))) /* merge_units */

extern int rt_msg_set_ubyte(char *, int);
extern int rt_msg_client_store_msg_in_send_buf(int, int, int, char *, int, int);
int rt_msg_client_ireceive_broadcasts(unsigned short id, unsigned char f)
{
    char buf[16];
    char *p = 0;
    int r;
    if (D_004908EC != 1) return 5;
    r = rt_msg_client_get_valid_connection(id, &p);
    if (r) return r;
    if (rt_msg_set_ubyte(buf, 2) || rt_msg_set_ubyte(buf + 1, f == 1)) return 7;
    return rt_msg_client_store_msg_in_send_buf(*(int *)(p + 0x80), 0xD, 0xFFFF, buf, 2, 0);
}
#undef rt_msg_client_get_valid_connection /* merge_units */
/* merge_units: end func_002FD670 */
