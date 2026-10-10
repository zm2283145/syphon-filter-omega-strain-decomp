#include "types.h"
typedef struct { int w[12]; } __attribute__((aligned(16))) MRHead_c7;
typedef struct {
    MRHead_c7 head;
    int a30, a34, a38;
    float f3C, f40, f44, f48, f4C, f50, f54, f58;
    void* vt5C;
    int b60, b64, b68, b6C, b70, b74, b78;
    signed char c7C;
    int d80;
    signed char c84;
    int d88;
    unsigned char c8C;
    float f90;
} MotionReq_c7;
extern char D_004DFD80[];
extern char D_004DA930[];
static inline void QCopy_c7(void* d0, void* s0) { int n = 3; void* s = s0; void* d = d0;
    asm {
        .set noreorder
        nop
    lp:
        lq $a2, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $a2, -0x10(d)
        .set reorder
    }
}
MotionReq_c7* MotionRequest_Copy(MotionReq_c7* d, MotionReq_c7* s) {
    QCopy_c7(&d->head, &s->head);
    d->a30 = s->a30; d->a34 = s->a34; d->a38 = s->a38;
    d->f3C = s->f3C; d->f40 = s->f40; d->f44 = s->f44; d->f48 = s->f48;
    d->f4C = s->f4C; d->f50 = s->f50; d->f54 = s->f54; d->f58 = s->f58;
    d->vt5C = D_004DFD80;
    d->b60 = s->b60; d->b64 = s->b64; d->b68 = s->b68; d->b6C = s->b6C;
    d->b70 = s->b70; d->b74 = s->b74; d->b78 = s->b78;
    d->c7C = s->c7C;
    d->vt5C = D_004DA930;
    d->d80 = s->d80; d->c84 = s->c84; d->d88 = s->d88; d->c8C = s->c8C; d->f90 = s->f90;
    return d;
}