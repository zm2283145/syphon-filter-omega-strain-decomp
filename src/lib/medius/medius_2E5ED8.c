/*
 * lib/medius: 3 files, 002E5ED8-002E6010
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E5ED8 */
extern void *memset(void *, int, unsigned int);
extern unsigned char D_0048C4B4;
extern int D_00522758;
extern int D_0048C474;
extern void (*D_0048C470)(void *);
extern void rt_time_elapsed(int *, unsigned int *);
typedef struct { int a, b, c, d, e; } M2E5ED8;
int func_002E5ED8(void)
{
    M2E5ED8 m;
    unsigned int t;
    if (D_0048C4B4) {
        rt_time_elapsed(&D_00522758, &t);
        if (t >= 0x1F5) {
            memset(&m, 0, 0x14);
            m.e = D_0048C474;
            m.a = 0;
            m.b = 0;
            m.c = 0;
            m.d = 0;
            D_0048C470(&m);
            D_0048C4B4 = 0;
        }
    }
    return 0;
}
/* merge_units: end func_002E5ED8 */

/* merge_units: begin func_002E5F68 */
typedef struct { char pad[0x10]; int h; char pad2[0x18]; char sub[0x18]; } E2E5F68;
extern E2E5F68 *D_0048C4A8;
extern void DmeFree(int *);
extern void rt_circ_buf_destroy(char *);
int NetFreeAllDataStreams(void)
{
    unsigned int i;
    if (D_0048C4A8 == 0) return 0;
    for (i = 0; i < 0x800; i++) {
        if (D_0048C4A8[i].h) DmeFree(&D_0048C4A8[i].h);
        if (D_0048C4A8[i].sub) rt_circ_buf_destroy(D_0048C4A8[i].sub);
    }
    return 0;
}
/* merge_units: end func_002E5F68 */

/* merge_units: begin func_002E6010 */
extern int NetGetConnInfo(unsigned int, char **);
extern void NetIDisconnect(unsigned int);
int DisconnectFailedConnections(void)
{
    char *p = 0;
    unsigned int i;
    for (i = 0; i < 4; i++) {
        if (NetGetConnInfo(i, &p) == 0 && p != 0 && *(int *)(p + 0x438) == 3)
            NetIDisconnect(i);
    }
    return 0;
}
/* merge_units: end func_002E6010 */
