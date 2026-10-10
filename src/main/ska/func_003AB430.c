#include "types.h"
typedef struct { char data[0x40]; } AnimList;
typedef struct { char data[0x50]; } AnimSet;
typedef struct { char data[0x18]; } AnimRange;
typedef struct { int handle; int unk4; } AnimRef;
typedef struct { void* res; char pad[0xC]; char inst[1]; } AnimModel;
extern void* func_0018C6B0(void* res, int a);
extern void AnimEvent_Construct(AnimList* l);
extern void func_001A1500(AnimSet* s);
extern void* func_001ADD70(void* inst);
extern void* func_00393F10(AnimRange* r);
extern void func_0018C620(AnimRef* r, void* anim);
extern void AnimCtl_InstallMotion(void* inst, void* anim, int mode, void* range, float speed, float start, AnimRef* ref, AnimList* a, AnimList* b, AnimSet* s);
extern void func_00189F40(AnimSet* s, int flags);
extern void func_0018A260(AnimList* l, int flags);
/* Starts the model's default animation. */
void AnimModel_InitAnim(AnimModel* m)
{
    void* r;
    AnimSet set;
    AnimRef ref;
    AnimList b;
    AnimList a;
    AnimRange range;
    void* inst;
    void* anim;
    if (m->res) {
        anim = func_0018C6B0(m->res, 0);
        AnimEvent_Construct(&a);
        AnimEvent_Construct(&b);
        func_001A1500(&set);
        inst = func_001ADD70(m->inst);
        r = func_00393F10(&range);
        func_0018C620(&ref, anim);
        AnimCtl_InstallMotion(inst, anim, 3, r, -1.0f, 0.0f, &ref, &a, &b, &set);
        func_00189F40(&set, -1);
        func_0018A260(&b, -1);
        func_0018A260(&a, -1);
    }
}
