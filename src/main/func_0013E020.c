#pragma cplusplus on
struct P_0013E020 { char pad[0xE8]; unsigned char bE8; };
struct A_0013E020 { char pad[0x3310]; P_0013E020* p; };
extern "C" void* cHuman_GetFloorPoly(A_0013E020* a)
{
    bool ok = false;
    P_0013E020* p = a->p;
    if (p && p->bE8) ok = true;
    return ok ? (char*)p + 0x100 : 0;
}