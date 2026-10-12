typedef struct {
    char pad0[0x14];
    int state;
    int f18;
    int f1C;
    int pad20;
    int f24;
    unsigned char active;
} Player;

typedef struct {
    Player *pl[256];
    unsigned int host;
    char pad404[0x3C];
    int f440;
} Tbl;

typedef struct {
    char pad0[6];
    short f6;
    char pad8[2];
    short fA;
} Rec;

typedef struct {
    int type;
    int data;
    int pad[2];
} Ev;

extern char D_0048C454;
extern int D_0048C478;
extern void (*D_0058DF88)(Ev *);
extern int D_0058DF90;

extern int func_002E51B8(unsigned int a, Tbl **out);
extern int func_002E52D8(unsigned int a, unsigned int b, Player **out);
extern int func_002DB188(Rec **out, unsigned int a, unsigned int b);
extern void func_002DCA70(unsigned int a, int b);
extern void func_002E5550(unsigned int a, unsigned int b);
extern void func_002DB688(unsigned int a, unsigned int b);
extern void func_002E1470(unsigned int a, int b);
extern void func_002E8C50(unsigned int a, unsigned int b, int c, int d);

void func_002E8730(unsigned int a)
{
    Ev ev;
    Tbl *tbl;
    Player *pl;
    Rec *rec;
    unsigned int host = 0x100;
    int cnt = 0;
    unsigned int i;

    tbl = 0;
    pl = 0;
    if (a >= 4) return;
    if (func_002E51B8(a, &tbl) != 0) return;
    if (tbl == 0) return;
    if (tbl->f440 != 0) return;
    if (D_0058DF90 != 1 && D_0058DF90 != 2) return;
    for (i = 0; i < 256; i++) {
        if (func_002E52D8(a, i, &pl) != 0) return;
        if (pl != 0 && pl->active == 1) {
            if (pl->state == 0 || pl->state == 5) return;
            if (pl->state == 3 && host == 0x100) host = i;
            if (pl->state == 4) cnt++;
        }
    }
    if (cnt != 0) return;
    if (host != tbl->host) return;
    func_002DB188(&rec, a, host);
    if (rec == 0) {
        tbl->pl[host]->state = 2;
        func_002DCA70(a, -1);
        if (D_0058DF88 != 0) {
            ev.type = 0x16;
            ev.data = D_0048C478;
            D_0058DF88(&ev);
            D_0058DF88 = 0;
            D_0048C478 = 0;
            return;
        }
    }
    tbl->pl[host]->state = 5;
    tbl->pl[host]->f24 = 1;
    func_002E5550(a, host);
    func_002DCA70(a, -1);
    rec->f6 = 0;
    rec->fA = 0;
    D_0048C454 = 1;
    func_002DB688(a, host);
    func_002E1470(a, 1);
    if (D_0058DF88 != 0) {
        ev.type = 0;
        ev.data = D_0048C478;
        D_0058DF88(&ev);
        D_0058DF88 = 0;
        D_0048C478 = 0;
    }
    for (i = 0; i < 256; i++) {
        if (func_002E52D8(a, i, &pl) == 0 && pl != 0 && pl->active == 1 && pl->state == 3 && host != i)
            func_002E8C50(a, i, pl->f18, pl->f1C);
    }
}



