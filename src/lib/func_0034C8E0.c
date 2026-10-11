typedef struct NetIf_8E0 { int err; int f4; int f8; int state; char pad[0x10]; struct NetIf_8E0 *f20; struct NetIf_8E0 *f24; } NetIf_8E0;
extern void func_0010D3E0(int a);
extern int func_0034C9A0(NetIf_8E0 *a, NetIf_8E0 *b, int n);
int func_0034C8E0(NetIf_8E0 *o, int *out)
{
    NetIf_8E0 *c;
    NetIf_8E0 *d;
    int s;
    if (o == 0 || out == 0) return -0x200;
    c = o->f24;
    *out = 0;
    func_0010D3E0(0);
    if (c->state == 0) {
        *out = 1;
    } else if (c->state == 3) {
        return c->err ? c->err : -0x1F5;
    }
    if (o->f24->state != o->f20->state) {
        d = o->f20;
        d->state = o->f24->state;
        if (func_0034C9A0(d, d->f20, 16) != 0) return -0x1F5;
    }
    return 0;
}