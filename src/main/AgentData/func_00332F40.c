#pragma cplusplus on
struct Bits_2F40 {
    int w[1];
    bool test(int n) const { return (w[n / 32] >> (n & 31)) & 1; }
};
typedef struct { char pad[0xB2C]; Bits_2F40 bits; } AgentD2F40;
#pragma opt_propagation off
extern "C" bool AgentData_HasShownUnlock(AgentD2F40* self, unsigned char idx)
{
    int i = idx;
    bool r;
    if (i > -1) r = self->bits.test(i);
    else r = false;
    return r;
}