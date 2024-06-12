/******************************************************************************/
/* File   : CanIf_Prv.c                                                       */
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
#define CANIF_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.hpp"
VAR(boolean, CANIF_VAR) CanIf_Lok_InitStatus_b;
#define CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.hpp"

#if(CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.hpp"
VAR(Type_EcuabCanIf_eStatusNotification, CANIF_VAR) CanIf_Lok_RxNotification_taen[CANIF_CFG_NUM_CANRXPDUIDS];
#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.hpp"
#endif

#define CANIF_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.hpp"
P2CONST(Type_CfgEcuabCanIf_st, AUTOMATIC, AUTOMATIC) CanIf_Lok_ConfigSet_tpst;
#define CANIF_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.hpp"

#define CANIF_START_SEC_VAR_FAST_CLEARED_8
#include "CanIf_MemMap.hpp"
VAR(uint8, AUTOMATIC) CanIf_ActiveCfgSet;
#define CANIF_STOP_SEC_VAR_FAST_CLEARED_8
#include "CanIf_MemMap.hpp"

VAR(CanIf_ControllerStateType, CANIF_VAR) CanIf_Lok_ControllerState_ast[CANIF_TOTAL_CTRLS];

#if(CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)
VAR(Type_EcuabCanIf_eStatusNotification, CANIF_VAR) CanIf_Lok_TxNotification_aen[CANIF_TOTAL_TXPDUS];
#endif

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

