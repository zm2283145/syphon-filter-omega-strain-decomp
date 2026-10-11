#include "types.h"
typedef struct { char pad[0xC]; char f0C[4]; } Gen00221460;
extern unsigned char D_005721C8;
extern void func_003CE790(Gen00221460* self, int a);
extern void func_0043B190(void* msg);
extern void func_0043A030(void* msg, void* target);
void cGenerator_v16(Gen00221460* self)
{
    func_003CE790(self, 0);
    if (D_005721C8) {
        int msg[1];
        func_0043B190(msg);
        func_0043A030(msg, self->f0C);
    }
}