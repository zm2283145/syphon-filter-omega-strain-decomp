extern void Libc_Abort(void);
void std_dthandler(void) { Libc_Abort(); }