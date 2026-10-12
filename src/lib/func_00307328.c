typedef struct {
    char name[16];
    unsigned short port;
} Req7328;

typedef struct {
    int sock;
    int pad4;
    void *upnp;
    char padC[0x34];
    int arg40;
    unsigned char pad44;
    unsigned char active;
    unsigned short port;
    unsigned int mode;
} Obj7328;

extern void *D_00491320;
extern unsigned char D_00491324;
extern int func_0030DE00(void **out, int sock, unsigned short port);
extern int func_0030EFB0(void *obj, int value);
extern int func_0030EBF0(void *u, const char *name, unsigned short port, void *cb, Obj7328 *user);
extern void func_0030B338(void);

int func_00307328(Obj7328 *o, Req7328 *r)
{
    if (o == 0) return 2;
    if (r == 0) return 1;
    if (o->active != 0) return 15;
    if (o->mode < 8) {
        if (D_00491320 == 0) {
            if (func_0030DE00(&D_00491320, o->sock, o->port) != 0) return 15;
            if (func_0030EFB0(D_00491320, o->arg40) != 0) return 15;
        }
        o->upnp = D_00491320;
        if (D_00491324 == 0) {
            if (func_0030EBF0(D_00491320, r->name, r->port, func_0030B338, o) != 0) return 15;
            o->active = 1;
            D_00491324 = 1;
            goto done;
        }
    } else {
        if (o->upnp == 0) {
            if (func_0030DE00(&o->upnp, o->sock, o->port) != 0) return 15;
            if (func_0030EFB0(o->upnp, o->arg40) != 0) return 15;
        }
        if (func_0030EBF0(o->upnp, r->name, r->port, func_0030B338, o) != 0) return 15;
    }
    o->active = 1;
done:
    return 0;
}
