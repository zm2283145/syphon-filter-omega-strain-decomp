#include "types.h"
typedef struct { int a, b, id, c; } S242;
typedef struct { S242 s[8]; char pad[4]; unsigned char b84; } I242;
typedef struct { char pad[0x3524]; I242* f3524; } P242;
typedef struct { char pad[0xD4]; int fd4; int fd8; } T242;
typedef struct { char pad[0x694]; int f694; unsigned char b698; char p699[3]; void* f69c; char pad2[4]; T242* f6a4; unsigned char b6a8; } H242;
typedef struct { char pad[0xF0]; unsigned char bf0; char pad2[0x2B]; int f11c; char pad3[0x1C]; int f13c; } W242;
extern void IeElement_SetText(void*, char*);
extern char D_004A7218[];
extern int WeaponInv_GetHeldClass(I242*);
extern int WeaponInv_GetSpare(I242*, int);
extern int WeaponInv_HasAmmoText(I242*, int);
extern int WeaponInv_GetClip(I242*, int);
extern int sprintf(char*, const char*, ...);
extern int D_004FFD30;
extern W242* WeaponDb_Get(int, int);
void Hud_UpdateAmmoText(H242* h, P242* p) {
    char buf[0x20];
    I242* inv = p->f3524;
    int id;
    W242* w;
    if (inv->b84 != 6) id = inv->s[inv->b84].id;
    else id = -1;
    if (id == -1) {
        IeElement_SetText(h->f69c, D_004A7218);
        h->f694 = h->f6a4->fd8;
        h->b698 = 7;
        return;
    }
    buf[0] = 0;
    if (!h->b6a8 && h->f6a4->fd4 != 1) {
        if ((unsigned char)WeaponInv_GetHeldClass(inv) == 1 || (unsigned char)WeaponInv_GetHeldClass(inv) == 7) {
            sprintf(buf, "%d", WeaponInv_GetSpare(inv, 6));
        } else if (WeaponInv_HasAmmoText(inv, -1)) {
            int a = WeaponInv_GetClip(inv, 6);
            sprintf(buf, "%d/%d", a, WeaponInv_GetSpare(inv, 6));
        }
    }
    IeElement_SetText(h->f69c, buf);
    w = WeaponDb_Get(D_004FFD30, id);
    if (w->bf0 == 7) {
        h->f694 = w->f11c;
        h->b698 = 7;
    } else {
        h->f694 = w->f13c;
        h->b698 = 7;
    }
}
