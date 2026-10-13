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
} ActionInfo;

typedef void (*DtorFn)(void *, int);
typedef void (*DelFn)(void *);

extern unsigned char *func_00100BC0(unsigned char *p, unsigned int *out);
extern unsigned char *func_00100C70(unsigned char *p, int *out);
extern void func_00100AB0(void);
extern void *func_001025D0(ThrowCtx *ctx, ActionInfo *info);
extern void func_001021E0(void *x, ActionInfo *info);
extern void func_00102510(ThrowCtx *ctx, ActionInfo *info);

#define RD32(q) ((((q)[0] | ((q)[1] << 8)) | ((q)[2] << 16)) | ((q)[3] << 24))

void func_00101640(ThrowCtx *ctx, ActionInfo *info, unsigned char *catcher)
{
    unsigned char *p;
    unsigned char b;

    for (;;) {
        p = info->p;
        if (p == 0) {
            func_001021E0(func_001025D0(ctx, info), info);
            if (info->x4 == 0)
                func_00100AB0();
            func_00102510(ctx, info);
            p = info->p;
            if (p == 0)
                continue;
        }
        b = p[0];
        switch (b & 0x1F) {
        case 1: {
            int off;
            func_00100C70(p + 1, &off);
            info->p += off;
            break;
        }
        case 2: {
            int off;
            unsigned char *q = func_00100C70(p + 1, &off);
            ((DtorFn)RD32(q))(ctx->x18 + off, -1);
            info->p = q + 4;
            break;
        }
        case 3: {
            int isreg = b & 0x40;
            int off1, off2;
            unsigned char *q, *next;
            DtorFn fn;
            signed char cond;
            q = func_00100C70(p + 1, &off1);
            q = func_00100C70(q, &off2);
            fn = (DtorFn)RD32(q);
            next = q + 4;
            if (isreg)
                cond = (signed char)ctx->regs[off1];
            else
                cond = *(signed char *)(ctx->x18 + off1);
            if (cond)
                fn(ctx->x18 + off2, -1);
            info->p = next;
            break;
        }
        case 4: {
            int isreg = b & 0x20;
            int off;
            unsigned char *q, *next;
            DtorFn fn;
            void *obj;
            q = func_00100C70(p + 1, &off);
            fn = (DtorFn)RD32(q);
            next = q + 4;
            if (isreg)
                obj = (void *)(int)ctx->regs[off];
            else
                obj = *(void **)(ctx->x18 + off);
            fn(obj, -1);
            info->p = next;
            break;
        }
        case 5: {
            int off;
            unsigned int n, size;
            int i;
            unsigned char *q, *next;
            DtorFn fn;
            char *ptr;
            q = func_00100C70(p + 1, &off);
            q = func_00100BC0(q, &n);
            q = func_00100BC0(q, &size);
            fn = (DtorFn)RD32(q);
            next = q + 4;
            ptr = ctx->x18 + off;
            ptr += n * size;
            for (i = n; i != 0; i--) {
                ptr -= size;
                fn(ptr, -1);
            }
            info->p = next;
            break;
        }
        case 6: {
            int isreg = b & 0x20;
            int off1, off2;
            unsigned char *q, *next;
            DtorFn fn;
            char *obj;
            q = func_00100C70(p + 1, &off1);
            q = func_00100C70(q, &off2);
            fn = (DtorFn)RD32(q);
            next = q + 4;
            if (isreg)
                obj = (char *)(int)ctx->regs[off1];
            else
                obj = *(char **)(ctx->x18 + off1);
            fn(obj + off2, 0);
            info->p = next;
            break;
        }
        case 7: {
            int isreg = b & 0x20;
            int off1, off2;
            unsigned char *q, *next;
            DtorFn fn;
            char *obj;
            q = func_00100C70(p + 1, &off1);
            q = func_00100C70(q, &off2);
            fn = (DtorFn)RD32(q);
            next = q + 4;
            if (isreg)
                obj = (char *)(int)ctx->regs[off1];
            else
                obj = *(char **)(ctx->x18 + off1);
            fn(obj + off2, -1);
            info->p = next;
            break;
        }
        case 8: {
            int isreg = b & 0x20;
            int off1, off2, off3;
            unsigned char *q, *next;
            DtorFn fn;
            signed char cond;
            char *obj;
            q = func_00100C70(p + 1, &off1);
            q = func_00100C70(q, &off2);
            q = func_00100C70(q, &off3);
            fn = (DtorFn)RD32(q);
            next = q + 4;
            if (b & 0x40)
                cond = (signed char)ctx->regs[off1];
            else
                cond = *(signed char *)(ctx->x18 + off1);
            if (cond) {
                if (isreg)
                    obj = (char *)(int)ctx->regs[off2];
                else
                    obj = *(char **)(ctx->x18 + off2);
                fn(obj + off3, -1);
            }
            info->p = next;
            break;
        }
        case 9: {
            int isreg = b & 0x20;
            int off1, off2;
            unsigned int n, size;
            int i;
            unsigned char *q, *next;
            DtorFn fn;
            char *ptr;
            q = func_00100C70(p + 1, &off1);
            q = func_00100C70(q, &off2);
            q = func_00100BC0(q, &n);
            q = func_00100BC0(q, &size);
            fn = (DtorFn)RD32(q);
            next = q + 4;
            if (isreg)
                ptr = (char *)(int)ctx->regs[off1] + off2;
            else
                ptr = *(char **)(ctx->x18 + off1) + off2;
            ptr += n * size;
            for (i = n; i != 0; i--) {
                ptr -= size;
                fn(ptr, -1);
            }
            info->p = next;
            break;
        }
        case 10: {
            int isreg = b & 0x20;
            int off;
            unsigned char *q, *next;
            DelFn fn;
            void *obj;
            q = func_00100C70(p + 1, &off);
            fn = (DelFn)RD32(q);
            next = q + 4;
            if (isreg)
                obj = (void *)(int)ctx->regs[off];
            else
                obj = *(void **)(ctx->x18 + off);
            fn(obj);
            info->p = next;
            break;
        }
        case 11: {
            int isreg = b & 0x20;
            int off1, off2;
            unsigned char *q, *next;
            DelFn fn;
            signed char cond;
            void *obj;
            q = func_00100C70(p + 1, &off1);
            q = func_00100C70(q, &off2);
            fn = (DelFn)RD32(q);
            next = q + 4;
            if (b & 0x40)
                cond = (signed char)ctx->regs[off1];
            else
                cond = *(signed char *)(ctx->x18 + off1);
            if (cond) {
                if (isreg)
                    obj = (void *)(int)ctx->regs[off2];
                else
                    obj = *(void **)(ctx->x18 + off2);
                fn(obj);
            }
            info->p = next;
            break;
        }
        case 12: {
            volatile int x;
            unsigned int a;
            int c;
            if (catcher == p)
                return;
            { unsigned char *r = p + 1; x = RD32(r); }
            info->p = func_00100C70(func_00100BC0(p + 5, &a), &c);
            break;
        }
        case 13: {
            int off;
            unsigned char *q;
            int *loc;
            DtorFn fn;
            q = func_00100C70(p + 1, &off);
            loc = (int *)(ctx->x18 + off);
            fn = (DtorFn)loc[2];
            if (fn) {
                if (ctx->x4 == loc[0])
                    ctx->x8 = fn;
                else
                    fn((void *)loc[0], -1);
            }
            info->p = q;
            break;
        }
        case 15: {
            unsigned int a, bb;
            int c;
            unsigned char *q;
            if (catcher == p)
                return;
            q = func_00100BC0(p + 1, &a);
            q = func_00100BC0(q, &bb);
            q = func_00100C70(q, &c);
            info->p = q + a * 4;
            break;
        }
        default:
            func_00100AB0();
            break;
        }
        if (b & 0x80)
            info->p = 0;
    }
}
