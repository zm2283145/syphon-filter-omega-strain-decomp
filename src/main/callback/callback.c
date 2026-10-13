/*
 * main/callback: 2 files, 003EA0E0-003EA1D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EA0E0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "eventQueue.h"
extern "C" {
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_004BDFC8[];                   /* "callback.cc" */
extern EQEvent* g_EventQueueRunning;                 /* event currently running */
extern char g_EventQueue[];                   /* queued events */
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
void Mem_Free(int pool, void* p, char* file, int line);
void ActiveList_EraseMatching(void* list, EQPred pred);
}

static inline void EQ_Delete(EQEvent* e)
{
    if (D_00533880)
        Alloc_Lock(9);
    D_00533888++;
    e->~EQEvent();
    Mem_Free(0, e, D_004BDFC8, 0x36);
    if (D_00533880)
        Alloc_Unlock(9);
    D_00533888--;
}
/* Removes an event from the queue and destroys it (unless it is running). */
extern "C" void EventQueue_Remove(EQEvent* ev)
{
    if (g_EventQueueRunning != ev) {
        EQCmp c __attribute__((aligned(8)));
        ActiveList_EraseMatching(g_EventQueue, EQPred(c, &ev));
        EQ_Delete(ev);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003EA0E0 */

/* merge_units: begin func_003EA1D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern unsigned char g_EventQueueClosed;            /* queue closed: drop new events */
void List_End(void* list, void* item);      /* push_back */
}
/* Queues an event; destroys it right away when the queue is closed. */
extern "C" void EventQueue_Admit(EQEvent* e)
{
    if (g_EventQueueClosed) {
        EQEvent* p = e;
        if (p) {
            AllocGuard g;
            p->~EQEvent();
            Mem_Free(0, p, D_004BDFC8, 0x27);
        }
        return;
    }
    List_End(g_EventQueue, &e);
}
#pragma pop /* merge_units */
/* merge_units: end func_003EA1D0 */
