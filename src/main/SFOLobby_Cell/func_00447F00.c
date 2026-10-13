#include "types.h"
typedef struct { char c[21]; } S21;
typedef struct { char c[32]; } S32;
typedef struct { char c[256]; } S256;
int SFOLobby_NoInstance();
int SFOLobby_SetError(char *, int, char *, int);
extern char D_004C0D10;
extern char *D_00585E60;
typedef struct { S21 name; int a; int b; int c; S32 d; S256 e; int f; } R47;
void func_00447F00(int d0, int d1, int d2, R47 *src) {
    if (SFOLobby_NoInstance() == 0) {
        R47 *d;
        *(int *)(D_00585E60 + 0x1EC) = 1;
        switch (src->a) {
        case 0:
        case -971:
            break;
        case -991:
        case -989:
        case -988:
        default:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x99F);
            break;
        }
        d = (R47 *)(D_00585E60 + 0x1394);
        d->name = src->name;
        d->a = src->a;
        d->b = src->b;
        d->c = src->c;
        d->d = src->d;
        d->e = src->e;
        d->f = src->f;
    }
}
