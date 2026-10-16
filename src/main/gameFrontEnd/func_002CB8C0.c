#pragma opt_propagation off
extern char* App_GetInstance(void);
extern void Boot_LoadFonts(char* g);
extern void func_002CCE80(int x);
extern void func_004136F0(char* a, char* b);
extern void func_00413880(char* a, char* b);
extern void func_004138F0(char* a, char* b);
extern void func_00413900(char* a, char* b);
extern void func_00413C70(char* a);
extern int Gui_GetScreenList(void);
extern char* Gui_GetScreenStack(void);
extern void func_00414900(char* s);
extern void func_004158C0(char* p, int x);
extern void func_004185A0(int a, char* b, int c, int d);
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
extern char D_005381F0[];
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
    func_00414900(flag ? D_004AD048 : D_004AD060);
    {
        char* g = App_GetInstance();
        func_004185A0(Gui_GetScreenList(), D_004AD078, *(int*)(g + 0x280), 0);
    }
    {
        char* g = App_GetInstance();
        func_004185A0(Gui_GetScreenList(), D_004AD080, *(int*)(g + 0x284), 0);
    }
    {
        char* g = App_GetInstance();
        func_004185A0(Gui_GetScreenList(), D_004AD088, *(int*)(g + 0x288), 0);
    }
    func_002CCE80(*(int*)(App_GetInstance() + 0x280));
    func_002CCE80(*(int*)(App_GetInstance() + 0x284));
    func_002CCE80(*(int*)(App_GetInstance() + 0x288));
    Gui_GetScreenStack()[0x51] = 0;
    func_004158C0(Gui_GetScreenStack(), 1);
    func_00413C70(D_00571DC0);
    func_004138F0(D_00571DC0, D_004FFB8C);
    sprintf(buf, D_004AD098, D_0048B2F8);
    func_00413880(D_00571DC0, buf);
    func_00413900(D_00571DC0, D_004AD0A8);
    func_004136F0(D_00571DC0, buf);
    if (!flag) {
        SlotB8C0* s = (SlotB8C0*)(D_005381F0 + D_00538C60 * 0x110);
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
