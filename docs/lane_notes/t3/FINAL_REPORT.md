# T3 final report (2026-11-02)

Staged: none.

## XLib_Init 0x37E780 (3816 B): 109 -> 52 lab lines, not matched
Best draft: build/agents/T3/xi_best52.c (check_match: DIFF, size now exact; frame 0x150 like retail).
- Fixed: SetBGColor block (helper `F2B` with a `float t = f` copy + int locals `ib, ig, ir` assigned r, g, b), SetBuffers
  block (fbp passed as an expression, parameter order (fbw, psm, fbmsk, zpsm, zbp, zmsk, fbh, fbp, half)), fog multiply
  operand order (`fr = r; fr *= 256.0f`), frame size (dead-block frame hole `int h[8]` declared before dimx, q4 idiom,
  owner review pending, commented in the file).
- Left: one ~70-instruction window (pixenv tail + alphaReg + fog + dimx loop setup) where retail's schedule/colouring
  differs (b zero hoisted before g zero, 128/256a/alpha early, dimx in v1/v0). About 6 of the 52 lab lines are lab masking
  artefacts on absolute hardware addresses. Several hundred source variants in that window all give 52 or worse
  (list in NOTES.md).

## WeatherEmitter_Update 0x39A000 (4356 B): surveyed, not started
- It is cParticleBox::NextFrame (particle.cc, between the matched Render and RequestBlock); no better prototype counterpart
  exists. Both prototypes' versions are ~3000 B; retail adds an effect-ID loop over child definitions, atan2/tan FOV
  clamping, extra owner virtual calls, and a grown cParticleBox layout. It needs a from-scratch rebuild in the
  less-optimised mode; outline in NOTES.md.
