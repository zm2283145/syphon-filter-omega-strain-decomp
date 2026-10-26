/*
 * lib/medius: 17 files, 002F7040-002F7AB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F7040 */
extern unsigned char D_004908A0;
extern char D_00525600[];
extern int D_00525640[];
extern int sceBInetClose(void *cd, int *buf, int p, int x);
int rt_comm_platform2_destroy(int x)
{
    if (D_004908A0 != 1) return 5;
    if (x < 0) return 2;
    return sceBInetClose(D_00525600, D_00525640, x, 500) != 0;
}
/* merge_units: end func_002F7040 */

/* merge_units: begin func_002F7090 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int sceBInetSend(char *, char *, int, int, unsigned short, int *, int);
int rt_comm_platform2_send(int a, int b, unsigned short c, short *out)
{
    int x = 0;
    int r;
    if (D_004908A0 != 1) return 5;
    if (a < 0) return 2;
    if (b == 0) return 2;
    if (out == 0) return 2;
    r = sceBInetSend(D_00525600, D_00525640, a, b, c, &x, 0);
    if (r < 0) return 1;
    *out = r;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F7090 */

/* merge_units: begin func_002F7128 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int sceBInetIP2Address(char *, int);
extern int sceBInetSendTo(char *, char *, int, int, unsigned short, int *, char *, unsigned short, int);
int rt_comm_platform2_send_to(int a, int name, unsigned short x, int y, unsigned short z, short *out)
{
    char buf[16];
    int w = 0;
    int r;
    if (D_004908A0 != 1) return 5;
    if (a < 0) return 2;
    if (name == 0) return 2;
    if (x == 0) return 2;
    if (y == 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (sceBInetIP2Address(buf, name) < 0) return 1;
    r = sceBInetSendTo(D_00525600, D_00525640, a, y, z, &w, buf, x, 0);
    if (r < 0) return 1;
    *out = r;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F7128 */

/* merge_units: begin func_002F7218 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int sceBInetSendEcho(char *, char *, int, unsigned short, char *);
int rt_comm_platform2_send_echo(int a, unsigned char *out, int name, unsigned short port)
{
    char buf[16];
    unsigned char st;
    int r;
    if (out == 0) return 2;
    *out = 0;
    st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (name == 0) return 2;
    if (sceBInetIP2Address(buf, name) < 0) return 1;
    r = sceBInetSendEcho(D_00525600, D_00525640, a, port, buf);
    if (r < 0) return 1;
    if (r > 0) *out = st;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F7218 */

/* merge_units: begin func_002F72D8 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int sceBInetRecv(char *, char *, int, void *, unsigned short, int *, int);
int rt_comm_platform2_receive(int a, void *buf, unsigned short len, short *out)
{
    int flags;
    unsigned char st;
    int r;
    flags = 0;
    st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (buf == 0) return 2;
    if (out == 0) return 2;
    r = sceBInetRecv(D_00525600, D_00525640, a, buf, len > 0x1000 ? 0x1000 : len, &flags, 2);
    if (r < 0) {
        if (flags & 4) return 13;
        return 1;
    }
    if (flags & 4) return 13;
    *out = r;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F72D8 */

/* merge_units: begin func_002F73A8 */
typedef struct { char b[16]; } Addr;
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int sceBInetRecvFrom(char *, char *, int, char *, int, int *, Addr *, int *, int);
extern int sceBInetAddress2IP(void *, Addr *);
int rt_comm_platform2_receive_from(int s, void *from, unsigned short *port, char *buf, unsigned short size, short *nread)
{
    Addr addr;
    int flags = 0;
    int p;
    int n;
    unsigned short len;
    int r;
    if (D_004908A0 != 1) return 5;
    if (s < 0) return 2;
    if (from == 0) return 2;
    if (port == 0) return 2;
    if (buf == 0) return 2;
    if (nread == 0) return 2;
    *nread = 0;
    len = size <= 0x1000 ? size : 0x1000;
    r = sceBInetRecvFrom(D_00525600, D_00525640, s, buf, len, &flags, &addr, &p, 2);
    if (r < 0) {
        if (r != -500) return 1;
        r = 0;
    }
    n = r;
    if (n > 0) {
        *port = p;
        r = sceBInetAddress2IP(from, &addr);
        if (r != 0) return 1;
    }
    *nread = n;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F73A8 */

/* merge_units: begin func_002F74C0 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int sceBInetRecvEcho(char *, char *, int, unsigned short *, char *);
#if 0 /* merge_units */
extern int sceBInetAddress2IP(char *, char *);
#endif /* merge_units */
#define sceBInetAddress2IP(a0, a1) (sceBInetAddress2IP((void *)(a0), (Addr *)(a1))) /* merge_units */

int rt_comm_platform2_receive_echo(int a, unsigned char *out, char *name, unsigned short *port)
{
    char buf[16];
    unsigned short p;
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (D_004908A0 != 1) return 5;
    if (a < 0) return 2;
    if (name == 0) return 2;
    r = sceBInetRecvEcho(D_00525600, D_00525640, a, &p, buf);
    if (r < 0) {
        if (r != -500) return 1;
        r = 0;
    }
    if (r > 0) {
        *out = 1;
        *port = p;
        if (sceBInetAddress2IP(name, buf)) return 1;
    }
    return 0;
}
#undef D_00525640 /* merge_units */
#undef sceBInetAddress2IP /* merge_units */
/* merge_units: end func_002F74C0 */

/* merge_units: begin func_002F7590 */
extern int sceBInetGetAvailBytesToRead(int, int *);
int rt_comm_platform2_get_avail_bytes_to_read(int a, short *out)
{
    int fl = 0;
    unsigned char st = D_004908A0;
    int r;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    r = sceBInetGetAvailBytesToRead(a, &fl);
    if (r < 0) {
        if (r == -0x1FE || r == -0x1FD || r == -0x1FC) return 0xD;
        return 1;
    }
    if (fl & 4) return 0xD;
    *out = r;
    return 0;
}
/* merge_units: end func_002F7590 */

/* merge_units: begin func_002F7628 */
extern char D_004908A8[];
extern void String_Copy(char *d, const char *s);
int rt_comm_platform2_get_local_ip(char *out)
{
    if (D_004908A0 != 1) return 5;
    if (out == 0) return 2;
    String_Copy(out, D_004908A8);
    return 0;
}
/* merge_units: end func_002F7628 */

/* merge_units: begin func_002F7670 */
extern char D_004908C0[];
int rt_comm_platform2_get_broadcast_ip(char *out)
{
    if (D_004908A0 != 1) return 5;
    if (out == 0) return 2;
    String_Copy(out, D_004908C0);
    return 0;
}
/* merge_units: end func_002F7670 */

/* merge_units: begin func_002F76B8 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int sceInetName2Address(char *, char *, int, char *, int, int, int);
extern int sceInetAddress2String(char *, char *, char *, int, char *);
int rt_comm_platform2_get_host_by_name(int a, char *out)
{
    char buf[16];
    if (D_004908A0 != 1) return 5;
    if (a == 0) return 2;
    if (out == 0) return 2;
    if (sceInetName2Address(D_00525600, D_00525640, 0, buf, a, 0, 0) < 0) return 1;
    if (sceInetAddress2String(D_00525600, D_00525640, out, 0x10, buf) < 0) return 1;
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F76B8 */

/* merge_units: begin func_002F7768 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int sceBInetControl(char *, char *, int, int, char *, int);
int rt_comm_platform2_get_remote_ip(int a, char *out)
{
    char buf[0x4C];
    unsigned char st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (out == 0) return 2;
    if (sceBInetControl(D_00525600, D_00525640, a, 1, buf, 0x4C) != st) return 1;
    return sceInetAddress2String(D_00525600, D_00525640, out, 0x10, buf + 0x24) != 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F7768 */

/* merge_units: begin func_002F7818 */
extern int sceBInetDisplayLibnetbState(char* p);
int rt_comm_platform2_display_state(void)
{
    if (D_004908A0 != 1)
        return 5;
    return sceBInetDisplayLibnetbState(D_00525600) != 0;
}
/* merge_units: end func_002F7818 */

/* merge_units: begin func_002F7850 */
extern int sceBInetIsOpened(int, int *);
int rt_comm_platform2_is_connected(int a, unsigned char *out)
{
    int v = 0;
    unsigned char st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (sceBInetIsOpened(a, &v)) return 1;
    if (v) *out = st;
    return 0;
}
/* merge_units: end func_002F7850 */

/* merge_units: begin func_002F78D0 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int D_00525580[];
extern int D_004908D4;
extern int sceInetGetInterfaceList(void *a, void *b, int *list, int max);
extern int sceInetInterfaceControl(void *a, void *b, int sock, int opt, int *out, int len);
extern int rt_time_start(void *t);
extern int rt_time_elapsed(void *t, unsigned int *elapsed);
extern int rt_time_delay(int ms);

/* Polls the socket list until one reports state 3 (stores it in D_004908D4) or ~95 s pass. */
int rt_comm_platform2_wait_for_interface_startup(void)
{
    int timer[4];
    int info;
    unsigned int elapsed = 0;
    int found = 0;
    int n;
    int i;

    n = sceInetGetInterfaceList(D_00525600, D_00525640, D_00525580, 0x20);
    if (n <= 0) return 1;
    if (rt_time_start(timer)) return 1;
    for (;;) {
        for (i = 0; i < n; i++) {
            int sock = D_00525580[i];
            if (sceInetInterfaceControl(D_00525600, D_00525640, sock, 8, &info, 4)) return 1;
            if ((info & 3) == 3) {
                found = 1;
                D_004908D4 = sock;
                break;
            }
        }
        if (found) break;
        if (rt_time_elapsed(timer, &elapsed)) return 1;
        if (elapsed > 0x17318) return 1;
        if (rt_time_delay(2)) return 1;
    }
    return 0;
}
#undef D_00525640 /* merge_units */
/* merge_units: end func_002F78D0 */

/* merge_units: begin func_002F7A30 */
extern void *memset(void *, int, unsigned int);
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

extern int sceLibnetWaitGetAddress(char *, char *, int *, int, char *, int);
#if 0 /* merge_units */
extern int sceBInetAddress2IP(char *, char *);
#endif /* merge_units */
#define sceBInetAddress2IP(a0, a1) (sceBInetAddress2IP((void *)(a0), (Addr *)(a1))) /* merge_units */

int rt_comm_platform2_get_local_ip_from_stack(char *out)
{
    char buf[16];
    int x;
    if (out == 0) return 2;
    memset(buf, 0, 0x10);
    if (sceLibnetWaitGetAddress(D_00525600, D_00525640, &x, 1, buf, 2) < 0) return 1;
    return sceBInetAddress2IP(out, buf) != 0;
}
#undef D_00525640 /* merge_units */
#undef sceBInetAddress2IP /* merge_units */
/* merge_units: end func_002F7A30 */

/* merge_units: begin func_002F7AB0 */
#if 0 /* merge_units */
extern char D_00525640[];
#endif /* merge_units */
#define D_00525640 ((char*)&D_00525640) /* merge_units */

#if 0 /* merge_units */
extern int sceInetInterfaceControl(char *, char *, int, int, char *, int);
#endif /* merge_units */
#define sceInetInterfaceControl(a0, a1, a2, a3, a4, a5) (sceInetInterfaceControl((void *)(a0), (void *)(a1), (a2), (a3), (int *)(a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern int sceBInetAddress2IP(char *, char *);
#endif /* merge_units */
#define sceBInetAddress2IP(a0, a1) (sceBInetAddress2IP((void *)(a0), (Addr *)(a1))) /* merge_units */

int rt_comm_platform2_get_broadcast_ip_from_stack(char *out)
{
    char buf[16];
    if (out == 0) return 2;
    if (D_004908D4 < 0) return 1;
    memset(buf, 0, 0x10);
    if (sceInetInterfaceControl(D_00525600, D_00525640, D_004908D4, 0xB, buf, 0x10)) return 1;
    return sceBInetAddress2IP(out, buf) != 0;
}
#undef D_00525640 /* merge_units */
#undef sceInetInterfaceControl /* merge_units */
#undef sceBInetAddress2IP /* merge_units */
/* merge_units: end func_002F7AB0 */
