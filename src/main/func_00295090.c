typedef struct { char pad[0x14]; unsigned short flags; } E295090;
typedef struct { char pad[0x30]; unsigned char b30; } Ui295090;
typedef struct S295090 {
    char pad0[0xF8];
    unsigned char bF8[0x11];
    unsigned char b109;
    char pad10A[0x118 - 0x10A];
    E295090* items[0x18];
    unsigned char b178[0x54];
    int cur;
    E295090* focus;
} S295090;
extern Ui295090* D_004FFC04;
extern int D_005063D0[];
extern void func_00294300(S295090* s, int a);
extern void func_00294C60(S295090* s);
extern void func_00296B70(S295090* s, int a);
extern void func_0041E0F0(void* a, void* b, int c, int d, int e);

void func_00295090(S295090* s, int i, int f)
{
    if (s->focus) {
        if (s->b178[s->cur]) {
            if ((s->cur <= 0x10 && s->bF8[s->cur]) || (s->cur == 0x14 && s->b109))
                func_0041E0F0(s, s->focus, 6, (int)"onStateOn", 0);
            else
                func_0041E0F0(s, s->focus, 6, (int)"onLoseFocus", 0);
        } else {
            func_0041E0F0(s, s->focus, 6, (int)"onStateOff", 0);
        }
        s->cur = -1;
        s->focus = 0;
    }
    if (i < 0 || i >= 0x18)
        return;
    {
        E295090* e = s->items[i];
        if (!e || !(e->flags & 4) || !(e->flags & 2))
            return;
    }
    if (f)
        func_00294300(s, 0);
    s->focus = s->items[i];
    s->cur = i;
    if (s->b178[s->cur])
        func_0041E0F0(s, s->focus, 6, (int)"onGainFocus", 0);
    else
        func_0041E0F0(s, s->focus, 6, (int)"onDeactivate", 0);
    func_00294C60(s);
    if (i > 0x10 || s->b178[s->cur] || D_004FFC04->b30)
        func_00296B70(s, -1);
    else
        func_00296B70(s, D_005063D0[i]);
}

