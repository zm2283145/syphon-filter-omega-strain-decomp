typedef struct {
    int mode; char name[16]; unsigned short port; short pad16; unsigned short port2; short pad1A;
    int x1C; int x20; int x24; int x28; int x2C; void *data; unsigned short len; short pad36;
    int x38; int x3C; int x40; int x44; int x48;
} NsCfg;
typedef struct {
    char pad0[5]; unsigned char b5; unsigned short x6; char name[16]; unsigned short port; short pad1A;
    int x1C[1]; int t20[2]; int t28[2]; int x30; int t34[2]; unsigned short x3C; short pad3E; int x40;
    unsigned char b44; char pad45[11]; int q50[6]; int q68[7]; short pad84; unsigned short x86; unsigned short x88;
} NsSock;
typedef struct {
    unsigned short id; short pad2; unsigned int x4; int x8; NsCfg cfg; int pad58; unsigned char b5C; char pad5D[3];
    int pad60[6]; NsSock *sock[2]; NsSock *active; void *x84; void *x88; void *x8C; void *x90; void *x94;
} NsConn;
typedef struct { int x0; int x4; unsigned char b8; char pad[3]; } NsAddr;
extern unsigned char D_004908EC;
extern unsigned short D_004908F0;
extern unsigned char D_004AF4E8;
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern int NetConn_Allocate(unsigned short *, int, int, int);
extern void KM_Destroy(unsigned short);
extern void KM_Create(unsigned short, int, int);
extern int rt_msg_client_get_connection(unsigned short, NsConn **);
extern int rt_msg_client_change_state(NsConn *, int);
extern int Net_AllocZeroed(void *, unsigned long);
extern int rt_time_start(void *);
extern int rt_circ_buf_clear(void *);
extern int rt_comm_create(void *, char *, unsigned short, NsAddr *);
extern int rt_msg_client_map_comm_error(int);
extern int rt_msg_client_update_comm_wait(NsConn *);

int NetSession_CreateSockets(unsigned short *out, NsCfg *cfg)
{
    NsAddr loc;
    unsigned short id = 0;
    NsConn *conn = 0;
    unsigned char st = D_004908EC;
    NsSock *s;
    unsigned int i;
    int r;

    if (st != 1) return 5;
    if (!out) return 2;
    if (!cfg) return 2;
    if (!cfg->port) return 2;
    if (!cfg->x38) return 2;
    if (cfg->mode >= 2u) return 2;
    *out = D_004908F0 + 1;
    if ((r = NetConn_Allocate(&id, cfg->mode, cfg->x28, cfg->x2C)) != 0) return r;
    *out = id;
    KM_Destroy(id);
    KM_Create(id, 0, cfg->x1C);
    if ((r = rt_msg_client_get_connection(id, &conn)) != 0) return r;
    if (!conn) return 9;
    if (conn->x8 != st) return 23;
    if ((r = rt_msg_client_change_state(conn, 0)) != 0) return r;
    memcpy(&conn->cfg, cfg, sizeof(*cfg));
    if (cfg->data && cfg->len) {
        if (Net_AllocZeroed(&conn->cfg.data, cfg->len)) return 8;
        memcpy(conn->cfg.data, cfg->data, cfg->len);
        conn->cfg.len = cfg->len;
    } else {
        conn->cfg.data = 0;
        conn->cfg.len = 0;
    }
    conn->b5C = D_004AF4E8;
    conn->x84 = (void *)cfg->x38;
    conn->x88 = (void *)cfg->x40;
    conn->x8C = (void *)cfg->x3C;
    conn->x90 = (void *)cfg->x44;
    conn->x94 = (void *)cfg->x48;
    for (i = 0; i < 2; i++) {
        s = conn->sock[i];
        if (s) {
            s->x86 = 0;
            s->x88 = 0;
            if (rt_time_start(s->t20)) return 24;
            if (rt_time_start(s->t28)) return 24;
            s->x3C = 0;
            s->x30 = cfg->x20;
            if (rt_time_start(s->t34)) return 24;
            s->x40 = cfg->x24;
            s->b44 = 0;
            if (rt_circ_buf_clear(s->q50)) return 21;
            if (rt_circ_buf_clear(s->q68)) return 21;
        }
    }
    if ((r = rt_msg_client_change_state(conn, 2)) != 0) return r;
    if (conn->x4 == 1) {
        s = conn->sock[1];
        if (!s) return 9;
        memset(&loc, 0, sizeof(loc));
        loc.x0 = 1;
        loc.x4 = 584;
        if ((r = rt_msg_client_map_comm_error(rt_comm_create(s->x1C, 0, cfg->port2, &loc))) != 0) return r;
        s->b5 = 0;
    }
    if (conn->x4 < 2) {
        s = conn->sock[0];
        if (!s) return 9;
        strncpy(s->name, cfg->name, 15);
        s->name[15] = 0;
        s->port = cfg->port;
        memset(&loc, 0, sizeof(loc));
        loc.x0 = 0;
        loc.b8 = 1;
        if ((r = rt_msg_client_map_comm_error(rt_comm_create(s->x1C, cfg->name, cfg->port, &loc))) != 0) return r;
        s->b5 = 1;
        conn->active = s;
    }
    if (!conn->active) return 9;
    if (conn->id != conn->active->x6) return 1;
    return rt_msg_client_update_comm_wait(conn);
}
