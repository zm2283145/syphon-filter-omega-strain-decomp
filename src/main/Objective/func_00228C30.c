#pragma cplusplus on
#include "types.h"

struct Obj8C30 {
    char pad[0x24]; signed char x24; char p25[2]; signed char x27; signed char max; signed char cur;
    char p2A[0x3A]; char* x64; char* x68; char p6C[4]; int x70; char p74[4]; char* name;
    void Format();
    int Remaining() { return max - cur; }
};

extern "C" {
extern void* ObjMan_GetService(void);
extern void ObjMan_Notify(void* m, char* text);
extern int sprintf(char*, const char*, ...);
extern char D_004A5DA0[];
extern char D_004A5DC0[];
extern char D_004A5DE0[];
extern char D_004A5E00[];
}

extern "C" void Objective_FormatStatusText(Obj8C30* self)
{
    int c, mx;
    char buf[0x80];
    void* m = ObjMan_GetService();
    self->cur++;
    mx = self->max; c = self->cur;
    if (c >= mx) {
        self->x24 = 1;
        sprintf(buf, D_004A5DA0, self->name, c, mx);
        return;
    }
    if (self->name == 0)
        return;
    switch (self->x27) {
    case 0:
        c = mx - c;
        if (c > 1)
            sprintf(buf, D_004A5DC0, self->name, c, self->x64);
        else
            sprintf(buf, D_004A5DE0, self->name, c, self->x68);
        break;
    case 1:
        sprintf(buf, D_004A5E00, self->x70);
        break;
    }
    ObjMan_Notify(m, buf);
}


