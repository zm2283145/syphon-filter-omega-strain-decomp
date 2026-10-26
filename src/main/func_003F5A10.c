#include "types.h"
typedef struct { char pad[0x48]; char x48[0x60]; int xA8; } G3S_003F5A10;
extern void viBufReset(void* p);
extern void voBufReset(void* p);
extern void Movie_DecodeThread(G3S_003F5A10* s);
extern char D_0055C460[];
extern volatile int D_0055C46C;
void videoDecMain(G3S_003F5A10* s) {
    viBufReset(s->x48);
    voBufReset(D_0055C460);
    Movie_DecodeThread(s);
    while (D_0055C46C) {
    }
    s->xA8 = 3;
}