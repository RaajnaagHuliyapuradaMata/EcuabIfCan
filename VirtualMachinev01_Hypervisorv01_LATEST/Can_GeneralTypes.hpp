#pragma once
/******************************************************************************/
/* File   : Can_GeneralTypes.hpp                                              */
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
#include "Types_McalCan.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef struct{
   Type_McalCan_tId       CanId;
   Type_McalCan_tHandleHw Hoh;
   uint8                  ControllerId;
}Can_HwType;

typedef enum{
      CANTRCV_TRCVMODE_NORMAL
   ,  CANTRCV_TRCVMODE_SLEEP
   ,  CANTRCV_TRCVMODE_STANDBY
}CanTrcv_TrcvModeType;

typedef enum{
      CANTRCV_WUMODE_ENABLE
   ,  CANTRCV_WUMODE_DISABLE
   ,  CANTRCV_WUMODE_CLEAR
}CanTrcv_TrcvWakeupModeType;

typedef enum{
      CANTRCV_WU_ERROR
   ,  CANTRCV_WU_NOT_SUPPORTED
   ,  CANTRCV_WU_BY_BUS
   ,  CANTRCV_WU_INTERNALLY
   ,  CANTRCV_WU_RESET
   ,  CANTRCV_WU_POWER_ON
   ,  CANTRCV_WU_BY_PIN
}CanTrcv_TrcvWakeupReasonType;

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

