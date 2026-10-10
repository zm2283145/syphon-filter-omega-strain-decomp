#include "types.h"
typedef struct { char pad[0xC]; unsigned char enabled; char pad2[3]; } SubState;
typedef struct {
    void* vtable;
    int unk4;
    int a, b, c, d, e, f;   /* 0x08..0x1C */
    int index;              /* 0x20 */
    int count;              /* 0x24 */
    unsigned char busy;     /* 0x28 */
    char pad29[0x47];
    SubState sub;           /* 0x70 */
    int last;               /* 0x80 */
} Widget;
extern char D_004E09F0[];
extern void func_00416A90(Widget* w);
extern void func_00417C40(SubState* s);
/* Constructor. */
Widget* func_00417BC0(Widget* w)
{
    SubState* sub;
    func_00416A90(w);
    sub = &w->sub;
    w->vtable = D_004E09F0;
    w->a = 0;
    w->b = 0;
    w->c = 0;
    w->d = 0;
    w->e = 0;
    w->f = 0;
    func_00417C40(sub);
    sub->enabled = 1;
    w->count = 0;
    w->index = -1;
    w->busy = 0;
    w->last = 0;
    return w;
}
