#ifndef VU0_QUAT_ROT_H
#define VU0_QUAT_ROT_H
/* VU0 quaternion helpers (vc1, Placement_Invert family 00191400/001A90D0).
 * VU0_QROT(V, Q, D): rotate vector *V by quaternion *Q (q v q*), result to *D
 * (w of the result keeps V's w). Operands must be pointer variables. */
#define VU0_QROT(V, Q, D) asm { \
    lqc2 vf1, 0x0(V); vmove.w vf6, vf1; vmr32.w vf1, vf0; lqc2 vf2, 0x0(Q); \
    vmove.w vf3, vf2; vsub.xyz vf3, vf0, vf2; vmul.xyzw vf4, vf2, vf1; \
    vopmula.xyz ACC, vf2, vf1; vmaddaw.xyz ACC, vf1, vf2w; vopmsub.xyz vf5, vf1, vf2; \
    vsubaz.w ACC, vf4, vf4z; vmsubay.w ACC, vf0, vf4y; vmsubx.w vf5, vf0, vf4x; \
    vopmula.xyz ACC, vf5, vf3; vmaddaw.xyz ACC, vf5, vf3w; vmaddaw.xyz ACC, vf3, vf5w; \
    vopmsub.xyz vf6, vf3, vf5; sqc2 vf6, 0x0(D) }
/* *D = (-S.xyz, S.w) */
#define VU0_NEG3(S, D) asm { lqc2 vf1, 0x0(S); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(D) }
#endif