#pragma cplusplus on
class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void f64(int h, int n);
    virtual void f68(int h);
};

typedef struct {
    char pad[0xC];
    unsigned char type;
    char padD[0x14 - 0xD];
    int value;
} Prop;

typedef struct {
    char pad[0x29];
    unsigned char f29;
    char pad2A[0x2D - 0x2A];
    unsigned char f2D;
    char pad2E[0x37 - 0x2E];
    unsigned char f37;
} Self7D90;

extern "C" {
extern void func_002C7C40(char* s, int n);
extern void func_002C81D0(Self7D90* self);
extern void func_002C82F0(Self7D90* self);
extern long long func_003698B0(unsigned char on);
extern int Gui_GetScreenList(void);
extern VObj* Gui_GetScreenStack(void);
extern int func_00418A80(int a, char* b, char* c);
extern void GuiManager_Update(int a, float f);
extern int func_0041DB80(int h, char* name);
extern int func_0041E0F0(VObj* o, int h, int n, int name, int out);
extern char D_004ACEA8[];
extern char D_004ACEB0[];
extern char D_004ACEB8[];
extern char D_004ACEC8[];
extern char D_004ACED8[];
extern unsigned char D_004FFBB2;
extern int D_0051EF78;
extern int D_0051EF80;
extern int D_0051EF88;
extern int D_0051EF90;
extern unsigned char D_00587B38;
}

extern "C" void FrontEnd_SetLoadingScreen(Self7D90* self, int on, char* a, char* b)
{
    if (self->f37) {
        return;
    }
    if ((unsigned char)on == self->f2D) {
        return;
    }
    if (!self->f29) {
        return;
    }
    if (on) {
        D_0051EF78 = func_003698B0((unsigned char)on);
    }
    if (!D_004FFBB2) {
        if (on) {
            func_002C7C40(D_004ACEA8, 3000);
        }
        return;
    }
    if (on) {
        D_00587B38 = 1;
        a = a ? a : D_004ACEB0;
        b = b ? b : D_004ACEB8;
        D_0051EF80 = func_00418A80(Gui_GetScreenList(), b, a);
        {
            VObj* o = Gui_GetScreenStack();
            o->f64(D_0051EF80, 1000);
        }
        self->f2D = 1;
        D_0051EF90 = 0;
        if (D_0051EF80) {
            D_0051EF88 = func_0041DB80(D_0051EF80, D_004ACEC8);
            {
                int h = D_0051EF88;
                if (h) {
                    Prop* p = 0;
                    if (func_0041E0F0(Gui_GetScreenStack(), h, 4, (int)D_004ACED8, (int)&p) && p->type == 1) {
                        D_0051EF90 = p->value;
                    }
                }
            }
        }
        func_002C82F0(self);
    } else {
        func_002C81D0(self);
        {
            VObj* o = Gui_GetScreenStack();
            o->f68(D_0051EF80);
        }
        GuiManager_Update(Gui_GetScreenList(), 0.0f);
        D_00587B38 = 0;
        D_0051EF80 = 0;
        D_0051EF88 = 0;
        self->f2D = 0;
    }
}
