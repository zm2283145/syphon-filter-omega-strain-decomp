#pragma cplusplus on
#include "types.h"
#include "gui_grid_types.h"
#include "gui_widget_vslots.h"
struct Item { char pad[0x40A]; short unk40A; };
struct Slots { char pad[0x2410]; Item* unk2410; Item* unk2414; char pad2418[8]; Item* unk2420; };
struct Agent { char pad0[0x2470]; Item* unk2470; Item* unk2474; char pad2478[0x3524-0x2478]; void* unk3524; };
struct Widget : GuiWidgetV { char pad4[0x10]; unsigned short unk14; };
struct Screen { char pad0[0x48]; Agent* unk48; Agent* unk4C; char pad50[0x34]; int unk84; int unk88; int unk8C; int unk90; Widget* unk94; char pad98[0x34]; Widget* unkCC; char padD0[0x2C]; int unkFC; };
struct Stack { char pad0[0x20]; Widget* unk20; };
extern "C" {
void FrontEnd_OpenPopup(void*,int,char*,char*,void* =0,int=0);
void Game_NetSendPauseState(void*,int,int);
void GuiScreen_SetFocus(Stack*,Widget*);
void GuiStack_SwapScreens(Stack*,Screen*,void*);
void* Gui_GetScreenList();
Stack* Gui_GetScreenStack();
char* Loc_LookupText(char*);
void Pad_Reset(void*);
void WeaponInv_Add(void*,short,int,int,int=1,int=0);
void WeaponInv_Equip(void*,int);
void WeaponInv_HolsterCurrent(void*);
void WeaponInv_RemoveSlot(void*,int,int,int,int=0);
int WeaponInv_SlotOfItem(short);
void* func_00418A80(void*,char*,char*);
void func_0041E0F0(void*,void*,int,int,int=0);
extern signed char D_00489D62[];
extern char D_004A9870[],D_004AC2B0[],D_004AC2C8[],D_004AC2D0[],D_004AC2E0[],D_004AC2F0[],D_004AC300[],D_004AC310[],D_004AC320[],D_004AC330[],D_004AC340[],D_004AC350[],D_004AC360[],D_004FFB50[],D_0055A300[];
extern void* D_004FFC04;
extern signed char D_004FFC29;
extern unsigned char D_005721C8;
}
// Return an integer short-circuit result without a final byte conversion.
#pragma push
#pragma bool off
static inline int Press(GuiGridInput*p,int button) { return p->type==1 && p->device==0 && p->button==button && p->action==0; }
#pragma pop
extern "C" int GuiEquipmentModify_Accept(Screen* arg0, GuiGridInput* arg1) {
    void* temp_s0;
    char* temp_s0_2;
    int temp_v0_6;
    char* temp_v0_8;
    Item* temp_v1_2;
    int temp_v1_3;
    int temp_v1_6;
    bool var_t0;
    bool var_a3;
    void* var_s0_2;
    int var_s2;
    int var_s1;
    unsigned char var_a2;
    int var_v0;
    int var_v0_2;
    int var_v0_3;
    signed char *var_s0;
    unsigned short temp_a0;
    Widget* temp_v1_5;
    Widget* var_s0_3;
    Widget* var_s0_4;
    Agent* temp_a0_2;
    Item* temp_v0_5;
    Item* temp_v0_7;
    Widget* temp_v1_4;
    Widget* temp_v1_7;
    Widget* temp_v1_8;

    var_t0 = 0;
    var_a3 = 0;
    temp_a0 = arg1->type;
    var_a2 = 0;
    if ((temp_a0 == 1) && (arg1->device == 0)) {
        var_a2 = 1;
    }
    if ((var_a2) && (arg1->button == 0x80)) {
        var_a3 = 1;
    }
    if ((var_a3) && (arg1->action == 0)) {
        var_t0 = 1;
    }
    if (var_t0) {
        Agent* temp_v0 = arg0->unk4C;
        Slots* firstSlots;
        Item* temp_v1 = temp_v0->unk2470;
        firstSlots=(Slots*)((int)temp_v0+0x60);
        if (temp_v1 != 0) {
            int temp_v0_2 = arg0->unkFC;
            if (temp_v0_2 != 0) {
                ((Slots*)((temp_v0_2 << 2) + (int)firstSlots))->unk2410 = temp_v1;
                arg0->unk4C->unk2470 = 0;
                Agent* temp_v0_3 = arg0->unk4C;
                Slots* secondSlots=(Slots*)((int)temp_v0_3+0x60);
                Item* temp_v0_4 = temp_v0_3->unk2474;
                if (temp_v0_4 != 0) {
                    secondSlots->unk2420 = temp_v0_4;
                    arg0->unk4C->unk2474 = 0;
                }
            }
        }
        WeaponInv_HolsterCurrent(arg0->unk48->unk3524);
        var_s2 = 2;
        var_s1 = 8;
        var_s0 = D_00489D62;
        do {
            temp_a0_2 = arg0->unk48;
            temp_v1_2 = ((Slots*)((int)((Slots*)((int)temp_a0_2+0x60)) + var_s1))->unk2410;
            if (((Agent*)(var_s1 + (int)arg0->unk4C))->unk2470 != temp_v1_2) {
                if (temp_v1_2 != 0) {
                    WeaponInv_RemoveSlot(temp_a0_2->unk3524, *var_s0, 0, 0);
                }
                temp_v0_5 = ((Slots*)((int)((Slots*)((int)arg0->unk4C+0x60)) + var_s1))->unk2410;
                if (temp_v0_5 != 0) {
                    WeaponInv_Add(arg0->unk48->unk3524, temp_v0_5->unk40A, 1, 0);
                }
            }
            var_s2 += 1;
            var_s1 += 4;
            var_s0 += 1;
        } while (var_s2 < 0xA);
        temp_v0_6 = arg0->unkFC;
        if (temp_v0_6 != 0) {
            // Preserve index evaluation before the actor pointer read.
            int off=temp_v0_6*4;
            Agent* agent=*(Agent* volatile*)&arg0->unk4C;
            temp_v0_7=((Slots*)(off+((int)agent+0x60)))->unk2410;
            if (temp_v0_7 != 0) {
                WeaponInv_Equip(arg0->unk48->unk3524, WeaponInv_SlotOfItem(temp_v0_7->unk40A));
            }
        }
        var_s0_2 = 0;
        if (D_005721C8 != 0) {
            var_s0_2 = func_00418A80(Gui_GetScreenList(), D_004AC2B0, D_004AC2C8);
        } else {
            D_004FFC29 = 0;
            Pad_Reset(D_0055A300);
        }
        GuiStack_SwapScreens(Gui_GetScreenStack(), arg0, var_s0_2);
        Game_NetSendPauseState(D_004FFB50, 0, 0);
        return 1;
    }
    var_v0 = Press(arg1,0x10);
    if (var_v0 != 0) {
        if (D_005721C8 != 0) {
            temp_s0 = func_00418A80(Gui_GetScreenList(), D_004AC2B0, D_004AC2C8);
            GuiStack_SwapScreens(Gui_GetScreenStack(), arg0, temp_s0);
            Game_NetSendPauseState(D_004FFB50, 0, 0);
            return 1;
        }
        temp_s0_2 = Loc_LookupText(D_004AC2D0);
        temp_v0_8 = Loc_LookupText(D_004AC2E0);
        if ((temp_s0_2 != 0) && (temp_v0_8 != 0)) {
            FrontEnd_OpenPopup(D_004FFC04, 5, temp_s0_2, temp_v0_8,arg0);
        }
        return 1;
    }
    var_v0_2 = Press(arg1,0x8000);
    if (var_v0_2 != 0) {
        temp_v1_3 = arg0->unk84;
        var_s0_3 = 0;
        if (temp_v1_3 == 1) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC2F0, D_004A9870);
        }
        else if (temp_v1_3 == 2) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC300, D_004A9870);
        }
        else if (temp_v1_3 == 3) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC310, D_004A9870);
        }
        else if (temp_v1_3 == 4) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC320, D_004A9870);
        }
        else if (temp_v1_3 == 5) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC330, D_004A9870);
        }
        else if (temp_v1_3 == 6) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC340, D_004A9870);
        }
        else if (temp_v1_3 == 0) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC350, D_004A9870);
        }
        if (var_s0_3 != 0) {
            if (Gui_GetScreenStack()->unk20 == var_s0_3) {
                return 1;
            }
            arg0->unk8C = 0;
            GuiScreen_SetFocus(Gui_GetScreenStack(), var_s0_3);
            temp_v1_4 = arg0->unkCC;
            temp_v1_4->unk14 = (unsigned short) (temp_v1_4->unk14 & 0xFF7F);
            temp_v1_5 = arg0->unk94;
            temp_v1_5->unk14 = (unsigned short) (temp_v1_5->unk14 & 0xFF7F);
            func_0041E0F0(var_s0_3, Gui_GetScreenStack(), 0x10, 0);
            goto block_88;
        }
block_88:
        return 1;
    }
    if (arg0->unk84 > 0) {
        var_v0_3 = Press(arg1,0x2000);
        if (var_v0_3 != 0) {
            if (Gui_GetScreenStack()->unk20 == arg0->unk94) {
                return 1;
            }
            arg0->unk8C = 1;
            temp_v1_6 = arg0->unk84;
            var_s0_4 = 0;
            if (temp_v1_6 == 1) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC2F0, D_004A9870);
            }
            else if (temp_v1_6 == 2) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC300, D_004A9870);
            }
            else if (temp_v1_6 == 3) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC310, D_004A9870);
            }
            else if (temp_v1_6 == 4) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC320, D_004A9870);
            }
            else if (temp_v1_6 == 5) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC330, D_004A9870);
            }
            else if (temp_v1_6 == 6) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC340, D_004A9870);
            }
            else if (temp_v1_6 == 0) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC350, D_004A9870);
            }
            GuiScreen_SetFocus(Gui_GetScreenStack(), arg0->unk94);
            temp_v1_7 = arg0->unkCC;
            temp_v1_7->unk14 = (unsigned short) (temp_v1_7->unk14 | 2);
            temp_v1_8 = arg0->unkCC;
            temp_v1_8->unk14 = (unsigned short) (temp_v1_8->unk14 | 8);
            if (var_s0_4 != 0) {
                func_0041E0F0(arg0, var_s0_4, 6, (int)D_004AC360);
                func_0041E0F0(var_s0_4, Gui_GetScreenStack(), 0x10, 0);
            }
            return 1;
        }
        goto block_136;
    }
block_136:
    return 0;
}
