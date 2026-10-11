#include "types.h"
extern unsigned char* D_005061D0;
static inline short R16_00230980(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00230980(void) { unsigned short lo = R16_00230980(); return lo + ((unsigned short)R16_00230980() << 16); }
static inline float RF_00230980(void) { int i = R32_00230980(); return *(float*)&i; }
static inline char R8_00230980(void) { return *D_005061D0++; }
typedef struct { char pad[0x24]; void* obj; float a; float b; } M_00230980;
extern void func_00282160(void* out);
extern void Global_SpawnLight(void* obj, int z, float a, float b);
void func_00230980(M_00230980* m) {
    func_00282160(&m->obj);
    m->a = RF_00230980();
    m->b = RF_00230980();
    Global_SpawnLight(m->obj, 0, m->a, m->b);
}