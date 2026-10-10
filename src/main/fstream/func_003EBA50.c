#include "types.h"

typedef struct Singleton {
    char b[0xC];
    int unkC;
    int unk10;
    unsigned char unk14;
} Singleton;

extern signed char D_0055A850;
extern int D_0055A858;
extern Singleton D_0055A870;
extern void ScalarCollection_Init(Singleton*);
extern void func_003EB960(void);
extern void __register_global_object(void*, void*, void*);

/* Returns the lazily constructed singleton at D_0055A870. */
Singleton* func_003EBA50(void) {
    if (D_0055A850 == 0) {
        ScalarCollection_Init(&D_0055A870);
        D_0055A870.unkC = 0;
        D_0055A870.unk10 = 0;
        D_0055A870.unk14 = 0;
        __register_global_object(&D_0055A870, func_003EB960, &D_0055A858);
        D_0055A850 = 1;
    }
    return &D_0055A870;
}
