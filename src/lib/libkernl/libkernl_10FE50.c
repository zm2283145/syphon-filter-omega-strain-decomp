typedef struct { char b[64]; } E;
typedef struct { char pad[0x14]; E *base; int n; char pad2[8]; int idx; } R;
E *_sceRpcGetFPacket(R *r) { int i = r->idx % r->n; E *e = &r->base[i]; r->idx = i + 1; return e; }