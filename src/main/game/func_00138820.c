#pragma cplusplus on
struct M_00138820 { char pad[0x24]; signed char b24; char pad2[3]; int x28; unsigned char b2C; unsigned char b2D; };
extern "C" { extern char* D_005061D0; void func_00330F00(int x); void func_00331870(int x); }
static inline void WriteByte(char v) { *D_005061D0 = v; D_005061D0++; }
extern "C" void cNetAgentUpdateMsg_v04(M_00138820* m)
{
    WriteByte(m->b24);
    WriteByte(m->b2C);
    WriteByte(m->b2D);
    if (m->b2C) func_00330F00(m->x28);
    else func_00331870(m->x28);
}