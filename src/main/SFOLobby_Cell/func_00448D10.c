#include "types.h"
typedef struct { char c[21]; } S21;
int SFOLobby_NoInstance();
int SFOLobby_SetError(char *, int, char *, int);
extern char D_004C0D10;
extern char *D_00585E60;
typedef struct { S21 name; int a; } R4D;
void func_00448D10(int d0, int d1, int d2, R4D *src) {
    if (SFOLobby_NoInstance() == 0) {
        R4D *d;
        *(int *)(D_00585E60 + 0x1D8) = 1;
        if (src->a != 0) SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x718);
        d = (R4D *)(D_00585E60 + 0xBF0);
        d->name = src->name;
        d->a = src->a;
        switch (src->a) {
        case 0:
            break;
        case -956:
            SFOLobby_SetError(D_00585E60, 0x2A, &D_004C0D10, 0x725);
            break;
        case -991:
        case -988:
        case -989:
        case -990:
        case -5:
        case -985:
            break;
        }
    }
}
