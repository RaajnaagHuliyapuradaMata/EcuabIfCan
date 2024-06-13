#pragma once
/******************************************************************************/
/* File   : Types_EcuabCanIf.hpp                                              */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "ComStack_Types.hpp"
#include "Can_GeneralTypes.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      EcuabCanIf_eModePdu_OFFLINE
   ,  EcuabCanIf_eModePdu_TX_OFFLINE
   ,  EcuabCanIf_eModePdu_TX_OFFLINE_ACTIVE
   ,  EcuabCanIf_eModePdu_ONLINE
   ,  EcuabCanIf_eModePdu_TX_TP_ONLINE
   ,  EcuabCanIf_eModePdu_TX_USER_TP_ONLINE
}Type_EcuabCanIf_eModesPdu;

typedef enum{
      EcuabCanIf_eModeController_UNINIT
   ,  EcuabCanIf_eModeController_SLEEP
   ,  EcuabCanIf_eModeController_STARTED
   ,  EcuabCanIf_eModeController_STOPPED
}Type_EcuabCanIf_eModesController;

typedef enum{
      EcuabCanIf_eStatusNotification_NONE
   ,  EcuabCanIf_eStatusNotification_TX_RX
}Type_EcuabCanIf_eStatusNotification;

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

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
