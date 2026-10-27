/*
 * SFOGame/Source/human: 4 files, 0019F7C0-0019F7F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0019F7C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* cBitArray_34_opAssign(int* dst, int* src) {
    dst[0] = src[0];
    dst[1] = src[1];
    return dst;
}

void func_0019F7E0(char* self) {
    *(int*)(self + 12) = 0;
    *(int*)(self + 16) = 0;
}
static inline void merge_flush_func_0019F7C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019F7C0 */

/* merge_units: begin func_0019F7F0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "cmessage.h"
#pragma pop

typedef struct { int head; int bits[2]; int c; int d; } E7PS2;
E7PS2* Actor_ShiftPriorityHistory(E7PS2* dst, E7PS2* src) {
    int i;
    dst->head = src->head;
    for (i = 0; i < sizeof(int) * 8; i++) {
        if ((*(int*)((char*)src + (i / 32) * 4 + 4) >> (i & 31)) & 1) {
            *(int*)((char*)dst + (i / 32) * 4 + 4) |= 1 << (i & 31);
        } else {
            *(int*)((char*)dst + (i / 32) * 4 + 4) &= ~(1 << (i & 31));
        }
    }
    dst->c = src->c;
    dst->d = src->d;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019F7F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019F7F0 */

/* merge_units: begin func_0019F890 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Placeholder vtable: State() is slot 64 (vtable offset 0x108). */
class ActBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual unsigned char State();
};
struct Actor9F : ActBase {
    char pad04[0x54];
    void* target58;
    char pad5C[0x2EC0 - 0x5C];
    char root2EC0[0x3224 - 0x2EC0];
    int prev3224;
    int pad3228;
    int alt322C;
    char pad3230[8];
    int cur3238;
    char pad323C[0xC];
    int flags3248;
    char pad324C[0x3474 - 0x324C];
    void* link3474;
    char pad3478[0x3524 - 0x3478];
    int item3524;
};

struct ActMsg : CMsg {
    int action;
    int target;
    void* actor;
};

extern "C" {
void* cSkaSystem_GetAnchor(void* root, void* key);
void Actor_UnlinkAll(Actor9F* a);
void cSkaAnimAnchor_DetachChildren(void* r);
void cWeapon_DrawLastWeaponUsed(int item);
}
extern char D_0049D040[];
extern char D_0049D048[];
extern char D_004DA950[];
extern char g_CasEventMsgClass[];

static inline int ActBit(int v, int n) { return (v >> n) & 1; }
static inline bool IsDown(Actor9F* a, int n) { return (a->cur3238 >> n) & 1; }
static inline bool WasDown(Actor9F* a, int n) { return (a->prev3224 >> n) & 1; }
static inline bool Alt(Actor9F* a, int n) { return (a->alt322C >> n) & 1; }
static inline bool IsPressed(Actor9F* a, int n) { return IsDown(a, n) && !WasDown(a, n); }
static inline bool IsHeld(Actor9F* a, int n) { return IsDown(a, n) || WasDown(a, n); }
static inline bool ActTriggered(Actor9F* a, int n) { return IsPressed(a, n) || (!IsHeld(a, n) && Alt(a, n)); }

static inline bool IsBusy9F(Actor9F* a) { unsigned char st = a->State(); return st == 2 || st == 3; }
extern "C" void Actor_ReactToActionChanges(Actor9F* a)
{
    if (ActTriggered(a, 21)) {
        cSkaAnimAnchor_DetachChildren(cSkaSystem_GetAnchor(a->root2EC0, D_0049D040));
        cSkaAnimAnchor_DetachChildren(cSkaSystem_GetAnchor(a->root2EC0, D_0049D048));
        cWeapon_DrawLastWeaponUsed(a->item3524);
        Actor_UnlinkAll(a);
    }
    if (ActTriggered(a, 17) || ActTriggered(a, 18)) {
        if (!ActBit(a->prev3224, 19) && a->link3474 != 0) {
            int act;
            if (IsBusy9F(a))
                act = 0xD;
            else {
                act = 0xF;
                asm { .set reorder } /* scheduling barrier: keeps the if/else as branches instead of movz */
            }
            {
                ActMsg m;
                cMessage_ctor_cMessageNameR(&m, g_CasEventMsgClass);
                m.actor = a;
                m.action = (char)act;
                m.kind = 1;
                m.vtable = D_004DA950;
                m.target = -1;
                QueueMessage_cMessageR_cSystemP_int(&m, a->link3474, 1);
                m.vtable = D_004DA950;
                cMessage_dtor(&m, 0);
            }
            a->link3474 = 0;
        }
    }
    if (ActTriggered(a, 16)) {
        ActMsg m;
        cMessage_ctor_cMessageNameR(&m, g_CasEventMsgClass);
        m.actor = 0;
        m.vtable = D_004DA950;
        m.action = 0xC;
        m.target = -1;
        QueueMessage_cMessageR_cSystemP_int(&m, a->target58, 1);
        m.vtable = D_004DA950;
        cMessage_dtor(&m, 0);
        cWeapon_DrawLastWeaponUsed(a->item3524);
    }
    if (ActTriggered(a, 6)) {
        ActMsg m;
        a->flags3248 &= ~0x100;
        a->flags3248 &= ~0x200;
        cMessage_ctor_cMessageNameR(&m, g_CasEventMsgClass);
        m.actor = 0;
        m.vtable = D_004DA950;
        m.action = 7;
        m.target = -1;
        QueueMessage_cMessageR_cSystemP_int(&m, a->target58, 0);
        m.vtable = D_004DA950;
        cMessage_dtor(&m, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019F890(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019F890 */

/* merge_units: begin func_0019FD60 */
#pragma push /* merge_units */
extern void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(void* r);
extern int cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Empty(void* v);
extern void** cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Back(void* v);
extern void cSkaAnimAnchor_TreeNode_DetachChild(void* r, void* c);
void cSkaAnimAnchor_DetachChildren(void* r)
{
    while (!cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Empty(cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(r))) {
        cSkaAnimAnchor_TreeNode_DetachChild(r, *cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Back(cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(r)));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019FD60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019FD60 */
