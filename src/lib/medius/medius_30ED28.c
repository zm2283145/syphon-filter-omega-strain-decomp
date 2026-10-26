typedef struct {
    int f0;
    int f4;
    int flags;
    char pad[0x2044 - 0xC];
    void (*cb2044)(void *u, int r, int flags);
    void (*cb2048)(void *u, int r, int flags);
    void (*cb204C)(void *u, int r, int flags);
} UpCtxED28;
typedef struct { char pad[0x50]; int state; char pad2[4]; UpCtxED28 *ctx; } UpnpED28;

extern unsigned char D_0049134C;
extern unsigned char D_0049134D;
extern unsigned char D_0049134E;
extern unsigned char D_0049134F;
extern int D_00491350;
extern int D_00491354;
extern int D_00491358;
extern int D_0049135C;

extern void rt_comm_destroy(int h);
extern int func_0030BE60(UpnpED28 *u, char *done);
extern int func_0030C418(UpnpED28 *u);
extern int func_0030C5E8(UpnpED28 *u);
extern int func_0030C780(UpnpED28 *u);
extern int func_0030CA90(UpnpED28 *u);
extern int func_0030CD00(UpnpED28 *u);
extern int func_0030D1E8(UpnpED28 *u);
extern int func_0030D2B8(UpnpED28 *u);
extern int func_0030D520(UpnpED28 *u);
extern int process_nat_resolution_timeslice(UpnpED28 *u);
extern int process_heartbeat_timeslice(UpnpED28 *u);
/* weak discarded stub: the retail TU defined func_0030D8B0 before this function (gives the non-likely branch) */
int __attribute__((weak, section(".dtors_drop"))) func_0030D8B0(UpnpED28 *u) { return 0; }

int func_0030ED28(UpnpED28 *u)
{
    int r = 0;
    unsigned char done;

    if (u == 0) return 2;
    switch (u->state) {
    case 0:
        r = process_heartbeat_timeslice(u);
        break;
    case 1:
        if (D_0049134C == 0) {
            done = 0;
            r = func_0030BE60(u, &done);
            if (r != 0 || done != 0) {
                D_00491350 = r;
                D_0049134C = 1;
                rt_comm_destroy(u->ctx->f0);
                u->ctx->f0 = 0;
                u->ctx->cb2044(u, r, u->ctx->flags);
                u->ctx->cb2044 = 0;
                u->state = 0;
            }
        } else {
            u->ctx->cb2044(u, D_00491350, u->ctx->flags);
            u->ctx->cb2044 = 0;
            u->state = 0;
        }
        break;
    case 2:
        if (D_0049134D == 0) {
            r = func_0030C418(u);
            break;
        }
        u->ctx->cb2048(u, D_00491354, u->ctx->flags);
        u->ctx->cb2048 = 0;
        u->state = 0;
        break;
    case 3:
        if ((u->ctx->flags & 0x1000) && D_0049134E == 0) {
            r = func_0030C5E8(u);
            break;
        }
        if ((u->ctx->flags & 0x800) && D_0049134F == 0) {
            r = func_0030C5E8(u);
            break;
        }
        if (u->ctx->flags & 0x1000)
            u->ctx->cb204C(u, D_00491358, u->ctx->flags);
        else
            u->ctx->cb204C(u, D_0049135C, u->ctx->flags);
        u->ctx->cb204C = 0;
        u->state = 0;
        break;
    case 4:
        r = func_0030C780(u);
        break;
    case 5:
        r = func_0030CA90(u);
        break;
    case 6:
        r = func_0030CD00(u);
        break;
    case 7:
        r = func_0030D1E8(u);
        break;
    case 8:
        r = func_0030D2B8(u);
        break;
    case 9:
        r = func_0030D520(u);
        break;
    case 10:
        r = process_nat_resolution_timeslice(u);
        break;
    }
    if (r == 0 && u->ctx != 0)
        r = func_0030D8B0(u);
    return r;
}





