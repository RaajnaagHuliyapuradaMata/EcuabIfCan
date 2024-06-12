/******************************************************************************/
/* File   : CanIf_PduMode.c                                                   */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "CanIf_Cfg.hpp"
#include "CfgEcuabCanIf.hpp"
#include "CanIf_Prv.hpp"

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
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(
      VAR(uint8,     AUTOMATIC) ControllerId
   ,  VAR(Type_EcuabCanIf_eModesPdu, AUTOMATIC) PduModeRequest
){
     VAR(Std_ReturnType,     AUTOMATIC) lRetVal_en         = E_NOT_OK;
   P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) lControllerState_p = CanIf_Lok_ControllerState_ast + ControllerId;

   if(
         lControllerState_p->DeviceMode
      != EcuabCanIf_eModeController_STARTED
   ){
      lRetVal_en = E_NOT_OK;
   }
   else{
      lControllerState_p->ChannelMode = PduModeRequest;
      lRetVal_en = E_OK;
   }
   return(lRetVal_en);
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode(
        VAR(uint8,     AUTOMATIC                 ) ControllerId
   ,  P2VAR(Type_EcuabCanIf_eModesPdu, AUTOMATIC, CANIF_APPL_DATA) PduModePtr
){
   P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) lControllerState_p = CanIf_Lok_ControllerState_ast + ControllerId;
   *PduModePtr = lControllerState_p->ChannelMode;
   return E_OK;
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.hpp"

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

