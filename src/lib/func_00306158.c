typedef struct { int sec; int usec; } ScfTime;
extern int func_003064E0(void *in, ScfTime *tv);
#define SCF_TIME_CONV(name, conv) extern int conv(ScfTime *tv, void *out); int name(void *in, void *out) { ScfTime tv; int ret = 2; if (in == 0) return ret; if (out == 0) return ret; ret = func_003064E0(in, &tv); if (ret != 0) return ret; return conv(&tv, out); }
SCF_TIME_CONV(func_00306158, func_003063D0)
