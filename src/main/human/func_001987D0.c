#include "types.h"
typedef struct { void* cur; void* first; void* last; void** node; int pad[4]; } C5DqIt;
typedef struct { int a[4]; } C5Dq;
typedef struct { char pad[0x3C]; C5Dq sel; } C5Motion;
extern void func_00198C40(C5DqIt* out, C5Dq* d);
extern void func_00198BE0(C5DqIt* out, C5Dq* d);
extern int func_00198880(C5DqIt* a, C5DqIt* b);
extern void* func_00198BD0(C5DqIt* it);
extern void* func_00198BC0(void* p);
extern float func_00198900(void* p, void* arg);
extern void DequeIter_Next(C5DqIt* it);
float MotionCtrl_GetSelectorMetric(C5Motion* m, void* arg) {
    float sum = 0.0f;
    C5DqIt it;
    C5DqIt end;
    func_00198C40(&it, &m->sel);
    func_00198BE0(&end, &m->sel);
    while (func_00198880(&it, &end)) {
        sum += func_00198900(func_00198BC0(func_00198BD0(&it)), arg);
        DequeIter_Next(&it);
    }
    return sum;
}