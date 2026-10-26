/*
 * lib/medius: 3 files, 002F6998-002F6B80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F6998 */
#include "types.h"
typedef struct { unsigned int count; float rate; float peak; } R2F6998;
int rt_comm_metric_update_single(R2F6998* p, unsigned int ms)
{
    if (!p) return 2;
    if (ms != 0) p->rate = (float)p->count / ((float)ms / 1000.0f);
    else p->rate = 0.0f;
    if (p->rate > p->peak) p->peak = p->rate;
    p->count = 0;
    return 0;
}
/* merge_units: end func_002F6998 */

/* merge_units: begin func_002F6A48 */
/* The EE soft-float libcall is aliased to its retail function. */
__asm__("fptodp = SoftFloat_FloatToDouble");
typedef struct { unsigned int count; float rate; float peak; } Rate2F6A48;
typedef struct { int timer[2]; Rate2F6A48 r[4]; } Stats2F6A48;
extern Stats2F6A48 D_00525508;
extern char D_00525540[];
extern char D_004AF1D8[];
extern char D_004AF200[];
extern char D_004AF228[];
extern char D_004AF250[];
extern char D_004AF278[];
extern int rt_time_elapsed_msecs(void *t, unsigned int *elapsed);
extern int printf(const char *fmt, ...);
extern int rt_time_start(void *t);
/* Prints the transfer-rate statistics once more than a second has elapsed. */
int rt_comm_metric_print(void)
{
    unsigned int ms;
    Stats2F6A48 *s;

    if (rt_time_elapsed_msecs(D_00525540, &ms) != 0) return 1;
    if (ms > 1000) {
        s = &D_00525508;
        printf(D_004AF1D8, s->r[0].rate, s->r[0].peak);
        printf(D_004AF200, s->r[1].rate, s->r[1].peak);
        printf(D_004AF228, s->r[2].rate, s->r[2].peak);
        printf(D_004AF250, s->r[3].rate, s->r[3].peak);
        printf(D_004AF278);
        if (rt_time_start(D_00525540) != 0) return 1;
    }
    return 0;
}
/* merge_units: end func_002F6A48 */

/* merge_units: begin func_002F6B80 */
const unsigned int D_004908A0[2] = { 0x0, 0x0 };
const unsigned int D_004908A8[6] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
const unsigned int D_004908C0[5] = { 0x0, 0x0, 0x0, 0x0, 0x0 };
extern int D_004908D4;
extern char D_00525600[];
extern char D_00525640[];
extern void sceSifMInitRpc(int);
extern void sceLibnetInitialize(char *, int, int, int);
extern int sceLibnetRegisterHandler(char *, char *);
extern int rt_comm_platform2_wait_for_interface_startup(void);
extern int rt_comm_platform2_get_local_ip_from_stack(char *);
extern int rt_comm_platform2_get_broadcast_ip_from_stack(char *);
int rt_comm_platform2_startup(void)
{
    int r;
    if ((*(unsigned char*)D_004908A0)) return 4;
    sceSifMInitRpc(0);
    sceLibnetInitialize(D_00525600, 0x800, 0x2000, 0x20);
    if (sceLibnetRegisterHandler(D_00525600, D_00525640) < 0) return 1;
    r = rt_comm_platform2_wait_for_interface_startup();
    if (r) return r;
    if (D_004908D4 < 0) return 1;
    r = rt_comm_platform2_get_local_ip_from_stack(((char*)D_004908A8));
    if (r) return r;
    r = rt_comm_platform2_get_broadcast_ip_from_stack(((char*)D_004908C0));
    if (r) return r;
    (*(unsigned char*)D_004908A0) = 1;
    return 0;
}
/* merge_units: end func_002F6B80 */
