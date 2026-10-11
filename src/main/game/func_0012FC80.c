#pragma cplusplus on
typedef struct { char pad0[0x62]; unsigned char b62; char p63; unsigned char b64; char pad1[0xB4-0x65]; void* pB4; } Obj_0012FC80;
extern "C" {
void func_002CBB30(void* p);
void func_002CBAD0(void* p);
}
extern "C" void func_0012FC80(Obj_0012FC80* o)
{
    if (o->b62 || o->b64) {
        func_002CBB30(o->pB4);
        func_002CBAD0(o->pB4);
    }
}