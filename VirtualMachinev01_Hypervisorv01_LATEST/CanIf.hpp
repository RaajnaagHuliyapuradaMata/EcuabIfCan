#pragma once
/******************************************************************************/
/* File   : CanIf.hpp                                                         */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Types_EcuabCanIf.hpp"

#include "CanIf_Cfg.hpp"

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
extern FUNC(void, CANIF_CODE) CanIf_Init(P2CONST (Type_CfgEcuabCanIf_st, AUTOMATIC, CANIF_APPL_CONST) ConfigPtr);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode(VAR (uint8, AUTOMATIC) ControllerId
   ,     VAR(Type_EcuabCanIf_eModesController, AUTOMATIC) ControllerMode);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(VAR(uint8, AUTOMATIC) ControllerId
   ,     P2VAR(Type_EcuabCanIf_eModesController, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanIfTxSduId
   ,     P2CONST(Type_SwcServiceCom_stInfoPdu, AUTOMATIC, CANIF_APPL_CONST) CanIfTxInfoPtr);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(VAR(uint8, AUTOMATIC) ControllerId
   ,     VAR(Type_EcuabCanIf_eModesPdu, AUTOMATIC) PduModeRequest);
extern FUNC(void, CANIF_CODE) CanIf_DeInit(P2CONST (Type_CfgEcuabCanIf_st, AUTOMATIC, CANIF_APPL_CONST) ConfigPtr);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode(
                                                         VAR(uint8, AUTOMATIC) ControllerId
   ,     P2VAR(Type_EcuabCanIf_eModesPdu, AUTOMATIC,CANIF_APPL_DATA) PduModePtr
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData(VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanIfRxSduId
   ,     P2VAR(Type_SwcServiceCom_stInfoPdu, AUTOMATIC, CANIF_APPL_CONST)CanIfRxInfoPtr);

extern FUNC(Type_EcuabCanIf_eStatusNotification, CANIF_CODE) CanIf_ReadTxNotifStatus(
                                                                      VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanIfTxSduId
);

extern FUNC(Type_EcuabCanIf_eStatusNotification, CANIF_CODE) CanIf_ReadRxNotifStatus(VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanIfRxSduId);

extern FUNC(void, CANIF_CODE) CanIf_GetVersionInfo (P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_DATA) VersionInfo);

extern FUNC(void, CANIF_CODE) CanIf_ResetDynamicTxId(VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanTxPduId);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode(
                                            P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA) TransceiverModePtr
   ,     VAR(uint8, AUTOMATIC) TransceiverId
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReturnRxPduId(
                                                     VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanIfRxTargetPduId
   ,     P2VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC, CANIF_APPL_CONST) CanIfRxPduIdPtr
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReturnTxPduId(
                                                     VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanIfTxTargetPduId
   ,     P2VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC, CANIF_APPL_CONST) CanIfTxPduIdPtr
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Rn_ReadTxPduCanId(
                                                    VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanIfTxPduId
   ,     P2VAR(uint32, AUTOMATIC, AUTOMATIC) TxPduCanId);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Rn_ReadRxPduCanId( VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC)CanIfRxPduId
   ,     P2VAR(uint32, AUTOMATIC, CANIF_APPL_DATA)RxPduCanId);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

