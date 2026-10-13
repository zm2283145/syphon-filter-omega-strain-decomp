#include "types.h"
#pragma opt_propagation off
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
extern void __register_global_object(void* obj, void* dtor, void* link);
extern char func_00135A60[];
extern char D_004EF0B0[];
extern char D_004EF098[];
extern char D_004EF250[];
extern char D_004EF240[];
extern char D_004EF3F0[];
extern char D_004EF3E0[];
extern char D_004EF590[];
extern char D_004EF580[];
extern char D_004EF730[];
extern char D_004EF720[];
extern char D_004EF8D0[];
extern char D_004EF8C0[];
extern char D_004EFA70[];
extern char D_004EFA60[];
extern char D_004EFC10[];
extern char D_004EFC00[];
extern char D_004EFDB0[];
extern char D_004EFDA0[];
extern char D_004EFF50[];
extern char D_004EFF40[];
extern char D_004F00F0[];
extern char D_004F00E0[];
extern char D_004F0290[];
extern char D_004F0280[];
extern char D_004F0430[];
extern char D_004F0420[];
extern char D_004F05D0[];
extern char D_004F05C0[];
extern char D_004F0770[];
extern char D_004F0760[];
extern char D_004F0910[];
extern char D_004F0900[];
extern char D_004F0AB0[];
extern char D_004F0AA0[];
extern char g_FlashlightClickSound[];
extern char D_004F0C40[];
extern char D_004F0DF0[];
extern char D_004F0DE0[];
extern char D_004F0F90[];
extern char D_004F0F80[];
extern char D_004F1130[];
extern char D_004F1120[];
extern char D_004F12D0[];
extern char D_004F12C0[];
extern char D_004F1470[];
extern char D_004F1460[];
extern char D_004F1610[];
extern char D_004F1600[];
extern char D_004F17B0[];
extern char D_004F17A0[];
extern char D_004F1950[];
extern char D_004F1940[];
extern char D_004F1AF0[];
extern char D_004F1AE0[];
extern char D_004F1C90[];
extern char D_004F1C80[];
extern char D_004F1E30[];
extern char D_004F1E20[];
extern char D_004F1FD0[];
extern char D_004F1FC0[];
extern char D_004F2170[];
extern char D_004F2160[];
extern char D_004F2310[];
extern char D_004F2300[];
extern char D_004F24B0[];
extern char D_004F24A0[];
extern char D_004F2650[];
extern char D_004F2640[];
extern char D_004F27F0[];
extern char D_004F27E0[];
extern char D_004F2990[];
extern char D_004F2980[];
extern char D_004F2B30[];
extern char D_004F2B20[];
extern char* D_004F2CC0;
extern char* D_004F2CE8;
extern char* D_004F2D00;
extern char D_004F2CF0[], D_004F2D08[];
extern int D_004F2CF8, D_004F2D10;
extern int D_004F2D18;
extern int D_004F2D20, D_004F2D28, D_004F2D30, D_004F2D38, D_004F2D40, D_004F2D48;
extern int D_004F2D50, D_004F2D58, D_004F2D60, D_004F2D68, D_004F2D70, D_004F2D78;
extern char D_0048A340[];
extern char D_00493880[], D_00493888[], D_00493898[];
extern char func_001C7500[], func_001C7340[];
extern char Script_PlaySnd_2[], Script_StopSnd_2[], Script_PlaySnd[], Script_StopSnd[];
extern char Script_PlayMusic[], Script_StopMusic[], Script_PlayQuip[], Script_PlayQuip_2[];
extern char Script_StopAllQuips[], Script_SetReverb[], Script_AddPDAQuip[], Script_AddPDAQuip_2[];
extern int func_002824D0();
extern int ScriptEnum_Register();
extern int cGOBJ_GetScriptTypeKeyPtr();
extern int Script_RegisterNative_2();

/* 37 global SoundRequest objects (inlined ctor, voice 0; name is a 16-char
 * 128-bit literal, built by mw as li + pcpyld) registered with dtor
 * func_00135A60, then the SYS_SOUND message / script native registrations. */
#define SNDREQ(obj, t, Q, link) \
    p = (SoundRequest*)obj; \
    ((SoundRequest*)obj)->voice = 0; \
    ((SoundRequest*)obj)->voiceId = -2; \
    func_0036E5D0(&((SoundRequest*)obj)->a); \
    func_0036E5D0(&((SoundRequest*)obj)->b); \
    p->type = t; \
    *(__int128*)p->name = Q; \
    p->voice = 0; \
    { int tmp; int* r; tmp = -1; r = &tmp; p->voiceId = *r; } \
    p->x30 = 0; \
    p->x34 = 0; \
    p->x38 = 0; \
    p->x184 = -1; \
    p->x186 = 0; \
    __register_global_object(p, func_00135A60, link)

void func_004C7500(void)
{
    SoundRequest* p;
    SNDREQ(D_004EF0B0, 1, 0x4D5F43505F5449485F42, D_004EF098);
    SNDREQ(D_004EF250, 1, 0x4D5F43504E5F5449485F42, D_004EF240);
    SNDREQ(D_004EF3F0, 1, 0x535F43505F59425F42, D_004EF3E0);
    SNDREQ(D_004EF590, 1, 0x45544552434E4F435F5449485F42, D_004EF580);
    SNDREQ(D_004EF730, 1, 0x52414C56454B5F5449485F42, D_004EF720);
    SNDREQ(D_004EF8D0, 0, 0x4D5F45544552434E4F435F46, D_004EF8C0);
    SNDREQ(D_004EFA70, 0, 0x465F45544552434E4F435F46, D_004EFA60);
    SNDREQ(D_004EFC10, 0, 0x4D5F44494C4F535F4C4154454D5F46, D_004EFC00);
    SNDREQ(D_004EFDB0, 0, 0x465F44494C4F535F4C4154454D5F46, D_004EFDA0);
    SNDREQ(D_004EFF50, 2, 0x4D5F5449485F43504E5F56, D_004EFF40);
    SNDREQ(D_004F00F0, 2, 0x4D5F485445445F43504E5F56, D_004F00E0);
    SNDREQ(D_004F0290, 2, 0x465F5449485F43504E5F56, D_004F0280);
    SNDREQ(D_004F0430, 2, 0x465F485445445F43504E5F56, D_004F0420);
    SNDREQ(D_004F05D0, 2, 0x4D5F5449485F43505F56, D_004F05C0);
    SNDREQ(D_004F0770, 2, 0x4D5F485445445F43505F56, D_004F0760);
    SNDREQ(D_004F0910, 2, 0x465F5449485F43505F56, D_004F0900);
    SNDREQ(D_004F0AB0, 2, 0x465F485445445F43505F56, D_004F0AA0);
    SNDREQ(g_FlashlightClickSound, 1, 0x544847494C4853414C465F45, D_004F0C40);
    SNDREQ(D_004F0DF0, 1, 0x46464F5F4E4F5F52495F45, D_004F0DE0);
    SNDREQ(D_004F0F90, 1, 0x52454D49545F45, D_004F0F80);
    SNDREQ(D_004F1130, 1, 0x48434E55414C5F52455341545F47, D_004F1120);
    SNDREQ(D_004F12D0, 1, 0x5A5A55425F52455341545F47, D_004F12C0);
    SNDREQ(D_004F1470, 1, 0x455249465F52455341545F47, D_004F1460);
    SNDREQ(D_004F1610, 2, 0x4D41455243535F4E5255425F56, D_004F1600);
    SNDREQ(D_004F17B0, 1, 0x4F4D4D415F454B41545F45, D_004F17A0);
    SNDREQ(D_004F1950, 1, 0x4843544957535F5045575F45, D_004F1940);
    SNDREQ(D_004F1AF0, 1, 0x50554B4349505F5045575F45, D_004F1AE0);
    SNDREQ(D_004F1C90, 1, 0x4B4341504B4341425F45, D_004F1C80);
    SNDREQ(D_004F1E30, 1, 0x4B414552424B43454E5F47, D_004F1E20);
    SNDREQ(D_004F1FD0, 1, 0x4D495F4C414D524548545F45, D_004F1FC0);
    SNDREQ(D_004F2170, 1, 0x4D4F4F5A5F45, D_004F2160);
    SNDREQ(D_004F2310, 1, 0x4B434954534E5554535F47, D_004F2300);
    SNDREQ(D_004F24B0, 1, 0x54494C535F4546494E4B5F47, D_004F24A0);
    SNDREQ(D_004F2650, 1, 0x5353494D5F4546494E4B5F47, D_004F2640);
    SNDREQ(D_004F27F0, 1, 0x455249465952445F4E5547485F47, D_004F27E0);
    SNDREQ(D_004F2990, 1, 0x455249465952445F454C4649525F47, D_004F2980);
    SNDREQ(D_004F2B30, 1, 0x455249465952445F4E554748535F47, D_004F2B20);
    D_004F2CC0 = "SYS_SOUND";
    D_004F2CE8 = "cStopAllQuipsMsg";
    D_004F2CF8 = func_002824D0(func_001C7500, D_004F2CF0, "cStopAllQuipsMsg");
    D_004F2D00 = "cPlayQuipMsg";
    D_004F2D10 = func_002824D0(func_001C7340, D_004F2D08, "cPlayQuipMsg");
    D_004F2D18 = ScriptEnum_Register("cGameSound::eSndBank", D_0048A340, 7);
    D_004F2D20 = Script_RegisterNative_2(Script_PlaySnd_2, D_00493880, "PlaySnd", 2, &D_004F2D18, D_00493898);
    D_004F2D28 = Script_RegisterNative_2(Script_StopSnd_2, D_00493880, "StopSnd", 2, &D_004F2D18, D_00493898);
    D_004F2D30 = Script_RegisterNative_2(Script_PlaySnd, D_00493880, "PlaySnd", 3, &D_004F2D18, D_00493898, cGOBJ_GetScriptTypeKeyPtr());
    D_004F2D38 = Script_RegisterNative_2(Script_StopSnd, D_00493880, "StopSnd", 3, &D_004F2D18, D_00493898, cGOBJ_GetScriptTypeKeyPtr());
    D_004F2D40 = Script_RegisterNative_2(Script_PlayMusic, D_00493880, "PlayMusic", 2, D_00493898, cGOBJ_GetScriptTypeKeyPtr());
    D_004F2D48 = Script_RegisterNative_2(Script_StopMusic, D_00493880, "StopMusic", 2, D_00493898, cGOBJ_GetScriptTypeKeyPtr());
    D_004F2D50 = Script_RegisterNative_2(Script_PlayQuip, D_00493880, "PlayQuip", 2, D_00493898, D_00493888);
    D_004F2D58 = Script_RegisterNative_2(Script_PlayQuip_2, D_00493880, "PlayQuip", 3, D_00493898, cGOBJ_GetScriptTypeKeyPtr(), D_00493888);
    D_004F2D60 = Script_RegisterNative_2(Script_StopAllQuips, D_00493880, "StopAllQuips", 0);
    D_004F2D68 = Script_RegisterNative_2(Script_SetReverb, D_00493880, "SetReverb", 1, D_00493888);
    D_004F2D70 = Script_RegisterNative_2(Script_AddPDAQuip, D_00493880, "AddPDAQuip", 1, D_00493898);
    D_004F2D78 = Script_RegisterNative_2(Script_AddPDAQuip_2, D_00493880, "AddPDAQuip", 2, D_00493898, D_00493898);
}





