typedef struct {
    int id;
    int addr;
    int type;
    int time;
    int retries;
} Peer_2EE4C8;

typedef struct {
    char pad0[0xC];
    int ids[4];
} Group_2EE4C8;

typedef struct {
    char pad0[0x8];
    int handle;
    char pad0C[0x50 - 0xC];
    char groups[8];
    int groupsOn;
    int peerCount;
    Peer_2EE4C8* peers;
} Net_2EE4C8;

typedef struct {
    unsigned char type;
    char pad1[3];
    unsigned short id;
} Pkt_2EE4C8;

typedef struct {
    char pad0[0x34];
    int selfId;
} Self_2EE4C8;

typedef struct {
    char pad0[0x38];
    unsigned int flags;
    char pad3C[0x844 - 0x3C];
    int stream;
    char pad848[0x854 - 0x848];
    int nextSeq;
    int bufLen;
    void* buf;
} Conn_2EE4C8;

extern int func_002F5160(void);
extern Conn_2EE4C8* func_002D9E88(int handle, unsigned short id);
extern void func_002F33D8(void* groups);
extern Group_2EE4C8* func_002F3388(void* groups, unsigned short id);
extern void func_002D9C10(int handle, char* data, int len, int addr);
extern int func_00315E38(int seq);
extern void func_00315ED8(int stream, int seq, char* data, int len);
extern int func_00315FC8(int stream);
extern int func_002F3228(Conn_2EE4C8* c, int flags);
extern void func_002FB2D8(void** buf, int size);
extern void* memcpy(void* d, const void* s, unsigned int n);

int func_002EE4C8(Net_2EE4C8* net, Pkt_2EE4C8* pkt, Self_2EE4C8* self, char* data, int len)
{
    Group_2EE4C8* grp;
    Conn_2EE4C8* conn;
    Peer_2EE4C8* p;
    int now;
    int useGroups;
    int i;
    int j;
    int seq;
    int s;
    int d;

    now = func_002F5160();
    conn = func_002D9E88(net->handle, pkt->id);
    if (conn == 0) {
        return -1;
    }
    if (pkt->type != 0x30) {
        return -1;
    }
    {
        useGroups = 0;
        if (net->groupsOn) {
            useGroups = 1;
            func_002F33D8(net->groups);
        }
        if (useGroups) {
            grp = func_002F3388(net->groups, pkt->id);
        } else {
            grp = 0;
        }
        for (i = 0; i < net->peerCount; i++) {
            p = &net->peers[i];
            if (p->type != 2) {
                continue;
            }
            if (p->id == self->selfId) {
                p->time = now;
                p->retries = 0;
            } else if (p->id != pkt->id && useGroups) {
                if (grp) {
                    for (j = 3; j >= 0; j--) {
                        if (grp->ids[j] == p->id) {
                            break;
                        }
                    }
                    if (j >= 0) {
                        continue;
                    }
                }
                func_002D9C10(net->handle, data, len, p->addr);
            }
        }
        if (conn->flags & 1) {
            return 0;
        }
        {
            data += 8;
            memcpy(&seq, data, 4);
            data += 4;
            len -= 12;
            if ((seq & 0x60000000) != 0x60000000) {
                s = conn->stream;
                if (s == 0) {
                    s = func_00315E38(seq);
                    conn->stream = s;
                    if (s == 0) {
                        return -1;
                    }
                }
            } else {
                s = conn->stream;
            }
            if (s != 0) {
                func_00315ED8(s, seq, data, len);
                if (func_00315FC8(conn->stream)) {
                    func_002F3228(conn, 0x40000000);
                }
            } else {
                d = seq - conn->nextSeq;
                if (d < 0) {
                    if (d >= -0x10) {
                        goto done;
                    }
                }
                if ((unsigned int)len > 0x800) {
                    return -1;
                }
                if (conn->buf == 0) {
                    func_002FB2D8(&conn->buf, 0x800);
                    if (conn->buf == 0) {
                        return 0;
                    }
                }
                memcpy(conn->buf, data, len);
                conn->bufLen = len;
                func_002F3228(conn, 0x40000000);
                conn->nextSeq = seq + 1;
            }
        done:
            return 0;
        }
    }
}
