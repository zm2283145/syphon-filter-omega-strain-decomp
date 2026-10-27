#include "types.h"
typedef struct { char data[0x40]; } AnimList;
typedef struct { char data[0x50]; } AnimSet;
typedef struct { char data[0x18]; } AnimRange;
typedef struct { int handle; int unk4; } AnimRef;
typedef struct { void* res; char pad[0xC]; char inst[1]; } AnimModel;
extern void* cSkaAnimationSet_GetNode_int(void* res, int a);
extern void cSkaAnimEndedMessage_ctor_void(AnimList* l);
extern void cSkaAnimCheckpoints_ctor_void(AnimSet* s);
extern void* func_001ADD70(void* inst);
extern void* cSkaCrossFadeDuration_ctor_void(AnimRange* r);
extern void nSka_GetPlaybackGroupId(AnimRef* r, void* anim);
extern void cSkaRequestStream_AddRequest(void* inst, void* anim, int mode, void* range, float speed, float start, AnimRef* ref, AnimList* a, AnimList* b, AnimSet* s);
extern void cSkaAnimCheckpoints_dtor(AnimSet* s, int flags);
extern void cSkaAnimEndedMessage_dtor(AnimList* l, int flags);
/* Starts the model's default animation. */
void cSkaSystem_SetInitialAnimation(AnimModel* m)
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
        anim = cSkaAnimationSet_GetNode_int(m->res, 0);
        cSkaAnimEndedMessage_ctor_void(&a);
        cSkaAnimEndedMessage_ctor_void(&b);
        cSkaAnimCheckpoints_ctor_void(&set);
        inst = func_001ADD70(m->inst);
        r = cSkaCrossFadeDuration_ctor_void(&range);
        nSka_GetPlaybackGroupId(&ref, anim);
        cSkaRequestStream_AddRequest(inst, anim, 3, r, -1.0f, 0.0f, &ref, &a, &b, &set);
        cSkaAnimCheckpoints_dtor(&set, -1);
        cSkaAnimEndedMessage_dtor(&b, -1);
        cSkaAnimEndedMessage_dtor(&a, -1);
    }
}
