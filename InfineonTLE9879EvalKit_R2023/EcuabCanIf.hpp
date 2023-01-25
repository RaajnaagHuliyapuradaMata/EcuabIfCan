#pragma once
/******************************************************************************/
/* File   : EcuabCanIf.hpp                                                    */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infEcuabCanIf_ServiceNvM_Types.hpp"
#include "CfgEcuabCanIf.hpp"
#include "EcuabCanIf_core.hpp"
#include "infEcuabCanIf_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_EcuabCanIf:
      INTERFACES_EXPORTED_ECUABCANIF
   ,  public abstract_module
   ,  public class_EcuabCanIf_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstEcuabCanIf_Type* lptrConst = (ConstEcuabCanIf_Type*)NULL_PTR;
      infServicePduRClient_Lo infServicePduRClient_EcuabCanIf;

   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      FUNC(void, ECUABCANIF_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, ECUABCANIF_CONST,       ECUABCANIF_APPL_CONST) lptrConstModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   ECUABCANIF_CONFIG_DATA, ECUABCANIF_APPL_CONST) lptrCfgModule
      );
      FUNC(void, ECUABCANIF_CODE) DeInitFunction (void);
      FUNC(void, ECUABCANIF_CODE) MainFunction   (void);
      ECUABCANIF_CORE_FUNCTIONALITIES
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
extern VAR(module_EcuabCanIf, ECUABCANIF_VAR) EcuabCanIf;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

