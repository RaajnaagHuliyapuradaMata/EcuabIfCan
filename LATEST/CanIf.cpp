/******************************************************************************/
/* File   : CanIf.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infCanIf_EcuM.hpp"
#include "infCanIf_Dcm.hpp"
#include "infCanIf_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CANIF_AR_RELEASE_MAJOR_VERSION                                         4
#define CANIF_AR_RELEASE_MINOR_VERSION                                         3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CANIF_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible CANIF_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(CANIF_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible CANIF_AR_RELEASE_MINOR_VERSION!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_CanIf:
      public abstract_module
{
   public:
      module_CanIf(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }

      FUNC(void, CANIF_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, CANIF_CONFIG_DATA, CANIF_APPL_CONST) lptrCfgModule
      );

      FUNC(void, CANIF_CODE) DeInitFunction (void);
      FUNC(void, CANIF_CODE) MainFunction   (void);
};

extern VAR(module_CanIf, CANIF_VAR) CanIf;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, CANIF_VAR, CANIF_CONST) gptrinfEcuMClient_CanIf = &CanIf;
CONSTP2VAR(infDcmClient,  CANIF_VAR, CANIF_CONST) gptrinfDcmClient_CanIf  = &CanIf;
CONSTP2VAR(infSchMClient, CANIF_VAR, CANIF_CONST) gptrinfSchMClient_CanIf = &CanIf;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
#include "CfgCanIf.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_CanIf, CANIF_VAR) CanIf(
   {
         0x0000
      ,  0xFFFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CANIF_CODE) module_CanIf::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, CANIF_CONFIG_DATA, CANIF_APPL_CONST) lptrCfgModule
){
   if(NULL_PTR == lptrCfgModule){
#if(STD_ON == CanIf_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
// check lptrCfgCanIf for memory faults
// use PBcfg_CanIf as back-up configuration
   }
   IsInitDone = E_OK;
}

FUNC(void, CANIF_CODE) module_CanIf::DeInitFunction(void){
   CanIf.IsInitDone = E_NOT_OK;
}

FUNC(void, CANIF_CODE) module_CanIf::MainFunction(void){
}

class class_CanIf_Unused{
   public:
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

FUNC(void, CANIF_CODE) class_CanIf_Unused::GetControllerMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::SetControllerMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::Transmit(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CancelTransmit(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::ReadRxPduData(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::ReadTxNotifStatus(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::ReadRxNotifStatus(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::GetPduMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::SetPduMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::SetDynamicTxId(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::GetTrcvMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::SetTrcvMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::GetTrcvWakeupReason(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::SetTrcvWakeupMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CheckWakeup(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CheckValidation(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::GetTxConfirmationState(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::ClearTrcvWufFlag(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CheckTrcvWakeFlag(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CheckBaudRate(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::ChangeBaudRate(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CbTxConfirmation(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CbRxIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CbCancelTxConfirmation(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CbControllerBusOff(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CbConfirmPnAvailability(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CbClearTrcvWufFlagIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CbCheckTrcvWakeFlagIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CbControllerModeIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Unused::CbTrcvModeIndication(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

