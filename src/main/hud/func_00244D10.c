#pragma cplusplus on
#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } Tx_244D10;
typedef struct { char pad[0x14]; unsigned short flags; char pad16[0x32]; char sub[4]; } Ob_244D10;
typedef struct { float time; unsigned char b4; char pad5[3]; float f8; unsigned char bC; char padD[3]; Ob_244D10* obj; Tx_244D10* text; } T_244D10;
typedef struct { float r, g, b, a; } Col_244D10;
extern "C" int ScriptEvent_TimeFormat(char* buf, float seconds);
extern "C" void func_0041C070(Tx_244D10* t, Col_244D10* c);
extern "C" void func_0041BEB0(Tx_244D10* t, char* text, int zero);
extern "C" int func_002071F0(void* p);

extern "C" bool func_00244D10(T_244D10* t, float now)
{
    unsigned char running = t->time > now;
    bool expired = 0;
    if (t->b4 && !running) {
        t->b4 = 0;
        t->f8 = 5.0f + now;
        expired = 1;
    }
    t->b4 = running;
    if (t->text && t->obj) {
        t->text->flags &= ~2;
        t->obj->flags &= ~2;
        if (t->b4 || t->f8 > now) {
            char buf[16];
            Col_244D10 c;
            bool show;
            ScriptEvent_TimeFormat(buf, t->b4 ? t->time - now : 0.0f);
            c.r = 1.0f;
            c.g = 1.0f;
            c.b = 1.0f;
            c.a = 1.0f;
            show = 1;
            if (t->f8 > now) {
                if ((int)((t->f8 - now) / 0.25f) & 1) {
                    c.b = 0.3f;
                    c.g = 0.3f;
                } else {
                    show = 0;
                }
            }
            if (show) {
                func_0041C070(t->text, &c);
                func_0041BEB0(t->text, buf, 0);
                t->text->flags |= 2;
                if (func_002071F0(t->obj->sub))
                    t->obj->flags |= 2;
            }
            t->bC = show;
        } else {
            t->f8 = 0.0f;
        }
    }
    return expired;
}


