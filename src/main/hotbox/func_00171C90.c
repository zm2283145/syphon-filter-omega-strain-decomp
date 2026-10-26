#include "types.h"
typedef struct { void* vt; char pad[0x1C]; unsigned char kind; char pad21[0x1F]; } Msg_1C90;
typedef struct { char pad[0x68]; int f68; } Leaf_1C90;
typedef struct { char pad[0x49]; unsigned char f49; char pad4A[0x4E]; PtrVec f98; } Item_1C90;
typedef struct { char pad[0x60]; PtrVec items; char pad6C[0x24]; int f90; int f94; } Obj_1C90;
void cGOBJTriggerEventMsg_ctor(Msg_1C90* m, int type, int a, int b, Obj_1C90* src);
int Event_Send(Msg_1C90*, void*, int);
int cMessage_dtor(Msg_1C90*, int);
int* cArray_cGameGOBJPtr_opIndex(PtrVec* v, int i);
int cArray_cGameGOBJPtr_Size(PtrVec* v);
int** std_vector_pod_int_data(PtrVec* v);
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern char D_004DAF10[];
static inline unsigned char IsLocal_1C90(void) { unsigned char v; if (g_IsMultiplayer) v = D_005721C0; else v = 1; return v; }
static inline Leaf_1C90* First_1C90(PtrVec* v) { return cArray_cGameGOBJPtr_Size(v) ? (Leaf_1C90*)*cArray_cGameGOBJPtr_opIndex(v, 0) : 0; }
#pragma push
#pragma opt_strength_reduction off
int cHotbox_v43(Obj_1C90* self, int arg)
{
    int i;
    switch (self->f90) {
    case 0x12:
    case 8:
    for (i = 0; i < self->items.count; i++) {
        Msg_1C90 m;
        cGOBJTriggerEventMsg_ctor(&m, 4, self->f94, arg, self);
        if (g_IsMultiplayer) {
            int owned = 0;
            if (self->f94 == -1 && ((Item_1C90*)self->items.data[i])->f49 == 0xE) {
                Item_1C90* it = (Item_1C90*)(*std_vector_pod_int_data(&self->items))[i];
                if (First_1C90(&it->f98)) {
                    Item_1C90* it2 = (Item_1C90*)self->items.data[i];
                    owned = First_1C90(&it2->f98)->f68 == 3;
                }
            }
            if (self->f90 == 0x12 || owned)
                m.kind = 1;
            else
                m.kind = IsLocal_1C90() ? 1 : 2;
        }
        Event_Send(&m, (void*)self->items.data[i], 0);
        m.vt = D_004DAF10;
        cMessage_dtor(&m, 0);
    }
    return 1;
    }
    return 0;
}
#pragma pop
