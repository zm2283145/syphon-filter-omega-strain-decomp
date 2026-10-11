typedef struct { unsigned char b[12]; } ScfAddr12;
typedef struct { unsigned char b[4]; } ScfU32u;
extern char *func_002FAED0(void *pkt);
extern unsigned int func_002FAEE8(void *pkt);
#define SCF_PKT_GET12(name, off) int name(void *pkt, ScfAddr12 *out) { int ret = 1; if (pkt == 0) return ret; if (out == 0) return ret; *out = *(ScfAddr12 *)(func_002FAED0(pkt) + off); return 0; }
#define SCF_PKT_SET12(name, off) int name(void *pkt, ScfAddr12 *in) { int ret = 1; if (pkt == 0) return ret; if (in == 0) return ret; *(ScfAddr12 *)(func_002FAED0(pkt) + off) = *in; return 0; }
SCF_PKT_GET12(func_00308F58, 12)
