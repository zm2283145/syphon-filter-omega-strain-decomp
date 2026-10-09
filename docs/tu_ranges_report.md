# TU range inference for SFOGame main.bin

Output: `/root/w/tu/tu_ranges.txt` (same format as `pub/tu_ranges.txt`; `?` marks a new file whose name is a guess). Scripts: `/root/w/tu/work/` (`base.py` builds the call/data index, `ext.py` does the extension, `final.py` adds the new files, `emit.py` writes the output, `loo.py` runs the leave-one-out check).

## Coverage

| | files | functions | bytes |
|---|---|---|---|
| anchors (`pub/tu_ranges.txt`) | 132 | 3523 (24.9%) | 1196132 (33.6%) |
| after extending the anchors | 132 | 6051 (42.8%) | 1777988 (49.9%) |
| final (with new `?` files) | 150 | 6645 (47.1%) | 1889228 (53.0%) |

Total: 14123 functions, 3563124 bytes (0x100000-0x4769a4).

## Method

Each file is one contiguous run, so if a function in the gap next to file X is shown to belong to X, every function between X and it belongs to X too. Each gap between two assigned runs L and R is extended from both ends. A side keeps extending while it finds evidence for its own file and stops at the first function with *strong* evidence for any other file. Weak evidence may only bridge up to 3 functions that have no evidence. Strong evidence may bridge any number. The process repeats until nothing changes, because newly assigned functions add class names, data reference points and callers for the next pass.

Evidence for "f belongs to X":
- **data (strong)**: f references an initialised datum d (below 0x4E1D80, not bss). Every user of d is either in X or unassigned. In address order, d sits between two reference points of X that are less than 0x800 apart. A reference point is a datum used only by functions of one file. The data, rodata and vtable sections are laid out in the same TU order as text: the anchor files' private data come out in strictly increasing file order, which is what makes this check work. Isolated reference points that break the local file order are dropped. Strings for template or header code (`*.hh`, `*.h`, `... length error`) are excluded. Weak/template functions refer to pooled copies of these strings in other TUs: they made scriptManager.cc collapse into scriptBase.cc in the leave-one-out test.
- **fptr (strong)**: f's address is stored in initialised non-vtable data (for example script or state tables) that sits between two reference points of X.
- **vt (strong)**: f appears in exactly one vtable V, and V's file is known, either from V's address being between two reference points or from most of V's single-use slots being in X. A vtable is ignored when its slots or its users (ctor/dtor) span more than one assigned file. This is the inline/header-class case (most `c*Msg` classes): the linker keeps one copy of each weak function, from whichever object comes first, so the slots end up in different TUs. Example: the cHotboxMsg vtable is in the hotbox data but slot 0 points into npc.cc.
- **name (strong)**: f's class (from `cX_*`, `Script_cX_*`, `ScriptType_cX_Init`, or the named vtable of a single-vtable slot) maps to X. A class maps to X when the address span of its tagged functions contains only file X, or when no file is in the span and the class name matches the file name (cAgentData -> AgentData.cc, cHotbox -> hotbox.cc, `GOBJ`/`OBJ` suffix ignored).
- **calledby (weak)**: every caller or address-taker of f is in X (static helper).
- **callpriv (weak)**: f calls a function of X whose other callers are all in X.
- **prefix (weak)**: f's descriptive prefix (`Loader_`, `Mem_`, ...) appears only in X.

**Validation (leave one out).** Each of the 82 anchor files with 5 or more functions was removed in turn and the extension rerun with all the others. Of those files' 3,424 functions, only 2 were absorbed by a neighbour (both in SFOLobby_Connect.cc, taken by SFOLobby_Config.cc). Before the template-string, vtable-spread and bss fixes this test lost 145 functions, including all of scriptManager.cc, fileman.cc and vu1model.cc. The extension is therefore conservative: it rarely crosses a real file boundary that has no file string.

**New files** (all marked `?`) were seeded only from:
1. A block of one class's methods that lies wholly inside one gap, with 3 or more tagged functions, and is not a `*Msg` class. Message classes are header/inline and get emitted inside whichever TU uses them, for example cMenuChoiceMsg next to playerControls.cc and cDisableMsg/cEnableMsg dtors among the cHotbox methods. Class blocks that overlap were merged and named after the shortest (base) class.
2. Library families by symbol name (sce*/lg*, libmpeg internal names, newlib `_vf*printf_r`).
3. One header-string cluster (aiMsgs.hh).

After seeding, the same extension pass grew the new files and the anchors again.

## New files

| file | range | functions | seed / notes |
|---|---|---|---|
| `libgraph.c?` | 0x00102A90-0x00102B40 | 3 | new library block: 1 functions matching ^sceGs (sceGsSetDefDispEnv); grown by calledby:2 |
| `libmpeg.c?` | 0x001080C8-0x0010CAF0 | 106 | new library block: 4 functions matching ^(Mpeg_|_sequenceScalable|_picture) (Mpeg_PrintError, _sequenceScalableExtension, _pictureSpatialScalableExtension, _pictureTemporalScalableExtension); grown by callpriv:2, calledby:8, data:10, fptr:4 |
| `libcdvd.c?` | 0x00118420-0x00119E60 | 26 | new library block: 4 functions matching ^sceCd (sceCdSearchFile, sceCdInit, sceCdRead, sceCdReadClock); grown by data:7, calledby:3 |
| `vfiprintf.c?` | 0x0012B520-0x0012B698 | 4 | new library block: 1 functions matching ^_vfiprintf_r$ (_vfiprintf_r); grown by calledby:2 |
| `vfprintf.c?` | 0x0012C290-0x0012DC38 | 6 | new library block: 1 functions matching ^_vfprintf_r$ (_vfprintf_r); grown by calledby:4 |
| `node.cc?` | 0x0015BE80-0x0015D130 | 51 | new: methods of cNode form a contiguous block (0x15be80-0x15c880) with no file string; named after cNode; grown by calledby:6 |
| `envSettings.cc?` | 0x001780A0-0x00178630 | 14 | new: methods of cEnvSettings form a contiguous block (0x1780a0-0x178630) with no file string; named after cEnvSettings; grown by nothing |
| `gameLight.cc?` | 0x00178EF0-0x00179D70 | 35 | new: methods of cGameDirectionalLight, cGameLight, cGameSceneLight form a contiguous block (0x178ef0-0x179d70) with no file string; named after cGameLight; grown by nothing |
| `gameCamera.cc?` | 0x00179EC0-0x00180820 | 126 | new: methods of cGameCamera form a contiguous block (0x17a100-0x180820) with no file string; named after cGameCamera; grown by name:5, vt:4 |
| `usbkb.c?` | 0x00222B78-0x00223FF0 | 27 | new library block: 7 functions matching ^sceUsbKb (sceUsbKbInit, sceUsbKbEnd, sceUsbKbGetInfo, sceUsbKbRead...); grown by calledby:1, data:1 |
| `gameGobjController.cc?` | 0x0022EF70-0x00230240 | 23 | new: methods of cGameGobjController form a contiguous block (0x22f100-0x2301e0) with no file string; named after cGameGobjController; grown by name:3, prefix:1 |
| `NINotice.cc?` | 0x002373A0-0x00237540 | 5 | new: methods of cNINotice form a contiguous block (0x2373a0-0x237540) with no file string; named after cNINotice; grown by nothing |
| `fireObj.cc?` | 0x00261B70-0x002625B0 | 18 | new: methods of cFireObj form a contiguous block (0x261b70-0x2625b0) with no file string; named after cFireObj; grown by nothing |
| `libdbc.c?` | 0x0026A2D0-0x0026B1C8 | 18 | new library block: 12 functions matching ^sceDbc (sceDbcInit, sceDbcSetWorkAddr, sceDbcCreateSocket, sceDbcDeleteSocket...); grown by calledby:2 |
| `aiMsgs.cc?` | 0x0026EBE0-0x00271170 | 94 | new: 12 functions referencing "aiMsgs.hh" packed in 0x26ebe0-0x271170 (inline AI message code, all in one gap); grown by nothing |
| `lgaud.c?` | 0x003241C8-0x00326040 | 27 | new library block: 19 functions matching ^lgAud (lgAudInit, lgAudOpen, lgAudRead, lgAudWrite...); grown by data:5, calledby:3 |
| `libnet.c?` | 0x0034B710-0x0034B710 | 1 | new library block: 1 functions matching ^sceLibnet (sceLibnetInitialize); grown by nothing |
| `group.cc?` | 0x003D96D0-0x003D9910 | 10 | new: methods of cGroup form a contiguous block (0x3d96d0-0x3d9910) with no file string; named after cGroup; grown by nothing |

Notes on new files:
- `gameLight.cc?`: the method blocks of cGameSceneLight, cGameDirectionalLight and cGameLight interleave (0x178EF0-0x179D70), so they are one TU. It is named after the base class cGameLight.
- `gameCamera.cc?`: the cGameCamera methods span 0x17A100-0x180820, with the `Curve_*` helpers inside. A function in this block references "gameCamera.hh". The extension added the cHumanSeenMsg inlines just in front of it.
- `gameGobjController.cc?`: seeded from the cGameGobjController block. "gameGobjController.hh" is referenced inside it, and the cTimerExpiredMsg inlines were added in front.
- `node.cc?` (cNode, between npc.cc and path.cc), `envSettings.cc?`, `fireObj.cc?`, `group.cc?` (Script_cGroup_* between scriptBase.cc and scriptManager.cc), `NINotice.cc?` (5 functions directly before NIEvent.cc; it could be the head of NIEvent.cc, but no evidence joins them).
- Library names are conventional guesses: `libcdvd.c?` (sceCd*), `usbkb.c?`, `libdbc.c?`, `lgaud.c?`, `libgraph.c?` (sceGsSetDefDispEnv plus 2 static callees), `libnet.c?` (only sceLibnetInitialize, nothing joined it), `libmpeg.c?` (`_sequenceScalableExtension` etc. are libmpeg static names; grown left by data evidence to 0x1080C8), and `vfprintf.c?` / `vfiprintf.c?` (newlib builds these two objects from one source).
- Not added (too weak): single functions that reference `Net*Msg.hh` / `*Msg.hh` strings in gaps, such as NetScoreMsg.hh at 0x316370, NetShatterMsg.hh at 0x3166B0, NetWeaponMsg.hh at 0x316A80 and netTaserMsg.hh at 0x27B9C0. NetCreateCharacterMsg.cc suggests that each net message may be its own TU. But several of these singletons are only 0x300 bytes apart, and inline message code is also emitted inside the TUs that use it, so they stay as hints. The same applies to the `Math_*`, `SoftFloat_*` and `String_*` runtime code in 0x100000-0x12EBB8 (newlib/libm objects are mostly one function per file, and the names are invented).

## Extended anchor files

Rows show functions added before (left) and after (right) the anchor range, and the evidence types that justified them. Functions bridged without their own evidence are not counted in the evidence column.

| file | final range | +left | +right | evidence |
|---|---|---|---|---|
| game.cc | 0x0012ECD0-0x00138AB0 | 25 | 2 | vt:2, prefix:2, name:1 |
| weapon.cc | 0x0013F990-0x00147880 | 7 | 2 | name:2, vt:2, calledby:2, data:1 |
| npc.cc | 0x00148480-0x0015B7F0 | 3 | 7 | vt:5, name:2 |
| path.cc | 0x0015D170-0x001651F0 | 10 | 14 | calledby:11, vt:2 |
| machine.cc | 0x00165540-0x00169780 | 9 | 0 | calledby:6, data:1 |
| ai.cc | 0x00169A60-0x0016F910 | 10 | 23 | vt:9, name:5, data:4 |
| hotbox.cc | 0x0016FB50-0x001735E0 | 48 | 34 | name:11, calledby:2, callpriv:1, vt:1 |
| player.cc | 0x00175330-0x00177C60 | 47 | 0 | vt:4 |
| human.cc | 0x00184AF0-0x001BDFE0 | 26 | 20 | calledby:5, name:3, vt:3, data:2, callpriv:2 |
| Loader.cc | 0x001C01D0-0x001C4F20 | 0 | 23 | calledby:16, prefix:1 |
| gameSound.cc | 0x001C61A0-0x001CA750 | 33 | 2 | vt:5, name:2, calledby:2 |
| humanIk.cc | 0x001D8730-0x001DF910 | 0 | 10 | calledby:10 |
| humanCollision.cc | 0x001EB340-0x001EB960 | 3 | 6 | calledby:3, prefix:1 |
| GameGOBJ.cc | 0x002104B0-0x0021C820 | 72 | 27 | name:48, vt:21, calledby:9, callpriv:6, prefix:6, data:2 |
| Generator.cc | 0x0021C830-0x00222880 | 41 | 8 | name:28, vt:9, calledby:1 |
| Objective.cc | 0x00224F30-0x00229B30 | 80 | 6 | name:45, prefix:14, callpriv:14, vt:6, calledby:1 |
| frontend.cc | 0x00229B40-0x00229D30 | 2 | 0 | calledby:2 |
| frontCharacter.cc | 0x00229EB0-0x0022A220 | 0 | 3 | calledby:2 |
| targetManager.cc | 0x0022D4F0-0x0022D630 | 0 | 1 | calledby:1 |
| Checkpoint.cc | 0x0022DCF0-0x0022EF60 | 14 | 8 | name:7, vt:5 |
| SpecFxDefs.cc | 0x00230470-0x00237260 | 2 | 0 | name:2, vt:2 |
| NIEvent.cc | 0x00237550-0x00241AB0 | 33 | 73 | calledby:22, name:14, vt:6, callpriv:2 |
| hud.cc | 0x00241B70-0x00246FF0 | 0 | 3 | calledby:3 |
| playerControls.cc | 0x00247320-0x00250EE0 | 0 | 36 | calledby:30, data:2, prefix:1 |
| pickup_menu.cc | 0x00251040-0x00251060 | 1 | 0 | calledby:1 |
| backpack.cc | 0x00251920-0x00259250 | 57 | 27 | name:33, calledby:5, callpriv:1 |
| grenade.cc | 0x0025AC20-0x0025D730 | 2 | 11 | data:5, vt:3, prefix:2 |
| taser.cc | 0x00262E00-0x00265B90 | 3 | 0 | data:2, callpriv:1 |
| scriptUtils.cc | 0x002674E0-0x002699F0 | 37 | 0 | name:2, vt:2 |
| map.cc | 0x0026C7E0-0x0026EBD0 | 12 | 4 | calledby:5, vt:3 |
| hudTargets.cc | 0x00272AD0-0x00274B20 | 0 | 3 | calledby:1 |
| bullet.cc | 0x002756E0-0x00277E20 | 4 | 1 | calledby:1, data:1 |
| hud_netlobby.cc | 0x0027ADA0-0x0027B880 | 1 | 1 | calledby:2 |
| tank.cc | 0x00282910-0x00287C40 | 19 | 23 | name:24, vt:6, calledby:2 |
| GuiAgentCreate.cc | 0x0028B380-0x0028F760 | 38 | 0 | vt:10, data:4 |
| GuiGameOptions.cc | 0x002995D0-0x0029C590 | 33 | 3 | vt:8, data:4, name:3 |
| GuiEquipmentSetup.cc | 0x002A1CE0-0x002A75E0 | 13 | 43 | vt:8, data:8, calledby:2 |
| GuiMissionList.cc | 0x002AAC60-0x002ACCF0 | 6 | 15 | vt:8 |
| WaterFx.cc | 0x002B1CB0-0x002B4CF0 | 1 | 20 | calledby:13, prefix:8 |
| GuiEquipmentModify.cc | 0x002BD560-0x002C1100 | 17 | 0 | data:7, vt:5, calledby:1 |
| gameFrontEnd.cc | 0x002C7C00-0x002CD6B0 | 6 | 43 | data:5, calledby:3, vt:2, callpriv:1 |
| LargeInt.c | 0x002EFC00-0x002F14E8 | 16 | 0 | calledby:6, data:1 |
| AgentData.cc | 0x0032F130-0x00337AB0 | 136 | 8 | name:39, prefix:8, calledby:8, data:2, vt:1 |
| GuiLobbyScreen.cc | 0x0033CEF0-0x0033D580 | 7 | 0 | vt:2 |
| GuiAgentModify.cc | 0x0033F9C0-0x00343E10 | 34 | 0 | vt:11 |
| GuiNetMessages.cc | 0x00346CC0-0x003497C0 | 19 | 10 | vt:8, data:7 |
| GuiRatings.cc | 0x0034D1D0-0x0034DD20 | 9 | 1 | vt:7 |
| GuiScoresEquip.cc | 0x0035AE80-0x0035FFB0 | 12 | 41 | data:11, vt:6, calledby:1 |
| GuiAgentInfo.cc | 0x00361E70-0x00365900 | 48 | 57 | vt:6, data:2 |
| FileHalPS2.cc | 0x00368F60-0x003698A0 | 3 | 3 | calledby:2, callpriv:1 |
| mem.cc | 0x0036B130-0x0036C960 | 2 | 0 | callpriv:2, prefix:2 |
| xlib.cc | 0x0037B0C0-0x0037F740 | 0 | 2 | calledby:2 |
| texman.cc | 0x0037FEA0-0x00383560 | 0 | 2 | calledby:1 |
| man.cc | 0x003836B0-0x00392260 | 29 | 0 | data:3, calledby:2, prefix:1 |
| gameobj.cc | 0x003926D0-0x00397170 | 65 | 33 | name:3, calledby:2, callpriv:1, data:1 |
| particle.cc | 0x00397A10-0x003A6180 | 4 | 14 | vt:10, calledby:3, data:1 |
| 989snd.c | 0x003A74E0-0x003A8A90 | 20 | 0 | data:3 |
| skeleton.cc | 0x003A9F90-0x003AA500 | 0 | 3 | calledby:3 |
| ska.cc | 0x003AB430-0x003BA7F0 | 166 | 74 | calledby:26, data:13, prefix:6, callpriv:2 |
| skybox.cc | 0x003BBD00-0x003BCC70 | 5 | 4 | name:4, calledby:3 |
| collision.cc | 0x003C0220-0x003C55C0 | 2 | 17 | prefix:6, calledby:6 |
| system.cc | 0x003CAD70-0x003CB4B0 | 0 | 1 | prefix:1 |
| gobj.cc | 0x003CC1F0-0x003CF220 | 36 | 3 | name:12, prefix:8, calledby:2 |
| scriptBase.cc | 0x003D5DD0-0x003D9470 | 0 | 7 | calledby:2 |
| scriptManager.cc | 0x003D9D20-0x003E28E0 | 2 | 0 | calledby:1 |
| character.cc | 0x003E56F0-0x003E5EF0 | 0 | 5 | calledby:3 |
| interface_element.cc | 0x003E7ED0-0x003E9000 | 12 | 0 | vt:1 |
| callback.cc | 0x003E9C20-0x003EA2B0 | 0 | 1 | calledby:1 |
| interface_model.cc | 0x003EEE70-0x003F43B0 | 0 | 51 | calledby:31, vt:6, data:1 |
| NetObj.cc | 0x003FB340-0x003FC810 | 0 | 14 | calledby:10, prefix:1 |
| globalization.cc | 0x003FDB40-0x003FEEE0 | 3 | 7 | calledby:6, prefix:4 |
| materialProperties.cc | 0x00408EA0-0x00409510 | 0 | 11 | calledby:11 |
| GobjMan.cc | 0x0040BF50-0x0040C8E0 | 0 | 1 | calledby:1 |
| MemCard.cc | 0x0040D690-0x0040E4C0 | 1 | 0 | callpriv:1 |
| MovieSubtitles.cc | 0x0040FBC0-0x00412C40 | 2 | 2 | calledby:2, data:2 |
| interface_manager.cc | 0x00412CF0-0x00413E10 | 0 | 1 | calledby:1 |
| guiManager.cc | 0x00418B10-0x004193D0 | 0 | 1 | calledby:1 |
| guiTextWidget.cc | 0x0041BE10-0x0041CE70 | 10 | 5 | vt:2, data:2 |
| guiTextListWidget.cc | 0x00420E10-0x00423080 | 22 | 21 | calledby:6, vt:4, data:2, callpriv:1 |
| guiTextArrayWidget.cc | 0x00425BB0-0x00428000 | 12 | 17 | vt:3, calledby:2, data:2 |
| DME.cc | 0x004292B0-0x0042ACD0 | 5 | 14 | data:4, calledby:2 |
| nellymoser_wrapper.c | 0x0042C1E0-0x0042C960 | 0 | 1 | calledby:1 |
| NetObjectMgr.cc | 0x0042CF30-0x00432150 | 8 | 81 | calledby:18, callpriv:2, vt:2, prefix:1 |
| NPCInfoObject.cc | 0x004321D0-0x00437490 | 2 | 15 | calledby:12, callpriv:1 |
| GenInfoObject.cc | 0x00438AE0-0x0043BA00 | 2 | 14 | calledby:10, data:1, callpriv:1 |
| SFOLobby_Lobby.cc | 0x0044FA70-0x004516E0 | 4 | 3 | calledby:2, data:1 |
| SFOLobby_Main.cc | 0x004518F0-0x004534A0 | 5 | 0 | callpriv:2 |
| GuiSubTitleDisplay.cc | 0x00457AA0-0x00459BB0 | 8 | 6 | vt:4, calledby:3 |
| GuiGameScreen.cc | 0x0045BC10-0x0045F090 | 39 | 0 | vt:7, calledby:1 |
| inventory.cc | 0x004702A0-0x004719B0 | 0 | 6 | calledby:4 |
| NetMsgThrottle.cc | 0x00472050-0x00472370 | 3 | 1 | calledby:4 |

Per-file notes on non-trivial decisions:
- **hotbox.cc** (anchor: 1 function, 0x170E20): extended to 0x16FB50-0x1735E0, covering Script_cHotbox_*, ScriptType_cHotbox_Init, cHotbox_v01/v43, ctor, dtor and ctor2 by class name. The cHotboxMsg_v01 at 0x16FA30 stays outside: it is an inline message virtual and nothing ties it to either side.
- **GameGOBJ.cc** +72 left: Lift_*/PathObj_* and the cGameGOBJ-family Script wrappers (name:48, vt:21).
- **Objective.cc** +80 left: cObjective script wrappers and ObjMan_* (name/prefix/callpriv).
- **AgentData.cc** +136 left: the cAgentData block (0x32F130-0x3339E0, 38 named methods) is matched by class name to AgentData.cc, which starts at 0x336460.
- **ska.cc** +166 left / +74 right: the Anim*/SkaClip*/RootCollection* animation runtime. The data hits (rodata between ska.cc reference points) recur every few functions all the way down to AnimModel_InitAnim at 0x3AB430. BoneScales_Init at 0x3AA5B0, between skeleton.cc and ska.cc, is left open.
- **backpack.cc** +57 left: cBackpack methods, matched by class name.
- **gameobj.cc** +65 left / +33 right, **GuiAgentInfo.cc** +48/+57, **interface_model.cc** +51 right, **NIEvent.cc** +33/+73: the right-hand growth is mostly vt and static-helper chains.
- **scriptBase.cc / scriptManager.cc**: the Script_cGroup_* block between them is kept as its own `group.cc?`. Both neighbours call into it, and nothing joins it to either side.
- **mem.cc / hog.cc / fileman.cc**: 0x36CA70-0x36CAC0 (3 functions, between mem.cc and hog.cc) and 0x36D200-0x36D630 (9 functions, between hog.cc and fileman.cc, called from many modules) stay unassigned. In the leave-one-out run, Hog_Register's `Hog_` prefix had pulled fileman.cc into hog.cc, so prefixes are now only weak evidence.
- Messages (`c*Msg` dtors and virtuals) are only taken into a file when they lie between functions that are strongly tied to that file. Most remaining unassigned named functions are such inlines (80 class-tagged functions remain unassigned, almost all `*Msg`).

## Remaining gaps

The largest unassigned stretches (by bytes) are: 0x001EB990-0x002103A0 (455 functions, humanCollision.cc..GameGOBJ.cc); 0x002CD9F0-0x002EFB28 (643 functions, gameFrontEnd.cc..LargeInt.c); 0x002F4A10-0x00310D20 (564 functions, RSA.c..rt_xmlparse.c); 0x00119F58-0x0012B398 (211 functions, libcdvd.c?..vfiprintf.c?); 0x0045F1A0-0x00470270 (560 functions, GuiGameScreen.cc..inventory.cc); 0x003135E0-0x00324140 (335 functions, rt_xmlparse.c..lgaud.c?); 0x001CA7D0-0x001D8720 (118 functions, gameSound.cc..humanIk.cc); 0x001DF980-0x001EB310 (152 functions, humanIk.cc..humanCollision.cc). They hold many files without file strings and with mostly unnamed functions. As more functions are named, rerunning `final.py` then `emit.py` will extend coverage automatically (class names feed the strongest evidence).
