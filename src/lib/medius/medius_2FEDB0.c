/*
 * lib/medius: 2 files, 002FEDB0-002FEE78
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FEDB0 */
typedef struct { int a; } C;
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_channel(C *);
extern int rt_msg_set_u2byte(void *, unsigned short);
extern int rt_msg_client_store_msg_in_send_buf(C *, int, int, void *, int, int);
int rt_msg_client_store_flush_msg_in_send_buf(C *c, unsigned short id)
{
    unsigned char buf[2];
    int n = 0;
    int type;
    void *p;
    int r;    if (D_004908EC != 1) return 5;
    if (rt_msg_client_is_valid_channel(c) != 1) return 2;
    if (id != 0xFFFF) {
        if (id == 0xFFFE) {
            type = 0xF;
            p = 0;
        } else {
            type = 0x10;
            if (rt_msg_set_u2byte(buf, id)) return 7;
            p = buf;
            n = 2;
        }
        r = rt_msg_client_store_msg_in_send_buf(c, type, 0xFFFF, p, n, 0);
        if (r) return r;
    }
    return 0;
}
/* merge_units: end func_002FEDB0 */

/* merge_units: begin func_002FEE78 */
typedef struct { char b[16]; } K;
typedef struct { int f0; char p4; unsigned char f5; unsigned short f6; } S;
typedef struct {
    unsigned short id; char p2[2]; int f4; int f8; char pC[4]; K f10; unsigned short f20; unsigned short f22;
    char p24[0x34]; unsigned short f58; char p5A[0x16]; char f70[8];
} O;
extern unsigned char D_005297C0[];
extern int rt_msg_client_is_valid_connection(O *);
#if 0 /* merge_units */
extern int rt_msg_client_is_valid_channel(S *);
#endif /* merge_units */
#define rt_msg_client_is_valid_channel(a0) (rt_msg_client_is_valid_channel((C *)(a0))) /* merge_units */

extern int rt_msg_client_calc_connect_aux_udp_msg_size(unsigned short *);
extern int rt_msg_client_get_client_version(int, unsigned char *, unsigned char *, unsigned char *);
extern int rt_msg_set_ubyte(unsigned char *, unsigned char);
#if 0 /* merge_units */
extern int rt_msg_set_u2byte(unsigned char *, unsigned short);
#endif /* merge_units */
#define rt_msg_set_u2byte(a0, a1) (rt_msg_set_u2byte((void *)(a0), (a1))) /* merge_units */

extern void rt_msg_set_u4byte(unsigned char *, unsigned int);
extern unsigned int KM_GetSoftwareID(void);
#if 0 /* merge_units */
extern int rt_msg_client_store_msg_in_send_buf(S *, int, int, unsigned char *, int, int);
#endif /* merge_units */
#define rt_msg_client_store_msg_in_send_buf(a0, a1, a2, a3, a4, a5) (rt_msg_client_store_msg_in_send_buf((C *)(a0), (a1), (a2), (void *)(a3), (a4), (a5))) /* merge_units */

extern int rt_time_start(void *);
int rt_msg_client_store_connect_aux_udp(O *o, S *s)
{
    unsigned short len = 0;
    unsigned char a, b, c;
    unsigned char *p = D_005297C0;
    int r;
    if (D_004908EC != 1) return 5;
    if (rt_msg_client_is_valid_connection(o) != 1) return 2;
    if (rt_msg_client_is_valid_channel(s) != 1) return 2;
    if (s->f5 != 1) return 2;
    if (o->id != s->f6) return 2;
    r = rt_msg_client_calc_connect_aux_udp_msg_size(&len);
    if (r) return r;
    if (len != 0x1D) return 1;
    r = rt_msg_client_get_client_version(o->f4, &a, &b, &c);
    if (r) return r;
    if (rt_msg_set_ubyte(p, a)) return 7;
    p++;
    if (rt_msg_set_ubyte(p, b)) return 7;
    p++;
    if (rt_msg_set_ubyte(p, c)) return 7;
    p++;
    if (rt_msg_set_u2byte(p, o->f22)) return 7;
    p += 2;
    rt_msg_set_u4byte(p, KM_GetSoftwareID());
    p += 4;
    *(K *)p = o->f10;
    p += 16;
    if (rt_msg_set_u2byte(p, o->f20)) return 7;
    p += 2;
    if (rt_msg_set_u2byte(p, o->f58)) return 7;
    p += 2;
    r = rt_msg_client_store_msg_in_send_buf(s, 0x16, 0xFFFF, p - 0x1D, 0x1D, 1);
    if (r) return r;
    if (rt_time_start(o->f70)) return 0x18;
    return 0;
}
#undef rt_msg_client_is_valid_channel /* merge_units */
#undef rt_msg_set_u2byte /* merge_units */
#undef rt_msg_client_store_msg_in_send_buf /* merge_units */
/* merge_units: end func_002FEE78 */
