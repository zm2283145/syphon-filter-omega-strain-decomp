#pragma cplusplus on
#include "types.h"
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
extern void* D_004FFC38;
extern char D_004D9DE0[];
extern char D_004D9DC0[];
extern char D_0049CAE8[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void EventQueue_Admit(Q_76660* q);
void ActorFader_Start(float, void*, int);
int ObjHandle_Set(void*, int);
void func_00176EB0(void*);
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
        ActorFader_Start(1.0f, D_004FFC38, 2);
        {
            AllocGuard guard;
            q = (Q_76660*)Mem_Alloc(0, 0x10, D_0049CAE8, 0x204);
        }
        if (q)
            Init_76660(q, self);
        EventQueue_Admit(q);
        ObjHandle_Set(self->h110, ObjHandle_Set(self->h118, 0));
        func_00176EB0(self->f13C);
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
