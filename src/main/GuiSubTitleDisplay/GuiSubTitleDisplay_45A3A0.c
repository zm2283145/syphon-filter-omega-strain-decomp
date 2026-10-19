/*
 * main/GuiSubTitleDisplay: 3 files, 0045A3A0-0045A700
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045A3A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct LightCfg_h5 {
    int unk0;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    float vol0;
    float vol2;
    float vol1;
    int mode14;
    int unk18;
    float level;
    int alt;
} LightCfg_h5;
typedef struct LightState_h5 {
    char pad[0x174];
    unsigned char c174;
    unsigned char c175;
    unsigned char c176;
} LightState_h5;
extern LightState_h5* D_004FFC0C;
extern char D_004FFB50[];
extern char D_004F2CC0[];
extern int D_005383C0;
extern void Pad_EnableVibration(int v);
extern void* Service_Lookup(char* a, char* b);
extern void SoundMgr_SetChannelVolume(void* svc, int ch, int v);
extern void SoundMgr_SetOutputMode(void* svc, int v);
extern char* GameIni_GetString(char* key);
extern int String_CompareNoCase(char* a, char* b);
extern void* App_GetInstance(void);
extern void Options_SetVideoMode(void* a, int mode);
void GameOptions_Apply(LightCfg_h5* cfg, unsigned int mask)
{
    void* svc;
    if (mask & 1) {
        if (D_004FFC0C) {
            D_004FFC0C->c174 = cfg->b4;
        }
    }
    if (mask & 2) {
        Pad_EnableVibration(cfg->b5);
    }
    if (mask & 4) {
        if (D_004FFC0C) {
            D_004FFC0C->c175 = cfg->b6;
        }
    }
    if (mask & 8) {
        if (D_004FFC0C) {
            D_004FFC0C->c176 = cfg->b7;
        }
    }
    if (mask & 0x10) {
        svc = Service_Lookup(D_004FFB50, D_004F2CC0);
        if (svc) {
            SoundMgr_SetChannelVolume(svc, 0, (int)(1024.0f * cfg->vol0));
        }
    }
    if (mask & 0x20) {
        svc = Service_Lookup(D_004FFB50, D_004F2CC0);
        if (svc) {
            SoundMgr_SetChannelVolume(svc, 2, (int)(1024.0f * cfg->vol2));
        }
    }
    if (mask & 0x40) {
        svc = Service_Lookup(D_004FFB50, D_004F2CC0);
        if (svc) {
            SoundMgr_SetChannelVolume(svc, 1, (int)(1024.0f * cfg->vol1));
        }
    }
    if (mask & 0x80) {
        svc = Service_Lookup(D_004FFB50, D_004F2CC0);
        if (svc) {
            SoundMgr_SetOutputMode(svc, cfg->mode14);
        }
    }
    if (mask & 0x400) {
        D_005383C0 = (unsigned char)(int)(191.25f * cfg->level);
    }
    if (mask & 0x800) {
        int same = String_CompareNoCase(GameIni_GetString("BOOT_VIDEOMODE"), "PAL") == 0;
        int mode;
        mode = cfg->alt == 0 ? (same ? 2 : 0) : 4;
        Options_SetVideoMode(App_GetInstance(), mode);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0045A3A0 */

/* merge_units: begin func_0045A600 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int GameOptions_Diff(char * arg0, char * arg1) {
    int var_v0;

    var_v0 = 0;
    if (F_(arg1, 0x4, unsigned char) != F_(arg0, 0x4, unsigned char)) {
        var_v0 |= 1;
    }
    if (F_(arg1, 0x5, unsigned char) != F_(arg0, 0x5, unsigned char)) {
        var_v0 |= 2;
    }
    if (F_(arg1, 0x6, unsigned char) != F_(arg0, 0x6, unsigned char)) {
        var_v0 |= 4;
    }
    if (F_(arg1, 0x7, unsigned char) != F_(arg0, 0x7, unsigned char)) {
        var_v0 |= 8;
    }
    if (F_(arg1, 0x8, float) != F_(arg0, 0x8, float)) {
        var_v0 |= 0x10;
    }
    if (F_(arg1, 0xC, float) != F_(arg0, 0xC, float)) {
        var_v0 |= 0x20;
    }
    if (F_(arg1, 0x10, float) != F_(arg0, 0x10, float)) {
        var_v0 |= 0x40;
    }
    if (F_(arg1, 0x14, int) != F_(arg0, 0x14, int)) {
        var_v0 |= 0x80;
    }
    if (F_(arg1, 0x1C, float) != F_(arg0, 0x1C, float)) {
        var_v0 |= 0x400;
    }
    if (F_(arg1, 0x20, int) != F_(arg0, 0x20, int)) {
        var_v0 |= 0x800;
    }
    return var_v0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0045A600 */

/* merge_units: begin func_0045A700 */
#pragma push /* merge_units */
typedef struct {
    int unk0;
    unsigned char b4, b5, b6, b7;
    float unk8;
    float unkC;
    float unk10;
    int unk14;
    unsigned char b18, b19;
    char pad1A[2];
    float unk1C;
    int unk20;
} Settings0045A700;
extern Settings0045A700* Options_SetDefaults(Settings0045A700* s);
/* Initialise with defaults, then override three fields. */
void func_0045A700(Settings0045A700* s)
{
    Settings0045A700 def;
    Options_SetDefaults(&def);
    s->unk0 = def.unk0;
    s->b4 = def.b4;
    s->b5 = def.b5;
    s->b6 = def.b6;
    s->b7 = def.b7;
    s->unk8 = def.unk8;
    s->unkC = def.unkC;
    s->unk10 = def.unk10;
    s->unk14 = def.unk14;
    s->b18 = def.b18;
    s->b19 = def.b19;
    s->unk1C = def.unk1C;
    s->unk20 = def.unk20;
    s->b5 = 1;
    s->b4 = 0;
    s->unk20 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0045A700 */
