/* Extra linker definitions passed before the splat-generated script. */
ENTRY(_start);
__dl__FPv = 0x00100740; /* mangled operator delete(void*) used by C++ units; same address as operator_delete */
D_0048943C = 0x0048943C; /* data inside a C-owned block, referenced by lib/libc/libc_124D30.c */
D_00542940 = 0x00542940; /* bss referenced by Libs/989snd/ee/989snd_4.c */
func_1E68080 = 0x01E68080; /* overlay function called from Libs/SFOLobby/SFOLobby/SFOLobby_Config (jal target outside the main ELF) */
__unexpected = 0x00101250; /* MW exception-specification handler emitted by the compiler */
__end__catch = 0x00100D20; /* MW catch cleanup emitted by the compiler */
