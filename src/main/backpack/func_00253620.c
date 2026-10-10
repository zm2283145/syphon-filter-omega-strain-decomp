#include "types.h"

typedef struct ColorArgs {
    int r, g, b;
    int alpha; /* float passed as a raw word */
} ColorArgs;

extern void Global_SetPickupTextColor(int r, int g, int b, float alpha);

/* Script native: SetPickupTextColor(r, g, b, alpha). */
int Script_SetPickupTextColor(ColorArgs* args) {
    float alpha;
    int b, g, r;
    volatile int wa, wb, wg, wr;
    wa = args->alpha;
    alpha = *(float*)&wa;
    wb = args->b;
    b = wb;
    wg = args->g;
    g = wg;
    wr = args->r;
    r = wr;
    Global_SetPickupTextColor(r, g, b, alpha);
    return 0;
}
