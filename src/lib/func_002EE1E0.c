typedef struct {
    int a;
    int b;
    int state;
    int time;
    unsigned int retries;
} Ent;

typedef struct {
    char p0[8];
    int h;
    int xC;
    char p10[0x40];
    char x50[8];
    int x58;
    int n;
    Ent *ents;
} Conn;

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

extern int func_002F5160(void);
extern void func_002F33D8(void *);
extern Grp *func_002F3388(void *, int);
extern void func_002D9C10(int, char *, int, int);
extern Chan *func_002D9E88(int, int);
extern int func_002D8AD8(int);
extern int func_002F4030(int);
extern int func_002F3220(Chan *);
extern void func_002F3238(Chan *, int);
extern void func_002F3228(Chan *, int);
extern void func_003136D0(int, int, int, char *, int);
extern void *memcpy(void *, const void *, unsigned int);

int func_002EE1E0(Conn *s, Key *key, Peer *p, char *buf, int len)
{
    int hdr;
    int type;
    int flag;
    Grp *g;
    Chan *c;
    int i;
    int now = func_002F5160();

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
        func_002F33D8(s->x50);
        flag = 1;
    }
    g = 0;
    if (flag)
        g = func_002F3388(s->x50, key->port);
    for (i = 0; i < s->n; i++) {
        Ent *e = &s->ents[i];
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
        func_002D9C10(s->h, buf, len, e->b);
    }
    c = func_002D9E88(s->h, key->port);
    if (c == 0 || (c->x38 & 2)) return 0;
    buf += 8;
    len -= 12;
    memcpy(&hdr, buf, 4);
    buf += 4;
    if (c->x848 == 0) {
        c->x848 = func_002F4030(func_002D8AD8(s->h));
        if (c->x848 == 0) return 0;
    }
    {
    int f = func_002F3220(c) & 0x4000;
    if (len != 0) {
        c->x1C = now;
        if (!f) {
            func_002F3238(c, 0x1000);
            func_002F3228(c, 0x4000);
        }
    } else {
        c->x1C = 0;
        func_002F3238(c, 0x4000);
    }
    }
    func_002F3228(c, 0x2000);
    func_003136D0(c->x848, type, hdr, buf, len);
    return 0;
}



