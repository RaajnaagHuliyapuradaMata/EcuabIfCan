#pragma once
/******************************************************************************/
/* File   : EcuabCanIf_Version.hpp                                            */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ECUABCANIF_AR_RELEASE_VERSION_MAJOR                                    4
#define ECUABCANIF_AR_RELEASE_VERSION_MINOR                                    3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(ECUABCANIF_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible ECUABCANIF_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(ECUABCANIF_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible ECUABCANIF_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

