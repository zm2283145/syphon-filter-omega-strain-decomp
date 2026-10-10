#include "types.h"
typedef struct { char pad[0xE0]; float start; float cur; char grp[4]; } S3AC530;
typedef struct { float a; float b; } R3AC530;
extern int func_003AC6D0(void);
extern float AnimGroup_IsReady(void* grp, int x);
int func_003AC530(S3AC530* p, R3AC530* r)
{
    float d;
    if (p->start != -1.0f) {
        d = p->start - p->cur;
    } else {
        d = AnimGroup_IsReady(p->grp, func_003AC6D0());
    }
    return d <= 0.5f * (r->a + r->b);
}