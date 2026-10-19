#pragma push
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma cplusplus on
#include "types.h"
#include "hotbox_types.h"
#include "sfo_common_types.h"
#include "cmessage.h"
struct EnableMsg { CMSG_HEADER; int player; } __attribute__((aligned(16)));
struct HotMsg { CMSG_HEADER; int action; unsigned int code; int value; void* who; } __attribute__((aligned(16)));
struct TeleportMsg { CMSG_HEADER; signed char mode; char pad25[0xB]; float matrix[16]; } __attribute__((aligned(16)));
struct SimpleMsg { CMSG_HEADER; int object; int unknown; } __attribute__((aligned(16)));
extern "C" {
void EnvController_ActivateFirst(int,void*);
void* Mtx_GetIdentity();
void Node_GetTranslation(void*,void*);
int Player_GetIndex(int);
void Vec4_CopyAsPoint(void*,void*);
void World_PushObjectFromAction(void*,void*);
void cGOBJTriggerEventMsg_ctor(void*,int,int,void*,int);
void* Mtx_SetRotationTranslation(void*,void*,void*);
int* func_00172990(PtrVec*,int);
extern char D_004D9360[],D_004D9940[],D_004DAF10[],D_004DB8D0[],D_004E0880[],D_004EE698[],D_004F7930[],g_Game[],g_TeleportMsgClass[],g_cEnableMsgClass[];
extern int D_004FFBD4;
extern void* g_LocalPlayer;
}
extern "C" void Hotbox_Type2Receiver(cHotbox *arg0, SfGameObject *arg1) {
    EnableMsg sp2B0;
    Vec4 sp2A0;
    HotMsg sp260;
    HotMsg sp220;
    HotMsg sp1E0;
    HotMsg sp1A0;
    TeleportMsg sp130;
    HotMsg spF0;
    HotMsg spB0;
    SimpleMsg sp80;
    Vec4 sp70;
    TeleportMsg* tp;

    int temp_s0_2;
    int temp_s0_3;
    int temp_s0_4;
    int temp_s0_5;
    int temp_s0_6;
    int var_s1;
    int var_s1_2;
    int var_s5;
    int var_s4;
    unsigned int temp_s1;
    SfGameObject* temp_a1;
    void *temp_s1_2;
    void* temp_s0;

    temp_s1 = arg0->type;
    switch (temp_s1) {
    case 1:
    case 6:
        var_s5 = -1;
        if (arg1 != 0) {
            var_s5 = Player_GetIndex(arg1->id);
        }
        var_s4 = 0;
        if (0 < arg0->unk60.count) {
            do {
                Event_Construct(&sp2B0, &g_cEnableMsgClass);
                sp2B0.vtable = D_004E0880;
                sp2B0.player = var_s5;
                sp2B0.flags = 0x40;
                sp2B0.kind = 1;
                Event_Send(&sp2B0, (void*)arg0->unk60.data[var_s4], 0);
                sp2B0.vtable = D_004E0880;
                cMessage_dtor(&sp2B0, 0);
                var_s4 += 1;
            } while (var_s4 < arg0->unk60.count);
            goto done;
        }
    default:
        goto done;
    case 2:
        temp_s1_2 = g_LocalPlayer;
        Node_GetTranslation(&sp2A0, (void*)*arg0->unk60.data);
        tp=&sp130;
        Event_Construct(tp, &g_TeleportMsgClass);
        sp130.mode = 0;
        sp130.vtable = D_004D9360;
        temp_s0 = Mtx_GetIdentity();
        Vec4_CopyAsPoint(&sp70, &sp2A0);
        void* dest=(char*)tp+0x30;
        // Empty scheduling barrier: retain the destination address before call setup.
        asm { .set reorder }
        Mtx_SetRotationTranslation(dest,temp_s0,&sp70);
        Event_Send(tp, temp_s1_2, 0);
        sp130.vtable = D_004D9360;
        cMessage_dtor(tp, 0);
        goto done;
    case 3:
        var_s1 = 0;
        if (0 < arg0->unk60.count) {
            do {
                cGOBJTriggerEventMsg_ctor(&spF0, 0, 0, arg0,0);
                Event_Send(&spF0, (void*)arg0->unk60.data[var_s1], 0);
                spF0.vtable = D_004DAF10;
                cMessage_dtor(&spF0, 0);
                var_s1 += 1;
            } while (var_s1 < arg0->unk60.count);
            goto done;
        }
        break;
    case 4:
        var_s1_2 = 0;
        if (0 < arg0->unk60.count) {
            do {
                cGOBJTriggerEventMsg_ctor(&sp260, 1, *(int*)arg0->pad94, arg0,0);
                Event_Send(&sp260, (void*)arg0->unk60.data[var_s1_2], 0);
                sp260.vtable = D_004DAF10;
                cMessage_dtor(&sp260, 0);
                var_s1_2 += 1;
            } while (var_s1_2 < arg0->unk60.count);
            goto done;
        }
        break;
    case 5:
        if (arg0->unk60.count > 0) {
            EnvController_ActivateFirst(D_004FFBD4, (void*)*arg0->unk60.data);
            goto done;
        }
        break;
    case 8:
    case 12:
    case 14:
    case 18:
        temp_s0_2 = *(int*)arg0->pad94;
        Event_Construct(&spB0, &D_004EE698);
        spB0.vtable = D_004D9940;
        spB0.code = temp_s1;
        spB0.value = temp_s0_2;
        spB0.who = arg1;
        spB0.action = 0;
        Event_Send(&spB0, arg1, 0);
        spB0.vtable = D_004D9940;
        cMessage_dtor(&spB0, 0);
        goto done;
    case 13:
        temp_s0_3 = *(int*)arg0->pad94;
        Event_Construct(&sp220, &D_004EE698);
        sp220.vtable = D_004D9940;
        sp220.code = temp_s1;
        sp220.value = temp_s0_3;
        sp220.kind = 5;
        sp220.flags = 0x40;
        sp220.who = arg1;
        sp220.action = 0;
        Event_Send(&sp220, arg1, 0);
        sp220.vtable = D_004D9940;
        cMessage_dtor(&sp220, 0);
        goto done;
    case 10:
        if (arg0->unk60.count != 0) {
            temp_s0_4 = *func_00172990(&arg0->unk60, 0);
            Event_Construct(&sp80, &D_004F7930);
            sp80.vtable = D_004DB8D0;
            sp80.object = temp_s0_4;
            sp80.unknown = 0;
            Event_Send(&sp80, arg1, 0);
            sp80.vtable = D_004DB8D0;
            cMessage_dtor(&sp80, 0);
            goto done;
        }
        break;
    case 11:
        if (arg0->unk60.count != 0) {
            temp_a1 = (SfGameObject*)*arg0->unk60.data;
            if (temp_a1->classByte == 9) {
                World_PushObjectFromAction(&g_Game, temp_a1);
                goto done;
            }
        }
        break;
    case 9:
        temp_s0_5 = *(int*)arg0->pad94;
        Event_Construct(&sp1E0, &D_004EE698);
        sp1E0.vtable = D_004D9940;
        sp1E0.code = temp_s1;
        sp1E0.value = temp_s0_5;
        sp1E0.kind = 8;
        sp1E0.flags = 0x40;
        sp1E0.who = arg1;
        sp1E0.action = 0;
        Event_Send(&sp1E0, arg1, 0);
        sp1E0.vtable = D_004D9940;
        cMessage_dtor(&sp1E0, 0);
        goto done;
    case 15:
    case 16:
        temp_s0_6 = ((SfGameObject*)*arg0->unk60.data)->id;
        Event_Construct(&sp1A0, &D_004EE698);
        sp1A0.vtable = D_004D9940;
        sp1A0.code = temp_s1;
        sp1A0.value = temp_s0_6;
        sp1A0.kind = 8;
        sp1A0.flags = 0x40;
        sp1A0.who = arg1;
        sp1A0.action = 0;
        Event_Send(&sp1A0, arg1, 0);
        sp1A0.vtable = D_004D9940;
        cMessage_dtor(&sp1A0, 0);
        break;
    }
done:
    return;
}

#pragma pop
