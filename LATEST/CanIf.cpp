/******************************************************************************/
/* File   : CanIf.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CanIf.hpp"
#include "infCanIf_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CANIF_AR_RELEASE_VERSION_MAJOR                                         4
#define CANIF_AR_RELEASE_VERSION_MINOR                                         3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CANIF_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible CANIF_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(CANIF_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible CANIF_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, CANIF_VAR, CANIF_CONST) gptrinfEcuMClient_CanIf = &CanIf;
CONSTP2VAR(infCanIf_PduR, CANIF_VAR, CANIF_CONST) gptrinfCanIf_PduR       = &CanIf;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_CanIf, CANIF_VAR) CanIf;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CANIF_CODE) module_CanIf::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, CANIF_CONFIG_DATA, CANIF_APPL_CONST) lptrCfgModule
){
#if(STD_ON == CanIf_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         lptrCfg = lptrCfgModule;
      }
      else{
#if(STD_ON == CanIf_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == CanIf_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == CanIf_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CANIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CANIF_CODE) module_CanIf::DeInitFunction(
   void
){
#if(STD_ON == CanIf_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == CanIf_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == CanIf_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CANIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CANIF_CODE) module_CanIf::MainFunction(
   void
){
#if(STD_ON == CanIf_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif

#if(STD_ON == _ReSIM)
      RxIndication();
#else
#endif

#if(STD_ON == CanIf_InitCheck)
   }
   else{
#if(STD_ON == CanIf_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CANIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::GetControllerMode(
//      uint8                IdController
//   ,  TypeStateController* ptrModeController
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::SetControllerMode(
//      uint8               IdController
//   ,  TypeStateController ModeController
   void
){
   return E_OK;
}

/*
FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::GetControllerErrorState(
      uint8           IdController
   ,  TypeStateError* ptrStateError
   void
){
   return E_OK;
}
TBD: and many more!
*/

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::GetPduMode(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::SetPduMode(
   void
){
   return E_OK;
}

FUNC(void, CANIF_CODE) module_CanIf::SetDynamicTxId(
   void
){
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::GetTrcvMode(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::SetTrcvMode(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::GetTrcvWakeupReason(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::SetTrcvWakeupMode(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::CheckWakeup(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::CheckValidation(
   void
){
   return E_OK;
}

FUNC(void, CANIF_CODE) module_CanIf::GetTxConfirmationState(
   void
){
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::ClearTrcvWufFlag(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::CheckTrcvWakeFlag(
   void
){
   return E_OK;
}

//SetBaudRate

FUNC(void, CANIF_CODE) module_CanIf::CheckBaudRate(
   void
){
}

FUNC(void, CANIF_CODE) module_CanIf::ChangeBaudRate(
   void
){
}

FUNC(void, CANIF_CODE) module_CanIf::CbControllerBusOff(
   void
){
}

FUNC(void, CANIF_CODE) module_CanIf::CbConfirmPnAvailability(
   void
){
}

FUNC(void, CANIF_CODE) module_CanIf::CbClearTrcvWufFlagIndication(
   void
){
}

FUNC(void, CANIF_CODE) module_CanIf::CbCheckTrcvWakeFlagIndication(
   void
){
}

FUNC(void, CANIF_CODE) module_CanIf::CbControllerModeIndication(
   void
){
}

FUNC(void, CANIF_CODE) module_CanIf::CbTrcvModeIndication(
   void
){
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::Transmit(
//            TypeIdPdu IdPduTx
//   ,  const TypeInfoPdu* ptrInfoPdu
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::CancelTransmit(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, CANIF_CODE) module_CanIf::ReadRxPduData(
   void
){
   return E_OK;
}

FUNC(void, CANIF_CODE) module_CanIf::ReadTxNotifStatus(
   void
){
}

FUNC(void, CANIF_CODE) module_CanIf::ReadRxNotifStatus(
   void
){
}

FUNC(void, CANIF_CODE) module_CanIf::TxConfirmation(
   void
){
}

FUNC(void, CANIF_CODE) module_CanIf::RxIndication(
   void
){
#if(STD_ON == _ReSIM)
   infPduRClient_CanIf.RxIndication(
         0
      ,  0
   );
#else
#endif
}

FUNC(void, CANIF_CODE) module_CanIf::CbCancelTxConfirmation(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

