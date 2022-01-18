#pragma once

#include "Std_Types.h"
#include "Compiler_Cfg_CanIf.h"

class class_CanIf{
   public:
      FUNC(void, CANIF_CODE) InitFunction                  (void);
      FUNC(void, CANIF_CODE) GetControllerMode             (void);
      FUNC(void, CANIF_CODE) SetControllerMode             (void);
      FUNC(void, CANIF_CODE) Transmit                      (void);
      FUNC(void, CANIF_CODE) CancelTransmit                (void);
      FUNC(void, CANIF_CODE) ReadRxPduData                 (void);
      FUNC(void, CANIF_CODE) ReadTxNotifStatus             (void);
      FUNC(void, CANIF_CODE) ReadRxNotifStatus             (void);
      FUNC(void, CANIF_CODE) GetPduMode                    (void);
      FUNC(void, CANIF_CODE) SetPduMode                    (void);
      FUNC(void, CANIF_CODE) GetVersionInfo                (void);
      FUNC(void, CANIF_CODE) SetDynamicTxId                (void);
      FUNC(void, CANIF_CODE) GetTrcvMode                   (void);
      FUNC(void, CANIF_CODE) SetTrcvMode                   (void);
      FUNC(void, CANIF_CODE) GetTrcvWakeupReason           (void);
      FUNC(void, CANIF_CODE) SetTrcvWakeupMode             (void);
      FUNC(void, CANIF_CODE) CheckWakeup                   (void);
      FUNC(void, CANIF_CODE) CheckValidation               (void);
      FUNC(void, CANIF_CODE) GetTxConfirmationState        (void);
      FUNC(void, CANIF_CODE) ClearTrcvWufFlag              (void);
      FUNC(void, CANIF_CODE) CheckTrcvWakeFlag             (void);
      FUNC(void, CANIF_CODE) CheckBaudRate                 (void);
      FUNC(void, CANIF_CODE) ChangeBaudRate                (void);
      FUNC(void, CANIF_CODE) CbTxConfirmation              (void);
      FUNC(void, CANIF_CODE) CbRxIndication                (void);
      FUNC(void, CANIF_CODE) CbCancelTxConfirmation        (void);
      FUNC(void, CANIF_CODE) CbControllerBusOff            (void);
      FUNC(void, CANIF_CODE) CbConfirmPnAvailability       (void);
      FUNC(void, CANIF_CODE) CbClearTrcvWufFlagIndication  (void);
      FUNC(void, CANIF_CODE) CbCheckTrcvWakeFlagIndication (void);
      FUNC(void, CANIF_CODE) CbControllerModeIndication    (void);
      FUNC(void, CANIF_CODE) CbTrcvModeIndication          (void);
};

extern class_CanIf CanIf;

