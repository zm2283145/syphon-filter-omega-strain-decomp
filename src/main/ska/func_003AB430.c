#include "types.h"
typedef struct { char data[0x40]; } AnimList;
typedef struct { char data[0x50]; } AnimSet;
typedef struct { char data[0x18]; } AnimRange;
typedef struct { int handle; int unk4; } AnimRef;
typedef struct { void* res; char pad[0xC]; char inst[1]; } AnimModel;
extern void* ModelCtx_GetAnchorById(void* res, int a);
extern void AnimEvent_Construct(AnimList* l);
extern void cSkaAnimCheckpoints_ctor_void(AnimSet* s);
extern void* func_001ADD70(void* inst);
extern void* cSkaCrossFadeDuration_ctor_void(AnimRange* r);
extern void nSka_GetPlaybackGroupId(AnimRef* r, void* anim);
extern void AnimCtl_InstallMotion(void* inst, void* anim, int mode, void* range, float speed, float start, AnimRef* ref, AnimList* a, AnimList* b, AnimSet* s);
extern void cSkaAnimCheckpoints_dtor(AnimSet* s, int flags);
extern void AnimEvent_dtor(AnimList* l, int flags);
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
        anim = ModelCtx_GetAnchorById(m->res, 0);
        AnimEvent_Construct(&a);
        AnimEvent_Construct(&b);
        cSkaAnimCheckpoints_ctor_void(&set);
        inst = func_001ADD70(m->inst);
        r = cSkaCrossFadeDuration_ctor_void(&range);
        nSka_GetPlaybackGroupId(&ref, anim);
        AnimCtl_InstallMotion(inst, anim, 3, r, -1.0f, 0.0f, &ref, &a, &b, &set);
        cSkaAnimCheckpoints_dtor(&set, -1);
        AnimEvent_dtor(&b, -1);
        AnimEvent_dtor(&a, -1);
    }
}
