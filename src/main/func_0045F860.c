#include "types.h"

typedef struct F860W {
    char pad00[0x14];
    unsigned short flags;
} F860W;

typedef struct F860Slot {
    F860W* w;
    char pad04[0x14];
} F860Slot;

typedef struct F860X {
    char pad00[0x34];
    float x;
    float y;
} F860X;

typedef struct F860 {
    char pad00[0x48];
    F860Slot slots[15];
    F860X* anchor;
    int layout;
} F860;

extern int D_00497B20[][3];
extern void func_0041E0F0(F860* self, F860W* w, int a, int b, int c);
extern void func_0041EBA0(float x, float y, F860W* w);

void func_0045F860(F860* self) {
    int i;
    F860Slot* s;
    F860X* a;
    float ax;
    float ay;
    int rows;
    int j;
    float y;
    int r;
    int n;
    float x;
    float yy;
    int c;
    int k;

    for (i = 0; i < 15; i++) {
        if (self->slots[i].w) {
            self->slots[i].w->flags &= ~2;
            func_0041E0F0(self, self->slots[i].w, 10, 0, 0);
        } else {
            return;
        }
    }
    if (self->layout <= 0 || self->layout >= 16 || (a = self->anchor) == 0)
        return;
    rows = 0;
    ax = a->x;
    ay = a->y;
    for (j = 0; j < 3; j++) {
        if (D_00497B20[self->layout - 1][j])
            rows++;
    }
    y = -120.0f;
    y = ((3 - rows) * y) / 2.0f;
    k = 0;
    for (r = 0; r < rows; r++) {
        n = D_00497B20[self->layout - 1][r];
        x = 120.0f;
        x = ((5 - n) * x) / 2.0f;
        for (c = 0; c < n; c++) {
            func_0041EBA0(ax + x, ay + y, self->slots[k].w);
            k++;
            x += 120.0f;
        }
        y += -120.0f;
    }
}



