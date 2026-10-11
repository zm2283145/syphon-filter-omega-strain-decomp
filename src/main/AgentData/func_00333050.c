extern __int128 func_003FDA40(const char* s);
extern int func_003308E0(__int128 key);
typedef struct { char pad[0xB08]; unsigned int bits[1]; } AgentD3050;
void cAgentData_UnlockWeapon(AgentD3050* self, const char* name)
{
    int i = func_003308E0(func_003FDA40(name));
    if (i > -1)
        self->bits[i / 32] |= 1 << (i & 31);
}