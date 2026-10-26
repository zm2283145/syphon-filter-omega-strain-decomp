/*
 * lib/medius: 4 files, 002DD030-002DD1F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DD030 */
extern int D_0048C4B0;
extern int rt_p2p_set_send_aggregation(int, int, int);
extern int DmeToRtMsgConnectionIndex(unsigned int);
extern int rt_msg_client_set_send_aggregation_time(int, int);
extern int rt_msg_client_set_server_send_aggregation_time(int, int);
extern int NetMapMsgClientError(int, int);
int NetISetSendAggregationInterval(unsigned int a, int b, int c)
{
    int r;
    if (a == 0xFFFF || a == 0) {
        if (rt_p2p_set_send_aggregation(D_0048C4B0, b, c)) return 0x25;
    } else {
        r = NetMapMsgClientError(rt_msg_client_set_send_aggregation_time(DmeToRtMsgConnectionIndex(a), b), 0x18);
        if (r) return r;
        r = NetMapMsgClientError(rt_msg_client_set_server_send_aggregation_time(DmeToRtMsgConnectionIndex(a), c), 0x18);
        if (r) return r;
    }
    return 0;
}
/* merge_units: end func_002DD030 */

/* merge_units: begin func_002DD0F0 */
extern int rt_msg_client_get_metrics(int, float *);
int NetIGetBandwidthInfo(float *out)
{
    float buf[16];
    int r;
    if (out == 0) return 0x17;
    r = NetMapMsgClientError(rt_msg_client_get_metrics(0, buf), 0x18);
    if (r) return r;
    out[2] = buf[6];
    out[3] = buf[7];
    out[0] = buf[3];
    out[1] = buf[4];
    out[6] = buf[12];
    out[7] = buf[13];
    out[4] = buf[9];
    out[5] = buf[10];
    return r;
}
/* merge_units: end func_002DD0F0 */

/* merge_units: begin func_002DD178 */
unsigned int D_0048C458[1] = { 0x0 };
extern int NetGetConnInfo(unsigned int, char **);
int NetIGetMyClientIndex(int *out, unsigned int idx)
{
    char *p = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0x100;
    if ((*(int*)D_0048C458) == 0) return 0x11;
    if (idx >= 4) return 0x17;
    r = NetGetConnInfo(idx, &p);
    if (r) return r;
    if (p == 0) return r;
    *out = *(int *)(p + 0x400);
    return r;
}
/* merge_units: end func_002DD178 */

/* merge_units: begin func_002DD1F8 */
extern long rt_p2p_get_host_index(int, int *);
int NetIGetPeerToPeerHostClientIndex(int a, int *out)
{
    int v = -2;
    if (a != 0) return 0x17;
    if (out == 0) return 0x17;
    *out = 0x100;
    if (rt_p2p_get_host_index(D_0048C4B0, &v) != 0) return 0x25;
    if (v == -2) return 1;
    *out = v;
    return 0;
}
/* merge_units: end func_002DD1F8 */
