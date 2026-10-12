typedef struct { unsigned char flags; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { unsigned int type; char pad[4]; char name[16]; unsigned short port; char pad1[2]; int sendlist; char pad2[0x14]; int recvlist; char pad3[0x14]; int timer[2]; char pad4[0x18]; int f6C; int f70; int f74; int f78; int f7C; int f80; int f84; char pad5[8]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; char pad[0x28]; int pool1; int pool2; char pad2[0xC]; unsigned char b44; } ScfSock;
typedef struct { int f0; int f4; int f8; } ScfInfo;
extern char *strncpy(char *d, const char *s, unsigned int n);
extern int func_003089B0(ScfSock *s, int *idx);
extern int func_00306DE0(void);
extern int func_003060C0(int *timer);
extern int func_002FA4C8(int *list, int pool);
extern int func_0030AB20(ScfSock *s, ScfPeer *e);
extern int RtUdp_BuildHeader(ScfSock *s, ScfPeer *e, int kind, ScfHdr *hd);
extern int RtUdp_CopyPacket(ScfPeer *e, ScfHdr *hd, void *data, int len);
extern int RtUdp_QueueAck(ScfSock *s, ScfPeer *e, ScfInfo *info);

int func_00309FD8(ScfSock *s, ScfInfo *info, char *name, unsigned short port)
{
    ScfHdr hd;
    ScfPeer *e = 0;
    int idx = -1;
    int ret;
    if (info->f4 == 0) return 0;
    for (;;) {
        ret = func_003089B0(s, &idx);
        if (ret != 0) { ret = 7; break; }
        if (idx == -1) { ret = 7; break; }
        e = &s->ents[idx];
        e->f74 = info->f4;
        e->f78 = func_00306DE0();
        e->f7C = func_00306DE0();
        e->f80 = 0;
        e->port = port;
        e->f84 = info->f8;
        strncpy(e->name, name, 16);
        func_003060C0(e->timer);
        e->f70 = 1000;
        e->f6C = 0;
        if (func_002FA4C8(&e->sendlist, s->pool1) != 0 || func_002FA4C8(&e->recvlist, s->pool2) != 0) {
            e->type = 6;
            func_0030AB20(s, e);
            ret = 7;
        }
        break;
    }
    if (ret != 0) return ret;
    switch (e->type) {
    case 0:
        if (s->b44 == 0) {
            e->type = 7;
            break;
        }
        e->type = 9;
        ret = RtUdp_BuildHeader(s, e, 4, &hd);
        if (ret != 0) {
fail:
            e->type = 1;
            func_0030AB20(s, e);
            return ret;
        }
        hd.flags |= 0x40;
        ret = RtUdp_CopyPacket(e, &hd, 0, 0);
        if (ret != 0) goto fail;
        ret = RtUdp_QueueAck(s, e, info);
        break;
    case 8:
    case 9:
    case 11:
    case 12:
        ret = RtUdp_QueueAck(s, e, info);
        break;
    default:
        e->type = 1;
        ret = func_0030AB20(s, e);
        break;
    }
    return ret;
}



