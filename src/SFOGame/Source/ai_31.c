/*
 * SFOGame/Source/ai: 1 file, 0016F1C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016F1C0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct {
    void* vtable;
    char base[0x18];
    int size;
    unsigned char kind;
    char pad[3];
    void* target;
    char pad2[8];
} AIMsg;
typedef struct { char pad[0x30]; void* target; } NetCtx;
typedef struct { char pad[0x30]; void* owner; char pad2[0x28]; unsigned char disabled; } cAI;
extern NetCtx* g_LocalPlayer;
extern char g_ScriptAIActivatedMsgKey[];
extern void cAIActivatedMsg_dtor();
extern void cAIActivatedMsg_Clone();
extern void cAIActivatedMsg_Pack();
extern void cAIActivatedMsg_getSOBJClassId();
void * const D_004DCD30[8] = { (void*)0x0, (void*)0x0, (void*)cAIActivatedMsg_dtor, (void*)cAIActivatedMsg_Clone, (void*)cAIActivatedMsg_Pack, (void*)cAIActivatedMsg_getSOBJClassId, (void*)0x0, (void*)0x0 };
extern char D_004DCD70[];
extern void cMessage_ctor_cMessageNameR(AIMsg* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(AIMsg* msg, void* target, int flags);
extern void cMessage_dtor(AIMsg* msg, int flags);

/* cAI virtual slot 0x10: unless disabled, sends a kind-2 message carrying the network target to the owner. */
void cAI_Activate(cAI* self)
{
    if (!self->disabled) {
        AIMsg msg;
        void* target = g_LocalPlayer->target;
        unsigned char* kind;
        cMessage_ctor_cMessageNameR(&msg, g_ScriptAIActivatedMsgKey);
        msg.target = target;
        kind = &msg.kind;
        *kind = 2;
        msg.vtable = ((char*)D_004DCD30);
        msg.size = 0x40;
        *kind = 2;
        QueueMessage_cMessageR_cSystemP_int(&msg, self->owner, 0);
        msg.vtable = D_004DCD70;
        cMessage_dtor(&msg, 0);
    }
}
static inline void merge_flush_func_0016F1C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016F1C0 */
