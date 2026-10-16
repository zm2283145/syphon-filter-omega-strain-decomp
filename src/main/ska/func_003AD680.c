#include "types.h"
typedef struct { int i0; int id; } F6Req;
typedef struct { char pad[4]; unsigned char busy; char pad2[0x2B]; char a30[0x14]; } F6Ctl2;
extern void BlockArray_Append(void* arr, void* item);
extern void func_003ABB10(F6Ctl2*);
extern void MotionGraph_ClearQueued(F6Ctl2*);
extern void MotionGraph_Install(float w, F6Ctl2* c, F6Req* r, int stop);
extern F6Req* AnimCtl_GetSelected(F6Ctl2*);
extern void MotionGraph_ClearActive(F6Ctl2*);
void AnimCtl_Install(F6Ctl2* c, F6Req* r, unsigned char mode)
{
    if (c->busy) {
        return;
    }
    switch (mode) {
    case 0:
        BlockArray_Append(c->a30, r);
        break;
    case 1:
        func_003ABB10(c);
        MotionGraph_ClearQueued(c);
        MotionGraph_Install(0.0f, c, r, 1);
        break;
    case 2:
        {
        F6Req* sel = AnimCtl_GetSelected(c);
        if (r->id != sel->id) {
            func_003ABB10(c);
            MotionGraph_ClearQueued(c);
            MotionGraph_Install(0.0f, c, r, 1);
        }
        }
        break;
    case 3:
        MotionGraph_ClearActive(c);
        MotionGraph_ClearQueued(c);
        MotionGraph_Install(1.0f, c, r, 1);
        break;
    }
}