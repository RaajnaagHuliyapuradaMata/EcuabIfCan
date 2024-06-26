/******************************************************************************/
/* File   : EcuabCanIf_Rb_Apis.c                                              */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "EcuabCanIf_Prv.hpp"

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
FUNC(void, CANIF_CODE) CanIf_ControllerErrorPassive(
   VAR(uint8, AUTOMATIC) ControllerId
){
   UNUSED(ControllerId);
}

FUNC(void, CANIF_CODE) CanIf_ResetDynamicTxId(
   VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanTxPduId
){
   UNUSED(CanTxPduId);
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_Rn_ReadTxPduCanId(
        VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC                 ) CanIfTxPduId
   ,  P2VAR(uint32,                    AUTOMATIC, CANIF_APPL_DATA) TxPduCanId
){
       VAR(Std_ReturnType,            AUTOMATIC                 ) RetVal           = E_NOT_OK;
       VAR(uint32,                    AUTOMATIC                 ) lCanId_u32       = 0;
       VAR(uint16,                    AUTOMATIC                 ) ltxPduCustId_t   = CanIf_Lok_ConfigSet_tpst->TxPduIdTable_Ptr[CanIfTxPduId];
   P2CONST(CanIf_Cfg_TxPduConfig_tst, AUTOMATIC, CANIF_CFG_CONST) lTxPduConfig_pst = (CanIf_Lok_ConfigSet_tpst->CanIf_TxPduConfigPtr) + ltxPduCustId_t;
   if(0xFFFFFFFFu != lTxPduConfig_pst->TxPduCanId){
      lCanId_u32  = lTxPduConfig_pst->TxPduCanId;
      lCanId_u32 &= CANIF_MSB_BIT_RESET;
      lCanId_u32 |= ( ((Type_McalCan_tId)lTxPduConfig_pst->TxPduCanIdType) << CANIF_CANID_BIT_SHIFT );
      RetVal = E_OK;
   }
   if(RetVal == E_OK){
      *TxPduCanId  = lCanId_u32;
   }
   return RetVal;
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_Rn_ReadRxPduCanId(
        VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC                 ) CanIfRxPduId
   ,  P2VAR(uint32,                    AUTOMATIC, CANIF_APPL_DATA) RxPduCanId
){
       VAR(Std_ReturnType,          AUTOMATIC                 ) Status_t      = E_OK;
   P2CONST(CanIf_Cfg_RxPduType_tst, AUTOMATIC, CANIF_CFG_CONST) RxPduCfg_pcst = CanIf_Lok_ConfigSet_tpst->RxPduConfig_pcst + CanIf_Lok_ConfigSet_tpst->RxPduIdTable_Ptr[CanIfRxPduId];
   *RxPduCanId = (uint32)RxPduCfg_pcst->RxPduCanId;
   return Status_t;
}

FUNC(Std_ReturnType, CANIF_CODE)CanIf_ReturnTxPduId(
        VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC                  ) CanIfTxTargetPduId
   ,  P2VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC, CANIF_APPL_CONST) CanIfTxPduIdPtr
){
       VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC                 ) PduIdx_Temp;
       VAR(Std_ReturnType,            AUTOMATIC                 ) Ret_Val            = E_NOT_OK;
       VAR(uint16_least,              AUTOMATIC                 ) CanIf_TotalTxPduId = CanIf_Lok_ConfigSet_tpst->NumOfTxPdus;
   P2CONST(CanIf_Cfg_TxPduConfig_tst, AUTOMATIC, CANIF_CFG_CONST) lTxPduConfig_pst   = CanIf_Lok_ConfigSet_tpst->CanIf_TxPduConfigPtr;

   for(
      PduIdx_Temp = 0;
      PduIdx_Temp < CanIf_TotalTxPduId;
      PduIdx_Temp ++
   ){
      if(
            (CanIfTxTargetPduId == lTxPduConfig_pst[PduIdx_Temp].TxPduTargetPduId)
         && (USER               == lTxPduConfig_pst[PduIdx_Temp].TxPduTxUserUL)
      ){
         *CanIfTxPduIdPtr = lTxPduConfig_pst[PduIdx_Temp].TxPduId;
         Ret_Val = E_OK;
         break;
      }
   }
   return Ret_Val;
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReturnRxPduId(
        VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC           ) CanIfRxTargetPduId
   ,  P2VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC, AUTOMATIC) CanIfRxPduIdPtr
){
       VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC                 ) PduIdx_t;
       VAR(Std_ReturnType,            AUTOMATIC                 ) Status_t      = E_NOT_OK;
   P2CONST(CanIf_Cfg_RxPduType_tst,   AUTOMATIC, CANIF_CFG_CONST) RxPduCfg_pcst = CanIf_Lok_ConfigSet_tpst->RxPduConfig_pcst;

   for(
      PduIdx_t = 0;
      PduIdx_t < CanIf_Lok_ConfigSet_tpst->NumCanRxPduId_t;
      PduIdx_t ++
   ){
      if(
            (CanIfRxTargetPduId                             == RxPduCfg_pcst[PduIdx_t].RxPduTargetId_t)
         && (CanIf_Lok_ConfigSet_tpst->NumCddRxPdus_t + 7u)  < RxPduCfg_pcst[PduIdx_t].IndexForUL_u8
      ){
         *CanIfRxPduIdPtr = PduIdx_t;
         Status_t = E_OK;
         break;
      }
   }
    return Status_t;
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.hpp"

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

