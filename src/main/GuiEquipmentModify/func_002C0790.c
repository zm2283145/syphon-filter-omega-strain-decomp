#pragma cplusplus on
#include "types.h"
#include "gui_widget_vslots.h"
struct Widget : GuiWidgetV {
    char pad04[0x10]; unsigned short unk14; char pad16[0x1E];
    float unk34; float unk38; int unk3C; float unk40; int unk44;
    void* unk48; char pad4C[0x10]; int unk5C;
};
struct Screen {
    char pad00[0x48]; int unk48; char pad4C[0x48];
    Widget* unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8;
    char padAC[0x20]; Widget* unkCC; Widget* unkD0; Widget* unkD4;
    char padD8[0x880]; Widget* unk958; char* unk95C;
};
struct Agent { char pad[0xB70]; unsigned char unkB70; };
struct State { char pad[0x251]; unsigned char unk251; };
extern "C" {
int Loc_FindKeyThunk(char*);
char* Loc_GetTextById(int);
char* Loc_LookupText(char*);
Agent* func_00185C70(int);
char* func_00336110(Agent*);
char* func_00336170(Agent*);
void func_0041BEB0(Widget*, char*, int);
void func_0041F150();
void func_00421070(Widget*);
extern State* D_004FFC04;
extern int D_00506508;
extern Screen* D_0051EE10;
extern unsigned char D_005721C8;
void func_002C21C0();
void func_002C2290();
void func_002C2340();
extern char D_0048BA80[];
extern char D_004A7520[];
extern char D_004A9870[];
extern char D_004A9BF0[];
extern char D_004AA640[];
extern char D_004AC2F0[];
extern char D_004AC300[];
extern char D_004AC310[];
extern char D_004AC320[];
extern char D_004AC330[];
extern char D_004AC340[];
extern char D_004AC4A0[];
extern char D_004AC4B0[];
extern char D_004AC4C0[];
extern char D_004AC4D0[];
extern char D_004AC4E0[];
extern char D_004AC4F8[];
extern char D_004AC508[];
extern char D_004AC518[];
extern char D_004AC520[];
extern char D_004AC530[];
extern char D_004AC540[];
extern char D_004AC550[];
extern char D_004AC560[];
extern char D_004AC570[];
extern char D_004AC580[];
extern char D_004AC590[];
extern char D_004AC5A0[];
extern char D_004AC5B0[];
}
extern "C" void func_002C0790(Screen* arg0) {
    Widget *var_s2;
    char *temp_s2;
    char *var_a0;
    Widget *temp_v1;
    Widget *temp_v1_2;
    Widget *temp_v1_3;
    Widget *temp_v1_4;
    Widget *temp_v1_5;
    Widget *temp_v1_6;
    Widget *temp_v1_7;
    Widget *temp_v1_8;
    Widget *var_s0;
    Widget *var_s1;
    Widget *var_s1_10;
    Widget *var_s1_11;
    Widget *var_s1_12;
    Widget *var_s1_13;
    Widget *var_s1_2;
    Widget *var_s1_3;
    Widget *var_s1_4;
    Widget *var_s1_5;
    Widget *var_s1_6;
    Widget *var_s1_7;
    Widget *var_s1_8;
    Widget *var_s1_9;
    Widget *var_s2_2;
    char *temp_s1;

    func_0041F150();
    D_0051EE10 = arg0;
    var_s1 = (Widget*)GuiFindAs(arg0, D_004AC4A0, D_004A9BF0);
    if (var_s1 != 0) {
        var_s1->unk48 = (void*)&func_002C2340;
    }
    var_s1_2 = (Widget*)GuiFindAs(arg0, D_004AC4B0, D_004A9BF0);
    arg0->unkD0 = var_s1_2;
    temp_v1 = arg0->unkD0;
    if (temp_v1 != 0) {
        temp_v1->unk48 = (void*)&func_002C2290;
    }
    var_s1_3 = (Widget*)GuiFindAs(arg0, D_004AC4C0, D_004A9BF0);
    arg0->unkD4 = var_s1_3;
    temp_v1_2 = arg0->unkD4;
    if (temp_v1_2 != 0) {
        temp_v1_2->unk48 = (void*)&func_002C21C0;
    }
    var_s1_4 = (Widget*)GuiFindAs(arg0, D_004AC4D0, D_004AA640);
    arg0->unk94 = var_s1_4;
    arg0->unk98 = (int) arg0->unk94->unk34;
    arg0->unk9C = (int) arg0->unk94->unk38;
    arg0->unkA4 = (int) arg0->unk94->unk5C;
    arg0->unkA8 = (int) ((arg0->unk94->unk40 / (float) arg0->unkA4) - 1.0f);
    arg0->unkCC = (Widget*)func_0041DB80(arg0, D_004AC4E0);
    temp_v1_3 = arg0->unkCC;
    temp_v1_3->unk14 = (unsigned short) (temp_v1_3->unk14 & 0xFF7F);
    temp_v1_4 = arg0->unk94;
    temp_v1_4->unk14 = (unsigned short) (temp_v1_4->unk14 & 0xFF7F);
    var_s2 = (Widget*)GuiFindAs(arg0, D_004AC4F8, D_004A7520);
    var_s1_5 = (Widget*)GuiFindAs(arg0, D_004AC508, D_004A7520);
    if (func_00185C70(arg0->unk48)->unkB70 != 0) {
        func_0041BEB0(var_s2, func_00336170(func_00185C70(arg0->unk48)), 0);
        func_0041BEB0(var_s1_5, func_00336110(func_00185C70(arg0->unk48)), 0);
    } else {
        func_0041BEB0(var_s2, D_004AC518, 0);
        func_0041BEB0(var_s1_5, Loc_GetTextById(Loc_FindKeyThunk(D_004AC520) + 1), 0);
    }
    if (D_004FFC04->unk251 != 0) {
        var_s1_6 = (Widget*)GuiFindAs(arg0, D_004AC340, D_004A9870);
        var_s1_6->unk14 = (unsigned short) (var_s1_6->unk14 & 0xFFFB);
        var_s1_7 = (Widget*)GuiFindAs(arg0, D_004AC2F0, D_004A9870);
        var_s1_7->unk14 = (unsigned short) (var_s1_7->unk14 & 0xFFFB);
        var_s1_8 = (Widget*)GuiFindAs(arg0, D_004AC300, D_004A9870);
        var_s1_8->unk14 = (unsigned short) (var_s1_8->unk14 & 0xFFFB);
        var_s1_9 = (Widget*)GuiFindAs(arg0, D_004AC310, D_004A9870);
        var_s1_9->unk14 = (unsigned short) (var_s1_9->unk14 & 0xFFFB);
        var_s1_10 = (Widget*)GuiFindAs(arg0, D_004AC320, D_004A9870);
        var_s1_10->unk14 = (unsigned short) (var_s1_10->unk14 & 0xFFFB);
        var_s1_11 = (Widget*)GuiFindAs(arg0, D_004AC330, D_004A9870);
        var_s1_11->unk14 = (unsigned short) (var_s1_11->unk14 & 0xFFFB);
        func_00421070(arg0->unk94);
        temp_v1_5 = arg0->unk94;
        temp_v1_5->unk14 = (unsigned short) (temp_v1_5->unk14 & 0xFF7F);
        temp_v1_6 = arg0->unkCC;
        temp_v1_6->unk14 = (unsigned short) (temp_v1_6->unk14 & 0xFF7F);
        temp_v1_7 = arg0->unkCC;
        temp_v1_7->unk14 = (unsigned short) (temp_v1_7->unk14 & 0xFFFD);
    }
    temp_s2 = Loc_LookupText(D_004AC530);
    var_s1_12 = (Widget*)GuiFindAs(arg0, D_004AC540, D_004A7520);
    if ((temp_s2 != 0) && (var_s1_12 != 0)) {
        func_0041BEB0(var_s1_12, temp_s2, 0);
    }
    temp_s1 = Loc_LookupText(D_004AC550);
    var_s2_2 = (Widget*)GuiFindAs(arg0, D_004AC560, D_004A7520);
    if ((temp_s1 != 0) && (var_s2_2 != 0)) {
        func_0041BEB0(var_s2_2, temp_s1, 0);
    }
    var_s1_13 = (Widget*)GuiFindAs(arg0, D_004AC570, D_004A7520);
    arg0->unk958 = var_s1_13;
    arg0->unk95C = Loc_LookupText(D_004AC580);
    if (arg0->unk95C == 0) {
        arg0->unk95C = D_0048BA80;
    }
    if ((D_00506508 == 0) || (D_005721C8 == 0)) {
        temp_v1_8 = arg0->unk958;
        if (temp_v1_8 != 0) {
            temp_v1_8->unk14 = (unsigned short) (temp_v1_8->unk14 & 0xFFFD);
        }
    }
    var_s0 = (Widget*)GuiFindAs(arg0, D_004AC590, D_004A7520);
    if (var_s0 != 0) {
        if (D_005721C8 != 0) {
            var_a0 = D_004AC5A0;
        } else {
            var_a0 = D_004AC5B0;
        }
        func_0041BEB0(var_s0, Loc_LookupText(var_a0), 0);
    }
}
