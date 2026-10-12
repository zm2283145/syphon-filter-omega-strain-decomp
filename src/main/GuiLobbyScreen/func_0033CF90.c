typedef struct O O;
extern void *D_004FFC04;
extern char D_004B99D8[];
extern void *func_004294C0(void);
extern int func_0033D0C0(O *o, void *snd, unsigned short msg, int param, int extra);
extern char *func_0033CE30(O *o, unsigned char a, char *b, char *c, int d, int e);
extern int func_002CAE30(void *ui, int a, char *b, char *c, void *d, int e);
extern int func_00449770(void *p);
extern void func_002CAC80(void *ui, int id);
extern int func_00441CA0(O *o, void *snd, unsigned short msg, int param, int extra);

int func_0033CF90(O *o, void *snd, unsigned short msg, int param, int extra)
{
    if (msg == 0x2000) {
        func_0033D0C0(o, snd, msg, param, extra);
        return 1;
    }
    if (param == 0x13) {
        void *owner = func_004294C0();
        if (owner) {
            void *ui = D_004FFC04;
            int id = func_002CAE30(ui, 0, D_004B99D8, func_0033CE30(o, 0x56, 0, 0, 0, 0), 0, 0);
            if (!func_00449770(owner)) {
                ui = D_004FFC04;
                func_002CAE30(ui, 2, D_004B99D8, func_0033CE30(o, 0x57, 0, 0, 0, 0), 0, 0);
            }
            func_002CAC80(D_004FFC04, id);
        }
        return 1;
    }
    return func_00441CA0(o, snd, msg, param, extra);
}

