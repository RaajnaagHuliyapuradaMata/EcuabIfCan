add_library(
   BswAUTOSAR_EcuAb_CanIf
   CanIf.cpp
)

include_directories(
   ../../BswAUTOSAR_Service_SchM/LATEST
   ../../common/LATEST
   ../../common/LATEST/Compiler_Abstraction_GNU/LATEST
   ../../SwcServiceEcuM/LATEST
)

