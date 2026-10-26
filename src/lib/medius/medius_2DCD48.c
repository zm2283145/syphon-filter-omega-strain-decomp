/*
 * lib/medius: 3 files, 002DCD48-002DCF40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DCD48 */
typedef struct { unsigned int v[100]; } A2DCD48;
extern int NetGetClientPingInfo(unsigned int, A2DCD48 **);
int NetIGetAverageDelayToClient(unsigned int *out, unsigned int idx)
{
    unsigned int buf[100];
    A2DCD48 *src = 0;
    unsigned int t;
    int i, j;
    int r;
    if (idx >= 0x100) return 0x17;
    if (out == 0) return 0x17;
    r = NetGetClientPingInfo(idx, &src);
    if (r) return r;
    if (src == 0) return 0x16;
    for (i = 0; i < 100; i++) buf[i] = src->v[i];
    for (i = 99; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (buf[j] > buf[j + 1]) {
                t = buf[j];
                buf[j] = buf[j + 1];
                buf[j + 1] = t;
            }
        }
    }
    *out = buf[50];
    return 0;
}
/* merge_units: end func_002DCD48 */

/* merge_units: begin func_002DCE20 */
typedef struct { unsigned int v[100]; unsigned int n; } T2DCE20;
#if 0 /* merge_units */
extern int NetGetClientPingInfo(unsigned int, T2DCE20 **);
#endif /* merge_units */
#define NetGetClientPingInfo(a0, a1) (NetGetClientPingInfo((a0), (A2DCD48 * *)(a1))) /* merge_units */

int NetGetPercentileDelayToClient(unsigned int *out, unsigned int id)
{
    unsigned int a[100];
    unsigned int p[1];
    int i, j, r, k;
    unsigned int t;
    p[0] = 0;
    if (id >= 0x100) return 0x17;
    if (out == 0) return 0x17;
    r = NetGetClientPingInfo(id, (T2DCE20 **)p);
    if (r) return r;
    if (p[0] == 0) return 0x16;
    for (i = 0; i < 100; i++) a[i] = ((T2DCE20 *)p[0])->v[i];
    for (i = ((T2DCE20 *)p[0])->n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) { t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }
        }
    }
    k = ((T2DCE20 *)p[0])->n / 20;
    if (k <= 0) k = 1;
    *out = a[k];
    return 0;
}
#undef NetGetClientPingInfo /* merge_units */
/* merge_units: end func_002DCE20 */

/* merge_units: begin func_002DCF40 */
const unsigned int D_0048C4B0[1] = { 0x0 };
extern int rt_p2p_get_buffer_stats(int, int *, int *, int *, int *);
extern int DmeToRtMsgConnectionIndex(unsigned int);
extern int rt_msg_client_get_buffer_status(int, int *, int *, int *, int *);
extern int NetMapMsgClientError(int, int);
int NetIGetBufferStatus(unsigned int a, int *o0, int *o1, int *o2, int *o3)
{
    int v[4];
    int r;
    if (a == 0xFFFF || a == 0) {
        if (rt_p2p_get_buffer_stats((*(int*)D_0048C4B0), &v[0], &v[1], &v[2], &v[3])) return 0x25;
    } else {
        r = NetMapMsgClientError(rt_msg_client_get_buffer_status(DmeToRtMsgConnectionIndex(a), &v[0], &v[1], &v[2], &v[3]), 0x18);
        if (r) return r;
    }
    if (o0) *o0 = v[0];
    if (o1) *o1 = v[1];
    if (o2) *o2 = v[2];
    if (o1) *o3 = v[3];
    return 0;
}
/* merge_units: end func_002DCF40 */
