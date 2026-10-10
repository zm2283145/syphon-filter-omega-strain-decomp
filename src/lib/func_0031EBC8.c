#include "types.h"
typedef struct {
    int pad0[2];
    float scale;
    int padC;
    short count;
    short pad12;
    signed char mode;
    signed char state;
} g2Det;
char func_0031EBC8(short level, unsigned short dur, g2Det* d, float val) {
    int th = level < 255 ? level : 255;
    if (d->mode == 1) {
        d->count = 0;
        if (d->state == 0 && val >= (float)th) {
            d->state = 1;
        }
    } else {
        short lim = (unsigned int)(dur * d->scale + 0.5f);
        d->count++;
        if (lim < d->count) {
            d->state = 0;
            if (d->count > 0x7FBC) {
                d->count = 0x7FBC;
            }
        }
    }
    return d->state;
}