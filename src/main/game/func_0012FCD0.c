#pragma cplusplus on
typedef struct { char pad[0x2B]; unsigned char b2B; } Sub_0012FCD0;
typedef struct { char pad0[0x62]; unsigned char b62; char p63; unsigned char b64; char pad1[0xB4-0x65]; Sub_0012FCD0* pB4; } Obj_0012FCD0;
extern "C" {
void Awards_Init(void);
void func_002CC3E0(void* p);
}
extern "C" void func_0012FCD0(Obj_0012FCD0* o)
{
    Awards_Init();
    if (o->b64) {
        o->pB4->b2B = 1;
        func_002CC3E0(o->pB4);
    } else if (o->b62) {
        func_002CC3E0(o->pB4);
    }
}