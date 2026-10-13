typedef struct { char pad[0x64]; int a; int b; char pad2[0x7C - 0x6C]; unsigned char kind; char pad3[3]; char text[4]; } O3534A0;
typedef struct { char d[12]; } Str3534A0;
extern void *Gui_GetScreenList(void);
extern O3534A0 *func_00418A80(void *mgr, char *type, char *name);
extern void String_CtorCStr_13B480(Str3534A0 *s, char *c);
extern void func_0013D680(void *dst, Str3534A0 *s);
extern void func_00138B70(Str3534A0 *s, int flags);
O3534A0 *func_003534A0(unsigned char kind)
{
    char *name;
    char *text;
    int a = 2;
    int b = 1;
    O3534A0 *o;
    switch (kind) {
    case 0:
        name = "SARATING";
        text = "CSUBMENU";
        a = 3;
        b = 0x1A;
        break;
    case 1:
        name = "COMENDAT";
        text = "CSUBMENU";
        a = 4;
        break;
    case 2:
        name = "MEDALS";
        text = "CSUBMENU";
        break;
    default:
        return 0;
    }
    o = func_00418A80(Gui_GetScreenList(), "GuiAchievementScreen", name);
    if (o == 0)
        return 0;
    o->kind = kind;
    {
        Str3534A0 s;
        String_CtorCStr_13B480(&s, text);
        func_0013D680(o->text, &s);
        func_00138B70(&s, 0);
    }
    o->a = a;
    o->b = b;
    return o;
}