#include "types.h"

typedef struct { char pad[0x60]; float m[12]; } Src1CF;
extern void Mtx44_Set(Mtx44* m, float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
                      float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);

/* Builds a 4x4 matrix from the 3x4 block at +0x60 of src, with (0, 0, 0, 1) as the last column. */
void func_001CF1F0(Mtx44* out, Src1CF* s)
{
    Mtx44_Set(out, s->m[0], s->m[1], s->m[2], s->m[3], s->m[4], s->m[5], s->m[6], s->m[7],
              s->m[8], s->m[9], s->m[10], s->m[11], 0.0f, 0.0f, 0.0f, 1.0f);
}
