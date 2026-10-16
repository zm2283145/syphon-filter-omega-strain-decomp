typedef struct {
    char pad0[0x88];
    void *ui;
    char pad8C[0xA8 - 0x8C];
    void *cur;
    char padAC[0xC8 - 0xAC];
    char a[0xE4 - 0xC8];
    char b[4];
} Obj;
extern void *DME_GetLobby(void);
extern void func_004515F0(void *p, int v);
extern void GuiArrayWidget_Select(void *p, int a, int b);
extern void func_002ABF40(void *p, unsigned char mode);
extern void func_002ACC80(void *p, void *cur);

void func_0033D8E0(Obj *o, unsigned char mode)
{
    if (mode == 1 || mode == 3 || mode == 2) {
        if (o->cur != o->a) {
            if (DME_GetLobby()) {
                func_004515F0(DME_GetLobby(), 0);
            }
            o->cur = o->a;
        }
        o->cur = o->a;
    } else if (mode == 0) {
        if (o->cur != o->b) {
            if (DME_GetLobby()) {
                func_004515F0(DME_GetLobby(), 1);
            }
            o->cur = o->b;
        }
    }
    if (o->ui) {
        GuiArrayWidget_Select(o->ui, 0, 0);
        func_002ABF40(o->ui, mode);
        func_002ACC80(o->ui, o->cur);
    }
}


