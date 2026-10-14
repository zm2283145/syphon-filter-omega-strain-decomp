#include "types.h"
extern void func_0031BA78(void* a, void* b, int n, float* out);
extern void func_0031A418(float* a, int start, int end, int max, int* out, int* count);
extern float func_0031AB38(float* out, float y0, float y1, float y2);
void func_0031A820(void* a, void* b, float* buf, float* val, float* pos, int* count, int max)
{
    int idx[100];
    int i; int k;
    func_0031BA78(a, b, 0x100, buf);
    func_0031A418(buf, 0, 0x100, max, idx, count);
    for (i = 0; i < *count; i++) {
        k = idx[i];
        pos[i] = (float)k + func_0031AB38(&val[i], buf[k - 1], buf[k], buf[k + 1]);
    }
    if (*count < 4) {
        float d = 7.0f; float p = d; for (k = 0; k < 36; k++) { pos[k] = p; p += d; val[k] = buf[(k + 1) * 7];
        }
        *count = 36;
    }
}