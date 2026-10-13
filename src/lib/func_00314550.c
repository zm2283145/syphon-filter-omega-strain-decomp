typedef struct {
    int x00;
    int x04;
    unsigned int count;
    int x0C;
    int x10;
    int x14;
    int x18;
    int x1C;
    int x20;
    int x24;
    int x28;
    int x2C;
    int x30;
    void *x34;
    int x38;
    int x3C;
    int x40;
    int x44;
    int x48;
    int x4C;
    int x50;
} Cfg;

typedef struct {
    int port;
    int x04;
    int x08;
    int x0C;
    int x10;
    int x14;
    int x18;
    int x1C;
    int x20;
    int x24;
    int x28;
    int x2C;
    void *x30;
    void *x34;
    void *x38;
    void *x3C;
} Prm;

typedef struct {
    int id;
    unsigned char a;
    unsigned char b;
    unsigned char c;
} Ent;

typedef struct {
    int slot;
    int count;
    unsigned char state;
    unsigned char ready;
    unsigned char xA;
    int xC;
    Cfg cfg;
    Prm prm;
    int handle;
    unsigned char xA8;
    unsigned char xA9;
    int xAC[8];
    int xCC[12];
    int subs[0x40];
    unsigned char x1FC;
    int x200;
    Ent *ents;
} Obj;

typedef struct {
    int type;
    char x04[0x10];
    int x14;
} Info;

extern short D_00491432;
extern unsigned char D_00491430;
extern unsigned short D_0058C0B0;
extern int D_0048C460;
extern char D_004B34A0[];

int func_00314D50(int, int);
int func_00314F58(int, Obj **);
int func_00315E28(int, int);
int func_002F4EE0(int *, Prm *);
int func_00315730(int, int *);
int func_002F4F48(int, int, int *, char *);
int func_002F5038(int, int);
int func_002E60A0(Info **);
int func_002F4F30(int, char *, int, void *);
int func_002F4F90(int, int *);
int func_002F4FB0(int, int, void *);
int func_00315260(void *, void *);
int func_00315A28();
int func_00315AE8();
int func_00315BB0();
int func_00315C60();
int func_00315CF8();
void *memset(void *, int, unsigned int);
int sprintf(char *, const char *, ...);

int func_00314550(int slot, int unused, Cfg *cfg)
{
    char name[0x40];
    Obj *obj;
    int h;
    int sub;
    Info *info;
    int x;
    int ret;
    unsigned int i;
    int f;
    int j;

    info = 0;
    sub = 0;
    ret = 0x11;
    if (D_00491432 <= 0) return ret;
    if (D_00491430 != 1) return ret;
    ret = 0x17;
    if (cfg == 0) return ret;
    if (cfg->count > 0x40) return ret;
    ret = func_00314D50(slot, unused);
    if (ret != 0) return ret;
    ret = func_00314F58(slot, &obj);
    if (ret != 0) return ret;
    ret = 0x29;
    if (obj == 0) return ret;
    if (obj->state != 0) return ret;
    obj->handle = 0;
    obj->slot = slot;
    obj->xA = 0;
    obj->xC = 0x100;
    obj->cfg = *cfg;
    obj->xA8 = 0;
    obj->xA9 = 0;
    obj->x1FC = 0;
    obj->ready = 0;
    memset(&obj->prm, 0, sizeof(Prm));
    obj->prm.x28 = obj->cfg.x0C;
    obj->prm.port = D_0058C0B0;
    obj->prm.x04 = obj->cfg.x14;
    obj->prm.x10 = obj->cfg.x20;
    obj->prm.x08 = obj->cfg.x18;
    obj->prm.x14 = obj->cfg.x24;
    obj->prm.x0C = obj->cfg.x1C;
    obj->prm.x18 = obj->cfg.x28;
    obj->prm.x1C = obj->cfg.x3C;
    obj->prm.x20 = obj->cfg.x40;
    obj->prm.x2C = D_0048C460;
    if (cfg->x34 != 0 || cfg->x2C != 0) {
        obj->prm.x30 = func_00315A28;
        obj->prm.x34 = func_00315AE8;
    } else {
        obj->prm.x30 = 0;
        obj->prm.x34 = 0;
    }
    if (cfg->x44 != 0) {
        obj->prm.x38 = func_00315BB0;
    } else {
        obj->prm.x38 = 0;
    }
    if (cfg->x4C != 0) {
        obj->prm.x3C = func_00315C60;
    } else {
        obj->prm.x3C = 0;
    }
    ret = 0x29;
    if (obj->ents == 0) return ret;
    for (j = 0; j < obj->count; j++) {
        obj->ents[j].id = j;
        obj->ents[j].a = 0;
        obj->ents[j].b = 0;
        obj->ents[j].c = 0;
    }
    ret = func_00315E28(func_002F4EE0(&obj->handle, &obj->prm), 0x2A);
    if (ret != 0) return ret;
    ret = func_00315730(obj->cfg.x10, &h);
    if (ret != 0) return ret;
    i = 0;
    if (obj->cfg.count != 0) {
        do {
            sprintf(name, D_004B34A0, i);
            ret = func_00315E28(func_002F4F48(obj->handle, h, &sub, name), 0x2A);
            if (ret != 0) return ret;
            obj->subs[i] = sub;
            i++;
        } while (i < obj->cfg.count);
    }
    if (i != 0) {
        ret = func_00315E28(func_002F5038(obj->handle, sub), 0x2A);
        if (ret != 0) return ret;
    }
    obj->state = 1;
    ret = func_002E60A0(&info);
    if (ret != 0) return ret;
    if (info == 0) return 0xA;
    if (info->type == 3) {
        obj->xA8 = 0;
        ret = func_00315E28(func_002F4F30(obj->handle, info->x04, info->x14, func_00315CF8), 0x2A);
        if (ret != 0) return ret;
    } else {
        obj->xA9 = 1;
    }
    ret = func_00315E28(func_002F4F90(obj->handle, &x), 0x2A);
    if (ret != 0) return ret;
    ret = func_00315E28(func_002F4FB0(obj->handle, x, &obj->xAC), 0x2A);
    if (ret != 0) return ret;
    ret = func_00315260(&obj->xAC, &obj->xCC);
    if (ret != 0) return ret;
    obj->ready = 1;
    return ret;
}
