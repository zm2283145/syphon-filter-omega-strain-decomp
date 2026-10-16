#include "types.h"
typedef struct {
    void* vt; char pad04[0x18]; int w1C; signed char kind; char pad21[3]; signed char b24; char pad25[3];
    int id; float f0; float f1; char key[16]; int a3; signed char c0; signed char c1;
} Msg_242E40;
extern unsigned char D_005721C8;
extern char D_0051EE48[];
extern char D_004DE0F0[];
extern int Loc_LookupText(char* key);
extern void Hud_ShowCallout(int a0, int* a1, float f0, float f1, int text, int a3, signed char c0, signed char c1);
extern void Event_Construct(Msg_242E40* m, void* type);
extern char* strncpy(char*, const char*, int);
extern void Transport_Send(int a, Msg_242E40* m, int b, int c);
extern void cMessage_dtor(Msg_242E40* m, int f);

void Hud_SetCalloutLabel(int a0, int* a1, float f0, float f1, char* key, int a3, signed char c0, signed char c1, int send)
{
    int text = Loc_LookupText(key);
    if (text) {
        Hud_ShowCallout(a0, a1, f0, f1, text, a3, c0, c1);
        if (D_005721C8 && send) {
            Msg_242E40 m;
            Msg_242E40* p = &m;
            Event_Construct(p, D_0051EE48);
            m.b24 = 0;
            m.vt = D_004DE0F0;
            m.id = *a1;
            m.f0 = f0;
            m.f1 = f1;
            m.a3 = a3;
            m.c0 = c0;
            m.c1 = c1;
            if (key) {
                strncpy(p->key, key, 16);
            }
            m.w1C = 0x40;
            m.kind = 4;
            Transport_Send(0, &m, -1, -1);
            m.vt = D_004DE0F0;
            cMessage_dtor(&m, 0);
        }
    }
}

