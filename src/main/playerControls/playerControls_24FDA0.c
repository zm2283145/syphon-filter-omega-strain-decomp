/*
 * main/playerControls: range (2 files, 0024FDA0-0024FDE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0024FDA0 */
#pragma push /* merge_units */
typedef struct { __int128 v; float a; float b; signed char f; } MM24;
#pragma push
#pragma optimization_level 3
MM24 *MoveMsg_Set(MM24 *m, __int128 *v, float a, float b, int flag) {
    signed char c;
    m->v = *v;
    m->a = a;
    m->b = b;
    /* barrier: empty asm keeps the branchy bool (b + delay slot) shape */
    if (flag) { c = 1; asm { .set reorder } } else c = 0;
    m->f = c;
    return m;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FDA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FDA0 */

/* merge_units: begin func_0024FDE0 */
#pragma push /* merge_units */
typedef struct { float x, y, z; } Vec3;
static inline float WrapPi(float a)
{
    for (;;) {
        if (a > 3.1415927f) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
    return a;
}
void Math_WrapAngleDiff(Vec3* out, Vec3* in)
{
    float x = WrapPi(in->x);
    float y = WrapPi(in->y);
    float z = WrapPi(in->z);
    out->x = x;
    out->y = y;
    out->z = z;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FDE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FDE0 */
