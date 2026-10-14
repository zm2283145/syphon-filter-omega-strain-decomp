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

extern void func_002ED640(int, Ent *, int, int);
extern short func_002DA910(int);
extern void func_002DA900(int, int *);
extern void func_002F3308(void *, Msg *);
int __attribute__((weak, section(".dtors_drop"))) func_002EDD88(void *s) { return 0; }

void func_002EF748(Conn *s, Msg *m)
{
    int h = 0xFFFF;
    int i;
    int id;
    Ent *e;

    if (s == 0) return;
    func_002DA900(s->h, &h);
    func_002F3308((char *)s + 0x50, m);
    if (s->xC > 0 && m->id != h && s->xC == func_002DA910(s->h) && s->x58 == 0) {
        id = m->id;
        for (i = 0, e = s->ents; i < s->n; i++, e++) {
            if (e->a == id) break;
            if (e->state == 0) break;
        }
        if (i >= s->n) {
            func_002EDD88(s);
            e = &s->ents[i];
        }
        func_002ED640(s->h, e, 2, id);
    }
}


