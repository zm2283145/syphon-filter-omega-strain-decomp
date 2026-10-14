/*
 * main/ai: range (3 files, 0016EFE0-0016F0E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

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
void func_0016EFE0(void* src, char* obj)
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
void func_0016F060(void* dst, char* obj)
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
extern void cAIDeactivatedMsg_v02();
extern void cAIDeactivatedMsg_v03();
void * const D_004DCD10[8] = { (void*)0x0, (void*)0x0, (void*)cAIDeactivatedMsg_dtor, (void*)cAIDeactivatedMsg_v01, (void*)cAIDeactivatedMsg_v02, (void*)cAIDeactivatedMsg_v03, (void*)0x0, (void*)0x0 };
extern void Event_Construct(E3AIMsgF0* msg, void* name);
extern void Event_Send(E3AIMsgF0* msg, void* target, int flags);
extern void cMessage_dtor(E3AIMsgF0* msg, int flags);

/* cAI virtual slot 0x11: unless disabled, sends the AI-deactivated message to the owner. */
void cAI_v11(E3cAIF0* self)
{
    if (!self->disabled) {
        E3AIMsgF0 msg;
        unsigned char* kind;
        Event_Construct(&msg, g_ScriptAIDeactivatedMsgKey);
        msg.vtable = ((char*)D_004DCD10);
        kind = &msg.kind;
        *kind = 2;
        *kind = 2;
        Event_Send(&msg, self->owner, 0);
        msg.vtable = ((char*)D_004DCD10);
        cMessage_dtor(&msg, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016F0E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016F0E0 */
