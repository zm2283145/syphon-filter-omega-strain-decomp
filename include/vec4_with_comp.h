#ifndef VEC4_WITH_COMP_H
#define VEC4_WITH_COMP_H
/* o->v = o->v.With<F>(val): quad copy to a stack temp, set one float component,
 * copy to a second temp, then memberwise store back (vc1, 0028D4E0 family).
 * Use with: #pragma push / peephole off / opt_propagation off / opt_common_subs off ... #pragma pop */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) VWC4;
#define VEC4_WITH_COMP_FUNC(NAME, OFF, F) \
void NAME(char* o, float val) { \
    VWC4 r; VWC4 t; \
    VWC4* d2; \
    VWC4* d3; \
    VWC4* d1; \
    float b; float c; float d; float a; \
    d1 = &t; *d1 = *(VWC4*)(o + (OFF)); d2 = &t; d2->F = val; d3 = &r; *d3 = *d2; \
    d = r.w; c = r.z; b = r.y; a = r.x; \
    ((VWC4*)(o + (OFF)))->x = a; ((VWC4*)(o + (OFF)))->y = b; ((VWC4*)(o + (OFF)))->z = c; ((VWC4*)(o + (OFF)))->w = d; \
}
#endif