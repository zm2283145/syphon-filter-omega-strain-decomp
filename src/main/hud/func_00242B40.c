#include "types.h"
extern unsigned char D_00533880;
extern int D_00533888;
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
typedef struct { void* vtable; char pad[0x18]; int x1C; unsigned char x20; char pad21[3]; unsigned char x24; char pad25[3]; int key; char pad2C[0x18]; int id; unsigned char flag; unsigned char x49; } Msg_242B40;
typedef struct { int key; int x4; int id; int c; int d; } Ent_242B40;
typedef struct Node_242B40 { struct Node_242B40* prev; struct Node_242B40* next; Ent_242B40* ent; } Node_242B40;
typedef struct { Node_242B40* n; } It_242B40;

extern unsigned char D_005721C8;
extern char D_0051EE48[];
extern char D_004DE0F0[];
extern char D_004A7210[];
void Event_Construct(Msg_242B40* m, void* type);
void Transport_Send(int a, Msg_242B40* m, int b, int c);
void cMessage_dtor(Msg_242B40* m, int flags);
void func_00242E30(It_242B40* out, char* l);
void func_002426B0(It_242B40* out, char* l);
void func_002426A0(It_242B40* out, It_242B40* in);
void func_0015AF40(It_242B40* out, It_242B40* in);
void func_00138DA0(It_242B40* out, char* l, It_242B40* pos);
void func_003F45A0(int a, float f);
void func_003E8DE0(int a, int b);
void func_003E7EC0(int a, int b);
void func_003E9770(int a);
void Mem_Free(int pool, void* allocation, char* file, int line);

static inline void BeginI_(It_242B40* out, char* l) { It_242B40 t; func_00242E30(&t, l); func_002426A0(out, &t); }
static inline void Begin_(It_242B40* out, char* l) { BeginI_(out, l); }
static inline void EndI_(It_242B40* out, char* l) { It_242B40 t; func_002426B0(&t, l); func_002426A0(out, &t); }
static inline void End_(It_242B40* out, char* l) { EndI_(out, l); }
static inline void EraseI_(char* l, Node_242B40* n) { It_242B40 ac; It_242B40 a8; It_242B40 a4; ac.n = n; func_0015AF40(&a4, &ac); func_00138DA0(&a8, l, &a4); }

#pragma opt_dead_assignments off
int func_00242B40(char* o, int* key, int id, signed char flag, int send)
{
    Msg_242B40 m;
    It_242B40 it;
    It_242B40 b8;
    It_242B40 b4;
    int gap;
    if (D_005721C8 && send) {
        Event_Construct(&m, D_0051EE48);
        m.vtable = D_004DE0F0;
        m.x24 = 1;
        m.key = *key;
        m.x1C = 0x40;
        m.x20 = 4;
        m.id = id;
        m.flag = flag;
        m.x49 = 0;
        Transport_Send(0, &m, -1, -1);
        m.vtable = D_004DE0F0;
        cMessage_dtor(&m, 0);
    }
    { int* p = &gap; }
    Begin_(&b8, o + 0x6E8);
    for (it = b8; End_(&b4, o + 0x6E8), it.n != b4.n; it.n = it.n->next) {
        if (it.n->ent->key == *key && id == it.n->ent->id) {
            Ent_242B40* e;
            if (flag) {
                func_003F45A0(it.n->ent->c, 0.0f);
                func_003E8DE0(it.n->ent->c, 0);
            }
            e = it.n->ent;
            {
                if (D_00533880) Alloc_Lock(9);
                D_00533888++;
                if (e) {
                    if (e->c)
                        func_003E7EC0(e->c, 0);
                    if (e->d)
                        func_003E9770(e->d);
                }
                Mem_Free(0, e, D_004A7210, 0x55F);
                if (D_00533880) Alloc_Unlock(9);
                D_00533888--;
            }
            EraseI_(o + 0x6E8, it.n);
            return 1;
        }
    }
    return 0;
}













