typedef struct Game {
    char pad0[0x250];
    unsigned char videoMode;
    char pad251[3];
    int width;
    int height;
    float invFps;
    int fps;
} Game;

extern void func_003CBE90(char* name);
extern void func_0045A700(int);
extern char* func_003CBA90(char* key);
extern void printf(char* fmt, ...);
extern int String_CompareNoCase(char* a, char* b);
extern int String_CompareN(char* a, char* b, int n);
extern int strlen(char*);
extern int func_00121BC8(char*);
extern void func_003FE110(int);
extern char* Loc_GetLanguageName(unsigned char id);
extern void Loc_SetLanguage(unsigned char id);
extern char* Loc_GetCurrentLanguageName(void);
extern int func_00129C80(char* a, char* b);

extern int D_004FFD2C;
extern char D_004FFBB5;
extern char D_004FFBB1;
extern int D_00494188;

void Game_LoadIni(Game* g) {
    char* s;
    char* v;
    int i;
    int ukEnglish;
    int j;

    func_003CBE90("SFO_GAME.INI");
    func_0045A700(D_004FFD2C);
    { char* mode = func_003CBA90("BOOT_VIDEOMODE"); printf("videomode: %s\n", mode); }
    { int pal = String_CompareNoCase(func_003CBA90("BOOT_VIDEOMODE"), "PAL") == 0; if (pal) {
        g->videoMode = 2;
        g->width = 0x280;
        g->height = 0x200;
        g->fps = 0x32;
    } else { int pro = String_CompareNoCase(func_003CBA90("BOOT_VIDEOMODE"), "PROSCAN") == 0; if (pro) {
        g->videoMode = 4;
        g->width = 0x280;
        g->height = 0x1E0;
        g->fps = 0x1E;
    } else {
        g->videoMode = 0;
        g->width = 0x280;
        g->height = 0x1C0;
        g->fps = 0x1E;
    } }}
    D_004FFBB5 = 1;
    D_004FFBB1 = 1;
    g->invFps = 1.0f / g->fps;
    { char* net = func_003CBA90("NET_BUFFER_SIZE");
    if (strlen(net) != 0) {
        D_00494188 = func_00121BC8(net);
    } }
    /* retail "1" is an 8-byte, 8-aligned literal: a 4-byte wide string */
    ukEnglish = String_CompareNoCase(func_003CBA90("BOOT_USE_UK_ENGLISH"), (char*)L"1") == 0;
    s = func_003CBA90("BOOT_LANGUAGE");
    if (s && *s) {
        if (String_CompareNoCase(s, "PS2_SETTING") == 0) {
            func_003FE110(ukEnglish);
        } else {
            for (i = 0; i < 7; i++) {
                if (String_CompareNoCase(s, Loc_GetLanguageName(i)) == 0) {
                    Loc_SetLanguage(i);
                    break;
                }
                if (i == 6) {
                    func_003FE110(ukEnglish);
                    break;
                }
            }
        }
    } else {
        func_003FE110(ukEnglish);
    }
    v = func_003CBA90("BOOT_VALID_LANGUAGES");
    if (v && *v) {
        if (func_00129C80(v, Loc_GetCurrentLanguageName()) == 0) {
            for (j = 0; j < 7; j++) {
                char* name = Loc_GetLanguageName(j);
                if (String_CompareN(v, name, strlen(name)) == 0) {
                    Loc_SetLanguage(j);
                    return;
                }
                if (j == 6) {
                    Loc_SetLanguage(0);
                }
            }
        }
    }
}
