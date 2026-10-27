/*
 * SFOGame/Source/ai: 6 files, 0016EF80-0016EFE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016EF80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copy.
 */

#include "types.h"

Word* cConstLListIterator_cTargetAwarenessPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_0016EF80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016EF80 */

/* merge_units: begin func_0016EF90 */
#pragma push /* merge_units */
#include "iter_return_copy.h"

/* Return the end iterator. */
DEFINE_ITER_END(std_list_cTargetAwarenessPtr_end_void_2)
static inline void merge_flush_func_0016EF90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016EF90 */

/* merge_units: begin func_0016EFC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator constructor.
 */


/* volatile mirrors the original stack temporary. */
Word* std_list_cTargetAwarenessPtr_generic_iterator_1_ctor(Word* self, int value) {
    volatile int tmp = value;
    self->value = tmp;
    return self;
}
static inline void merge_flush_func_0016EFC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016EFC0 */

/* merge_units: begin func_0016EFE0 */
#pragma push /* merge_units */
static inline void QCopy_EFE0(void* dst, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
void cAiTransfer_Put(void* src, char* obj)
{
    if (obj)
        obj += 0x44;
    QCopy_EFE0(obj, src, 0x14);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016EFE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016EFE0 */

/* merge_units: begin func_0016F060 */
#pragma push /* merge_units */
static inline void QCopy_F060(void* dst, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
void cAiTransfer_Get(void* dst, char* obj)
{
    if (obj)
        obj += 0x44;
    QCopy_F060(dst, obj, 0x14);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016F060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016F060 */

/* merge_units: begin func_0016F0E0 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[0xF];
} E3AIMsgF0;
typedef struct { char pad[0x30]; void* owner; char pad2[0x29]; unsigned char disabled; } E3cAIF0;
extern char g_ScriptAIDeactivatedMsgKey[];
extern void cAIDeactivatedMsg_dtor();
extern void cAIDeactivatedMsg_v01();
extern void cAIDeactivatedMsg_Pack();
extern void cAIDeactivatedMsg_getSOBJClassId();
void * const D_004DCD10[8] = { (void*)0x0, (void*)0x0, (void*)cAIDeactivatedMsg_dtor, (void*)cAIDeactivatedMsg_v01, (void*)cAIDeactivatedMsg_Pack, (void*)cAIDeactivatedMsg_getSOBJClassId, (void*)0x0, (void*)0x0 };
extern void cMessage_ctor_cMessageNameR(E3AIMsgF0* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(E3AIMsgF0* msg, void* target, int flags);
extern void cMessage_dtor(E3AIMsgF0* msg, int flags);

/* cAI virtual slot 0x11: unless disabled, sends the AI-deactivated message to the owner. */
void cAI_Deactivate(E3cAIF0* self)
{
    if (!self->disabled) {
        E3AIMsgF0 msg;
        unsigned char* kind;
        cMessage_ctor_cMessageNameR(&msg, g_ScriptAIDeactivatedMsgKey);
        msg.vtable = ((char*)D_004DCD10);
        kind = &msg.kind;
        *kind = 2;
        *kind = 2;
        QueueMessage_cMessageR_cSystemP_int(&msg, self->owner, 0);
        msg.vtable = ((char*)D_004DCD10);
        cMessage_dtor(&msg, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016F0E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016F0E0 */
