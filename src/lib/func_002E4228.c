__asm__("dpcmp = SoftFloat_UnpackAndCompare\n"
        "dpmul = SoftFloat_DoubleMultiply\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "litodp = SoftFloat_IntToDouble");

typedef unsigned int u32;
typedef struct { char pad[0x400]; int f400; } Conn_2E4228;
typedef struct { char pad[0xA]; unsigned short base; unsigned short count; } Tbl_2E4228;
typedef struct {
    unsigned char state;
    unsigned char pad1[2];
    unsigned char slot;
    unsigned char f4;
    unsigned char f5;
    unsigned char pad6[2];
    int f8;
    int padC;
    void* buf;
    char pad14[0xC];
    int rate;
    char pad24[2];
    unsigned short maxLen;
    volatile int time;
    char q[0x8];
    int len;
    int pad38;
    void* data;
} Ent_2E4228;

extern u32 D_0048C450;
extern double D_004ADC80;
extern char D_0051FCD8[];
extern volatile int D_0058806C;
extern int D_00590318[];
extern int D_0059840C;
extern int NetGetConnInfo(u32, Conn_2E4228**);
extern int NetIGetClient(Tbl_2E4228**, u32, int);
extern int NetIGetSessionMasterClientIndex(int*, u32);
extern int NetGetStreamChannel(int, Ent_2E4228**);
extern int rt_circ_buf_get_used(void*, u32*);
extern int NetGetDataStreamPacket(char*, int, u32);
extern int NetSendDmeMessage(int, u32, int, int, int, char*);
extern void rt_circ_buf_free(void*, u32);
extern int rt_circ_buf_normalize(void*, int);
extern void* memcpy(void*, const void*, unsigned int);
extern void DmeFree(void*);
extern void rt_circ_buf_destroy(void*);
extern void SendCloseDataStream(int, int);

static inline void Stamp_2E4228(Ent_2E4228* x, u32 n)
{
    x->time = D_0058806C;
    rt_circ_buf_free(x->q, n);
}

static inline void Reset_2E4228(Ent_2E4228* x)
{
    x->state = 1;
    x->buf = 0;
}

void SendClientDataStreams(void)
{
    Conn_2E4228* conn;
    Tbl_2E4228* tbl;
    int idx;
    Ent_2E4228* e;
    u32 n;
    u32 i;

    idx = 0x100;
    e = 0;
    tbl = 0;
    conn = 0;

    if (D_0048C450 >= 4) return;
    if (NetGetConnInfo(D_0048C450, &conn) != 0) return;
    if (conn == 0) return;
    if (NetIGetClient(&tbl, D_0048C450, conn->f400) != 0) return;
    if (tbl == 0) return;
    if (tbl->base >= 0x800) return;
    if (NetIGetSessionMasterClientIndex(&idx, D_0048C450) != 0) return;
    if (idx < 0) return;
    if (idx >= 0x100) return;

    for (i = 0; i < tbl->count; i++) {
        int id = i + tbl->base;
        int dest;
        if (NetGetStreamChannel(id, &e) != 0) continue;
        if (e == 0) continue;
        if (e->state != 2) continue;
        dest = e->f8;
        if (D_00590318[e->slot] != 0 && conn->f400 != idx) {
            if (e->f5) dest = idx;
        }
        if (e == (Ent_2E4228*)-0x2C) continue;
        n = 0;
        if (rt_circ_buf_get_used(e->q, &n) != 0) continue;
        if (n != 0) {
            Ent_2E4228* ent = e;
            u32 m;
            u32 len;
            int dt;
            m = ent->maxLen < n ? ent->maxLen : n;
            dt = D_0058806C - ent->time;
            n = m < 0x100 ? m : 0xFF;
            len = n;
            if ((double)(n * 1000) < (double)(ent->rate * dt) * 1.02) {
                if (NetSendDmeMessage(0x50, D_0048C450, dest, D_0059840C,
                                  NetGetDataStreamPacket(D_0051FCD8, id, len), D_0051FCD8) == 0) {
                    Stamp_2E4228(e, n);
                    rt_circ_buf_normalize(e->q, 1);
                    memcpy(e->buf, e->data, e->len);
                }
            }
        } else if (e->f4 != 0) {
            DmeFree(&e->buf);
            rt_circ_buf_destroy(e->q);
            Reset_2E4228(e);
            SendCloseDataStream(dest, id);
        }
    }
}