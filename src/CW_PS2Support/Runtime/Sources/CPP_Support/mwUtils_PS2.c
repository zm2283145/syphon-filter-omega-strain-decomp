/*
 * CW_PS2Support/Runtime/Sources/CPP_Support/mwUtils_PS2: 4 files, 00100410-001005E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00100410 */
#pragma push /* merge_units */
#include "types.h"
extern void FunctionList_CallEach(void* a, void* b, void* c, void* d);
extern void StaticInit_flashlight();
extern void StaticInit_game();
extern void StaticInit_weapon();
extern void StaticInit_npc();
extern void StaticInit_Node();
extern void StaticInit_path();
extern void StaticInit_machine();
extern void StaticInit_ai();
extern void StaticInit_hotbox();
extern void StaticInit_terrain();
extern void StaticInit_player();
extern void StaticInit_Env();
extern void StaticInit_gamelight();
extern void StaticInit_gameCamera();
extern void StaticInit_human();
extern void StaticInit_Loader();
extern void StaticInit_gameSound();
extern void StaticInit_humanIk();
extern void StaticInit_humanCollision();
extern void func_004CC810();
extern void StaticInit_game_msg();
extern void StaticInit_gameSound_msg();
extern void StaticInit_player_msg();
extern void StaticInit_gamePhysics();
extern void StaticInit_GameGOBJ();
extern void StaticInit_Generator();
extern void StaticInit_Objective();
extern void StaticInit_targetManager();
extern void StaticInit_Checkpoint();
extern void StaticInit_gameGobjController();
extern void StaticInit_SpecFxDefs();
extern void StaticInit_NIEvent();
extern void StaticInit_hud();
extern void StaticInit_playerControls();
extern void StaticInit_pickup_menu();
extern void StaticInit_backpack();
extern void StaticInit_grenade();
extern void StaticInit_RestoreBody();
extern void StaticInit_SwitchBodies();
extern void StaticInit_VisionFxMan();
extern void StaticInit_hud_util();
extern void StaticInit_hud_radar();
extern void StaticInit_gameEventMsg();
extern void StaticInit_fire();
extern void StaticInit_taser();
extern void StaticInit_scriptUtils();
extern void StaticInit_map();
extern void StaticInit_AIMsgs();
extern void StaticInit_hud_loading();
extern void StaticInit_tremor();
extern void StaticInit_globals();
extern void StaticInit_hudTargets();
extern void StaticInit_bullet();
extern void StaticInit_decals();
extern void StaticInit_hud_netlobby();
extern void StaticInit_netTaserMsg();
extern void StaticInit_NetGrenadeMsg();
extern void StaticInit_playerCamera();
extern void StaticInit_netBackpackMsg();
extern void StaticInit_BeamMsg();
extern void StaticInit_tank();
extern void StaticInit_GuiTitleScreen();
extern void StaticInit_GuiAccountLogin();
extern void StaticInit_GuiAgentCreate();
extern void StaticInit_GuiAgentLoad();
extern void StaticInit_GuiCommandCenter();
extern void StaticInit_GuiGameOptions();
extern void StaticInit_GuiOnlineConnect();
extern void StaticInit_GuiOnlineOfflineSelect();
extern void StaticInit_GuiMissionSetup();
extern void StaticInit_GuiEquipmentSetup();
extern void StaticInit_GuiMessageBox();
extern void StaticInit_GuiNetJoinMission();
extern void StaticInit_GuiMissionList();
extern void StaticInit_GuiNetContacts();
extern void StaticInit_GuiChatWindow();
extern void StaticInit_GuiNetAgencyCell();
extern void StaticInit_GuiOnlineOptions();
extern void StaticInit_GuiZeusShell();
extern void StaticInit_GuiQuickChat();
extern void StaticInit_WaterFx();
extern void StaticInit_GuiEquipmentModify();
extern void StaticInit_NetCalloutMsgName();
extern void StaticInit_NetCalloutMsg();
extern void StaticInit_NetCopyMsg();
extern void StaticInit_NetCreateBlastMsg();
extern void StaticInit_NetGeneratorCreate();
extern void StaticInit_NetGeneratorDelete();
extern void StaticInit_NetLabelMsg();
extern void StaticInit_NetNPCMsgs();
extern void StaticInit_NetObjectiveMsg();
extern void StaticInit_NetPathMsg();
extern void StaticInit_NetScoreMsg();
extern void StaticInit_NetShatterMsg();
extern void StaticInit_NetWeaponMsg();
extern void StaticInit_NetQuickChatMsg();
extern void StaticInit_NetRemoveHudObjectiveMsg();
extern void StaticInit_GuiCharacterDisplay();
extern void StaticInit_enableSuperJumpMsg();
extern void StaticInit_GuiSlideShow();
extern void StaticInit_GuiKeyboard();
extern void StaticInit_AgentData();
extern void StaticInit_GuiAgentModify();
extern void StaticInit_GuiNetMessages();
extern void StaticInit_GuiDossiers();
extern void StaticInit_GuiRatings();
extern void StaticInit_GuiRanks();
extern void StaticInit_GuiOmegaStrain();
extern void StaticInit_GuiMissionStatistics();
extern void StaticInit_GuiAchievementScreen();
extern void StaticInit_GuiPersonnelMenu();
extern void StaticInit_GuiPersonnelScreen();
extern void StaticInit_GuiScoresEquip();
extern void StaticInit_GuiAgentInfo();
extern void StaticInit_GuiObjectivesFactory();
extern void StaticInit_xdrawprim();
extern void StaticInit_lights();
extern void StaticInit_dmaman();
extern void StaticInit_vu1man();
extern void StaticInit_xlib();
extern void StaticInit_gameobj();
extern void StaticInit_particle();
extern void StaticInit_sfoglobals();
extern void StaticInit_skeleton();
extern void StaticInit_ska();
extern void StaticInit_skybox();
extern void StaticInit_vu0man();
extern void StaticInit_bboxman();
extern void StaticInit_los();
extern void StaticInit_message();
extern void StaticInit_system();
extern void StaticInit_SFOini();
extern void StaticInit_lib_msg();
extern void StaticInit_gobj();
extern void StaticInit_shadows();
extern void StaticInit_scriptManager();
extern void StaticInit_character();
extern void StaticInit_interface();
extern void StaticInit_console();
extern void StaticInit_interface_element();
extern void StaticInit_interface_gobj();
extern void StaticInit_callback();
extern void StaticInit_devices();
extern void StaticInit_gobjController();
extern void StaticInit_specfx();
extern void StaticInit_interface_model();
extern void StaticInit_MoviePlayer();
extern void StaticInit_NetObj();
extern void StaticInit_sfomath();
extern void StaticInit_globalization();
extern void StaticInit_charActionMsg();
extern void StaticInit_DisableMsg();
extern void StaticInit_EnableMsg();
extern void StaticInit_moveMsg();
extern void StaticInit_manUtils();
extern void StaticInit_DamageMsg();
extern void StaticInit_materialProperties();
extern void StaticInit_GobjMan();
extern void StaticInit_MovieSubtitles();
extern void StaticInit_interface_manager();
extern void StaticInit_guiCanvas();
extern void StaticInit_guiTextEditWidget();
extern void StaticInit_guiTextWidget();
extern void StaticInit_guiWidget();
extern void StaticInit_guiButtonWidget();
extern void StaticInit_guiTextListWidget();
extern void StaticInit_guiArrayWidget();
extern void StaticInit_guiTextArrayWidget();
extern void StaticInit_ActivateMsg();
extern void StaticInit_DeactivateMsg();
extern void StaticInit_DME();
extern void StaticInit_nellymoser_wrapper();
extern void StaticInit_NetActivateAndControlMsg();
extern void StaticInit_NetObjectMgr();
extern void StaticInit_NetPlayGameMsg();
extern void StaticInit_NetSetGobjMsg();
extern void StaticInit_NetTerrainActivation();
extern void StaticInit_NetTransferMsg();
extern void StaticInit_NPCInfoObject();
extern void StaticInit_camera();
extern void StaticInit_GenInfoObject();
extern void StaticInit_wpnEnums();
extern void StaticInit_guiScrollBarWidget();
extern void StaticInit_guiBitmapWidget();
extern void StaticInit_guiMLTextWidget();
extern void StaticInit_guiSliderWidget();
extern void StaticInit_WeaponVisChangeMsg();
extern void StaticInit_NetTransferRecvMsgName();
extern void StaticInit_NetLevelInfoMsgName();
extern void StaticInit_GuiWeaponDisplay();
extern void StaticInit_GuiSaveAgentWidget();
extern void StaticInit_GuiStartMenu();
extern void StaticInit_GuiSubTitleDisplayFactory();
extern void StaticInit_GuiGameScreen();
extern void StaticInit_GuiEndGameAwards();
extern void StaticInit_GuiEndGameObjectivesFactory();
extern void StaticInit_GuiEndGameStatisticsFactory();
extern void StaticInit_GuiMapScreenFactory();
extern void StaticInit_gameCanvas();
extern void StaticInit_guiConstants();
extern void StaticInit_inventory();
extern void StaticInit_NetMsgThrottle();
extern void StaticInit_RegisterActivateBodyToss();
static void * const dat_004D8D10[203] = { (void*)StaticInit_game, (void*)StaticInit_weapon, (void*)StaticInit_npc, (void*)StaticInit_Node, (void*)StaticInit_path, (void*)StaticInit_machine, (void*)StaticInit_ai, (void*)StaticInit_hotbox, (void*)StaticInit_terrain, (void*)StaticInit_player, (void*)StaticInit_Env, (void*)StaticInit_gamelight, (void*)StaticInit_gameCamera, (void*)StaticInit_human, (void*)StaticInit_Loader, (void*)StaticInit_gameSound, (void*)StaticInit_humanIk, (void*)StaticInit_humanCollision, (void*)func_004CC810, (void*)StaticInit_game_msg, (void*)StaticInit_gameSound_msg, (void*)StaticInit_player_msg, (void*)StaticInit_gamePhysics, (void*)StaticInit_GameGOBJ, (void*)StaticInit_Generator, (void*)StaticInit_Objective, (void*)StaticInit_targetManager, (void*)StaticInit_Checkpoint, (void*)StaticInit_gameGobjController, (void*)StaticInit_SpecFxDefs, (void*)StaticInit_NIEvent, (void*)StaticInit_hud, (void*)StaticInit_playerControls, (void*)StaticInit_pickup_menu, (void*)StaticInit_backpack, (void*)StaticInit_grenade, (void*)StaticInit_RestoreBody, (void*)StaticInit_SwitchBodies, (void*)StaticInit_VisionFxMan, (void*)StaticInit_hud_util, (void*)StaticInit_hud_radar, (void*)StaticInit_gameEventMsg, (void*)StaticInit_fire, (void*)StaticInit_taser, (void*)StaticInit_scriptUtils, (void*)StaticInit_map, (void*)StaticInit_AIMsgs, (void*)StaticInit_hud_loading, (void*)StaticInit_tremor, (void*)StaticInit_globals, (void*)StaticInit_hudTargets, (void*)StaticInit_bullet, (void*)StaticInit_decals, (void*)StaticInit_hud_netlobby, (void*)StaticInit_netTaserMsg, (void*)StaticInit_NetGrenadeMsg, (void*)StaticInit_playerCamera, (void*)StaticInit_netBackpackMsg, (void*)StaticInit_BeamMsg, (void*)StaticInit_tank, (void*)StaticInit_GuiTitleScreen, (void*)StaticInit_GuiAccountLogin, (void*)StaticInit_GuiAgentCreate, (void*)StaticInit_GuiAgentLoad, (void*)StaticInit_GuiCommandCenter, (void*)StaticInit_GuiGameOptions, (void*)StaticInit_GuiOnlineConnect, (void*)StaticInit_GuiOnlineOfflineSelect, (void*)StaticInit_GuiMissionSetup, (void*)StaticInit_GuiEquipmentSetup, (void*)StaticInit_GuiMessageBox, (void*)StaticInit_GuiNetJoinMission, (void*)StaticInit_GuiMissionList, (void*)StaticInit_GuiNetContacts, (void*)StaticInit_GuiChatWindow, (void*)StaticInit_GuiNetAgencyCell, (void*)StaticInit_GuiOnlineOptions, (void*)StaticInit_GuiZeusShell, (void*)StaticInit_GuiQuickChat, (void*)StaticInit_WaterFx, (void*)StaticInit_GuiEquipmentModify, (void*)StaticInit_NetCalloutMsgName, (void*)StaticInit_NetCalloutMsg, (void*)StaticInit_NetCopyMsg, (void*)StaticInit_NetCreateBlastMsg, (void*)StaticInit_NetGeneratorCreate, (void*)StaticInit_NetGeneratorDelete, (void*)StaticInit_NetLabelMsg, (void*)StaticInit_NetNPCMsgs, (void*)StaticInit_NetObjectiveMsg, (void*)StaticInit_NetPathMsg, (void*)StaticInit_NetScoreMsg, (void*)StaticInit_NetShatterMsg, (void*)StaticInit_NetWeaponMsg, (void*)StaticInit_NetQuickChatMsg, (void*)StaticInit_NetRemoveHudObjectiveMsg, (void*)StaticInit_GuiCharacterDisplay, (void*)StaticInit_enableSuperJumpMsg, (void*)StaticInit_GuiSlideShow, (void*)StaticInit_GuiKeyboard, (void*)StaticInit_AgentData, (void*)StaticInit_GuiAgentModify, (void*)StaticInit_GuiNetMessages, (void*)StaticInit_GuiDossiers, (void*)StaticInit_GuiRatings, (void*)StaticInit_GuiRanks, (void*)StaticInit_GuiOmegaStrain, (void*)StaticInit_GuiMissionStatistics, (void*)StaticInit_GuiAchievementScreen, (void*)StaticInit_GuiPersonnelMenu, (void*)StaticInit_GuiPersonnelScreen, (void*)StaticInit_GuiScoresEquip, (void*)StaticInit_GuiAgentInfo, (void*)StaticInit_GuiObjectivesFactory, (void*)StaticInit_xdrawprim, (void*)StaticInit_lights, (void*)StaticInit_dmaman, (void*)StaticInit_vu1man, (void*)StaticInit_xlib, (void*)StaticInit_gameobj, (void*)StaticInit_particle, (void*)StaticInit_sfoglobals, (void*)StaticInit_skeleton, (void*)StaticInit_ska, (void*)StaticInit_skybox, (void*)StaticInit_vu0man, (void*)StaticInit_bboxman, (void*)StaticInit_los, (void*)StaticInit_message, (void*)StaticInit_system, (void*)StaticInit_SFOini, (void*)StaticInit_lib_msg, (void*)StaticInit_gobj, (void*)StaticInit_shadows, (void*)StaticInit_scriptManager, (void*)StaticInit_character, (void*)StaticInit_interface, (void*)StaticInit_console, (void*)StaticInit_interface_element, (void*)StaticInit_interface_gobj, (void*)StaticInit_callback, (void*)StaticInit_devices, (void*)StaticInit_gobjController, (void*)StaticInit_specfx, (void*)StaticInit_interface_model, (void*)StaticInit_MoviePlayer, (void*)StaticInit_NetObj, (void*)StaticInit_sfomath, (void*)StaticInit_globalization, (void*)StaticInit_charActionMsg, (void*)StaticInit_DisableMsg, (void*)StaticInit_EnableMsg, (void*)StaticInit_moveMsg, (void*)StaticInit_manUtils, (void*)StaticInit_DamageMsg, (void*)StaticInit_materialProperties, (void*)StaticInit_GobjMan, (void*)StaticInit_MovieSubtitles, (void*)StaticInit_interface_manager, (void*)StaticInit_guiCanvas, (void*)StaticInit_guiTextEditWidget, (void*)StaticInit_guiTextWidget, (void*)StaticInit_guiWidget, (void*)StaticInit_guiButtonWidget, (void*)StaticInit_guiTextListWidget, (void*)StaticInit_guiArrayWidget, (void*)StaticInit_guiTextArrayWidget, (void*)StaticInit_ActivateMsg, (void*)StaticInit_DeactivateMsg, (void*)StaticInit_DME, (void*)StaticInit_nellymoser_wrapper, (void*)StaticInit_NetActivateAndControlMsg, (void*)StaticInit_NetObjectMgr, (void*)StaticInit_NetPlayGameMsg, (void*)StaticInit_NetSetGobjMsg, (void*)StaticInit_NetTerrainActivation, (void*)StaticInit_NetTransferMsg, (void*)StaticInit_NPCInfoObject, (void*)StaticInit_camera, (void*)StaticInit_GenInfoObject, (void*)StaticInit_wpnEnums, (void*)StaticInit_guiScrollBarWidget, (void*)StaticInit_guiBitmapWidget, (void*)StaticInit_guiMLTextWidget, (void*)StaticInit_guiSliderWidget, (void*)StaticInit_WeaponVisChangeMsg, (void*)StaticInit_NetTransferRecvMsgName, (void*)StaticInit_NetLevelInfoMsgName, (void*)StaticInit_GuiWeaponDisplay, (void*)StaticInit_GuiSaveAgentWidget, (void*)StaticInit_GuiStartMenu, (void*)StaticInit_GuiSubTitleDisplayFactory, (void*)StaticInit_flashlight, (void*)StaticInit_GuiGameScreen, (void*)StaticInit_GuiEndGameAwards, (void*)StaticInit_GuiEndGameObjectivesFactory, (void*)StaticInit_GuiEndGameStatisticsFactory, (void*)StaticInit_GuiMapScreenFactory, (void*)StaticInit_gameCanvas, (void*)StaticInit_guiConstants, (void*)StaticInit_inventory, (void*)StaticInit_NetMsgThrottle, (void*)StaticInit_RegisterActivateBodyToss };
static const unsigned int dat_004D903C[1] = { 0x0 };
extern char D_004E1B00[];
#pragma opt_common_subs off
void mwInit(void) { FunctionList_CallEach(((char*)dat_004D8D10), ((char*)dat_004D903C), D_004E1B00, D_004E1B00); }
static inline void merge_flush_func_00100410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00100410 */

/* merge_units: begin func_00100440 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void __destroy_array(void* block, void (*dtor)(void*, short), unsigned int size, unsigned int n)
{
    char* p = (char*)block + size * n;
    while (n) {
        p -= size;
        dtor(p, -1);
        n--;
    }
}
static inline void merge_flush_func_00100440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00100440 */

/* merge_units: begin func_001004B0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef void (*CD_001004B0)(void*, short);
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
class PAD_001004B0 {
public:
    void* p; unsigned int size; unsigned int n; CD_001004B0 dtor; unsigned int i;
    PAD_001004B0(void* a, unsigned int s, unsigned int c, CD_001004B0 d) { p = a; size = s; n = c; dtor = d; i = n; }
    __declspec(weak) __declspec(DROPDTOR) ~PAD_001004B0() {
        if (i < n && dtor) {
            char* cptr = (char*)p + size * i;
            for (; i > 0; i--) { cptr -= size; dtor(cptr, -1); }
        }
    }
};
extern "C" void __construct_array(void* block, CD_001004B0 ctor, CD_001004B0 dtor, unsigned int size, unsigned int n)
{
    PAD_001004B0 pad(block, size, n, dtor);
    char* cp = (char*)block;
    for (pad.i = 0; pad.i < n; pad.i++, cp += size)
        ctor(cp, 1);
}
static inline void merge_flush_func_001004B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001004B0 */

/* merge_units: begin func_001005E0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef void (*CD_001005E0)(void*, short);
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
class PAD_001005E0 {
public:
    void* p; unsigned int size; unsigned int n; CD_001005E0 dtor; unsigned int i;
    PAD_001005E0(void* a, unsigned int s, unsigned int c, CD_001005E0 d) { p = a; size = s; n = c; dtor = d; i = n; }
    __declspec(weak) __declspec(DROPDTOR) ~PAD_001005E0() {
        if (i < n && dtor) {
            char* cptr = (char*)p + size * i;
            for (; i > 0; i--) { cptr -= size; dtor(cptr, -1); }
        }
    }
};
extern "C" void* func_001005E0(void* block, CD_001005E0 ctor, CD_001005E0 dtor, unsigned int size, unsigned int n)
{
    char* ptr;
    if ((ptr = (char*)block) != 0) {
        unsigned int* p = (unsigned int*)ptr;
        p[0] = size;
        p[1] = n;
        ptr += 16;
        if (ctor) {
            PAD_001005E0 pad(ptr, size, n, dtor);
            char* cp = ptr;
            for (pad.i = 0; pad.i < n; pad.i++, cp += size)
                ctor(cp, 1);
        }
    }
    return ptr;
}
static inline void merge_flush_func_001005E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001005E0 */
