#pragma once
/******************************************************************************/
/* File   : infEcuabCanIf_ServicePduR.hpp                                                 */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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
      virtual FUNC(Std_TypeReturn, ECUABCANIF_CODE) Transmit(
         void
      ) = 0;

      virtual FUNC(Std_TypeReturn, ECUABCANIF_CODE) McalCancelTransmit(
         void
      ) = 0;

      virtual FUNC(Std_TypeReturn, ECUABCANIF_CODE) ReadRxPduData(
         void
      ) = 0;

      virtual FUNC(void, ECUABCANIF_CODE) ReadTxNotifStatus(
         void
      ) = 0;

      virtual FUNC(void, ECUABCANIF_CODE) ReadRxNotifStatus(
         void
      ) = 0;

      virtual FUNC(void, ECUABCANIF_CODE) TxConfirmation(
         void
      ) = 0;

      virtual FUNC(void, ECUABCANIF_CODE) RxIndication(
         void
      ) = 0;

      virtual FUNC(void, ECUABCANIF_CODE) CbCancelTxConfirmation(
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

