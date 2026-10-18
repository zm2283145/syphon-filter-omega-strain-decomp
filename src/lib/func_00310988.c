typedef struct { char *ctx; int type; char pad8[0x208]; void *data; char pad214[0]; } P310988;
extern int Net_AllocZeroed(void **pp, unsigned long size);
extern int func_00310D40(char **out, int flags, unsigned int size);
extern int func_00311018(char *ctx, int v);
extern int func_00311070(char *ctx, int v);
extern int func_003110C8(char *ctx, int v);
extern int func_00311120(char *ctx, unsigned char flag, int value);
extern int func_00310C30(P310988 *p);
extern void func_0030F150(void);
extern void func_0030F298(void);
extern void func_0030F310(void);
extern void func_0030FBA0(void);
extern void func_0030FD30(void);
extern void func_0030FD80(void);
extern void func_00310238(void);
extern void func_003104A8(void);
extern void func_003104F8(void);
extern void func_00310598(void);
extern void func_00310820(void);
extern void func_00310898(void);
int func_00310988(P310988 **out, int type, unsigned int size)
{
    P310988 *p = 0;
    int r = 0;
    int e;
    if (out)
        goto init;
    return 5;
body:
    p->type = type;
    func_00311018(p->ctx, (int)p);
    switch (type) {
    case 0:
        if (Net_AllocZeroed(&p->data, 4868)) {
            r = 3;
            break;
        }
        func_00311070(p->ctx, (int)func_0030F150);
        func_003110C8(p->ctx, (int)func_0030F298);
        func_00311120(p->ctx, 0, (int)func_0030F310);
        break;
    case 8:
        if (Net_AllocZeroed(&p->data, 4)) {
            r = 3;
            break;
        }
        func_00311070(p->ctx, (int)func_0030FBA0);
        func_003110C8(p->ctx, (int)func_0030FD30);
        func_00311120(p->ctx, 0, (int)func_0030FD80);
        break;
    case 7:
        if (Net_AllocZeroed(&p->data, 4)) {
            r = 3;
            break;
        }
        func_00311070(p->ctx, (int)func_0030FBA0);
        func_003110C8(p->ctx, (int)func_0030FD30);
        func_00311120(p->ctx, 0, (int)func_0030FD80);
        break;
    case 10:
        if (Net_AllocZeroed(&p->data, 256)) {
            r = 3;
            break;
        }
        func_00311070(p->ctx, (int)func_00310238);
        func_003110C8(p->ctx, (int)func_003104A8);
        func_00311120(p->ctx, 0, (int)func_003104F8);
        break;
    case 11:
        if (Net_AllocZeroed(&p->data, 6148)) {
            r = 3;
            break;
        }
        func_00311070(p->ctx, (int)func_00310598);
        func_003110C8(p->ctx, (int)func_00310820);
        func_00311120(p->ctx, 0, (int)func_00310898);
        break;
    default:
        r = 6;
        break;
    }
    if (r)
        goto fail;
    *out = p;
    return 0;
init:
    if (!Net_AllocZeroed((void **)&p, 532)) {
        e = func_00310D40(&p->ctx, 0, size);
        if (!p->ctx) {
            r = 3;
            goto fail;
        }
        if (!e)
            goto body;
        r = 3;
        goto fail;
    }
    r = 3;
fail:
    func_00310C30(p);
    return r;
}
