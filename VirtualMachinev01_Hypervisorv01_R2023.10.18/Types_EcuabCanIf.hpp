#pragma once
/******************************************************************************/
/* File   : Types_EcuabCanIf.hpp                                              */
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

