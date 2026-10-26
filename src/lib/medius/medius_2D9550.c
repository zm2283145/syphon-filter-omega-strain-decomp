/*
 * lib/medius: 3 files, 002D9550-002D9A30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D9550 */
extern int GetGrid(char *, int);
extern char *GridGetNext(char *);
extern char *GridGetName(char *);
extern int strcmp(const char *, const char *);
extern void QuitChannel(char *, int);
extern char *AddGrid(char *, int, int);
extern void GridSetName(char *, const char *);
extern char *GetPlayerFromGroup(int, int);
extern void GridAddPlayer(char *, char *);
extern void GridSetChannelInfo(char *, unsigned short *);
extern void GridSetPackHeader(char *, char *, int, int);
extern void SetPlayerCurChannel(char *, int);
extern int GridSendPackage(char *, int, char *, unsigned short *, int);

int CreateChannel(char *s, int a1, int *id, const char *name)
{
    char buf[16];
    unsigned short info[0x28];
    char *n = *(char **)(s + 0x64);
    char *p, *c;
    if (id == 0 || name == 0 || *name == 0)
        return 1;
    for (*id = 1; GetGrid(s, *id); (*id)++)
        ;
    while ((n = GridGetNext(n)) != 0 && n != *(char **)(s + 0x64)) {
        if (strcmp(GridGetName(n), name) == 0)
            return 1;
    }
    if (*(int *)(s + 0x98) > 0) {
        QuitChannel(s, *(int *)(s + 0x98));
        *(int *)(s + 0x98) = 0;
    }
    n = AddGrid(s, *id, a1);
    GridSetName(n, name);
    c = GetPlayerFromGroup(*(int *)(s + 0x6C), *(int *)(s + 0x78));
    GridAddPlayer(n, c);
    GridSetChannelInfo(n, info);
    GridSetPackHeader(*(char **)(s + 0x64), buf, 6, 0x44);
    SetPlayerCurChannel(c, *(int *)(s + 0x98) = info[1]);
    return GridSendPackage(*(char **)(s + 0x64), *(int *)(s + 0x78), buf, info, 0x44);
}
/* merge_units: end func_002D9550 */

/* merge_units: begin func_002D96C8 */
typedef struct { char b[8]; } Raw;
typedef struct {
    unsigned char type;
    unsigned char id;
    unsigned short len;
    unsigned short w4;
    unsigned short w6;
} Hdr;
typedef struct Conn {
    int pad0;
    struct Conn *next;
    int pad8;
    int xC;
    int x10;
    int x14;
    int pad18[2];
    int x20;
    int x24;
    int x28;
    int x2C;
    int x30;
    int x34;
} Conn;
typedef struct {
    char pad0[0x6C];
    Conn *x6C;
    int pad70;
    int x74;
    int x78;
    char pad7C[0x98 - 0x7C];
    int x98;
} S;

extern void *memcpy(void *, const void *, unsigned int);
extern int GetCurrentTimeMs(void);
#if 0 /* merge_units */
extern Conn *GetPlayerFromGroup(Conn *, int);
#endif /* merge_units */
#define GetPlayerFromGroup(a0, a1) ((Conn *)GetPlayerFromGroup((int)(a0), (a1))) /* merge_units */

extern void AudioSendPingMessage(S *, int);
#if 0 /* merge_units */
extern void SetPlayerCurChannel(Conn *, int);
#endif /* merge_units */
#define SetPlayerCurChannel(a0, a1) (SetPlayerCurChannel((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void *GetGrid(S *, int);
#endif /* merge_units */
#define GetGrid(a0, a1) ((void *)GetGrid((char *)(a0), (a1))) /* merge_units */

extern int GetSetPreviousMessage(Conn *, Hdr *, int);
extern void SendRedundancyMessage(S *, int, int, int);
extern int GridProcessAudioPack(void *, Hdr *, Conn *, Hdr *, unsigned int);
extern int GridProcessVideoPack(void *, Hdr *, Conn *, Hdr *, unsigned int);
extern int GridProcessDataPack(void *, Hdr *, Conn *, Hdr *, unsigned int);

int ProcessPackage(S *o, int k1, int k2, Hdr *hp, unsigned int len)
{
    Hdr h;
    Conn *c, *head, *d;
    void *e;
    int now = GetCurrentTimeMs();
    int id34, r;
    if (len < 8)
        return -1;
    memcpy(&h, hp, 8);
    if (h.type & 0x80) {
        h.type &= 0x7F;
        memcpy(hp, &h, 8);
        c = GetPlayerFromGroup(o->x6C, h.w4);
        if (c != 0 && c->xC == 0) {
            if (c->x20 == k1) {
                c->x28 = k2;
                c->xC = 2;
            } else if (c->x24 == k1) {
                c->x2C = k2;
                c->xC = 1;
            } else {
                c = 0;
            }
        }
    } else {
        head = c = o->x6C;
        while (c) {
            if (c->x20 == k1 && c->x28 == k2) {
                if (c->xC == 0)
                    c->xC = 2;
                break;
            }
            if (c->x24 == k1 && c->x2C == k2) {
                if (c->xC == 0)
                    c->xC = 1;
                break;
            }
            c = c->next;
            if (c == head)
                c = 0;
        }
    }
    if (c == 0)
        return 0;
    c->x10 = now;
    c->x14 = 0;
    id34 = c->x34;
    d = GetPlayerFromGroup(o->x6C, h.w4);
    if (d == 0)
        return 0;
    switch (h.type) {
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x2F:
    case 0x30:
        if (h.len != len - 12)
            return -1;
        break;
    default:
        if (h.len != len - 8)
            return -1;
        break;
    }
    if (h.w4 == o->x78)
        return 0;
    if (h.id) {
        if (h.id != d->x30 || h.id != o->x98) {
            AudioSendPingMessage(o, d->x34);
            d->x10 = now;
            d->x14++;
            if (h.id != o->x98)
                return 0;
            SetPlayerCurChannel(d, h.id);
        }
    }
    e = GetGrid(o, h.id);
    if (e == 0)
        return 0;
    r = GetSetPreviousMessage(d, &h, id34);
    if (r != 0xFFFF && r != id34) {
        if (o->x74)
            SendRedundancyMessage(o, h.id, id34, h.w4);
        return 0;
    }
    if (h.id) {
        if ((unsigned char)(h.type - 0x20) < 4 || h.type == 0x2F)
            return GridProcessAudioPack(e, &h, c, hp, len);
        if (h.type == 0x30)
            return GridProcessVideoPack(e, &h, c, hp, len);
    }
    return GridProcessDataPack(e, &h, c, hp, len);
}
#undef GetPlayerFromGroup /* merge_units */
#undef SetPlayerCurChannel /* merge_units */
#undef GetGrid /* merge_units */
/* merge_units: end func_002D96C8 */

/* merge_units: begin func_002D9A30 */
typedef struct Hdr_002D9A30 {
    char b[8];
} Hdr_002D9A30;
typedef struct Conn_002D9A30 {
    char pad0[0xC];
    unsigned int state;
    char pad10[0x20 - 0x10];
    int h20;
    int h24;
    int cb28;
    int cb2C;
} Conn_002D9A30;
typedef struct Obj {
    char pad0[0x6C];
    int list;
} Obj;
#if 0 /* merge_units */
extern Conn_002D9A30 *GetPlayerFromGroup(int, int);
#endif /* merge_units */
#define GetPlayerFromGroup(a0, a1) ((Conn_002D9A30 *)GetPlayerFromGroup((a0), (a1))) /* merge_units */

extern int AudioSendTo(Obj *, char *, int, int, int);
int SendPackage(Obj *o, int id, Hdr_002D9A30 *hdr, void *data, unsigned int len)
{
    char buf[0x500];
    int ret = 0;
    Conn_002D9A30 *c = GetPlayerFromGroup(o->list, id);
    int n;
    if (len + 8 > 0x500)
        return -1;
    if (c == 0)
        return -1;
    n = 8;
    *(Hdr_002D9A30 *)buf = *hdr;
    memcpy(buf + n, data, len);
    n = len + n;
    if (c->h24 != 0 && c->state < 2) {
        if (c->cb2C == 0)
            return -1;
        ret = -1;
        if (n == AudioSendTo(o, buf, n, c->h24, c->cb2C))
            ret = 0;
    }
    if (c->h20 != 0) {
        if (c->state == 2 || c->state == 0) {
            if (c->cb28 == 0)
                return -1;
            if (n != AudioSendTo(o, buf, n, c->h20, c->cb28))
                ret = -1;
        }
    }
    return ret;
}
#undef GetPlayerFromGroup /* merge_units */
/* merge_units: end func_002D9A30 */
