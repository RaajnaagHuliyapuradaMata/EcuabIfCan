#if !defined (CANIF_TYPES_H)
# define CANIF_TYPES_H

# define CANIF_CFGVAR_PRECOMPILETIME           1u
# define CANIF_CFGVAR_LINKTIME                 2u
# define CANIF_CFGVAR_POSTBUILDTIME            3u

# define CANIF_TYPES_MAJOR_VERSION             0x06u
# define CANIF_TYPES_MINOR_VERSION             0x17u
# define CANIF_TYPES_PATCH_VERSION             0x00u

# define CANIF_E_PARAM_CANID                   10u
# define CANIF_E_PARAM_DLC                     11u
# define CANIF_E_PARAM_HRH                     12u
# define CANIF_E_PARAM_LPDU                    13u
# define CANIF_E_PARAM_CONTROLLER              14u
# define CANIF_E_PARAM_CONTROLLERID            15u
# define CANIF_E_PARAM_WAKEUPSOURCE            16u
# define CANIF_E_PARAM_TRCV                    17u
# define CANIF_E_PARAM_TRCVMODE                18u
# define CANIF_E_PARAM_TRCVWAKEUPMODE          19u
# define CANIF_E_PARAM_POINTER                 20u
# define CANIF_E_PARAM_CTRLMODE                21u
# define CANIF_E_PARAM_PDU_MODE                22u

# define CANIF_E_UNINIT                        30u

# define CANIF_E_INVALID_TXPDUID               50u
# define CANIF_E_INVALID_RXPDUID               60u
# define CANIF_E_INVALID_DLC                   61u
# define CANIF_E_STOPPED                       70u
# define CANIF_E_NOT_SLEEP                     71u

# define CANIF_E_NO_ERROR                      0u
# define CANIF_E_INVALID_PDURECEPTIONMODE      44u
# define CANIF_E_CONFIG                        45u
# define CANIF_E_FATAL                         46u
# define CANIF_E_INVALID_SA                    47u
# define CANIF_E_INVALID_DA                    48u
# define CANIF_E_INVALID_CANIDTYPESIZE         49u
# define CANIF_E_INVALID_DLC_METADATA          50u

# define CANIF_E_FULL_TX_BUFFER_FIFO           51u
# define CANIF_E_INVALID_DOUBLEHASH_CALC       52u

# define CANIF_MODULE_ID                       60u

# define CANIF_VENDOR_ID                       0x001Eu

# define CANIF_LINEAR                          1u
# define CANIF_BINARY                          2u
# define CANIF_DOUBLE_HASH                     3u

# define CanIf_TrcvIndex_INVALID               ((uint8)0xFFu)

# define infEcuabCanIfSwcApplEcuM_InitFunction_API                        1u

# define CANIF_SETCONTROLLERMODE_API           3u
# define CANIF_GETCONTROLLERMODE_API           4u
# define EcuabCanIf_Transmit_API                    5u

# define CANIF_SETPDUMODE_API                  9u
# define CANIF_GETPDUMODE_API                  10u
# define CANIF_GETVERSIONINFO_API              11u

# define CANIF_SETDYNAMICTXID_API_ID           12u

# define CANIF_SETTRCVMODE_API                 13u
# define CANIF_GETTRCVMODE_API                 14u
# define CANIF_GETTRCVWAKEUPREASON_API         15u
# define CANIF_SETTRCVWAKEUPMODE_API           16u

# define CANIF_CHECKWAKEUP_API                 17u

# define CANIF_CHECKVALIDATIONUP_API           18u

# define EcuabCanIf_TxConfirmation_API              19u
# define EcuabCanIf_RxIndication_API                20u

# define CANIF_CANCELTXCONFIRMATION_API        21u

# define CANIF_CONTROLLERBUSOFF_API            22u

# define CANIF_CONTROLLERMODEINDICATION_API    23u
# define CANIF_TRCVMODEINDICATION_API          24u

# define CANIF_GETTXCONFIRMATIONSTATE_API      25u

# define CANIF_CONFIRMPNAVAILABILITY_API       26u
# define CANIF_BAUDRATECHECK_API               28u
# define CANIF_BAUDRATECHANGE_API              27u
# define CANIF_BAUDRATESET_API                 39u

# define CANIF_CLEARTRCVWUFFLAG_API            30u
# define CANIF_CHECKTRCVWAKEFLAG_API           31u
# define CANIF_CLEARTRCVWUFFLAGINDICATION_API  32u
# define CANIF_CHECKTRCVWAKEFLAGINDICATION_API 33u

#define CANIF_GETCONTROLLERERRORSTATE_API      75u
#define CANIF_ENABLEBUSMIRRORING_API           76u
#define CANIF_GETCONTROLLERRXERRORCOUNTER_API  77u
#define CANIF_GETCONTROLLERTXERRORCOUNTER_API  78u

#define CANIF_APPL_GENERICCONFIRMATION_API     243u

# define CANIF_RAMCHECKEXECUTE_API             249u
# define CANIF_RAMCHECKENABLEMAILBOX_API       248u
# define CANIF_RAMCHECKENABLECONTROLLER_API    247u
# define CANIF_SETPDURECEPTIONMODE_API         246u
# define CANIF_RAMCHECKCORRUPTMAILBOX_API      245u
# define CANIF_RAMCHECKCORRUPTCONTROLLER_API   244u

# define CANIF_CANCELTRANSMIT_API              250u
# define CANIF_TXNOTIFICATION_API              251u

# define CANIF_SETADDRESSTABLEENTRY_API        252u
# define CANIF_RESETADDRESSTABLEENTRY_API      253u

# define CANIF_J1939_DYN_ADDR_DISABLED         0u
# define CANIF_J1939_DYN_ADDR_EXT_CANID        1u
# define CANIF_J1939_DYN_ADDR_MIXED_CANID      2u

# define CANIF_STATIC_BUFFER_SIZE              8u

# include "Types_McalCan.hpp"
# if((CANIF_WAKEUP_SUPPORT == STD_ON) || (CANIF_WAKEUP_VALIDATION == STD_ON) || (CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME))
#  include "EcuM_Cbk.hpp"
# endif

# if !defined (CANIF_PN_WU_TX_PDU_FILTER)
#  error "CANIF_PN_WU_TX_PDU_FILTER is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_TRCV_HANDLING)
#  error "CANIF_TRCV_HANDLING is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_PN_TRCV_HANDLING)
#  error "CANIF_PN_TRCV_HANDLING is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_WAKEUP_VALIDATION)
#  error "CANIF_WAKEUP_VALIDATION is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_SETDYNAMICTXID_API)
#  error "CANIF_SETDYNAMICTXID_API is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_META_DATA_RX_SUPPORT)
#  error "CANIF_META_DATA_RX_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_META_DATA_TX_SUPPORT)
#  error "CANIF_META_DATA_TX_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_STATIC_FD_TXQUEUE)
#  error "CANIF_STATIC_FD_TXQUEUE is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_MULTIPLE_CANDRV_SUPPORT)
#  error "CANIF_MULTIPLE_CANDRV_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_CANCEL_SUPPORT_API)
#  error "CANIF_CANCEL_SUPPORT_API is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_WAKEUP_SUPPORT)
#  error "CANIF_WAKEUP_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_CHANGE_BAUDRATE_SUPPORT)
#  error "CANIF_CHANGE_BAUDRATE_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_SET_BAUDRATE_API)
#  error "CANIF_SET_BAUDRATE_API is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_J1939_DYN_ADDR_SUPPORT)
#  error "CANIF_J1939_DYN_ADDR_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CPU_TYPE)
#  error "CPU_TYPE is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if !defined (CANIF_SEARCH_ALGORITHM)
#  error "CANIF_SEARCH_ALGORITHM is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
# endif

# if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#  define CanIf_HwHandleType uint16
# else
#  define CanIf_HwHandleType Can_HwHandleType
# endif

typedef enum{
  CANIF_CS_UNINIT = 0u,
  CANIF_CS_STOPPED,
  CANIF_CS_STARTED,
  CANIF_CS_SLEEP
}CanIf_ControllerModeType;

typedef enum{
  CANIF_SET_OFFLINE = 0u,
  CANIF_SET_RX_OFFLINE,
  CANIF_SET_RX_ONLINE,
  CANIF_SET_TX_OFFLINE,
  CANIF_SET_TX_ONLINE,
  CANIF_SET_ONLINE,
  CANIF_SET_TX_OFFLINE_ACTIVE,
# if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
  CANIF_SET_ONLINE_WAKF,
  CANIF_SET_TX_ONLINE_WAKF,
# endif
  CANIF_NO_MODE_PDU_SET_MODE_TYPE_END
}CanIf_PduSetModeType;

typedef enum{
  CANIF_GET_OFFLINE = 0u,
  CANIF_GET_RX_ONLINE,
  CANIF_GET_TX_ONLINE,
  CANIF_GET_ONLINE,
  CANIF_GET_OFFLINE_ACTIVE,
  CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE,
# if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
  CANIF_GET_ONLINE_WAKF,
  CANIF_GET_TX_ONLINE_WAKF,
# endif
  CANIF_NO_MODE_PDU_GET_MODE_TYPE_END
}CanIf_PduGetModeType;

typedef enum{
  CANIF_RxBasicCANMailbox = 0u,
  CANIF_RxFullCANMailbox,
  CANIF_TxBasicCANMailbox,
  CANIF_TxFullCANMailbox,
  CANIF_UnusedCANMailbox
}CanIf_MailBoxTypeType;

typedef enum{
  CanIf_SimpleRxIndicationLayout = 0u,
  CanIf_AdvancedRxIndicationLayout,
  CanIf_NmOsekRxIndicationLayout,
  CanIf_CddRxIndicationLayout
}EcuabCanIf_RxIndicationLayoutType;

typedef enum{
  CANIF_NO_NOTIFICATION = 0u,
  CANIF_TX_RX_NOTIFICATION
}CanIf_NotifStatusType;

typedef enum{
  CANIF_WAKEUPREQUEST_NONE = 0u,
  CANIF_WAKEUPREQUEST_CAN  = 1u,
  CANIF_WAKEUPREQUEST_TRCV = 2u
}CanIf_WakeUpTargetType;

typedef enum{
  CANIF_WUVALIDATION_IDLE     = 0u,
  CANIF_WUVALIDATION_ARMED    = 1u,
  CANIF_WUVALIDATION_DETECTED = 2u
}CanIf_WakeUpValidationStateType;

typedef enum{
  CANIF_DO_TRANSMIT     = 0u,
  CANIF_DO_NOT_TRANSMIT = 1u
}EcuabCanIf_TransmitStateType;

typedef enum{
  CANIF_MSG_TYPE_CAN = 0u,
  CANIF_MSG_TYPE_FD_CAN,
  CANIF_MSG_TYPE_NO_FD_CAN
}CanIf_MsgType;

typedef enum{
  CANIF_RMT_RECEIVE_STOP      = 0u,
  CANIF_RMT_IGNORE_CONTINUE   = 1u
}CanIf_ReceptionModeType;

typedef struct sCanIf_RxSearchParamsType{
  Can_IdType    eCanId;
  PduIdType     eRxPduId;
  PduIdType     eRxPduIdMatch;
# if(CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON) || (CANIF_META_DATA_RX_SUPPORT == STD_ON)
  CanIf_MsgType eRxMsgType;
# endif
  CanIf_HwHandleType eHrh;
  boolean       eContinueSearch;
}CanIf_RxSearchParamsType;

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, EcuabCanIf_TxConfirmationFctType) (VAR(PduIdType, AUTOMATIC) CanTxPduId);

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_SimpleRxIndicationFctType) (VAR(PduIdType, AUTOMATIC) CanRxPduId, P2CONST(uint8, AUTOMATIC, CANIF_UL_STANDARD_VAR) CanSduPtr);

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_AdvancedRxIndicationFctType) (VAR(PduIdType, AUTOMATIC) CanRxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_UL_ADVANCED_VAR) PduInfoPtr);

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_NmOsekRxIndicationFctType) (VAR(PduIdType, AUTOMATIC) CanRxPduId, P2CONST(uint8, AUTOMATIC, CANIF_UL_OSEKNM_VAR) CanSduPtr, VAR(Can_IdType, AUTOMATIC) CanId);

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_CddRxIndicationFctType) (VAR(PduIdType, AUTOMATIC) CanRxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_UL_ADVANCED_VAR) PduInfoPtr, VAR(Can_IdType, AUTOMATIC) CanId);

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_CtrlModeIndicationFctType) (VAR(uint8, AUTOMATIC) ControllerId, VAR(CanIf_ControllerModeType, AUTOMATIC) ControllerMode);

typedef P2FUNC(void, CANIF_APPL_STATE_CODE, CanIf_BusOffNotificationFctType) (VAR(uint8, AUTOMATIC) ControllerId);

# if(CANIF_WAKEUP_VALIDATION == STD_ON)

typedef P2FUNC(void, CANIF_APPL_STATE_CODE, CanIf_WakeUpValidationFctType) (VAR(EcuM_WakeupSourceType, AUTOMATIC) CanWakeupEvents);
# endif

# if(CANIF_EXTENDED_RAM_CHECK_SUPPORT == STD_ON)

typedef P2FUNC(void, CANIF_APPL_STATE_CODE, CanIf_RamCheckCorruptMailboxIndFctType) (VAR(uint8, AUTOMATIC) ControllerId, VAR(CanIf_HwHandleType, AUTOMATIC) HwHandle);

typedef P2FUNC(void, CANIF_APPL_STATE_CODE, CanIf_RamCheckCorruptControllerIndFctType) (VAR(uint8, AUTOMATIC) ControllerId);
# endif

# if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)

typedef P2FUNC(Can_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_SetControllerModeFctType) (VAR(uint8, AUTOMATIC) Controller, VAR(Can_StateTransitionType, AUTOMATIC) Transition);

typedef P2FUNC(Can_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_WriteFctType) (VAR(Can_HwHandleType, AUTOMATIC) Hth, P2CONST(Can_PduType, AUTOMATIC, CANIF_VAR_STACK) PduInfo);

#  if(CANIF_CANCEL_SUPPORT_API == STD_ON)

typedef P2FUNC(void, CANIF_CBK_CANDRV_CODE, CanIf_Can_CancelTxFctType) (VAR(Can_HwHandleType, AUTOMATIC) Hth, VAR(PduIdType, AUTOMATIC) PduId);
#  endif

#  if(CANIF_WAKEUP_SUPPORT == STD_ON)

typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_CheckWakeupFctType) (VAR(uint8, AUTOMATIC) Controller);
#  endif

#  if(CANIF_CHANGE_BAUDRATE_SUPPORT == STD_ON)

typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_CheckBaudrateFctType) (VAR(uint8, AUTOMATIC) Controller, CONST(uint16, AUTOMATIC) Baudrate);

typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_ChangeBaudrateFctType) (VAR(uint8, AUTOMATIC) Controller, CONST(uint16, AUTOMATIC) Baudrate);
#  endif

#  if(CANIF_SET_BAUDRATE_API == STD_ON)

typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_SetBaudrateFctType) (VAR(uint8, AUTOMATIC) Controller, VAR(uint16, AUTOMATIC) BaudRateConfigID);
#  endif

#  if(CANIF_EXTENDED_RAM_CHECK_SUPPORT == STD_ON)

typedef P2FUNC(void, CANIF_CBK_CANDRV_CODE, CanIf_Can_RamCheckExecuteFctType) (VAR(uint8, AUTOMATIC) Controller);

typedef P2FUNC(void, CANIF_CBK_CANDRV_CODE, CanIf_Can_RamCheckEnableMailboxFctType) (VAR(Can_HwHandleType, AUTOMATIC) htrh);

typedef P2FUNC(void, CANIF_CBK_CANDRV_CODE, CanIf_Can_RamCheckEnableControllerFctType) (VAR(uint8, AUTOMATIC) Controller);
#  endif

# if(CANIF_BUS_MIRRORING_SUPPORT == STD_ON)

typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_GetControllerErrorStateFctType) (VAR(uint8, AUTOMATIC) Controller, P2VAR(Can_ErrorStateType, AUTOMATIC, CANIF_VAR_STACK) ErrorStatePtr);

typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_GetControllerRxErrorCounterFctType) (VAR(uint8, AUTOMATIC) Controller, P2VAR(uint8, AUTOMATIC, CANIF_VAR_STACK) RxErrorCounterPtr);

typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_GetControllerTxErrorCounterFctType) (VAR(uint8, AUTOMATIC) Controller, P2VAR(uint8, AUTOMATIC, CANIF_VAR_STACK) TxErrorCounterPtr);
#  endif
# endif

# if(CANIF_TRCV_HANDLING == STD_ON)

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_TrcvModeIndicationFctType) (VAR(uint8, AUTOMATIC) TransceiverId, VAR(CanTrcv_TrcvModeType, AUTOMATIC) TransceiverMode);

typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_CheckWakeupFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex);

typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_SetOpModeFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex, VAR(CanTrcv_TrcvModeType, AUTOMATIC) OpMode);

typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_GetOpModeFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex, P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) OpMode);

typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_GetBusWuReasonFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex, P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_STATE_VAR)Reason);

typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_SetWakeupModeFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);

#  if(CANIF_PN_TRCV_HANDLING == STD_ON)

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_ConfirmPnAvailabilityFctType) (VAR(uint8, AUTOMATIC) TransceiverId);

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_ClearTrcvWufFlagIndicationFctType) (VAR(uint8, AUTOMATIC) TransceiverId);

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_CheckTrcvWakeFlagIndicationFctType) (VAR(uint8, AUTOMATIC) TransceiverId);

#   if(CANIF_TRCV_MAPPING == STD_ON)

typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_ClearTrcvWufFlagFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex);

typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_CheckWakeFlagFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex);
#   endif

#  endif
# endif

typedef union
{
  CanIf_SimpleRxIndicationFctType     eSimpleRxIndicationType;
  CanIf_AdvancedRxIndicationFctType   eAdvancedRxIndicationType;
  CanIf_NmOsekRxIndicationFctType     eNmOsekRxIndicationType;
  CanIf_CddRxIndicationFctType        eCddRxIndicationType;
}EcuabCanIf_RxIndicationFctType;

# if( CPU_TYPE == CPU_TYPE_8 )
typedef uint8 CanIf_TxQueueFlagType;
# elif( CPU_TYPE == CPU_TYPE_16 )
typedef uint16 CanIf_TxQueueFlagType;
# else
typedef uint32 CanIf_TxQueueFlagType;
# endif

typedef boolean CanIf_CancelResultType;

typedef struct sCanIf_TxQueueBaseType{
# if((CANIF_SETDYNAMICTXID_API == STD_ON) || (CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED) || (CANIF_META_DATA_TX_SUPPORT == STD_ON))
  Can_IdType    eCanId;
# endif
  uint8         eSduLength;
}CanIf_TxQueueBaseType;

typedef struct sCanIf_TxQueueBaseWithDataType{
# if(CANIF_STATIC_FD_TXQUEUE == STD_OFF)
  uint8                   eSdu[CANIF_STATIC_BUFFER_SIZE];
# endif
  CanIf_TxQueueBaseType eBaseParams;
}CanIf_TxQueueBaseWithDataType;

typedef struct sCanIf_TxPrioByCanIdByteQueueType{
  CanIf_TxQueueBaseWithDataType eQueueParams;
  uint8                         eQueued;
}CanIf_TxPrioByCanIdByteQueueType;

typedef struct sCanIf_TxPrioByCanIdBitQueueType{
  CanIf_TxQueueBaseWithDataType eQueueParams;
}CanIf_TxPrioByCanIdBitQueueType;

typedef struct sCanIf_TxBufferPrioByCanIdBaseType{
  CanIf_TxBufferSizeType  eQueueCounter;
}CanIf_TxBufferPrioByCanIdBaseType;

typedef struct sCanIf_TxFifoQueueBaseType{
  CanIf_TxQueueBaseType eBaseParams;
  PduIdType             eTxPduId;
# if(CANIF_CANCEL_SUPPORT_API == STD_ON)
  uint8                 eQueued;
# endif
}CanIf_TxFifoQueueBaseType;

typedef struct sCanIf_TxBufferFifoBaseType{
  CanIf_TxBufferSizeType  eWriteIdx;
  CanIf_TxBufferSizeType  eReadIdx;
  CanIf_TxBufferSizeType  eQueueCounter;
}CanIf_TxBufferFifoBaseType;

typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_DataChecksumRxErrFctType) (VAR(PduIdType, AUTOMATIC) CanIfRxPduId);

#endif

