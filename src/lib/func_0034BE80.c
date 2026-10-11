typedef struct { int type; int f4; int id; int mode; } NetIf_E80;
typedef struct { int f0; int f4; int f8[6]; int f20; } NetCfg_E80;
extern int Net_AllocZeroed(NetIf_E80 **pp, int size);
extern int func_0034CF80(NetIf_E80 *o);
extern int func_002FB3C0(NetIf_E80 **pp);
extern int func_0034ACC8(void *cd, int *buf, void *src);
extern int func_0034D028(NetIf_E80 *o);
int func_0034BE80(void *cd, int *buf, NetIf_E80 **out, NetCfg_E80 *cfg)
{
    NetIf_E80 *o;
    int r;
    if (out == 0 || cfg == 0) return -0x200;
    *out = 0;
    o = 0;
    if (Net_AllocZeroed(&o, 0x28) != 0 || o == 0) return -0x1F5;
    o->type = cfg->f8[0];
    o->f4 = cfg->f20;
    if (o->type == 0) o->mode = cfg->f0;
    else if (o->type == 3) o->mode = 4;
    else o->mode = 0;
    if (func_0034CF80(o) != 0) {
        func_002FB3C0(&o);
        return -0x1F5;
    }
    r = func_0034ACC8(cd, buf, cfg->f8);
    if (r < 0) {
        func_0034D028(o);
        func_002FB3C0(&o);
        return r;
    }
    o->id = r;
    *out = o;
    return 0;
}