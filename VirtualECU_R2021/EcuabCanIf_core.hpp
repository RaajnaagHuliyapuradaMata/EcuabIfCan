#pragma once
/******************************************************************************/
/* File   : EcuabCanIf_core.hpp                                                    */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_EcuabCanIf.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

//FUNC(Std_TypeReturn, CANIF_CODE) module_EcuabCanIf::GetControllerErrorState(

#define CANIF_CORE_FUNCTIONALITIES                                                       \
              FUNC(Std_TypeReturn, CANIF_CODE) GetControllerMode             (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) SetControllerMode             (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) Transmit                      (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) McalCancelTransmit                (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) ReadRxPduData                 (void);     \
              FUNC(void,           CANIF_CODE) ReadTxNotifStatus             (void);     \
              FUNC(void,           CANIF_CODE) ReadRxNotifStatus             (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) GetPduMode                    (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) SetPduMode                    (void);     \
              FUNC(void,           CANIF_CODE) SetDynamicTxId                (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) GetTrcvMode                   (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) SetTrcvMode                   (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) GetTrcvWakeupReason           (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) SetTrcvWakeupMode             (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) CheckWakeup                   (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) CheckValidation               (void);     \
              FUNC(void,           CANIF_CODE) GetTxConfirmationState        (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) ClearTrcvWufFlag              (void);     \
              FUNC(Std_TypeReturn, CANIF_CODE) CheckTrcvWakeFlag             (void);     \
              FUNC(void,           CANIF_CODE) CheckBaudRate                 (void);     \
              FUNC(void,           CANIF_CODE) ChangeBaudRate                (void);     \
              FUNC(void,           CANIF_CODE) TxConfirmation                (void);     \
              FUNC(void,           CANIF_CODE) RxIndication                  (void);     \
              FUNC(void,           CANIF_CODE) CbMcalCancelTxConfirmation        (void);     \
              FUNC(void,           CANIF_CODE) CbControllerBusOff            (void);     \
              FUNC(void,           CANIF_CODE) CbConfirmPnAvailability       (void);     \
              FUNC(void,           CANIF_CODE) CbClearTrcvWufFlagIndication  (void);     \
              FUNC(void,           CANIF_CODE) CbCheckTrcvWakeFlagIndication (void);     \
              FUNC(void,           CANIF_CODE) CbControllerModeIndication    (void);     \
              FUNC(void,           CANIF_CODE) CbTrcvModeIndication          (void);     \

#define CANIF_CORE_FUNCTIONALITIES_VIRTUAL                                               \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) GetControllerMode             (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) SetControllerMode             (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) Transmit                      (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) McalCancelTransmit                (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) ReadRxPduData                 (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) ReadTxNotifStatus             (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) ReadRxNotifStatus             (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) GetPduMode                    (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) SetPduMode                    (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) SetDynamicTxId                (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) GetTrcvMode                   (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) SetTrcvMode                   (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) GetTrcvWakeupReason           (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) SetTrcvWakeupMode             (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) CheckWakeup                   (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) CheckValidation               (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) GetTxConfirmationState        (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) ClearTrcvWufFlag              (void) = 0; \
      virtual FUNC(Std_TypeReturn, CANIF_CODE) CheckTrcvWakeFlag             (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) CheckBaudRate                 (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) ChangeBaudRate                (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) TxConfirmation                (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) RxIndication                  (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) CbMcalCancelTxConfirmation        (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) CbControllerBusOff            (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) CbConfirmPnAvailability       (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) CbClearTrcvWufFlagIndication  (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) CbCheckTrcvWakeFlagIndication (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) CbControllerModeIndication    (void) = 0; \
      virtual FUNC(void,           CANIF_CODE) CbTrcvModeIndication          (void) = 0; \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_EcuabCanIf_Functionality{
   public:
      CANIF_CORE_FUNCTIONALITIES_VIRTUAL
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

