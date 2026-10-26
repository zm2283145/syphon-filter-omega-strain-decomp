/*
 * lib/medius: 5 files, 002DEBE0-002DEF08
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DEBE0 */
extern unsigned int D_0048C450;
extern int D_00598400;
extern int NetFreeRemoteObject(unsigned int);
extern int NetSendDmeMessage(int, unsigned int, int, int, int, unsigned short *);
int NetFreeLocalObject(unsigned int a)
{
    unsigned short v;
    if (a >= 0x1000) return 0x17;
    if (D_0048C450 >= 4) return 8;
    NetFreeRemoteObject(a);
    v = a;
    NetSendDmeMessage(0x50, D_0048C450, -1, D_00598400, 2, &v);
    return 0;
}
/* merge_units: end func_002DEBE0 */

/* merge_units: begin func_002DEC60 */
extern int NetIGetObject(unsigned char **, unsigned int);
extern int NetGetConnInfo(unsigned int, char **);
#if 0 /* merge_units */
extern int NetFreeLocalObject(unsigned int);
#endif /* merge_units */
#define NetFreeLocalObject(a0) (NetFreeLocalObject((a0))) /* merge_units */

#if 0 /* merge_units */
extern void NetFreeRemoteObject(unsigned int);
#endif /* merge_units */
#define NetFreeRemoteObject(a0) ((void)NetFreeRemoteObject((a0))) /* merge_units */

int NetIFreeObject(unsigned int id)
{
    char *q = 0;
    unsigned char *p = 0;
    int r;
    if (id >= 0x1000) return 0x17;
    if (D_0048C450 >= 4) return 8;
    NetIGetObject(&p, id);
    if (p == 0) return 8;
    r = NetGetConnInfo(D_0048C450, &q);
    if (r) return r;
    if (q == 0) return r;
    if (*(int *)(p + 8) == *(int *)(q + 0x400)) {
        NetFreeLocalObject(id);
        return 0;
    }
    NetFreeRemoteObject(id);
    return 0;
}
#undef NetFreeLocalObject /* merge_units */
#undef NetFreeRemoteObject /* merge_units */
/* merge_units: end func_002DEC60 */

/* merge_units: begin func_002DED20 */
struct Grp { char pad[6]; unsigned short start; unsigned short count; };
extern signed char D_0058C178[];
extern void NetIGetClient(struct Grp **, unsigned int, unsigned int);
#if 0 /* merge_units */
extern int NetIGetObject(int *, unsigned int);
#endif /* merge_units */
#define NetIGetObject(a0, a1) (NetIGetObject((unsigned char * *)(a0), (a1))) /* merge_units */

extern int strcmp(const char *, const char *);
int LocalObjectName2Index(const char *name, unsigned int a, unsigned int b)
{
    struct Grp *g;
    int e;
    int i;
    int ret = -1;
    if (name == 0) return ret;
    if (a >= 4) return ret;
    if (b >= 0x100) return ret;
    NetIGetClient(&g, a, b);
    if (g != 0) {
        for (i = 0; i < g->count; ) {
            unsigned int id = i + g->start;
            i++;
            if (D_0058C178[id] == 2) {
                char *s;
                NetIGetObject(&e, id);
                s = (char *)e + 0xC;
                if (s && strcmp(s, name) == 0) return id;
            }
        }
    }
    return -1;
}
#undef NetIGetObject /* merge_units */
/* merge_units: end func_002DED20 */

/* merge_units: begin func_002DEE30 */
#if 0 /* merge_units */
extern void NetIGetClient(unsigned char **, unsigned int, int);
#endif /* merge_units */
#define NetIGetClient(a0, a1, a2) (NetIGetClient((struct Grp * *)(a0), (a1), (unsigned int)(a2))) /* merge_units */

int FindFreeLocalObject(void)
{
    char *q = 0;
    unsigned char *p = 0;
    int r;
    int i;
    if (D_0048C450 >= 4) return -1;
    r = NetGetConnInfo(D_0048C450, &q);
    if (r) return r;
    if (q == 0) return r;
    NetIGetClient(&p, D_0048C450, *(int *)(q + 0x400));
    if (p == 0) return -1;
    for (i = 0; i < *(unsigned short *)(p + 8); i++) {
        if (D_0058C178[i + *(unsigned short *)(p + 6)] != 2)
            return i + *(unsigned short *)(p + 6);
    }
    return -1;
}
#undef NetIGetClient /* merge_units */
/* merge_units: end func_002DEE30 */

/* merge_units: begin func_002DEF08 */
extern int D_005227E0[];
extern int NetMsg_Dispatch(unsigned int, int, unsigned short, int, unsigned short, int);
void Net_DispatchRecv(int a, unsigned int idx, unsigned short c, int d, unsigned short e)
{
    int h = NetMsg_Dispatch(idx, a, c, d, e, 0);
    if (idx < 4) D_005227E0[idx] = h;
    if (idx == 0xFFFF) D_005227E0[0] = h;
}
/* merge_units: end func_002DEF08 */
