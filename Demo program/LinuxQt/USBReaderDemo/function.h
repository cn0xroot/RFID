//System Setting

extern "C" int API_SetSerNum(  unsigned char *newValue, unsigned char *buffer);

extern "C" int API_GetSerNum( unsigned char *buffer);

extern "C" int WriteUserInfo( int num_blk, int num_length, char *user_info);

extern "C" int ReadUserInfo( int num_blk, int num_length, char *user_info);

extern "C" int GetVersionNum(char *VersionNum);

extern "C" int API_ControlLED( unsigned char freq, unsigned char duration, unsigned char *buffer);

extern "C" int API_ControlBuzzer( unsigned char freq, unsigned char duration, unsigned char *buffer);

//ISO14443A
extern "C" int MF_Request( unsigned char inf_mode, unsigned char *buffer);

extern "C" int MF_Anticoll( unsigned char *snr, unsigned char *tatus);

extern "C" int MF_Select( unsigned char *snr);

extern "C" int MF_Halt();

extern "C" int API_PCDRead( unsigned char mode, unsigned char blk_add, unsigned char num_blk, unsigned char *snr, unsigned char *buffer);

extern "C" int API_PCDWrite( unsigned char mode, unsigned char blk_add, unsigned char num_blk, unsigned char *snr, unsigned char *buffer);

extern "C" int API_PCDInitVal( unsigned char mode, unsigned char SectNum, unsigned char *snr, unsigned char *value);

extern "C" int API_PCDDec( unsigned char mode, unsigned char SectNum, unsigned char *snr,  unsigned char *value);

extern "C" int API_PCDInc( unsigned char   mode, unsigned char SectNum, unsigned char *snr, unsigned char *value);

extern "C" int GET_SNR( unsigned char mode, unsigned char API_halt, unsigned char *snr, unsigned char*value);

extern "C" int MF_Restore(unsigned char mode, int cardlength, unsigned char*carddata );

//ISO14443B
extern "C" int RequestType_B( unsigned char *buffer);

extern "C" int AntiType_B( unsigned char *buffer);

extern "C" int SelectType_B( unsigned char*SerialNum);

extern "C" int Request_AB( unsigned char* buffer);

extern "C" int API_ISO14443TypeBTransCOSCmd( unsigned char *cmd,  int cmdSize, unsigned char *buffer);

//ISO15693
extern "C" int API_ISO15693_Inventory( unsigned char flag, unsigned char afi, unsigned char *pData, unsigned char *nrOfCard, unsigned char *pBuffer);

extern "C" int API_ISO15693Read( unsigned char flags, unsigned char blk_add, unsigned char num_blk, unsigned char *uid, unsigned char *buffer);

extern "C" int API_ISO15693Write( unsigned char flags, unsigned char blk_add, unsigned char num_blk, unsigned char *uid, unsigned char *data);

extern "C" int API_ISO15693Lock( unsigned char flags, unsigned char num_blk, unsigned char *uid, unsigned char *buffer);

extern "C" int API_ISO15693StayQuiet( unsigned char flags, unsigned char *uid, unsigned char *buffer);

extern "C" int API_ISO15693Select( unsigned char flags, unsigned char *uid, unsigned char *buffer);

extern "C" int API_ResetToReady( unsigned char flags, unsigned char *uid, unsigned char *buffer);

extern "C" int API_WriteAFI( unsigned char flags, unsigned char afi, unsigned char *uid, unsigned char *buffer);

extern "C" int API_LockAFI( unsigned char flags, unsigned char *uid, unsigned char *buffer);

extern "C" int API_WriteDSFID( unsigned char flags, unsigned char DSFID, unsigned char *uid, unsigned char *buffer);

extern "C" int API_LockDSFID(unsigned char flags, unsigned char *uid, unsigned char *buffer );

extern "C" int API_ISO15693_GetSysInfo( unsigned char flags, unsigned char *uid, unsigned char *buffer);

extern "C" int API_ISO15693_GetMulSecurity( unsigned char flags, unsigned char blkAddr, unsigned char blkNum, unsigned char  *uid, unsigned char *pBuffer);

extern "C" int API_ISO15693TransCOSCmd( unsigned char *cmd, int cmdSize, unsigned char *buffer);

//ultralight
extern "C" int UL_HLRead(unsigned char mode, unsigned char blk_add, unsigned char *snr, unsigned char *buffer);

extern "C" int	UL_HLWrite( unsigned char mode, unsigned char blk_add, unsigned char *snr, unsigned char *buffer);

extern "C" int UL_Request( unsigned char mode,unsigned char *snr);
