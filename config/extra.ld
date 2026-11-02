/* Extra linker definitions passed before the splat-generated script. */
ENTRY(_start);
__dl__FPv = 0x00100740; /* mangled operator delete(void*) used by C++ units; same address as operator_delete */
D_0048943C = 0x0048943C; /* data inside a C-owned block, referenced by lib/libc/libc_124D30.c */
D_00542940 = 0x00542940; /* bss referenced by Libs/989snd/ee/989snd_4.c */
func_1E68080 = 0x01E68080; /* overlay function called from Libs/SFOLobby/SFOLobby/SFOLobby_Config (jal target outside the main ELF) */
__unexpected = 0x00101250; /* MW exception-specification handler emitted by the compiler */
__end__catch = 0x00100D20; /* MW catch cleanup emitted by the compiler */
fptodp = 0x0011BD70; /* MW float->double runtime helper emitted by the compiler; same address as SoftFloat_FloatToDouble */
dpadd = 0x0011C1A8; /* MW double add runtime helper emitted by the compiler; same address as SoftFloat_DoubleAdd */
dptofp = 0x0011C928; /* MW double->float runtime helper emitted by the compiler; same address as SoftFloat_DoubleToFloat */
/* StaticInit_scriptUtils (main/sinit/func_004D09A0.c) calls two anonymous-namespace helpers of scriptUtils.cc. MW only
   keeps caller-saved registers live across a call to a static function defined earlier in the same file, so that unit
   carries static copies of both helpers in their own sections. They are placed NOLOAD at the real helpers' addresses
   (the real code lives in scriptUtils_20.c / scriptUtils_25.c): the jal relocations resolve there and nothing is emitted. */
SECTIONS {
  .ipa_002690E0 0x002690E0 (NOLOAD) : { *(.ipa_002690E0) }
  .ipa_00269830 0x00269830 (NOLOAD) : { *(.ipa_00269830) }
}
