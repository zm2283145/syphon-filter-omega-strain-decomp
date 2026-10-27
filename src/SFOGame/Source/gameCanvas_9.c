/*
 * SFOGame/Source/gameCanvas: 5 files, 00465BC0-00465D80
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
static inline void merge_flush_func_00465BC0(void) {} /* merge_units */
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
extern void QueueMessage_cMessageR_cSystemP_int(Msg00239780* m, void* target, int a);
extern void cFileMan_dtor(void* member, int flags);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg00239780* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


int PlayGuiSound(char* self, void* a, void* b)
{
    Msg00239780 m;
    EffectMsg_WrapRequest(&m, a, b);
    m.b20 = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
    m.vtable = D_004DAE30;
    cFileMan_dtor(m.memberB, -1);
    cFileMan_dtor(m.memberA, -1);
    cMessage_dtor(&m, 0);
    return 1;
}
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00465C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00465C50 */

/* merge_units: begin func_00465CC0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(cPlaySoundMsg_dtor_void_2, D_004DAE30)
static inline void merge_flush_func_00465CC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00465CC0 */

/* merge_units: begin func_00465D50 */
#pragma push /* merge_units */
typedef struct { unsigned char flag : 1; unsigned char rest : 7; } Bits00465D50;
typedef struct { Bits00465D50 slots[16]; } Row00465D50;
extern Row00465D50* D_004EE620;
/* Clear the low flag bit of slot (row, col). */
void func_00465D50(int row, int col)
{
    D_004EE620[row].slots[col].flag = 0;
}
static inline void merge_flush_func_00465D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00465D50 */

/* merge_units: begin func_00465D80 */
#pragma push /* merge_units */
typedef struct FlagByte {
    unsigned char set : 1;
    unsigned char rest : 7;
} FlagByte;

typedef FlagByte FlagRow[16];

#if 0 /* merge_units */
extern FlagRow* D_004EE620;
#endif /* merge_units */
#define D_004EE620 (*(FlagRow **)&D_004EE620) /* merge_units */


/* Sets bit 0 of entry [row][col] in the 16-column flag table. */
void TeamTable_SetBit0_465D80(int row, int col) {
    D_004EE620[row][col].set = 1;
}
#undef D_004EE620 /* merge_units */
static inline void merge_flush_func_00465D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00465D80 */
