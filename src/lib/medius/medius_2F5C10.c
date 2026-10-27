/*
 * lib/medius: 11 files, 002F5C10-002F6330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F5C10 */
extern int D_0049089C;
extern int rt_comm_platform_shutdown(void);
int rt_comm_shutdown(void)
{
    int r;
    if (D_0049089C <= 0) return 4;
    if (--D_0049089C == 0 && (r = rt_comm_platform_shutdown()) != 0) return r;
    return 0;
}
/* merge_units: end func_002F5C10 */

/* merge_units: begin func_002F5C58 */
extern void *memset(void *, int, unsigned int);
int rt_comm_set_default_options(int *p)
{
    if (p == 0) return 2;
    memset(p, 0, 0xC);
    p[0] = 0;
    return 0;
}
/* merge_units: end func_002F5C58 */

/* merge_units: begin func_002F5C98 */
typedef struct { int a; int b; int c; } Opts;
typedef struct { unsigned char f0; unsigned char used; char pad2[2]; int f4; Opts opts; unsigned short port; char name[1]; } Ent;
extern int rt_comm_get_new_channel_id(int *);
extern int rt_comm_get_channel(int, Ent **);
#if 0 /* merge_units */
extern int rt_comm_set_default_options(Opts *);
#endif /* merge_units */
#define rt_comm_set_default_options(a0) (rt_comm_set_default_options((int *)(a0))) /* merge_units */

extern int rt_comm_platform_create(int *, char *, unsigned short *, Opts *, char *);
extern int rt_comm_release_channel_id(int);
int rt_comm_create(int *out, char *name, unsigned short port, Opts *opts)
{
    int id;
    Ent *e = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    r = rt_comm_get_new_channel_id(&id);
    if (r) return r;
    r = rt_comm_get_channel(id, &e);
    if (r) return r;
    if (e == 0) return 0xA;
    if (opts) {
        e->opts = *opts;
    } else {
        r = rt_comm_set_default_options(&e->opts);
        if (r) goto err;
    }
    r = rt_comm_platform_create(&e->f4, name, &port, &e->opts, e->name);
    if (r) {
err:
        rt_comm_release_channel_id(id);
        return r;
    }
    e->port = port;
    e->used = 1;
    *out = id;
    return 0;
}
#undef rt_comm_set_default_options /* merge_units */
/* merge_units: end func_002F5C98 */

/* merge_units: begin func_002F5DB0 */
extern int rt_comm_get_valid_channel(int, char **);
extern void rt_comm_platform_destroy(int);
int rt_comm_destroy(int a)
{
    char *p = 0;
    int r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    rt_comm_platform_destroy(*(int *)(p + 4));
    p[1] = 0;
    p[0] = 0;
    return rt_comm_release_channel_id(a);
}
/* merge_units: end func_002F5DB0 */

/* merge_units: begin func_002F5E10 */
extern int rt_comm_is_connected(int, unsigned char *);
extern int rt_comm_platform_send(int, int, unsigned short, unsigned short *);
extern int rt_comm_metric_add_data(unsigned short, int, int);
int rt_comm_send(int a, int b, unsigned short c, unsigned short *out)
{
    unsigned char ok;
    char *p = 0;
    int r, t;
    if (out == 0) return 2;
    *out = 0;
    if (b == 0) return 2;
    r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    t = *(int *)(p + 8);
    if (t != 0 && t != 2) return 0xC;
    if (((unsigned char *)p)[0x16] == 0 && *(int *)(p + 8) == 0) {
        ok = 0;
        r = rt_comm_is_connected(a, &ok);
        if (r) return r;
        if (ok == 0) {
            *out = 0;
            return r;
        }
        p[0x16] = 1;
    }
    r = rt_comm_platform_send(*(int *)(p + 4), b, c, out);
    if (r) return r;
    return rt_comm_metric_add_data(*out, 0, 0x28);
}
/* merge_units: end func_002F5E10 */

/* merge_units: begin func_002F5F20 */
extern int rt_comm_platform_send_to(int, int, unsigned short, int, unsigned short, unsigned short *);
int rt_comm_send_to(int a, int b, unsigned short c, int d, unsigned short e, unsigned short *out)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (d == 0) return 2;
    r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 1) return 0xC;
    r = rt_comm_platform_send_to(*(int *)(p + 4), b, c, d, e, out);
    if (r) return r;
    return rt_comm_metric_add_data(*out, 0, 0x1C);
}
/* merge_units: end func_002F5F20 */

/* merge_units: begin func_002F5FE8 */
extern int rt_comm_platform_send_echo(int, char *, int, unsigned short);
#if 0 /* merge_units */
extern int rt_comm_metric_add_data(int, int, int);
#endif /* merge_units */
#define rt_comm_metric_add_data(a0, a1, a2) (rt_comm_metric_add_data((unsigned short)(a0), (a1), (a2))) /* merge_units */

int rt_comm_send_echo(int a, char *b, int c, unsigned short d)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    *b = 0;
    if (c == 0) return 2;
    r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 3) return 0xC;
    r = rt_comm_platform_send_echo(*(int *)(p + 4), b, c, d);
    if (r) return r;
    return rt_comm_metric_add_data(0x1C, 0, 0);
}
#undef rt_comm_metric_add_data /* merge_units */
/* merge_units: end func_002F5FE8 */

/* merge_units: begin func_002F6090 */
extern int rt_comm_platform_receive(int, int, unsigned short, unsigned short *);
#if 0 /* merge_units */
extern int rt_comm_metric_add_data(int, unsigned short, int);
#endif /* merge_units */
#define rt_comm_metric_add_data(a0, a1, a2) (rt_comm_metric_add_data((unsigned short)(a0), (int)(a1), (a2))) /* merge_units */

int rt_comm_receive(int a, int b, unsigned short c, unsigned short *out)
{
    unsigned char ok;
    char *p = 0;
    int r, t;
    if (out == 0) return 2;
    *out = 0;
    if (b == 0) return 2;
    r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    t = *(int *)(p + 8);
    if (t != 0 && t != 2) return 0xC;
    if (((unsigned char *)p)[0x16] == 0 && *(int *)(p + 8) == 0) {
        ok = 0;
        r = rt_comm_is_connected(a, &ok);
        if (r) return r;
        if (ok == 0) {
            *out = 0;
            return r;
        }
        p[0x16] = 1;
    }
    r = rt_comm_platform_receive(*(int *)(p + 4), b, c, out);
    if (r) return r;
    return rt_comm_metric_add_data(0, *out, 0x28);
}
#undef rt_comm_metric_add_data /* merge_units */
/* merge_units: end func_002F6090 */

/* merge_units: begin func_002F61A0 */
extern int rt_comm_platform_receive_from(int, int, int, int, unsigned short, unsigned short *);
#if 0 /* merge_units */
extern int rt_comm_metric_add_data(int, unsigned short, int);
#endif /* merge_units */
#define rt_comm_metric_add_data(a0, a1, a2) (rt_comm_metric_add_data((unsigned short)(a0), (int)(a1), (a2))) /* merge_units */

int rt_comm_receive_from(int a, int b, int c, int d, unsigned short e, unsigned short *out)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (d == 0) return 2;
    r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 1) return 0xC;
    r = rt_comm_platform_receive_from(*(int *)(p + 4), b, c, d, e, out);
    if (r) return r;
    return rt_comm_metric_add_data(0, *out, 0x1C);
}
#undef rt_comm_metric_add_data /* merge_units */
/* merge_units: end func_002F61A0 */

/* merge_units: begin func_002F6268 */
extern int rt_comm_platform_receive_echo(int, unsigned char *, int, int);
#if 0 /* merge_units */
extern int rt_comm_metric_add_data(int, int, int);
#endif /* merge_units */
#define rt_comm_metric_add_data(a0, a1, a2) (rt_comm_metric_add_data((unsigned short)(a0), (a1), (a2))) /* merge_units */

int rt_comm_receive_echo(int a, unsigned char *out, int c, int d)
{
    char *p = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (c == 0) return 2;
    if (d == 0) return 2;
    r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 3) return 0xC;
    r = rt_comm_platform_receive_echo(*(int *)(p + 4), out, c, d);
    if (r) return r;
    if (*out == 1) {
        r = rt_comm_metric_add_data(0, 0x1C, 0);
        if (r) return r;
    }
    return 0;
}
#undef rt_comm_metric_add_data /* merge_units */
/* merge_units: end func_002F6268 */

/* merge_units: begin func_002F6330 */
extern int rt_comm_platform_get_avail_bytes_to_read(int, unsigned short *);
int rt_comm_get_avail_bytes_to_read(int a, unsigned short *out)
{
    unsigned char ok;
    char *p = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    r = rt_comm_get_valid_channel(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (((unsigned char *)p)[0x16] == 0 && *(int *)(p + 8) == 0) {
        ok = 0;
        r = rt_comm_is_connected(a, &ok);
        if (r) return r;
        if (ok == 0) {
            *out = 0;
            return r;
        }
        p[0x16] = 1;
    }
    return rt_comm_platform_get_avail_bytes_to_read(*(int *)(p + 4), out);
}
/* merge_units: end func_002F6330 */
