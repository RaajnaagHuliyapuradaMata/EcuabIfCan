#pragma once
/******************************************************************************/
/* File   : Types_EcuabCanIf.hpp                                              */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
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
      CANIF_OFFLINE
   ,  CANIF_TX_OFFLINE
   ,  CANIF_TX_OFFLINE_ACTIVE
   ,  CANIF_ONLINE
   ,  CANIF_TX_TP_ONLINE
   ,  CANIF_TX_USER_TP_ONLINE
}Type_EcuabCanIf_eModePdu;

typedef enum{
      CANIF_CS_UNINIT
   ,  CANIF_CS_SLEEP
   ,  CANIF_CS_STARTED
   ,  CANIF_CS_STOPPED
}Type_EcuabCanIf_eModeController;

typedef enum{
      CANIF_NO_NOTIFICATION
   ,  CANIF_TX_RX_NOTIFICATION
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

