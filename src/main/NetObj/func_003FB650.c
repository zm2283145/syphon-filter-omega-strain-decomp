#include "types.h"

typedef struct NetRecvE6 {
    int key;
    int handler;
    int context;
} NetRecvE6;

extern unsigned char D_005721C8;
extern char D_0055C7A0[];
extern signed char D_0055C9B8;
extern int D_0055C9C0;
extern int D_0055C9C4;
extern unsigned char D_0055C9C8;
extern int D_0055C9CC;
extern int D_0055C9D0;
extern NetRecvE6* NetRecvMap_Insert(void* map, int* key);

/* Binds a receiver to a net id; offline returns a static dummy slot. */
int* NetMap_BindReceiver(int id, int context, int handler)
{
    int key[1];
    key[0] = id;
    if (D_005721C8) {
        NetRecvMap_Insert(D_0055C7A0, key)->handler = handler;
        NetRecvMap_Insert(D_0055C7A0, key)->context = context;
        return &NetRecvMap_Insert(D_0055C7A0, key)->handler;
    }
    if (D_0055C9B8 == 0) {
        D_0055C9C0 = 0;
        D_0055C9C4 = -1;
        D_0055C9C8 = 0;
        D_0055C9CC = 0;
        D_0055C9D0 = 0;
        D_0055C9B8 = 1;
    }
    return &D_0055C9C0;
}