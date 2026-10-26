/*
 * main/player: range (4 files, 00176590-00176E60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00176590 */
#pragma push /* merge_units */
typedef struct { char pad[0x1AC]; float f1AC; } A2P176;
void cPlayer_v1E(A2P176* p, float x) {
    if (!(x <= p->f1AC)) p->f1AC = x;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176590 */

/* merge_units: begin func_001765B0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; char* obj; char pad2[0x1A8 - 0x34]; float maxv; } S1765B0;
extern int g_Hud;
extern char* Loc_LookupText(char* key);
extern void Hud_ShowCallout(int a, char* b, char* c, int d, int e, int f, float g, float h);
void cPlayer_v26(S1765B0* p, int a1, int a2, int flag, float v)
{
    if (v > p->maxv) {
        p->maxv = v;
    }
    if (flag == 0 && v > 0.5f) {
        char* s;
        int d;
        d = g_Hud;
        s = p->obj + 0xC;
        Hud_ShowCallout(d, s, Loc_LookupText("headshot"), 0, 0, 0, 0.1f, 1.0f);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001765B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001765B0 */

/* merge_units: begin func_00176660 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma inline_depth(8)

struct Pri_76660 {
    int cur;
    int w[1];
    int Test(int i) { return ((w[i / 32] >> (i & 31)) & 1) != 0; }
    void Update() {
        int i = 11;
        while (i >= 0 && !Test(i))
            i--;
        if (!Test(i))
            cur = -1;
        else
            cur = i;
    }
    void Set(int i) { w[i / 32] |= 1 << (i & 31); Update(); }
    void Clear(int i) { w[i / 32] &= ~(1 << (i & 31)); Update(); }
};
struct Q_76660 { int type; unsigned char a; unsigned char b; char pad6[2]; void* vt; void* obj; };
struct Msg_76660 { char pad[0x24]; int id; };
struct PC_76660 {
    char pad0[0x50];
    char input[0x40];
    Pri_76660 pri;
    char pad98[0x110 - 0x98];
    char h110[8];
    char h118[0x13C - 0x118];
    char f13C[4];
};
extern "C" {
extern void* g_Fader;
extern char D_004D9DE0[];
extern char D_004D9DC0[];
extern char D_0049CAE8[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void EventQueue_Admit(Q_76660* q);
void ActorFader_Start(float, void*, int);
int ObjHandle_Set(void*, int);
void cLList_cSafePtr_cGOBJ_Clear(void*);
void PlayerInput_ClearPendingBit11(void*);
}
static inline void Init_76660(Q_76660* q, void* obj)
{
    q->vt = D_004D9DE0;
    q->a = 1;
    q->type = 0xF;
    q->b = 0;
    q->vt = D_004D9DC0;
    q->obj = obj;
}
extern "C" int PlayerComp_HandleMessage(PC_76660* self, Msg_76660* msg)
{
    switch (msg->id) {
    case 2:
        self->pri.Set(4);
        self->pri.Set(2);
        break;
    case 3:
        self->pri.Clear(2);
        break;
    case 4:
        self->pri.Clear(4);
        self->pri.Set(3);
        break;
    case 5:
        self->pri.Clear(3);
        break;
    case 6:
        self->pri.Set(7);
        break;
    case 7:
        self->pri.Clear(7);
        break;
    case 8:
    case 9:
    case 11:
        break;
    case 10:
        self->pri.Set(6);
        break;
    case 12:
        self->pri.Clear(6);
        break;
    case 16: {
        Q_76660* q;
        ActorFader_Start(1.0f, g_Fader, 2);
        {
            AllocGuard guard;
            q = (Q_76660*)Mem_Alloc(0, 0x10, D_0049CAE8, 0x204);
        }
        if (q)
            Init_76660(q, self);
        EventQueue_Admit(q);
        ObjHandle_Set(self->h110, ObjHandle_Set(self->h118, 0));
        cLList_cSafePtr_cGOBJ_Clear(self->f13C);
        break;
    }
    case 17:
        PlayerInput_ClearPendingBit11(self->input);
        break;
    default:
        return 0;
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176660(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176660 */

/* merge_units: begin func_00176E60 */
#pragma push /* merge_units */
typedef struct { int a; int b; void* vt; } S_6E60;
extern void operator_delete(void* p);
S_6E60* cCBData_dtor(S_6E60* self, short flag)
{
    if (self) {
        self->vt = D_004D9DE0;
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176E60 */
