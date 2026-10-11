#include "types.h"
typedef struct { int x0; int x4; int x8; } I2AC300;
typedef struct {
    char pad0[0x74];
    int x74;
    int pad78;
    int x7C;
    char pad80[0xAC - 0x80];
    unsigned char bAC;
    char padAD[0xBC - 0xAD];
    unsigned char bBC;
    char padBD[3];
    I2AC300 cur;
    int xCC;
    char padD0[0x110 - 0xD0];
    int count;
    I2AC300* items;
} S2AC300;
extern void func_004235E0(S2AC300* s, int a, int b);
extern void* func_004294C0(void);
extern void func_00450590(void* p, int a, int b);
void func_002AC300(S2AC300* s, int a, int sel)
{
    func_004235E0(s, a, sel);
    s->xCC = sel;
    if (s->xCC >= 0 && s->xCC < s->count)
    {
        I2AC300* it = &s->items[s->xCC];
        s->cur.x0 = it->x0;
        s->cur.x4 = it->x4;
        s->cur.x8 = it->x8;
    }
    if (s->bBC && !s->bAC) {
        void* p = func_004294C0();
        if (p) {
            int v = s->x7C;
            if (v < 0 || v >= s->count) {
                v = 0;
                if (0 < s->count)
                    v = s->items[0].x4;
            }
            if (s->bBC)
                func_00450590(p, v, v + s->x74);
        }
    }
}