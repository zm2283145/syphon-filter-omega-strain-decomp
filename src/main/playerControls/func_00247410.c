#pragma cplusplus on
#include "types.h"
struct St_247410 {
    char pad[0x20]; int id; char pad24[0xC]; int prev; char pad34[4]; int cur;
    bool Entered(int s) { bool np = !(prev == s); return np && cur == s; }
    bool Left(int s) { return prev == s && !(cur == s); }
    bool Involves(int s) { return prev == s || cur == s; }
    bool NotIn(int s) { return !(prev == s) && !(cur == s); }
};
typedef struct { float a; float b; } HEnt_247410;
typedef struct { int x; int y; } Tmp_247410;
extern "C" {
void* func_002477E0(Tmp_247410* t, float f);
void func_002477C0(char* h, void* e);
void ActorHeading_RetargetLast(char* h, float f);
int func_002477B0(char* h);
void func_00247720(char* h, int id);
HEnt_247410* History_At(char* h, int id);
}
extern "C" void func_00247410(St_247410* s, char* a, int on, float f)
{
    float spd;
    if ((s->Entered(5) && s->NotIn(8)) || (s->Entered(8) && s->NotIn(5)) || (s->Entered(5) && s->Entered(8))) {
        if (on && s->id == -1) {
            Tmp_247410 t;
            if (s->cur == 8)
                spd = 0.33f;
            else if (s->cur == 5)
                spd = 1.0f;
            func_002477C0(a + 0x3088, func_002477E0(&t, f));
            ActorHeading_RetargetLast(a + 0x3030, spd);
            s->id = func_002477B0(a + 0x3030);
        }
    } else if ((s->Left(5) && s->cur != 8) || (s->Left(8) && s->cur != 5) || (s->Left(5) && s->Left(8))) {
        if (s->id != -1) {
            func_00247720(a + 0x3088, s->id);
            ActorHeading_RetargetLast(a + 0x3030, -1.0f);
            s->id = -1;
        }
    } else if ((s->cur == 5 || s->cur == 8) && on && s->id != -1) {
        History_At(a + 0x3088, s->id)->b = f;
        ActorHeading_RetargetLast(a + 0x3030, -1.0f);
    }
}



