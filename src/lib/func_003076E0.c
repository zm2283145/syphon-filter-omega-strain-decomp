typedef struct {
    int state; int f4; char name[16]; unsigned short port; char pad1A[2];
    char f1C[0x18]; char f34[0x18]; char f4C[8]; char f54[8]; char pad5C[0x10];
    int f6C; int f70; int f74; int f78; int f7C; char pad80[0xC]; int f8C;
} RtPeer;
typedef struct {
    int f0; RtPeer *peers; int f8; char q[0x20]; unsigned int npeers; int f30; int f34;
} RtUdp;
typedef struct { char name[16]; unsigned short port; int f14; } RtAddr;
extern int func_00307488(RtUdp *r, char *name, unsigned short *port);
extern int func_00307530(RtUdp *r, char *name, unsigned short *port);
extern int strcmp(const char *a, const char *b);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern int func_003089B0(RtUdp *r, int *idx);
extern int func_002FA4C8(void *q, int n);
extern int func_00306DE0(void);
extern int func_003060C0(void *t);
extern int func_00306D88(void);
extern int func_002F8DC8(int a, int b, unsigned char *buf);
extern int func_00309CA8(RtUdp *r, RtPeer *p, unsigned char *buf);
extern int RtUdp_BuildHeader(RtUdp *r, RtPeer *p, int kind, unsigned char *hdr);
extern int RtUdp_CopyPacket(RtPeer *p, unsigned char *hdr, void *body, int n);
int func_003076E0(RtUdp *r, RtAddr *a, int *out)
{
    RtAddr self;
    unsigned char buf[0x40];
    unsigned char hdr[16];
    int idx = -1;
    RtPeer *p;
    int ret;
    if (out == 0) return 1;
    *out = -1;
    if (a == 0) return 1;
    if (r == 0) return 2;
    self.name[0] = 0;
    self.port = 0;
    func_00307488(r, self.name, &self.port);
    if (a->port == self.port && strcmp(a->name, self.name) == 0) return 0x15;
    self.name[0] = 0;
    self.port = 0;
    func_00307530(r, self.name, &self.port);
    if (a->port == self.port && strcmp(a->name, self.name) == 0) return 0x15;
    ret = func_003089B0(r, &idx);
    if (ret != 0) return ret;
    *out = idx;
    p = &r->peers[idx];
    if (func_002FA4C8(p->f1C, r->f30) != 0) {
        r->peers[idx].state = 6;
        return 7;
    }
    if (func_002FA4C8(p->f34, r->f34) != 0) {
        p->state = 6;
        return 7;
    }
    p->state = 9;
    p->f74 = func_00306DE0();
    p->f78 = func_00306DE0();
    p->f7C = func_00306DE0();
    p->port = a->port;
    strncpy(p->name, a->name, 16);
    func_003060C0(p->f4C);
    func_003060C0(p->f54);
    p->f70 = 1000;
    p->f6C = 0;
    p->f8C = a->f14;
    if (func_00306D88() == 1) {
        func_002F8DC8(-1, p->f8C, buf);
        ret = func_00309CA8(r, p, buf);
    } else {
        if (RtUdp_BuildHeader(r, p, 4, hdr) != 0) {
            p->state = 6;
            return 7;
        }
        hdr[0] |= 0x40;
        ret = RtUdp_CopyPacket(p, hdr, 0, 0);
    }
    if (ret != 0) {
        p->state = 6;
        return 7;
    }
    return 0;
}
