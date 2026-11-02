# T1 notes (2026-11-02)

## 003C6FC0 ColQuery_InitSweep (2228 B) - MATCH, staged (pending/t1/mw38_003C6FC0.c from is_clean.c)
- Built from the matched Reset_2 source (src/Libs/SFOLib/Source/vu0man/func_003C66B0.c). is1 (first draft): 168 lab lines nosp, frame 1152 vs 1552.
- Frame: a dead `if (0) { Iterator curr, end; 3x self->mTransform = mTransform * mInvTransform; }` after ArrCopy gives every
  retail hole (16 B small slots at the frame top, 3 main-level matrix ret temps, 3 depth-1 `r` matrices). The two fov
  matrices are what Reset_2's dead `M d0, d1` placeholder stood for.
- fov block: `float tn = Libc_Tanf(0.5f*fov); float t = tn * scale.y; float inv = 1.0f / t;` (tan first in mul.s, one div),
  fovMat declared before invFovMat; both products via one 3-operand VU0 `Mul(d, a, b)` (d = a*b; asm operands d, a, b):
  `Mul(&mT, &fovMat, &mT)`, `Mul(&mInv, &mInv, &invFovMat)`. Retail's trailing nop came out by itself.
- `mInvTransform = MulCopy(invRotTrans, invScaleMat)` (S3's CopyOfM pass) fixed the a1/a2/a3 rotation in the two
  ret-copy blocks (69 -> 23).
- func_003BF760 call: `V& hv = (V(0, height, 0, 0) *= invScaleMat); func_003BF760(list, self->mInvTransform, GetY(hv));`
  with GetY a 3-level pass-through to `GetY0(v) { const float* p = &v.y; return *p; }`. Plain `.y`, `const float&`, named
  pointer: address folded or computed after the arg copy (23); 1-level GetY: address early but wrong colour (14); 3 levels: 0.

## 003E57B0 func_003E57B0 = cCharActionMsg_DestinationParams::Pack (1460 B) - NOT matched
- Best C-only draft: dp_best105_c.c (lab 105 lines). Best overall: dp_best90.c (lab 90), but it reads the old-path vector
  components through GCC volatile `lwc1` asm accessors, which the acceptance rules do not allow (plain loads). Research only.
- Skeleton from the prototype (Pack__Q27nMSGLIB32cCharActionMsg_DestinationParams 0x3D3620, lines 701-767 via P6L pl.sh) is
  right: static prevDestMsg (D_0055A228) lazily `new ("character.cc", 0x2C5) Msg(tmpVector)` (operator new holds AllocGuard),
  pos != prev pos test, size/buffer test, cCharActionMsg_Pack, then (retail only) `if (!ref || !ref->mObj || !ref->mValid)
  { old copy path } else { transform path }`, common RotZ, nOutMsgID, delete prev (AllocGuard + Destroy + Deallocate 0x363),
  prev = Clone().
- Matched pieces (in both drafts): prologue, static-msg block (CharMsg base ctor + `Dest(pos)` member ctor written through a
  `Dest* p = this` pointer; min.s via asm), the comparison (named `const V&` b then a; only c.eq.s operand colour left),
  transform path: `M inv = Inverse(obj->mTransform)` (Reset's Inv2 with local t), `pos *= inv` (V* p before M* q), and a
  `TransformPlane(plane, inv)` inline with named n/pt (puts t, n, pt at 0xC0/0xB0/0xA0 as retail).
- KEY FINDING (micro tests t11-t19.c): the dead `move rX,zero` before float constants, the repeated dsll32/dsra32 / andi
  0xffff pairs and the unfolded per-access `addiu` in retail are a BASIC-BLOCK-LOCAL effect of a preceding volatile asm
  WITH AN OUTPUT operand in the same block (`__asm__ volatile("..." : "=r"/"=f"(x) ...)`). An asm after the code, in another
  block, in an `if (0)`, non-volatile, input-only or empty does not do it, and neither does any opt pragma. With that
  effect: `unsigned short s = 0; s = (int)(32768.0f * v); out = s;` gives retail's move + 2 andi, and
  `int r = 0; r = (short)(f * 8192.0f); return r;` (inline) gives move + 2 dsll pairs.
- Retail shows the effect in the old-path block, the common RotZ block and the packing block, but no asm instruction is
  visible there, so the trigger is unknown. Volatile `lwc1` accessors reproduce the whole old path (dp_best90.c) but are
  not acceptable C.
- Other open items: vcalls must go through t9 (use a polymorphic class cast instead of function pointers); ObjRef id read
  `addiu a0,a0,12; lw a0,0(a0)` (accessor returning a reference); packed shorts (move + 4 pairs each); `nop` after the
  UpdateTransform vcall.

## 0020D680 CameraCol_Sweep (2136 B) - not started (recon only)
- Same less-optimised traits (b;nop, BB-end nops, recomputed addresses). Has a function-static zero vector (D_004E1D88 guard,
  D_004E1D90) and a 1-element stack array of 0x40-byte entries (count at sp+0x7A0), then two loops, each building a
  SphereSweptRay probe (ctor), calling ColQuery_InitTransformedThunk or Reset_..._etc depending on a byte flag,
  ColQuery_ExecuteThunk, and storing the hit at self+0x60. No prototype counterpart. Probably more than 2 hours.
