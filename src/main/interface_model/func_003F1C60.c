#include "types.h"
#include "interface_model_types.h"

extern void func_003F1E10(char* self, int value);
extern int* func_003F1E20(PtrVec* v, int i);
extern int func_003F1E30(PtrVec* v);

typedef struct Elem3C60 {
    char pad[0x18];
    PtrVec items;
} Elem3C60;
typedef struct V12_3C60 { float x, y, z; } V12_3C60;
typedef struct Item3C60 { char pad[0x1C]; char* link; } Item3C60;

typedef struct Model3C60 {
    char pad0[0x70];
    V12_3C60* dst;
    char pad74[0x0C];
    void** elems;
    char pad84[0x1C];
    char fA0[0x0C];
    char fAC[4];
    char fB0[4];
    char fB4[4];
    char fB8[8];
    char fC0[4];
    char fC4[4];
    char fC8[4];
    char fCC[4];
} Model3C60;

void func_003F1C60(Model3C60* self, RawVec* types)
{
    void** p = self->elems;
    int i;
    for (i = 0; i < types->count; i++, p++) {
        switch ((unsigned char)types->data[i]) {
        case 0: {
            Elem3C60* e = (Elem3C60*)*p;
            V12_3C60* d = self->dst;
            int n = func_003F1E30(&e->items);
            int j;
            for (j = 0; j < n; j++) {
                func_003F1E10((char*)*func_003F1E20(&e->items, j), (int)d++);
            }
            break;
        }
        case 1: ((Item3C60*)*p)->link = self->fA0; break;
        case 2: ((Item3C60*)*p)->link = self->fAC; break;
        case 3: ((Item3C60*)*p)->link = self->fB0; break;
        case 4: ((Item3C60*)*p)->link = self->fB4; break;
        case 5: ((Item3C60*)*p)->link = self->fB8; break;
        case 6: ((Item3C60*)*p)->link = self->fC0; break;
        case 7: ((Item3C60*)*p)->link = self->fC4; break;
        case 8: ((Item3C60*)*p)->link = self->fC8; break;
        case 9: ((Item3C60*)*p)->link = self->fCC; break;
        }
    }
}

