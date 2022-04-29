/******************************************************************************/
/* File   : CanIf.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgCanIf.hpp"
#include "CanIf_core.hpp"
#include "infCanIf.hpp"

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
class module_CanIf:
      public abstract_module
   ,  public class_CanIf_Functionality
{
   public:
      module_CanIf(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, CANIF_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, CANIF_CONFIG_DATA, CANIF_APPL_CONST) lptrCfgModule
      );
      FUNC(void, CANIF_CODE) DeInitFunction (void);
      FUNC(void, CANIF_CODE) MainFunction   (void);
      CANIF_CORE_FUNCTIONALITIES
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

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_CanIf, CANIF_VAR) CanIf(
   {
         CANIF_AR_RELEASE_VERSION_MAJOR
      ,  CANIF_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
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
#if(STD_ON == CanIf_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == CanIf_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == CanIf_DevErrorDetect)
         Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
            lptrCfg = &PBcfgCanIf;
         }
      }
      IsInitDone = E_OK;
#if(STD_ON == CanIf_InitCheck)
   }
#endif
}

FUNC(void, CANIF_CODE) module_CanIf::DeInitFunction(void){
#if(STD_ON == CanIf_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == CanIf_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == CanIf_InitCheck)
   }
#endif
}

FUNC(void, CANIF_CODE) module_CanIf::MainFunction(void){
#if(STD_ON == CanIf_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == CanIf_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
#if(STD_ON == CanIf_InitCheck)
   }
#endif
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::GetControllerMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::SetControllerMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::Transmit(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CancelTransmit(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::ReadRxPduData(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::ReadTxNotifStatus(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::ReadRxNotifStatus(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::GetPduMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::SetPduMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::SetDynamicTxId(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::GetTrcvMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::SetTrcvMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::GetTrcvWakeupReason(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::SetTrcvWakeupMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CheckWakeup(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CheckValidation(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::GetTxConfirmationState(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::ClearTrcvWufFlag(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CheckTrcvWakeFlag(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CheckBaudRate(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::ChangeBaudRate(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CbTxConfirmation(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CbRxIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CbCancelTxConfirmation(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CbControllerBusOff(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CbConfirmPnAvailability(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CbClearTrcvWufFlagIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CbCheckTrcvWakeFlagIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CbControllerModeIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf_Functionality::CbTrcvModeIndication(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

