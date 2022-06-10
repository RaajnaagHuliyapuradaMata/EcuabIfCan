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
#include "infCanIf_Exp.hpp"
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
class module_CanIf:
      INTERFACES_EXPORTED_CANIF
      public abstract_module
   ,  public class_CanIf_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
            Std_TypeReturn          IsInitDone{E_NOT_OK};
      const CfgModule_TypeAbstract* lptrCfg{(CfgModule_TypeAbstract*)NULL_PTR};
            infPduRClient_Lo        infPduRClient_CanIf;

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
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         if(STD_HIGH){
            lptrCfg = lptrCfgModule;
         }
         else{
            lptrCfg = &PBcfgCanIf;
         }
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

FUNC(void, CANIF_CODE) module_CanIf::DeInitFunction(void){
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

FUNC(void, CANIF_CODE) module_CanIf::MainFunction(void){
#if(STD_ON == CanIf_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
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

FUNC(void, CANIF_CODE) module_CanIf::GetControllerMode(void){
}

FUNC(void, CANIF_CODE) module_CanIf::SetControllerMode(void){
}

FUNC(void, CANIF_CODE) module_CanIf::Transmit(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CancelTransmit(void){
}

FUNC(void, CANIF_CODE) module_CanIf::ReadRxPduData(void){
}

FUNC(void, CANIF_CODE) module_CanIf::ReadTxNotifStatus(void){
}

FUNC(void, CANIF_CODE) module_CanIf::ReadRxNotifStatus(void){
}

FUNC(void, CANIF_CODE) module_CanIf::GetPduMode(void){
}

FUNC(void, CANIF_CODE) module_CanIf::SetPduMode(void){
}

FUNC(void, CANIF_CODE) module_CanIf::SetDynamicTxId(void){
}

FUNC(void, CANIF_CODE) module_CanIf::GetTrcvMode(void){
}

FUNC(void, CANIF_CODE) module_CanIf::SetTrcvMode(void){
}

FUNC(void, CANIF_CODE) module_CanIf::GetTrcvWakeupReason(void){
}

FUNC(void, CANIF_CODE) module_CanIf::SetTrcvWakeupMode(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CheckWakeup(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CheckValidation(void){
}

FUNC(void, CANIF_CODE) module_CanIf::GetTxConfirmationState(void){
}

FUNC(void, CANIF_CODE) module_CanIf::ClearTrcvWufFlag(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CheckTrcvWakeFlag(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CheckBaudRate(void){
}

FUNC(void, CANIF_CODE) module_CanIf::ChangeBaudRate(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CbTxConfirmation(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CbRxIndication(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CbCancelTxConfirmation(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CbControllerBusOff(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CbConfirmPnAvailability(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CbClearTrcvWufFlagIndication(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CbCheckTrcvWakeFlagIndication(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CbControllerModeIndication(void){
}

FUNC(void, CANIF_CODE) module_CanIf::CbTrcvModeIndication(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

