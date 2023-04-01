#pragma once
/******************************************************************************/
/* File   : infEcuabCanIf_ServicePduR.hpp                                                 */
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
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_EcuabCanIf.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class infEcuabCanIf_ServicePduR{
   public:
      virtual FUNC(Std_TypeReturn, CANIF_CODE) Transmit(
         void
      ) = 0;

      virtual FUNC(Std_TypeReturn, CANIF_CODE) McalCancelTransmit(
         void
      ) = 0;

      virtual FUNC(Std_TypeReturn, CANIF_CODE) ReadRxPduData(
         void
      ) = 0;

      virtual FUNC(void, CANIF_CODE) ReadTxNotifStatus(
         void
      ) = 0;

      virtual FUNC(void, CANIF_CODE) ReadRxNotifStatus(
         void
      ) = 0;

      virtual FUNC(void, CANIF_CODE) TxConfirmation(
         void
      ) = 0;

      virtual FUNC(void, CANIF_CODE) RxIndication(
         void
      ) = 0;

      virtual FUNC(void, CANIF_CODE) CbMcalCancelTxConfirmation(
         void
      ) = 0;
};

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

