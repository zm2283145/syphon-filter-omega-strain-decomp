/*
 * lib/medius: 7 files, 002ED940-002EE1E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002ED940 */
typedef struct {
    int a;
    char *b;
    int state;
    int time;
    unsigned int retries;
} Ent;

typedef struct Node {
    int x0;
    struct Node *next;
} Node;

typedef struct {
    char p0[8];
    int h;
    int xC;
    char p10[0x48];
    int x58;
    int n;
    Ent *ents;
} Conn;

extern int GetAudioSequence(int);
extern int GetVideoSequence(int);
extern unsigned short GetPackSequence(int);
extern int AudioSendToPlayer(int, char *, int, char *);
extern Node *GetFirstPlayer(int);
extern Node *GetMyPlayer(int);
extern void *memcpy(void *, const void *, unsigned int);

int GridSendPackage(Conn *s, int h, char *buf, char *src, int len)
{
    char pkt[0x500];
    int tmp;
    char *p = pkt;
    int first = 1;
    int mode;
    int result;
    char *data;
    int hl;
    int n;
    int i;
    char *nd;

    memcpy(pkt, buf, 8);
    data = src;
    mode = 0;
    result = 0;
again:
    {
        hl = 8;
        switch (buf[0] & 0x7F) {
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x2F:
            mode = 1;
            hl = 12;
            tmp = GetAudioSequence(s->h);
            memcpy(p + 8, &tmp, 4);
            break;
        case 0x30:
            tmp = GetVideoSequence(s->h);
            if (first)
                tmp |= 0x20000000;
            if ((unsigned int)len < 0x1F9)
                tmp |= 0x40000000;
            memcpy(p + 8, &tmp, 4);
            hl = 12;
            mode = 2;
            break;
        }
        n = len;
        if ((buf[0] & 0x7F) == 0x30) {
            if (len > 0x1F8)
                n = 0x1F8;
            *(unsigned short *)(pkt + 2) = n;
        }
        memcpy(pkt + hl, data, n);
        len -= n;
        hl += n;
        data += n;
        if (s->xC > 0) {
            for (i = 0; i < s->n; i++) {
                nd = s->ents[i].b;
                if (nd == 0)
                    continue;
                if (s->x58 == 0) {
                    if (mode == 1 && (*(int *)(nd + 0x38) & 0x20000))
                        continue;
                    if (mode == 2 && (*(int *)(nd + 0x38) & 0x10000))
                        continue;
                }
                if (s->ents[i].state != 2)
                    continue;
                if (s->ents[i].a == h)
                    continue;
                if (hl != AudioSendToPlayer(s->h, pkt, hl, nd))
                    result = -1;
            }
        } else {
            nd = (char *)GetFirstPlayer(s->h);
            while ((char *)GetMyPlayer(s->h) != (nd = (char *)((Node *)nd)->next)) {
                if (hl != AudioSendToPlayer(s->h, pkt, hl, nd))
                    result = -1;
            }
        }
        if (len != 0) {
            *(unsigned short *)(pkt + 6) = GetPackSequence(s->h);
            first = 0;
            goto again;
        }
    }
    return result;
}
/* merge_units: end func_002ED940 */

/* merge_units: begin func_002EDC60 */
extern char *strncpy(char *, const char *, unsigned int);
typedef struct { char p0[0xC]; int xC; char x10[0x48]; int x58; } A;
typedef struct { unsigned short x0, x2, x4, x6; char x8[0x3C]; } B;
void GridSetChannelInfo(A *a, B *b)
{
    unsigned short u, v;
    u = a->x58;
    v = a->xC;
    b->x0 = 0x44;
    b->x4 = u;
    b->x2 = v;
    b->x6 = u;
    strncpy(b->x8, a->x10, 0x3C);
    b->x8[0x3B] = 0;
}
/* merge_units: end func_002EDC60 */

/* merge_units: begin func_002EDCB0 */
extern unsigned short GetPlayerCountInSet(char *);
void GridGetEnumChannelInfo(char *src, unsigned short *d)
{
    d[0] = *(unsigned short *)(src + 0xC);
    strncpy((char *)d + 4, src + 0x10, 0x3C);
    ((char *)d)[0x3F] = 0;
    d[1] = GetPlayerCountInSet(src + 0x50);
}
/* merge_units: end func_002EDCB0 */

/* merge_units: begin func_002EDD08 */
typedef struct { unsigned char type; unsigned char ver; unsigned short len; unsigned short id; unsigned short seq; } H2EDD08;
typedef struct { int x0; int x4; void *conn; unsigned int xC; } S2EDD08;
extern void GetLocalID(void *, int *);
#if 0 /* merge_units */
extern int GetPackSequence(void *);
#endif /* merge_units */
#define GetPackSequence(a0) ((int)GetPackSequence((int)(a0))) /* merge_units */

void GridSetPackHeader(S2EDD08 *s, H2EDD08 *h, int type, int len)
{
    int id = 0xFFFF;
    GetLocalID(s->conn, &id);
    h->type = type | 0x80;
    h->len = len;
    { int seq = GetPackSequence(s->conn);
      h->seq = seq;
      h->ver = s->xC;
      h->id = id; }
}
#undef GetPackSequence /* merge_units */
/* merge_units: end func_002EDD08 */

/* merge_units: begin func_002EDD88 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { int a, b, c, time, e; } E2EDD88;
extern int GetCurrentTimeMs(void);
extern void rt_memory_allocate_init_zero(void *, unsigned long);
extern int rt_memory_free(void *);
extern void *memset(void *, int, unsigned int);
int GridExpandConnections(void *s)
{
    E2EDD88 *old;
    int now, i;
    if (s == 0 || F(s, int, 0x58) != 0) return -1;
    now = GetCurrentTimeMs();
    old = F(s, E2EDD88 *, 0x60);
    rt_memory_allocate_init_zero(&F(s, E2EDD88 *, 0x60), (unsigned int)(F(s, int, 0x5C) * 2 * sizeof(E2EDD88)));
    if (F(s, E2EDD88 *, 0x60) == 0) {
        F(s, E2EDD88 *, 0x60) = old;
        return -1;
    }
    for (i = 0; i < F(s, int, 0x5C); i++)
        F(s, E2EDD88 *, 0x60)[i] = old[i];
    rt_memory_free(&old);
    F(s, int, 0x5C) *= 2;
    for (; i < F(s, int, 0x5C); i++) {
        memset(&F(s, E2EDD88 *, 0x60)[i], 0, sizeof(E2EDD88));
        F(s, E2EDD88 *, 0x60)[i].time = now;
    }
    return 0;
}
/* merge_units: end func_002EDD88 */

/* merge_units: begin func_002EDEE8 */
typedef struct {
    int a;
    int b;
    int state;
    int time;
    unsigned int retries;
} Ent_002EDEE8;

typedef struct {
    char p0[8];
    int h;
    int xC;
    char p10[0x48];
    int x58;
    int n;
    Ent_002EDEE8 *ents;
    char p64[8];
    int x6C;
    int x70;
    int x74;
    char x78[8];
    int x80;
} Conn_002EDEE8;

typedef struct {
    int a;
    int t;
    int c, d;
} Stamp;
extern void AudioSetConnection(int, Ent_002EDEE8 *, int, int);
#if 0 /* merge_units */
extern void GridSetPackHeader(Conn_002EDEE8 *, char *, int, int);
#endif /* merge_units */
#define GridSetPackHeader(a0, a1, a2, a3) (GridSetPackHeader((S2EDD08 *)(a0), (H2EDD08 *)(a1), (a2), (a3))) /* merge_units */

extern void SendPackage(int, int, char *, void *, int);
extern short GetCurChannel(int);
extern void InvalidateConnection(Ent_002EDEE8 *);
extern void SetAudioStatus(int, int);
extern void ResetAudioStatus(int, int);
extern void GridInviteConnect(Conn_002EDEE8 *);
#if 0 /* merge_units */
extern void GetLocalID(int, int *);
#endif /* merge_units */
#define GetLocalID(a0, a1) (GetLocalID((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void GridSendPackage(Conn_002EDEE8 *, int, char *, void *, int);
#endif /* merge_units */
#define GridSendPackage(a0, a1, a2, a3, a4) ((void)GridSendPackage((Conn *)(a0), (a1), (a2), (char *)(a3), (a4))) /* merge_units */

extern void JoinChannel(int, int);

int GridUpdate(Conn_002EDEE8 *s)
{
    char buf[16];
    char buf2[16];
    Stamp st;
    short sh;
    int h;
    int i;
    int cnt = 0;
    int now = GetCurrentTimeMs();

    if (s->x74 != 0 && (unsigned int)(now - s->x74) > 2000) {
        for (i = 0; i < s->n && s->ents[i].state != 0; i++)
            ;
        if (i < s->n) {
            AudioSetConnection(s->h, &s->ents[i], 1, s->x80);
            GridSetPackHeader(s, buf, 8, 0);
            SendPackage(s->h, s->x80, buf, 0, 0);
        }
        s->x74 = 0;
        memset(s->x78, 0, 0xC);
    }
    for (i = 0; i < s->n; i++) {
        Ent_002EDEE8 *e = &s->ents[i];
        if (e->state == 2) {
            if (now - e->time >= 1500) {
                if (e->retries++ < 16) {
                    {
                    int h2 = s->h;
                    e->time = now;
                    sh = GetCurChannel(h2);
                    }
                    GridSetPackHeader(s, buf2, 1, 2);
                    SendPackage(s->h, e->a, buf2, &sh, 2);
                } else {
                    InvalidateConnection(e);
                    continue;
                }
            }
            cnt++;
        }
    }
    if (s->xC > 0) {
        if (cnt > 0) {
            SetAudioStatus(s->h, 4);
            if (cnt < s->n && s->x58 != 0 && now - s->x70 > 6000) {
                GridInviteConnect(s);
                s->x70 = now;
            }
            if ((unsigned int)(now - s->x6C) > 1500) {
                h = 0xFFFF;
                st.a = 0;
                st.t = now;
                GetLocalID(s->h, &h);
                GridSetPackHeader(s, buf2, 3, 8);
                GridSendPackage(s, h, buf2, &st, 8);
                s->x6C = now;
            }
        } else {
            ResetAudioStatus(s->h, 4);
            if (now - s->x70 > 3000) {
                JoinChannel(s->h, s->xC);
                s->x70 = now;
            }
        }
    }
    return 0;
}
#undef GridSetPackHeader /* merge_units */
#undef GetLocalID /* merge_units */
#undef GridSendPackage /* merge_units */
/* merge_units: end func_002EDEE8 */

/* merge_units: begin func_002EE1E0 */
typedef struct {
    int a;
    int b;
    int state;
    int time;
    unsigned int retries;
} Ent_002EE1E0;

typedef struct {
    char p0[8];
    int h;
    int xC;
    char p10[0x40];
    char x50[8];
    int x58;
    int n;
    Ent_002EE1E0 *ents;
} Conn_002EE1E0;

typedef struct {
    unsigned char b0;
    char p1[3];
    unsigned short port;
} Key;

typedef struct {
    char p0[0x34];
    int x34;
} Peer;

typedef struct {
    char p0[0xC];
    int arr[4];
} Grp;

typedef struct {
    char p0[0x1C];
    int x1C;
    char p20[0x18];
    int x38;
    char p3C[0x80C];
    int x848;
} Chan;
#if 0 /* merge_units */
extern void GetPlayerCountInSet(void *);
#endif /* merge_units */
#define GetPlayerCountInSet(a0) ((void)GetPlayerCountInSet((char *)(a0))) /* merge_units */

extern Grp *GetRefFromSet(void *, int);
#if 0 /* merge_units */
extern void AudioSendToPlayer(int, char *, int, int);
#endif /* merge_units */
#define AudioSendToPlayer(a0, a1, a2, a3) ((void)AudioSendToPlayer((a0), (a1), (a2), (char *)(a3))) /* merge_units */

extern Chan *GetPlayerByID(int, int);
extern int GetResourceManager(int);
extern int RequestSequencer(int);
extern int GetPlayerStatus(Chan *);
extern void ResetPlayerStatus(Chan *, int);
extern void SetPlayerStatus(Chan *, int);
extern void AddSequence(int, int, int, char *, int);

int GridProcessAudioPack(Conn_002EE1E0 *s, Key *key, Peer *p, char *buf, int len)
{
    int hdr;
    int type;
    int flag;
    Grp *g;
    Chan *c;
    int i;
    int now = GetCurrentTimeMs();

    switch (key->b0) {
    case 0x20: type = 0x21; break;
    case 0x21: type = 0x22; break;
    case 0x22: type = 0x23; break;
    case 0x23: type = 0x24; break;
    case 0x2F: type = 0x3F; break;
    default: return -1;
    }
    flag = 0;
    if (s->x58 != 0) {
        GetPlayerCountInSet(s->x50);
        flag = 1;
    }
    g = 0;
    if (flag)
        g = GetRefFromSet(s->x50, key->port);
    for (i = 0; i < s->n; i++) {
        Ent_002EE1E0 *e = &s->ents[i];
        if (e->state != 2) continue;
        if (e->a == p->x34) {
            e->time = now;
            e->retries = 0;
            continue;
        }
        if (e->a == key->port) continue;
        if (!flag) continue;
        if (g) {
            int j;
            for (j = 3; j >= 0; j--)
                if (g->arr[j] == e->a) break;
            if (j >= 0) continue;
        }
        AudioSendToPlayer(s->h, buf, len, e->b);
    }
    c = GetPlayerByID(s->h, key->port);
    if (c == 0 || (c->x38 & 2)) return 0;
    buf += 8;
    len -= 12;
    memcpy(&hdr, buf, 4);
    buf += 4;
    if (c->x848 == 0) {
        c->x848 = RequestSequencer(GetResourceManager(s->h));
        if (c->x848 == 0) return 0;
    }
    {
    int f = GetPlayerStatus(c) & 0x4000;
    if (len != 0) {
        c->x1C = now;
        if (!f) {
            ResetPlayerStatus(c, 0x1000);
            SetPlayerStatus(c, 0x4000);
        }
    } else {
        c->x1C = 0;
        ResetPlayerStatus(c, 0x4000);
    }
    }
    SetPlayerStatus(c, 0x2000);
    AddSequence(c->x848, type, hdr, buf, len);
    return 0;
}
#undef GetPlayerCountInSet /* merge_units */
#undef AudioSendToPlayer /* merge_units */
/* merge_units: end func_002EE1E0 */
