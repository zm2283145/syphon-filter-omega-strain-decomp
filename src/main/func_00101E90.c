/* MW C++ runtime exception action iterator: skip the current action, return next action kind (cf. func_00101640) */
#pragma opt_propagation off
typedef struct ThrowCtx {
    int x0;
    int x4;
    void *x8;
    char padC[0x18 - 0xC];
    char *x18;
    char pad1C[0x20 - 0x1C];
    __int128 regs[32];
} ThrowCtx;

typedef struct ActionInfo {
    int x0;
    int x4;
    unsigned char *p;
    char padC[0x20 - 0xC];
    ThrowCtx ctx;
} ActionInfo;

extern unsigned char *func_00100BC0(unsigned char *p, unsigned int *out);
extern unsigned char *func_00100C70(unsigned char *p, int *out);
extern void func_00100AB0(void);
extern void *func_001025D0(ThrowCtx *ctx, ActionInfo *info);
extern void func_001021E0(void *x, ActionInfo *info);
extern void func_00102510(ThrowCtx *ctx, ActionInfo *info);

static inline int IsNull(unsigned char *p) { return !p; }
#define RD32(q) ((((q)[0] | ((q)[1] << 8)) | ((q)[2] << 16)) | ((q)[3] << 24))

int func_00101E90(ActionInfo *info)
{
    ThrowCtx *ctx = &info->ctx;
    unsigned char *p;
    unsigned char *q;

    for (;;) {
        p = info->p;
        if (IsNull(p) || (p[0] & 0x80)) {
            func_001021E0(func_001025D0(ctx, info), info);
            if (info->x4 == 0)
                func_00100AB0();
            func_00102510(ctx, info);
            if (info->p == 0)
                continue;
        } else {
            switch (p[0] & 0x1F) {
            case 2: {
                int off;
                q = func_00100C70(p + 1, &off);
                info->p = q + 4;
                break;
            }
            case 3: {
                int off1, off2;
                q = func_00100C70(func_00100C70(p + 1, &off1), &off2);
                info->p = q + 4;
                break;
            }
            case 4: {
                int off;
                q = func_00100C70(p + 1, &off);
                info->p = q + 4;
                break;
            }
            case 5: {
                int off;
                unsigned int n, size;
                q = func_00100BC0(func_00100BC0(func_00100C70(p + 1, &off), &n), &size);
                info->p = q + 4;
                break;
            }
            case 6: {
                int off1, off2;
                q = func_00100C70(func_00100C70(p + 1, &off1), &off2);
                info->p = q + 4;
                break;
            }
            case 7: {
                int off1, off2;
                q = func_00100C70(func_00100C70(p + 1, &off1), &off2);
                info->p = q + 4;
                break;
            }
            case 8: {
                int off1, off2, off3;
                q = func_00100C70(func_00100C70(func_00100C70(p + 1, &off1), &off2), &off3);
                info->p = q + 4;
                break;
            }
            case 9: {
                int off1, off2;
                unsigned int n, size;
                q = func_00100BC0(func_00100BC0(func_00100C70(func_00100C70(p + 1, &off1), &off2), &n), &size);
                info->p = q + 4;
                break;
            }
            case 10: {
                int off;
                q = func_00100C70(p + 1, &off);
                info->p = q + 4;
                break;
            }
            case 11: {
                int off1, off2;
                q = func_00100C70(func_00100C70(p + 1, &off1), &off2);
                info->p = q + 4;
                break;
            }
            case 12: {
                volatile int x;
                unsigned int a;
                int c;
                { unsigned char *r = p + 1; x = RD32(r); }
                info->p = func_00100C70(func_00100BC0(p + 5, &a), &c);
                break;
            }
            case 13: {
                int off;
                info->p = func_00100C70(p + 1, &off);
                break;
            }
            case 15: {
                unsigned int a, bb;
                int c;
                info->p = func_00100C70(func_00100BC0(func_00100BC0(p + 1, &a), &bb), &c) + a * 4;
                break;
            }
            default:
                func_00100AB0();
                break;
            }
        }
        break;
    }
    {
        int off;
        int k;
        while ((k = ((p = info->p)[0] & 0x1F)) == 1) {
            func_00100C70(p + 1, &off);
            info->p += off;
        }
        return k;
    }
}
