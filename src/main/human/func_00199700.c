#pragma cplusplus on
struct P_00199700 { unsigned char b0; char pad[0x17]; int v18; };
struct A_00199700 { char pad[0x33EC]; P_00199700* p; };
extern "C" int Flashlight_GetLitSpot(A_00199700* a)
{
    bool ok = false;
    P_00199700* p = a->p;
    if (p && p->b0) ok = true;
    return ok ? p->v18 : 0;
}