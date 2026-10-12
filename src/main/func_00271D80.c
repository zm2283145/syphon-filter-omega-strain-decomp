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

extern void func_003EEBE0(int obj, int a, int b);
extern int func_003EEB30(int obj, char* name);
extern int func_00260D50(int obj, char* name);
extern void func_003F4510(int s, float lo, float hi, unsigned char fl);
extern void func_003E8DE0(int o, int on);
extern char* Loc_LookupText(char* key);
extern int func_00272200(int obj, char* name, char* text);
extern char D_004FFC90[];

void func_00271D80(Hud271D80* self) {
    int ctx = *self->ctx;
    int panel;
    char* t;

    func_003EEBE0(ctx, 1, 1);
    panel = func_003EEB30(*self->ctx, "background_panels_group");
    if (panel) {
        self->fC = func_00260D50(panel, "filmstrip");
        if (self->fC) func_003F4510(self->fC, 0.0f, 300.0f, 0);
        self->f14 = func_00260D50(panel, "dotsbottom");
        if (self->f14) func_003F4510(self->f14, 0.0f, 60.0f, 0);
        /* retail "bar" sits 8-aligned with padding: the embedded NUL makes it a 5-byte literal */
        self->f10 = func_00260D50(panel, "bar\0");
        if (self->f10) func_003F4510(self->f10, 0.0f, 60.0f, 0);
        self->f8 = func_00260D50(panel, "background_text");
        if (self->f8) func_003F4510(self->f8, 0.0f, 60.0f, 0);
    }
    self->f24 = func_00260D50(ctx, "pressx");
    if (self->f24) func_003E8DE0(self->f24, 0);
    t = Loc_LookupText("Continue");
    if (t) self->f38 = func_00272200(ctx, "loading_data_text", t);
    if (self->f38) func_003E8DE0(self->f38, 0);
    self->f28 = func_00260D50(ctx, "host");
    if (self->f28) func_003E8DE0(self->f28, 0);
    self->f18 = func_00260D50(ctx, "whiteflash");
    if (self->f18) func_003F4510(self->f18, 0.0f, 17.0f, 0);
    self->f1C = func_00260D50(ctx, "backgroundmap1");
    if (self->f1C) func_003F4510(self->f1C, 0.0f, 300.0f, 0);
    self->f20 = func_00260D50(ctx, "backgroundmap2");
    if (self->f20) func_003F4510(self->f20, 0.0f, 300.0f, 0);
    t = Loc_LookupText("level_techname1");
    if (!t) t = Loc_LookupText("level_name");
    self->f30 = func_00272200(ctx, "levelname1", t ? t : D_004FFC90);
    t = Loc_LookupText("level_techname2");
    if (t) self->f34 = func_00272200(ctx, "levelname2", t);
    t = Loc_LookupText("level_briefing");
    if (t) self->f2C = func_00272200(ctx, "briefing", t);
}



