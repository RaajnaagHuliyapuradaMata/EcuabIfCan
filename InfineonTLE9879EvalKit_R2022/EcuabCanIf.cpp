/******************************************************************************/
/* File   : EcuabCanIf.cpp                                                    */
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
#include "Module.hpp"
#include "EcuabCanIf.hpp"
#include "infEcuabCanIf_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ECUABCANIF_AR_RELEASE_VERSION_MAJOR                                    4
#define ECUABCANIF_AR_RELEASE_VERSION_MINOR                                    3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(ECUABCANIF_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible ECUABCANIF_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(ECUABCANIF_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible ECUABCANIF_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_EcuabCanIf, ECUABCANIF_VAR) EcuabCanIf;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, ECUABCANIF_CONST,       ECUABCANIF_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   ECUABCANIF_CONFIG_DATA, ECUABCANIF_APPL_CONST) lptrCfgModule
){
#if(STD_ON == EcuabCanIf_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstEcuabCanIf_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == EcuabCanIf_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == EcuabCanIf_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == EcuabCanIf_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ECUABCANIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::DeInitFunction(
   void
){
#if(STD_ON == EcuabCanIf_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == EcuabCanIf_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == EcuabCanIf_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ECUABCANIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::MainFunction(
   void
){
#if(STD_ON == EcuabCanIf_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif

#if(STD_ON == _ReSIM)
      RxIndication();
#else
#endif

#if(STD_ON == EcuabCanIf_InitCheck)
   }
   else{
#if(STD_ON == EcuabCanIf_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  ECUABCANIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::GetControllerMode(
//      uint8                IdController
//   ,  TypeStateController* ptrModeController
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::SetControllerMode(
//      uint8               IdController
//   ,  TypeStateController ModeController
   void
){
   return E_OK;
}

/*
FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::GetControllerErrorState(
      uint8           IdController
   ,  TypeStateError* ptrStateError
   void
){
   return E_OK;
}
TBD: and many more!
*/

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::GetPduMode(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::SetPduMode(
   void
){
   return E_OK;
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::SetDynamicTxId(
   void
){
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::GetTrcvMode(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::SetTrcvMode(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::GetTrcvWakeupReason(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::SetTrcvWakeupMode(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::CheckWakeup(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::CheckValidation(
   void
){
   return E_OK;
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::GetTxConfirmationState(
   void
){
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::ClearTrcvWufFlag(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::CheckTrcvWakeFlag(
   void
){
   return E_OK;
}

//SetBaudRate

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::CheckBaudRate(
   void
){
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::ChangeBaudRate(
   void
){
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::CbControllerBusOff(
   void
){
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::CbConfirmPnAvailability(
   void
){
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::CbClearTrcvWufFlagIndication(
   void
){
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::CbCheckTrcvWakeFlagIndication(
   void
){
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::CbControllerModeIndication(
   void
){
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::CbTrcvModeIndication(
   void
){
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::Transmit(
//            TypeIdPdu IdPduTx
//   ,  const TypeInfoPdu* ptrInfoPdu
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::McalCancelTransmit(
   void
){
   return E_OK;
}

FUNC(Std_TypeReturn, ECUABCANIF_CODE) module_EcuabCanIf::ReadRxPduData(
   void
){
   return E_OK;
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::ReadTxNotifStatus(
   void
){
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::ReadRxNotifStatus(
   void
){
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::TxConfirmation(
   void
){
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::RxIndication(
   void
){
#if(STD_ON == _ReSIM)
   infServicePduRClient_EcuabCanIf.RxIndication(
         0
      ,  0
   );
#else
#endif
}

FUNC(void, ECUABCANIF_CODE) module_EcuabCanIf::CbCancelTxConfirmation(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

