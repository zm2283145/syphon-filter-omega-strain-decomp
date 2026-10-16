#pragma cplusplus on
#include "sfo_ai_types.h"
#include "hotbox_types.h"
#include "vslot_pad.h"
typedef SfGameObject Actor;
union ThinkIter { HotboxListNode* p; };
struct ThinkFlags { unsigned char a:7; unsigned char tested:1; };
struct ObjectV { VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) virtual bool Type(void*); VPAD2(e) VPAD1(f) virtual int Life(); };
struct ControllerV { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); VPAD4(d) VPAD2(e) virtual int Enemy(Actor*); };
extern "C" {
Actor* ActorRef_Copy(SfWeakHandle*);
void NpcPerception_FindRecord(void*,void*,Actor*);
Actor* NpcPerception_NextCandidate(SfAiPerception*,Actor*);
void NpcPerception_SetTarget(SfAiPerception*,Actor*,int);
void NpcPerception_UpdateRecords(SfAiPerception*,float);
void NpcPerception_VisibilityTest(SfAiPerception*,Actor*);
void __register_global_object(void*,void*,void*);
void func_0016BB80(void*,void*);
void func_0016BB90(void*,void*);
void func_0016BBA0(void*,void*);
void StaticInit_FloorContactVecs(void*,int);
extern signed char D_004EE590;
extern char D_004EE598[],D_004EE5B0[];
}
#pragma push
#pragma bool off
static inline int Active(Actor* p) { return p->activated && p->enabled && !p->removed; }


#pragma pop
static inline bool Dead(int life) { bool yes=true; if ((unsigned)(life-2)>1U) yes=false; return yes; }
static inline bool Player(ControllerV* p) { bool yes=false; if(p) if(p->IsPlayer()) yes=true; return yes; }
static inline bool Player2(ControllerV* p) { if(p) if(p->IsPlayer()) return true; return false; }
static inline Actor* WGet(bool isNull, Actor* o, int id){ if (!isNull) if (o->id != id) return 0; return o; }
static inline Actor* WGet2(bool isNull, Actor* o, int id){ if (!isNull) if (o->id != id) o = 0; return o; }
extern "C" void NpcPerception_Think(SfAiPerception* arg0, float dt) {
    ThinkIter spBC;
    ThinkIter spB8;
    ThinkIter spB4;
    ThinkIter spB0;
    ThinkIter spAC;
    int spA8;
    void* spA4;
    void* spA0;
    void* sp9C;
    int *var_v0_2;
    bool var_a3;
    bool var_a3_2;
    Actor* temp_a1;
    bool var_a0_2;
    bool var_a0_3;
    bool var_a1;
    bool var_a1_2;
    bool temp_a1_2;
    bool temp_a2;
    int var_v0;
    int var_v1;
    bool var_v1_2;
    ControllerV* temp_a0_2;
    ControllerV* temp_a0_3;
    ControllerV* temp_a0_4;
    Actor* temp_v0;
    Actor* temp_v0_2;
    Actor* temp_a0;
    Actor* temp_a0_5;
    bool var_a0;
    Actor* temp_a1_3;
    Actor* temp_v0_3;
    Actor* var_a1_3;
    Actor* var_a2;
    Actor* var_v1_3;
    Actor* var_v1_4;
    float var_f21;
    float var_f20;
    bool var_s6;
    Actor* var_s4;
    SfAwarenessRecord* temp_s3;
    bool var_s2;
    Actor* temp_s1;
    Actor* temp_s1_2;
    bool var_s0;


    var_a1 = 1;
    var_s6 = 0;
    temp_a0 = (Actor*)arg0->target.object;
    bool null_temp_a0 = !temp_a0;
    if (!null_temp_a0 && (temp_a0->id != arg0->target.id)) {
        var_a1 = 0;
    }
    if ((var_a1 ? temp_a0 : 0) != 0) {
        temp_v0 = ActorRef_Copy(&arg0->target);
        var_v1 = Active(temp_v0);
        if ((var_v1 != 0) && (temp_v0_2 = ActorRef_Copy(&arg0->target), ((((ObjectV*)temp_v0_2)->Life() & 0xFF) != 3))) {
            temp_a1 = (Actor*)arg0->target.object;
            var_a0 = 1;
            bool null_temp_a1 = !temp_a1;
    if (!null_temp_a1 && (temp_a1->id != arg0->target.id)) {
                var_a0 = 0;
            }
            if (((ControllerV*)arg0->component)->Enemy(var_a0 ? temp_a1 : 0) == 0) {
                goto block_14;
            }
        } else {
block_14:
            NpcPerception_SetTarget(arg0, 0, 0x14);
        }
    }
    NpcPerception_UpdateRecords(arg0,dt);
    var_f21 = 0.0f;
    var_s4 = 0;
    func_0016BBA0(&spA4, &arg0->records);
    func_0016BB90(&spB4, &spA4);
    spBC = spB4;
    func_0016BB80(&spA0, &arg0->records);
    func_0016BB90(&spB0, &spA0);
    if (spBC.p != spB0.p) {
        do {
            temp_s3 = (SfAwarenessRecord*)spBC.p->value;
            temp_s1 = (Actor*)temp_s3->object;
            var_a0_2 = 1;
            bool null_temp_s1 = !temp_s1;
    if (!null_temp_s1 && (temp_s1->id != temp_s3->id)) {
                var_a0_2 = 0;
            }
            temp_s1_2 = var_a0_2 ? temp_s1 : 0;
            if (temp_s1_2 != 0) {
                var_v0 = Active(temp_s1_2);
                if (var_v0 != 0) {
                    var_v1_2 = Dead(((ObjectV*)temp_s1_2)->Life() & 0xFF);
                    if (!var_v1_2) {
                        temp_a0_3 = (ControllerV*)arg0->component;
                        if (temp_a0_3->Enemy(temp_s1_2) != 0) {
                            temp_a0_4 = (ControllerV*)temp_s1_2->controller;
                            var_f20 = 0.0f;
                            var_s2 = 1;
                            var_s0 = 0;
                            if (temp_a0_4 == 0) goto skipP;
                            if (temp_a0_4->IsPlayer() == 0) goto skipP;
                            var_s0 = 1;
                            skipP:
                            if (var_s0) {
                                if (D_004EE590 == 0) {
                                    __register_global_object(D_004EE5B0, (void*)&StaticInit_FloorContactVecs, D_004EE598);
                                    D_004EE590 = 1;
                                }
                                var_s2 = ((ObjectV*)temp_s1_2)->Type(D_004EE5B0);
                            }
                            if (var_s2) {
                                if (temp_s3->age < 10.0f) {
                                    var_f20 = temp_s3->salience + (temp_s3->threat + temp_s3->visibility);
                                }
                                temp_a0_5 = (Actor*)arg0->target.object;
                                var_a1_2 = 1;
                                bool null_temp_a0_5 = !temp_a0_5;
    if (!null_temp_a0_5 && (temp_a0_5->id != arg0->target.id)) {
                                    var_a1_2 = 0;
                                }
                                if (temp_s1_2 == (var_a1_2 ? temp_a0_5 : 0)) {
                                    var_f20 *= 1.1f;
                                }
                                if (!(var_f20 <= var_f21)) {
                                    var_f21 = var_f20;
                                    var_s4 = temp_s1_2;
                                }
                            }
                        }
                    }
                }
            }
            spBC.p = spBC.p->next;
            func_0016BB80(&spA0, &arg0->records);
            func_0016BB90(&spB0, &spA0);
        } while (spBC.p != spB0.p);
    }
    if (!(var_f21 <= 0.0f)) {
        NpcPerception_SetTarget(arg0, var_s4, 0x14);
    } else {
        var_a2 = (Actor*)arg0->target.object;
        temp_a1_2 = !var_a2;
        var_a3 = 1;
        if ((temp_a1_2 == 0) && (var_a2->id != arg0->target.id)) {
            var_a3 = 0;
        }
        var_v1_3 = var_a3 ? var_a2 : 0;
        if (var_v1_3 != 0) {
            NpcPerception_FindRecord(&spB8, &arg0->records, (temp_a1_2 || var_a2->id == arg0->target.id) ? var_a2 : 0);
            func_0016BB80(&sp9C, &arg0->records);
            func_0016BB90(&spAC, &sp9C);
            if (spB8.p == spAC.p) {
                NpcPerception_SetTarget(arg0, 0, 0x14);
            }
        }
    }
    var_a1_3 = (Actor*)arg0->target.object;
    temp_a2 = !var_a1_3;
    var_a3_2 = 1;
    if ((temp_a2 == 0) && (var_a1_3->id != arg0->target.id)) {
        var_a3_2 = 0;
    }
    var_v1_4 = var_a3_2 ? var_a1_3 : 0;
    if ((var_v1_4 != 0) && (((ThinkFlags*)&arg0->flags)->tested == 0)) {
        Actor* vt = (temp_a2 || var_a1_3->id == arg0->target.id) ? var_a1_3 : 0;
        var_s6 = 1;
        NpcPerception_VisibilityTest(arg0, vt);
        ((ThinkFlags*)&arg0->flags)->tested = 1;
    }
    if (!var_s6) {
        temp_a1_3 = (Actor*)arg0->nextCandidate.object;
        var_a0_3 = 1;
        bool null_temp_a1_3 = !temp_a1_3;
    if (!null_temp_a1_3 && (temp_a1_3->id != arg0->nextCandidate.id)) {
            var_a0_3 = 0;
        }
        temp_v0_3 = NpcPerception_NextCandidate(arg0, var_a0_3 ? temp_a1_3 : 0);
        if (temp_v0_3 != 0) {
            arg0->nextCandidate.object = temp_v0_3;
            if (temp_v0_3 != 0) {
                var_v0_2 = &temp_v0_3->id;
            } else {
                spA8 = -1;
                var_v0_2 = &spA8;
            }
            arg0->nextCandidate.id = (int) *var_v0_2;
            NpcPerception_VisibilityTest(arg0, temp_v0_3);
        }
        ((ThinkFlags*)&arg0->flags)->tested = 0;
    }
}
