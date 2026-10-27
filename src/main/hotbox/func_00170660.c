#pragma cplusplus on
#include "types.h"
#include "hotbox_types.h"
#include "sfo_common_types.h"
#include "cmessage.h"
#include "vslot_pad.h"
union TrackerIter { HotboxListNode* p; };
struct HotMsg { CMSG_HEADER; int action; int code; int value; int who; };
struct HotboxV { VPAD32(a) VPAD32(b) VPAD2(c) virtual int Test(void*); };
extern "C" {
void std_list_deleter_voidPtr_erase_listdeleter(void*,void*,void*);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(void*,void*);
void std_list_cHotboxPtr_push_back(void*,void*);
void cLListIterator_cHotboxPtr_ctor_cLListIteratorR(void*,void*);
int opNe_cLListIteratorR_cLListIteratorR_2(void*,void*);
void cLList_cHotboxPtr_End(void*,void*);
void cLListIterator_cHotboxPtr_opInc(void*);
int* cLListIterator_cHotboxPtr_opMul(void*);
void cLListIterator_cHotboxPtr_opAssign(void*,void*);
void cLList_cHotboxPtr_Begin(void*,void*);
void cLListIterator_cHotboxPtr_ctor_void(void*);
void std_list_cHotboxPtr_generic_iterator_ctor(void*,void*);
void std_list_cHotboxPtr_generic_iterator_opCast(void*,void*);
void std_list_cHotboxPtr_begin(void*,void*);
void cLListIterator_cHotboxPtr_ctor_listR(void*,void*);
void std_list_cHotboxPtr_end_void(void*,void*);
extern char D_004D9940[],g_HotboxList[],D_004EE698[];
extern unsigned char D_005721C0,g_IsMultiplayer;
}
#pragma push
#pragma bool off
static inline int Active(SfGameObject* p){return p->activated && p->enabled && !p->removed;}
#pragma pop
extern "C" void cHotboxMan_Update(HotboxReceiver* arg0, void* arg1, void* arg2) {
    TrackerIter sp17C;
    TrackerIter sp178;
    cHotbox* sp174;
    HotboxListNode* sp170;
    TrackerIter sp16C;
    TrackerIter sp168;
    HotboxListNode* sp164;
    TrackerIter sp160;
    TrackerIter sp15C;
    HotboxListNode* sp158;
    TrackerIter sp154;
    HotboxListNode* sp150;
    HotboxListNode* sp14C;
    HotboxListNode* sp148;
    void* sp144;
    void* sp140;
    void* sp13C;
    void* sp138;
    void* sp134;
    void* sp130;
    void* sp12C;
    void* sp128;
    void* sp124;
    void* sp120;
    void* sp11C;
    void* sp118;
    TrackerIter sp114;
    HotMsg spE0;
    HotMsg spA0;
    float temp_f1;
    int temp_a0;
    int temp_a1;
    cHotbox* temp_s2;
    int temp_s1;
    int temp_s0;
    int temp_s2_2;
    int temp_s1_2;
    int var_v0;
    int var_v1;
    signed char var_v0_4;
    int var_v0_2;
    int var_v0_3;
    HotboxListNode* temp_a0_2;

    HotboxListNode* var_a0;

    temp_f1 = *(float*)&arg0->unk24 - 0.3f;
    *(float*)&arg0->unk24 = temp_f1;
    if (temp_f1 < 0.0f) {
        *(float*)&arg0->unk24 = 0.0f;
    }
    if (arg2 == 0) {
        arg2 = arg0->unk28;
    }
    std_list_cHotboxPtr_end_void(&sp140, &g_HotboxList);
    cLListIterator_cHotboxPtr_ctor_listR(&sp170, &sp140);
    std_list_cHotboxPtr_begin(&sp13C, arg2);
    cLListIterator_cHotboxPtr_ctor_listR(&sp16C, &sp13C);
    sp17C = sp16C;
    std_list_cHotboxPtr_end_void(&sp138, arg2);
    cLListIterator_cHotboxPtr_ctor_listR(&sp164, &sp138);
    sp168.p = sp164;
    sp178 = sp168;
    if (sp178.p != sp17C.p) {
        do {
            temp_s2 = (cHotbox*)sp17C.p->value;
            if (((HotboxV*)temp_s2)->Test(arg1) == 0 || (var_v0=Active((SfGameObject*)temp_s2), var_v0==0)) {

                if (g_IsMultiplayer != 0) {
                    if (g_IsMultiplayer != 0) {
                        var_v0_2 = D_005721C0;
                    } else {
                        var_v0_2 = 1;
                    }
                    if (var_v0_2 != 0) {
                        goto block_19;
                    }
                } else {
block_19:
                    temp_s2->occupants = (int) (temp_s2->occupants - 1);
                    if (temp_s2->occupants < 0) {
                        temp_s2->occupants = 0;
                    }
                }
                temp_s1 = arg0->unk20;
                temp_s0 = temp_s2->type;
                cMessage_ctor_cMessageNameR(&spE0, &D_004EE698);
                spE0.vtable = D_004D9940;
                spE0.action = 2;
                spE0.code = temp_s0;
                spE0.who = temp_s1;
                spE0.value = 0;
                temp_a1 = temp_s2->type;
                if ((temp_a1 == 5) || (temp_a1 == 0x12)) {
                    spE0.kind = 1;
                } else {
                    spE0.kind = 2;
                }
                spE0.flags = 0x40;
                QueueMessage_cMessageR_cSystemP_int(&spE0, temp_s2, 0);
                spE0.vtable = D_004D9940;
                cMessage_dtor(&spE0, 0);
                std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&sp144, &sp17C);
                std_list_cHotboxPtr_generic_iterator_opCast(&sp130, &sp144);
                std_list_deleter_voidPtr_erase_listdeleter(&sp134, arg2, &sp130);
                std_list_cHotboxPtr_generic_iterator_ctor(&sp148, &sp134);
                sp160.p = sp148;
                sp17C = sp160;
            } else {
                sp17C.p = sp17C.p->next;
            }
        } while (sp178.p != sp17C.p);
    }
    std_list_cHotboxPtr_end_void(&sp12C, &g_HotboxList);
    cLListIterator_cHotboxPtr_ctor_listR(&sp158, &sp12C);
    sp15C.p = sp158;
    sp114 = sp15C;
    std_list_cHotboxPtr_begin(&sp128, &g_HotboxList);
    cLListIterator_cHotboxPtr_ctor_listR(&sp154, &sp128);
    sp17C = sp154;
    var_a0 = sp17C.p;
    if (var_a0 != sp114.p) {
        do {
            sp174 = (cHotbox*)var_a0->value;
            var_v1 = Active((SfGameObject*)sp174);
            if ((var_v1 != 0) && (((HotboxV*)sp174)->Test(arg1) != 0)) {
                std_list_cHotboxPtr_end_void(&sp124, arg2);
                cLListIterator_cHotboxPtr_ctor_listR(&sp14C, &sp124);
                cLListIterator_cHotboxPtr_ctor_void(&sp120);
                cLList_cHotboxPtr_Begin(&sp11C, arg2);
                cLListIterator_cHotboxPtr_opAssign(&sp120, &sp11C);
                cLList_cHotboxPtr_End(&sp118, arg2);
                if (opNe_cLListIteratorR_cLListIteratorR_2(&sp120, &sp118) != 0) {
loop_40:
                    int found=*cLListIterator_cHotboxPtr_opMul(&sp120);
                    if (found != (int)sp174) {
                        cLListIterator_cHotboxPtr_opInc(&sp120);
                        cLList_cHotboxPtr_End(&sp118, arg2);
                        if (opNe_cLListIteratorR_cLListIteratorR_2(&sp120, &sp118) != 0) {
                            goto loop_40;
                        }
                    }
                }
                cLListIterator_cHotboxPtr_ctor_cLListIteratorR(&sp150, &sp120);
                if (sp150 == sp14C) {
                    if (g_IsMultiplayer != 0) {
                        if (g_IsMultiplayer != 0) {
                            var_v0_3 = D_005721C0;
                        } else {
                            var_v0_3 = 1;
                        }
                        if (var_v0_3 != 0) {
                            goto block_49;
                        }
                    } else {
block_49:
                        cHotbox* occupied=sp174;
                        occupied->occupants = occupied->occupants + 1;
                        if (3 < occupied->occupants) {
                            occupied->occupants = 3;
                        }
                    }
                    std_list_cHotboxPtr_push_back(arg2, &sp174);
                    temp_s2_2 = arg0->unk20;
                    temp_s1_2 = sp174->type;
                    cMessage_ctor_cMessageNameR(&spA0, &D_004EE698);
                    spA0.vtable = D_004D9940;
                    spA0.action = 0;
                    spA0.code = temp_s1_2;
                    spA0.who = temp_s2_2;
                    spA0.value = 0;
                    temp_a0 = sp174->type;
                    if (temp_a0 == 5 || temp_a0 == 0x12) {
                        spA0.kind=1;
                    } else {
                        spA0.kind=2;
                    }
                    spA0.flags = 0x40;
                    QueueMessage_cMessageR_cSystemP_int(&spA0, sp174, 0);
                    spA0.vtable = D_004D9940;
                    cMessage_dtor(&spA0, 0);
                }
            }
            temp_a0_2 = sp17C.p->next;
            sp17C.p = temp_a0_2;
            var_a0 = ((TrackerIter volatile*)&sp17C)->p;
        } while (var_a0 != sp114.p);
    }
}
