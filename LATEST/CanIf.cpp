/******************************************************************************/
/* File   : CanIf.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
#include "CfgCanIf.h"
#include "infCanIf_EcuM.h"
#include "infCanIf_Dcm.h"
#include "infCanIf_SchM.h"

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
      FUNC(void, CANIF_CODE) InitFunction   (void);
      FUNC(void, CANIF_CODE) DeInitFunction (void);
      FUNC(void, CANIF_CODE) GetVersionInfo (void);
      FUNC(void, CANIF_CODE) MainFunction   (void);

   private:
      CONST(Std_TypeVersionInfo, CANIF_CONST) VersionInfo = {
            0x0000
         ,  0xFFFF
         ,  0x01
         ,  '0'
         ,  '1'
         ,  '0'
      };
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
VAR(module_CanIf, CANIF_VAR) CanIf;
CONSTP2VAR(infEcuMClient, CANIF_VAR, CANIF_CONST) gptrinfEcuMClient_CanIf = &CanIf;
CONSTP2VAR(infDcmClient,  CANIF_VAR, CANIF_CONST) gptrinfDcmClient_CanIf  = &CanIf;
CONSTP2VAR(infSchMClient, CANIF_VAR, CANIF_CONST) gptrinfSchMClient_CanIf = &CanIf;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CANIF_CODE) module_CanIf::InitFunction(void){
   CanIf.IsInitDone = E_OK;
}

FUNC(void, CANIF_CODE) module_CanIf::DeInitFunction(void){
   CanIf.IsInitDone = E_NOT_OK;
}

FUNC(void, CANIF_CODE) module_CanIf::GetVersionInfo(void){
#if(STD_ON == CanIf_DevErrorDetect)
//TBD: API parameter check
   Det_ReportError(
   );
#endif
}

FUNC(void, CANIF_CODE) module_CanIf::MainFunction(void){
}

#include "CanIf_Unused.h"

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

