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
extern void func_0026BE70(int v);
extern void* Service_Lookup(char* a, char* b);
extern void func_001C9540(void* svc, int ch, int v);
extern void func_001C9670(void* svc, int v);
extern char* func_003CBA90(char* key);
extern int String_CompareNoCase(char* a, char* b);
extern void* func_001698C0(void);
extern void func_00165420(void* a, int mode);
void func_0045A3A0(LightCfg_h5* cfg, unsigned int mask)
{
    void* svc;
    if (mask & 1) {
        if (D_004FFC0C) {
            D_004FFC0C->c174 = cfg->b4;
        }
    }
    if (mask & 2) {
        func_0026BE70(cfg->b5);
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
            func_001C9540(svc, 0, (int)(1024.0f * cfg->vol0));
        }
    }
    if (mask & 0x20) {
        svc = Service_Lookup(D_004FFB50, D_004F2CC0);
        if (svc) {
            func_001C9540(svc, 2, (int)(1024.0f * cfg->vol2));
        }
    }
    if (mask & 0x40) {
        svc = Service_Lookup(D_004FFB50, D_004F2CC0);
        if (svc) {
            func_001C9540(svc, 1, (int)(1024.0f * cfg->vol1));
        }
    }
    if (mask & 0x80) {
        svc = Service_Lookup(D_004FFB50, D_004F2CC0);
        if (svc) {
            func_001C9670(svc, cfg->mode14);
        }
    }
    if (mask & 0x400) {
        D_005383C0 = (unsigned char)(int)(191.25f * cfg->level);
    }
    if (mask & 0x800) {
        int same = String_CompareNoCase(func_003CBA90("BOOT_VIDEOMODE"), "PAL") == 0;
        int mode;
        mode = cfg->alt == 0 ? (same ? 2 : 0) : 4;
        func_00165420(func_001698C0(), mode);
    }
}