

#ifndef __CANIF_CDD_H__
# define __CANIF_CDD_H__

# define FBLCW_START_SEC_CODE
# include "MemMap.hpp"

FUNC(void, FBLCW_CODE) FblCw_ControllerBusOff(uint8 controllerId);

FUNC(void, FBLCW_CODE) FblCw_ControllerModeIndication(uint8 controllerId, CanIf_ControllerModeType controllerMode);

FUNC(void, FBLCW_CODE) FblCw_CheckTransceiverWakeFlagIndication(uint8 transceiverId);

FUNC(void, FBLCW_CODE) FblCw_ClearTrcvWufFlagIndication(uint8 transceiverId);

FUNC(void, FBLCW_CODE) FblCw_ConfirmPnAvailability(uint8 transceiverId);

FUNC(void, FBLCW_CODE) FblCw_TransceiverModeIndication(uint8 transceiverId, CanTrcv_TrcvModeType transceiverMode);

# define FBLCW_STOP_SEC_CODE
# include "MemMap.hpp"

#endif

