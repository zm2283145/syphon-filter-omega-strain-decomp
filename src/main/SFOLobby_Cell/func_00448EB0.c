#include "types.h"
typedef struct { char c[21]; } S21;
typedef struct { char c[32]; } S32;
typedef struct { char c[256]; } S256;
int SFOLobby_NoInstance();
int SFOLobby_SetError(char *, int, char *, int);
extern char D_004C0D10;
extern char *D_00585E60;
typedef struct { S21 name; int a; int b; } R4E;
void func_00448EB0(int d0, int d1, int d2, R4E *src) {
    if (SFOLobby_NoInstance() == 0) {
        R4E *d;
        *(int *)(D_00585E60 + 0x1CC) = 1;
        switch (src->a) {
        case 0:
            break;
        case -992:
            SFOLobby_SetError(D_00585E60, 0x1C, &D_004C0D10, 0x6C1);
            break;
        case -970:
            SFOLobby_SetError(D_00585E60, 0x1A, &D_004C0D10, 0x6C6);
            break;
        case -989:
        case -988:
        case -991:
        default:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x6CE);
            break;
        }
        d = (R4E *)(D_00585E60 + 0xBD0);
        d->name = src->name;
        d->a = src->a;
        d->b = src->b;
    }
}
