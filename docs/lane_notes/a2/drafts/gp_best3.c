typedef struct {
    int id;
    int addr;
    int state;
    int time;
    unsigned int retries;
} Ent_2EE798;

typedef struct {
    char p0[8];
    int h;
    int xC;
    char name[0x40];
    char p50[8];
    int x58;
    int n;
    Ent_2EE798* ents;
    char p64[0x10];
    int x74;
    int x78[3];
} Net_2EE798;

typedef struct {
    unsigned char type;
    char p1[3];
    unsigned short id;
} Pkt_2EE798;

typedef struct {
    char p0[0x30];
    int chan;
    int id;
    unsigned int flags;
    int x3C;
} Self_2EE798;

typedef struct {
    char p0[8];
    int h;
    char pC[0x24];
    int chan;
    int id;
    char p38[0x810];
    int seq;
    int codec;
} Player_2EE798;

typedef struct { int a, b, c; } Addr_2EE798;

typedef struct {
    unsigned short size;
    unsigned short chan;
    unsigned short count;
    unsigned short max;
    char name[0x3C];
} ChanInfo_2EE798;

extern int GetCurrentTimeMs(void);
extern void AudioSendToPlayer(int h, char* data, int len, int addr);
extern short GetCurChannel(int h);
extern void GridSetPackHeader(Net_2EE798* net, char* hdr, int type, int len);
extern void SendPackage(int h, int to, char* hdr, void* data, int len);
extern void SetPlayerCurChannel(void* p, int chan);
extern Player_2EE798* GetPlayerByID(int h, int id);
extern void GridAddPlayer(Net_2EE798* net, Player_2EE798* p);
extern Net_2EE798* GetGrid(int h, int chan);
extern Net_2EE798* AddGrid(int h, int chan, int kind);
extern void AudioSetConnection(int h, Ent_2EE798* e, int state, int id);
extern int GridExpandConnections(Net_2EE798* net);
extern int randNum(void);
extern void InvalidateConnection(Ent_2EE798* e);
extern void GridSendRedundancyMessage(Net_2EE798* net);
extern void GridRemoveAllRedundancy(Net_2EE798* net, int id);
extern void GridInviteConnect(Net_2EE798* net);
extern char* strncpy(char* d, const char* s, unsigned int n);
extern void GridRemovePlayer(Net_2EE798* net, int id);
extern int GridSendGreeting(Net_2EE798* net, int id, int flag);
extern void AudioSendPingMessage(int h, int id);
extern int GetResourceManager(int h);
extern void ReleaseCodec(int rm, int codec);
extern void ReleaseSequencer(int rm, int seq);
extern void RemovePlayer(int h, int id);
extern void GridAddRedundancy(Net_2EE798* net, int id, int chan);

#define U16(p, o) (*(unsigned short*)((char*)(p) + (o)))
#define I32(p, o) (*(int*)((char*)(p) + (o)))

int GridProcessDataPack(Net_2EE798* net, Pkt_2EE798* pkt, Self_2EE798* self, char* data, int len)
{
    char hdr[16];
    ChanInfo_2EE798 info;
    short ch;
    short ch2;
    int ret;
    int now;
    int fwd;
    int i;
    char* pl;

    pl = data + 8;
    now = GetCurrentTimeMs();
    fwd = 0;
    ret = 0;
    if (net->xC != 0 && net->x58 != 0) {
        switch (pkt->type) {
        case 0:
            fwd = 0;
            break;
        case 1:
            fwd = 0;
            break;
        case 2:
            fwd = 0;
            break;
        case 3:
            I32(pl, 0)++;
            fwd = 1;
            break;
        case 4:
            fwd = 0;
            break;
        case 5:
            fwd = 1;
            break;
        case 6:
            fwd = 1;
            break;
        case 7:
            fwd = 0;
            break;
        case 9:
            fwd = 1;
            break;
        case 10:
            fwd = 1;
            break;
        case 15:
            fwd = 1;
            break;
        case 16:
            fwd = 1;
            break;
        }
    }
    for (i = 0; i < net->n; i++) {
        Ent_2EE798* c = &net->ents[i];
        if (c->state != 2) continue;
        if (c->id == self->id) {
            c->time = now;
            c->retries = 0;
        } else if (c->id != pkt->id) {
            if (fwd) AudioSendToPlayer(net->h, data, len, c->addr);
        }
    }
    switch (pkt->type) {
    case 0:
    case 13:
        break;
    case 1:
        ch = GetCurChannel(net->h);
        GridSetPackHeader(net, hdr, 2, 2);
        SendPackage(net->h, self->id, hdr, &ch, 2);
    case 2:
        if (self->chan != U16(pl, 0)) SetPlayerCurChannel(self, U16(pl, 0));
        break;
    case 3:
        GridSetPackHeader(net, hdr, 4, 8);
        SendPackage(net->h, pkt->id, hdr, pl, 8);
        break;
    case 4:
        self->x3C -= (self->x3C + I32(pl, 4) - now) >> 3;
        break;
    case 15:
        ret = GridSendGreeting(net, pkt->id, 0);
        break;
    case 5: {
        Player_2EE798* pp;
        Net_2EE798* gg;
        Ent_2EE798* ee;
        pp = GetPlayerByID(net->h, pkt->id);
        if (pp->chan != U16(pl, 2)) SetPlayerCurChannel(pp, U16(pl, 2));
        if (net->xC == 0) {
            GridAddPlayer(net, pp);
            if (U16(pl, 2) != 0) {
                gg = GetGrid(net->h, U16(pl, 2));
                if (gg == 0) {
                    unsigned short cc;
                    gg = AddGrid(net->h, U16(pl, 2), 3);
                    cc = U16(pl, 2);
                    GridSetPackHeader(gg, hdr, 7, 2);
                    SendPackage(gg->h, pkt->id, hdr, &cc, 2);
                }
                GridAddPlayer(gg, pp);
            }
        }
        for (i = 0; i < net->n; i++) {
            ee = &net->ents[i];
            if (ee->state == 2 && ee->id == pkt->id) break;
        }
        if (i < net->n) break;
        for (i = 0; i < net->n; i++) {
            ee = &net->ents[i];
            if (ee->state == 0 || ee->id == pkt->id) break;
        }
        if (i >= net->n) {
            if (net->x58 != 0) break;
            GridExpandConnections(net);
            ee = &net->ents[i];
        }
        if (U16(pl, 4) != 0) {
            AudioSetConnection(net->h, ee, 1, pkt->id);
            GridSetPackHeader(net, hdr, 8, 0);
            SendPackage(net->h, pkt->id, hdr, 0, 0);
        } else {
            net->x74 = now;
            *(Addr_2EE798*)net->x78 = *(Addr_2EE798*)pl;
        }
        break;
    }
    case 8: {
        Ent_2EE798* e8;
        int id;
        e8 = 0;
        for (i = 0; i < net->n; i++) {
            e8 = &net->ents[i];
            if (e8->state != 2 || e8->id == pkt->id) break;
        }
        if (i >= net->n && net->x58 == 0) {
            GridExpandConnections(net);
            e8 = &net->ents[i];
        }
        if (i >= net->n) {
            e8 = &net->ents[randNum() % net->n];
            id = e8->id;
            GridSetPackHeader(net, hdr, 14, 0);
            SendPackage(net->h, id, hdr, 0, 0);
            InvalidateConnection(e8);
            if (net->x58 != 0) {
                GridSendRedundancyMessage(net);
                GridRemoveAllRedundancy(net, id);
            }
        }
        AudioSetConnection(net->h, e8, 2, pkt->id);
        GridSetPackHeader(net, hdr, 12, 0);
        SendPackage(net->h, pkt->id, hdr, 0, 0);
        break;
    }
    case 12: {
        Ent_2EE798* e12;
        for (i = 0; i < net->n; i++) {
            e12 = &net->ents[i];
            if (e12->id == pkt->id && (unsigned int)(e12->state - 1) < 2) break;
        }
        if (i < net->n) {
            e12->time = now;
            e12->state = 2;
            e12->retries = 0;
            break;
        }
        GridSetPackHeader(net, hdr, 14, 0);
        SendPackage(net->h, pkt->id, hdr, 0, 0);
        break;
    }
    case 14:
        for (i = 0; i < net->n; i++) {
            Ent_2EE798* c = &net->ents[i];
            if (c->id == pkt->id) {
                InvalidateConnection(c);
                if (net->x58 != 0) {
                    GridSendRedundancyMessage(net);
                    GridInviteConnect(net);
                    GridRemoveAllRedundancy(net, pkt->id);
                }
                break;
            }
        }
        break;
    case 6: {
        Player_2EE798* p6;
        Net_2EE798* g6;
        if (GetGrid(net->h, U16(pl, 2)) != 0) break;
        p6 = GetPlayerByID(net->h, pkt->id);
        g6 = AddGrid(net->h, U16(pl, 2), U16(pl, 4));
        strncpy(g6->name, pl + 8, 0x40);
        g6->name[0x3F] = 0;
        SetPlayerCurChannel(p6, U16(pl, 2));
        break;
    }
    case 7: {
        Net_2EE798* g;
        g = GetGrid(net->h, U16(pl, 0));
        if (g == 0) break;
        {
            unsigned short u, v;
            u = g->x58;
            v = g->xC;
            info.size = 0x44;
            info.count = u;
            info.chan = v;
            info.max = u;
            strncpy(info.name, g->name, 0x3C);
            info.name[0x3B] = 0;
        }
        GridSetPackHeader(g, hdr, 11, 0x44);
        SendPackage(g->h, pkt->id, hdr, &info, 0x44);
        break;
    }
    case 11: {
        Net_2EE798* g;
        g = GetGrid(net->h, U16(pl, 2));
        if (g == 0) break;
        strncpy(g->name, pl + 8, 0x40);
        if (U16(pl, 4) != 0) break;
        if (g->x58 == 0) break;
        g->x58 = 0;
        GridExpandConnections(g);
        break;
    }
    case 9: {
        Player_2EE798* p;
        Net_2EE798* g;
        if (U16(pl, 0) == 0) break;
        p = GetPlayerByID(net->h, pkt->id);
        if (p == 0) break;
        if (p->chan > 0 && p->chan != U16(pl, 0)) {
            g = GetGrid(net->h, p->chan);
            if (g != 0) GridRemovePlayer(g, p->id);
        }
        g = GetGrid(net->h, U16(pl, 0));
        if (g == 0) break;
        if (p->chan != g->xC) SetPlayerCurChannel(p, g->xC);
        if (GetCurChannel(g->h) != g->xC) break;
        if (g->x58 != 0) {
            ret = GridSendGreeting(g, pkt->id, 1);
        } else {
            AudioSendPingMessage(g->h, pkt->id);
        }
        break;
    }
    case 10: {
        Player_2EE798* p;
        if (U16(pl, 0) == 0) break;
        p = GetPlayerByID(net->h, pkt->id);
        if (GetGrid(net->h, U16(pl, 0)) == 0) break;
        if (p == 0) break;
        if (p->codec != 0) {
            ReleaseCodec(GetResourceManager(p->h), p->codec);
            p->codec = 0;
        }
        if (p->seq != 0) {
            ReleaseSequencer(GetResourceManager(p->h), p->seq);
            p->seq = 0;
        }
        SetPlayerCurChannel(p, 0);
        break;
    }
    case 16:
        RemovePlayer(net->h, pkt->id);
        break;
    case 17:
        {
            int f = I32(pl, 0);
            unsigned int fl = self->flags;
            if (f & 1) fl |= 0x10000; else fl &= ~0x10000;
            if (f & 2) fl |= 0x20000; else fl &= ~0x20000;
            self->flags = fl;
        }
        break;
    case 18: {
        Net_2EE798* g;
        if (U16(pl, 0) == 0) break;
        g = GetGrid(net->h, U16(pl, 0));
        if (U16(pl, 2) == 0xFFFF) {
            GridRemoveAllRedundancy(g, pkt->id);
        } else {
            GridAddRedundancy(g, pkt->id, U16(pl, 2));
        }
        break;
    }
    }
    return ret;
}
