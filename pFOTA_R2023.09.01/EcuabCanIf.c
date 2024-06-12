#define CANIF_SOURCE
#ifdef __cplusplus
extern "C"
{
#endif

#include "EcuabCanIf.hpp"
#include "CanIf_Cbk.hpp"

#if !defined (CANIF_AVOID_VSTDLIB_COPY)
#include "vstdlib.hpp"
#if defined (VSTD_HL_USE_VSTD_RAMMEMCPY)
#define CANIF_USES_VSTDLIB_COPY      STD_ON
#endif
#endif

#if !defined (CANIF_USES_VSTDLIB_COPY)
#define CANIF_USES_VSTDLIB_COPY      STD_OFF
#endif

#if(CANIF_TRCV_HANDLING == STD_ON)
#include "infEcuabCanIfEcuabCanTrcv.hpp"
#endif

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
#include "SwcServiceDet.hpp"
#endif

#include "SchM_CanIf.hpp"

#if(CANIF_BUS_MIRRORING_SUPPORT == STD_ON)
#include "Mirror_Cbk.hpp"
#endif

#if(CANIF_CBK_MAJOR_VERSION != 0x05u)
# error "Vendor specific major version number of CanIf.c and CanIf_Cbk.h are inconsistent!"
#endif

#if(CANIF_CBK_MINOR_VERSION != 0x05u)
# error "Vendor specific minor version number of CanIf.c and CanIf_Cbk.h are inconsistent!"
#endif

#if(CANIF_CBK_PATCH_VERSION != 0x00u)
# error "Vendor specific patch version number of CanIf.c and CanIf_Cbk.h are inconsistent!"
#endif

#if(CANIF_TYPES_MAJOR_VERSION != 0x06u)
# error "Vendor specific major version number of CanIf.c and CanIf_Types.h are inconsistent!"
#endif

#if(CANIF_TYPES_MINOR_VERSION != 0x17u)
# error "Vendor specific minor version number of CanIf.c and CanIf_Types.h are inconsistent!"
#endif

#if(CANIF_TYPES_PATCH_VERSION != 0x00u)
# error "Vendor specific patch version number of CanIf.c and CanIf_Types.h are inconsistent!"
#endif

#if(CANIF_API_MAJOR_VERSION != 0x06u)
# error "Vendor specific major version number of CanIf.c and CanIf.h are inconsistent!"
#endif

#if(CANIF_API_MINOR_VERSION != 0x19u)
# error "Vendor specific minor version number of CanIf.c and CanIf.h are inconsistent!"
#endif

#if(CANIF_API_PATCH_VERSION != 0x00u)
# error "Vendor specific patch version number of CanIf.c and CanIf.h are inconsistent!"
#endif

#if(CANIF_CPU_TYPE_SET_IN_ECUC_MODULE != CPU_TYPE)
# error "Invalid configuration! CPUType configured in EcuC-module differs from \"CPU_TYPE\" set in \"Platform_Types.h\"."
#endif

#if(CANIF_CFG5_GENERATOR_COMPATIBILITY_VERSION != CANIF_GENDATA_COMPATIBILITY_VERSION)
#error "Module CanIf: Source and Generated Header files are inconsistent! Please check the version of the generator."
#endif

#if defined (CANIF_RX_PASS_STATIC_DLC)
#if(CANIF_RX_PASS_STATIC_DLC == STD_ON)
#error "Feature CANIF_RX_PASS_STATIC_DLC is NOT supported by CAN interface anymore."
#endif
#endif

#if(CANIF_WAKEUP_VALIDATION == STD_ON)
#if(CANIF_WAKEUP_SUPPORT == STD_OFF)
#error "Invalid configuration: Wake up validation (CANIF_WAKEUP_VALIDATION) is activated without activating wake up support (CANIF_WAKEUP_SUPPORT)"
#endif
#endif

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
#if(CANIF_TRCV_MAPPING == STD_ON)
#error "Invalid configuration: One channel optimization not possible with transceiver mapping"
#endif
#endif

#if(CANIF_WAKEUP_VALIDATION == STD_OFF)
#if(CANIF_WAKEUP_VALID_ALL_RX_MSGS == STD_ON)
#error "Invalid configuration"
#endif
#endif

#if(CANIF_PN_TRCV_HANDLING == STD_ON)
#if(CANIF_TRCV_HANDLING == STD_OFF)
#error "Invalid configuration: Partial networking transceiver handling (CANIF_PN_TRCV_HANDLING) is enabled while transceiver handling is disabled (CANIF_TRCV_HANDLING)"
#endif
#endif

#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
#error "Invalid configuration: One channel optimization not possible if multiple CAN drivers are used"
#endif
#endif

#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
#if(EcuabCanIf_Transmit_CANCELLATION == STD_ON)
# error "HW Tx-cancellation is NOT supported in combination with Tx-Buffer Type FIFO!"
#endif
#endif

#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)

#define CANIF_PN_WU_FLAG_GET                   0x80u

#endif

#define CANIF_WU_VALIDATION_NM_FLAG_GET         0x80u
#define CANIF_WU_VALIDATION_NM_MASK_OUT         0x7Fu

#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)

#define CANIF_MASKCODE_RANGE   0x20000000u
#define CANIF_FDFLAG           0x40000000u

#define CANIF_STOP_FLAG        0x40000000u
#define CANIF_RANGE_FLAG       0x20000000u
#else

#define CANIF_MASKCODE_RANGE   0x2000u
#define CANIF_FDFLAG           0x4000u

#define CANIF_STOP_FLAG        0x4000u
#define CANIF_RANGE_FLAG       0x2000u
#endif

#define CANIF_J1939_NULL_ADDR                 0xFEu
#define CANIF_J1939_BROADCAST_ADDR            0xFFu
#define CANIF_J1939_DATA_PAGE_MASK            0x03000000u
#define CANIF_J1939_PGN_MASK                  0x03FF0000u
#define CANIF_J1939_AC_PGN                    0x00EE0000u
#define CANIF_J1939_MIN_PDU2_MASK             0x00F00000u
#define CANIF_J1939_DA_MASK                   0x0000FF00u
#define CANIF_J1939_INV_DA_MASK               0xFFFF00FFu
#define CANIF_J1939_SA_MASK                   0x000000FFu
#define CANIF_J1939_INV_SA_MASK               0xFFFFFF00u
#define CANIF_J1939_RQST_PGN                  0x00EA0000u
#define CANIF_J1939_ACKM_ACKADDR_POS          4u
#define CANIF_J1939_ACKM_PGN                  0x00E80000u

#if((CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON) || (CANIF_META_DATA_RX_SUPPORT == STD_ON) || (CANIF_RX_INDICATION_TYPE_IV_IS_USED == STD_ON))
#define CanIf_Indirect_HlIndication(hrh, pduid, cansduptr, candlc, canid)     CanIf_HlIndication((hrh), (pduid), (cansduptr), (candlc), (canid))
#else
#define CanIf_Indirect_HlIndication(hrh, pduid, cansduptr, candlc, canid)     CanIf_HlIndication((hrh), (pduid), (cansduptr), (candlc))
#endif

#define CanIf_ControllerType                               EcuabCanIf_StatesCtrlIdxOfTxPduConfigType
#define CanIf_RxIndFctListIdxType                          CfgEcuabCanIf_ListFctIndicationRxIdxOfRxPduConfigType
#define CanIf_TxConfFctListIdxType                         EcuabCanIf_ListFctConfirmationTxIdxOfTxPduConfigType
#define CanIf_TxPduQueueType                               EcuabCanIf_IndexQueuePduTxStartIdxOfControllerConfigType
#define CanIf_CanTrcvFctTblIdx                             CanIf_CanTrcvFctTblIdxOfTransceiverUpToLowMapType

#define  CanIf_AnyIdxType uint32_least

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
#define CANIF_CHANNEL_CANTYPE_FIRST
#define CANIF_CHANNEL_CANTYPE_ONLY                   void
#define CANIF_CHANNEL_CANPARA_ONLY
#define CANIF_CHANNEL_CANPARA_FIRST
#define CANIF_CHANNEL_CANPARA_FIRST_LOCAL
#define CanIf_Controller_Value                       0u
#define CANIF_CHANNEL_CANTYPE_LOCAL
#define CANIF_WUCHANNEL_CANTYPE_LOCAL
#define CanIf_Controller_Value_Local                 0u
#define CanIf_WU_Controller_Value_Local              0u
#define CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE     CanIf_GetMaxTrcvHandleIdPlusOne()
#else
#define CANIF_CHANNEL_CANTYPE_FIRST                  CanIf_ControllerType ControllerId,
#define CANIF_CHANNEL_CANTYPE_ONLY                   CanIf_ControllerType ControllerId
#define CANIF_CHANNEL_CANPARA_ONLY                   ControllerId
#define CANIF_CHANNEL_CANPARA_FIRST                  ControllerId,
#define CANIF_CHANNEL_CANPARA_FIRST_LOCAL            controller,
#define CanIf_Controller_Value                       ControllerId
#define CANIF_CHANNEL_CANTYPE_LOCAL                  CanIf_ControllerType controller;
#define CANIF_WUCHANNEL_CANTYPE_LOCAL                CanIf_ControllerType wuController;
#define CanIf_Controller_Value_Local                 controller
#define CanIf_WU_Controller_Value_Local              wuController
#define CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE     CanIf_GetMaxTrcvHandleIdPlusOne()
#endif

#define CANIF_CFG_MAX_CONTROLLER                     CanIf_GetSizeOfCtrlStates()
#define CANIF_CFG_TX_CONTROLLER(index)               CanIf_GetCtrlStatesIdxOfTxPduConfig(index)

#if(CANIF_TRCV_MAPPING == STD_ON)
#define CANIF_CFG_MAX_CANTRCV_TRCVHANDLEIDPLUSONE    CanIf_GetSizeOfTransceiverUpToUpperMap()
#else
#define CANIF_CFG_MAX_CANTRCV_TRCVHANDLEIDPLUSONE    CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE
#endif

#if(CANIF_TRCV_HANDLING == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
#define CanIf_TrcvIdUpper                     0u
#else
#define CanIf_TrcvIdUpper                     TransceiverId
#endif
#endif

#define CANIF_CFG_GENERATORCOMPATIBILITYVERSION            CanIf_GetGeneratorCompatibilityVersion()
#define CANIF_CFG_MAGICNUMBER                              CanIf_GetFinalMagicNumber()

#define CANIF_CFG_MAX_MAILBOXES                            CanIf_GetSizeOfMailBoxConfig()
#define CANIF_CFG_MAX_TXPDUS                               CanIf_GetSizeOfTxPduConfig()
#define CANIF_CFG_MAX_ULTXPDUS                             CanIf_GetSizeOfUlTxPduId2InternalTxPduId()

#define CANIF_CFG_MAX_TXCONFIRMATIONS                      CanIf_GetSizeOfTxConfirmationFctList()
#define CANIF_CFG_MAX_RXPDUS                               CanIf_GetSizeOfRxPduConfig()
#define CANIF_CFG_MAX_ULRXPDUS                             CanIf_GetSizeOfUlRxPduId2InternalRxPduId()

#define CANIF_CFG_MAX_RXINDICATIONS                        CanIf_GetSizeOfRxIndicationFctList()
#define CANIF_CFG_MAX_WAKEUPSOURCES                        CanIf_GetMaxWakeUpSources()

#define CANIF_CFG_MULTIPLECANDRV_HXHOFFSET(index)          CanIf_GetHxhOffset(index)

#define CANIF_CFG_CTRL_STARTIDX2MAPPEDTXBUFFERS(index)     CanIf_GetMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig(index)

#define CANIF_CFG_CTRL_STOPIDX2MAPPEDTXBUFFERS(index)      CanIf_GetMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig(index)

#define CANIF_CFG_MAPPEDTXBUFFERS(index)                   CanIf_GetMailBoxConfigIdxOfMappedTxBuffersConfig(index)

#define CANIF_CFG_IS_CANDRVINDEXVALID(index)               CanIf_IsCanDrvFctTblUsedOfCanChannelIdUpToLowMap(index)
#define CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(index)        CanIf_GetCanDrvFctTblIdxOfCanChannelIdUpToLowMap(index)

#define CANIF_CFG_CTRLJ1939DYNADDRSUPPORT(index)           CanIf_GetJ1939DynAddrSupportOfCtrlConfig(index)

#define CANIF_CFG_CTRLID2J1939DYNADDROFFSET(index)         CanIf_GetJ1939DynAddrOffsetOfCtrlConfig(index)

#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#define CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(index)      CanIf_GetChannelIndexOfCanChannelIdUpToLowMap(index)
#define CANIF_GET_CANSETCTRLMODEFCT(index)                CanIf_GetSetControllerModeFctOfCanDrvFctTbl(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(index))
#else
#define CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(index)      (index)
#define canSetCtrlModeFct                                 Can_SetControllerMode
#endif

#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#define CANIF_GET_CANCANCELTXFCT(index)                   CanIf_GetCancelTxFctOfCanDrvFctTbl(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(index))
#else
#define canCancelTxFct                                    Can_CancelTx
#endif

#define CANIF_CFG_RX_RXINDICATION(index)                   CanIf_GetRxIndicationFctListIdxOfRxPduConfig(index)
#define CANIF_CFG_RX_DLC(index)                            CanIf_GetDlcOfRxPduConfig(index)
#define CANIF_CFG_RX_UPPERPDUID(index)                     CanIf_GetUpperPduIdOfRxPduConfig(index)
#define CANIF_CFG_RX_MASK(index)                           CanIf_GetRxPduMaskOfRxPduConfig(index)
#define CANIF_CFG_RX_CANID(index)                          CanIf_GetRxPduCanIdOfRxPduConfig(index)
#define CANIF_CFG_RX_RXMETADATALENGTH(index)               CanIf_GetRxMetaDataLengthOfRxPduConfig(index)
#define CANIF_CFG_RX_MSGTYPE(index)                        CanIf_GetMsgTypeOfRxPduConfig(index)
#define CANIF_CFG_RX_MAXVALIDRXDLC                         CanIf_GetMaxValidRxDlc()

#define CANIF_CFG_RX_ISDATACHECKSUMPDU(index)              CanIf_IsIsDataChecksumRxPduOfRxPduConfig(index)

#define CANIF_CFG_RX_ISRECEPTIONMODEPDU(index)             CanIf_IsPduRxModeUsedOfRxPduConfig(index)

#define CANIF_CFG_RX_PDURECEPTIONMODEIDX(Index)            CanIf_GetPduRxModeIdxOfRxPduConfig(Index)

#define CANIF_CFG_EXTRXPDUID2INTRXPDUID(index)             CanIf_GetRxPduConfigIdxOfUlRxPduId2InternalRxPduId(index)

#define CANIF_CFG_INTRXPDUID2EXTRXPDUID(index)             CanIf_GetCanIfRxPduIdOfRxPduConfig(index)

#define CANIF_VAR_SET_PDU_RECEPTION_MODE(Index, Value)     CanIf_SetPduRxMode(Index, Value)
#define CANIF_VAR_GET_PDU_RECEPTION_MODE(Index)            CanIf_GetPduRxMode(Index)

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
#define CANIF_VAR_J1939RXADDR_LOOKUP(ch, addr)            CanIf_GetJ1939RxAddr_Lookup(addr)
#define CANIF_VAR_SET_J1939RXADDR_LOOKUP(ch, addr, value) CanIf_SetJ1939RxAddr_Lookup((addr), (value))
#else
#define CANIF_VAR_J1939RXADDR_LOOKUP(ch, addr)            CanIf_GetJ1939RxAddr_Lookup(CANIF_CFG_CTRLID2J1939DYNADDROFFSET(ch) + (addr))
#define CANIF_VAR_SET_J1939RXADDR_LOOKUP(ch, addr, value) CanIf_SetJ1939RxAddr_Lookup((CANIF_CFG_CTRLID2J1939DYNADDROFFSET(ch) + (addr)), (value))
#endif

#define CANIF_CFG_TX_CANID(index)                          CanIf_GetCanIdOfTxPduConfig(index)
#define CANIF_CFG_TX_HTH(index)                            CanIf_GetMailBoxConfigIdxOfTxPduConfig(index)
#define CANIF_CFG_TX_TXCONFIRMATION(index)                 CanIf_GetTxConfirmationFctListIdxOfTxPduConfig(index)
#define CANIF_CFG_TX_UPPERLAYERTXPDUID(index)              CanIf_GetUpperLayerTxPduIdOfTxPduConfig(index)
#define CANIF_CFG_TX_TXMETADATALENGTH(index)               CanIf_GetTxMetaDataLengthOfTxPduConfig(index)
#define CANIF_CFG_TX_DLC(index)                            CanIf_GetDlcOfTxPduConfig(index)
#define CANIF_CFG_TX_CANIDTXMASK(index)                    CanIf_GetCanIdTxMaskOfTxPduConfig(index)

#define CANIF_CFG_TX_ISDATACHECKSUMPDU(index)              CanIf_IsIsDataChecksumTxPduOfTxPduConfig(index)

#define CANIF_CFG_TXPDUID2INTTXPDUID(index)                CanIf_GetUlTxPduId2InternalTxPduId(index)
#define CANIF_CFG_TX_QUEUEINDEX(index)                     CanIf_GetTxQueueIdxOfTxPduQueueIndex(index)

#define CANIF_CFG_TXBUFFERFIFO_BUFFERBASEIDX(index)        CanIf_GetTxBufferFifoBaseIdxOfTxBufferFifoConfig(index)

#define CANIF_CFG_TXBUFFERFIFO_QUEUEBASESTARTIDX(index)    CanIf_GetTxFifoQueueBaseStartIdxOfTxBufferFifoConfig(index)
#define CANIF_CFG_TXBUFFERFIFO_QUEUEBASEENDIDX(index)      CanIf_GetTxFifoQueueBaseEndIdxOfTxBufferFifoConfig(index)

#define CANIF_CFG_TXBUFFFERFIFO_QUEUEDATASTARTIDX(index)   CanIf_GetTxFifoQueueDataStartIdxOfTxBufferFifoConfig(index)

#define CANIF_CFG_TXBUFFERFIFO_QUEUESIZE(index)            CanIf_GetTxFifoQueueBaseLengthOfTxBufferFifoConfig(index)

#define CANIF_CFG_TXBUFFERFIFO_SIZEOFONEPAYLOADEL(index)   CanIf_GetSizeOfOnePayloadElOfTxBufferFifoConfig(index)

#define CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(index, field)    CanIf_GetTxBufferFifoBase(index).field

#define CANIF_VAR_TXBUFFERFIFO_QUEUEBASE(index, field)     CanIf_GetTxFifoQueueBase(index).field

#define CANIF_VAR_TXBUFFERFIFO_QUEUEDATA(index)            CanIf_GetTxFifoQueueData(index)
#define CANIF_VAR_SET_TXBUFFERFIFO_QUEUEDATA(index)        CanIf_SetTxFifoQueueData(index)
#define CANIF_ADDR_VAR_TXBUFFERFIFO_QUEUEDATA(index)       CanIf_GetAddrTxFifoQueueData(index)

#define CANIF_VAR_TXBUFFERFIFO_QUEUEIDX2FIFOEL(index)      CanIf_GetTxQueueIndex2FifoEl(index)
#define CANIF_VAR_SET_TXBUFFERFIFO_QUEUEIDX2FIFOEL(index, value)  CanIf_SetTxQueueIndex2FifoEl(index, value)

#define CANIF_CFG_SIZEOF_FIFO_BUFFER                       CanIf_GetSizeOfTxFifoQueueData()

#define CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_BUFFERBASEIDX(index)            CanIf_GetTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig(index)

#define CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_QUEUESIZE(index)                CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig(index)

#define CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_STARTIDX2MAPPEDTXPDUS(index)    CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig(index)

#define CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_STOPIDX2MAPPEDTXPDUS(index)     CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig(index)

#define CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_MAPPEDTXPDUS(index)             CanIf_GetTxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus(index)

#define CANIF_VAR_TXBUFFERPRIOBYCANID_BUFFERBASE(index, field)                 CanIf_GetTxBufferPrioByCanIdBase(index).field

#define CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_BUFFERBASEIDX(index)             CanIf_GetTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdBitQueueConfig(index)

#define CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUESTARTIDX(index)             CanIf_GetTxQueueFlagsStartIdxOfTxBufferPrioByCanIdBitQueueConfig(index)
#define CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUESTOPIDX(index)              CanIf_GetTxQueueFlagsEndIdxOfTxBufferPrioByCanIdBitQueueConfig(index)
#define CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_BITPOS2TXPDUIDOFFSET(index)      CanIf_GetBitPos2TxPduIdOffsetOfTxBufferPrioByCanIdBitQueueConfig(index)

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
#define CANIF_VAR_J1939TXADDR_LOOKUP(ch, addr)            CanIf_GetJ1939TxAddr_Lookup(addr)
#define CANIF_VAR_SET_J1939TXADDR_LOOKUP(ch, addr, value) CanIf_SetJ1939TxAddr_Lookup((addr), (value))
#else
#define CANIF_VAR_J1939TXADDR_LOOKUP(ch, addr)            CanIf_GetJ1939TxAddr_Lookup(CANIF_CFG_CTRLID2J1939DYNADDROFFSET(ch) + (addr))
#define CANIF_VAR_SET_J1939TXADDR_LOOKUP(ch, addr, value) CanIf_SetJ1939TxAddr_Lookup((CANIF_CFG_CTRLID2J1939DYNADDROFFSET(ch) + (addr)), (value))
#endif

#define CANIF_CFG_MAILBOX_PDUIDFIRST(index)                CanIf_GetPduIdFirstOfMailBoxConfig(index)
#define CANIF_CFG_MAILBOX_PDUIDLAST(index)                 CanIf_GetPduIdLastOfMailBoxConfig(index)
#define CANIF_CFG_MAILBOX_MAILBOXTYPE(index)               CanIf_GetMailBoxTypeOfMailBoxConfig(index)
#define CANIF_CFG_MAILBOX_CONTROLLER(index)                CanIf_GetCtrlStatesIdxOfMailBoxConfig(index)
#define CANIF_CFG_MAILBOX_TXBUFFERIDX(index)               CanIf_GetTxBufferCfgIdxOfMailBoxConfig(index)
#define CANIF_CFG_MAILBOX_TXBUFFERHANDLINGTYPE(index)      CanIf_GetTxBufferHandlingTypeOfMailBoxConfig(index)
#define CANIF_CFG_MAILBOX_HASTXBUFFER(index)               CanIf_IsTxBufferCfgUsedOfMailBoxConfig(index)

#define CANIF_CFG_WAKEUP_WAKEUPSOURCE(index)               CanIf_GetWakeUpSourceOfWakeUpConfig(index)
#define CANIF_CFG_WAKEUP_WAKEUPTARGETMODULE(index)         CanIf_GetWakeUpTargetModuleOfWakeUpConfig(index)
#define CANIF_CFG_WAKEUP_WAKEUPTARGETADDRESS(index)        CanIf_GetWakeUpTargetAddressOfWakeUpConfig(index)
#define CANIF_CFG_WAKEUP_CONTROLLER(index)                 CanIf_GetControllerOfWakeUpConfig(index)

#define CANIF_CFG_TRCVUPTOLOWMAP_DRIVERINDEX(index)        CanIf_GetCanTrcvFctTblIdxOfTransceiverUpToLowMap(index)
#define CANIF_CFG_TRCVUPTOLOWMAP_CHANNELINDEX(index)       CanIf_GetChannelIndexOfTransceiverUpToLowMap(index)

#define CanIf_GetCanTrcv_SetOpModeFctMap(index)            CanIf_GetSetOpModeFctOfCanTrcvFctTbl(index)
#define CanIf_GetCanTrcv_GetOpModeFctMap(index)            CanIf_GetGetOpModeFctOfCanTrcvFctTbl(index)
#define CanIf_GetCanTrcv_GetBusWuReasonFctMap(index)       CanIf_GetGetBusWuReasonFctOfCanTrcvFctTbl(index)
#define CanIf_GetCanTrcv_SetWakeupModeFctMap(index)        CanIf_GetSetWakeupModeFctOfCanTrcvFctTbl(index)
#define CanIf_GetCanTrcv_CheckWakeupFctMap(index)          CanIf_GetCheckWakeupFctOfCanTrcvFctTbl(index)

#define CanIf_GetCanTrcv_ClearTrcvWufFlagFctMap(index)     CanIf_GetClearTrcvWufFlagFctOfCanTrcvFctTbl(index)
#define CanIf_GetCanTrcv_CheckWakeFlagFctMap(index)        CanIf_GetCheckWakeFlagFctOfCanTrcvFctTbl(index)

#define CANIF_CFG_RXDHRANDOMNUMBER1(index)                 CanIf_GetRxDHRandomNumber1OfCtrlConfig(index)
#define CANIF_CFG_RXDHRANDOMNUMBER2(index)                 CanIf_GetRxDHRandomNumber2OfCtrlConfig(index)

#define CANIF_CFG_RXDHADJUST(index)                        CanIf_GetRxDHAdjust(index)
#define CANIF_CFG_RXDHADJUSTCOUNT                          CanIf_GetSizeOfRxDHAdjust()

#define CANIF_CFG_STAT2DYN_INDIRECTION(index)                                       CanIf_GetTxPduStatic2DynamicIndirection(index)
#define CANIF_CFG_TXBUFFERPRIOBYCANID_STATFDQUEUE_QUEUEIDX2DATASTARTSTOP(index)     CanIf_GetTxQueueIndex2DataStartStopIdxOfTxPduQueueIndex(index)

#define CANIF_CFG_TXBUFFERPRIOBYCANID_STATFDQUEUE_DATASTARTIDX(index)               CanIf_GetTxQueueDataStartIdxOfTxQueueIndex2DataStartStop(CANIF_CFG_TXBUFFERPRIOBYCANID_STATFDQUEUE_QUEUEIDX2DATASTARTSTOP(index))
#define CANIF_CFG_TXBUFFERPRIOBYCANID_STATFDQUEUE_MAXDATALENGTH(index)              CanIf_GetTxQueueDataLengthOfTxQueueIndex2DataStartStop(CANIF_CFG_TXBUFFERPRIOBYCANID_STATFDQUEUE_QUEUEIDX2DATASTARTSTOP(index))

#define CANIF_CFG_ISFEATUREPNWUTXPDUFILTERENABLED(index)   CanIf_IsFeaturePnWuTxPduFilterEnabledOfCtrlConfig(index)
#define CANIF_CFG_TRCVTOCTRLMAP(index)                     CanIf_GetTrcvToCtrlMap(index)
#define CANIF_CFG_TRCVUPTOUPPERMAP(index)                  CanIf_GetTransceiverUpToUpperMap(index)

#define CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(index, field)                      CanIf_GetTxQueue(index).field

#define CANIF_VAR_TXBUFFERPRIOBYCANID_STATFDQUEUE_QUEUEDATA(index)             CanIf_GetTxQueueData(index)
#define CANIF_ADDR_VAR_TXBUFFERPRIOBYCANID_STATFDQUEUE_QUEUEDATA(index)        CanIf_GetAddrTxQueueData(index)

#define CANIF_VAR_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUEFLAGS(index)                CanIf_GetTxQueueFlags(index)
#define CANIF_VAR_SET_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUEFLAGS(index, value)     CanIf_SetTxQueueFlags((index), (value))

#define CANIF_VAR_DYNTXID(index)                                               CanIf_GetDynTxId(index)

#define CANIF_CFG_RXINDICATION_FUNCTION(index)             CanIf_GetRxIndicationFctOfRxIndicationFctList(index)
#define CANIF_CFG_RXINDICATION_FUNCTIONLAYOUT(index)       CanIf_GetRxIndicationLayoutOfRxIndicationFctList(index)
#define CANIF_CFG_TXCONFIRMATION(index)                    CanIf_GetTxConfirmationFctList(index)

#define CANIF_CFG_BUSOFFNOTIFICATION()                     CanIf_GetBusOffNotificationFctPtr()
#define CANIF_CFG_WAKEUPVALIDATION()                       CanIf_GetWakeUpValidationFctPtr()
#define CANIF_CFG_CTRLMODEINDICATIONFCT()                  CanIf_GetCtrlModeIndicationFctPtr()

#define CANIF_CFG_RAMCHECKCORRUPTMAILBOXINDFCT()           CanIf_GetRamCheckCorruptMailboxIndFctPtr()
#define CANIF_CFG_RAMCHECKCORRUPTCONTROLLERINDFCT()        CanIf_GetRamCheckCorruptControllerIndFctPtr()

#define CANIF_CFG_TRCVMODEINDICATIONFCT()                  CanIf_GetTrcvModeIndicationFctPtr()
#define CANIF_CFG_CHECKTRCVWAKEFLAGINDICATIONFCT()         CanIf_GetCheckTrcvWakeFlagIndicationFctPtr()
#define CANIF_CFG_CLEARTRCVWUFFLAGINDICATIONFCT()          CanIf_GetClearTrcvWufFlagIndicationFctPtr()
#define CANIF_CFG_CONFIRMPNAVAILABILITYFCT()               CanIf_GetConfirmPnAvailabilityFctPtr()

#define CanIf_SetCtrlMode(index, value)                    CanIf_SetCtrlModeOfCtrlStates((index), (value))
#define CanIf_GetCtrlMode(index)                           CanIf_GetCtrlModeOfCtrlStates(index)

#define CanIf_SetChannelMode(index, value)                 CanIf_SetPduModeOfCtrlStates((index), (value))
#define CanIf_GetChannelMode(index)                        CanIf_GetPduModeOfCtrlStates(index)

#define CanIf_SetPnWuTxPduFilterActive(index, value)       CanIf_SetPnWuTxPduFilterActiveOfCtrlStates((index), (value))
#define CanIf_IsPnWuTxPduFilterActive(index)               CanIf_IsPnWuTxPduFilterActiveOfCtrlStates(index)

#define CanIf_SetTxConfState(index, value)                 CanIf_SetTxConfStateOfCtrlStates((index), (value))
#define CanIf_GetTxConfState(index)                        CanIf_GetTxConfStateOfCtrlStates(index)

#define CanIf_SetWakeUpValidationState(index, value)       CanIf_SetWakeUpValidationStateOfCtrlStates((index), (value))
#define CanIf_GetWakeUpValidationState(index)              CanIf_GetWakeUpValidationStateOfCtrlStates(index)

#define CanIf_ChangeMirroring(index, value)                CanIf_SetBusMirroringActiveOfCtrlStates((index), (value))
#define CanIf_IsMirroringEnabled(index)                    CanIf_IsBusMirroringActiveOfCtrlStates(index)

#define CanIf_SetTxQueueCounter(index, value)              (CanIf_GetTxBufferPrioByCanIdBase(index).eQueueCounter = (value))
#define CanIf_GetTxQueueCounter(index)                     (CanIf_GetTxBufferPrioByCanIdBase(index).eQueueCounter)
#define CanIf_IncTxQueueCounter(index)                     (++CanIf_GetTxBufferPrioByCanIdBase(index).eQueueCounter)
#define CanIf_DecTxQueueCounter(index)                     (--CanIf_GetTxBufferPrioByCanIdBase(index).eQueueCounter)

#define CanIf_GetCan_WriteFctMap(index)                    CanIf_GetWriteFctOfCanDrvFctTbl(index)
#define CanIf_GetCan_CheckWakeupFctMap(index)              CanIf_GetCheckWakeupFctOfCanDrvFctTbl(index)
#define CanIf_GetCan_CheckBaudrateFctMap(index)            CanIf_GetCheckBaudrateFctOfCanDrvFctTbl(index)
#define CanIf_GetCan_ChangeBaudrateFctMap(index)           CanIf_GetChangeBaudrateFctOfCanDrvFctTbl(index)
#define CanIf_GetCan_SetBaudrateFctMap(index)              CanIf_GetSetBaudrateFctOfCanDrvFctTbl(index)

#define CanIf_GetCan_RamCheckExecuteFctMap(index)          CanIf_GetRamCheckExecuteFctOfCanDrvFctTbl(index)
#define CanIf_GetCan_RamCheckEnableMailboxFctMap(index)    CanIf_GetRamCheckEnableMailboxFctOfCanDrvFctTbl(index)
#define CanIf_GetCan_RamCheckEnableControllerFctMap(index) CanIf_GetRamCheckEnableControllerFctOfCanDrvFctTbl(index)

#define CanIf_GetCan_GetControllerErrorStateFctMap(index)      CanIf_GetGetControllerErrorStateFctOfCanDrvFctTbl(index)
#define CanIf_GetCan_GetControllerRxErrorCounterFctMap(index)  CanIf_GetGetControllerRxErrorCounterOfCanDrvFctTbl(index)
#define CanIf_GetCan_GetControllerTxErrorCounterFctMap(index)  CanIf_GetGetControllerTxErrorCounterOfCanDrvFctTbl(index)

#define CanIf_EnterCritical(area)     SchM_Enter_CanIf_##area()
#define CanIf_LeaveCritical(area)     SchM_Exit_CanIf_##area()

#define CANIF_NOP      ((uint8)0xFFu)

#if(CANIF_BITQUEUE == STD_ON)
#if( CPU_TYPE == CPU_TYPE_8 )
#define kCanTxQueueShift     3u
#define elemStartBitIdx      7u
# elif( CPU_TYPE == CPU_TYPE_16 )
#define kCanTxQueueShift     4u
#define elemStartBitIdx      15u
#else
#define kCanTxQueueShift     5u
#define elemStartBitIdx      31u
#endif

#define kCanTxQueueMask      (((uint8)1u << kCanTxQueueShift) - (uint8)1u)
#endif

#define CANIF_START_SEC_CONST_8BIT
#include "MemMap.hpp"

CONST(uint8, CANIF_CONST) CanIf_MainVersion         = (uint8)CANIF_SW_MAJOR_VERSION;
CONST(uint8, CANIF_CONST) CanIf_SubVersion          = (uint8)CANIF_SW_MINOR_VERSION;
CONST(uint8, CANIF_CONST) CanIf_ReleaseVersion      = (uint8)CANIF_SW_PATCH_VERSION;

#define CANIF_STOP_SEC_CONST_8BIT
#include "MemMap.hpp"

#define CANIF_START_SEC_CODE
#include "MemMap.hpp"

#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

CANIF_LOCAL FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_QueueTxTreatment(CanIf_HwHandleType hth);

CANIF_LOCAL FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_QueueTxTransmit(PduIdType PduId);

CANIF_LOCAL FUNC(void, CANIF_CODE) CanIf_ClearQueue(CANIF_CHANNEL_CANTYPE_ONLY);
#endif

#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPrioByCanIdTxPduAsQueued(PduIdType PduId);

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearPrioByCanIdTxPduAsQueued(PduIdType PduId);
#endif

#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
#if  (CANIF_CANCEL_SUPPORT_API == STD_ON)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) infEcuabCanIfSwcApplEcuM_InitFunctionSubInitFifoQueue(void);
#endif
#endif

#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)

CANIF_LOCAL_INLINE FUNC(boolean, CANIF_CODE) EcuabCanIf_TransmitSubCheckFiFoQueueEmpty(PduIdType CanTxPduId);
#endif

#if((CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON) || (CANIF_META_DATA_RX_SUPPORT == STD_ON) || (CANIF_RX_INDICATION_TYPE_IV_IS_USED == STD_ON))

CANIF_LOCAL FUNC(void, CANIF_CODE) CanIf_HlIndication(CanIf_HwHandleType  Hrh, PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc, Can_IdType CanId);
#else
CANIF_LOCAL FUNC(void, CANIF_CODE) CanIf_HlIndication(CanIf_HwHandleType  Hrh, PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc);
#endif

CANIF_LOCAL FUNC(void, CANIF_CODE) CanIf_HlTxConfirmation(PduIdType CanTxPduId);

#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)

CANIF_LOCAL_INLINE FUNC(EcuabCanIf_TransmitStateType, CANIF_CODE) EcuabCanIf_TransmitSubHandleTxPduFilter(CANIF_CHANNEL_CANTYPE_FIRST CONST(PduIdType, AUTOMATIC) CanTxPduId);
#endif

#if(CANIF_META_DATA_TX_SUPPORT == STD_ON)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_TransmitSubHandleMetaData(P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_MSG_VAR) PduInfoPtr, P2VAR(Can_PduType, AUTOMATIC, AUTOMATIC) localPduPtr);
#endif

#if(CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_TransmitSubJ1939DynAddr(CANIF_CHANNEL_CANTYPE_FIRST P2VAR(Can_PduType, AUTOMATIC, AUTOMATIC)localPduPtr);
#endif
#endif

#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_TransmitSubHandleTxResBusy(P2CONST(Can_PduType, AUTOMATIC, AUTOMATIC) localPduPtr);
#endif

#if(CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_RxIndicationSubJ1939DynAddr(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams);
#endif
#endif

#if(CANIF_SEARCH_ALGORITHM == CANIF_BINARY)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubBinarySearch(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams);

#if(CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON)
CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubBinarySearchSubCheckMsgType(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams);
#endif
#endif

#if(CANIF_SEARCH_ALGORITHM == CANIF_DOUBLE_HASH)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubDoubleHashSearch(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams);
#endif

#if(CANIF_SEARCH_ALGORITHM == CANIF_LINEAR)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubLinearSearch(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams);
#endif

CANIF_LOCAL_INLINE FUNC(CanIf_NotifStatusType, CANIF_CODE) EcuabCanIf_RxIndicationSubReceptionPduMode(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams);

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubRangeSearch(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams);

#if((CANIF_WAKEUP_VALIDATION == STD_ON) && (CANIF_WAKEUP_VALID_ALL_RX_MSGS == STD_ON))

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubWakeupValidation(P2CONST(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams);
#endif

CANIF_LOCAL_INLINE FUNC (Std_ReturnType, CANIF_CODE) EcuabCanIf_TransmitSubWrite(P2CONST(Can_PduType, AUTOMATIC, AUTOMATIC) localPduPtr);

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubBasicCan(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams);

#if(CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON) || (CANIF_RX_INDICATION_TYPE_IV_IS_USED == STD_ON)
CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) CanIf_HlIndicationSubULCall(PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc, Can_IdType CanId);
#else
CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) CanIf_HlIndicationSubULCall(PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc);
#endif

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerModeSubSwitch(CANIF_CHANNEL_CANTYPE_FIRST CanIf_ControllerModeType ControllerMode);

#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) CanIf_TxBufferPrioByCanIdQueuePdu(P2CONST(Can_PduType, AUTOMATIC, CANIF_CBK_DRV_VAR) PduInfoPtr);
#endif

#define CANIF_STOP_SEC_CODE
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

CANIF_LOCAL CONST(uint8, CANIF_CONST) CanIfState[CANIF_NO_MODE_PDU_GET_MODE_TYPE_END][CANIF_NO_MODE_PDU_SET_MODE_TYPE_END] =
{
  {
    (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_RX_ONLINE)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_TX_ONLINE)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_GET_OFFLINE_ACTIVE)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
,   (uint8)(CANIF_GET_ONLINE_WAKF)
   ,   (uint8)(CANIF_GET_TX_ONLINE_WAKF)
#endif
  },

  {
    (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
,   (uint8)(CANIF_GET_ONLINE_WAKF)
   ,   (uint8)(CANIF_GET_ONLINE_WAKF)
#endif
  },

  {
    (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_GET_OFFLINE_ACTIVE)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
,   (uint8)(CANIF_GET_ONLINE_WAKF)
   ,   (uint8)(CANIF_GET_TX_ONLINE_WAKF)
#endif
  },

  {
    (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_GET_TX_ONLINE)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_RX_ONLINE)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
,   (uint8)(CANIF_GET_ONLINE_WAKF)
   ,   (uint8)(CANIF_GET_ONLINE_WAKF)
#endif
  },

  {
    (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE)
   ,   (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_GET_TX_ONLINE)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_NOP)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
,   (uint8)(CANIF_GET_ONLINE_WAKF)
   ,   (uint8)(CANIF_GET_TX_ONLINE_WAKF)
#endif
  },

  {
    (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_GET_OFFLINE_ACTIVE)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_RX_ONLINE)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_NOP)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
,   (uint8)(CANIF_GET_ONLINE_WAKF)
   ,   (uint8)(CANIF_GET_ONLINE_WAKF)
#endif
  }
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
,

  {
    (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_GET_TX_ONLINE_WAKF)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_RX_ONLINE)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_NOP)
  },

  {
    (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_NOP)
   ,   (uint8)(CANIF_GET_ONLINE_WAKF)
   ,   (uint8)(CANIF_GET_OFFLINE)
   ,   (uint8)(CANIF_GET_TX_ONLINE)
   ,   (uint8)(CANIF_GET_ONLINE)
   ,   (uint8)(CANIF_GET_OFFLINE_ACTIVE)
   ,   (uint8)(CANIF_GET_ONLINE_WAKF)
   ,   (uint8)(CANIF_NOP)
  }
#endif
};

#if(CANIF_BITQUEUE == STD_ON)

CANIF_LOCAL CONST(EcuabCanIf_QueueTxFlagType, CANIF_CONST) CanShiftLookUp[1u << kCanTxQueueShift] =
{
  (EcuabCanIf_QueueTxFlagType)0x00000001u, (EcuabCanIf_QueueTxFlagType)0x00000002u, (EcuabCanIf_QueueTxFlagType)0x00000004u, (EcuabCanIf_QueueTxFlagType)0x00000008u
   ,  (EcuabCanIf_QueueTxFlagType)0x00000010u, (EcuabCanIf_QueueTxFlagType)0x00000020u, (EcuabCanIf_QueueTxFlagType)0x00000040u, (EcuabCanIf_QueueTxFlagType)0x00000080u
#if( CPU_TYPE > CPU_TYPE_8 )
,  (EcuabCanIf_QueueTxFlagType)0x00000100u, (EcuabCanIf_QueueTxFlagType)0x00000200u, (EcuabCanIf_QueueTxFlagType)0x00000400u, (EcuabCanIf_QueueTxFlagType)0x00000800u
   ,  (EcuabCanIf_QueueTxFlagType)0x00001000u, (EcuabCanIf_QueueTxFlagType)0x00002000u, (EcuabCanIf_QueueTxFlagType)0x00004000u, (EcuabCanIf_QueueTxFlagType)0x00008000u
#endif
#if( CPU_TYPE > CPU_TYPE_16 )
,  (EcuabCanIf_QueueTxFlagType)0x00010000u, (EcuabCanIf_QueueTxFlagType)0x00020000u, (EcuabCanIf_QueueTxFlagType)0x00040000u, (EcuabCanIf_QueueTxFlagType)0x00080000u
   ,  (EcuabCanIf_QueueTxFlagType)0x00100000u, (EcuabCanIf_QueueTxFlagType)0x00200000u, (EcuabCanIf_QueueTxFlagType)0x00400000u, (EcuabCanIf_QueueTxFlagType)0x00800000u
   ,  (EcuabCanIf_QueueTxFlagType)0x01000000u, (EcuabCanIf_QueueTxFlagType)0x02000000u, (EcuabCanIf_QueueTxFlagType)0x04000000u, (EcuabCanIf_QueueTxFlagType)0x08000000u
   ,  (EcuabCanIf_QueueTxFlagType)0x10000000u, (EcuabCanIf_QueueTxFlagType)0x20000000u, (EcuabCanIf_QueueTxFlagType)0x40000000u, (EcuabCanIf_QueueTxFlagType)0x80000000u
#endif
};
#endif

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.hpp"

#if(CANIF_USE_INIT_POINTER == STD_ON)
P2CONST(CanIf_ConfigType, CANIF_VAR_INIT, CANIF_XCFG) CanIf_ConfigDataPtr = NULL_PTR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
CANIF_LOCAL VAR(boolean, CANIF_VAR_INIT) CanIf_SystemInit = FALSE;
#endif
#endif

#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CODE
#include "MemMap.hpp"

#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)

CANIF_LOCAL_INLINE FUNC(boolean, CANIF_CODE) EcuabCanIf_TransmitSubCheckFiFoQueueEmpty(PduIdType CanTxPduId){
  boolean  retVal = FALSE;
  CanIf_AnyIdxType txBufferCfgIdx;
  CanIf_AnyIdxType hth;

  hth = CANIF_CFG_TX_HTH(CanTxPduId);
  txBufferCfgIdx = CANIF_CFG_MAILBOX_TXBUFFERIDX(hth);

  if(CANIF_VAR_TXBUFFERFIFO_BUFFERBASE((CANIF_CFG_TXBUFFERFIFO_BUFFERBASEIDX(txBufferCfgIdx)), eQueueCounter) == 0u){
    retVal = TRUE;
  }
  return retVal;
}
#endif

#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
#if(CANIF_CANCEL_SUPPORT_API == STD_ON)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) infEcuabCanIfSwcApplEcuM_InitFunctionSubInitFifoQueue(void){
  CanIf_AnyIdxType counter;

  for(counter = 0; counter < CanIf_GetSizeOfTxQueueIndex2FifoEl(); counter++){
    CANIF_VAR_SET_TXBUFFERFIFO_QUEUEIDX2FIFOEL((counter), CANIF_NO_ENTRY_IN_TX_FIFO);
  }

  for(counter = 0; counter < CanIf_GetSizeOfTxFifoQueueBase(); counter++){
    CANIF_VAR_TXBUFFERFIFO_QUEUEBASE( counter, eQueued) = 0;
  }
}
#endif
#endif

#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPrioByCanIdTxPduAsQueued(PduIdType PduId){
#if(CANIF_BITQUEUE == STD_ON)
  CanIf_AnyIdxType  queueElementIdx;
  uint8         elementBitIdx;
  PduIdType     queueBitPos;
#endif
  uint8 errorId;
  CanIf_AnyIdxType txBufferCfgIdx;
  Std_ReturnType retval = E_NOT_OK;
  errorId = CANIF_E_NO_ERROR;
  txBufferCfgIdx = CANIF_CFG_MAILBOX_TXBUFFERIDX(CANIF_CFG_TX_HTH(PduId));

#if(CANIF_BITQUEUE == STD_ON)

  queueBitPos  =  (PduIdType)(PduId - CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_BITPOS2TXPDUIDOFFSET(txBufferCfgIdx));
  queueElementIdx = (((uint16_least)queueBitPos) >> kCanTxQueueShift) + CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUESTARTIDX(txBufferCfgIdx);
  elementBitIdx  = (uint8)(queueBitPos & kCanTxQueueMask);

  if( (CANIF_VAR_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUEFLAGS(queueElementIdx) & CanShiftLookUp[elementBitIdx]) == (EcuabCanIf_QueueTxFlagType)0 ){
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
    if(queueElementIdx >= CanIf_GetSizeOfTxQueueFlags()){
      errorId = CANIF_E_FATAL;
    }
    else
#endif
    {
      CANIF_VAR_SET_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUEFLAGS(queueElementIdx, (CANIF_VAR_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUEFLAGS(queueElementIdx) | CanShiftLookUp[elementBitIdx]));
      CanIf_IncTxQueueCounter(CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_BUFFERBASEIDX(txBufferCfgIdx));
      retval = E_OK;
    }
  }

#else

  if(CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(CANIF_CFG_TX_QUEUEINDEX(PduId), eQueued) == 0u){
    CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(CANIF_CFG_TX_QUEUEINDEX(PduId), eQueued) = 1u;
    CanIf_IncTxQueueCounter(CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_BUFFERBASEIDX(txBufferCfgIdx) );
    retval = E_OK;
  }
#endif

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(infEcuabCanIfSwcApplEcuM_InitFunction_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearPrioByCanIdTxPduAsQueued(PduIdType PduId){
#if(CANIF_BITQUEUE == STD_ON)
  CanIf_AnyIdxType  queueElementIdx;
  uint8         elementBitIdx;
  PduIdType     queueBitPos;
#endif
  uint8 errorId;
  CanIf_AnyIdxType txBufferCfgIdx;
  Std_ReturnType retval = E_NOT_OK;
  errorId = CANIF_E_NO_ERROR;
  txBufferCfgIdx = CANIF_CFG_MAILBOX_TXBUFFERIDX(CANIF_CFG_TX_HTH(PduId));

#if(CANIF_BITQUEUE == STD_ON)

  queueBitPos  =  (PduIdType)(PduId - CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_BITPOS2TXPDUIDOFFSET(txBufferCfgIdx));
  queueElementIdx = (((uint16_least)queueBitPos) >> kCanTxQueueShift) + CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUESTARTIDX(txBufferCfgIdx);
  elementBitIdx  = (uint8)(queueBitPos & kCanTxQueueMask);

  if( (CANIF_VAR_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUEFLAGS(queueElementIdx) & CanShiftLookUp[elementBitIdx]) != (EcuabCanIf_QueueTxFlagType)0 ){
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
    if(queueElementIdx >= CanIf_GetSizeOfTxQueueFlags()){
      errorId = CANIF_E_FATAL;
    }
    else
#endif
    {
      CANIF_VAR_SET_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUEFLAGS(queueElementIdx, (CANIF_VAR_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUEFLAGS(queueElementIdx) & (~CanShiftLookUp[elementBitIdx])));
      CanIf_DecTxQueueCounter(CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_BUFFERBASEIDX(txBufferCfgIdx));
      retval = E_OK;
    }
  }

#else

  if(CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(CANIF_CFG_TX_QUEUEINDEX(PduId), eQueued) == 1u){
    CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(CANIF_CFG_TX_QUEUEINDEX(PduId), eQueued) = 0u;
    CanIf_DecTxQueueCounter(CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_BUFFERBASEIDX(txBufferCfgIdx));
    retval = E_OK;
  }
#endif

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(infEcuabCanIfSwcApplEcuM_InitFunction_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

CANIF_LOCAL FUNC(void, CANIF_CODE) CanIf_ClearQueue(CANIF_CHANNEL_CANTYPE_ONLY){
  CanIf_AnyIdxType idx2MappedTxBufferCfg;
  CanIf_AnyIdxType hth;
#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)
  CanIf_AnyIdxType txBufferBaseIdx;
#if(CANIF_BITQUEUE == STD_ON)
  CanIf_AnyIdxType TxQueueFlagsIdx;
#else
  CanIf_AnyIdxType MappedTxPdusIdx;
  CanIf_AnyIdxType TxPduId;
#endif
#endif
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
  CanIf_AnyIdxType txBufferFifoBaseIdx;
#if(CANIF_CANCEL_SUPPORT_API == STD_ON)
  CanIf_AnyIdxType txFifoQueueBaseStartIdx;
  CanIf_TxBufferSizeType readIdx;
  CanIf_TxBufferSizeType counter;
#endif
#endif
  CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_1);

  for(idx2MappedTxBufferCfg = CANIF_CFG_CTRL_STARTIDX2MAPPEDTXBUFFERS(CanIf_Controller_Value); idx2MappedTxBufferCfg < CANIF_CFG_CTRL_STOPIDX2MAPPEDTXBUFFERS(CanIf_Controller_Value); idx2MappedTxBufferCfg++ ){
    CanIf_AnyIdxType txBufferCfgIdx;
    hth = CANIF_CFG_MAPPEDTXBUFFERS(idx2MappedTxBufferCfg);
    txBufferCfgIdx = CANIF_CFG_MAILBOX_TXBUFFERIDX(hth);

    switch(CANIF_CFG_MAILBOX_TXBUFFERHANDLINGTYPE(hth)){
#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)
      case CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID:
#if(CANIF_BITQUEUE == STD_ON)

        for( TxQueueFlagsIdx = CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUESTARTIDX(txBufferCfgIdx); TxQueueFlagsIdx < CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUESTOPIDX(txBufferCfgIdx); TxQueueFlagsIdx++)
        {
          CANIF_VAR_SET_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUEFLAGS(TxQueueFlagsIdx, 0);
        }
        txBufferBaseIdx = CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_BUFFERBASEIDX(txBufferCfgIdx);
#else

        for(MappedTxPdusIdx = CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_STARTIDX2MAPPEDTXPDUS(txBufferCfgIdx); MappedTxPdusIdx < CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_STOPIDX2MAPPEDTXPDUS(txBufferCfgIdx); MappedTxPdusIdx++)
        {
          TxPduId =  CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_MAPPEDTXPDUS(MappedTxPdusIdx);
          CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(CANIF_CFG_TX_QUEUEINDEX(TxPduId), eQueued) = 0;
        }
        txBufferBaseIdx = CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_BUFFERBASEIDX(txBufferCfgIdx);
#endif

        CanIf_SetTxQueueCounter(txBufferBaseIdx, 0);
        break;
#endif
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
      case CANIF_TXBUFFER_HANDLINGTYPE_FIFO:

        txBufferFifoBaseIdx = CANIF_CFG_TXBUFFERFIFO_BUFFERBASEIDX((txBufferCfgIdx));

#if(CANIF_CANCEL_SUPPORT_API == STD_ON)
        if(CanIf_GetCtrlMode(CanIf_Controller_Value) != CANIF_CS_UNINIT)
        {
          readIdx = CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx);
          counter =  CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eQueueCounter);
          txFifoQueueBaseStartIdx = CANIF_CFG_TXBUFFERFIFO_QUEUEBASESTARTIDX(txBufferCfgIdx);

          while(counter > 0u)
          {
            CANIF_VAR_SET_TXBUFFERFIFO_QUEUEIDX2FIFOEL(CANIF_CFG_TX_QUEUEINDEX(CANIF_VAR_TXBUFFERFIFO_QUEUEBASE((readIdx + txFifoQueueBaseStartIdx), eTxPduId)), CANIF_NO_ENTRY_IN_TX_FIFO);
            CANIF_VAR_TXBUFFERFIFO_QUEUEBASE((readIdx + txFifoQueueBaseStartIdx), eQueued) = 0;

            readIdx++;
            if(readIdx == CANIF_CFG_TXBUFFERFIFO_QUEUESIZE(txBufferCfgIdx))
            {
              readIdx = 0;
            }
            counter--;
          }
        }
#endif

        CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eWriteIdx) = 0;
        CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx) = 0;
        CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eQueueCounter) = 0;

        break;
#endif
      default:
        break;
    }
  }
  CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_1);
}
#endif

FUNC(void, CANIF_CODE) infEcuabCanIfSwcApplEcuM_InitFunction(P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_XCFG) ConfigPtr){
  CANIF_CHANNEL_CANTYPE_LOCAL
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_USE_INIT_POINTER == STD_ON)
  CanIf_ConfigDataPtr = ConfigPtr;

#if((CANIF_DEV_ERROR_DETECT == STD_ON ) || (CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME))

  if(CanIf_ConfigDataPtr == NULL_PTR){
#if(CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME)
    EcuM_BswErrorHook((uint16) CANIF_MODULE_ID, (uint8) ECUM_BSWERROR_NULLPTR);
#else
    errorId = CANIF_E_PARAM_POINTER;
#endif
    }
    else
#endif
#if(CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME)

  if(CANIF_CFG_GENERATORCOMPATIBILITYVERSION != CANIF_GENDATA_COMPATIBILITY_VERSION){
    EcuM_BswErrorHook((uint16) CANIF_MODULE_ID, (uint8) ECUM_BSWERROR_COMPATIBILITYVERSION);
  }

  else if(CANIF_CFG_MAGICNUMBER != CANIF_MAGIC_NUMBER){
    EcuM_BswErrorHook((uint16) CANIF_MODULE_ID, (uint8) ECUM_BSWERROR_MAGICNUMBER);
  }
  else
#endif
#else
  CANIF_DUMMY_STATEMENT(ConfigPtr);
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)

#if(CANIF_EXTENDEDID_SUPPORT != STD_ON)
  if(sizeof (Can_IdType) != 2u){
    errorId = CANIF_E_INVALID_CANIDTYPESIZE;
  }
#else
  if(sizeof (Can_IdType) != 4u){
    errorId = CANIF_E_INVALID_CANIDTYPESIZE;
  }
#endif
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
  else

  if( CanIf_GetSizeOfCanChannelIdUpToLowMap() < CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_FATAL;
  }
#endif
  else
#endif
  {
#if(CANIF_SETDYNAMICTXID_API == STD_ON)
    PduIdType DynamicPduId;
    PduIdType CanPduId;
    for(CanPduId = 0; CanPduId < CANIF_CFG_MAX_TXPDUS; CanPduId++){
      DynamicPduId = CANIF_CFG_STAT2DYN_INDIRECTION(CanPduId);
      if(DynamicPduId < CanIf_GetSizeOfDynTxId())
      {
        CANIF_VAR_DYNTXID(DynamicPduId) = CANIF_CFG_TX_CANID(CanPduId);
      }
    }
#endif

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    for(controller = 0; controller < CANIF_CFG_MAX_CONTROLLER; controller++)
#endif
    {
#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION==STD_ON)
      CanIf_ClearQueue();
#else
      CanIf_ClearQueue(CanIf_Controller_Value_Local);
#endif
#endif

      CanIf_SetCtrlMode(CanIf_Controller_Value_Local, CANIF_CS_STOPPED);

      CanIf_SetChannelMode(CanIf_Controller_Value_Local, CANIF_GET_OFFLINE);
#if(CANIF_WAKEUP_VALIDATION == STD_ON)

      CanIf_SetWakeUpValidationState(CanIf_Controller_Value_Local, CANIF_WUVALIDATION_ARMED);
#endif
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)

      CanIf_SetPnWuTxPduFilterActive(CanIf_Controller_Value_Local, FALSE);
#endif

#if(CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON)

      CanIf_SetTxConfState(CanIf_Controller_Value_Local, CANIF_NO_NOTIFICATION);
#endif

#if(CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)
      {
        uint8 index;

        if(CANIF_CFG_CTRLJ1939DYNADDRSUPPORT(CanIf_Controller_Value_Local) != CANIF_J1939_DYN_ADDR_DISABLED )
        {
          for(index = 0; index < 0xFFu; index++)
          {
            CANIF_VAR_SET_J1939RXADDR_LOOKUP(CanIf_Controller_Value_Local, index, CANIF_J1939_NULL_ADDR);
            CANIF_VAR_SET_J1939TXADDR_LOOKUP(CanIf_Controller_Value_Local, index, CANIF_J1939_NULL_ADDR);
          }
          CANIF_VAR_SET_J1939RXADDR_LOOKUP(CanIf_Controller_Value_Local, 0xFFu, CANIF_J1939_BROADCAST_ADDR);
          CANIF_VAR_SET_J1939TXADDR_LOOKUP(CanIf_Controller_Value_Local, 0xFFu, CANIF_J1939_BROADCAST_ADDR);
        }
      }
#endif
#endif

#if(CANIF_BUS_MIRRORING_SUPPORT == STD_ON)

      CanIf_ChangeMirroring(CanIf_Controller_Value_Local, FALSE);
#endif
    }
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
#if(CANIF_CANCEL_SUPPORT_API == STD_ON)

    infEcuabCanIfSwcApplEcuM_InitFunctionSubInitFifoQueue();
#endif
#endif
#if(CANIF_SET_PDU_RECEPTION_MODE_SUPPORT == STD_ON)
    {
      CanIf_PduRxModeIterType index;

      for(index = 0; index < CanIf_GetSizeOfPduRxMode(); index++)
      {
        CANIF_VAR_SET_PDU_RECEPTION_MODE(index, CANIF_RMT_RECEIVE_STOP);
      }
    }
#endif
#if((CANIF_DEV_ERROR_DETECT == STD_ON) && (CANIF_USE_INIT_POINTER == STD_ON))
    CanIf_SystemInit = TRUE;
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(infEcuabCanIfSwcApplEcuM_InitFunction_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
}

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerModeSubSwitch(CANIF_CHANNEL_CANTYPE_FIRST CanIf_ControllerModeType ControllerMode){
  Std_ReturnType retval;
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
  CanIf_Can_SetControllerModeFctType canSetCtrlModeFct;

  canSetCtrlModeFct = CANIF_GET_CANSETCTRLMODEFCT(CanIf_Controller_Value);
#endif
  retval = E_NOT_OK;

  switch(ControllerMode){
    case CANIF_CS_STOPPED:

      switch(CanIf_GetCtrlMode(CanIf_Controller_Value))
      {
        case CANIF_CS_SLEEP:

          if(canSetCtrlModeFct((uint8)CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), CAN_T_WAKEUP) == CAN_OK)
          {
            retval = E_OK;
          }
          break;

        case CANIF_CS_STARTED:

          if(canSetCtrlModeFct((uint8)CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), CAN_T_STOP) == CAN_OK)
          {
#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

            CanIf_ClearQueue(CANIF_CHANNEL_CANPARA_ONLY);
#endif
            retval = E_OK;
          }
          break;

        case CANIF_CS_STOPPED:

          if(canSetCtrlModeFct((uint8)CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), CAN_T_STOP) == CAN_OK)
          {
            retval = E_OK;
          }
          break;

        default:

          break;
      }
      break;
    case CANIF_CS_STARTED:

      switch(CanIf_GetCtrlMode(CanIf_Controller_Value))
      {
        case CANIF_CS_STOPPED:

          if(canSetCtrlModeFct((uint8)CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), CAN_T_START) == CAN_OK)
          {
            retval = E_OK;
          }
          break;

        case CANIF_CS_STARTED:

          if(canSetCtrlModeFct((uint8)CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), CAN_T_START) == CAN_OK)
          {
            retval = E_OK;
          }
          break;

        default:

          break;
      }
      break;
    case CANIF_CS_SLEEP:

      switch(CanIf_GetCtrlMode(CanIf_Controller_Value))
      {
        case CANIF_CS_STOPPED:

          if(canSetCtrlModeFct((uint8)CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), CAN_T_SLEEP) == CAN_OK)
          {
#if(CANIF_WAKEUP_VALIDATION == STD_ON)

            CanIf_SetWakeUpValidationState(CanIf_Controller_Value, CANIF_WUVALIDATION_ARMED);
#endif
            retval = E_OK;
          }
          break;

        case CANIF_CS_SLEEP:
          if(canSetCtrlModeFct((uint8)CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), CAN_T_SLEEP) == CAN_OK)
          {
            retval = E_OK;
          }
          break;

        default:

          break;
      }
      break;
    default:

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
      CanIf_Det_ReportError(CANIF_SETCONTROLLERMODE_API, CANIF_E_PARAM_CTRLMODE);
#endif
      break;
    }
    return retval;
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode(uint8 ControllerId, CanIf_ControllerModeType ControllerMode){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
#if((CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON) && (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value)){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
  else
#endif
  {
#if(CANIF_DEV_ERROR_DETECT == STD_OFF)

    if(CanIf_GetCtrlMode(CanIf_Controller_Value) != CANIF_CS_UNINIT)
#endif
    {
      CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_0);
      retval = CanIf_SetControllerModeSubSwitch(CANIF_CHANNEL_CANPARA_FIRST ControllerMode);
      CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_0);
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_SETCONTROLLERMODE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif

  return retval;
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(uint8 ControllerId, P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) ControllerModePtr){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }

  else if(ControllerModePtr == NULL_PTR){
    errorId = CANIF_E_PARAM_POINTER;
  }
  else
#endif

  {
    *ControllerModePtr = CanIf_GetCtrlMode(CanIf_Controller_Value);
    retval = E_OK;
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_GETCONTROLLERMODE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
  return retval;
}

#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)

CANIF_LOCAL_INLINE FUNC(EcuabCanIf_TransmitStateType, CANIF_CODE) EcuabCanIf_TransmitSubHandleTxPduFilter(CANIF_CHANNEL_CANTYPE_FIRST CONST(PduIdType, AUTOMATIC) CanTxPduId){
  EcuabCanIf_TransmitStateType pnTxState;
  uint8 pnPduLength;
  pnTxState = CANIF_DO_TRANSMIT;

  pnPduLength = CANIF_CFG_TX_DLC(CanTxPduId);

  if(CANIF_CFG_ISFEATUREPNWUTXPDUFILTERENABLED(CanIf_Controller_Value)){
    if(CanIf_IsPnWuTxPduFilterActive(CanIf_Controller_Value)){
      if((pnPduLength & CANIF_PN_WU_FLAG_GET) == 0u)
      {
        pnTxState = CANIF_DO_NOT_TRANSMIT;
      }
    }
  }

  return pnTxState;
}
#endif

#if(CANIF_META_DATA_TX_SUPPORT == STD_ON)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_TransmitSubHandleMetaData(P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_MSG_VAR) PduInfoPtr, P2VAR(Can_PduType, AUTOMATIC, AUTOMATIC) localPduPtr){
  uint8 startPos;
  uint8 endPos;
  Can_IdType localId;

  if(CANIF_CFG_TX_TXMETADATALENGTH(localPduPtr->swPduHandle) > 0u){
    localId = 0;
    endPos = (uint8)(PduInfoPtr->SduLength);

    if(PduInfoPtr->SduLength >= CANIF_CFG_TX_TXMETADATALENGTH(localPduPtr->swPduHandle)){
      startPos =  (uint8)((PduInfoPtr->SduLength) - 1u);
      endPos = (uint8)(endPos - CANIF_CFG_TX_TXMETADATALENGTH(localPduPtr->swPduHandle));

      while(startPos > endPos)
      {
        localId |= PduInfoPtr->SduDataPtr[startPos];
        localId = localId << 8;
        startPos--;
      }
      localId |= PduInfoPtr->SduDataPtr[startPos];

      localPduPtr->id = (Can_IdType)(((localPduPtr->id & CANIF_CFG_TX_CANIDTXMASK(localPduPtr->swPduHandle)) | (localId & (Can_IdType)(~CANIF_CFG_TX_CANIDTXMASK(localPduPtr->swPduHandle)))));
    }

    localPduPtr->length = endPos;
  }
  else

  {
    localPduPtr->length = (uint8)(PduInfoPtr->SduLength);
  }
}
#endif

#if(CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_TransmitSubJ1939DynAddr(CANIF_CHANNEL_CANTYPE_FIRST P2VAR(Can_PduType, AUTOMATIC, AUTOMATIC)localPduPtr){
  uint8 errorId = CANIF_E_NO_ERROR;
  Std_ReturnType retVal = E_OK;

  if( CANIF_CFG_CTRLJ1939DYNADDRSUPPORT(CanIf_Controller_Value) != CANIF_J1939_DYN_ADDR_DISABLED ){
    uint8 da;
    uint8 sa;
    uint8 sa_t;

    if(((localPduPtr)->id & CANIF_EXT_CANID_MASK) == CANIF_EXT_CANID_MASK){
      if((((localPduPtr)->id & CANIF_J1939_DATA_PAGE_MASK) != CANIF_J1939_DATA_PAGE_MASK) && (((localPduPtr)->id & CANIF_J1939_PGN_MASK) != CANIF_J1939_AC_PGN))
      {
        if(((localPduPtr)->id & CANIF_J1939_MIN_PDU2_MASK) < CANIF_J1939_MIN_PDU2_MASK)
        {
          da = (uint8)(((localPduPtr)->id & CANIF_J1939_DA_MASK) >> 8);
          da = CANIF_VAR_J1939TXADDR_LOOKUP(CanIf_Controller_Value, da);
          if(da == CANIF_J1939_NULL_ADDR)
          {
            errorId = CANIF_E_INVALID_DA;
            retVal = E_NOT_OK;
          }
          (localPduPtr)->id = (Can_IdType)(((localPduPtr)->id & CANIF_J1939_INV_DA_MASK) | (((Can_IdType)da) << 8u));
          if(((localPduPtr)->id & CANIF_J1939_PGN_MASK) == CANIF_J1939_ACKM_PGN)
          {
            uint8 ackAddr = CANIF_VAR_J1939TXADDR_LOOKUP(CanIf_Controller_Value, (localPduPtr)->sdu[CANIF_J1939_ACKM_ACKADDR_POS]);
            if(ackAddr == CANIF_J1939_NULL_ADDR)
            {
              errorId = CANIF_E_INVALID_DA;
              retVal = E_NOT_OK;
            }
            if((localPduPtr)->length > CANIF_J1939_ACKM_ACKADDR_POS)
            {
              (localPduPtr)->sdu[CANIF_J1939_ACKM_ACKADDR_POS] = ackAddr;
            }
            else
            {
              errorId = CANIF_E_CONFIG;
              retVal  = E_NOT_OK;
            }
          }
        }

        sa = (uint8)((localPduPtr)->id & CANIF_J1939_SA_MASK);
        sa_t = CANIF_VAR_J1939TXADDR_LOOKUP(CanIf_Controller_Value, sa);

        if((sa == CANIF_J1939_BROADCAST_ADDR) || ((sa != CANIF_J1939_NULL_ADDR) && (sa_t == CANIF_J1939_NULL_ADDR)) || ((sa == CANIF_J1939_NULL_ADDR) && (((localPduPtr)->id & CANIF_J1939_PGN_MASK) != CANIF_J1939_RQST_PGN)))
        {
          errorId = CANIF_E_INVALID_SA;
          retVal = E_NOT_OK;
        }
        (localPduPtr)->id = (Can_IdType)(((localPduPtr)->id & CANIF_J1939_INV_SA_MASK) | sa_t);
      }
    }
#if(CANIF_J1939_DYN_ADDR_SUPPORT == CANIF_J1939_DYN_ADDR_MIXED_CANID)
    else{
      if( CANIF_CFG_CTRLJ1939DYNADDRSUPPORT(CanIf_Controller_Value) != CANIF_J1939_DYN_ADDR_EXT_CANID )
      {
        sa = (uint8)((localPduPtr)->id & CANIF_J1939_SA_MASK);
        sa = CANIF_VAR_J1939TXADDR_LOOKUP(CanIf_Controller_Value, sa);
        if(sa == CANIF_J1939_NULL_ADDR)
        {
          errorId = CANIF_E_INVALID_SA;
          retVal = E_NOT_OK;
        }
        (localPduPtr)->id = (Can_IdType)(((localPduPtr)->id & CANIF_J1939_INV_SA_MASK) | sa);
      }
    }
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(EcuabCanIf_Transmit_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}
#endif
#endif

#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) CanIf_TxBufferPrioByCanIdQueuePdu(P2CONST(Can_PduType, AUTOMATIC, CANIF_CBK_DRV_VAR) PduInfoPtr ){
  CanIf_AnyIdxType queueindex = CANIF_CFG_TX_QUEUEINDEX(PduInfoPtr->swPduHandle);
#if(CANIF_USES_VSTDLIB_COPY == STD_OFF)
  PduLengthType i;
#endif

#if((CANIF_SETDYNAMICTXID_API == STD_ON) || (CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED) || (CANIF_META_DATA_TX_SUPPORT == STD_ON))
  CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(queueindex, eQueueParams.eBaseParams.eCanId) = PduInfoPtr->id;
#endif

  CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(queueindex, eQueueParams.eBaseParams.eSduLength) = PduInfoPtr->length;

#if(CANIF_USES_VSTDLIB_COPY == STD_ON)
#if(CANIF_STATIC_FD_TXQUEUE == STD_ON)
  VStdMemCpyRamToRam(CANIF_ADDR_VAR_TXBUFFERPRIOBYCANID_STATFDQUEUE_QUEUEDATA(CANIF_CFG_TXBUFFERPRIOBYCANID_STATFDQUEUE_DATASTARTIDX(PduInfoPtr->swPduHandle)), PduInfoPtr->sdu, PduInfoPtr->length);
#else
  VStdMemCpyRamToRam(CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(queueindex, eQueueParams.eSdu), PduInfoPtr->sdu, PduInfoPtr->length);
#endif
#else
  for(i = 0; i < PduInfoPtr->length; i++){
#if(CANIF_STATIC_FD_TXQUEUE == STD_ON)
    CanIf_SetTxQueueData((CANIF_CFG_TXBUFFERPRIOBYCANID_STATFDQUEUE_DATASTARTIDX(PduInfoPtr->swPduHandle))+i, PduInfoPtr->sdu[i]);
#else
    CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(queueindex, eQueueParams.eSdu[i]) = PduInfoPtr->sdu[i];
#endif
  }
#endif
}
#endif

#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

CANIF_LOCAL_INLINE FUNC (Std_ReturnType, CANIF_CODE) EcuabCanIf_TransmitSubHandleTxResBusy(P2CONST(Can_PduType, AUTOMATIC, AUTOMATIC) localPduPtr){
  Std_ReturnType retval;
  CanIf_AnyIdxType hth;
  uint8 errorId;

#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
  CanIf_TxBufferSizeType writeIdx;
  CanIf_AnyIdxType queueDataStartIdx;
  CanIf_AnyIdxType txBufferCfgIdx;
  CanIf_AnyIdxType txBufferFifoBaseIdx;
  CanIf_AnyIdxType txFifoQueueBaseStartIdx;
#endif
  errorId = CANIF_E_NO_ERROR;
  retval = E_NOT_OK;
  hth = CANIF_CFG_TX_HTH(localPduPtr->swPduHandle);

  if(CANIF_CFG_MAILBOX_HASTXBUFFER(hth)){
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
    if((localPduPtr->sdu == NULL_PTR) && (localPduPtr->length != 0u)){
      errorId = CANIF_E_PARAM_POINTER;
    }
    else
#endif
    {
#if((CANIF_USES_VSTDLIB_COPY != STD_ON) && (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))
      PduLengthType i;
#endif
      switch(CANIF_CFG_MAILBOX_TXBUFFERHANDLINGTYPE(hth))
      {
#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)

        case CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID:

#if(CANIF_STATIC_FD_TXQUEUE == STD_ON)
          if(localPduPtr->length <= CANIF_CFG_TXBUFFERPRIOBYCANID_STATFDQUEUE_MAXDATALENGTH(localPduPtr->swPduHandle))
#else
          if(localPduPtr->length <= CANIF_STATIC_BUFFER_SIZE)
#endif
          {
            CanIf_TxBufferPrioByCanIdQueuePdu(localPduPtr);

            (void)CanIf_SetPrioByCanIdTxPduAsQueued(localPduPtr->swPduHandle);
            retval = E_OK;
          }
          else

          {
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
            errorId = CANIF_E_PARAM_DLC;
#endif
            retval = E_NOT_OK;
          }
          break;
#endif
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)

        case CANIF_TXBUFFER_HANDLINGTYPE_FIFO:
          txBufferCfgIdx = CANIF_CFG_MAILBOX_TXBUFFERIDX(hth);

          if(localPduPtr->length <= CANIF_CFG_TXBUFFERFIFO_SIZEOFONEPAYLOADEL(txBufferCfgIdx))
          {
            txBufferFifoBaseIdx = CANIF_CFG_TXBUFFERFIFO_BUFFERBASEIDX((txBufferCfgIdx));

            if(CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eQueueCounter) < CANIF_CFG_TXBUFFERFIFO_QUEUESIZE(txBufferCfgIdx))
            {
              txFifoQueueBaseStartIdx = CANIF_CFG_TXBUFFERFIFO_QUEUEBASESTARTIDX(txBufferCfgIdx);
              writeIdx = CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eWriteIdx);

              CANIF_VAR_TXBUFFERFIFO_QUEUEBASE((writeIdx + txFifoQueueBaseStartIdx), eBaseParams.eSduLength) = localPduPtr->length;
#if((CANIF_SETDYNAMICTXID_API == STD_ON) || (CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED) || (CANIF_META_DATA_TX_SUPPORT == STD_ON))

              CANIF_VAR_TXBUFFERFIFO_QUEUEBASE((writeIdx + txFifoQueueBaseStartIdx), eBaseParams.eCanId) = localPduPtr->id;
#endif

              CANIF_VAR_TXBUFFERFIFO_QUEUEBASE((writeIdx + txFifoQueueBaseStartIdx), eTxPduId) = localPduPtr->swPduHandle;

              queueDataStartIdx = ((uint32_least)writeIdx * (uint32_least)CANIF_CFG_TXBUFFERFIFO_SIZEOFONEPAYLOADEL(txBufferCfgIdx)) + CANIF_CFG_TXBUFFFERFIFO_QUEUEDATASTARTIDX(txBufferCfgIdx);
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

              if((queueDataStartIdx + localPduPtr->length) >  CANIF_CFG_SIZEOF_FIFO_BUFFER)
              {
                errorId = CANIF_E_FATAL;
                retval = E_NOT_OK;
              }
              else
#endif
              {
#if(CANIF_USES_VSTDLIB_COPY == STD_ON)
                VStdMemCpyRamToRam(CANIF_ADDR_VAR_TXBUFFERFIFO_QUEUEDATA(queueDataStartIdx), localPduPtr->sdu, localPduPtr->length);
#else
                for(i = 0u; i < localPduPtr->length; i++)
                {
                  CanIf_SetTxFifoQueueData((queueDataStartIdx+i), localPduPtr->sdu[i]);
                }
#endif
#if CANIF_CANCEL_SUPPORT_API == STD_ON

                CANIF_VAR_TXBUFFERFIFO_QUEUEBASE((writeIdx + txFifoQueueBaseStartIdx), eQueued) = 1;

                CANIF_VAR_SET_TXBUFFERFIFO_QUEUEIDX2FIFOEL(CANIF_CFG_TX_QUEUEINDEX(localPduPtr->swPduHandle), writeIdx );
#endif

                (CANIF_VAR_TXBUFFERFIFO_BUFFERBASE( txBufferFifoBaseIdx, eQueueCounter))++;

                (CANIF_VAR_TXBUFFERFIFO_BUFFERBASE( txBufferFifoBaseIdx, eWriteIdx))++;
                if(CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eWriteIdx) == (CANIF_CFG_TXBUFFERFIFO_QUEUESIZE(txBufferCfgIdx)))
                {
                  CANIF_VAR_TXBUFFERFIFO_BUFFERBASE( txBufferFifoBaseIdx, eWriteIdx) = 0;
                }
                retval = E_OK;
              }
            }
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
            else
            {
              errorId = CANIF_E_FULL_TX_BUFFER_FIFO;
            }
#endif
          }
          else
          {
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
            errorId = CANIF_E_PARAM_DLC;
#endif
            retval = E_NOT_OK;
          }
          break;
#endif
      default:
        break;
      }
    }
  }
  else{
    retval = E_NOT_OK;
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(EcuabCanIf_Transmit_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

CANIF_LOCAL_INLINE FUNC (Std_ReturnType, CANIF_CODE) EcuabCanIf_TransmitSubWrite(P2CONST(Can_PduType, AUTOMATIC, AUTOMATIC) localPduPtr){
  Std_ReturnType  retval;
  Can_ReturnType txResult;
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
  boolean doCanWrite;
#endif
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
  txResult = CAN_BUSY;
  doCanWrite = TRUE;
  if( CANIF_CFG_MAILBOX_TXBUFFERHANDLINGTYPE(CANIF_CFG_TX_HTH(localPduPtr->swPduHandle)) == CANIF_TXBUFFER_HANDLINGTYPE_FIFO){
    doCanWrite = EcuabCanIf_TransmitSubCheckFiFoQueueEmpty(localPduPtr->swPduHandle);
  }
  if(doCanWrite == TRUE)
#endif
  {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    {
      CanIf_Can_WriteFctType canWriteFct;
      Can_HwHandleType canDrvHth;

      canWriteFct = CanIf_GetCan_WriteFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CANIF_CFG_TX_CONTROLLER(localPduPtr->swPduHandle)));
      canDrvHth = (Can_HwHandleType)(CANIF_CFG_TX_HTH(localPduPtr->swPduHandle) - CANIF_CFG_MULTIPLECANDRV_HXHOFFSET(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CANIF_CFG_TX_CONTROLLER(localPduPtr->swPduHandle))));

      txResult = canWriteFct(canDrvHth, (P2CONST(Can_PduType, AUTOMATIC, CANIF_VAR_STACK))localPduPtr);
    }
#else
    txResult = Can_Write((CanIf_HwHandleType)CANIF_CFG_TX_HTH(localPduPtr->swPduHandle), (P2CONST(Can_PduType, AUTOMATIC, CANIF_VAR_STACK))localPduPtr);
#endif
  }
  if(txResult == CAN_BUSY){
#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

    retval = EcuabCanIf_TransmitSubHandleTxResBusy(localPduPtr);
#else
    retval = E_NOT_OK;
#endif
  }
  else if(txResult == CAN_NOT_OK){
    retval = E_NOT_OK;
  }
  else{
#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)

    if(CANIF_CFG_MAILBOX_TXBUFFERHANDLINGTYPE(CANIF_CFG_TX_HTH(localPduPtr->swPduHandle)) == CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID){
      (void)CanIf_ClearPrioByCanIdTxPduAsQueued(localPduPtr->swPduHandle);
    }
#endif

    retval = E_OK;
  }
  return retval;
}

FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_Transmit(PduIdType CanTxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_MSG_VAR)PduInfoPtr){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_DATA_CHECKSUM_TX_SUPPORT == STD_ON)
  uint8 txPduDataWithChecksum[CANIF_CFG_MAXTXDLC_PLUS_DATACHECKSUM];
#endif
  Can_PduType     localPdu;
#if CANIF_SETDYNAMICTXID_API == STD_ON
  PduIdType     DynamicPduId;
#endif
  CANIF_CHANNEL_CANTYPE_LOCAL

#if((CANIF_DEV_ERROR_DETECT == STD_ON) && (CANIF_USE_INIT_POINTER == STD_ON))
  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif
#if((CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME) || (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

  if(CanTxPduId >= CANIF_CFG_MAX_ULTXPDUS){
    errorId = CANIF_E_INVALID_TXPDUID;
  }
  else
#endif
  {
    CanTxPduId = CANIF_CFG_TXPDUID2INTTXPDUID(CanTxPduId);
#endif
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

    if(CanTxPduId >= CANIF_CFG_MAX_TXPDUS){
      errorId = CANIF_E_INVALID_TXPDUID;
    }
    else
#endif
    {
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)

      controller = CANIF_CFG_TX_CONTROLLER(CanTxPduId);
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)

      if(PduInfoPtr == NULL_PTR)
      {
        errorId = CANIF_E_PARAM_POINTER;
      }

      else if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT)
      {
        errorId = CANIF_E_UNINIT;

      }
      else
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

      if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value_Local))
      {
        errorId = CANIF_E_PARAM_CONTROLLERID;
      }
      else
#endif
#endif
#endif
      {
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
        EcuabCanIf_TransmitStateType pnTxState;
#endif

#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)

        pnTxState = EcuabCanIf_TransmitSubHandleTxPduFilter(CANIF_CHANNEL_CANPARA_FIRST_LOCAL CanTxPduId);
        if(pnTxState == CANIF_DO_TRANSMIT)
#endif
        {
          if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_STARTED)
          {
            if((CanIf_GetChannelMode(CanIf_Controller_Value_Local) == CANIF_GET_ONLINE) ||
              (CanIf_GetChannelMode(CanIf_Controller_Value_Local) == CANIF_GET_TX_ONLINE)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
              || (CanIf_GetChannelMode(CanIf_Controller_Value_Local) == CANIF_GET_ONLINE_WAKF)
              || (CanIf_GetChannelMode(CanIf_Controller_Value_Local) == CANIF_GET_TX_ONLINE_WAKF)
#endif
              )
            {
              CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_4);

#if(CANIF_SETDYNAMICTXID_API == STD_ON)
              DynamicPduId = CANIF_CFG_STAT2DYN_INDIRECTION(CanTxPduId);
              if(DynamicPduId != CanIf_TxPduHnd_INVALID)
              {
                (localPdu).id = CANIF_VAR_DYNTXID(DynamicPduId);
              }
              else
              {
                (localPdu).id = CANIF_CFG_TX_CANID(CanTxPduId);
              }
#else
              (localPdu).id = CANIF_CFG_TX_CANID(CanTxPduId);
#endif

              localPdu.sdu = (PduInfoPtr->SduDataPtr);
              localPdu.swPduHandle = (CanTxPduId);

#if(CANIF_META_DATA_TX_SUPPORT == STD_ON)

              EcuabCanIf_TransmitSubHandleMetaData(PduInfoPtr, &localPdu);
#else
              localPdu.length = (uint8)(PduInfoPtr->SduLength);
#endif

#if(CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#if  (CANIF_EXTENDEDID_SUPPORT == STD_ON)

              retval = EcuabCanIf_TransmitSubJ1939DynAddr(CANIF_CHANNEL_CANPARA_FIRST_LOCAL &localPdu);
              if(retval == E_OK)
#endif
#endif
              {
#if(CANIF_DATA_CHECKSUM_TX_SUPPORT == STD_ON)

                if(CANIF_CFG_TX_ISDATACHECKSUMPDU(CanTxPduId))
                {
                  EcuabCanIf_TransmitSubDataChecksumTxAppend(&localPdu, &txPduDataWithChecksum[0]);

                  localPdu.sdu = (P2VAR(uint8, TYPEDEF, CAN_APPL_VAR))(&txPduDataWithChecksum[0]);
                }
#endif
                retval = EcuabCanIf_TransmitSubWrite(&localPdu);
              }

              CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_4);
            }

            else if((CanIf_GetChannelMode(CanIf_Controller_Value_Local) == CANIF_GET_OFFLINE_ACTIVE) ||
                    (CanIf_GetChannelMode(CanIf_Controller_Value_Local) == CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE))
            {
              retval = E_OK;

              CanIf_HlTxConfirmation(CanTxPduId);
            }
            else
            {
              errorId = CANIF_E_STOPPED;
            }
          }

          else if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_STOPPED)
          {
            errorId = CANIF_E_STOPPED;
          }
          else
          {
          }
        }
      }
    }
#if((CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME) || (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))
  }
#endif

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(EcuabCanIf_Transmit_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

  return retval;
}

CANIF_LOCAL FUNC(void, CANIF_CODE) CanIf_HlTxConfirmation(PduIdType CanTxPduId){
  CanIf_TxConfFctListIdxType index;
  PduIdType upperLayerTxPduId;
  Type_EcuabCanIf_FctConfirmationTx txConfirmationFct;

  index = CANIF_CFG_TX_TXCONFIRMATION(CanTxPduId);

  upperLayerTxPduId = CANIF_CFG_TX_UPPERLAYERTXPDUID(CanTxPduId);

  txConfirmationFct = CANIF_CFG_TXCONFIRMATION(index);

  if(txConfirmationFct != (Type_EcuabCanIf_FctConfirmationTx)NULL_PTR){
      txConfirmationFct(upperLayerTxPduId);
  }
}

FUNC(void, CANIF_CODE) EcuabCanIf_TxConfirmation(PduIdType CanTxPduId){
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(CanTxPduId >=  CANIF_CFG_MAX_TXPDUS){
    errorId = CANIF_E_PARAM_LPDU;
  }

  else if(CanIf_GetCtrlMode(CANIF_CFG_TX_CONTROLLER(CanTxPduId)) == CANIF_CS_UNINIT ){
    errorId = CANIF_E_UNINIT;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CANIF_CFG_TX_CONTROLLER(CanTxPduId))){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
    if(CanIf_GetCtrlMode(CANIF_CFG_TX_CONTROLLER(CanTxPduId)) == CANIF_CS_STARTED){
      if( (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(CanTxPduId)) == CANIF_GET_ONLINE) ||
             (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(CanTxPduId)) == CANIF_GET_TX_ONLINE)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
        || (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(CanTxPduId)) == CANIF_GET_ONLINE_WAKF)
        || (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(CanTxPduId)) == CANIF_GET_TX_ONLINE_WAKF)
#endif
         )
      {
#if((CANIF_PN_WU_TX_PDU_FILTER == STD_ON) || (CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON))
        CANIF_CHANNEL_CANTYPE_LOCAL
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
        controller = CANIF_CFG_TX_CONTROLLER(CanTxPduId);
#endif
#endif

#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)

        CanIf_SetPnWuTxPduFilterActive(CanIf_Controller_Value_Local, FALSE);
#endif

#if(CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON)

        CanIf_SetTxConfState(CanIf_Controller_Value_Local, CANIF_TX_RX_NOTIFICATION);
#endif

#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))
        {
          CanIf_AnyIdxType hth;
          hth = CANIF_CFG_TX_HTH(CanTxPduId);

          if(CANIF_CFG_MAILBOX_HASTXBUFFER(hth))
          {
            CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_2);

            (void)EcuabCanIf_QueueTxTreatment((CanIf_HwHandleType)hth);

            CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_2);
          }
        }
#endif

        CanIf_HlTxConfirmation(CanTxPduId);
      }
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(EcuabCanIf_TxConfirmation_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
}

#if  (CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)

CANIF_LOCAL_INLINE FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_RxIndicationSubJ1939DynAddr(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams){
  CANIF_CHANNEL_CANTYPE_LOCAL
  uint8 errorId = CANIF_E_NO_ERROR;
  Std_ReturnType retVal = E_OK;

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
  CanIf_Controller_Value_Local = CANIF_CFG_MAILBOX_CONTROLLER(rxSearchParams->eHrh);
#endif

  if( CANIF_CFG_CTRLJ1939DYNADDRSUPPORT(CanIf_Controller_Value_Local) != CANIF_J1939_DYN_ADDR_DISABLED ){
    uint8 da;
    uint8 sa;
    uint8 sa_t;

    if(((rxSearchParams->eCanId) & CANIF_EXT_CANID_MASK) == CANIF_EXT_CANID_MASK){
      if((((rxSearchParams->eCanId) & CANIF_J1939_DATA_PAGE_MASK) != CANIF_J1939_DATA_PAGE_MASK) && (((rxSearchParams->eCanId) & CANIF_J1939_PGN_MASK) != CANIF_J1939_AC_PGN))
      {
        CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_7);

        if(((rxSearchParams->eCanId) & CANIF_J1939_MIN_PDU2_MASK) < CANIF_J1939_MIN_PDU2_MASK)
        {
          da = (uint8)(((rxSearchParams->eCanId) & CANIF_J1939_DA_MASK) >> 8);
          da = CANIF_VAR_J1939RXADDR_LOOKUP(CanIf_Controller_Value_Local, da);
          if(da == CANIF_J1939_NULL_ADDR)
          {
            errorId = CANIF_E_INVALID_DA;
            retVal = E_NOT_OK;
          }
          (rxSearchParams->eCanId) = (Can_IdType)(((rxSearchParams->eCanId) & CANIF_J1939_INV_DA_MASK) | (((Can_IdType)da) << 8u));
        }

        sa = (uint8)((rxSearchParams->eCanId) & CANIF_J1939_SA_MASK);
        sa_t = CANIF_VAR_J1939RXADDR_LOOKUP(CanIf_Controller_Value_Local, sa);

        CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_7);

        if((sa == CANIF_J1939_BROADCAST_ADDR) || ((sa != CANIF_J1939_NULL_ADDR) && (sa_t == CANIF_J1939_NULL_ADDR)) || ((sa == CANIF_J1939_NULL_ADDR) && (((rxSearchParams->eCanId) & CANIF_J1939_PGN_MASK) != CANIF_J1939_RQST_PGN)))
        {
          errorId = CANIF_E_INVALID_SA;
          retVal = E_NOT_OK;
        }
        (rxSearchParams->eCanId) = (Can_IdType)(((rxSearchParams->eCanId) & CANIF_J1939_INV_SA_MASK) | sa_t);
      }
    }
#if(CANIF_J1939_DYN_ADDR_SUPPORT == CANIF_J1939_DYN_ADDR_MIXED_CANID)
    else{
      if( CANIF_CFG_CTRLJ1939DYNADDRSUPPORT(CanIf_Controller_Value_Local) == CANIF_J1939_DYN_ADDR_MIXED_CANID )
      {
        sa = (uint8)((rxSearchParams->eCanId) & CANIF_J1939_SA_MASK);
        sa = CANIF_VAR_J1939RXADDR_LOOKUP(CanIf_Controller_Value_Local, sa);
        if(sa == CANIF_J1939_NULL_ADDR)
        {
          errorId = CANIF_E_INVALID_SA;
          retVal = E_NOT_OK;
        }
        (rxSearchParams->eCanId) = (Can_IdType)(((rxSearchParams->eCanId) & CANIF_J1939_INV_SA_MASK) | sa);
      }
    }
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(EcuabCanIf_RxIndication_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}
#endif
#endif

#if(CANIF_SEARCH_ALGORITHM == CANIF_BINARY)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubBinarySearch(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams){
  PduIdType firstRxPduId;
  PduIdType lastRxPduId;
  PduIdType midRxPduId;
  PduIdType resultId;

  resultId = CanIf_RxPduHnd_INVALID;

  firstRxPduId = CANIF_CFG_MAILBOX_PDUIDFIRST(rxSearchParams->eHrh);
  lastRxPduId = rxSearchParams->eRxPduId;

  while(firstRxPduId <= lastRxPduId){
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)
    sint32 diffId;
#else
    sint16 diffId;
#endif

    midRxPduId = (PduIdType)((lastRxPduId + firstRxPduId) >> 1);

#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)
    diffId = (sint32)rxSearchParams->eCanId - (sint32)CANIF_CFG_RX_CANID(midRxPduId);
#else
    diffId = (sint16)rxSearchParams->eCanId - (sint16)CANIF_CFG_RX_CANID(midRxPduId);
#endif

    if(diffId == 0){
      resultId = midRxPduId;
      break;
    }
    else if(diffId > 0){
      lastRxPduId = midRxPduId;
    }
    else{
      firstRxPduId = midRxPduId;
    }

    if((lastRxPduId - firstRxPduId) < 2u){
      if(rxSearchParams->eCanId == CANIF_CFG_RX_CANID(firstRxPduId))
      {
        resultId = firstRxPduId;
        break;
      }
      else if(rxSearchParams->eCanId == CANIF_CFG_RX_CANID(lastRxPduId))
      {
        resultId = lastRxPduId;
        break;
      }
      else
      {
        break;
      }
    }
  }

  if(resultId != CanIf_RxPduHnd_INVALID){
#if(CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON)

    rxSearchParams->eRxPduIdMatch = resultId;
    EcuabCanIf_RxIndicationSubBinarySearchSubCheckMsgType(rxSearchParams);
#else

    rxSearchParams->eRxPduIdMatch = resultId;
    rxSearchParams->eContinueSearch = FALSE;
#endif
  }
}

#if(CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubBinarySearchSubCheckMsgType(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams){
  if((CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduIdMatch) == CANIF_MSG_TYPE_CAN) || (CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduIdMatch) == rxSearchParams->eRxMsgType)){
    rxSearchParams->eContinueSearch = FALSE;
  }
  else{
    if(rxSearchParams->eRxPduIdMatch < CANIF_CFG_MAILBOX_PDUIDLAST(rxSearchParams->eHrh)){
      if(rxSearchParams->eCanId == CANIF_CFG_RX_CANID(rxSearchParams->eRxPduIdMatch + 1u))
      {
        if(CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduIdMatch + 1u) == rxSearchParams->eRxMsgType)
        {
          rxSearchParams->eRxPduIdMatch = rxSearchParams->eRxPduIdMatch + 1u;
          rxSearchParams->eContinueSearch = FALSE;
        }
      }
    }

    if(rxSearchParams->eContinueSearch == TRUE){
      if(rxSearchParams->eRxPduIdMatch > CANIF_CFG_MAILBOX_PDUIDFIRST(rxSearchParams->eHrh) )
      {
        if(rxSearchParams->eCanId == CANIF_CFG_RX_CANID(rxSearchParams->eRxPduIdMatch - 1u))
        {
          if(CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduIdMatch - 1u) == rxSearchParams->eRxMsgType)
          {
            rxSearchParams->eRxPduIdMatch = rxSearchParams->eRxPduIdMatch - 1u;
            rxSearchParams->eContinueSearch = FALSE;
          }
        }
      }
    }

    if(rxSearchParams->eContinueSearch == TRUE){
      rxSearchParams->eRxPduIdMatch = CanIf_RxPduHnd_INVALID;
    }
  }
}
#endif
#endif

#if(CANIF_SEARCH_ALGORITHM == CANIF_DOUBLE_HASH)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubDoubleHashSearch(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams){
  Can_IdType hash1;
  Can_IdType hash2;
  uint16_least dhCalcRxPduId;
  uint8 errorId = CANIF_E_NO_ERROR;

  hash1 = (rxSearchParams->eCanId ^ (Can_IdType)CANIF_CFG_RXDHRANDOMNUMBER1(CANIF_CFG_MAILBOX_CONTROLLER(rxSearchParams->eHrh))) % (Can_IdType)CANIF_CFG_RXDHADJUSTCOUNT;
  hash2 = (rxSearchParams->eCanId ^ (Can_IdType)CANIF_CFG_RXDHRANDOMNUMBER2(CANIF_CFG_MAILBOX_CONTROLLER(rxSearchParams->eHrh))) % (Can_IdType)CANIF_CFG_RXDHADJUSTCOUNT;
  dhCalcRxPduId = (uint16_least)CANIF_CFG_RXDHADJUST(hash1) + (uint16_least)CANIF_CFG_RXDHADJUST(hash2);

  if(dhCalcRxPduId >= CANIF_CFG_MAX_RXPDUS){
    rxSearchParams->eRxPduId = (PduIdType)(dhCalcRxPduId - CANIF_CFG_MAX_RXPDUS);
  }
  else{
    rxSearchParams->eRxPduId = (PduIdType)(dhCalcRxPduId);
  }

  if(CANIF_CFG_RX_CANID(rxSearchParams->eRxPduId) == rxSearchParams->eCanId){
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

    if((rxSearchParams->eRxPduId >= CANIF_CFG_MAILBOX_PDUIDFIRST(rxSearchParams->eHrh)) && (rxSearchParams->eRxPduId <= CANIF_CFG_MAILBOX_PDUIDLAST(rxSearchParams->eHrh)))
#endif
    {
#if(CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON)
      if((CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduId) == CANIF_MSG_TYPE_CAN) || (CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduId) == rxSearchParams->eRxMsgType))
#endif
      {
        rxSearchParams->eRxPduIdMatch = rxSearchParams->eRxPduId;
        rxSearchParams->eContinueSearch = FALSE;
      }
#if(CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON)
      else
      {
        if(rxSearchParams->eRxPduId > CANIF_CFG_MAILBOX_PDUIDFIRST(rxSearchParams->eHrh))
        {
          rxSearchParams->eRxPduId--;
          if((CANIF_CFG_RX_CANID(rxSearchParams->eRxPduId) & (~CANIF_FDFLAG)) == rxSearchParams->eCanId)
          {
            if(CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduId) == rxSearchParams->eRxMsgType)
            {
              rxSearchParams->eRxPduIdMatch = rxSearchParams->eRxPduId;
              rxSearchParams->eContinueSearch = FALSE;
            }
          }
        }
      }
#endif
    }
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
    else{
      errorId = CANIF_E_INVALID_DOUBLEHASH_CALC;
    }
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(EcuabCanIf_RxIndication_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
}
#endif

#if(CANIF_SEARCH_ALGORITHM == CANIF_LINEAR)

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubLinearSearch(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams){
  while(((CANIF_CFG_RX_MASK(rxSearchParams->eRxPduId) & CANIF_RANGE_FLAG) != CANIF_RANGE_FLAG)){
    if(CANIF_CFG_RX_CANID(rxSearchParams->eRxPduId) == rxSearchParams->eCanId){
#if(CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON)
      if((CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduId)  == CANIF_MSG_TYPE_CAN) || (CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduId) == rxSearchParams->eRxMsgType))
#endif
      {
        rxSearchParams->eRxPduIdMatch = rxSearchParams->eRxPduId;
        rxSearchParams->eContinueSearch = FALSE;
        break;
      }
    }

    if((CANIF_CFG_RX_MASK(rxSearchParams->eRxPduId) & CANIF_STOP_FLAG) != 0u){
      rxSearchParams->eContinueSearch = FALSE;
      break;
    }
    else{
      rxSearchParams->eRxPduId--;
    }
  }
}
#endif

CANIF_LOCAL_INLINE FUNC(CanIf_NotifStatusType, CANIF_CODE) EcuabCanIf_RxIndicationSubReceptionPduMode(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams){
  CanIf_NotifStatusType retVal;
#if(CANIF_SET_PDU_RECEPTION_MODE_SUPPORT == STD_ON) || (CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON)
  retVal = CANIF_NO_NOTIFICATION;
#endif
#if(CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON)

  if((CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduId)  == CANIF_MSG_TYPE_CAN) || (CANIF_CFG_RX_MSGTYPE(rxSearchParams->eRxPduId) == rxSearchParams->eRxMsgType))
#endif
  {
#if(CANIF_SET_PDU_RECEPTION_MODE_SUPPORT == STD_ON)

    if(CANIF_CFG_RX_ISRECEPTIONMODEPDU(rxSearchParams->eRxPduId)){
      if(CANIF_VAR_GET_PDU_RECEPTION_MODE(CANIF_CFG_RX_PDURECEPTIONMODEIDX(rxSearchParams->eRxPduId)) == CANIF_RMT_RECEIVE_STOP)
#endif
      {
        rxSearchParams->eRxPduIdMatch = rxSearchParams->eRxPduId;
        retVal = CANIF_TX_RX_NOTIFICATION;
      }
#if(CANIF_SET_PDU_RECEPTION_MODE_SUPPORT == STD_ON)
    }
    else

    {
      rxSearchParams->eRxPduIdMatch = rxSearchParams->eRxPduId;
      retVal = CANIF_TX_RX_NOTIFICATION;
    }
#endif
  }
  return retVal;
}

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubRangeSearch(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams){
  while((CANIF_CFG_RX_MASK(rxSearchParams->eRxPduId) & (CANIF_STOP_FLAG | CANIF_RANGE_FLAG)) == CANIF_RANGE_FLAG){
    if((CANIF_CFG_RX_CANID(rxSearchParams->eRxPduId) & CANIF_MASKCODE_RANGE) == CANIF_MASKCODE_RANGE){
      if(CANIF_CFG_RX_CANID(rxSearchParams->eRxPduId) == ((rxSearchParams->eCanId & (CANIF_CFG_RX_MASK(rxSearchParams->eRxPduId) )) | CANIF_MASKCODE_RANGE ))
      {
        if(EcuabCanIf_RxIndicationSubReceptionPduMode(rxSearchParams) == CANIF_TX_RX_NOTIFICATION)
        {
          break;
        }
      }
    }
    else

    {
      if((rxSearchParams->eCanId >= CANIF_CFG_RX_CANID(rxSearchParams->eRxPduId)) && (rxSearchParams->eCanId <= ((CANIF_CFG_RX_MASK(rxSearchParams->eRxPduId) & ~(CANIF_STOP_FLAG | CANIF_RANGE_FLAG)))))
      {
        if(EcuabCanIf_RxIndicationSubReceptionPduMode(rxSearchParams) == CANIF_TX_RX_NOTIFICATION)
        {
          break;
        }
      }
    }
    rxSearchParams->eRxPduId--;
  }

  if((CANIF_CFG_RX_MASK(rxSearchParams->eRxPduId) & (CANIF_STOP_FLAG | CANIF_RANGE_FLAG)) == (CANIF_STOP_FLAG | CANIF_RANGE_FLAG)){
    if((CANIF_CFG_RX_CANID(rxSearchParams->eRxPduId) & CANIF_MASKCODE_RANGE) == CANIF_MASKCODE_RANGE){
      if(CANIF_CFG_RX_CANID(rxSearchParams->eRxPduId) == ((rxSearchParams->eCanId & CANIF_CFG_RX_MASK(rxSearchParams->eRxPduId)) | CANIF_MASKCODE_RANGE ))
      {
        (void)EcuabCanIf_RxIndicationSubReceptionPduMode(rxSearchParams);
      }
    }
    else

    {
      if((rxSearchParams->eCanId >= CANIF_CFG_RX_CANID(rxSearchParams->eRxPduId)) && (rxSearchParams->eCanId <= ((CANIF_CFG_RX_MASK(rxSearchParams->eRxPduId) & ~(CANIF_STOP_FLAG | CANIF_RANGE_FLAG)))))
      {
        (void)EcuabCanIf_RxIndicationSubReceptionPduMode(rxSearchParams);
      }
    }
  }
}

#if((CANIF_WAKEUP_VALIDATION == STD_ON) && (CANIF_WAKEUP_VALID_ALL_RX_MSGS == STD_ON))

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubWakeupValidation(P2CONST(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams){
  CANIF_CHANNEL_CANTYPE_LOCAL
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)

  controller = CANIF_CFG_MAILBOX_CONTROLLER(rxSearchParams->eHrh);
#else
  CANIF_DUMMY_STATEMENT(rxSearchParams);
#endif
  if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_STARTED){
    CanIf_SetWakeUpValidationState(CanIf_Controller_Value_Local, CANIF_WUVALIDATION_DETECTED);
  }
}
#endif

CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationSubBasicCan(P2VAR(CanIf_RxSearchParamsType, AUTOMATIC, AUTOMATIC) rxSearchParams){
  rxSearchParams->eContinueSearch = TRUE;

  if((CANIF_CFG_RX_MASK(rxSearchParams->eRxPduId) & CANIF_RANGE_FLAG) != CANIF_RANGE_FLAG){
#if(CANIF_SEARCH_ALGORITHM == CANIF_BINARY)

    EcuabCanIf_RxIndicationSubBinarySearch(rxSearchParams);
#endif

#if(CANIF_SEARCH_ALGORITHM == CANIF_DOUBLE_HASH)

    EcuabCanIf_RxIndicationSubDoubleHashSearch(rxSearchParams);
#endif

#if(CANIF_SEARCH_ALGORITHM == CANIF_LINEAR)

    EcuabCanIf_RxIndicationSubLinearSearch(rxSearchParams);
#endif
#if(CANIF_SET_PDU_RECEPTION_MODE_SUPPORT == STD_ON)

    if(rxSearchParams->eRxPduIdMatch != CanIf_RxPduHnd_INVALID){
      if(CANIF_CFG_RX_ISRECEPTIONMODEPDU(rxSearchParams->eRxPduIdMatch))
      {
        if(CANIF_VAR_GET_PDU_RECEPTION_MODE(CANIF_CFG_RX_PDURECEPTIONMODEIDX(rxSearchParams->eRxPduIdMatch)) == CANIF_RMT_IGNORE_CONTINUE)
        {
          rxSearchParams->eRxPduIdMatch = CanIf_RxPduHnd_INVALID;

          if((CANIF_CFG_RX_MASK(CANIF_CFG_MAILBOX_PDUIDFIRST(rxSearchParams->eHrh)) & CANIF_STOP_FLAG) == 0u)
          {
            rxSearchParams->eContinueSearch = TRUE;
          }
        }
      }
    }
#endif

#if(CANIF_SEARCH_ALGORITHM != CANIF_LINEAR) || (CANIF_SET_PDU_RECEPTION_MODE_SUPPORT == STD_ON)

    rxSearchParams->eRxPduId = CANIF_CFG_MAILBOX_PDUIDFIRST(rxSearchParams->eHrh);
    if((CANIF_CFG_RX_MASK(rxSearchParams->eRxPduId) & CANIF_STOP_FLAG) == 0u){
      rxSearchParams->eRxPduId--;
    }
    else{
      rxSearchParams->eContinueSearch = FALSE;
    }
#endif
  }

  if(rxSearchParams->eContinueSearch == TRUE){
    EcuabCanIf_RxIndicationSubRangeSearch(rxSearchParams);
  }
}

FUNC(void, CANIF_CODE) EcuabCanIf_RxIndicationAsr403(CanIf_HwHandleType Hrh, Can_IdType CanId, uint8 CanDlc, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR)CanSduPtr){
  CanIf_RxSearchParamsType rxSearchParams;
#if(CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)
  Std_ReturnType j1939DynAddrRetVal;
#endif
#endif
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(CanSduPtr == NULL_PTR){
    errorId = CANIF_E_PARAM_POINTER;
  }

  else if(CanDlc > CANIF_CFG_RX_MAXVALIDRXDLC){
    errorId = CANIF_E_PARAM_DLC;
  }
#if(CANIF_EXTENDEDID_SUPPORT != STD_ON)

  else if((CanId & (~CANIF_FDFLAG)) > 0x7FFu){
    errorId = CANIF_E_PARAM_CANID;
  }
#endif

  else if(Hrh >= CANIF_CFG_MAX_MAILBOXES){
    errorId = CANIF_E_PARAM_HRH;
  }
  else
#endif
  {
#if(CANIF_BUS_MIRRORING_SUPPORT == STD_ON)

    if(CanIf_IsMirroringEnabled(CANIF_CFG_MAILBOX_CONTROLLER(Hrh))){
      Mirror_ReportCanFrame(CANIF_CFG_MAILBOX_CONTROLLER(Hrh), CanId, CanDlc, CanSduPtr);
    }
#endif

#if(CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON) || (CANIF_META_DATA_RX_SUPPORT == STD_ON)

    if((CanId & CANIF_FDFLAG) == CANIF_FDFLAG){
      rxSearchParams.eRxMsgType = CANIF_MSG_TYPE_FD_CAN;
    }
    else{
      rxSearchParams.eRxMsgType = CANIF_MSG_TYPE_NO_FD_CAN;
    }
#endif

    CanId = (CanId & (~CANIF_FDFLAG));
    rxSearchParams.eCanId = CanId;
    rxSearchParams.eHrh = Hrh;

#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)

    CanIf_SetPnWuTxPduFilterActive(CANIF_CFG_MAILBOX_CONTROLLER(Hrh), FALSE);
#endif

#if((CANIF_WAKEUP_VALIDATION == STD_ON) && (CANIF_WAKEUP_VALID_ALL_RX_MSGS == STD_ON))

    EcuabCanIf_RxIndicationSubWakeupValidation(&rxSearchParams);
#endif

#if(CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)

    j1939DynAddrRetVal = EcuabCanIf_RxIndicationSubJ1939DynAddr(&rxSearchParams);
    if(j1939DynAddrRetVal == E_OK)
#endif
#endif
    {
      if(CANIF_CFG_MAX_RXPDUS != 0u)
      {
        rxSearchParams.eRxPduId = CANIF_CFG_MAILBOX_PDUIDLAST(Hrh);

        if(rxSearchParams.eRxPduId != CanIf_RxPduHnd_INVALID)
        {
          rxSearchParams.eRxPduIdMatch = CanIf_RxPduHnd_INVALID;

          if(CANIF_CFG_MAILBOX_MAILBOXTYPE(Hrh) == CANIF_RxFullCANMailbox)
          {
            (void)EcuabCanIf_RxIndicationSubReceptionPduMode(&rxSearchParams);
          }
          else if(CANIF_CFG_MAILBOX_MAILBOXTYPE(Hrh) == CANIF_RxBasicCANMailbox)

          {
            EcuabCanIf_RxIndicationSubBasicCan(&rxSearchParams);
          }
          else
          {
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
            errorId = CANIF_E_CONFIG;
#endif
          }

          if(rxSearchParams.eRxPduIdMatch != CanIf_RxPduHnd_INVALID)
          {
#if(CANIF_DATA_CHECKSUM_RX_SUPPORT == STD_ON)
            Std_ReturnType localRetVal;

            if(CANIF_CFG_RX_ISDATACHECKSUMPDU(rxSearchParams.eRxPduIdMatch))
            {
#if((CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME) || (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))

              PduIdType CanIfRxPduId = CANIF_CFG_INTRXPDUID2EXTRXPDUID(rxSearchParams.eRxPduIdMatch);
#else
              PduIdType CanIfRxPduId = rxSearchParams.eRxPduIdMatch;
#endif

              localRetVal = EcuabCanIf_RxIndicationSubDataChecksumRxVerify(CanIfRxPduId, CanId, CanDlc, CanSduPtr);
            }
            else
            {
              localRetVal = E_OK;
            }

            if(localRetVal == E_OK)
#endif
            {
#if(CANIF_META_DATA_RX_SUPPORT == STD_ON)

              if(rxSearchParams.eRxMsgType == CANIF_MSG_TYPE_FD_CAN)
              {
                rxSearchParams.eCanId |= CANIF_FDFLAG;
              }
#endif

              CanIf_Indirect_HlIndication(Hrh, rxSearchParams.eRxPduIdMatch, CanSduPtr, CanDlc, rxSearchParams.eCanId);
            }
          }
        }
      }
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(EcuabCanIf_RxIndication_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
}

#if(CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON) || (CANIF_RX_INDICATION_TYPE_IV_IS_USED == STD_ON)
CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) CanIf_HlIndicationSubULCall(PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc, Can_IdType CanId)
#else
CANIF_LOCAL_INLINE FUNC(void, CANIF_CODE) CanIf_HlIndicationSubULCall(PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc )
#endif
{
  CanIf_RxIndFctListIdxType index;
  index = CANIF_CFG_RX_RXINDICATION(PduId);

#if(CANIF_RX_INDICATION_TYPE_I_IS_USED == STD_ON)
  if(CANIF_CFG_RXINDICATION_FUNCTIONLAYOUT(index) == CanIf_SimpleRxIndicationLayout){
    CanIf_SimpleRxIndicationFctType rxIndicationFct;
    rxIndicationFct = CANIF_CFG_RXINDICATION_FUNCTION(index).eSimpleRxIndicationType;
    if(rxIndicationFct != NULL_PTR){
      rxIndicationFct(CANIF_CFG_RX_UPPERPDUID(PduId), (P2CONST(uint8, AUTOMATIC, CANIF_UL_STANDARD_VAR))CanSduPtr);
    }
  }
  else
#endif

#if(CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON)
  if(CANIF_CFG_RXINDICATION_FUNCTIONLAYOUT(index) == CanIf_NmOsekRxIndicationLayout){
    CanIf_NmOsekRxIndicationFctType rxIndicationFct;
    rxIndicationFct = CANIF_CFG_RXINDICATION_FUNCTION(index).eNmOsekRxIndicationType;
    if(rxIndicationFct != NULL_PTR){
      rxIndicationFct(CANIF_CFG_RX_UPPERPDUID(PduId), (P2CONST(uint8, AUTOMATIC, CANIF_UL_OSEKNM_VAR))CanSduPtr, CanId);
    }
  }
  else
#endif

#if(CANIF_RX_INDICATION_TYPE_IV_IS_USED == STD_ON)
  if(CANIF_CFG_RXINDICATION_FUNCTIONLAYOUT(index) == CanIf_CddRxIndicationLayout){
    CanIf_CddRxIndicationFctType rxIndicationFct;
    PduInfoType pduinfo;

    pduinfo.SduDataPtr = (P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA))CanSduPtr;

    pduinfo.SduLength = CanDlc;

    rxIndicationFct = CANIF_CFG_RXINDICATION_FUNCTION(index).eCddRxIndicationType;
    if(rxIndicationFct != NULL_PTR){
      rxIndicationFct(CANIF_CFG_RX_UPPERPDUID(PduId), (P2CONST(PduInfoType, AUTOMATIC, CANIF_UL_ADVANCED_VAR))&pduinfo, CanId);
    }
  }
  else
#endif

  if(CANIF_CFG_RXINDICATION_FUNCTIONLAYOUT(index) == CanIf_AdvancedRxIndicationLayout){
    CanIf_AdvancedRxIndicationFctType rxIndicationFct;
    PduInfoType pduinfo;

    pduinfo.SduDataPtr = (P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA))CanSduPtr;

    pduinfo.SduLength = CanDlc;

    rxIndicationFct = CANIF_CFG_RXINDICATION_FUNCTION(index).eAdvancedRxIndicationType;
    if(rxIndicationFct != (CanIf_AdvancedRxIndicationFctType)NULL_PTR){
      rxIndicationFct(CANIF_CFG_RX_UPPERPDUID(PduId), (P2CONST(PduInfoType, AUTOMATIC, CANIF_UL_ADVANCED_VAR))&pduinfo);
    }
  }
}

#if((CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON) || (CANIF_META_DATA_RX_SUPPORT == STD_ON) || (CANIF_RX_INDICATION_TYPE_IV_IS_USED == STD_ON))

CANIF_LOCAL FUNC(void, CANIF_CODE) CanIf_HlIndication(CanIf_HwHandleType  Hrh, PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc, Can_IdType CanId)
#else

CANIF_LOCAL FUNC(void, CANIF_CODE) CanIf_HlIndication(CanIf_HwHandleType  Hrh, PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc)
#endif
{
  uint8 errorId = CANIF_E_NO_ERROR;
  CANIF_CHANNEL_CANTYPE_LOCAL

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
  CANIF_DUMMY_STATEMENT(Hrh);
#else

  controller = CANIF_CFG_MAILBOX_CONTROLLER(Hrh);
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)

  if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_CONFIG;
  }
  else
#endif

  if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif
  {
    if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_STARTED){
#if(CANIF_WAKEUP_VALIDATION == STD_ON)
#if(CANIF_WAKEUP_VALID_ALL_RX_MSGS != STD_ON)

#if(CANIF_WAKEUP_VALID_ONLY_NM_RX_MSGS == STD_ON)
      if((uint8)(CANIF_CFG_RX_DLC(PduId) & CANIF_WU_VALIDATION_NM_FLAG_GET) != 0u)
#endif
      {
        CanIf_SetWakeUpValidationState(CanIf_Controller_Value_Local, CANIF_WUVALIDATION_DETECTED);
      }
#endif
#endif

      if( (CanIf_GetChannelMode(CanIf_Controller_Value_Local) == CANIF_GET_ONLINE) ||
           (CanIf_GetChannelMode(CanIf_Controller_Value_Local) == CANIF_GET_RX_ONLINE) ||
           (CanIf_GetChannelMode(CanIf_Controller_Value_Local) == CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
        || (CanIf_GetChannelMode(CanIf_Controller_Value_Local) == CANIF_GET_ONLINE_WAKF)
#endif
         )
      {
#if(CANIF_DLC_CHECK == STD_ON)

        if(CanDlc < (uint8)(CANIF_CFG_RX_DLC(PduId) & CANIF_WU_VALIDATION_NM_MASK_OUT) )
        {
          errorId = CANIF_E_INVALID_DLC;
        }
        else

#endif
        {
#if(CANIF_META_DATA_RX_SUPPORT == STD_ON)
          uint8 CanSduLocal[CANIF_CFG_MAXRXDLC_PLUS_MAXMETADATA];
          uint8_least i;
          uint8_least j;
          if((CANIF_CFG_RX_RXMETADATALENGTH(PduId) > 0u) && ((CanDlc + CANIF_CFG_RX_RXMETADATALENGTH(PduId)) > CANIF_CFG_MAXRXDLC_PLUS_MAXMETADATA))
          {
            errorId = CANIF_E_INVALID_DLC_METADATA;
          }
          else
          {
            if(CANIF_CFG_RX_RXMETADATALENGTH(PduId) > 0u)
            {
#if(CANIF_USES_VSTDLIB_COPY == STD_ON)
              VStdMemCpyRamToRam(CanSduLocal, CanSduPtr, CanDlc);
              i = CanDlc;
#else
              for(i = 0; i < CanDlc; i++)
              {
                CanSduLocal[i] = CanSduPtr[i];
              }
#endif
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)
              {
                Can_IdType CanIdLocal;
                CanIdLocal = CanId;

                for(j = 0; j < CANIF_CFG_RX_RXMETADATALENGTH(PduId); j++)
                {
                  CanSduLocal[i] = (uint8)(CanIdLocal & 0x000000FFu);
                  i++;
                  CanIdLocal = CanIdLocal >> 8;
                }
              }
#else
              {
                Can_IdType CanIdLocal;
                uint8_least shiftCounter;
                CanIdLocal = CanId;
                shiftCounter = 0;
                for(j = 0; j < CANIF_CFG_RX_RXMETADATALENGTH(PduId); j++)
                {
                  if(shiftCounter < 2u)
                  {
                    CanSduLocal[i] = (uint8)(CanIdLocal & 0x00FFu);
                    CanIdLocal = CanIdLocal >> 8u;
                    shiftCounter++;
                  }
                  else
                  {
                    CanSduLocal[i] = 0x00;
                  }
                  i++;
                }
              }
#endif
#if(CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)

              if((CanId & CANIF_J1939_PGN_MASK) == CANIF_J1939_ACKM_PGN)
              {
                uint8 ackAddr = CANIF_VAR_J1939RXADDR_LOOKUP(CanIf_Controller_Value_Local, CanSduPtr[CANIF_J1939_ACKM_ACKADDR_POS]);
                if(ackAddr == CANIF_J1939_NULL_ADDR)
                {
                  errorId = CANIF_E_INVALID_DA;
                }
                CanSduLocal[CANIF_J1939_ACKM_ACKADDR_POS] = ackAddr;
              }
#endif
#endif
              CanSduPtr =  CanSduLocal;
              CanDlc = (uint8)i;
            }
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
            if( CANIF_CFG_RX_RXINDICATION(PduId) >= CANIF_CFG_MAX_RXINDICATIONS )
            {
              errorId = CANIF_E_CONFIG;
            }
            else
#endif
            {
#if(CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON) || (CANIF_RX_INDICATION_TYPE_IV_IS_USED == STD_ON)
#if(CANIF_META_DATA_RX_SUPPORT == STD_ON)

              CanId = (CanId & (~CANIF_FDFLAG));
#endif
              CanIf_HlIndicationSubULCall(PduId, CanSduPtr, CanDlc, CanId);
#else
              CanIf_HlIndicationSubULCall(PduId, CanSduPtr, CanDlc);
#endif
            }
#if(CANIF_META_DATA_RX_SUPPORT == STD_ON)
          }

#endif
        }
      }
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(EcuabCanIf_RxIndication_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

}

FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(uint8 ControllerId){
  uint8 errorId = CANIF_E_NO_ERROR;
  Type_CfgEcuabCanIf_FctNotificationBusOff busoffnotificationFct = CANIF_CFG_BUSOFFNOTIFICATION();

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLER;
  }
  else
#endif
  {
    if(CanIf_GetCtrlMode(CanIf_Controller_Value) != CANIF_CS_UNINIT){
      (void)CanIf_SetPduMode(CanIf_Controller_Value, CANIF_SET_TX_OFFLINE);

      CanIf_SetCtrlMode(CanIf_Controller_Value, CANIF_CS_STOPPED);

#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

      CanIf_ClearQueue(CANIF_CHANNEL_CANPARA_ONLY);
#endif

#if(CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON)

      CanIf_SetTxConfState(CanIf_Controller_Value, CANIF_NO_NOTIFICATION);
#endif

      if(busoffnotificationFct != (Type_CfgEcuabCanIf_FctNotificationBusOff)NULL_PTR)
      {
        busoffnotificationFct(CanIf_Controller_Value);
      }
    }
    else{
      errorId = CANIF_E_UNINIT;
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CONTROLLERBUSOFF_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
    CANIF_DUMMY_STATEMENT(ControllerId);
#endif
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(uint8 ControllerId, CanIf_PduSetModeType PduModeRequest){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }

  else if(PduModeRequest >= CANIF_NO_MODE_PDU_SET_MODE_TYPE_END){
    errorId = CANIF_E_PARAM_PDU_MODE;
  }
  else
#endif
  {
    if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_STARTED){
      retval = E_OK;
      CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_3);

      if(CanIfState[CanIf_GetChannelMode(CanIf_Controller_Value)][PduModeRequest] != CANIF_NOP)
      {
        switch(PduModeRequest)
        {
          case CANIF_SET_OFFLINE:
          case CANIF_SET_TX_OFFLINE:
          case CANIF_SET_TX_OFFLINE_ACTIVE:
            switch(CanIf_GetChannelMode(CanIf_Controller_Value))
            {
              case CANIF_GET_TX_ONLINE:
              case CANIF_GET_ONLINE:

#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
              case CANIF_GET_TX_ONLINE_WAKF:
              case CANIF_GET_ONLINE_WAKF:
#endif
#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

                CanIf_ClearQueue(CANIF_CHANNEL_CANPARA_ONLY);
#endif
                break;
              default:
                break;
            }

#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
            CanIf_SetPnWuTxPduFilterActive(CanIf_Controller_Value, FALSE);
#endif
            break;
          case CANIF_SET_ONLINE:
          case CANIF_SET_TX_ONLINE:
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
            CanIf_SetPnWuTxPduFilterActive(CanIf_Controller_Value, FALSE);
#endif
            break;
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
          case CANIF_SET_ONLINE_WAKF:
          case CANIF_SET_TX_ONLINE_WAKF:

            if(CANIF_CFG_ISFEATUREPNWUTXPDUFILTERENABLED(CanIf_Controller_Value))
            {
              CanIf_SetPnWuTxPduFilterActive(CanIf_Controller_Value, TRUE);
            }
            break;
#endif
          default:
            break;
        }

        CanIf_SetChannelMode(CanIf_Controller_Value, (CanIf_PduGetModeType)CanIfState[CanIf_GetChannelMode(CanIf_Controller_Value)][PduModeRequest]);
      }
      CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_3);
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_SETPDUMODE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

#if((CANIF_ONE_CONTROLLER_OPTIMIZATION==STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
  return retval;
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode(uint8 ControllerId, P2VAR(CanIf_PduGetModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) PduModePtr){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }

  else if(PduModePtr == NULL_PTR){
    errorId = CANIF_E_PARAM_POINTER;
  }
  else
#endif
  {
    *PduModePtr = CanIf_GetChannelMode(CanIf_Controller_Value);
    retval = E_OK;
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_GETPDUMODE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
  return retval;
}

#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

CANIF_LOCAL FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_QueueTxTransmit( PduIdType PduId){
  Can_PduType localPdu;
  Can_ReturnType txResult;
  Std_ReturnType retval;
  CanIf_AnyIdxType hth;

  uint8 errorId = CANIF_E_NO_ERROR;

#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
  CanIf_AnyIdxType txBufferCfgIdx;
  CanIf_AnyIdxType txFifoQueueBaseStartIdx;
  CanIf_AnyIdxType txBufferFifoBaseIdx;
#endif

  retval = E_NOT_OK;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

  if(PduId >= CANIF_CFG_MAX_TXPDUS){
    errorId = CANIF_E_INVALID_TXPDUID;
  }
  else
#endif

  {
    hth = CANIF_CFG_TX_HTH(PduId);
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
    txBufferCfgIdx = CANIF_CFG_MAILBOX_TXBUFFERIDX(hth);
#endif

    switch(CANIF_CFG_MAILBOX_TXBUFFERHANDLINGTYPE(hth)){
#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)
      case CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID:

#if((CANIF_SETDYNAMICTXID_API == STD_ON) || (CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED) || (CANIF_META_DATA_TX_SUPPORT == STD_ON))
        (localPdu).id = CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(CANIF_CFG_TX_QUEUEINDEX(PduId), eQueueParams.eBaseParams.eCanId);
#else
        (localPdu).id = CANIF_CFG_TX_CANID(PduId);
#endif
        (localPdu).length = (uint8)CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(CANIF_CFG_TX_QUEUEINDEX(PduId), eQueueParams.eBaseParams.eSduLength);
#if(CANIF_STATIC_FD_TXQUEUE == STD_ON)
        (localPdu).sdu = CANIF_ADDR_VAR_TXBUFFERPRIOBYCANID_STATFDQUEUE_QUEUEDATA(CANIF_CFG_TXBUFFERPRIOBYCANID_STATFDQUEUE_DATASTARTIDX(PduId));
#else
        (localPdu).sdu = CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(CANIF_CFG_TX_QUEUEINDEX(PduId), eQueueParams.eSdu);
#endif
        (localPdu).swPduHandle = (PduId);
        break;
#endif
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
      case CANIF_TXBUFFER_HANDLINGTYPE_FIFO:
        txBufferFifoBaseIdx = CANIF_CFG_TXBUFFERFIFO_BUFFERBASEIDX(txBufferCfgIdx);
        txFifoQueueBaseStartIdx = CANIF_CFG_TXBUFFERFIFO_QUEUEBASESTARTIDX(txBufferCfgIdx);

#if((CANIF_SETDYNAMICTXID_API == STD_ON) || (CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED) || (CANIF_META_DATA_TX_SUPPORT == STD_ON))
        (localPdu).id = CANIF_VAR_TXBUFFERFIFO_QUEUEBASE( (CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx  ) + txFifoQueueBaseStartIdx ), eBaseParams.eCanId );
#else
        (localPdu).id = CANIF_CFG_TX_CANID(PduId);
#endif
        (localPdu).length = CANIF_VAR_TXBUFFERFIFO_QUEUEBASE( (CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx  ) + txFifoQueueBaseStartIdx ), eBaseParams.eSduLength );
        (localPdu).sdu = CANIF_ADDR_VAR_TXBUFFERFIFO_QUEUEDATA((CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx) * (uint32)CANIF_CFG_TXBUFFERFIFO_SIZEOFONEPAYLOADEL(txBufferCfgIdx)) + CANIF_CFG_TXBUFFFERFIFO_QUEUEDATASTARTIDX(txBufferCfgIdx));
        (localPdu).swPduHandle = (PduId);
          break;
#endif
      default:
        break;
    }

#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    {
      CanIf_Can_WriteFctType canWriteFct;
      Can_HwHandleType canDrvHth;

      canWriteFct = CanIf_GetCan_WriteFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CANIF_CFG_TX_CONTROLLER(PduId)));
      canDrvHth = (Can_HwHandleType)(hth - CANIF_CFG_MULTIPLECANDRV_HXHOFFSET(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CANIF_CFG_TX_CONTROLLER(PduId))));

      txResult = canWriteFct(canDrvHth, &localPdu);
    }
#else
    txResult = Can_Write((CanIf_HwHandleType)hth, &localPdu);
#endif

    if(txResult == CAN_OK){
      switch(CANIF_CFG_MAILBOX_TXBUFFERHANDLINGTYPE(hth))
      {
#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)
        case CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID:
          (void)CanIf_ClearPrioByCanIdTxPduAsQueued(PduId);
          break;
#endif

#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
        case CANIF_TXBUFFER_HANDLINGTYPE_FIFO:
          txBufferFifoBaseIdx = CANIF_CFG_TXBUFFERFIFO_BUFFERBASEIDX(txBufferCfgIdx);
#if(CANIF_CANCEL_SUPPORT_API == STD_ON)
          CANIF_VAR_TXBUFFERFIFO_QUEUEBASE(( CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx)+CANIF_CFG_TXBUFFERFIFO_QUEUEBASESTARTIDX( txBufferCfgIdx)), eQueued) = 0;
          CANIF_VAR_SET_TXBUFFERFIFO_QUEUEIDX2FIFOEL(CANIF_CFG_TX_QUEUEINDEX(PduId), CANIF_NO_ENTRY_IN_TX_FIFO);
#endif
          CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx)++;
          if(CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx) == CANIF_CFG_TXBUFFERFIFO_QUEUESIZE(txBufferCfgIdx))
          {
            CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx) = 0;
          }
          CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eQueueCounter)--;
          break;
#endif
        default:
          break;
      }
      retval = E_OK;
    }
    else if(txResult == CAN_BUSY){
      retval = E_OK;
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CANCELTRANSMIT_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

CANIF_LOCAL FUNC(Std_ReturnType, CANIF_CODE) EcuabCanIf_QueueTxTreatment(CanIf_HwHandleType hth){
#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)
#if(CANIF_BITQUEUE == STD_ON)

  sint16_least queueElementIdx;

  sint16_least queueEndElementIdx;
  sint8_least elementBitIdx;
  EcuabCanIf_QueueTxFlagType  elem;
  PduIdType PduId;
#else
  CanIf_AnyIdxType idx2MappedTxPdus;
#endif
  CanIf_AnyIdxType txBufferPrioByCanIdBaseIdx;
#endif
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
  CanIf_AnyIdxType txBufferFifoBaseIdx;
  CanIf_AnyIdxType txBufferFifoQueueBaseStartIdx;
  CanIf_TxBufferSizeType txBufferFifoActReadIdx;
#endif
  Std_ReturnType retval;
  CanIf_AnyIdxType txBufferCfgIdx;

  retval = E_NOT_OK;

  txBufferCfgIdx = CANIF_CFG_MAILBOX_TXBUFFERIDX(hth);

  switch(CANIF_CFG_MAILBOX_TXBUFFERHANDLINGTYPE(hth)){
#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)
    case CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID:
#if(CANIF_BITQUEUE == STD_ON)

      txBufferPrioByCanIdBaseIdx = CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_BUFFERBASEIDX(txBufferCfgIdx);

      if(CanIf_GetTxQueueCounter(txBufferPrioByCanIdBaseIdx) != 0u)
      {
        queueEndElementIdx = (sint16_least)(CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUESTARTIDX(txBufferCfgIdx));

        for(queueElementIdx = (((sint16_least)CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUESTOPIDX(txBufferCfgIdx)) - (sint16_least)1); queueElementIdx >= queueEndElementIdx; queueElementIdx--)
        {
          elem = CANIF_VAR_TXBUFFERPRIOBYCANIDBITQUEUE_QUEUEFLAGS((uint16_least)queueElementIdx);
          if(elem != (EcuabCanIf_QueueTxFlagType)0)
          {
            for(elementBitIdx = (sint8_least)elemStartBitIdx; elementBitIdx >= (sint8_least)0; elementBitIdx--)
            {
              if( ( elem & CanShiftLookUp[elementBitIdx] ) != (EcuabCanIf_QueueTxFlagType)0)
              {
                PduId = ((((PduIdType)queueElementIdx - (PduIdType)queueEndElementIdx) << kCanTxQueueShift) + (PduIdType)elementBitIdx) + (PduIdType)CANIF_CFG_TXBUFFERPRIOBYCANIDBITQUEUE_BITPOS2TXPDUIDOFFSET(txBufferCfgIdx);

                retval = EcuabCanIf_QueueTxTransmit(PduId);
                break;
              }
            }

            break;
          }
        }
      }
#else

      txBufferPrioByCanIdBaseIdx = CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_BUFFERBASEIDX(txBufferCfgIdx);

      if(CanIf_GetTxQueueCounter(txBufferPrioByCanIdBaseIdx) != 0u)
      {
        for(idx2MappedTxPdus = ((CanIf_AnyIdxType)CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_STOPIDX2MAPPEDTXPDUS(txBufferCfgIdx)-1u); idx2MappedTxPdus >= CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_STARTIDX2MAPPEDTXPDUS(txBufferCfgIdx); idx2MappedTxPdus--)
        {
          CanIf_AnyIdxType TxPduId;
          TxPduId = CANIF_CFG_TXBUFFERPRIOBYCANIDBYTEQUEUE_MAPPEDTXPDUS(idx2MappedTxPdus);

          if(CANIF_VAR_TXBUFFERPRIOBYCANID_QUEUE(CANIF_CFG_TX_QUEUEINDEX(TxPduId), eQueued) != 0u)
          {
            retval = EcuabCanIf_QueueTxTransmit((PduIdType)TxPduId);
            break;
          }
        }
      }
#endif
      break;
#endif
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)
    case CANIF_TXBUFFER_HANDLINGTYPE_FIFO:

      txBufferFifoBaseIdx = CANIF_CFG_TXBUFFERFIFO_BUFFERBASEIDX(txBufferCfgIdx);
      txBufferFifoQueueBaseStartIdx = CANIF_CFG_TXBUFFERFIFO_QUEUEBASESTARTIDX(txBufferCfgIdx);

      if(CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eQueueCounter) != 0u)
      {
#if(CANIF_CANCEL_SUPPORT_API == STD_ON)

        txBufferFifoActReadIdx = CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx);

        while((CANIF_VAR_TXBUFFERFIFO_QUEUEBASE((txBufferFifoActReadIdx + txBufferFifoQueueBaseStartIdx), eQueued) == 0u) && ((CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eQueueCounter)) != 0u))
        {
          CANIF_VAR_TXBUFFERFIFO_BUFFERBASE( txBufferFifoBaseIdx, eReadIdx) ++;

          if(CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx) == CANIF_CFG_TXBUFFERFIFO_QUEUESIZE(txBufferCfgIdx))
          {
            CANIF_VAR_TXBUFFERFIFO_BUFFERBASE( txBufferFifoBaseIdx, eReadIdx) = 0;
          }

          CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eQueueCounter)--;

          txBufferFifoActReadIdx = CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx);
        }

        if(CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eQueueCounter) != 0u)
#endif
        {
          txBufferFifoActReadIdx = CANIF_VAR_TXBUFFERFIFO_BUFFERBASE(txBufferFifoBaseIdx, eReadIdx);
          retval = EcuabCanIf_QueueTxTransmit(CANIF_VAR_TXBUFFERFIFO_QUEUEBASE((txBufferFifoActReadIdx + txBufferFifoQueueBaseStartIdx), eTxPduId));
        }
      }
      break;
#endif
    default:
      break;
  }
  return retval;
}
#endif

#if(CANIF_VERSION_INFO_API == STD_ON)

FUNC(void, CANIF_CODE) CanIf_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_VAR) VersionInfo){
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)

  if(VersionInfo == NULL_PTR){
    errorId = CANIF_E_PARAM_POINTER;
  }
  else
#endif
  {
    VersionInfo->vendorID         = CANIF_VENDOR_ID;
    VersionInfo->moduleID         = CANIF_MODULE_ID;
    VersionInfo->sw_major_version = CANIF_SW_MAJOR_VERSION;
    VersionInfo->sw_minor_version = CANIF_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = CANIF_SW_PATCH_VERSION;
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_GETVERSIONINFO_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
}
#endif

FUNC(void, CANIF_CODE) infEcuabCanIfSwcApplEcuM_InitFunctionMemory(void){
  CANIF_CHANNEL_CANTYPE_LOCAL

#if(CANIF_USE_INIT_POINTER == STD_ON)

  CanIf_ConfigDataPtr = NULL_PTR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
  CanIf_SystemInit = FALSE;
#endif
#endif

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
  for(controller = 0; controller < (sizeof(EcuabCanIf_StatesCtrl) / sizeof(EcuabCanIf_StatesCtrlType)); controller++)
#endif
  {
    CanIf_SetCtrlMode(CanIf_Controller_Value_Local, CANIF_CS_UNINIT);
  }
}

#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_OFF)
#if(EcuabCanIf_Transmit_CANCELLATION == STD_ON)

FUNC(void, CANIF_CODE) CanIf_CancelTxConfirmation(PduIdType CanTxPduId, P2CONST(Can_PduType, AUTOMATIC, CANIF_CBK_DRV_VAR) PduInfoPtr){
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#     if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#     endif

  if(PduInfoPtr == NULL_PTR){
    errorId = CANIF_E_PARAM_POINTER;
  }

  else if(PduInfoPtr->swPduHandle >= CANIF_CFG_MAX_TXPDUS){
    errorId = CANIF_E_PARAM_LPDU;
  }

  else if(CanIf_GetCtrlMode(CANIF_CFG_TX_CONTROLLER(PduInfoPtr->swPduHandle)) == CANIF_CS_UNINIT ){
    errorId = CANIF_E_UNINIT;
  }
#     if((CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON) && (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CANIF_CFG_TX_CONTROLLER(PduInfoPtr->swPduHandle))){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#     endif
  else
#endif
  {
    if(CANIF_CFG_MAILBOX_HASTXBUFFER(CANIF_CFG_TX_HTH(PduInfoPtr->swPduHandle))){
#if(CANIF_STATIC_FD_TXQUEUE == STD_ON)
      if(PduInfoPtr->length <= CANIF_CFG_TXBUFFERPRIOBYCANID_STATFDQUEUE_MAXDATALENGTH(PduInfoPtr->swPduHandle))
#    else
      if(PduInfoPtr->length <= CANIF_STATIC_BUFFER_SIZE)
#endif
      {
        CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_1);
        if(CanIf_SetPrioByCanIdTxPduAsQueued(PduInfoPtr->swPduHandle) == E_OK)
        {
          CanIf_TxBufferPrioByCanIdQueuePdu(PduInfoPtr);
        }
        else
        {
        }
        CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_1);
      }
#if((CANIF_STATIC_FD_TXQUEUE == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_ON))
      else
      {
        errorId = CANIF_E_PARAM_DLC;
      }
#endif

      CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_2);
      (void)EcuabCanIf_QueueTxTreatment((CanIf_HwHandleType)CANIF_CFG_TX_HTH(PduInfoPtr->swPduHandle));
      CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_2);
    }
    else{
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CANCELTXCONFIRMATION_API, errorId);
  }
#    else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  CANIF_DUMMY_STATEMENT(CanTxPduId);
}
#endif
#endif
#endif

#if(CANIF_CANCEL_SUPPORT_API == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit(PduIdType CanTxPduId){
  Std_ReturnType retval = E_OK;
  uint8 errorId = CANIF_E_NO_ERROR;

#if((CANIF_DEV_ERROR_DETECT == STD_ON) && (CANIF_USE_INIT_POINTER == STD_ON))

  if(CanIf_SystemInit == FALSE){
    retval = E_NOT_OK;

    errorId = CANIF_E_UNINIT;
  }
  else
#endif
#if((CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME) || (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

  if(CanTxPduId >= CANIF_CFG_MAX_ULTXPDUS){
    retval = E_NOT_OK;

    errorId = CANIF_E_INVALID_TXPDUID;
  }
  else
#endif
  {
    CanTxPduId = CANIF_CFG_TXPDUID2INTTXPDUID(CanTxPduId);
#endif
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

    if(CanTxPduId >= CANIF_CFG_MAX_TXPDUS){
      retval = E_NOT_OK;

      errorId = CANIF_E_INVALID_TXPDUID;
    }
    else
#endif
    {
      {
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

        if(CanIf_GetCtrlMode(CANIF_CFG_TX_CONTROLLER(CanTxPduId)) == CANIF_CS_UNINIT)
        {
          retval = E_NOT_OK;
          errorId = CANIF_E_UNINIT;
        }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

        else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CANIF_CFG_TX_CONTROLLER(CanTxPduId)))
        {
          retval = E_NOT_OK;
          errorId = CANIF_E_PARAM_CONTROLLERID;
        }
#endif
#endif
        else
#endif
        {
          CanIf_AnyIdxType  hth;
#if  (CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
          CANIF_CHANNEL_CANTYPE_LOCAL
          controller = CANIF_CFG_TX_CONTROLLER(CanTxPduId);
#endif
          hth = CANIF_CFG_TX_HTH(CanTxPduId);
          {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
            Can_HwHandleType canDrvHth;
            CanIf_Can_CancelTxFctType canCancelTxFct;
            canCancelTxFct = CANIF_GET_CANCANCELTXFCT(CanIf_Controller_Value_Local);

            canDrvHth = (Can_HwHandleType)(hth - CANIF_CFG_MULTIPLECANDRV_HXHOFFSET(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CanIf_Controller_Value_Local)));

            if(canCancelTxFct != NULL_PTR)
#endif
            {
#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))

              if(CANIF_CFG_MAILBOX_HASTXBUFFER(hth))
              {
                CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_1);

                switch(CANIF_CFG_MAILBOX_TXBUFFERHANDLINGTYPE(hth))
                {
#if(EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON)

                  case CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID:
                    (void)CanIf_ClearPrioByCanIdTxPduAsQueued(CanTxPduId);
                    break;
#endif
#if(EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON)

                  case CANIF_TXBUFFER_HANDLINGTYPE_FIFO:
                    {
                      CanIf_AnyIdxType queueindex;
                      CanIf_AnyIdxType txBufferCfgIdx;
                      queueindex = CANIF_CFG_TX_QUEUEINDEX(CanTxPduId);
                      txBufferCfgIdx = CANIF_CFG_MAILBOX_TXBUFFERIDX(hth);

                      if(CANIF_VAR_TXBUFFERFIFO_QUEUEIDX2FIFOEL(queueindex) != CANIF_NO_ENTRY_IN_TX_FIFO)
                      {
                        CANIF_VAR_TXBUFFERFIFO_QUEUEBASE((CANIF_VAR_TXBUFFERFIFO_QUEUEIDX2FIFOEL(queueindex) + CANIF_CFG_TXBUFFERFIFO_QUEUEBASESTARTIDX(txBufferCfgIdx)), eQueued) = 0;
                        CANIF_VAR_SET_TXBUFFERFIFO_QUEUEIDX2FIFOEL(queueindex, CANIF_NO_ENTRY_IN_TX_FIFO);
                      }
                    }
                    break;
#endif
                default:
                    break;
                }

                CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_1);

#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
                canCancelTxFct(canDrvHth, CanTxPduId);
#else
                canCancelTxFct((CanIf_HwHandleType)hth, CanTxPduId);
#endif
              }
              else
              {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
                canCancelTxFct(canDrvHth, CanTxPduId);
#else
                canCancelTxFct((CanIf_HwHandleType)hth, CanTxPduId);
#endif
              }
#else
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
              canCancelTxFct(canDrvHth, CanTxPduId);
#else
              canCancelTxFct((CanIf_HwHandleType)hth, CanTxPduId);
#endif
#endif
            }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
            else
            {
              retval = E_NOT_OK;
            }
#endif
          }
        }
      }
    }
#if((CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME) || (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))
  }
#endif

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CANCELTRANSMIT_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if(CANIF_CANCEL_SUPPORT_API == STD_ON)

FUNC(void, CANIF_CODE) CanIf_CancelTxNotification(PduIdType PduId, CanIf_CancelResultType IsCancelled){
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(PduId >=  CANIF_CFG_MAX_TXPDUS){
    errorId = CANIF_E_PARAM_LPDU;
  }

  else if(CanIf_GetCtrlMode(CANIF_CFG_TX_CONTROLLER(PduId)) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CANIF_CFG_TX_CONTROLLER(PduId))){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
    if(CanIf_GetCtrlMode(CANIF_CFG_TX_CONTROLLER(PduId)) == CANIF_CS_STARTED){
      if( (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(PduId)) == CANIF_GET_ONLINE) ||
           (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(PduId)) == CANIF_GET_TX_ONLINE)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
         || (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(PduId)) == CANIF_GET_ONLINE_WAKF)
         || (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(PduId)) == CANIF_GET_TX_ONLINE_WAKF)
#endif
       )
      {
#if((EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID == STD_ON) || (EcuabCanIf_Transmit_BUFFER_FIFO == STD_ON))
        if(CANIF_CFG_MAILBOX_HASTXBUFFER(CANIF_CFG_TX_HTH(PduId)))
        {
          CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_2);
          (void)EcuabCanIf_QueueTxTreatment((CanIf_HwHandleType)CANIF_CFG_TX_HTH(PduId));

          CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_2);
        }
#endif
      }
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_TXNOTIFICATION_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  CANIF_DUMMY_STATEMENT(IsCancelled);
}
#endif

#if(CANIF_TRCV_HANDLING == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(TransceiverId >= CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#if(CANIF_TRCV_MAPPING == STD_ON)

  if(TransceiverId >= CanIf_GetSizeOfTransceiverUpToLowMap()){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#endif
#endif
  {
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)

    CanIf_Controller_Value_Local = CANIF_CFG_TRCVTOCTRLMAP(TransceiverId);
    if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
      errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
#endif
    if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
      errorId = CANIF_E_UNINIT;
    }

    else if((TransceiverMode != CANTRCV_TRCVMODE_NORMAL) &&
             (TransceiverMode != CANTRCV_TRCVMODE_STANDBY) &&
             (TransceiverMode != CANTRCV_TRCVMODE_SLEEP)){
      errorId = CANIF_E_PARAM_TRCVMODE;
    }
    else
#endif
    {
#if(CANIF_TRCV_MAPPING == STD_ON)
      uint8                           lowIndex;
      CanIf_CanTrcvFctTblIdx          lowAddress;
      CanIf_CanTrcv_SetOpModeFctType  lowFct;

      lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP_CHANNELINDEX(TransceiverId);
      lowAddress = CANIF_CFG_TRCVUPTOLOWMAP_DRIVERINDEX(TransceiverId);

      lowFct = CanIf_GetCanTrcv_SetOpModeFctMap(lowAddress);

      if(lowFct != NULL_PTR)
      {
        retval = lowFct(lowIndex, TransceiverMode);
      }
#else

      retval = CanTrcv_SetOpMode(TransceiverId, TransceiverMode);
#endif
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_SETTRCVMODE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if(CANIF_TRCV_HANDLING == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode(P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) TransceiverModePtr, uint8 TransceiverId ){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(TransceiverId >= CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#if(CANIF_TRCV_MAPPING == STD_ON)

  if(TransceiverId >= CanIf_GetSizeOfTransceiverUpToLowMap()){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#endif
#endif
  {
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    CanIf_Controller_Value_Local = CANIF_CFG_TRCVTOCTRLMAP(TransceiverId);

    if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
      errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
#endif

    if(TransceiverModePtr == NULL_PTR){
      errorId = CANIF_E_PARAM_POINTER;
    }

    else if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
      errorId = CANIF_E_UNINIT;
    }
    else
#endif
    {
#if(CANIF_TRCV_MAPPING == STD_ON)
      uint8                           lowIndex;
      CanIf_CanTrcvFctTblIdx          lowAddress;
      CanIf_CanTrcv_GetOpModeFctType  lowFct;

      lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP_CHANNELINDEX(TransceiverId);
      lowAddress = CANIF_CFG_TRCVUPTOLOWMAP_DRIVERINDEX(TransceiverId);
      lowFct = CanIf_GetCanTrcv_GetOpModeFctMap(lowAddress);

      if(lowFct != NULL_PTR)
      {
        retval = lowFct(lowIndex, TransceiverModePtr);
      }
#else

      retval = CanTrcv_GetOpMode(TransceiverId, TransceiverModePtr);
#endif
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_GETTRCVMODE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if(CANIF_TRCV_HANDLING == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason(uint8 TransceiverId, P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_STATE_VAR) TrcvWuReasonPtr){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(TransceiverId >= CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#if(CANIF_TRCV_MAPPING == STD_ON)

  if(TransceiverId >= CanIf_GetSizeOfTransceiverUpToLowMap()){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#endif
#endif
  {
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    CanIf_Controller_Value_Local = CANIF_CFG_TRCVTOCTRLMAP(TransceiverId);

    if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
      errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
#endif

    if(TrcvWuReasonPtr == NULL_PTR){
      errorId = CANIF_E_PARAM_POINTER;
    }

    else if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
      errorId = CANIF_E_UNINIT;
    }
    else
#endif
    {
#if(CANIF_TRCV_MAPPING == STD_ON)
      uint8                                 lowIndex;
      CanIf_CanTrcvFctTblIdx                lowAddress;
      CanIf_CanTrcv_GetBusWuReasonFctType   lowFct;

      lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP_CHANNELINDEX(TransceiverId);
      lowAddress = CANIF_CFG_TRCVUPTOLOWMAP_DRIVERINDEX(TransceiverId);

      lowFct = CanIf_GetCanTrcv_GetBusWuReasonFctMap(lowAddress);

      if(lowFct != NULL_PTR)
      {
        retval = lowFct(lowIndex, TrcvWuReasonPtr);
      }
#else

      retval = CanTrcv_GetBusWuReason(TransceiverId, TrcvWuReasonPtr);
#endif
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_GETTRCVWAKEUPREASON_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if(CANIF_TRCV_HANDLING == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode(uint8 TransceiverId, CanTrcv_TrcvWakeupModeType TrcvWakeupMode){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(TransceiverId >= CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#if(CANIF_TRCV_MAPPING == STD_ON)

  if(TransceiverId >= CanIf_GetSizeOfTransceiverUpToLowMap()){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#endif
#endif
  {
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    CanIf_Controller_Value_Local = CANIF_CFG_TRCVTOCTRLMAP(TransceiverId);

    if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
      errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
#endif

    if((TrcvWakeupMode != CANTRCV_WUMODE_ENABLE) &&
        (TrcvWakeupMode != CANTRCV_WUMODE_DISABLE) &&
        (TrcvWakeupMode != CANTRCV_WUMODE_CLEAR)){
      errorId = CANIF_E_PARAM_TRCVWAKEUPMODE;
    }

    else if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
      errorId = CANIF_E_UNINIT;
    }
    else
#endif
    {
#if(CANIF_TRCV_MAPPING == STD_ON)
      uint8                                 lowIndex;
      CanIf_CanTrcvFctTblIdx                lowAddress;
      CanIf_CanTrcv_SetWakeupModeFctType    lowFct;

      lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP_CHANNELINDEX(TransceiverId);
      lowAddress = CANIF_CFG_TRCVUPTOLOWMAP_DRIVERINDEX(TransceiverId);
      lowFct = CanIf_GetCanTrcv_SetWakeupModeFctMap(lowAddress);

      if(lowFct != NULL_PTR)
      {
        retval = lowFct(lowIndex, TrcvWakeupMode);
      }
#else

      retval = CanTrcv_SetWakeupMode(TransceiverId, TrcvWakeupMode);
#endif
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_SETTRCVWAKEUPMODE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if(CANIF_TRCV_HANDLING == STD_ON)

FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode){
  uint8 errorId = CANIF_E_NO_ERROR;
  CANIF_CHANNEL_CANTYPE_LOCAL

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(TransceiverId >= CANIF_CFG_MAX_CANTRCV_TRCVHANDLEIDPLUSONE){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#endif
  {
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
#if(CANIF_TRCV_MAPPING == STD_ON)
    CanIf_TrcvIdUpper = CANIF_CFG_TRCVUPTOUPPERMAP(TransceiverId);
#endif
    CanIf_Controller_Value_Local = CANIF_CFG_TRCVTOCTRLMAP(CanIf_TrcvIdUpper);
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
#if(CANIF_TRCV_MAPPING == STD_ON)

    if(CanIf_TrcvIdUpper >= CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE){
      errorId = CANIF_E_PARAM_TRCV;
    }
    else
#endif

    if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
      errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
#endif

    if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
      errorId = CANIF_E_UNINIT;
    }
    else
#endif
    {
#if(CANIF_DEV_ERROR_DETECT == STD_OFF)

      if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) != CANIF_CS_UNINIT)
#endif
      {
        CanIf_TrcvModeIndicationFctType  trcvModeIndicationFct;
        trcvModeIndicationFct = CANIF_CFG_TRCVMODEINDICATIONFCT();
        if(trcvModeIndicationFct != NULL_PTR)
        {
          trcvModeIndicationFct(CanIf_TrcvIdUpper, TransceiverMode);
        }
      }
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_TRCVMODEINDICATION_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
  CANIF_DUMMY_STATEMENT(TransceiverId);
#endif
#endif
}
#endif

#if((CANIF_TRCV_HANDLING == STD_ON) && (CANIF_PN_TRCV_HANDLING == STD_ON))

FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability(uint8 TransceiverId){
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(TransceiverId >= CANIF_CFG_MAX_CANTRCV_TRCVHANDLEIDPLUSONE){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#endif
  {
#if(CANIF_TRCV_MAPPING == STD_ON)
    CanIf_TrcvIdUpper = CANIF_CFG_TRCVUPTOUPPERMAP(TransceiverId);
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    CanIf_Controller_Value_Local = CANIF_CFG_TRCVTOCTRLMAP(CanIf_TrcvIdUpper);
#if(CANIF_TRCV_MAPPING == STD_ON)

    if(CanIf_TrcvIdUpper >= CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE){
      errorId = CANIF_E_PARAM_TRCV;
    }
    else
#endif

    if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
      errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
#endif

    if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
      errorId = CANIF_E_UNINIT;
    }
    else
#endif
    {
      CanIf_ConfirmPnAvailabilityFctType cbkFct;
      cbkFct = CANIF_CFG_CONFIRMPNAVAILABILITYFCT();

      if(cbkFct != NULL_PTR)
      {
        cbkFct(CanIf_TrcvIdUpper);
      }
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CONFIRMPNAVAILABILITY_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
  CANIF_DUMMY_STATEMENT(TransceiverId);
#endif
#endif
}
#endif

#if((CANIF_TRCV_HANDLING == STD_ON) && (CANIF_PN_TRCV_HANDLING == STD_ON))

FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId){
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(TransceiverId >= CANIF_CFG_MAX_CANTRCV_TRCVHANDLEIDPLUSONE){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#endif
  {
#if(CANIF_TRCV_MAPPING == STD_ON)
    CanIf_TrcvIdUpper = CANIF_CFG_TRCVUPTOUPPERMAP(TransceiverId);
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    CanIf_Controller_Value_Local = CANIF_CFG_TRCVTOCTRLMAP(CanIf_TrcvIdUpper);
#if(CANIF_TRCV_MAPPING == STD_ON)

    if(CanIf_TrcvIdUpper >= CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE){
      errorId = CANIF_E_PARAM_TRCV;
    }
    else
#endif

    if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
      errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
#endif

    if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
      errorId = CANIF_E_UNINIT;
    }
    else
#endif
    {
      CanIf_ClearTrcvWufFlagIndicationFctType cbkFct;
      cbkFct = CANIF_CFG_CLEARTRCVWUFFLAGINDICATIONFCT();

      if(cbkFct != NULL_PTR)
      {
        cbkFct(CanIf_TrcvIdUpper);
      }
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CLEARTRCVWUFFLAGINDICATION_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
  CANIF_DUMMY_STATEMENT(TransceiverId);
#endif
#endif
}
#endif

#if((CANIF_TRCV_HANDLING == STD_ON) && (CANIF_PN_TRCV_HANDLING == STD_ON))

FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId){
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(TransceiverId >= CANIF_CFG_MAX_CANTRCV_TRCVHANDLEIDPLUSONE){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#endif
  {
#if(CANIF_TRCV_MAPPING == STD_ON)
    CanIf_TrcvIdUpper = CANIF_CFG_TRCVUPTOUPPERMAP(TransceiverId);
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    CanIf_Controller_Value_Local = CANIF_CFG_TRCVTOCTRLMAP(CanIf_TrcvIdUpper);
#if(CANIF_TRCV_MAPPING == STD_ON)

    if(CanIf_TrcvIdUpper >= CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE){
      errorId = CANIF_E_PARAM_TRCV;
    }
    else
#endif

    if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
      errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
#endif

    if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
      errorId = CANIF_E_UNINIT;
    }
    else
#endif
    {
      CanIf_CheckTrcvWakeFlagIndicationFctType cbkFct;
      cbkFct = CANIF_CFG_CHECKTRCVWAKEFLAGINDICATIONFCT();

      if(cbkFct != NULL_PTR)
      {
        cbkFct(CanIf_TrcvIdUpper);
      }
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CHECKTRCVWAKEFLAGINDICATION_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
  CANIF_DUMMY_STATEMENT(TransceiverId);
#endif
#endif
}
#endif

#if((CANIF_TRCV_HANDLING == STD_ON) && (CANIF_PN_TRCV_HANDLING == STD_ON))

FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag(uint8 TransceiverId){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(TransceiverId >= CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#if(CANIF_TRCV_MAPPING == STD_ON)

  if(TransceiverId >= CanIf_GetSizeOfTransceiverUpToLowMap()){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#endif
#endif
  {
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    CanIf_Controller_Value_Local = CANIF_CFG_TRCVTOCTRLMAP(TransceiverId);

    if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
      errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
#endif

    if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
      errorId = CANIF_E_UNINIT;
    }
    else
#endif
    {
#if(CANIF_TRCV_MAPPING == STD_ON)

      uint8                                  TrcvChannelId;
      CanIf_CanTrcvFctTblIdx                 TrcvDriverId;
      CanIf_CanTrcv_ClearTrcvWufFlagFctType  lowFct;

      TrcvChannelId = CANIF_CFG_TRCVUPTOLOWMAP_CHANNELINDEX(TransceiverId);
      TrcvDriverId = CANIF_CFG_TRCVUPTOLOWMAP_DRIVERINDEX(TransceiverId);

      lowFct = CanIf_GetCanTrcv_ClearTrcvWufFlagFctMap(TrcvDriverId);

      if(lowFct != (CanIf_CanTrcv_ClearTrcvWufFlagFctType)NULL_PTR)
      {
        retval = lowFct(TrcvChannelId);
      }
      else
      {
        errorId = CANIF_E_PARAM_TRCV;

      }
#else

      retval = CanTrcv_ClearTrcvWufFlag(TransceiverId);
#endif
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CLEARTRCVWUFFLAG_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if((CANIF_TRCV_HANDLING == STD_ON) && (CANIF_PN_TRCV_HANDLING == STD_ON))

FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag(uint8 TransceiverId){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(TransceiverId >= CANIF_CFG_MAX_TRANSCEIVERHANDLEIDPLUSONE){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#if(CANIF_TRCV_MAPPING == STD_ON)
  if(TransceiverId >= CanIf_GetSizeOfTransceiverUpToLowMap()){
    errorId = CANIF_E_PARAM_TRCV;
  }
  else
#endif
#endif
  {
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    CanIf_Controller_Value_Local = CANIF_CFG_TRCVTOCTRLMAP(TransceiverId);

    if(CanIf_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER){
      errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
#endif

    if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT){
      errorId = CANIF_E_UNINIT;
    }
    else
#endif
    {
#if(CANIF_TRCV_MAPPING == STD_ON)

      uint8                               TrcvChannelId;
      CanIf_CanTrcvFctTblIdx              TrcvDriverId;
      CanIf_CanTrcv_CheckWakeFlagFctType  lowFct;

      TrcvChannelId = CANIF_CFG_TRCVUPTOLOWMAP_CHANNELINDEX(TransceiverId);
      TrcvDriverId = CANIF_CFG_TRCVUPTOLOWMAP_DRIVERINDEX(TransceiverId);

      lowFct = CanIf_GetCanTrcv_CheckWakeFlagFctMap(TrcvDriverId);

      if(lowFct != (CanIf_CanTrcv_CheckWakeFlagFctType)NULL_PTR)
      {
        retval = lowFct(TrcvChannelId);
      }
      else
      {
        errorId = CANIF_E_PARAM_TRCV;

      }
#else
      retval = CanTrcv_CheckWakeFlag(TransceiverId);
#endif
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CHECKTRCVWAKEFLAG_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if(CANIF_WAKEUP_SUPPORT == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource){
  Std_ReturnType retval = E_OK;

  uint8 errorId = CANIF_E_NO_ERROR;
  Std_ReturnType localRetval;
  EcuM_WakeupSourceType wokenUpSources;
  uint8 numWUsrc;
  wokenUpSources = 0u;

#if((CANIF_DEV_ERROR_DETECT == STD_ON) && (CANIF_USE_INIT_POINTER == STD_ON))

  if(CanIf_SystemInit == FALSE){
    retval = E_NOT_OK;

    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  {
    for(numWUsrc = 0u; numWUsrc < CANIF_CFG_MAX_WAKEUPSOURCES; numWUsrc++){
      EcuM_WakeupSourceType                 wuSrc;
      CanIf_WakeUpTargetType                wuTrgtmodule;
      uint8                                 wuTrgtaddress;
      CANIF_WUCHANNEL_CANTYPE_LOCAL

      wuSrc         = CANIF_CFG_WAKEUP_WAKEUPSOURCE(numWUsrc);
      wuTrgtmodule  = CANIF_CFG_WAKEUP_WAKEUPTARGETMODULE(numWUsrc);
      wuTrgtaddress = CANIF_CFG_WAKEUP_WAKEUPTARGETADDRESS(numWUsrc);
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION==STD_OFF)

      wuController = CANIF_CFG_WAKEUP_CONTROLLER(numWUsrc);
#endif

      localRetval = E_NOT_OK;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)

      if(CanIf_WU_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER)
      {
        retval = E_NOT_OK;

        errorId = CANIF_E_PARAM_WAKEUPSOURCE;
      }
      else
#endif

      if(CanIf_GetCtrlMode(CanIf_WU_Controller_Value_Local) == CANIF_CS_UNINIT)
      {
        retval = E_NOT_OK;

        errorId = CANIF_E_UNINIT;
      }
      else
#endif
      {
        if((WakeupSource & wuSrc) != 0u)
        {
          if((CanIf_GetCtrlMode(CanIf_WU_Controller_Value_Local) == CANIF_CS_SLEEP) || (CanIf_GetCtrlMode(CanIf_WU_Controller_Value_Local) == CANIF_CS_STOPPED))
          {
            if(wuTrgtmodule == CANIF_WAKEUPREQUEST_CAN)
            {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
              if(wuTrgtaddress >= CanIf_GetSizeOfCanChannelIdUpToLowMap())
              {
                errorId = CANIF_E_PARAM_CONTROLLERID;
                retval = E_NOT_OK;
              }
              else
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

              if(!CANIF_CFG_IS_CANDRVINDEXVALID(wuTrgtaddress))
              {
                errorId = CANIF_E_PARAM_WAKEUPSOURCE;
                retval = E_NOT_OK;
              }
              else
#endif
#endif
              {
                CanIf_Can_CheckWakeupFctType canCheckWakeupFct;
                canCheckWakeupFct = CanIf_GetCan_CheckWakeupFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(wuTrgtaddress));
                if(canCheckWakeupFct != NULL_PTR)
                {
                  localRetval = canCheckWakeupFct(CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(wuTrgtaddress));
                }
              }
#else
              localRetval = Can_CheckWakeup(wuTrgtaddress);
#endif
            }
#if(CANIF_TRCV_HANDLING == STD_ON)

            else if(wuTrgtmodule == CANIF_WAKEUPREQUEST_TRCV)
            {
#if(CANIF_TRCV_MAPPING == STD_ON)

              uint8                                 lowIndex;
              CanIf_CanTrcvFctTblIdx                lowAddress;
              CanIf_CanTrcv_CheckWakeupFctType   lowFct;
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
              if(wuTrgtaddress >= CanIf_GetSizeOfTransceiverUpToLowMap())
              {
                errorId = CANIF_E_PARAM_TRCV;
                retval = E_NOT_OK;
              }
              else
#endif
              {
                lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP_CHANNELINDEX(wuTrgtaddress);
                lowAddress = CANIF_CFG_TRCVUPTOLOWMAP_DRIVERINDEX(wuTrgtaddress);

                lowFct = CanIf_GetCanTrcv_CheckWakeupFctMap(lowAddress);

                if(lowFct != NULL_PTR)
                {
                  localRetval = lowFct(lowIndex);
                }
              }
#else

              localRetval = CanTrcv_CheckWakeup(wuTrgtaddress);
#endif
            }
#endif
            else
            {
            }

            if(localRetval == E_OK)
            {
              wokenUpSources |= wuSrc;
            }
          }
          else
          {
            retval = E_NOT_OK;

            errorId = CANIF_E_NOT_SLEEP;
          }
        }
      }
    }
  }

  if(wokenUpSources == 0u){
    retval = E_NOT_OK;
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CHECKWAKEUP_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
  }
#endif

#if(CANIF_WAKEUP_VALIDATION == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource){
  Std_ReturnType retval = E_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
  EcuM_WakeupSourceType wokenUpSources;
  uint8  numWUsrc;
  wokenUpSources = 0u;

#if((CANIF_DEV_ERROR_DETECT == STD_ON) && (CANIF_USE_INIT_POINTER == STD_ON))

  if(CanIf_SystemInit == FALSE){
    retval = E_NOT_OK;

    errorId = CANIF_E_UNINIT;
  }
  else
#endif
  {
    for(numWUsrc = 0u; numWUsrc < CANIF_CFG_MAX_WAKEUPSOURCES; numWUsrc++){
      EcuM_WakeupSourceType                 wuSrc;
      CANIF_WUCHANNEL_CANTYPE_LOCAL

      wuSrc         = CANIF_CFG_WAKEUP_WAKEUPSOURCE(numWUsrc);
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)

      wuController  = CANIF_CFG_WAKEUP_CONTROLLER(numWUsrc);
#endif
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)

      if(CanIf_WU_Controller_Value_Local >= CANIF_CFG_MAX_CONTROLLER)
      {
        retval = E_NOT_OK;

        errorId = CANIF_E_PARAM_WAKEUPSOURCE;
      }
      else
#endif

      if(CanIf_GetCtrlMode(CanIf_WU_Controller_Value_Local) == CANIF_CS_UNINIT)
      {
        retval = E_NOT_OK;

        errorId = CANIF_E_UNINIT;
      }
      else
#endif
      {
        if((WakeupSource & wuSrc) != 0u)
        {
          if( CanIf_GetWakeUpValidationState(CanIf_WU_Controller_Value_Local) == CANIF_WUVALIDATION_DETECTED )
          {
            wokenUpSources |= wuSrc;
          }
        }
        else
        {
        }
      }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
      if(errorId != CANIF_E_NO_ERROR)
      {
        CanIf_Det_ReportError(CANIF_CHECKVALIDATIONUP_API, errorId);
      }
#endif
    }
  }

  if(wokenUpSources != 0u){
    CanIf_WakeUpValidationFctType wakeupValidationFct;
    wakeupValidationFct = CANIF_CFG_WAKEUPVALIDATION();
    if(wakeupValidationFct != NULL_PTR){
      wakeupValidationFct(wokenUpSources & WakeupSource);
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CHECKVALIDATIONUP_API, errorId);
  }
#endif
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if(CANIF_SETDYNAMICTXID_API == STD_ON)

FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId(PduIdType CanTxPduId, Can_IdType CanId){
  uint8 errorId = CANIF_E_NO_ERROR;
  CANIF_CHANNEL_CANTYPE_LOCAL
  PduIdType dynamicPduId;

#if((CANIF_DEV_ERROR_DETECT == STD_ON) && (CANIF_USE_INIT_POINTER == STD_ON))

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

#if((CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME) || (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

  if(CanTxPduId >= CANIF_CFG_MAX_ULTXPDUS){
    errorId = CANIF_E_INVALID_TXPDUID;
  }
  else
#endif
  {
    CanTxPduId = CANIF_CFG_TXPDUID2INTTXPDUID(CanTxPduId);
#endif
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

    if(CanTxPduId >= CANIF_CFG_MAX_TXPDUS){
      errorId = CANIF_E_INVALID_TXPDUID;
    }
    else
#endif
    {
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)

      controller = CANIF_CFG_TX_CONTROLLER(CanTxPduId);
#endif
      dynamicPduId = CANIF_CFG_STAT2DYN_INDIRECTION(CanTxPduId);

#if(CANIF_DEV_ERROR_DETECT == STD_ON)

      if(dynamicPduId >= CanIf_GetSizeOfDynTxId())
      {
        errorId = CANIF_E_INVALID_TXPDUID;
      }
#if(CANIF_EXTENDEDID_SUPPORT != STD_ON)

      else if((CanId & (~CANIF_FDFLAG)) > 0x7FFu)
      {
        errorId = CANIF_E_PARAM_CANID;
      }
#endif

      else if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) == CANIF_CS_UNINIT)
      {
        errorId = CANIF_E_UNINIT;
      }
      else
#endif
      {
#if(CANIF_DEV_ERROR_DETECT == STD_OFF)

        if(CanIf_GetCtrlMode(CanIf_Controller_Value_Local) != CANIF_CS_UNINIT)
#endif
        {
          CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_5);

          CANIF_VAR_DYNTXID(dynamicPduId) = CanId;
          CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_5);
        }
      }
    }
#if((CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME) || (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))
  }
#endif

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_SETDYNAMICTXID_API_ID, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
}
#endif

FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication(uint8 ControllerId, CanIf_ControllerModeType ControllerMode){
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLER;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif
    {
#if(CANIF_DEV_ERROR_DETECT == STD_OFF)

    if(CANIF_CS_UNINIT != CanIf_GetCtrlMode(CanIf_Controller_Value))
#endif
    {
      CanIf_CtrlModeIndicationFctType cbkFct;

      switch(ControllerMode)
      {
        case CANIF_CS_STOPPED:

          switch(CanIf_GetCtrlMode(CanIf_Controller_Value))
          {
            case CANIF_CS_STARTED:
            case CANIF_CS_SLEEP:

              CanIf_SetCtrlMode(CanIf_Controller_Value, CANIF_CS_STOPPED);
#if(CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON)

              CanIf_SetTxConfState(CanIf_Controller_Value, CANIF_NO_NOTIFICATION);
#endif
              break;
            case CANIF_CS_STOPPED:

              break;
            default:

              break;
          }
          break;
        case CANIF_CS_STARTED:

          switch(CanIf_GetCtrlMode(CanIf_Controller_Value))
          {
            case CANIF_CS_STOPPED:

              CanIf_SetCtrlMode(CanIf_Controller_Value, CANIF_CS_STARTED);
              break;
            case CANIF_CS_STARTED:

              break;
            case CANIF_CS_SLEEP:

              break;
            default:

              break;
          }
          break;
        case CANIF_CS_SLEEP:

          switch(CanIf_GetCtrlMode(CanIf_Controller_Value))
          {
            case CANIF_CS_STOPPED:
            case CANIF_CS_SLEEP:

              CanIf_SetCtrlMode(CanIf_Controller_Value, CANIF_CS_SLEEP);
              break;
            case CANIF_CS_STARTED:

              break;
            default:

              break;
          }
          break;
        default:

          break;
      }

      cbkFct = CANIF_CFG_CTRLMODEINDICATIONFCT();

      if(cbkFct != (CanIf_CtrlModeIndicationFctType)NULL_PTR)
      {
        cbkFct(CanIf_Controller_Value, ControllerMode);
      }
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_CONTROLLERMODEINDICATION_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
#endif
}

#if(CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON)

FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState(uint8 ControllerId){
  CanIf_NotifStatusType retval = CANIF_NO_NOTIFICATION;
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif
#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)

  if(CanIf_Controller_Value >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLER;
  }
  else
#endif

  if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif
  {
    retval = CanIf_GetTxConfState(CanIf_Controller_Value);
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_GETTXCONFIRMATIONSTATE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

#if(CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
  return retval;
}
#endif

#if(CANIF_CHANGE_BAUDRATE_SUPPORT == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckBaudrate(uint8 ControllerId, CONST(uint16, CANIF_CONST) Baudrate){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value)){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    CanIf_Can_CheckBaudrateFctType canCheckBaudrateFct;
    canCheckBaudrateFct = CanIf_GetCan_CheckBaudrateFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CanIf_Controller_Value));
    if(canCheckBaudrateFct != NULL_PTR){
      retval = canCheckBaudrateFct(CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), Baudrate);
    }
#else
    retval = Can_CheckBaudrate(CanIf_Controller_Value, Baudrate);
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_BAUDRATECHECK_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  CANIF_DUMMY_STATEMENT(ControllerId);

  return retval;
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_ChangeBaudrate(uint8 ControllerId, CONST(uint16, CANIF_CONST) Baudrate){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value)){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    CanIf_Can_ChangeBaudrateFctType canChangeBaudrateFct;
    canChangeBaudrateFct = CanIf_GetCan_ChangeBaudrateFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CanIf_Controller_Value));
    if(canChangeBaudrateFct != NULL_PTR){
      retval = canChangeBaudrateFct(CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), Baudrate);
    }
#else
    retval = Can_ChangeBaudrate(CanIf_Controller_Value, Baudrate);
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_BAUDRATECHANGE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  CANIF_DUMMY_STATEMENT(ControllerId);

  return retval;
}
#endif

#if(CANIF_SET_BAUDRATE_API == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID){
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
#if((CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON) && (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value)){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
  else
#endif
  {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    CanIf_Can_SetBaudrateFctType canSetBaudrateFct;
    canSetBaudrateFct = CanIf_GetCan_SetBaudrateFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CanIf_Controller_Value));
    if(canSetBaudrateFct != NULL_PTR){
      retval = canSetBaudrateFct(CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), BaudRateConfigID);
    }
#else
    retval = Can_SetBaudrate(CanIf_Controller_Value, BaudRateConfigID);
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_BAUDRATESET_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif

#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
  return retval;
}
#endif

#if(CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED)
#if(CANIF_EXTENDEDID_SUPPORT == STD_ON)

FUNC(void, CANIF_CODE) CanIf_SetAddressTableEntry(uint8 ControllerId, uint8 intAddr, uint8 busAddr){
  uint8 errorId = CANIF_E_NO_ERROR;
  uint8 oldBusAddr;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(CANIF_CFG_CTRLJ1939DYNADDRSUPPORT(CanIf_Controller_Value) == CANIF_J1939_DYN_ADDR_DISABLED){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
  else
#endif
  {
    CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_6);

    oldBusAddr = CANIF_VAR_J1939TXADDR_LOOKUP(CanIf_Controller_Value, intAddr);
    if(oldBusAddr != CANIF_J1939_NULL_ADDR){
      CANIF_VAR_SET_J1939RXADDR_LOOKUP(CanIf_Controller_Value, oldBusAddr, CANIF_J1939_NULL_ADDR);
    }
    CANIF_VAR_SET_J1939RXADDR_LOOKUP(CanIf_Controller_Value, busAddr, intAddr);
    CANIF_VAR_SET_J1939TXADDR_LOOKUP(CanIf_Controller_Value, intAddr, busAddr);

    CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_6);
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_SETADDRESSTABLEENTRY_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  CANIF_DUMMY_STATEMENT(ControllerId);
}

FUNC(void, CANIF_CODE) CanIf_ResetAddressTableEntry(uint8 ControllerId, uint8 intAddr){
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(CANIF_CFG_CTRLJ1939DYNADDRSUPPORT(CanIf_Controller_Value) == CANIF_J1939_DYN_ADDR_DISABLED){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
  else
#endif
  {
    uint8 busAddr;

    CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_6);

    busAddr = CANIF_VAR_J1939TXADDR_LOOKUP(CanIf_Controller_Value, intAddr);

    CANIF_VAR_SET_J1939RXADDR_LOOKUP(CanIf_Controller_Value, busAddr, CANIF_J1939_NULL_ADDR);
    CANIF_VAR_SET_J1939TXADDR_LOOKUP(CanIf_Controller_Value, intAddr, CANIF_J1939_NULL_ADDR);

    CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_6);
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_RESETADDRESSTABLEENTRY_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  CANIF_DUMMY_STATEMENT(ControllerId);
}
#endif
#endif

#if(CANIF_EXTENDED_RAM_CHECK_SUPPORT == STD_ON)

FUNC(void, CANIF_CODE) CanIf_RamCheckCorruptMailbox(uint8 ControllerId, CanIf_HwHandleType HwHandle){
  uint8 errorId = CANIF_E_NO_ERROR;
  CanIf_RamCheckCorruptMailboxIndFctType ramCheckCorruptMailboxIndFct = CANIF_CFG_RAMCHECKCORRUPTMAILBOXINDFCT();

  if(ramCheckCorruptMailboxIndFct != NULL_PTR){
    ramCheckCorruptMailboxIndFct(ControllerId, HwHandle);
  }
  else{
    errorId = CANIF_E_CONFIG;
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_RAMCHECKCORRUPTMAILBOX_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
}

FUNC(void, CANIF_CODE) CanIf_RamCheckCorruptController(uint8 ControllerId){
  uint8 errorId = CANIF_E_NO_ERROR;
  CanIf_RamCheckCorruptControllerIndFctType ramCheckCorruptControllerIndFct = CANIF_CFG_RAMCHECKCORRUPTCONTROLLERINDFCT();

  if(ramCheckCorruptControllerIndFct != NULL_PTR){
    ramCheckCorruptControllerIndFct(ControllerId);
  }
  else{
    errorId = CANIF_E_CONFIG;
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_RAMCHECKCORRUPTCONTROLLER_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
}

FUNC(void, CANIF_CODE) CanIf_RamCheckExecute(uint8 ControllerId){
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
  CanIf_Can_RamCheckExecuteFctType can_RamCheckExecuteFct;
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value)){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    can_RamCheckExecuteFct = CanIf_GetCan_RamCheckExecuteFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CanIf_Controller_Value));

    if(can_RamCheckExecuteFct != NULL_PTR){
      can_RamCheckExecuteFct(CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value));
    }
    else{
      errorId = CANIF_E_CONFIG;
    }
#else
    Can_RamCheckExecute(CanIf_Controller_Value);
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_RAMCHECKEXECUTE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
}

FUNC(void, CANIF_CODE) CanIf_RamCheckEnableMailbox(uint8 ControllerId, CanIf_HwHandleType HwHandle){
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
  CanIf_Can_RamCheckEnableMailboxFctType can_RamCheckEnableMailboxFct;
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value)){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    can_RamCheckEnableMailboxFct = CanIf_GetCan_RamCheckEnableMailboxFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CanIf_Controller_Value));

    if(can_RamCheckEnableMailboxFct != NULL_PTR){
      can_RamCheckEnableMailboxFct((Can_HwHandleType)HwHandle);
    }
    else{
      errorId = CANIF_E_CONFIG;
    }
#else
    Can_RamCheckEnableMailbox(HwHandle);
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_RAMCHECKENABLEMAILBOX_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  CANIF_DUMMY_STATEMENT(ControllerId);
}

FUNC(void, CANIF_CODE) CanIf_RamCheckEnableController(uint8 ControllerId){
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
  CanIf_Can_RamCheckEnableControllerFctType can_RamCheckEnableControllerFct;
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(CanIf_GetCtrlMode(CanIf_Controller_Value) == CANIF_CS_UNINIT){
    errorId = CANIF_E_UNINIT;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value)){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    can_RamCheckEnableControllerFct = CanIf_GetCan_RamCheckEnableControllerFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CanIf_Controller_Value));

    if(can_RamCheckEnableControllerFct != NULL_PTR){
      can_RamCheckEnableControllerFct(CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value));
    }
    else{
      errorId = CANIF_E_CONFIG;
    }
#else
    Can_RamCheckEnableController(CanIf_Controller_Value);
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_RAMCHECKENABLECONTROLLER_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
}
#endif

#if(CANIF_SET_PDU_RECEPTION_MODE_SUPPORT == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduReceptionMode(PduIdType id, CanIf_ReceptionModeType mode){
  Std_ReturnType retval  = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
  CanIf_AnyIdxType CanIfRxPduId;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif
#endif
#if((CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME) || (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

  if(id >= CANIF_CFG_MAX_ULRXPDUS){
    errorId = CANIF_E_INVALID_RXPDUID;
  }
  else
#endif
#endif
  {
#if((CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME) || (CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))

    CanIfRxPduId = CANIF_CFG_EXTRXPDUID2INTRXPDUID(id);
#else
    CanIfRxPduId = id;
#endif
#if(CANIF_DEV_ERROR_DETECT == STD_ON)

    if(CanIfRxPduId >= CANIF_CFG_MAX_RXPDUS){
      errorId = CANIF_E_INVALID_RXPDUID;
    }

    else if((mode != CANIF_RMT_RECEIVE_STOP) && (mode != CANIF_RMT_IGNORE_CONTINUE)){
      errorId = CANIF_E_INVALID_PDURECEPTIONMODE;
    }
    else
#endif
    {
      if(CANIF_CFG_RX_ISRECEPTIONMODEPDU(CanIfRxPduId))
      {
        CANIF_VAR_SET_PDU_RECEPTION_MODE(CANIF_CFG_RX_PDURECEPTIONMODEIDX(CanIfRxPduId), mode);
        retval = E_OK;
      }
#if(CANIF_DEV_ERROR_DETECT == STD_ON)
      else
      {
        errorId = CANIF_E_INVALID_RXPDUID;
      }
#endif
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_SETPDURECEPTIONMODE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}
#endif

#if(CANIF_BUS_MIRRORING_SUPPORT == STD_ON)

FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerErrorState(uint8 ControllerId, P2VAR(Can_ErrorStateType, AUTOMATIC, CANIF_APPL_STATE_VAR) ErrorStatePtr){
  Std_ReturnType retval  = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
  CanIf_Can_GetControllerErrorStateFctType can_GetControllerErrorStateFct;
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(ErrorStatePtr == NULL_PTR){
    errorId = CANIF_E_PARAM_POINTER;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value)){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    can_GetControllerErrorStateFct = CanIf_GetCan_GetControllerErrorStateFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CanIf_Controller_Value));

    if(can_GetControllerErrorStateFct != NULL_PTR){
      retval = can_GetControllerErrorStateFct(CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), ErrorStatePtr);
    }
    else{
      errorId = CANIF_E_CONFIG;
    }
#else
    retval = Can_GetControllerErrorState(CanIf_Controller_Value, ErrorStatePtr);
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_GETCONTROLLERERRORSTATE_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
  return retval;
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerRxErrorCounter(uint8 ControllerId, P2VAR(uint8, AUTOMATIC, CANIF_APPL_STATE_VAR) RxErrorCounterPtr){
  Std_ReturnType retval  = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
  CanIf_Can_GetControllerRxErrorCounterFctType can_GetControllerRxErrorCounterFct;
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(RxErrorCounterPtr == NULL_PTR){
    errorId = CANIF_E_PARAM_POINTER;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value)){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    can_GetControllerRxErrorCounterFct = CanIf_GetCan_GetControllerRxErrorCounterFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CanIf_Controller_Value));

    if(can_GetControllerRxErrorCounterFct != NULL_PTR){
      retval = can_GetControllerRxErrorCounterFct(CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), RxErrorCounterPtr);
    }
    else{
      errorId = CANIF_E_CONFIG;
    }
#else
    retval = Can_GetControllerRxErrorCounter(CanIf_Controller_Value, RxErrorCounterPtr);
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_GETCONTROLLERRXERRORCOUNTER_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
  return retval;
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerTxErrorCounter(uint8 ControllerId, P2VAR(uint8, AUTOMATIC, CANIF_APPL_STATE_VAR) TxErrorCounterPtr){
  Std_ReturnType retval  = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
  CanIf_Can_GetControllerTxErrorCounterFctType can_GetControllerTxErrorCounterFct;
#endif

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }

  else if(TxErrorCounterPtr == NULL_PTR){
    errorId = CANIF_E_PARAM_POINTER;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CanIf_Controller_Value)){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
    can_GetControllerTxErrorCounterFct = CanIf_GetCan_GetControllerTxErrorCounterFctMap(CANIF_CFG_CTRLUPTOLOWMAP_DRIVERINDEX(CanIf_Controller_Value));

    if(can_GetControllerTxErrorCounterFct != NULL_PTR){
      retval = can_GetControllerTxErrorCounterFct(CANIF_CFG_CTRLUPTOLOWMAP_CHANNELINDEX(CanIf_Controller_Value), TxErrorCounterPtr);
    }
    else{
      errorId = CANIF_E_CONFIG;
    }
#else
    retval = Can_GetControllerTxErrorCounter(CanIf_Controller_Value, TxErrorCounterPtr);
#endif
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_GETCONTROLLERTXERRORCOUNTER_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
  return retval;
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_EnableBusMirroring(uint8 ControllerId, boolean MirroringActive){
  Std_ReturnType retval  = E_NOT_OK;
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(ControllerId >= CANIF_CFG_MAX_CONTROLLER){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
  else
#endif
  {
    CanIf_ChangeMirroring(CanIf_Controller_Value, MirroringActive);
    retval = E_OK;
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_ENABLEBUSMIRRORING_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
#if((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  CANIF_DUMMY_STATEMENT(ControllerId);
#endif
  return retval;
}

FUNC(Can_ReturnType, CANIF_CODE) Appl_GenericConfirmation(uint8 Controller, Can_PduInfoPtrType DataPtr){
  uint8 errorId = CANIF_E_NO_ERROR;

#if(CANIF_DEV_ERROR_DETECT == STD_ON)
#if(CANIF_USE_INIT_POINTER == STD_ON)

  if(CanIf_SystemInit == FALSE){
    errorId = CANIF_E_UNINIT;
  }
  else
#endif

  if(DataPtr == NULL_PTR){
    errorId = CANIF_E_PARAM_POINTER;
  }

  else if(DataPtr->swPduHandle >=  CANIF_CFG_MAX_TXPDUS){
    errorId = CANIF_E_PARAM_LPDU;
  }

  else if(CanIf_GetCtrlMode(CANIF_CFG_TX_CONTROLLER(DataPtr->swPduHandle)) == CANIF_CS_UNINIT ){
    errorId = CANIF_E_UNINIT;
  }
#if(CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
#if(CANIF_POSTBUILD_VARIANT_SUPPORT == STD_ON)

  else if(!CANIF_CFG_IS_CANDRVINDEXVALID(CANIF_CFG_TX_CONTROLLER(DataPtr->swPduHandle))){
    errorId = CANIF_E_PARAM_CONTROLLERID;
  }
#endif
#endif
  else
#endif
  {
    if(CanIf_GetCtrlMode(CANIF_CFG_TX_CONTROLLER(DataPtr->swPduHandle)) == CANIF_CS_STARTED){
      if( (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(DataPtr->swPduHandle)) == CANIF_GET_ONLINE) ||
             (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(DataPtr->swPduHandle)) == CANIF_GET_TX_ONLINE)
#if(CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
        || (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(DataPtr->swPduHandle)) == CANIF_GET_ONLINE_WAKF)
        || (CanIf_GetChannelMode(CANIF_CFG_TX_CONTROLLER(DataPtr->swPduHandle)) == CANIF_GET_TX_ONLINE_WAKF)
#endif
         )
      {
        if(CanIf_IsMirroringEnabled(CANIF_CFG_TX_CONTROLLER(DataPtr->swPduHandle)))
        {
          Mirror_ReportCanFrame(CANIF_CFG_TX_CONTROLLER(DataPtr->swPduHandle), DataPtr->id, DataPtr->length, DataPtr->sdu);
        }
      }
    }
  }

#if(CANIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CANIF_E_NO_ERROR){
    CanIf_Det_ReportError(CANIF_APPL_GENERICCONFIRMATION_API, errorId);
  }
#else
  CANIF_DUMMY_STATEMENT(errorId);
#endif
  CANIF_DUMMY_STATEMENT(Controller);
  return CAN_OK;
}
#endif

#define CANIF_STOP_SEC_CODE
#include "MemMap.hpp"

#ifdef __cplusplus
}
#endif
