typedef struct Hud271D80 {
    int* ctx;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
} Hud271D80;

extern void IeNode_SetShown(int obj, int a, int b);
extern int IeNode_FindChild(int obj, char* name);
extern int Hud_FindOrCreateElement(int obj, char* name);
extern void IeElement_PlayRange(int s, float lo, float hi, unsigned char fl);
extern void IeElement_SetShown(int o, int on);
extern char* Loc_LookupText(char* key);
extern int LoadingScreen_SetText(int obj, char* name, char* text);
extern char D_004FFC90[];

void LoadingScreen_Setup(Hud271D80* self) {
    int ctx = *self->ctx;
    int panel;
    char* t;

    IeNode_SetShown(ctx, 1, 1);
    panel = IeNode_FindChild(*self->ctx, "background_panels_group");
    if (panel) {
        self->fC = Hud_FindOrCreateElement(panel, "filmstrip");
        if (self->fC) IeElement_PlayRange(self->fC, 0.0f, 300.0f, 0);
        self->f14 = Hud_FindOrCreateElement(panel, "dotsbottom");
        if (self->f14) IeElement_PlayRange(self->f14, 0.0f, 60.0f, 0);
        /* retail "bar" sits 8-aligned with padding: the embedded NUL makes it a 5-byte literal */
        self->f10 = Hud_FindOrCreateElement(panel, "bar\0");
        if (self->f10) IeElement_PlayRange(self->f10, 0.0f, 60.0f, 0);
        self->f8 = Hud_FindOrCreateElement(panel, "background_text");
        if (self->f8) IeElement_PlayRange(self->f8, 0.0f, 60.0f, 0);
    }
    self->f24 = Hud_FindOrCreateElement(ctx, "pressx");
    if (self->f24) IeElement_SetShown(self->f24, 0);
    t = Loc_LookupText("Continue");
    if (t) self->f38 = LoadingScreen_SetText(ctx, "loading_data_text", t);
    if (self->f38) IeElement_SetShown(self->f38, 0);
    self->f28 = Hud_FindOrCreateElement(ctx, "host");
    if (self->f28) IeElement_SetShown(self->f28, 0);
    self->f18 = Hud_FindOrCreateElement(ctx, "whiteflash");
    if (self->f18) IeElement_PlayRange(self->f18, 0.0f, 17.0f, 0);
    self->f1C = Hud_FindOrCreateElement(ctx, "backgroundmap1");
    if (self->f1C) IeElement_PlayRange(self->f1C, 0.0f, 300.0f, 0);
    self->f20 = Hud_FindOrCreateElement(ctx, "backgroundmap2");
    if (self->f20) IeElement_PlayRange(self->f20, 0.0f, 300.0f, 0);
    t = Loc_LookupText("level_techname1");
    if (!t) t = Loc_LookupText("level_name");
    self->f30 = LoadingScreen_SetText(ctx, "levelname1", t ? t : D_004FFC90);
    t = Loc_LookupText("level_techname2");
    if (t) self->f34 = LoadingScreen_SetText(ctx, "levelname2", t);
    t = Loc_LookupText("level_briefing");
    if (t) self->f2C = LoadingScreen_SetText(ctx, "briefing", t);
}



