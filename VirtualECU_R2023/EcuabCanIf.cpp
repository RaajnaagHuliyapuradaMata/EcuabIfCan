/******************************************************************************/
/* File   : EcuabCanIf.cpp                                                    */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "EcuabCanIf.hpp"

#include "infEcuabCanIfMcalCan.hpp"
#include "infEcuabCanIfSwcServiceEcuM.hpp"

#include "CfgEcuabCanIf.hpp"

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
const CfgEcuabCanIf_tst* EcuabCanIf_pstConfig;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, ECUABCANIF_CODE) infEcuabCanIfSwcServiceEcuM_InitFunction(const CfgEcuabCanIf_tst* pstConfig){
   EcuabCanIf_pstConfig = pstConfig;
}

FUNC(void, ECUABCANIF_CODE) infEcuabCanIfSwcServiceEcuM_DeInitFunction (void){}
FUNC(void, ECUABCANIF_CODE) infEcuabCanIfSwcServiceSchM_MainFunction   (void){}

FUNC(void, ECUABCANIF_CODE) infEcuabCanIfMcalCan_RxIndication(uint8 lu8IndexBufferRx){
   for(
      uint8 lu8IndexRxPdu = 0;
            lu8IndexRxPdu < EcuabCanIf_pstConfig->u8NumMaxRxPdu;
            lu8IndexRxPdu ++
   ){
      if(
            EcuabCanIf_pstConfig->astPduInfoTable[lu8IndexRxPdu].IdCan
         == McalCan_astRxFifio[lu8IndexBufferRx].McalCan_stFrameExtended.IdCan
      ){
         (EcuabCanIf_pstConfig->astPduInfoTable[lu8IndexRxPdu].fptrRxIndicationUpperLayer)(lu8IndexBufferRx);
         break;
      }
   }
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

