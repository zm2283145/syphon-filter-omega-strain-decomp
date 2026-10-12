/* Extra linker definitions passed before the splat-generated script. */
ENTRY(_start);
D_0010FBC0 = 0x0010FBC0; /* mid-function entry point called by SDK code (not a splat function start) */
__dl__FPv = 0x00100740; /* mangled operator delete(void*) used by C++ units; same address as operator_delete */
D_0048943C = 0x0048943C; /* data inside a C-owned block, referenced by lib/func_00124D30.c */
D_00542940 = 0x00542940; /* bss referenced by main/func_003A6DA0.c */
func_1E68080 = 0x01E68080; /* overlay function called from main/func_0044B7A0 (jal target outside the main ELF) */
