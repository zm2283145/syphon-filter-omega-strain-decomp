typedef struct { int sec; int usec; } ScfTime;
extern int func_00306488(ScfTime *tv);
#define SCF_TIME_GET(name, conv) extern int conv(ScfTime *tv, void *out); int name(void *out) { ScfTime tv; int ret = 2; if (out == 0) return ret; ret = func_00306488(&tv); if (ret != 0) return ret; return conv(&tv, out); }
SCF_TIME_GET(func_00306078, TimeVal_ToSeconds)
