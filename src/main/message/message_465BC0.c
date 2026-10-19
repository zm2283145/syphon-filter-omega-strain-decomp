/*
 * main/message: 3 files, 00465BC0-00465CC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00465BC0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "message_two_member_dtor.h"

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_00465BC0, D_004DADF0)
#pragma pop /* merge_units */
/* merge_units: end func_00465BC0 */

/* merge_units: begin func_00465C50 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char pad04[0x1C];
    char b20;
    char pad21[0x57];
    char memberA[0x9C];
    char memberB[0xAC];
} Msg00239780;
extern char g_Game[];
extern char D_004DAE30[];
extern void EffectMsg_WrapRequest(Msg00239780* m, void* a, void* b);
extern void Event_Send(Msg00239780* m, void* target, int a);
extern void FileMan_Release(void* member, int flags);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg00239780* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

int GuiSound_Play(char* self, void* a, void* b)
{
    Msg00239780 m;
    EffectMsg_WrapRequest(&m, a, b);
    m.b20 = 1;
    Event_Send(&m, g_Game, 1);
    m.vtable = D_004DAE30;
    FileMan_Release(m.memberB, -1);
    FileMan_Release(m.memberA, -1);
    cMessage_dtor(&m, 0);
    return 1;
}
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00465C50 */

/* merge_units: begin func_00465CC0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_00465CC0, D_004DAE30)
#pragma pop /* merge_units */
/* merge_units: end func_00465CC0 */
