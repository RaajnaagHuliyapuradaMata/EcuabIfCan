/******************************************************************************/
/* File   : CanIf_ReadNotifStatus.c                                           */
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
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
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
FUNC(Type_EcuabCanIf_eStatusNotification, CANIF_CODE) CanIf_ReadTxNotifStatus(
   VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanIfTxSduId
){
       VAR(uint16,                              AUTOMATIC                 ) ltxPduCustId_t   = CanIf_Lok_ConfigSet_tpst->TxPduIdTable_Ptr[CanIfTxSduId];
   P2CONST(CanIf_Cfg_TxPduConfig_tst,           AUTOMATIC, CANIF_CFG_CONST) lTxPduConfig_pst = CanIf_Lok_ConfigSet_tpst->CanIf_TxPduConfigPtr + ltxPduCustId_t;
     P2VAR(Type_EcuabCanIf_eStatusNotification, AUTOMATIC, AUTOMATIC      ) lTxNotifPtr      = (CanIf_Lok_TxNotification_aen + ltxPduCustId_t);
       VAR(Type_EcuabCanIf_eStatusNotification, AUTOMATIC                 ) NotifStatus      = EcuabCanIf_eStatusNotification_NONE;
   if(
         FALSE
      != lTxPduConfig_pst->TxPduReadNotifyStatus
   ){
      SchM_Enter_CanIf_TxRxNotifNoNest();
      NotifStatus    = (Type_EcuabCanIf_eStatusNotification)(*lTxNotifPtr);
      *(lTxNotifPtr) = EcuabCanIf_eStatusNotification_NONE;
      SchM_Exit_CanIf_TxRxNotifNoNest();
   }
   return NotifStatus;
}

FUNC(Type_EcuabCanIf_eStatusNotification, CANIF_CODE) CanIf_ReadRxNotifStatus(
   VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanIfRxSduId
){
   P2CONST(CanIf_Cfg_RxPduType_tst, AUTOMATIC, CANIF_CFG_CONST) RxPduCfg_pcst     = CanIf_Lok_ConfigSet_tpst->RxPduConfig_pcst + CanIf_Lok_ConfigSet_tpst->RxPduIdTable_Ptr[CanIfRxSduId];
   P2VAR(Type_EcuabCanIf_eStatusNotification,     AUTOMATIC, AUTOMATIC      ) RxNotifStatus_pen = CanIf_Lok_RxNotification_taen;
   VAR(Type_EcuabCanIf_eStatusNotification,       AUTOMATIC                 ) NotifStatus_ten   = EcuabCanIf_eStatusNotification_NONE;
   if(
         (RxPduCfg_pcst->RxPduReadNotifyReadDataStatus_u8 == CANIF_READ_NOTIFSTATUS_DATA)
      || (RxPduCfg_pcst->RxPduReadNotifyReadDataStatus_u8 == CANIF_READ_NOTIFSTATUS)
   ){
      SchM_Enter_CanIf_TxRxNotifNoNest();
      NotifStatus_ten = *(RxNotifStatus_pen + CanIfRxSduId);
      *(RxNotifStatus_pen + CanIfRxSduId) = EcuabCanIf_eStatusNotification_NONE;
      SchM_Exit_CanIf_TxRxNotifNoNest();
   }
   return NotifStatus_ten;
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.hpp"

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

