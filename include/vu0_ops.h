#ifndef VU0_OPS_H
#define VU0_OPS_H
/* VU0 macro-mode helpers (inline asm). Pointers are untyped so any 16-byte aligned
   vector struct can be passed. Hand-written style blocks use .set noreorder.
   MW asm rules (mw38): asm { } accepts vfN / vfNx / viN / ACC / Q / I without $ and
   .xyzw dest masks; C variables (params, locals, floats) can be used directly as GPR/FPR
   operands and get registers allocated (declaration order steers which). Default (reorder)
   blocks are scheduled with the surrounding code (sqc2 can land in a jr delay slot, mfc1
   gets a hazard nop); .set noreorder emits the block verbatim. vcallmsr counts as a
   call (operands go to s-regs); use .word 0x4A00D839 when retail has no saves. */

/* Zero test via the VU0 MAC flags (vi17): xyz -> mask 0xE, xyzw -> mask 0xF. */
static inline int VU0_IsZero3(void* v) {
    int r, k, f;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline int VU0_IsZero4(void* v) {
    int r, k, f;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
/* sceVu0UnitMatrix-style identity: row3 = vf0, rows 0..2 built from vf0 with MMI shuffles. */
static inline void VU0_UnitMatrix(void* m) {
    int t;
    asm {
        sqc2 vf0, 0x30(m)
        qmfc2.ni t, vf0
        pcpyud t, t, zero
        sq t, 0x10(m)
        pexcw t, t
        sq t, 0x20(m)
        pcpyud t, t, zero
        sq t, 0(m)
    }
}
/* xyz dot product; result taken from the w lane with mtsah/qfsrv. */
static inline float VU0_Dot3(void* a, void* b) {
    int t;
    float r;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
/* Grow an AABB {min, max} (two quads) to contain point p (xyz). */
static inline void VU0_BoxExtend(void* box, void* p) {
    char* hi = (char*)box + 0x10;
    asm {
        lqc2 vf1, 0(box)
        lqc2 vf2, 0(hi)
        lqc2 vf3, 0(p)
        vmini.xyz vf1, vf1, vf3
        vmax.xyz vf2, vf2, vf3
        sqc2 vf1, 0(box)
        sqc2 vf2, 0(hi)
    }
}
/* p[0..3] = rows of p transformed by the 3x3 part of m (row vectors; m rows in vf4..vf6). */
static inline void VU0_MulRows33(void* p, void* m) {
    asm {
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf8, 0x0(p)
        lqc2 vf9, 0x10(p)
        lqc2 vf10, 0x20(p)
        lqc2 vf11, 0x30(p)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        vmulax.xyz ACC, vf4, vf9x
        vmadday.xyz ACC, vf5, vf9y
        vmaddz.xyz vf9, vf6, vf9z
        vmulax.xyz ACC, vf4, vf10x
        vmadday.xyz ACC, vf5, vf10y
        vmaddz.xyz vf10, vf6, vf10z
        vmulax.xyz ACC, vf4, vf11x
        vmadday.xyz ACC, vf5, vf11y
        vmaddz.xyz vf11, vf6, vf11z
        sqc2 vf8, 0x0(p)
        sqc2 vf9, 0x10(p)
        sqc2 vf10, 0x20(p)
        sqc2 vf11, 0x30(p)
    }
}
/* p[0..3] = rows of p transformed by 4x4 m (m rows in vf4..vf7, results vf12..vf15). */
static inline void VU0_MulRows44(void* p, void* m) {
    asm {
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        lqc2 vf8, 0x0(p)
        lqc2 vf9, 0x10(p)
        lqc2 vf10, 0x20(p)
        lqc2 vf11, 0x30(p)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(p)
        sqc2 vf13, 0x10(p)
        sqc2 vf14, 0x20(p)
        sqc2 vf15, 0x30(p)
    }
}
/* d = a * b for 4x4 matrices (a rows in vf4..vf7, b rows in vf8..vf11, d rows from vf12..vf15). */
static inline void VU0_MulMtx44(void* d, void* a, void* b) {
    asm {
        lqc2 vf4, 0x0(a)
        lqc2 vf5, 0x10(a)
        lqc2 vf6, 0x20(a)
        lqc2 vf7, 0x30(a)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(d)
        sqc2 vf13, 0x10(d)
        sqc2 vf14, 0x20(d)
        sqc2 vf15, 0x30(d)
    }
}
/* v.xyz = v.xyz * (3x3 part of m), row-vector convention (m rows in vf4..vf6). */
static inline void VU0_ApplyMtx33(void* v, void* m) {
    asm {
        lqc2 vf8, 0(v)
        lqc2 vf4, 0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0(v)
    }
}
#endif