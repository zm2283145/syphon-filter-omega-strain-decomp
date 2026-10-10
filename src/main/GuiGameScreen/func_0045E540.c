#include "types.h"
typedef struct { char pad[0xC]; unsigned char flag; char padD[3]; } List0045E540;
typedef struct {
    void* vtable;
    char pad4[0x50];
    unsigned char b54, b55;
    char pad56[2];
    int unk58, unk5C, unk60;
    unsigned char b64;
    char pad65[0xB];
    List0045E540 listA;
    List0045E540 listB;
    char pad90[0x48];
    int unkD8;
    int padDC;
    int unkE0, unkE4, unkE8, unkEC;
} Widget0045E540;
extern char D_004E1620[];
extern void GuiWidget_ctor(Widget0045E540* w);
extern void func_001C10A0(List0045E540* list);
extern void func_001396D0(List0045E540* list, int n);
/* Constructor. */
Widget0045E540* func_0045E540(Widget0045E540* w)
{
    List0045E540* b;
    List0045E540* a;
    GuiWidget_ctor(w);
    w->vtable = D_004E1620;
    w->unk58 = 0;
    w->unk5C = 0;
    w->unk60 = 0;
    a = &w->listA;
    func_001C10A0(a);
    a->flag = 1;
    b = &w->listB;
    func_001C10A0(b);
    b->flag = 1;
    w->b55 = 0;
    w->b54 = 0;
    w->b64 = 1;
    w->unkE0 = 0;
    w->unkE4 = 0;
    w->unkE8 = 0;
    w->unkEC = 0;
    func_001396D0(b, 8);
    func_001396D0(a, 8);
    w->unkD8 = 0;
    return w;
}
