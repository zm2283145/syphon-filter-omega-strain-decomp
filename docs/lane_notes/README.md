# Lane notes (snapshot 2026-10-31, after R215)

Each `kN/NOTES.md` is the working log of matching lane kN: for every function it
tried, the best draft, its differing-word count (`check_match`), the remaining diff,
what was tried and the next idea. `kN/drafts/` holds the best near-miss drafts named
below. The notes refer to drafts by their original path, `build/agents/kN/work/<file>`
(or `rs/<file>` for k5); here they are flattened into `drafts/` (subfolders joined with `_`,
e.g. `work/tl/best_tl.c` → `drafts/tl_best_tl.c`).

Check a draft with `tools/check_match.py <draft> -c mw38` (k1's `mc_vO.c` uses `-c gcc296g0`).

## Best near misses

| Address | Function | Lane | Draft | Words | Remaining diff |
|---|---|---|---|---|---|
| 2B9108 | _sceMcFatCreateFile | k1 | `mc_vO.c` | 1 | `beql s6,zero` vs retail `beqz s6` at 0x130 (a1 treated as live) |
| 2DEF70 | RemoteClientDisconnectEvent | k2 | `def_k1.c`, `def_k2.c` | 4 | see k2 NOTES |
| 2E2250 | NetIRequestCreateRemoteNamedObject | k2 | (NOTES) | 4 | see k2 NOTES |
| 3870C0 | cMan_ManRender | k3 | `mr_ze.c` | 5 (2 real) | `sll a1` / first `lq s0` swapped at 0x2644 |
| 13FF40 | cWeapon_FireIfReady | k8 | `fw50.c` | 7 | s0/s1 swap of `p` and `v` |
| 385240 | cMan_GetGunBarrelMatrix | k3 | `t_g5.c` | 7 | see k3 NOTES |
| 37B5C0 | XLib_DisplayLastFrame | k3 | `b_37B5C0.c` | 7 | see k3 NOTES |
| 1B0F20 | cHuman_GetTransform_ForCameraTracking (body at 1B0F30) | k8 | `gt_best8.c` | 8 | needs a config split at 1B0F30 |
| 1D1140 | cHumanIkRoutine_PositionLeg | k4 | `k1.c` | 8 | see k4 NOTES |
| 2DF290 | NetIInitialize | k2 | (NOTES, `dfr.py` variants) | 8 | see k2 NOTES |
| 21E0C0 | cGenerator_NetSpawn | k2 | `gen35.cpp` | 9 | see k2 NOTES |
| 1D0780 | cHumanIkRoutine_AimHeadIndependently | k4 | `h18.c` | 9 | see k4 NOTES |
| 36B3B0 | cMemMan_Init_int_uint_uint | k3 | `b_36B3B0.c` | 9 | register/scheduling in `&D_00533CB0[pool]` |
| 1DD1C0 | cAimComponent_NextFrame | k7 | `ac0.c` | 11 | see k7 NOTES |
| 230DE0 | Global_Shatter | k6 | `g_230DE0.c` (`alt_s2_230DE0.c` 15) | 12 | register allocation in 3 spots |
| 4073C0 | SKL_CompressSKL | k7 | `skl_best16.c` | 16 | see k7 NOTES |
| 180580 | cSplinedMotion_QuaternionLERP_1_UpdateVelocity | k6 | `sq_a.c` | 17 | see k6 NOTES |
| 1A1590 | cHuman_Fall | k8 | `fa0.c` | 19 | see k8 NOTES |
| 405660 | Monster_ctor | k6 | `base_405660.c` | 21 | see k6 NOTES |
| 2625B0 | cFireObj_ctor_cPopulationR | k7 | `fo9.c` | 21 | see k7 NOTES |
| 18A950 | cHuman_HandleDeath | k8 | `pG.c` | 22 | see k8 NOTES |
| 290610 | cSkeleton_ResetBBoxContributors | k7 | `rb_best22.c` | 22 | see k7 NOTES |
| 36B630 | cMemMan_Init_void | k3 | `mv0.c` | 24 | see k3 NOTES |
| 25F930 | cVisionFxMan_DeactivateFx | k7 | `k_vf0.c` | 25 | see k7 NOTES |
| 22A8C0 | GetCollisionDist | k7 | `gcd_best28.c` | 28 | see k7 NOTES |
| 336700 | cAgentData_ctor | k7 | `ad_best28.c` | 28 | see k7 NOTES |
| 22BA30 | CheckBulletCollisions | k7 | `bc2.c` | 29 | see k7 NOTES |

## Big functions rebuilt from prototype DWARF (in progress)

| Address | Function | Lane | Draft | Words |
|---|---|---|---|---|
| 24B5D0 | PlayerInput_Update | k8 | `PI_best.c` (lead `PI_lead_kW6_95.c`) | 94 |
| 17A640 | cGameCamera_UpdateMotion | k8 | `gc1.c` | 85 |
| 440580 | GuiWeaponDisplay_onRender | k7 | `wd_best87.c` | 87 |
| 1DBB20 | InitWeaponSlotIkTargetTable | k4 | `b4.c` | 99 |
| 39B7B0 | cParticleShatter_Render | k5 | `n6.c` (placeholder callee names) | 107 |
| 1D1740 | nIk_TwoLimbIK | k4 | `tl_best_tl.c` (+`tl_hdr.h`, `tl_t7.c`) | 109 |
| 1D02B0 | cHumanIkRoutine_CalculateResultPose | k4 | `r0.c` | 127 |
| 37E780 | XLib_Init | k3 | `fx_ini.c` | 279 |
| 1A0B30 | cHuman_Land | k8 | `ld1.c` | 292 lines |
| 1E2180 | ActorPhys_RunResponse | k8 | `ar_best.c` | 970 |

Techniques that worked this session are in each lane's NOTES.md; the most useful
are summarised in `docs/HANDOFF.md` under "Near-miss techniques (newest)".
