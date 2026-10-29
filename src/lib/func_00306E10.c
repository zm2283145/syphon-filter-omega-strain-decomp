typedef struct Cfg {
    unsigned short f0; short pad2;
    void *f4; int f8; int fC; int f10; int f14; int f18; int f1C; void *f20; void *f24;
} Cfg;

typedef struct Slot { char b[0x90]; } Slot;
typedef struct Obj {
    int f0; void *f4; int f8; char fC[0x20];
    int f2C; int f30; int f34; int f38; int f3C; int f40;
    short pad44; unsigned short f46; struct A48 *f48; struct A4C *f4C; struct A50 *f50;
} Obj;

extern int rt_memory_allocate_init_zero(void *pp, unsigned long size);
extern int rt_list_buf_create(void *p, int n);
extern int rt_udp_create_shared_channel_data(Obj *o);
extern void rt_udp_destroy(Obj *o);

int rt_udp_create(Obj **out, Cfg *cfg)
{
    Obj *o = 0;
    int ret;

    if (out == 0) return 1;
    *out = 0;
    if (cfg == 0) return 1;
    if (cfg->f20 == 0) return 1;
    while (rt_memory_allocate_init_zero(&o, 0x54) == 0) {
        o->f2C = cfg->f8;
        o->f30 = cfg->f10;
        o->f34 = cfg->f14;
        o->f38 = cfg->fC;
        o->f3C = cfg->f18;
        o->f40 = cfg->f1C;
        o->f48 = (void *)cfg->f4;
        o->f46 = cfg->f0;
        o->f4C = (void *)cfg->f20;
        o->f50 = (void *)cfg->f24;
        if (o->f2C == 0) o->f2C = 1;
        if (o->f30 == 0) o->f30 = 0x1000;
        if (o->f34 == 0) o->f34 = 0x1000;
        if (o->f38 == 0) o->f38 = 0x59E;
        if (o->f3C == 0) o->f3C = 0x1E;
        if (rt_memory_allocate_init_zero(&o->f4, o->f2C * sizeof(Slot)) != 0) { ret = 9; goto fail; }
        if (rt_list_buf_create(o->fC, o->f34) != 0) { ret = 10; goto fail; }
        ret = rt_udp_create_shared_channel_data(o);
        if (ret != 0) goto fail;
        *out = o;
        return 0;
    }
    ret = 9;
fail:
    rt_udp_destroy(o);
    return ret;
}





