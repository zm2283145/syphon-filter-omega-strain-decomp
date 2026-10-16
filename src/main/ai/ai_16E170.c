/*
 * main/ai: range (2 files, 0016E170-0016E1A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "sfo_ai_types.h"
#include "sfo_actor_types.h"
#include "hotbox_types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0016E170 */
#pragma push /* merge_units */
typedef struct { int x0; int x4; int x8; unsigned char xC; } Req16E170;
unsigned char NpcAi_RequestMode(Req16E170* p, int v, int pri) {
    unsigned char r = 0;
    if (pri >= p->x8) {
        p->x4 = v;
        p->xC = 1;
        r = 1;
        p->x8 = pri;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016E170(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016E170 */

/* merge_units: begin func_0016E1A0 */
#pragma push /* merge_units */
#pragma cplusplus on
union NextIter {HotboxListNode* p;};
struct ObjectV { VPAD32(a) VPAD32(b) virtual int Life(); };
struct ControllerV { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); VPAD4(d) VPAD2(e) virtual int Enemy(SfGameObject*); VPAD4(f) VPAD1(g) virtual int Kind(); };
extern "C" {
    SfAwarenessRecord* NpcPerception_SensedRecord(SfAiPerception*,SfGameObject*);
    SfGameObject* PlayerSlots_Get(int);
    void func_0016B2D0(void*,void*);
    void func_0016B300(void*,void*);
    void func_0016B310(void*,void*);
    void func_0016E860(void*,int);
    void List_Begin_16E880(void*,void*);
    extern void* D_0049D010;
    extern char D_004EA190[];
    extern SfAiComponent* D_004FFC0C;
    extern unsigned char D_005721C8;
}
#pragma push
#pragma bool off
static inline int Active(SfGameObject* p) { return p->activated && p->enabled && !p->removed; }
#pragma pop
#pragma push
#pragma opt_common_subs off
extern "C" SfGameObject* NpcPerception_NextCandidate(SfAiPerception* arg0, SfGameObject* arg1) {
    NextIter spCC;
    HotboxListNode* spC8;
    HotboxListNode* spC4;
    NextIter spC0;
    HotboxListNode* spBC;
    HotboxListNode* spB8;
    NextIter spB4;
    HotboxListNode* spB0;
    HotboxListNode* spAC;
    int spA8;
    void* spA4;
    void* spA0;
    void* sp9C;
    void* sp98;
    void* sp94;
    void* sp90;
    void* sp8C;
    NextIter sp88;
    bool var_a0_2;
    bool var_a0_3;
    bool var_a2;
    int var_s6;
    int var_v0_2;
    int var_v0_3;
    ControllerV* temp_a0;
    ControllerV* temp_a0_2;
    ControllerV* temp_a0_3;
    ControllerV* temp_a0_4;
    ControllerV* temp_a0_5;
    ControllerV* temp_a0_6;
    ControllerV* temp_a0_7;
    ControllerV* temp_a0_8;
    SfWeakHandle* temp_a1;
    SfGameObject* var_s3;
    void* container;
    bool var_s1;
    int var_s1_2;
    SfGameObject* temp_s0;
    SfGameObject* temp_s0_2;
    SfGameObject* temp_s0_3;
    SfGameObject* temp_s0_4;
    SfGameObject* temp_v0;
    SfAwarenessRecord* temp_v0_2;
    SfGameObject* temp_v0_3;
    SfAwarenessRecord* temp_v0_4;
    SfWeakHandle* temp_v1;
    SfWeakHandle* temp_v1_2;
    SfGameObject* var_a0;
    SfGameObject* var_v0;

    container = D_004EA190;
    var_s3 = 0;
    List_Begin_16E880(&spA8, container);
    func_0016E860(&spAC, spA8);
    spCC.p = spAC;
    if (arg1 != 0) {
        temp_a0 = (ControllerV*)arg1->controller;
        if (temp_a0 != 0) {
            if ((temp_a0->Kind() & 255) == 1 || (((ControllerV*)arg1->controller)->Kind() & 255) == 2) {
                goto candidate_test;
            candidate_body:
                temp_a1 = (SfWeakHandle*)spCC.p->value;
                var_a0 = (SfGameObject*)temp_a1->object;
                { bool nil = !var_a0; var_a2 = true;
                    if(!nil) if(var_a0->id != temp_a1->id) var_a2=false; }
                var_v0 = var_a2 ? var_a0 : 0;
                if (var_v0 != 0) {
                    if (var_a0 && var_a0->id != temp_a1->id) var_a0=0;
                    if (var_a0 == arg1) goto candidate_found;
                }
                spCC.p = spCC.p->next;
            candidate_test:
                func_0016B2D0(&spA4, container);
                func_0016B300(&spC8, &spA4);
                if (spCC.p != spC8) goto candidate_body;
            candidate_found:
                func_0016B2D0(&spA0, container);
                func_0016B300(&spC4, &spA0);
                if (spCC.p == spC4) {
                    func_0016B310(&sp9C, container);
                    func_0016B300(&spC0, &sp9C);
                    spCC = spC0;
                } else {
                    spCC.p = spCC.p->next;
                }
            } else if (D_005721C8) {
                temp_a0_3=(ControllerV*)arg1->controller;
                if(temp_a0_3->IsPlayer()) {
                    var_s1=0;var_s6=0;
                    do {
                        temp_v0=PlayerSlots_Get(var_s6);
                        if(temp_v0) {
                            if(temp_v0->id == arg1->id) var_s1=1;
                            else if(var_s1 && ((ControllerV*)arg0->component)->Enemy(temp_v0)) {
                                var_s3=temp_v0;break;
                            }
                        }
                        var_s6++;
                    } while(var_s6<4);
                }
            }
        }
    }
    if (var_s3 == 0) {
        func_0016B2D0(&sp98, container);
        func_0016B300(&spBC, &sp98);
        if (spCC.p != spBC) {
        loop_37:
            temp_v1 = (SfWeakHandle*)spCC.p->value;
            temp_s0 = (SfGameObject*)temp_v1->object;
            var_a0_2 = 1;
            bool null_temp_s0 = !temp_s0;
            if (!null_temp_s0 && (temp_s0->id != temp_v1->id)) {
                var_a0_2 = 0;
            }
            temp_s0_2 = var_a0_2 ? temp_s0 : 0;
            if ((temp_s0_2 != 0) && (((SfAiComponent*)arg0->component)->actor != temp_s0_2)) {
                if ((((ObjectV*)temp_s0_2)->Life() & 0xFF) != 3) {
                    temp_a0_5 = (ControllerV*)arg0->component;
                    if (temp_a0_5->Enemy(temp_s0_2) != 0) {
                        var_s3 = temp_s0_2;
                    } else {
                        goto block_56;
                    }
                } else if (temp_s0_2->classWord == D_0049D010) {
                    var_v0_2 = Active(temp_s0_2);
                    if (var_v0_2 != 0) {
                        var_v0_2 = ((SfActor*)temp_s0_2)->pickupable != 0;
                    }
                    if ((var_v0_2 != 0) && ((temp_v0_2 = NpcPerception_SensedRecord(arg0, temp_s0_2), (temp_v0_2 == 0)) || (temp_v0_2->deadBodyNoticeSent == 0))) {
                        var_s3 = temp_s0_2;
                    } else {
                        goto block_56;
                    }
                } else {
                    goto block_56;
                }
            } else {
            block_56:
                spCC.p = spCC.p->next;
                func_0016B2D0(&sp98, container);
                func_0016B300(&spBC, &sp98);
                if (spCC.p == spBC) {

                } else {
                    goto loop_37;
                }
            }
        }
        func_0016B2D0(&sp94, container);
        func_0016B300(&spB8, &sp94);
        if ((spCC.p == spB8) && (var_s3 == 0)) {
            if (D_005721C8 != 0) {
                var_s1_2 = 0;
            loop_62:
                temp_v0_3 = PlayerSlots_Get(var_s1_2);
                if ((temp_v0_3 != 0) && ((temp_a0_6 = (ControllerV*)arg0->component, (temp_a0_6->Enemy(temp_v0_3) != 0)) || (arg0->flags2 & 1))) {
                    var_s3 = temp_v0_3;
                } else {
                    var_s1_2 += 1;
                    if (var_s1_2 >= 4) {

                    } else {
                        goto loop_62;
                    }
                }
            } else {
                temp_a0_7 = (ControllerV*)arg0->component;
                if (temp_a0_7->Enemy((SfGameObject*)D_004FFC0C->actor) == 0) {
                    if (arg0->flags2 & 1) {
                        goto block_71;
                    }
                } else {
                block_71:
                    var_s3 = (SfGameObject*)D_004FFC0C->actor;
                }
            }
            if (var_s3 == 0) {
                func_0016B310(&sp90, container);
                func_0016B300(&spB4, &sp90);
                sp88 = spB4;
                func_0016B2D0(&sp8C, container);
                func_0016B300(&spB0, &sp8C);
                if (sp88.p != spB0) {
                loop_74:
                    temp_v1_2 = (SfWeakHandle*)sp88.p->value;
                    temp_s0_3 = (SfGameObject*)temp_v1_2->object;
                    var_a0_3 = 1;
                    bool null_temp_s0_3 = !temp_s0_3;
                    if (!null_temp_s0_3 && (temp_s0_3->id != temp_v1_2->id)) {
                        var_a0_3 = 0;
                    }
                    temp_s0_4 = var_a0_3 ? temp_s0_3 : 0;
                    if ((temp_s0_4 != 0) && (((SfAiComponent*)arg0->component)->actor != temp_s0_4)) {
                        if ((((ObjectV*)temp_s0_4)->Life() & 0xFF) != 3) {
                            temp_a0_8 = (ControllerV*)arg0->component;
                            if (temp_a0_8->Enemy(temp_s0_4) != 0) {
                                var_s3 = temp_s0_4;
                            } else {
                                goto block_93;
                            }
                        } else if (temp_s0_4->classWord == D_0049D010) {
                            var_v0_3 = Active(temp_s0_4);
                            if (var_v0_3 != 0) {
                                var_v0_3 = ((SfActor*)temp_s0_4)->pickupable != 0;
                            }
                            if ((var_v0_3 != 0) && ((temp_v0_4 = NpcPerception_SensedRecord(arg0, temp_s0_4), (temp_v0_4 == 0)) || (temp_v0_4->deadBodyNoticeSent == 0))) {
                                var_s3 = temp_s0_4;
                            } else {
                                goto block_93;
                            }
                        } else {
                            goto block_93;
                        }
                    } else {
                    block_93:
                        sp88.p = sp88.p->next;
                        func_0016B2D0(&sp8C, container);
                        func_0016B300(&spB0, &sp8C);
                        if (sp88.p == spB0) {

                        } else {
                            goto loop_74;
                        }
                    }
                }
            }
        }
        if (var_s3 == 0) {
            var_s3 = arg1;
        }
    }
    return var_s3;
}

#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016E1A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016E1A0 */
