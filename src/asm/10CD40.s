.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"


/* Handwritten function */

glabel RFU000_FullReset
    addiu      $v1, $zero, 0x0
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU000_FullReset

/* Handwritten function */

glabel ResetEE
    addiu      $v1, $zero, 0x1
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ResetEE

/* Handwritten function */

glabel SetGsCrt
    addiu      $v1, $zero, 0x2
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetGsCrt

/* Handwritten function */

glabel RFU003
    addiu      $v1, $zero, 0x3
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU003

/* Handwritten function */

glabel Exit
    addiu      $v1, $zero, 0x4
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel Exit

/* Handwritten function */

glabel RFU005
    addiu      $v1, $zero, 0x5
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU005

/* Handwritten function */

glabel _LoadExecPS2
    addiu      $v1, $zero, 0x6
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _LoadExecPS2

/* Handwritten function */

glabel _ExecPS2
    addiu      $v1, $zero, 0x7
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _ExecPS2

/* Handwritten function */

glabel RFU008
    addiu      $v1, $zero, 0x8
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU008

/* Handwritten function */

glabel RFU009
    addiu      $v1, $zero, 0x9
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU009

/* Handwritten function */

glabel AddSbusIntcHandler
    addiu      $v1, $zero, 0xA
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel AddSbusIntcHandler

/* Handwritten function */

glabel RemoveSbusIntcHandler
    addiu      $v1, $zero, 0xB
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RemoveSbusIntcHandler

/* Handwritten function */

glabel Interrupt2Iop
    addiu      $v1, $zero, 0xC
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel Interrupt2Iop

/* Handwritten function */

glabel SetVTLBRefillHandler
    addiu      $v1, $zero, 0xD
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetVTLBRefillHandler

/* Handwritten function */

glabel SetVCommonHandler
    addiu      $v1, $zero, 0xE
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetVCommonHandler

/* Handwritten function */

glabel SetVInterruptHandler
    addiu      $v1, $zero, 0xF
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetVInterruptHandler

/* Handwritten function */

glabel AddIntcHandler
    addiu      $v1, $zero, 0x10
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel AddIntcHandler

/* Handwritten function */

glabel AddIntcHandler2
    addiu      $v1, $zero, 0x10
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel AddIntcHandler2

/* Handwritten function */

glabel RemoveIntcHandler
    addiu      $v1, $zero, 0x11
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RemoveIntcHandler

/* Handwritten function */

glabel AddDmacHandler
    addiu      $v1, $zero, 0x12
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel AddDmacHandler

/* Handwritten function */

glabel AddDmacHandler2
    addiu      $v1, $zero, 0x12
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel AddDmacHandler2

/* Handwritten function */

glabel RemoveDmacHandler
    addiu      $v1, $zero, 0x13
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RemoveDmacHandler

/* Handwritten function */

glabel _EnableIntc
    addiu      $v1, $zero, 0x14
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _EnableIntc

/* Handwritten function */

glabel _DisableIntc
    addiu      $v1, $zero, 0x15
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _DisableIntc

/* Handwritten function */

glabel _EnableDmac
    addiu      $v1, $zero, 0x16
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _EnableDmac

/* Handwritten function */

glabel _DisableDmac
    addiu      $v1, $zero, 0x17
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _DisableDmac

/* Handwritten function */

glabel SetAlarm
    addiu      $v1, $zero, 0xFC
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetAlarm

/* Handwritten function */

glabel ReleaseAlarm
    addiu      $v1, $zero, 0xFD
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ReleaseAlarm

/* Handwritten function */

glabel _iEnableIntc
    addiu      $v1, $zero, -0x1A
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _iEnableIntc

/* Handwritten function */

glabel _iDisableIntc
    addiu      $v1, $zero, -0x1B
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _iDisableIntc

/* Handwritten function */

glabel _iEnableDmac
    addiu      $v1, $zero, -0x1C
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _iEnableDmac

/* Handwritten function */

glabel _iDisableDmac
    addiu      $v1, $zero, -0x1D
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _iDisableDmac

/* Handwritten function */

glabel iSetAlarm
    addiu      $v1, $zero, -0xFE
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iSetAlarm

/* Handwritten function */

glabel iReleaseAlarm
    addiu      $v1, $zero, -0xFF
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iReleaseAlarm

/* Handwritten function */

glabel CreateThread
    addiu      $v1, $zero, 0x20
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel CreateThread

/* Handwritten function */

glabel DeleteThread
    addiu      $v1, $zero, 0x21
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel DeleteThread

/* Handwritten function */

glabel StartThread
    addiu      $v1, $zero, 0x22
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel StartThread

/* Handwritten function */

glabel ExitThread
    addiu      $v1, $zero, 0x23
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ExitThread

/* Handwritten function */

glabel ExitDeleteThread
    addiu      $v1, $zero, 0x24
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ExitDeleteThread

/* Handwritten function */

glabel TerminateThread
    addiu      $v1, $zero, 0x25
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel TerminateThread

/* Handwritten function */

glabel iTerminateThread
    addiu      $v1, $zero, -0x26
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iTerminateThread

/* Handwritten function */

glabel DisableDispatchThread
    addiu      $v1, $zero, 0x27
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel DisableDispatchThread

/* Handwritten function */

glabel EnableDispatchThread
    addiu      $v1, $zero, 0x28
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel EnableDispatchThread

/* Handwritten function */

glabel ChangeThreadPriority
    addiu      $v1, $zero, 0x29
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ChangeThreadPriority

/* Handwritten function */

glabel iChangeThreadPriority
    addiu      $v1, $zero, -0x2A
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iChangeThreadPriority

/* Handwritten function */

glabel RotateThreadReadyQueue
    addiu      $v1, $zero, 0x2B
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RotateThreadReadyQueue

/* Handwritten function */

glabel _iRotateThreadReadyQueue
    addiu      $v1, $zero, -0x2C
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _iRotateThreadReadyQueue

/* Handwritten function */

glabel ReleaseWaitThread
    addiu      $v1, $zero, 0x2D
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ReleaseWaitThread

/* Handwritten function */

glabel iReleaseWaitThread
    addiu      $v1, $zero, -0x2E
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iReleaseWaitThread

/* Handwritten function */

glabel GetThreadId
    addiu      $v1, $zero, 0x2F
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GetThreadId

/* Handwritten function */

glabel ReferThreadStatus
    addiu      $v1, $zero, 0x30
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ReferThreadStatus

/* Handwritten function */

glabel iReferThreadStatus
    addiu      $v1, $zero, -0x31
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iReferThreadStatus

/* Handwritten function */

glabel SleepThread
    addiu      $v1, $zero, 0x32
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SleepThread

/* Handwritten function */

glabel WakeupThread
    addiu      $v1, $zero, 0x33
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel WakeupThread

/* Handwritten function */

glabel _iWakeupThread
    addiu      $v1, $zero, -0x34
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _iWakeupThread

/* Handwritten function */

glabel CancelWakeupThread
    addiu      $v1, $zero, 0x35
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel CancelWakeupThread

/* Handwritten function */

glabel iCancelWakeupThread
    addiu      $v1, $zero, -0x36
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iCancelWakeupThread

/* Handwritten function */

glabel SuspendThread_2
    addiu      $v1, $zero, 0x37
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SuspendThread_2

/* Handwritten function */

glabel _iSuspendThread
    addiu      $v1, $zero, -0x38
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _iSuspendThread

/* Handwritten function */

glabel ResumeThread
    addiu      $v1, $zero, 0x39
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ResumeThread

/* Handwritten function */

glabel iResumeThread
    addiu      $v1, $zero, -0x3A
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iResumeThread

/* Handwritten function */

glabel JoinThread
    addiu      $v1, $zero, 0x3B
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel JoinThread

/* Handwritten function */

glabel RFU060
    addiu      $v1, $zero, 0x3C
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU060

/* Handwritten function */

glabel RFU061
    addiu      $v1, $zero, 0x3D
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU061

/* Handwritten function */

glabel EndOfHeap
    addiu      $v1, $zero, 0x3E
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel EndOfHeap

/* Handwritten function */

glabel RFU063
    addiu      $v1, $zero, 0x3F
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU063

/* Handwritten function */

glabel CreateSema
    addiu      $v1, $zero, 0x40
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel CreateSema

/* Handwritten function */

glabel DeleteSema
    addiu      $v1, $zero, 0x41
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel DeleteSema

/* Handwritten function */

glabel SignalSema
    addiu      $v1, $zero, 0x42
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SignalSema

/* Handwritten function */

glabel iSignalSema
    addiu      $v1, $zero, -0x43
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iSignalSema

/* Handwritten function */

glabel WaitSema
    addiu      $v1, $zero, 0x44
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel WaitSema

/* Handwritten function */

glabel PollSema
    addiu      $v1, $zero, 0x45
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel PollSema

/* Handwritten function */

glabel iPollSema
    addiu      $v1, $zero, -0x46
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iPollSema

/* Handwritten function */

glabel ReferSemaStatus
    addiu      $v1, $zero, 0x47
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel ReferSemaStatus

/* Handwritten function */

glabel iReferSemaStatus
    addiu      $v1, $zero, -0x48
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iReferSemaStatus

/* Handwritten function */

glabel RFU073
    addiu      $v1, $zero, 0x49
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU073

/* Handwritten function */

glabel SetOsdConfigParam
    addiu      $v1, $zero, 0x4A
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetOsdConfigParam

/* Handwritten function */

glabel GetOsdConfigParam
    addiu      $v1, $zero, 0x4B
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GetOsdConfigParam

/* Handwritten function */

glabel GetGsHParam
    addiu      $v1, $zero, 0x4C
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GetGsHParam

/* Handwritten function */

glabel GetGsVParam
    addiu      $v1, $zero, 0x4D
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GetGsVParam

/* Handwritten function */

glabel SetGsHParam
    addiu      $v1, $zero, 0x4E
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetGsHParam

/* Handwritten function */

glabel SetGsVParam
    addiu      $v1, $zero, 0x4F
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetGsVParam

/* Handwritten function */

glabel RFU080_CreateEventFlag
    addiu      $v1, $zero, 0x50
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU080_CreateEventFlag

/* Handwritten function */

glabel RFU081_DeleteEventFlag
    addiu      $v1, $zero, 0x51
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU081_DeleteEventFlag

/* Handwritten function */

glabel RFU082_SetEventFlag
    addiu      $v1, $zero, 0x52
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU082_SetEventFlag

/* Handwritten function */

glabel RFU083_iSetEventFlag
    addiu      $v1, $zero, -0x53
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU083_iSetEventFlag

/* Handwritten function */

glabel RFU084_ClearEventFlag
    addiu      $v1, $zero, 0x54
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU084_ClearEventFlag

/* Handwritten function */

glabel RFU085_iClearEventFlag
    addiu      $v1, $zero, -0x55
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU085_iClearEventFlag

/* Handwritten function */

glabel RFU086_WaitEvnetFlag
    addiu      $v1, $zero, 0x56
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU086_WaitEvnetFlag

/* Handwritten function */

glabel RFU087_PollEvnetFlag
    addiu      $v1, $zero, 0x57
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU087_PollEvnetFlag

/* Handwritten function */

glabel RFU088_iPollEvnetFlag
    addiu      $v1, $zero, -0x58
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU088_iPollEvnetFlag

/* Handwritten function */

glabel RFU089_ReferEventFlagStatus
    addiu      $v1, $zero, 0x59
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU089_ReferEventFlagStatus

/* Handwritten function */

glabel RFU090_iReferEventFlagStatus
    addiu      $v1, $zero, -0x5A
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU090_iReferEventFlagStatus

/* Handwritten function */

glabel RFU091
    addiu      $v1, $zero, 0x5B
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU091

/* Handwritten function */

glabel EnableIntcHandler
    addiu      $v1, $zero, 0x5C
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel EnableIntcHandler

/* Handwritten function */

glabel iEnableIntcHandler
    addiu      $v1, $zero, -0x5C
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iEnableIntcHandler

/* Handwritten function */

glabel DisableIntcHandler
    addiu      $v1, $zero, 0x5D
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel DisableIntcHandler

/* Handwritten function */

glabel iDisableIntcHandler
    addiu      $v1, $zero, -0x5D
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iDisableIntcHandler

/* Handwritten function */

glabel EnableDmacHandler
    addiu      $v1, $zero, 0x5E
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel EnableDmacHandler

/* Handwritten function */

glabel iEnableDmacHandler
    addiu      $v1, $zero, -0x5E
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iEnableDmacHandler

/* Handwritten function */

glabel DisableDmacHandler
    addiu      $v1, $zero, 0x5F
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel DisableDmacHandler

/* Handwritten function */

glabel iDisableDmacHandler
    addiu      $v1, $zero, -0x5F
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iDisableDmacHandler

/* Handwritten function */

glabel KSeg0
    addiu      $v1, $zero, 0x60
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel KSeg0

/* Handwritten function */

glabel EnableCache
    addiu      $v1, $zero, 0x61
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel EnableCache

/* Handwritten function */

glabel DisableCache
    addiu      $v1, $zero, 0x62
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel DisableCache

/* Handwritten function */

glabel GetCop0
    addiu      $v1, $zero, 0x63
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GetCop0

/* Handwritten function */

glabel FlushCache
    addiu      $v1, $zero, 0x64
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel FlushCache

/* Handwritten function */

glabel CpuConfig
    addiu      $v1, $zero, 0x66
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel CpuConfig

/* Handwritten function */

glabel iGetCop0
    addiu      $v1, $zero, -0x67
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iGetCop0

/* Handwritten function */

glabel iFlushCache
    addiu      $v1, $zero, -0x68
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iFlushCache

/* Handwritten function */

glabel iCpuConfig
    addiu      $v1, $zero, -0x6A
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iCpuConfig

/* Handwritten function */

glabel sceSifStopDma
    addiu      $v1, $zero, 0x6B
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel sceSifStopDma

/* Handwritten function */

glabel SetCPUTimerHandler
    addiu      $v1, $zero, 0x6C
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetCPUTimerHandler

/* Handwritten function */

glabel SetCPUTimer
    addiu      $v1, $zero, 0x6D
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetCPUTimer

/* Handwritten function */

glabel SetOsdConfigParam2
    addiu      $v1, $zero, 0x6E
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetOsdConfigParam2

/* Handwritten function */

glabel GetOsdConfigParam2
    addiu      $v1, $zero, 0x6F
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GetOsdConfigParam2

/* Handwritten function */

glabel GsGetIMR
    addiu      $v1, $zero, 0x70
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GsGetIMR

/* Handwritten function */

glabel iGsGetIMR
    addiu      $v1, $zero, -0x70
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iGsGetIMR

/* Handwritten function */

glabel GsPutIMR
    addiu      $v1, $zero, 0x71
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GsPutIMR

/* Handwritten function */

glabel iGsPutIMR
    addiu      $v1, $zero, -0x71
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel iGsPutIMR

/* Handwritten function */

glabel SetPgifHandler
    addiu      $v1, $zero, 0x72
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetPgifHandler

/* Handwritten function */

glabel SetVSyncFlag
    addiu      $v1, $zero, 0x73
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel SetVSyncFlag

/* Handwritten function */

glabel RFU116
    addiu      $v1, $zero, 0x74
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel RFU116

/* Handwritten function */

glabel _print
    addiu      $v1, $zero, 0x75
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _print

/* Handwritten function */

glabel sceSifDmaStat
    addiu      $v1, $zero, 0x76
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel sceSifDmaStat

/* Handwritten function */

glabel isceSifDmaStat
    addiu      $v1, $zero, -0x76
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel isceSifDmaStat

/* Handwritten function */

glabel sceSifSetDma
    addiu      $v1, $zero, 0x77
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel sceSifSetDma

/* Handwritten function */

glabel isceSifSetDma
    addiu      $v1, $zero, -0x77
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel isceSifSetDma

/* Handwritten function */

glabel sceSifSetDChain
    addiu      $v1, $zero, 0x78
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel sceSifSetDChain

/* Handwritten function */

glabel isceSifSetDChain
    addiu      $v1, $zero, -0x78
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel isceSifSetDChain

/* Handwritten function */

glabel sceSifSetReg
    addiu      $v1, $zero, 0x79
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel sceSifSetReg

/* Handwritten function */

glabel sceSifGetReg
    addiu      $v1, $zero, 0x7A
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel sceSifGetReg

/* Handwritten function */

glabel _ExecOSD
    addiu      $v1, $zero, 0x7B
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _ExecOSD

/* Handwritten function */

glabel Deci2Call
    addiu      $v1, $zero, 0x7C
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel Deci2Call

/* Handwritten function */

glabel PSMode
    addiu      $v1, $zero, 0x7D
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel PSMode

/* Handwritten function */

glabel MachineType
    addiu      $v1, $zero, 0x7E
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel MachineType

/* Handwritten function */

glabel GetMemorySize
    addiu      $v1, $zero, 0x7F
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel GetMemorySize

/* Handwritten function */

glabel _InitTLB
    addiu      $v1, $zero, 0x82
    syscall    0 /* handwritten instruction */
    jr         $ra
    nop
endlabel _InitTLB
