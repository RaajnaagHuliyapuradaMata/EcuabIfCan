#if !defined (CANIF_CBK_H)
# define CANIF_CBK_H
#ifdef __cplusplus
extern "C"
{
#endif

# include "CfgEcuabCanIf.hpp"

# define CANIF_CBK_MAJOR_VERSION   0x05u
# define CANIF_CBK_MINOR_VERSION   0x05u
# define CANIF_CBK_PATCH_VERSION   0x00u

# define CANIF_START_SEC_CODE
# include "MemMap.hpp"

FUNC(void, CANIF_CODE) EcuabCanIf_TxConfirmation(PduIdType CanTxPduId);
FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationAsr403(CanIf_HwHandleType Hrh, Can_IdType CanId, uint8 CanDlc, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR)CanSduPtr);

# if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)
#  if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_OFF)
#   if(EcuabCanIf_Transmit_CANCELLATION == STD_ON)
FUNC(void, CANIF_CODE) CanIf_CancelTxConfirmation(PduIdType CanTxPduId, P2CONST(Can_PduType, AUTOMATIC, CANIF_CBK_DRV_VAR) PduInfoPtr);
#   endif
#  endif
# endif

FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(uint8 ControllerId);

# if(CANIF_CANCEL_SUPPORT_API == STD_ON)
FUNC(void, CANIF_CODE) CanIf_CancelTxNotification(PduIdType PduId, CanIf_CancelResultType IsCancelled);
# endif

# define CANIF_STOP_SEC_CODE
# include "MemMap.hpp"

#ifdef __cplusplus
}
#endif
#endif

