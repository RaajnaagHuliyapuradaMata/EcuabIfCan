/******************************************************************************/
/* File   : CanIf_Transmit.c                                                  */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "CfgEcuabCanIf.hpp"
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
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(
          VAR(Type_SwcServiceCom_tIdPdu,    AUTOMATIC                  ) CanIfTxSduId
   ,  P2CONST(Type_SwcServiceCom_stInfoPdu, AUTOMATIC, CANIF_APPL_CONST) CanIfTxInfoPtr
){
       VAR(Std_ReturnType,            AUTOMATIC                 ) lRetVal_en       = E_OK;
       VAR(uint16,                    AUTOMATIC                 ) ltxPduCustId_t   = CanIf_Lok_ConfigSet_tpst->TxPduIdTable_Ptr[CanIfTxSduId];
   P2CONST(CanIf_Cfg_TxPduConfig_tst, AUTOMATIC, CANIF_CFG_CONST) lTxPduConfig_pst = (CanIf_Lok_ConfigSet_tpst->CanIf_TxPduConfigPtr) + ltxPduCustId_t;

   if(
         (
               lTxPduConfig_pst->TxTruncEnabled_b
            == FALSE
         )
      && (
               CanIfTxInfoPtr->SduLength
            >  lTxPduConfig_pst->TxPduLength_u8
         )
   ){
      lRetVal_en = E_NOT_OK;
   }
   else{
      lRetVal_en = CanIf_XCore_LocalCore_Transmit(
            CanIfTxSduId
         ,  CanIfTxInfoPtr
      );
   }
   return lRetVal_en;
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_XCore_LocalCore_Transmit(
          VAR(Type_SwcServiceCom_tIdPdu,    AUTOMATIC                  ) CanIfTxSduId
   ,  P2CONST(Type_SwcServiceCom_stInfoPdu, AUTOMATIC, CANIF_APPL_CONST) CanIfTxInfoPtr
){
       VAR(Type_EcuabCanIf_eModesController, AUTOMATIC                 ) lDeviceMode_en;
       VAR(Type_EcuabCanIf_eModesPdu,        AUTOMATIC                 ) lChannelMode_en;
       VAR(Type_McalCan_stPdu,               AUTOMATIC                 ) lPduInfo_st         = {NULL_PTR, 0, 0, 0};
       VAR(Type_McalCan_eReturn,             AUTOMATIC                 ) lCanStatus_en       = McalCan_eReturn_NOK;
       VAR(Type_SwcServiceCom_tLengthPdu,    AUTOMATIC                 ) lSduLength          = 0;
       VAR(uint32,                           AUTOMATIC                 ) lCanId_u32          = 0;
       VAR(uint16,                           AUTOMATIC                 ) ltxPduCustId_t      = CanIf_Lok_ConfigSet_tpst->TxPduIdTable_Ptr[CanIfTxSduId];
   P2CONST(CanIf_Cfg_TxPduConfig_tst,        AUTOMATIC, CANIF_CFG_CONST) lTxPduConfig_pst    = (CanIf_Lok_ConfigSet_tpst->CanIf_TxPduConfigPtr) + ltxPduCustId_t;
       VAR(Type_McalCan_tHandleHw,           AUTOMATIC                 ) lHth_uo             = lTxPduConfig_pst->CanIf_TxBufferConfigPtr->CanIf_HthConfigPtr->CanObjectId;
       VAR(uint8,                            AUTOMATIC                 ) lControllerId_u8    = lTxPduConfig_pst->CanIf_TxBufferConfigPtr->CanIf_HthConfigPtr->CanIf_CtrlConfigPtr->CtrlId;
     P2VAR(CanIf_ControllerStateType,        AUTOMATIC, AUTOMATIC      ) lControllerState_en = CanIf_Lok_ControllerState_ast + lControllerId_u8;
       VAR(Std_ReturnType,                   AUTOMATIC                 ) lRetVal_en          = E_NOT_OK;

   SchM_Enter_CanIf_ControllerState();
   lDeviceMode_en  = lControllerState_en->DeviceMode;
   lChannelMode_en = lControllerState_en->ChannelMode;
   SchM_Exit_CanIf_ControllerState();

   if(
         (lDeviceMode_en  == EcuabCanIf_eModeController_STARTED)
      && (lChannelMode_en == EcuabCanIf_eModePdu_ONLINE)
   ){
      if(
            lTxPduConfig_pst->TxPduCanId
         != 0xFFFFFFFFu
      ){
         lCanId_u32 = lTxPduConfig_pst->TxPduCanId;
      }
      else{
      }
      if(
            CanIfTxInfoPtr->SduLength
         >  lTxPduConfig_pst->TxPduLength_u8
      ){
         lSduLength = lTxPduConfig_pst->TxPduLength_u8;
      }
      else{
         lSduLength = CanIfTxInfoPtr->SduLength;
      }
      lPduInfo_st.id  = (Type_McalCan_tId)lCanId_u32;
      lPduInfo_st.id &= CANIF_MSB_BIT_RESET;
      lPduInfo_st.id |= (
            (Type_McalCan_tId)lTxPduConfig_pst->TxPduCanIdType
         << CANIF_CANID_BIT_SHIFT
      );
      lPduInfo_st.swPduHandle = lTxPduConfig_pst->TxPduId;
      lPduInfo_st.sdu         = CanIfTxInfoPtr->SduDataPtr;
      lPduInfo_st.length      = (uint8)lSduLength;
      lCanStatus_en = infMcalCanEcuabCanIf_tWrite(
            lHth_uo
         ,  &lPduInfo_st
      );

           if(lCanStatus_en == McalCan_eReturn_OK)  {lRetVal_en = E_OK;}
      else if(lCanStatus_en == McalCan_eReturn_BUSY){lRetVal_en = E_NOT_OK;}
      else                              {lRetVal_en = E_NOT_OK;}
   }
   else{
   }
   return lRetVal_en;
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.hpp"

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

