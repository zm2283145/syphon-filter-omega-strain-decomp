#pragma push
// Preserve the retail register allocation across the two navigation paths.
#pragma opt_dead_assignments off
#pragma inline_depth(8)
#pragma cplusplus on
#include "types.h"
#include "cmessage.h"
struct EventMessage { CMSG_HEADER; int value; int agent; };
#include "gui_grid_types.h"
typedef GuiGridInput Input;
struct Screen { char pad0[0x14]; unsigned short unk14; char pad16[0x32]; int unk48; void* unk4C; };
#include "vslot_pad.h"
struct Interface { VPAD16(a) VPAD2(b) VPAD1(c) virtual int Valid(); };
struct Entity { char pad0[0xC]; unsigned int unkC; char pad10[0x48]; Interface* unk58; };
struct State { char pad0[0x30]; Entity* unk30; };
extern "C" {
    void* Gui_GetScreenStack();
    char* Loc_GetTextById(int);
    char* Loc_LookupText(char*);
    void Notify_Insert(int,char*,void*,int,int=0);
    char* String_Copy(char*,char*);
    int func_0012F5B0(void*,int);
    void func_002426E0(int);
    char* Loc_GetStoredKey(int);
    void GuiTextWidget_SetText(void*,char*,int);
    void GuiWidget_SendEvent(void*,void*,int,int,int=0);
    int sprintf(char*,const char*,...);
    extern unsigned char D_0048BD10[];
    extern char D_0048BD14[],D_004ABEB8[],D_004ABEC8[],D_004ABED0[],D_004ABED8[],D_004ABEE8[],D_004ABEF8[],D_004DCF10[],D_004DE630[],D_004FFB50[],D_0052ACD8[],D_00587C90[];
    extern State* D_004FFC0C;
    extern int D_004FFC2C;
    extern unsigned char D_005721C8;
}
static inline unsigned char B13Has(Entity* e) {
    unsigned char ok=0;
    if(e->unk58 && e->unk58->Valid()) ok=1;
    return ok;
}
static inline int B13Index(Entity* e) {
    int idx;
    if(D_005721C8) {
        if(B13Has(e)) idx=((e->unkC & 0x7F000000)>>24)-1;
        else idx=-1;
    } else idx=0;
    return idx;
}
static inline int B13Player() {
    if(D_004FFC0C && D_004FFC0C->unk30) {
        Entity* e=D_004FFC0C->unk30;
        return func_0012F5B0(D_004FFB50,B13Index(e));
    }
    return -1;
}
#pragma push
// Materialize each comparison as an integer short-circuit result.
#pragma bool off
static inline int InputOk(Input*p){return p->type==1 && p->device==0 && p->action==0;}
#pragma pop
extern "C" int GuiQuickChat_HandleInput(Screen* arg0, Input* arg1) {
    EventMessage msg;
    char sp2D0[32];
    char sp2B0[32];
    char sp290[32];
    char sp90[512];
    int var_s2;
    char* temp_s6;
    Screen* var_s1;
    int var_s2_3;
    int var_s4;
    unsigned short temp_v1;
    char *var_s3_2;
    int temp_a0;
    int var_s2_2;
    int temp_v1_2;
    int var_s0;
    State* temp_s1;
    int temp_s0_2;
    char* temp_v0_2;
    char* savedName;
    int temp_a2;
    unsigned char *temp_v1_3;
    void** slot;
    int var_s0_2;
    Entity* temp_s2;
    int temp_s0;

    if (InputOk(arg1)) {
        temp_v1 = arg1->button;
        var_s4 = -1;
        if (temp_v1 == 0x1000) {
            var_s4 = 0;
        }
        if (temp_v1 == 0x4000) {
            var_s4 = 1;
        }
        if (temp_v1 == 0x8000) {
            var_s4 = 2;
        }
        if (temp_v1 == 0x2000) {
            var_s4 = 3;
        }
        if (var_s4 != -1) {
            temp_v1_2 = arg0->unk48 * 0x14;
            if (*(D_0048BD10 + temp_v1_2) != 0) {
                temp_a0 = var_s4 * 4;
                arg0->unk48 = (int) *(int*)(temp_a0 + (D_0048BD14 + temp_v1_2));
                slot = &((Screen*)(temp_a0 + (int)arg0))->unk4C;
                GuiWidget_SendEvent(arg0, *slot, 6, (int)D_004ABED8);
                GuiWidget_SendEvent(*slot, Gui_GetScreenStack(), 0x10, 0);
                var_s2 = 0;
                var_s1 = arg0;
                var_s0 = 0;
                do {
                    if (var_s1->unk4C != 0) {
                        temp_v1_3 = D_0048BD10 + (arg0->unk48 * 0x14);
                        if (*temp_v1_3 != 0) {
                            sprintf(sp2D0, D_004ABEE8, *(int*)(temp_v1_3 + var_s0 + 4));
                        } else {
                            sprintf(sp2D0, D_004ABEF8, *(int*)(temp_v1_3 + var_s0 + 4));
                        }
                        GuiTextWidget_SetText(var_s1->unk4C, Loc_LookupText(sp2D0), 0);
                    }
                    var_s2 += 1;
                    var_s1 = (Screen*)((char*)var_s1+4);
                    var_s0 += 4;
                } while (var_s2 < 4);
            } else {
                temp_s1 = D_004FFC0C;
                if (temp_s1 != 0) {
                    temp_s2 = temp_s1->unk30;
                    var_s0_2=1;
                    if(temp_s2) var_s0_2=B13Index(temp_s2)+1;
                    var_s2_2=B13Player();
                    temp_s0 = var_s4 * 4;
                    int row=*(int*)(temp_s0 + (D_0048BD14 + (arg0->unk48 * 0x14)));
                    savedName=sp2B0;
                    *(char*)(int)savedName = 0;
                    sp290[0] = 0;
                    sprintf(sp290, D_004ABEB8, 0x1E, row, var_s0_2);
                    temp_s6 = Loc_LookupText(sp290);
                    var_s3_2 = 0;
                    if (var_s2_2 > 0) {
                        var_s3_2 = Loc_GetTextById(var_s2_2);
                    }
                    temp_v0_2 = Loc_GetStoredKey(var_s2_2);
                    if (temp_v0_2 != 0) {
                        String_Copy(savedName, temp_v0_2);
                    }
                    var_s3_2=var_s3_2 ? var_s3_2 : D_004ABED0;
                    sprintf(sp90, D_004ABEC8, temp_s6, var_s3_2);
                    Notify_Insert(D_004FFC2C + 0x100, sp90, D_00587C90, 1);
                    if (D_005721C8 != 0) {
                        var_s2_3=B13Player();
                        temp_a2 = arg0->unk48;
                        temp_s0_2 = *(int*)(temp_s0 + (D_0048BD14 + (temp_a2 * 0x14)));
                        Event_Construct(&msg, D_0052ACD8);
                        msg.value = temp_s0_2;
                        msg.vtable = D_004DE630;
                        msg.agent = var_s2_3;
                        msg.kind = 4;
                        Event_Send(&msg, temp_s1->unk30, 0);
                        msg.vtable = D_004DCF10;
                        cMessage_dtor(&msg, 0);
                    }
                }
                GuiWidget_SendEvent(((Screen*)((var_s4<<2)+(int)arg0))->unk4C, Gui_GetScreenStack(), 0x10, 1);
                if (D_004FFC2C != 0) {
                    func_002426E0(D_004FFC2C);
                } else {
                    arg0->unk14 = (unsigned short) (arg0->unk14 & 0xFFFD);
                }
            }
            return 1;
        }
        if (temp_v1 == 0x10) {
            GuiWidget_SendEvent(arg0, Gui_GetScreenStack(), 0x10, 1);
            if (D_004FFC2C != 0) {
                func_002426E0(D_004FFC2C);
            } else {
                arg0->unk14 = (unsigned short) (arg0->unk14 & 0xFFFD);
            }
            return 1;
        }
        goto block_80;
    }
block_80:
    return 0;
}

#pragma pop
