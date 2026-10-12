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
    char p10[0x48];
    int x58;
    int n;
    Ent *ents;
    char p64[8];
    int x6C;
    int x70;
    int x74;
    char x78[8];
    int x80;
} Conn;

typedef struct {
    int a;
    int t;
    int c, d;
} Stamp;

extern int func_002F5160(void);
extern void func_002ED640(int, Ent *, int, int);
extern void func_002EDD08(Conn *, char *, int, int);
extern void func_002D9A30(int, int, char *, void *, int);
extern void *memset(void *, int, unsigned int);
extern short func_002DA910(int);
extern void func_002ED620(Ent *);
extern void func_002D9EA0(int, int);
extern void func_002D9EB0(int, int);
extern void func_002EF488(Conn *);
extern void func_002DA900(int, int *);
extern void func_002ED940(Conn *, int, char *, void *, int);
extern void func_002DA3D8(int, int);

int func_002EDEE8(Conn *s)
{
    char buf[16];
    char buf2[16];
    Stamp st;
    short sh;
    int h;
    int i;
    int cnt = 0;
    int now = func_002F5160();

    if (s->x74 != 0 && (unsigned int)(now - s->x74) > 2000) {
        for (i = 0; i < s->n && s->ents[i].state != 0; i++)
            ;
        if (i < s->n) {
            func_002ED640(s->h, &s->ents[i], 1, s->x80);
            func_002EDD08(s, buf, 8, 0);
            func_002D9A30(s->h, s->x80, buf, 0, 0);
        }
        s->x74 = 0;
        memset(s->x78, 0, 0xC);
    }
    for (i = 0; i < s->n; i++) {
        Ent *e = &s->ents[i];
        if (e->state == 2) {
            if (now - e->time >= 1500) {
                if (e->retries++ < 16) {
                    {
                    int h2 = s->h;
                    e->time = now;
                    sh = func_002DA910(h2);
                    }
                    func_002EDD08(s, buf2, 1, 2);
                    func_002D9A30(s->h, e->a, buf2, &sh, 2);
                } else {
                    func_002ED620(e);
                    continue;
                }
            }
            cnt++;
        }
    }
    if (s->xC > 0) {
        if (cnt > 0) {
            func_002D9EA0(s->h, 4);
            if (cnt < s->n && s->x58 != 0 && now - s->x70 > 6000) {
                func_002EF488(s);
                s->x70 = now;
            }
            if ((unsigned int)(now - s->x6C) > 1500) {
                h = 0xFFFF;
                st.a = 0;
                st.t = now;
                func_002DA900(s->h, &h);
                func_002EDD08(s, buf2, 3, 8);
                func_002ED940(s, h, buf2, &st, 8);
                s->x6C = now;
            }
        } else {
            func_002D9EB0(s->h, 4);
            if (now - s->x70 > 3000) {
                func_002DA3D8(s->h, s->xC);
                s->x70 = now;
            }
        }
    }
    return 0;
}


