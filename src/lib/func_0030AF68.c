typedef struct { int sock; char pad[0x20]; void *buf1; void *buf2; char pad2[0xC]; unsigned int mtu; char pad3[0xA]; unsigned short port; unsigned int idx; } ScfSock;
typedef struct { int a; unsigned int size; int c; } ScfSockOpt;
extern int Net_AllocZeroed(void *out, unsigned long n);
extern void *memset(void *d, int c, unsigned int n);
extern int func_002F5C98(int *sock, int a, unsigned short port, ScfSockOpt *opt);
extern int func_002F5BB0(void);
extern int func_002F65C8(int sock, unsigned short *port);
extern int D_00491310;
extern unsigned short D_00491314;
extern void *D_00491318;
extern void *D_0049131C;
extern ScfSock *D_00529860[8];

int RtUdp_Init(ScfSock *s)
{
    ScfSockOpt opt;
    int r;
    if (s->idx < 8) {
        if (s->mtu >= 0x59F) return 1;
        if (D_00491310 == 0) {
            D_00491314 = s->port;
            if (Net_AllocZeroed(&D_00491318, 0x5AA) != 0) return 9;
            if (Net_AllocZeroed(&D_0049131C, 0x5AA) != 0) return 9;
            memset(D_00529860, 0, 0x20);
            memset(&opt, 0, 12);
            opt.size = 0x5AA;
            opt.a = 1;
            r = func_002F5C98(&D_00491310, 0, D_00491314, &opt);
            if (r == 5) {
                if (func_002F5BB0() != 0) return 16;
                if (func_002F5C98(&D_00491310, 0, D_00491314, &opt) != 0) return 16;
            } else if (r != 0) {
                return 16;
            }
            if (func_002F65C8(D_00491310, &D_00491314) != 0) return 16;
            s->port = D_00491314;
        }
        if (D_00529860[s->idx] == 0) {
            if (s->port != D_00491314) return 16;
            D_00529860[s->idx] = s;
            s->sock = D_00491310;
            s->buf1 = D_00491318;
            s->buf2 = D_0049131C;
        } else return 17;
    } else {
        if (s->mtu >= 0x59F) return 1;
        if (Net_AllocZeroed(&s->buf1, s->mtu + 12) != 0) return 9;
        if (Net_AllocZeroed(&s->buf2, s->mtu + 12) != 0) return 9;
        memset(&opt, 0, 12);
        opt.size = s->mtu + 12;
        opt.a = 1;
        r = func_002F5C98(&s->sock, 0, s->port, &opt);
        if (r == 5) {
            if (func_002F5BB0() != 0) return 16;
            if (func_002F5C98(&s->sock, 0, s->port, &opt) != 0) return 16;
        } else if (r != 0) {
            return 16;
        }
        if (func_002F65C8(s->sock, &s->port) != 0) return 16;
    }
    return 0;
}

