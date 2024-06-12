#pragma once
/******************************************************************************/
/* File   : CanIf_Cbk.hpp                                                     */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CanIf.hpp"
#include "CanIf_Cfg_SymbolicNames.hpp"

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
extern FUNC(void, CANIF_CODE) infEcuabCanIfMcalCan_vIndicationRx(
      P2CONST(Can_HwType,                   AUTOMATIC, CANIF_APPL_DATA) Mailbox
   ,  P2CONST(Type_SwcServiceCom_stInfoPdu, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);

extern FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication( VAR(uint8, AUTOMATIC) TransceiverId
   ,     VAR(CanTrcv_TrcvModeType, AUTOMATIC) TransceiverMode);
extern FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication( VAR(uint8, AUTOMATIC) TransceiverId);
extern FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication( VAR(uint8, AUTOMATIC) TransceiverId);
extern FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability( VAR(uint8, AUTOMATIC) TransceiverId);
extern FUNC(void, CANIF_CODE) CanIf_TxConfirmation(VAR(Type_SwcServiceCom_tIdPdu, AUTOMATIC) CanTxPduId );
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit(Type_SwcServiceCom_tIdPdu TxPduId, Type_SwcServiceCom_stInfoPdu* PduInfoPtr);
extern FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(VAR(uint8, AUTOMATIC) ControllerId );

extern FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication(
      VAR(uint8,                    AUTOMATIC) ControllerId
   ,  VAR(Type_EcuabCanIf_eModesController, AUTOMATIC) ControllerMode
);

extern FUNC(void, CANIF_CODE) CanIf_ControllerErrorPassive(VAR(uint8, AUTOMATIC) ControllerId);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

