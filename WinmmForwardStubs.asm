OPTION CASEMAP:NONE

EXTERN g_Ordinal_2:QWORD
EXTERN g_mciExecute:QWORD
EXTERN g_CloseDriver:QWORD
EXTERN g_DefDriverProc:QWORD
EXTERN g_DriverCallback:QWORD
EXTERN g_DrvGetModuleHandle:QWORD
EXTERN g_GetDriverModuleHandle:QWORD
EXTERN g_OpenDriver:QWORD
EXTERN g_PlaySound:QWORD
EXTERN g_PlaySoundA:QWORD
EXTERN g_PlaySoundW:QWORD
EXTERN g_SendDriverMessage:QWORD
EXTERN g_WOWAppExit:QWORD
EXTERN g_auxGetDevCapsA:QWORD
EXTERN g_auxGetDevCapsW:QWORD
EXTERN g_auxGetNumDevs:QWORD
EXTERN g_auxGetVolume:QWORD
EXTERN g_auxOutMessage:QWORD
EXTERN g_auxSetVolume:QWORD
EXTERN g_joyConfigChanged:QWORD
EXTERN g_joyGetDevCapsA:QWORD
EXTERN g_joyGetDevCapsW:QWORD
EXTERN g_joyGetNumDevs:QWORD
EXTERN g_joyGetPos:QWORD
EXTERN g_joyGetPosEx:QWORD
EXTERN g_joyGetThreshold:QWORD
EXTERN g_joyReleaseCapture:QWORD
EXTERN g_joySetCapture:QWORD
EXTERN g_joySetThreshold:QWORD
EXTERN g_mciDriverNotify:QWORD
EXTERN g_mciDriverYield:QWORD
EXTERN g_mciFreeCommandResource:QWORD
EXTERN g_mciGetCreatorTask:QWORD
EXTERN g_mciGetDeviceIDA:QWORD
EXTERN g_mciGetDeviceIDFromElementIDA:QWORD
EXTERN g_mciGetDeviceIDFromElementIDW:QWORD
EXTERN g_mciGetDeviceIDW:QWORD
EXTERN g_mciGetDriverData:QWORD
EXTERN g_mciGetErrorStringA:QWORD
EXTERN g_mciGetErrorStringW:QWORD
EXTERN g_mciGetYieldProc:QWORD
EXTERN g_mciLoadCommandResource:QWORD
EXTERN g_mciSendCommandA:QWORD
EXTERN g_mciSendCommandW:QWORD
EXTERN g_mciSendStringA:QWORD
EXTERN g_mciSendStringW:QWORD
EXTERN g_mciSetDriverData:QWORD
EXTERN g_mciSetYieldProc:QWORD
EXTERN g_midiConnect:QWORD
EXTERN g_midiDisconnect:QWORD
EXTERN g_midiInAddBuffer:QWORD
EXTERN g_midiInClose:QWORD
EXTERN g_midiInGetDevCapsA:QWORD
EXTERN g_midiInGetDevCapsW:QWORD
EXTERN g_midiInGetErrorTextA:QWORD
EXTERN g_midiInGetErrorTextW:QWORD
EXTERN g_midiInGetID:QWORD
EXTERN g_midiInGetNumDevs:QWORD
EXTERN g_midiInMessage:QWORD
EXTERN g_midiInOpen:QWORD
EXTERN g_midiInPrepareHeader:QWORD
EXTERN g_midiInReset:QWORD
EXTERN g_midiInStart:QWORD
EXTERN g_midiInStop:QWORD
EXTERN g_midiInUnprepareHeader:QWORD
EXTERN g_midiOutCacheDrumPatches:QWORD
EXTERN g_midiOutCachePatches:QWORD
EXTERN g_midiOutClose:QWORD
EXTERN g_midiOutGetDevCapsA:QWORD
EXTERN g_midiOutGetDevCapsW:QWORD
EXTERN g_midiOutGetErrorTextA:QWORD
EXTERN g_midiOutGetErrorTextW:QWORD
EXTERN g_midiOutGetID:QWORD
EXTERN g_midiOutGetNumDevs:QWORD
EXTERN g_midiOutGetVolume:QWORD
EXTERN g_midiOutLongMsg:QWORD
EXTERN g_midiOutMessage:QWORD
EXTERN g_midiOutOpen:QWORD
EXTERN g_midiOutPrepareHeader:QWORD
EXTERN g_midiOutReset:QWORD
EXTERN g_midiOutSetVolume:QWORD
EXTERN g_midiOutShortMsg:QWORD
EXTERN g_midiOutUnprepareHeader:QWORD
EXTERN g_midiStreamClose:QWORD
EXTERN g_midiStreamOpen:QWORD
EXTERN g_midiStreamOut:QWORD
EXTERN g_midiStreamPause:QWORD
EXTERN g_midiStreamPosition:QWORD
EXTERN g_midiStreamProperty:QWORD
EXTERN g_midiStreamRestart:QWORD
EXTERN g_midiStreamStop:QWORD
EXTERN g_mixerClose:QWORD
EXTERN g_mixerGetControlDetailsA:QWORD
EXTERN g_mixerGetControlDetailsW:QWORD
EXTERN g_mixerGetDevCapsA:QWORD
EXTERN g_mixerGetDevCapsW:QWORD
EXTERN g_mixerGetID:QWORD
EXTERN g_mixerGetLineControlsA:QWORD
EXTERN g_mixerGetLineControlsW:QWORD
EXTERN g_mixerGetLineInfoA:QWORD
EXTERN g_mixerGetLineInfoW:QWORD
EXTERN g_mixerGetNumDevs:QWORD
EXTERN g_mixerMessage:QWORD
EXTERN g_mixerOpen:QWORD
EXTERN g_mixerSetControlDetails:QWORD
EXTERN g_mmDrvInstall:QWORD
EXTERN g_mmGetCurrentTask:QWORD
EXTERN g_mmTaskBlock:QWORD
EXTERN g_mmTaskCreate:QWORD
EXTERN g_mmTaskSignal:QWORD
EXTERN g_mmTaskYield:QWORD
EXTERN g_mmioAdvance:QWORD
EXTERN g_mmioAscend:QWORD
EXTERN g_mmioClose:QWORD
EXTERN g_mmioCreateChunk:QWORD
EXTERN g_mmioDescend:QWORD
EXTERN g_mmioFlush:QWORD
EXTERN g_mmioGetInfo:QWORD
EXTERN g_mmioInstallIOProcA:QWORD
EXTERN g_mmioInstallIOProcW:QWORD
EXTERN g_mmioOpenA:QWORD
EXTERN g_mmioOpenW:QWORD
EXTERN g_mmioRead:QWORD
EXTERN g_mmioRenameA:QWORD
EXTERN g_mmioRenameW:QWORD
EXTERN g_mmioSeek:QWORD
EXTERN g_mmioSendMessage:QWORD
EXTERN g_mmioSetBuffer:QWORD
EXTERN g_mmioSetInfo:QWORD
EXTERN g_mmioStringToFOURCCA:QWORD
EXTERN g_mmioStringToFOURCCW:QWORD
EXTERN g_mmioWrite:QWORD
EXTERN g_mmsystemGetVersion:QWORD
EXTERN g_sndPlaySoundA:QWORD
EXTERN g_sndPlaySoundW:QWORD
EXTERN g_timeBeginPeriod:QWORD
EXTERN g_timeEndPeriod:QWORD
EXTERN g_timeGetDevCaps:QWORD
EXTERN g_timeGetSystemTime:QWORD
EXTERN g_timeGetTime:QWORD
EXTERN g_timeKillEvent:QWORD
EXTERN g_timeSetEvent:QWORD
EXTERN g_waveInAddBuffer:QWORD
EXTERN g_waveInClose:QWORD
EXTERN g_waveInGetDevCapsA:QWORD
EXTERN g_waveInGetDevCapsW:QWORD
EXTERN g_waveInGetErrorTextA:QWORD
EXTERN g_waveInGetErrorTextW:QWORD
EXTERN g_waveInGetID:QWORD
EXTERN g_waveInGetNumDevs:QWORD
EXTERN g_waveInGetPosition:QWORD
EXTERN g_waveInMessage:QWORD
EXTERN g_waveInOpen:QWORD
EXTERN g_waveInPrepareHeader:QWORD
EXTERN g_waveInReset:QWORD
EXTERN g_waveInStart:QWORD
EXTERN g_waveInStop:QWORD
EXTERN g_waveInUnprepareHeader:QWORD
EXTERN g_waveOutBreakLoop:QWORD
EXTERN g_waveOutClose:QWORD
EXTERN g_waveOutGetDevCapsA:QWORD
EXTERN g_waveOutGetDevCapsW:QWORD
EXTERN g_waveOutGetErrorTextA:QWORD
EXTERN g_waveOutGetErrorTextW:QWORD
EXTERN g_waveOutGetID:QWORD
EXTERN g_waveOutGetNumDevs:QWORD
EXTERN g_waveOutGetPitch:QWORD
EXTERN g_waveOutGetPlaybackRate:QWORD
EXTERN g_waveOutGetPosition:QWORD
EXTERN g_waveOutGetVolume:QWORD
EXTERN g_waveOutMessage:QWORD
EXTERN g_waveOutOpen:QWORD
EXTERN g_waveOutPause:QWORD
EXTERN g_waveOutPrepareHeader:QWORD
EXTERN g_waveOutReset:QWORD
EXTERN g_waveOutRestart:QWORD
EXTERN g_waveOutSetPitch:QWORD
EXTERN g_waveOutSetPlaybackRate:QWORD
EXTERN g_waveOutSetVolume:QWORD
EXTERN g_waveOutUnprepareHeader:QWORD
EXTERN g_waveOutWrite:QWORD

.CODE

Proxy_Ordinal_2 PROC
    jmp qword ptr [g_Ordinal_2]
Proxy_Ordinal_2 ENDP

Proxy_mciExecute PROC
    jmp qword ptr [g_mciExecute]
Proxy_mciExecute ENDP

Proxy_CloseDriver PROC
    jmp qword ptr [g_CloseDriver]
Proxy_CloseDriver ENDP

Proxy_DefDriverProc PROC
    jmp qword ptr [g_DefDriverProc]
Proxy_DefDriverProc ENDP

Proxy_DriverCallback PROC
    jmp qword ptr [g_DriverCallback]
Proxy_DriverCallback ENDP

Proxy_DrvGetModuleHandle PROC
    jmp qword ptr [g_DrvGetModuleHandle]
Proxy_DrvGetModuleHandle ENDP

Proxy_GetDriverModuleHandle PROC
    jmp qword ptr [g_GetDriverModuleHandle]
Proxy_GetDriverModuleHandle ENDP

Proxy_OpenDriver PROC
    jmp qword ptr [g_OpenDriver]
Proxy_OpenDriver ENDP

Proxy_PlaySound PROC
    jmp qword ptr [g_PlaySound]
Proxy_PlaySound ENDP

Proxy_PlaySoundA PROC
    jmp qword ptr [g_PlaySoundA]
Proxy_PlaySoundA ENDP

Proxy_PlaySoundW PROC
    jmp qword ptr [g_PlaySoundW]
Proxy_PlaySoundW ENDP

Proxy_SendDriverMessage PROC
    jmp qword ptr [g_SendDriverMessage]
Proxy_SendDriverMessage ENDP

Proxy_WOWAppExit PROC
    jmp qword ptr [g_WOWAppExit]
Proxy_WOWAppExit ENDP

Proxy_auxGetDevCapsA PROC
    jmp qword ptr [g_auxGetDevCapsA]
Proxy_auxGetDevCapsA ENDP

Proxy_auxGetDevCapsW PROC
    jmp qword ptr [g_auxGetDevCapsW]
Proxy_auxGetDevCapsW ENDP

Proxy_auxGetNumDevs PROC
    jmp qword ptr [g_auxGetNumDevs]
Proxy_auxGetNumDevs ENDP

Proxy_auxGetVolume PROC
    jmp qword ptr [g_auxGetVolume]
Proxy_auxGetVolume ENDP

Proxy_auxOutMessage PROC
    jmp qword ptr [g_auxOutMessage]
Proxy_auxOutMessage ENDP

Proxy_auxSetVolume PROC
    jmp qword ptr [g_auxSetVolume]
Proxy_auxSetVolume ENDP

Proxy_joyConfigChanged PROC
    jmp qword ptr [g_joyConfigChanged]
Proxy_joyConfigChanged ENDP

Proxy_joyGetDevCapsA PROC
    jmp qword ptr [g_joyGetDevCapsA]
Proxy_joyGetDevCapsA ENDP

Proxy_joyGetDevCapsW PROC
    jmp qword ptr [g_joyGetDevCapsW]
Proxy_joyGetDevCapsW ENDP

Proxy_joyGetNumDevs PROC
    jmp qword ptr [g_joyGetNumDevs]
Proxy_joyGetNumDevs ENDP

Proxy_joyGetPos PROC
    jmp qword ptr [g_joyGetPos]
Proxy_joyGetPos ENDP

Proxy_joyGetPosEx PROC
    jmp qword ptr [g_joyGetPosEx]
Proxy_joyGetPosEx ENDP

Proxy_joyGetThreshold PROC
    jmp qword ptr [g_joyGetThreshold]
Proxy_joyGetThreshold ENDP

Proxy_joyReleaseCapture PROC
    jmp qword ptr [g_joyReleaseCapture]
Proxy_joyReleaseCapture ENDP

Proxy_joySetCapture PROC
    jmp qword ptr [g_joySetCapture]
Proxy_joySetCapture ENDP

Proxy_joySetThreshold PROC
    jmp qword ptr [g_joySetThreshold]
Proxy_joySetThreshold ENDP

Proxy_mciDriverNotify PROC
    jmp qword ptr [g_mciDriverNotify]
Proxy_mciDriverNotify ENDP

Proxy_mciDriverYield PROC
    jmp qword ptr [g_mciDriverYield]
Proxy_mciDriverYield ENDP

Proxy_mciFreeCommandResource PROC
    jmp qword ptr [g_mciFreeCommandResource]
Proxy_mciFreeCommandResource ENDP

Proxy_mciGetCreatorTask PROC
    jmp qword ptr [g_mciGetCreatorTask]
Proxy_mciGetCreatorTask ENDP

Proxy_mciGetDeviceIDA PROC
    jmp qword ptr [g_mciGetDeviceIDA]
Proxy_mciGetDeviceIDA ENDP

Proxy_mciGetDeviceIDFromElementIDA PROC
    jmp qword ptr [g_mciGetDeviceIDFromElementIDA]
Proxy_mciGetDeviceIDFromElementIDA ENDP

Proxy_mciGetDeviceIDFromElementIDW PROC
    jmp qword ptr [g_mciGetDeviceIDFromElementIDW]
Proxy_mciGetDeviceIDFromElementIDW ENDP

Proxy_mciGetDeviceIDW PROC
    jmp qword ptr [g_mciGetDeviceIDW]
Proxy_mciGetDeviceIDW ENDP

Proxy_mciGetDriverData PROC
    jmp qword ptr [g_mciGetDriverData]
Proxy_mciGetDriverData ENDP

Proxy_mciGetErrorStringA PROC
    jmp qword ptr [g_mciGetErrorStringA]
Proxy_mciGetErrorStringA ENDP

Proxy_mciGetErrorStringW PROC
    jmp qword ptr [g_mciGetErrorStringW]
Proxy_mciGetErrorStringW ENDP

Proxy_mciGetYieldProc PROC
    jmp qword ptr [g_mciGetYieldProc]
Proxy_mciGetYieldProc ENDP

Proxy_mciLoadCommandResource PROC
    jmp qword ptr [g_mciLoadCommandResource]
Proxy_mciLoadCommandResource ENDP

Proxy_mciSendCommandA PROC
    jmp qword ptr [g_mciSendCommandA]
Proxy_mciSendCommandA ENDP

Proxy_mciSendCommandW PROC
    jmp qword ptr [g_mciSendCommandW]
Proxy_mciSendCommandW ENDP

Proxy_mciSendStringA PROC
    jmp qword ptr [g_mciSendStringA]
Proxy_mciSendStringA ENDP

Proxy_mciSendStringW PROC
    jmp qword ptr [g_mciSendStringW]
Proxy_mciSendStringW ENDP

Proxy_mciSetDriverData PROC
    jmp qword ptr [g_mciSetDriverData]
Proxy_mciSetDriverData ENDP

Proxy_mciSetYieldProc PROC
    jmp qword ptr [g_mciSetYieldProc]
Proxy_mciSetYieldProc ENDP

Proxy_midiConnect PROC
    jmp qword ptr [g_midiConnect]
Proxy_midiConnect ENDP

Proxy_midiDisconnect PROC
    jmp qword ptr [g_midiDisconnect]
Proxy_midiDisconnect ENDP

Proxy_midiInAddBuffer PROC
    jmp qword ptr [g_midiInAddBuffer]
Proxy_midiInAddBuffer ENDP

Proxy_midiInClose PROC
    jmp qword ptr [g_midiInClose]
Proxy_midiInClose ENDP

Proxy_midiInGetDevCapsA PROC
    jmp qword ptr [g_midiInGetDevCapsA]
Proxy_midiInGetDevCapsA ENDP

Proxy_midiInGetDevCapsW PROC
    jmp qword ptr [g_midiInGetDevCapsW]
Proxy_midiInGetDevCapsW ENDP

Proxy_midiInGetErrorTextA PROC
    jmp qword ptr [g_midiInGetErrorTextA]
Proxy_midiInGetErrorTextA ENDP

Proxy_midiInGetErrorTextW PROC
    jmp qword ptr [g_midiInGetErrorTextW]
Proxy_midiInGetErrorTextW ENDP

Proxy_midiInGetID PROC
    jmp qword ptr [g_midiInGetID]
Proxy_midiInGetID ENDP

Proxy_midiInGetNumDevs PROC
    jmp qword ptr [g_midiInGetNumDevs]
Proxy_midiInGetNumDevs ENDP

Proxy_midiInMessage PROC
    jmp qword ptr [g_midiInMessage]
Proxy_midiInMessage ENDP

Proxy_midiInOpen PROC
    jmp qword ptr [g_midiInOpen]
Proxy_midiInOpen ENDP

Proxy_midiInPrepareHeader PROC
    jmp qword ptr [g_midiInPrepareHeader]
Proxy_midiInPrepareHeader ENDP

Proxy_midiInReset PROC
    jmp qword ptr [g_midiInReset]
Proxy_midiInReset ENDP

Proxy_midiInStart PROC
    jmp qword ptr [g_midiInStart]
Proxy_midiInStart ENDP

Proxy_midiInStop PROC
    jmp qword ptr [g_midiInStop]
Proxy_midiInStop ENDP

Proxy_midiInUnprepareHeader PROC
    jmp qword ptr [g_midiInUnprepareHeader]
Proxy_midiInUnprepareHeader ENDP

Proxy_midiOutCacheDrumPatches PROC
    jmp qword ptr [g_midiOutCacheDrumPatches]
Proxy_midiOutCacheDrumPatches ENDP

Proxy_midiOutCachePatches PROC
    jmp qword ptr [g_midiOutCachePatches]
Proxy_midiOutCachePatches ENDP

Proxy_midiOutClose PROC
    jmp qword ptr [g_midiOutClose]
Proxy_midiOutClose ENDP

Proxy_midiOutGetDevCapsA PROC
    jmp qword ptr [g_midiOutGetDevCapsA]
Proxy_midiOutGetDevCapsA ENDP

Proxy_midiOutGetDevCapsW PROC
    jmp qword ptr [g_midiOutGetDevCapsW]
Proxy_midiOutGetDevCapsW ENDP

Proxy_midiOutGetErrorTextA PROC
    jmp qword ptr [g_midiOutGetErrorTextA]
Proxy_midiOutGetErrorTextA ENDP

Proxy_midiOutGetErrorTextW PROC
    jmp qword ptr [g_midiOutGetErrorTextW]
Proxy_midiOutGetErrorTextW ENDP

Proxy_midiOutGetID PROC
    jmp qword ptr [g_midiOutGetID]
Proxy_midiOutGetID ENDP

Proxy_midiOutGetNumDevs PROC
    jmp qword ptr [g_midiOutGetNumDevs]
Proxy_midiOutGetNumDevs ENDP

Proxy_midiOutGetVolume PROC
    jmp qword ptr [g_midiOutGetVolume]
Proxy_midiOutGetVolume ENDP

Proxy_midiOutLongMsg PROC
    jmp qword ptr [g_midiOutLongMsg]
Proxy_midiOutLongMsg ENDP

Proxy_midiOutMessage PROC
    jmp qword ptr [g_midiOutMessage]
Proxy_midiOutMessage ENDP

Proxy_midiOutOpen PROC
    jmp qword ptr [g_midiOutOpen]
Proxy_midiOutOpen ENDP

Proxy_midiOutPrepareHeader PROC
    jmp qword ptr [g_midiOutPrepareHeader]
Proxy_midiOutPrepareHeader ENDP

Proxy_midiOutReset PROC
    jmp qword ptr [g_midiOutReset]
Proxy_midiOutReset ENDP

Proxy_midiOutSetVolume PROC
    jmp qword ptr [g_midiOutSetVolume]
Proxy_midiOutSetVolume ENDP

Proxy_midiOutShortMsg PROC
    jmp qword ptr [g_midiOutShortMsg]
Proxy_midiOutShortMsg ENDP

Proxy_midiOutUnprepareHeader PROC
    jmp qword ptr [g_midiOutUnprepareHeader]
Proxy_midiOutUnprepareHeader ENDP

Proxy_midiStreamClose PROC
    jmp qword ptr [g_midiStreamClose]
Proxy_midiStreamClose ENDP

Proxy_midiStreamOpen PROC
    jmp qword ptr [g_midiStreamOpen]
Proxy_midiStreamOpen ENDP

Proxy_midiStreamOut PROC
    jmp qword ptr [g_midiStreamOut]
Proxy_midiStreamOut ENDP

Proxy_midiStreamPause PROC
    jmp qword ptr [g_midiStreamPause]
Proxy_midiStreamPause ENDP

Proxy_midiStreamPosition PROC
    jmp qword ptr [g_midiStreamPosition]
Proxy_midiStreamPosition ENDP

Proxy_midiStreamProperty PROC
    jmp qword ptr [g_midiStreamProperty]
Proxy_midiStreamProperty ENDP

Proxy_midiStreamRestart PROC
    jmp qword ptr [g_midiStreamRestart]
Proxy_midiStreamRestart ENDP

Proxy_midiStreamStop PROC
    jmp qword ptr [g_midiStreamStop]
Proxy_midiStreamStop ENDP

Proxy_mixerClose PROC
    jmp qword ptr [g_mixerClose]
Proxy_mixerClose ENDP

Proxy_mixerGetControlDetailsA PROC
    jmp qword ptr [g_mixerGetControlDetailsA]
Proxy_mixerGetControlDetailsA ENDP

Proxy_mixerGetControlDetailsW PROC
    jmp qword ptr [g_mixerGetControlDetailsW]
Proxy_mixerGetControlDetailsW ENDP

Proxy_mixerGetDevCapsA PROC
    jmp qword ptr [g_mixerGetDevCapsA]
Proxy_mixerGetDevCapsA ENDP

Proxy_mixerGetDevCapsW PROC
    jmp qword ptr [g_mixerGetDevCapsW]
Proxy_mixerGetDevCapsW ENDP

Proxy_mixerGetID PROC
    jmp qword ptr [g_mixerGetID]
Proxy_mixerGetID ENDP

Proxy_mixerGetLineControlsA PROC
    jmp qword ptr [g_mixerGetLineControlsA]
Proxy_mixerGetLineControlsA ENDP

Proxy_mixerGetLineControlsW PROC
    jmp qword ptr [g_mixerGetLineControlsW]
Proxy_mixerGetLineControlsW ENDP

Proxy_mixerGetLineInfoA PROC
    jmp qword ptr [g_mixerGetLineInfoA]
Proxy_mixerGetLineInfoA ENDP

Proxy_mixerGetLineInfoW PROC
    jmp qword ptr [g_mixerGetLineInfoW]
Proxy_mixerGetLineInfoW ENDP

Proxy_mixerGetNumDevs PROC
    jmp qword ptr [g_mixerGetNumDevs]
Proxy_mixerGetNumDevs ENDP

Proxy_mixerMessage PROC
    jmp qword ptr [g_mixerMessage]
Proxy_mixerMessage ENDP

Proxy_mixerOpen PROC
    jmp qword ptr [g_mixerOpen]
Proxy_mixerOpen ENDP

Proxy_mixerSetControlDetails PROC
    jmp qword ptr [g_mixerSetControlDetails]
Proxy_mixerSetControlDetails ENDP

Proxy_mmDrvInstall PROC
    jmp qword ptr [g_mmDrvInstall]
Proxy_mmDrvInstall ENDP

Proxy_mmGetCurrentTask PROC
    jmp qword ptr [g_mmGetCurrentTask]
Proxy_mmGetCurrentTask ENDP

Proxy_mmTaskBlock PROC
    jmp qword ptr [g_mmTaskBlock]
Proxy_mmTaskBlock ENDP

Proxy_mmTaskCreate PROC
    jmp qword ptr [g_mmTaskCreate]
Proxy_mmTaskCreate ENDP

Proxy_mmTaskSignal PROC
    jmp qword ptr [g_mmTaskSignal]
Proxy_mmTaskSignal ENDP

Proxy_mmTaskYield PROC
    jmp qword ptr [g_mmTaskYield]
Proxy_mmTaskYield ENDP

Proxy_mmioAdvance PROC
    jmp qword ptr [g_mmioAdvance]
Proxy_mmioAdvance ENDP

Proxy_mmioAscend PROC
    jmp qword ptr [g_mmioAscend]
Proxy_mmioAscend ENDP

Proxy_mmioClose PROC
    jmp qword ptr [g_mmioClose]
Proxy_mmioClose ENDP

Proxy_mmioCreateChunk PROC
    jmp qword ptr [g_mmioCreateChunk]
Proxy_mmioCreateChunk ENDP

Proxy_mmioDescend PROC
    jmp qword ptr [g_mmioDescend]
Proxy_mmioDescend ENDP

Proxy_mmioFlush PROC
    jmp qword ptr [g_mmioFlush]
Proxy_mmioFlush ENDP

Proxy_mmioGetInfo PROC
    jmp qword ptr [g_mmioGetInfo]
Proxy_mmioGetInfo ENDP

Proxy_mmioInstallIOProcA PROC
    jmp qword ptr [g_mmioInstallIOProcA]
Proxy_mmioInstallIOProcA ENDP

Proxy_mmioInstallIOProcW PROC
    jmp qword ptr [g_mmioInstallIOProcW]
Proxy_mmioInstallIOProcW ENDP

Proxy_mmioOpenA PROC
    jmp qword ptr [g_mmioOpenA]
Proxy_mmioOpenA ENDP

Proxy_mmioOpenW PROC
    jmp qword ptr [g_mmioOpenW]
Proxy_mmioOpenW ENDP

Proxy_mmioRead PROC
    jmp qword ptr [g_mmioRead]
Proxy_mmioRead ENDP

Proxy_mmioRenameA PROC
    jmp qword ptr [g_mmioRenameA]
Proxy_mmioRenameA ENDP

Proxy_mmioRenameW PROC
    jmp qword ptr [g_mmioRenameW]
Proxy_mmioRenameW ENDP

Proxy_mmioSeek PROC
    jmp qword ptr [g_mmioSeek]
Proxy_mmioSeek ENDP

Proxy_mmioSendMessage PROC
    jmp qword ptr [g_mmioSendMessage]
Proxy_mmioSendMessage ENDP

Proxy_mmioSetBuffer PROC
    jmp qword ptr [g_mmioSetBuffer]
Proxy_mmioSetBuffer ENDP

Proxy_mmioSetInfo PROC
    jmp qword ptr [g_mmioSetInfo]
Proxy_mmioSetInfo ENDP

Proxy_mmioStringToFOURCCA PROC
    jmp qword ptr [g_mmioStringToFOURCCA]
Proxy_mmioStringToFOURCCA ENDP

Proxy_mmioStringToFOURCCW PROC
    jmp qword ptr [g_mmioStringToFOURCCW]
Proxy_mmioStringToFOURCCW ENDP

Proxy_mmioWrite PROC
    jmp qword ptr [g_mmioWrite]
Proxy_mmioWrite ENDP

Proxy_mmsystemGetVersion PROC
    jmp qword ptr [g_mmsystemGetVersion]
Proxy_mmsystemGetVersion ENDP

Proxy_sndPlaySoundA PROC
    jmp qword ptr [g_sndPlaySoundA]
Proxy_sndPlaySoundA ENDP

Proxy_sndPlaySoundW PROC
    jmp qword ptr [g_sndPlaySoundW]
Proxy_sndPlaySoundW ENDP

Proxy_timeBeginPeriod PROC
    jmp qword ptr [g_timeBeginPeriod]
Proxy_timeBeginPeriod ENDP

Proxy_timeEndPeriod PROC
    jmp qword ptr [g_timeEndPeriod]
Proxy_timeEndPeriod ENDP

Proxy_timeGetDevCaps PROC
    jmp qword ptr [g_timeGetDevCaps]
Proxy_timeGetDevCaps ENDP

Proxy_timeGetSystemTime PROC
    jmp qword ptr [g_timeGetSystemTime]
Proxy_timeGetSystemTime ENDP

Proxy_timeGetTime PROC
    jmp qword ptr [g_timeGetTime]
Proxy_timeGetTime ENDP

Proxy_timeKillEvent PROC
    jmp qword ptr [g_timeKillEvent]
Proxy_timeKillEvent ENDP

Proxy_timeSetEvent PROC
    jmp qword ptr [g_timeSetEvent]
Proxy_timeSetEvent ENDP

Proxy_waveInAddBuffer PROC
    jmp qword ptr [g_waveInAddBuffer]
Proxy_waveInAddBuffer ENDP

Proxy_waveInClose PROC
    jmp qword ptr [g_waveInClose]
Proxy_waveInClose ENDP

Proxy_waveInGetDevCapsA PROC
    jmp qword ptr [g_waveInGetDevCapsA]
Proxy_waveInGetDevCapsA ENDP

Proxy_waveInGetDevCapsW PROC
    jmp qword ptr [g_waveInGetDevCapsW]
Proxy_waveInGetDevCapsW ENDP

Proxy_waveInGetErrorTextA PROC
    jmp qword ptr [g_waveInGetErrorTextA]
Proxy_waveInGetErrorTextA ENDP

Proxy_waveInGetErrorTextW PROC
    jmp qword ptr [g_waveInGetErrorTextW]
Proxy_waveInGetErrorTextW ENDP

Proxy_waveInGetID PROC
    jmp qword ptr [g_waveInGetID]
Proxy_waveInGetID ENDP

Proxy_waveInGetNumDevs PROC
    jmp qword ptr [g_waveInGetNumDevs]
Proxy_waveInGetNumDevs ENDP

Proxy_waveInGetPosition PROC
    jmp qword ptr [g_waveInGetPosition]
Proxy_waveInGetPosition ENDP

Proxy_waveInMessage PROC
    jmp qword ptr [g_waveInMessage]
Proxy_waveInMessage ENDP

Proxy_waveInOpen PROC
    jmp qword ptr [g_waveInOpen]
Proxy_waveInOpen ENDP

Proxy_waveInPrepareHeader PROC
    jmp qword ptr [g_waveInPrepareHeader]
Proxy_waveInPrepareHeader ENDP

Proxy_waveInReset PROC
    jmp qword ptr [g_waveInReset]
Proxy_waveInReset ENDP

Proxy_waveInStart PROC
    jmp qword ptr [g_waveInStart]
Proxy_waveInStart ENDP

Proxy_waveInStop PROC
    jmp qword ptr [g_waveInStop]
Proxy_waveInStop ENDP

Proxy_waveInUnprepareHeader PROC
    jmp qword ptr [g_waveInUnprepareHeader]
Proxy_waveInUnprepareHeader ENDP

Proxy_waveOutBreakLoop PROC
    jmp qword ptr [g_waveOutBreakLoop]
Proxy_waveOutBreakLoop ENDP

Proxy_waveOutClose PROC
    jmp qword ptr [g_waveOutClose]
Proxy_waveOutClose ENDP

Proxy_waveOutGetDevCapsA PROC
    jmp qword ptr [g_waveOutGetDevCapsA]
Proxy_waveOutGetDevCapsA ENDP

Proxy_waveOutGetDevCapsW PROC
    jmp qword ptr [g_waveOutGetDevCapsW]
Proxy_waveOutGetDevCapsW ENDP

Proxy_waveOutGetErrorTextA PROC
    jmp qword ptr [g_waveOutGetErrorTextA]
Proxy_waveOutGetErrorTextA ENDP

Proxy_waveOutGetErrorTextW PROC
    jmp qword ptr [g_waveOutGetErrorTextW]
Proxy_waveOutGetErrorTextW ENDP

Proxy_waveOutGetID PROC
    jmp qword ptr [g_waveOutGetID]
Proxy_waveOutGetID ENDP

Proxy_waveOutGetNumDevs PROC
    jmp qword ptr [g_waveOutGetNumDevs]
Proxy_waveOutGetNumDevs ENDP

Proxy_waveOutGetPitch PROC
    jmp qword ptr [g_waveOutGetPitch]
Proxy_waveOutGetPitch ENDP

Proxy_waveOutGetPlaybackRate PROC
    jmp qword ptr [g_waveOutGetPlaybackRate]
Proxy_waveOutGetPlaybackRate ENDP

Proxy_waveOutGetPosition PROC
    jmp qword ptr [g_waveOutGetPosition]
Proxy_waveOutGetPosition ENDP

Proxy_waveOutGetVolume PROC
    jmp qword ptr [g_waveOutGetVolume]
Proxy_waveOutGetVolume ENDP

Proxy_waveOutMessage PROC
    jmp qword ptr [g_waveOutMessage]
Proxy_waveOutMessage ENDP

Proxy_waveOutOpen PROC
    jmp qword ptr [g_waveOutOpen]
Proxy_waveOutOpen ENDP

Proxy_waveOutPause PROC
    jmp qword ptr [g_waveOutPause]
Proxy_waveOutPause ENDP

Proxy_waveOutPrepareHeader PROC
    jmp qword ptr [g_waveOutPrepareHeader]
Proxy_waveOutPrepareHeader ENDP

Proxy_waveOutReset PROC
    jmp qword ptr [g_waveOutReset]
Proxy_waveOutReset ENDP

Proxy_waveOutRestart PROC
    jmp qword ptr [g_waveOutRestart]
Proxy_waveOutRestart ENDP

Proxy_waveOutSetPitch PROC
    jmp qword ptr [g_waveOutSetPitch]
Proxy_waveOutSetPitch ENDP

Proxy_waveOutSetPlaybackRate PROC
    jmp qword ptr [g_waveOutSetPlaybackRate]
Proxy_waveOutSetPlaybackRate ENDP

Proxy_waveOutSetVolume PROC
    jmp qword ptr [g_waveOutSetVolume]
Proxy_waveOutSetVolume ENDP

Proxy_waveOutUnprepareHeader PROC
    jmp qword ptr [g_waveOutUnprepareHeader]
Proxy_waveOutUnprepareHeader ENDP

Proxy_waveOutWrite PROC
    jmp qword ptr [g_waveOutWrite]
Proxy_waveOutWrite ENDP

END
