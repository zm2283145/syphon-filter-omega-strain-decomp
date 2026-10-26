/*
 * main/SFOLobby_Main: 5 files, 00453F30-00454080
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00453F30 */
#pragma push /* merge_units */
typedef __int128 Q128;
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int NetGetNetUpdateErrors(int *);                             

int func_00453F30(int arg0) {
    struct { int size; int st[4]; int pad[3]; } s;
    if ((arg0 < 0) || (arg0 >= 4)) {
        return 0;
    }
    s.size = 0x18;
    NetGetNetUpdateErrors(&s);
    return s.st[arg0] == 2;
}
#pragma pop /* merge_units */
/* merge_units: end func_00453F30 */

/* merge_units: begin func_00453F90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after SFOLobby_Main.cc (ends 0x004534A0),
 * before GuiSubTitleDisplay.cc (starts 0x00457AA0).
 */


void SFOLobby_PingRequest(void) {
}

void SFOLobby_PingIntel(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_00453F90 */

/* merge_units: begin func_00453FB0 */
#pragma push /* merge_units */
#include "loose05_types.h"

extern void cHeadSet_LeaveChannel(void);
extern void cHeadSet_NextFrame(int enabled);

/* Dispatch the lobby notification only while the suppression flag is clear. */
void SFOLobby_AudioShutdown(SFOLobby* lobby)
{
    if (!lobby->unk23D5)
        cHeadSet_LeaveChannel();
}

/* Enable the lobby operation only while the suppression flag is clear. */
void SFOLobby_AudioOnFrame(SFOLobby* lobby)
{
    if (!lobby->unk23D5)
        cHeadSet_NextFrame(1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00453FB0 */

/* merge_units: begin func_00454010 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after SFOLobby_Main.cc (ends 0x004534A0); probably part of it.
 */


extern int memset(void* dst, int value, int size); /* memset */
extern void func_0042B420(void* obj);
extern int cHeadSet_JoinChannel(int handle, int arg);

/* Clears an 84-byte record and hands it to func_0042B420. */
void func_00454010(void* rec) {
    memset(rec, 0, 84);
    func_0042B420(rec);
}

void SFOLobby_AudioStartup(SFOLobby* self) {
    if (self->unk23D5 == 0) {
        cHeadSet_JoinChannel(self->connHandle, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00454010 */

/* merge_units: begin func_00454080 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void FileMan_Release(void* member, int flags);
void GuiWidget_Destroy(void* self, int flags);
void operator_delete(void* allocation);
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_BaseWake();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Load();
extern "C" void GuiRadioLog_GetClassName();
extern "C" void GuiRadioLog_IsType();
extern "C" void GuiRadioLog_HandleInput();
extern "C" void GuiRadioLog_Update();
extern "C" void GuiRadioLog_HandleEvent();
extern "C" void GuiRadioLog_ClearFlag4();
extern "C" void GuiRadioLog_Init();
extern "C" void GuiRadioLog_Sleep();
extern void * const D_004E1290[];
}
struct TM454080 { void* vtable; char base[0x4C]; char payload[0x48]; char memberA[0x9C]; char memberB[4]; };
extern "C" TM454080* GuiRadioLog_dtor(TM454080* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1290);
        if (self->payload) {
            FileMan_Release(self->memberB, -1);
            FileMan_Release(self->memberA, -1);
        }
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1290[24] = { (void*)0x0, (void*)0x0, (void*)GuiRadioLog_dtor, (void*)GuiRadioLog_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiRadioLog_ClearFlag4, (void*)GuiWidget_BaseWake, (void*)GuiRadioLog_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiRadioLog_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiRadioLog_Update, (void*)GuiRadioLog_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiRadioLog_GetClassName, (void*)GuiRadioLog_IsType, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_00454080 */
