#pragma cplusplus on

struct Ctx_D3C0 {
    char pad0[0x5A0];
    unsigned char f5A0;
};

struct Pump_D3C0 {
    Ctx_D3C0* ctx;
    bool ok;
    char pad5[3];
    void (*cb)();
    bool err;
};

extern "C" int func_0040E5D0(Ctx_D3C0* ctx);

static inline bool Step(Pump_D3C0* s)
{
    s->ok = func_0040E5D0(s->ctx) != 0;
    if (!s->ok) s->err = 0;
    if (s->cb) s->cb();
    return !s->ok;
}

static inline void Wait(Pump_D3C0* s)
{
    while (!Step(s) || !s->ctx->f5A0) {
    }
}

extern "C" void func_0040D3C0(Pump_D3C0* s)
{
    Wait(s);
    s->ctx->f5A0 = 0;
    Wait(s);
    s->ctx->f5A0 = 0;
    Wait(s);
    s->ctx->f5A0 = 0;
    Wait(s);
}
