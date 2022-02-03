/*****************************************************/
/* File   : CanIf.cpp                                */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "CanIf.h"

#include "CanIf_EcuM.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
class_CanIf CanIf;
class_CanIf_EcuM CanIf_EcuM;
class_EcuM_Client *EcuM_Client_ptr_CanIf = &CanIf_EcuM;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, CANIF_CODE) class_CanIf_EcuM::InitFunction(void){
}

FUNC(void, CANIF_CODE) class_CanIf::GetControllerMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf::SetControllerMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf::Transmit(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CancelTransmit(void){
}

FUNC(void, CANIF_CODE) class_CanIf::ReadRxPduData(void){
}

FUNC(void, CANIF_CODE) class_CanIf::ReadTxNotifStatus(void){
}

FUNC(void, CANIF_CODE) class_CanIf::ReadRxNotifStatus(void){
}

FUNC(void, CANIF_CODE) class_CanIf::GetPduMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf::SetPduMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf::GetVersionInfo(void){
}

FUNC(void, CANIF_CODE) class_CanIf::SetDynamicTxId(void){
}

FUNC(void, CANIF_CODE) class_CanIf::GetTrcvMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf::SetTrcvMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf::GetTrcvWakeupReason(void){
}

FUNC(void, CANIF_CODE) class_CanIf::SetTrcvWakeupMode(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CheckWakeup(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CheckValidation(void){
}

FUNC(void, CANIF_CODE) class_CanIf::GetTxConfirmationState(void){
}

FUNC(void, CANIF_CODE) class_CanIf::ClearTrcvWufFlag(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CheckTrcvWakeFlag(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CheckBaudRate(void){
}

FUNC(void, CANIF_CODE) class_CanIf::ChangeBaudRate(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CbTxConfirmation(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CbRxIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CbCancelTxConfirmation(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CbControllerBusOff(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CbConfirmPnAvailability(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CbClearTrcvWufFlagIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CbCheckTrcvWakeFlagIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CbControllerModeIndication(void){
}

FUNC(void, CANIF_CODE) class_CanIf::CbTrcvModeIndication(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

