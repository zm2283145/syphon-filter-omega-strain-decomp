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
extern void std_list_deleter_voidPtr_ctor_void(Singleton*);
extern void cFileStreamMan_dtor(void);
extern void __register_global_object(void*, void*, void*);

/* Returns the lazily constructed singleton at D_0055A870. */
Singleton* GetFileStreamMan(void) {
    if (D_0055A850 == 0) {
        std_list_deleter_voidPtr_ctor_void(&D_0055A870);
        D_0055A870.unkC = 0;
        D_0055A870.unk10 = 0;
        D_0055A870.unk14 = 0;
        __register_global_object(&D_0055A870, cFileStreamMan_dtor, &D_0055A858);
        D_0055A850 = 1;
    }
    return &D_0055A870;
}
