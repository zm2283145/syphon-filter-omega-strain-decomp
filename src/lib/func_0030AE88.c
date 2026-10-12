typedef struct {
    char pad[0x5C];
    int timer[2];
    int pending;
    unsigned int rttvar;
    unsigned int srtt;
    unsigned int rto;
} RtUdpRtt;
extern void func_003060F0(int *timer, unsigned int *elapsed);
int RtUdp_UpdateRtt(void *ctx, RtUdpRtt *r, unsigned char flags, int seq)
{
    unsigned int elapsed;
    unsigned int srtt, rttvar, rto, v;
    int ret = 1;
    if (ctx == 0) return ret;
    if (r == 0) return ret;
    if (((flags & 6) == 6 || (flags & 4)) && r->pending != 0 && seq == r->pending) {
        func_003060F0(r->timer, &elapsed);
        srtt = r->srtt;
        rttvar = r->rttvar;
        if (srtt == 0) {
            srtt = elapsed;
            rttvar = elapsed >> 1;
        } else {
            rttvar = (rttvar * 3 + __builtin_abs(srtt - elapsed)) >> 2;
            srtt = (srtt * 7 + elapsed) >> 3;
        }
        v = rttvar;
        if (v == 0) v = 1;
        rto = srtt + v;
        r->srtt = srtt;
        r->rttvar = rttvar;
        r->pending = 0;
        if (rto > 500) rto = 500;
        r->rto = rto;
    }
    return 0;
}
