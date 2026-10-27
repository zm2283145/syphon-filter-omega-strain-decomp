/*
 * SFOGame/Source/npc: 4 files, 0015B220-0015B470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015B220 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { int key; int val; int x8; } Ent_B060;
typedef struct N_B060 { struct N_B060* prev; struct N_B060* next; Ent_B060* e; } N_B060;
typedef struct { int a; int b; } It2_B060;
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_0049B670[];
extern char D_004EA1B0[];
void std_list_deleter_voidPtr_begin_void(N_B060** out, void* list);
void func_0015AD60(N_B060** out, N_B060** in);
void func_0015AD50(N_B060** out, void* list);
void func_0015AD40(N_B060** out, N_B060** in);
void std_list_cEnabledListItemPtr_push_back(void* list, Ent_B060** e);
}
typedef struct { char pad[0xC]; int id; } Ctl_B060;
typedef struct { char pad[0x30]; Ctl_B060* ctl; } NPC_B060;
static inline void Begin(N_B060** out) { N_B060* t; std_list_deleter_voidPtr_begin_void(&t, D_004EA1B0); func_0015AD60(out, &t); }
static inline N_B060* End(N_B060** out) { N_B060* t; func_0015AD50(&t, D_004EA1B0); func_0015AD40(out, &t); return *out; }
static inline void Ent_Init(Ent_B060* p, Ctl_B060* c) { p->key = -1; p->key = c->id; p->val = 0; p->x8 = 0; }
extern "C" void cNPC_SetEnabled(NPC_B060* self, int bit, int set)
{
    Ent_B060* found = 0;
    N_B060* end;
    N_B060* it;
    N_B060* n;
    Begin(&it);
    n = it;
    for (; n != End(&end); n = n->next) {
        if (n->e->key == self->ctl->id) {
            found = n->e;
            break;
        }
    }
    if (!found) {
        Ent_B060* p;
        {
            AllocGuard g;
            p = (Ent_B060*)cMemMan_Allocate(0, 0xC, D_0049B670, 0xD7);
        }
        if (p)
            Ent_Init(p, self->ctl);
        found = p;
        std_list_cEnabledListItemPtr_push_back(D_004EA1B0, &found);
    }
    if (set) {
        if (bit >= 0)
            found->val |= 1 << bit;
        else
            found->val = 0xFF;
    } else {
        if (bit >= 0)
            found->val &= ~(1 << bit);
        else
            found->val = 0;
    }
}
static inline void merge_flush_func_0015B220(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015B220 */

/* merge_units: begin func_0015B430 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int cGOBJ_SOBJ_convert(int handle);

/* Script: LosCam(a, b); resolves both handles, result unused. */
int Script_LosCam(NpcScriptArgs* args) {
    cGOBJ_SOBJ_convert(args->arg1);
    cGOBJ_SOBJ_convert((int)args->npc);
    return 0;
}
static inline void merge_flush_func_0015B430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015B430 */

/* merge_units: begin func_0015B470 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "msg_clone.h"
#pragma pop

#pragma cplusplus on

extern "C" char D_004D9300[];

struct Msg_0023FF50 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = D_004D9300; p->b24 = s->b24;

extern "C" {
char D_0049C050[] = "NetObjectMgr.hh";
}
DEFINE_MESSAGE_CLONE(cSwitchControllersMsg_Clone, Msg_0023FF50, 0x28, D_0049C050, 0xE, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015B470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015B470 */

/* merge_units: begin func_0015B570 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" char D_004D9320[];
extern "C" char D_004DFD80[];
extern "C" char D_004E0840[];
MSG_CLONE_BEGIN(cCharActionMsg_Bool_Clone, 0x30, "character.hh", 0x1C5)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E0840;
    F(int, 0x24) = S(int, 0x24);
    F(char, 0x28) = S(char, 0x28);
    p->vt = D_004D9320;
    F(unsigned char, 0x2C) = S(unsigned char, 0x2C);
MSG_CLONE_END
static inline void merge_flush_func_0015B570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015B570 */
