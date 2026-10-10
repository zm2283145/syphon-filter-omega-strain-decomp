#include "types.h"
typedef struct { char pad[0x6C]; float timer; int text; } B8_Ckpt;
typedef struct { char pad[0x280]; int fonts[1]; } B8_Res;
extern char D_004F7960;
extern B8_Res* func_001698C0(void);
extern int func_0036AA50(int font, int text, int flags);
extern int func_003D1020(void);
extern void func_003D0EF0(int ctx, int text, int font, float* col, int x, int y);
void cCheckpoint_v10(B8_Ckpt* p, float dt) {
    float col[4];
    int w;
    int font;
    char idx;
    float a;
    if (p->text == 0 || p->timer < 0.0f) return;
    a = (p->timer < 1.0f) ? p->timer : 1.0f;
    col[0] = 0.65f;
    col[1] = 0.7f;
    col[2] = 1.0f;
    col[3] = a;
    idx = D_004F7960;
    font = *(int*)((unsigned char)idx * 4 + (int)func_001698C0() + 0x280);
    w = func_0036AA50(font, p->text, 0x200);
    func_003D0EF0(func_003D1020(), p->text, font, col, -(w / 2), 0);
    p->timer -= dt;
}