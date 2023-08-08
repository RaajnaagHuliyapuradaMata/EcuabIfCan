#if !defined (CANIF_H)
# define CANIF_H
#ifdef __cplusplus
extern "C"
{
#endif

# include "CfgEcuabCanIf.hpp"

# define CANIF_SW_MAJOR_VERSION                    0x06u
# define CANIF_SW_MINOR_VERSION                    0x19u
# define CANIF_SW_PATCH_VERSION                    0x00u
# define CANIF_AR_RELEASE_MAJOR_VERSION            0x04u
# define CANIF_AR_RELEASE_MINOR_VERSION            0x00u
# define CANIF_AR_RELEASE_REVISION_VERSION         0x03u
# define CANIF_API_MAJOR_VERSION                   CANIF_SW_MAJOR_VERSION
# define CANIF_API_MINOR_VERSION                   CANIF_SW_MINOR_VERSION
# define CANIF_API_PATCH_VERSION                   CANIF_SW_PATCH_VERSION
# define IF_ASRIFCAN_VERSION                       ((CANIF_SW_MAJOR_VERSION << 8u) | CANIF_SW_MINOR_VERSION)
# define IF_ASRIFCAN_RELEASE_VERSION               CANIF_SW_PATCH_VERSION
# define CANIF_GENDATA_COMPATIBILITY_VERSION       0x0212u
# define CANIF_DATACHECKSUM_COMPATIBILITY_VERSION  0x0101u
# define CANIF_MAGIC_NUMBER                        CANIF_FINAL_MAGIC_NUMBER
# define CANIF_EXT_CANID_MASK                      0x80000000u

# if(CANIF_DEV_ERROR_DETECT == STD_ON)

#  define CanIf_Det_ReportError(APIID, ErrorCode)  ((void)Det_ReportError(CANIF_MODULE_ID, 0, (APIID), (ErrorCode)))
# else
#  define CanIf_Det_ReportError(APIID, ErrorCode)
# endif

# if !defined (CANIF_LOCAL)
#  define CANIF_LOCAL static
# endif

# if !defined (CANIF_LOCAL_INLINE)
#  define CANIF_LOCAL_INLINE LOCAL_INLINE
# endif

# define CANIF_START_SEC_CODE
# include "MemMap.hpp"

FUNC(void, CANIF_CODE) infEcuabCanIfSwcApplEcuM_InitFunctionMemory(void);
FUNC(void, CANIF_CODE) infEcuabCanIfSwcApplEcuM_InitFunction(P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_XCFG) ConfigPtr);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode(uint8 ControllerId, CanIf_ControllerModeType ControllerMode);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(uint8 ControllerId, P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) ControllerModePtr);
FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_Transmit(PduIdType CanTxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_MSG_VAR) PduInfoPtr);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(uint8 ControllerId, CanIf_PduSetModeType PduModeRequest);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode(uint8 ControllerId, P2VAR(CanIf_PduGetModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) PduModePtr);

# if(CANIF_VERSION_INFO_API == STD_ON)
FUNC(void, CANIF_CODE) CanIf_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_VAR) VersionInfo);
# endif

# if(CANIF_TRCV_HANDLING == STD_ON)
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode(P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) TransceiverModePtr, uint8 TransceiverId);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason(uint8 TransceiverId, P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_STATE_VAR) TrcvWuReasonPtr);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode(uint8 TransceiverId, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);

#  if(CANIF_PN_TRCV_HANDLING == STD_ON)
FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability(uint8 TransceiverId);
FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId);
FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag(uint8 TransceiverId);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag(uint8 TransceiverId);
#  endif
# endif

# if(CANIF_WAKEUP_SUPPORT == STD_ON)
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
# endif

# if((CANIF_WAKEUP_SUPPORT == STD_ON) && (CANIF_WAKEUP_VALIDATION == STD_ON))
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource);
# endif

# if(CANIF_SETDYNAMICTXID_API == STD_ON)
FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId(PduIdType CanTxPduId, Can_IdType CanId);
# endif

# if(CANIF_CANCEL_SUPPORT_API == STD_ON)
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit(PduIdType CanTxPduId);
# endif

FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication(uint8 ControllerId, CanIf_ControllerModeType ControllerMode);

# if(CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON)
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState(uint8 ControllerId);
# endif

# if(CANIF_CHANGE_BAUDRATE_SUPPORT == STD_ON)
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckBaudrate(uint8 ControllerId, CONST(uint16, CANIF_CONST) Baudrate);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ChangeBaudrate(uint8 ControllerId, CONST(uint16, CANIF_CONST) Baudrate);
# endif

# if(CANIF_SET_BAUDRATE_API == STD_ON)
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID);
# endif

# if(CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#  if(CANIF_EXTENDEDID_SUPPORT == STD_ON)
FUNC(void, CANIF_CODE) CanIf_SetAddressTableEntry(uint8 ControllerId, uint8 intAddr, uint8 busAddr);
FUNC(void, CANIF_CODE) CanIf_ResetAddressTableEntry(uint8 ControllerId, uint8 intAddr);
#  endif
# endif

# if(CANIF_EXTENDED_RAM_CHECK_SUPPORT == STD_ON)
FUNC(void, CANIF_CODE) CanIf_RamCheckCorruptMailbox(uint8 ControllerId, CanIf_HwHandleType HwHandle);
FUNC(void, CANIF_CODE) CanIf_RamCheckCorruptController(uint8 ControllerId);
FUNC(void, CANIF_CODE) CanIf_RamCheckExecute(uint8 ControllerId);
FUNC(void, CANIF_CODE) CanIf_RamCheckEnableMailbox(uint8 ControllerId, CanIf_HwHandleType HwHandle);
FUNC(void, CANIF_CODE) CanIf_RamCheckEnableController(uint8 ControllerId);
# endif

# if(CANIF_DATA_CHECKSUM_TX_SUPPORT == STD_ON)
FUNC(void, CANIF_CODE) EcuabCanIf_TransmitSubDataChecksumTxAppend(P2CONST(Can_PduType, AUTOMATIC, CANIF_VAR_STACK) txPduInfoPtr, P2VAR(uint8, AUTOMATIC, CANIF_VAR_STACK) txPduDataWithChecksumPtr);
# endif

# if(CANIF_DATA_CHECKSUM_RX_SUPPORT == STD_ON)
FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_RxIndicationSubDataChecksumRxVerify(PduIdType CanIfRxPduId, Can_IdType CanId, uint8 CanDlc, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR)CanSduPtr);
# endif

# if(CANIF_SET_PDU_RECEPTION_MODE_SUPPORT == STD_ON)
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduReceptionMode(PduIdType id, CanIf_ReceptionModeType mode);
# endif

# if(CANIF_BUS_MIRRORING_SUPPORT == STD_ON)
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerErrorState(uint8 ControllerId, P2VAR(Can_ErrorStateType, AUTOMATIC, CANIF_APPL_STATE_VAR) ErrorStatePtr);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerRxErrorCounter(uint8 ControllerId, P2VAR(uint8, AUTOMATIC, CANIF_APPL_STATE_VAR) RxErrorCounterPtr);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerTxErrorCounter(uint8 ControllerId, P2VAR(uint8, AUTOMATIC, CANIF_APPL_STATE_VAR) TxErrorCounterPtr);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_EnableBusMirroring(uint8 ControllerId, boolean MirroringActive);
#endif

# define CANIF_STOP_SEC_CODE
# include "MemMap.hpp"

# define CANIF_START_SEC_CONST_8BIT
# include "MemMap.hpp"

extern CONST(uint8, CANIF_CONST) CanIf_MainVersion;
extern CONST(uint8, CANIF_CONST) CanIf_SubVersion;
extern CONST(uint8, CANIF_CONST) CanIf_ReleaseVersion;

# define CANIF_STOP_SEC_CONST_8BIT
# include "MemMap.hpp"

# if(CANIF_USE_INIT_POINTER == STD_ON)

#  define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.hpp"

extern P2CONST(CanIf_ConfigType, CANIF_VAR_INIT, CANIF_XCFG) CanIf_ConfigDataPtr;

#  define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.hpp"
# endif

#ifdef __cplusplus
}
#endif
#endif

