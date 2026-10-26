#pragma opt_propagation off
extern char* App_GetInstance(void);
extern void Boot_LoadFonts(char* g);
extern void SetFontColors(int x);
extern void cInterfaceManager_RemoveHogPath(char* a, char* b);
extern void func_00413880(char* a, char* b);
extern void cInterfaceManager_SetHogList(char* a, char* b);
extern void cInterfaceManager_OpenHogOfHog(char* a, char* b);
extern void cInterfaceManager_Init(char* a);
extern int Gui_GetScreenList(void);
extern char* Gui_GetScreenStack(void);
extern void GuiCanvas_Create(char* s);
extern void GuiCanvas_Activate(char* p, int x);
extern void GuiFont_Register(int a, char* b, int c, int d);
extern int sprintf(char* buf, const char* fmt, ...);
extern char D_0048B2F8[];
extern char D_004AD048[];
extern char D_004AD060[];
extern char D_004AD078[];
extern char D_004AD080[];
extern char D_004AD088[];
extern char D_004AD098[];
extern char D_004AD0A8[];
extern char D_004FFB8C[];
extern char g_Video[];
extern int D_00538C60;
extern float D_00539170[4];
extern char D_00571DC0[];

typedef struct {
    unsigned char pad[0x29];
    unsigned char done;
} SelfB8C0;

typedef struct {
    char pad[0x1F0];
    float v[4];
    char pad200[0x2F5 - 0x200];
    char f2F5;
    char f2F6;
} SlotB8C0;

void FrontEnd_CreateCanvas(SelfB8C0* self, int flag)
{
    char buf[0x80];

    if (self->done) {
        return;
    }
    Boot_LoadFonts(App_GetInstance());
    GuiCanvas_Create(flag ? D_004AD048 : D_004AD060);
    {
        char* g = App_GetInstance();
        GuiFont_Register(Gui_GetScreenList(), D_004AD078, *(int*)(g + 0x280), 0);
    }
    {
        char* g = App_GetInstance();
        GuiFont_Register(Gui_GetScreenList(), D_004AD080, *(int*)(g + 0x284), 0);
    }
    {
        char* g = App_GetInstance();
        GuiFont_Register(Gui_GetScreenList(), D_004AD088, *(int*)(g + 0x288), 0);
    }
    SetFontColors(*(int*)(App_GetInstance() + 0x280));
    SetFontColors(*(int*)(App_GetInstance() + 0x284));
    SetFontColors(*(int*)(App_GetInstance() + 0x288));
    Gui_GetScreenStack()[0x51] = 0;
    GuiCanvas_Activate(Gui_GetScreenStack(), 1);
    cInterfaceManager_Init(D_00571DC0);
    cInterfaceManager_SetHogList(D_00571DC0, D_004FFB8C);
    sprintf(buf, D_004AD098, D_0048B2F8);
    func_00413880(D_00571DC0, buf);
    cInterfaceManager_OpenHogOfHog(D_00571DC0, D_004AD0A8);
    cInterfaceManager_RemoveHogPath(D_00571DC0, buf);
    if (!flag) {
        SlotB8C0* s = (SlotB8C0*)(g_Video + D_00538C60 * 0x110);
        float* v = D_00539170;
        s->v[0] = v[0];
        s->v[1] = v[1];
        s->v[2] = v[2];
        s->v[3] = v[3];
        s->f2F5 = 1;
        s->f2F6 = 1;
    }
    self->done = 1;
}
