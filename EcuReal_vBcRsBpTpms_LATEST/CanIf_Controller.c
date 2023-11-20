/******************************************************************************/
/* File   : CanIf_Controller.c                                                */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "CanIf_Prv.hpp"

#include "infMcalCanEcuabCanIf.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.hpp"
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode(
      VAR(uint8,                    AUTOMATIC) ControllerId
   ,  VAR(Type_EcuabCanIf_eModesController, AUTOMATIC) ControllerMode
){
        VAR(Type_McalCan_eStatesTransition, AUTOMATIC)                  lCanMode;
       VAR(uint8,                          AUTOMATIC                 ) lCtrlCustId_u8     = CanIf_Lok_ConfigSet_tpst->CtrlIdTable_Ptr[ControllerId];
      P2VAR(CanIf_ControllerStateType,     AUTOMATIC, AUTOMATIC      ) lControllerState_p = CanIf_Lok_ControllerState_ast + ControllerId;
   P2CONST(CanIf_Cfg_CtrlConfig_tst,       AUTOMATIC, CANIF_CFG_CONST) lCtrlConfig_pst    = (CanIf_Lok_ConfigSet_tpst->CanIf_CtrlConfigPtr) + lCtrlCustId_u8;
        VAR(Type_McalCan_eReturn,          AUTOMATIC)                  lCanStatus_en      = McalCan_eReturn_NOK;
        VAR(Std_ReturnType,                AUTOMATIC)                  lRetVal_en         = E_NOT_OK;

   switch(ControllerMode){
        case EcuabCanIf_eModeController_SLEEP:
            lCanStatus_en = infMcalCanEcuabCanIf_tSetModeController((uint8)(lCtrlConfig_pst->CtrlCanCtrlRef), McalCan_eStatesTransition_SLEEP);
            if(lCanStatus_en != McalCan_eReturn_NOK){
                lRetVal_en = E_OK;
                lControllerState_p->ChannelMode = EcuabCanIf_eModePdu_OFFLINE;
            }
            break;

        case EcuabCanIf_eModeController_STARTED:
           lCanStatus_en = infMcalCanEcuabCanIf_tSetModeController((uint8)(lCtrlConfig_pst->CtrlCanCtrlRef), McalCan_eStatesTransition_START);
           if(lCanStatus_en != McalCan_eReturn_NOK){
               lRetVal_en = E_OK;
            }
            break;

        case EcuabCanIf_eModeController_STOPPED:
            if(lControllerState_p->DeviceMode == EcuabCanIf_eModeController_SLEEP){
                lCanMode = McalCan_eStatesTransition_WAKEUP;
            }
            else{
                lCanMode = McalCan_eStatesTransition_STOP;
            }
            lCanStatus_en = infMcalCanEcuabCanIf_tSetModeController((uint8)(lCtrlConfig_pst->CtrlCanCtrlRef), lCanMode);
            if(lCanStatus_en != McalCan_eReturn_NOK){
                lRetVal_en = E_OK;
                lControllerState_p->ChannelMode = EcuabCanIf_eModePdu_TX_OFFLINE;
            }
            break;

        default:
            break;
   }
   return(lRetVal_en);
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(
        VAR(uint8,                    AUTOMATIC)                  ControllerId
   ,  P2VAR(Type_EcuabCanIf_eModesController, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr
){
   P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) lControllerState_p;
    lControllerState_p = CanIf_Lok_ControllerState_ast + ControllerId;
    *ControllerModePtr = lControllerState_p->DeviceMode;
    return E_OK;
}

FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(
   VAR(uint8, AUTOMATIC) ControllerId
){
   P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) lControllerState_p;
   P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) lCallBackPtr_p;
   lControllerState_p = CanIf_Lok_ControllerState_ast + ControllerId;
   lCallBackPtr_p = &CanIf_Callback;
   SchM_Enter_CanIf_ControllerState();
   if(lControllerState_p->DeviceMode != EcuabCanIf_eModeController_UNINIT){
        lControllerState_p->DeviceMode = EcuabCanIf_eModeController_STOPPED;
   }
   lControllerState_p->ChannelMode = EcuabCanIf_eModePdu_TX_OFFLINE;
   SchM_Exit_CanIf_ControllerState();
   if(lCallBackPtr_p->User_ControllerBusOff != NULL_PTR){
        lCallBackPtr_p->User_ControllerBusOff(ControllerId);
   }
}

FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication(
      VAR(uint8,                    AUTOMATIC) ControllerId
   ,  VAR(Type_EcuabCanIf_eModesController, AUTOMATIC) ControllerMode
){
     P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) lControllerState_p;
   P2CONST(CanIf_CallbackFuncType,    AUTOMATIC, AUTOMATIC) lCallBackPtr_p;
   lControllerState_p = CanIf_Lok_ControllerState_ast + ControllerId;
   lCallBackPtr_p =  &CanIf_Callback;
   if(ControllerMode != EcuabCanIf_eModeController_UNINIT){
        lControllerState_p->DeviceMode = ControllerMode;
   }
   if(lCallBackPtr_p->User_ControllerModeIndication != NULL_PTR){
      lCallBackPtr_p->User_ControllerModeIndication(ControllerId, ControllerMode);
   }
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.hpp"

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

