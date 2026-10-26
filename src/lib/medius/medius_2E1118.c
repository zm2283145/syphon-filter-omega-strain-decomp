/*
 * lib/medius: 2 files, 002E1118-002E1158
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E1118 */
extern void *memset(void *, int, unsigned int);
int NetISetDefaultIncomingClientParams(int *p)
{
    if (p == 0) return 0x17;
    memset(p, 0, 0x74);
    p[0] = 1;
    return 0;
}
/* merge_units: end func_002E1118 */

/* merge_units: begin func_002E1158 */
typedef struct { int a; int err; } R2E1158;
extern int D_0048C458;
extern unsigned char D_0048C4AC;
extern int NetIsPeerToPeerHost(unsigned char *);
extern void NetSetIncomingClient(int *, R2E1158 *);
int NetIIncomingClient(int *req, R2E1158 *res)
{
    unsigned char st = 0;
    unsigned char ready;
    if (res == 0) return 0x17;
    res->err = 0x1E;
    res->a = 1;
    if (req == 0) {
        res->err = 0x17;
        return 0x17;
    }
    if (D_0048C458 != 1) {
        res->err = 0x11;
        return 0x11;
    }
    if (*req != 1) {
        res->err = 0x26;
        return 0x26;
    }
    ready = D_0048C4AC;
    if (ready != 1) {
        res->err = 0x1A;
        return 0x1A;
    }
    res->err = NetIsPeerToPeerHost(&st);
    if (res->err == 0) {
        if (st == 1) NetSetIncomingClient(req, res);
    }
    return res->err;
}
/* merge_units: end func_002E1158 */
