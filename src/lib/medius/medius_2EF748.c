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
} Conn;

typedef struct {
    char p0[0x34];
    int id;
} Msg;

extern void AudioSetConnection(int, Ent *, int, int);
extern short GetCurChannel(int);
extern void GetLocalID(int, int *);
extern void AddRefToSet(void *, Msg *);
int __attribute__((weak, section(".dtors_drop"))) GridExpandConnections(void *s) { return 0; }

void GridAddPlayer(Conn *s, Msg *m)
{
    int h = 0xFFFF;
    int i;
    int id;
    Ent *e;

    if (s == 0) return;
    GetLocalID(s->h, &h);
    AddRefToSet((char *)s + 0x50, m);
    if (s->xC > 0 && m->id != h && s->xC == GetCurChannel(s->h) && s->x58 == 0) {
        id = m->id;
        for (i = 0, e = s->ents; i < s->n; i++, e++) {
            if (e->a == id) break;
            if (e->state == 0) break;
        }
        if (i >= s->n) {
            GridExpandConnections(s);
            e = &s->ents[i];
        }
        AudioSetConnection(s->h, e, 2, id);
    }
}


