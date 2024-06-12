/******************************************************************************/
/* File   : CanIf_Init.c                                                      */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

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
FUNC(void, CANIF_CODE) CanIf_Init(
   P2CONST(Type_CfgEcuabCanIf_st, AUTOMATIC, CANIF_APPL_CONST) ConfigPtr
){
   P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) controllerState_pst;
    VAR(uint32, AUTOMATIC) index_u32;

#if( (CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON) || (CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API == STD_ON) || \
      (CANIF_PUBLIC_READRXPDU_DATA_API   == STD_ON) || (CANIF_RB_NODE_CALIBRATION                == STD_ON) )
   VAR(uint8_least, AUTOMATIC)pdu_uo;
#endif

   VAR (uint8, AUTOMATIC) numControllers_u8;
   CanIf_Lok_ConfigSet_tpst = &CfgEcuabCanIf_st;
   (void) ConfigPtr;

    numControllers_u8 = CanIf_Lok_ConfigSet_tpst->NumCanCtrl_u8;
   controllerState_pst = CanIf_Lok_ControllerState_ast;

#if(CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)
   for(pdu_uo = 0; pdu_uo < CanIf_Lok_ConfigSet_tpst->NumOfTxPdus; pdu_uo++){
        CanIf_Lok_TxNotification_aen[pdu_uo] = EcuabCanIf_eStatusNotification_NONE;
   }
#endif

   for(index_u32 = 0; index_u32 < numControllers_u8; index_u32++){
        (controllerState_pst + index_u32)->DeviceMode = EcuabCanIf_eModeController_STOPPED;
        (controllerState_pst + index_u32)->ChannelMode = EcuabCanIf_eModePdu_OFFLINE;
   }

#if(CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
   for(pdu_uo=CANIF_ZERO; pdu_uo < CanIf_Lok_ConfigSet_tpst->NumCanRxPduId_t; pdu_uo++){
        CanIf_Lok_RxNotification_taen[pdu_uo] = EcuabCanIf_eStatusNotification_NONE;
   }
#endif
   CanIf_Lok_InitStatus_b = TRUE;
}

FUNC(void, CANIF_CODE) CanIf_DeInit(P2CONST (Type_CfgEcuabCanIf_st, AUTOMATIC, CANIF_APPL_CONST) ConfigPtr){
    (void)ConfigPtr;
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.hpp"

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

