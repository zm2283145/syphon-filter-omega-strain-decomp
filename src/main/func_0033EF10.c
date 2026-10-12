typedef struct { char pad[0x110]; int busy; } UI;
typedef struct O { char pad[0x88]; UI *ui; int pad8C; int mode; } O;
extern void *D_004FFC04;
extern char D_004B9C60[];
extern void func_002ABF00(UI *ui);
extern void *func_004147A0(void);
extern void func_00414B30(void *mgr, UI *ui);
extern char *func_0033CE30(O *o, int a, char *b, char *c, int d, int e);
extern int func_002CAE30(void *ui, int a, char *b, char *c, void *d, int e);

int func_0033EF10(O *o, unsigned char mode, int flag)
{
    o->mode = mode;
    if (o->ui) {
        int id;
        void *dlg;
        func_002ABF00(o->ui);
        if (o->ui->busy) {
            if (flag)
                func_00414B30(func_004147A0(), o->ui);
            return 1;
        }
        switch (mode) {
        case 0: id = 0x11; break;
        case 1: id = 0x12; break;
        case 2: id = 0x10; break;
        case 3: id = 0x13; break;
        default: return 1;
        }        dlg = D_004FFC04;
        func_002CAE30(dlg, 2, D_004B9C60, func_0033CE30(o, id, 0, 0, 0, 0), 0, 0);
    }
    return 0;
}


