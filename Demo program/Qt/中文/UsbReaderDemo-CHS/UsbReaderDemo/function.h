#ifndef FUNCTION_H
#define FUNCTION_H

/******************* System Functions ******************************/

typedef int (* ControlBuzzer_Func)(int freq, int duration, unsigned char *buffer);

typedef int (* ControlLED_Func)(int freq, int duration, unsigned char *buffer);

typedef int (* GetVersionNum_Func)(char *VersionNum);

typedef int (* SetSerNum_Func)(unsigned char *newValue, unsigned char *buffer);

typedef int (* GetSerNum_Func)(unsigned char *buffer);

/******************* MIFARE High Level Functions ******************************/
typedef int (* MF_Read_Func)(unsigned char mode, unsigned char blk_add, unsigned char num_blk, unsigned char *snr, unsigned char *buffer);

typedef int (* MF_Write_Func)(unsigned char mode, unsigned char blk_add, unsigned char num_blk, unsigned char *snr, unsigned char *buffer);

typedef int (* MF_InitValue_Func)(unsigned char mode, unsigned char SectNum, unsigned char *snr, unsigned char *value);
      
typedef int (* MF_Dec_Func)(unsigned char mode, unsigned char SectNum, unsigned char *snr, unsigned char *value);

typedef int (* MF_Inc_Func)(int mode, int SectNum, unsigned char *snr, unsigned char *value);

typedef int (* MF_Halt_Func)();

typedef int (* MF_Getsnr_Func)(int mode, int halt, unsigned char *snr, unsigned char *value);

/******************* ISO14443 Type B Functions ******************************/
typedef int (* TypeB_Request_Func)(unsigned char *buffer);

typedef int (* TYPEB_SFZSNR_Func)(unsigned char mode, unsigned char halt, unsigned char *snr, unsigned char *value);

typedef int (* TypeB_TransCOS_Func)(unsigned char *cmd, int cmdSize, unsigned char *buffer);


/******************* Ultralight Functions ******************************/
typedef int (* UL_Request_Func)(unsigned char mode, unsigned char *snr);

typedef int (* UL_HLRead_Func)(unsigned char mode, unsigned char blk_add, unsigned char *snr, unsigned char *buffer);

typedef int (* UL_HLWrite_Func)(unsigned char mode, unsigned char blk_add, unsigned char *snr, unsigned char *buffer);


/******************* ISO15693 Functions ******************************/
typedef int (* ISO15693_Inventory_Func)(unsigned char *Cardnumber, unsigned char *pBuffer);

typedef int (* ISO15693_Read_Func)(unsigned char flags, unsigned char blk_add, unsigned char num_blk, unsigned char *uid, unsigned char *buffer);

typedef int (* ISO15693_Write_Func)(unsigned char flags, unsigned char blk_add, unsigned char num_blk, unsigned char *uid, unsigned char *data);

typedef int (* ISO15693_GetSysInfo_Func)(unsigned char flag, unsigned char *uid, unsigned char *Buffer);

typedef int (* ISO15693_Lock_Func)(unsigned char flags, unsigned char num_blk, unsigned char *uid, unsigned char *buffer);

typedef int (* ISO15693_Select_Func)(unsigned char flags, unsigned char *uid, unsigned char *buffer);

typedef int (* ISO15693_WriteAFI_Func)(unsigned char flags, unsigned char afi, unsigned char *uid, unsigned char *buffer);

typedef int (* ISO15693_LockAFI_Func)(unsigned char flags, unsigned char *uid, unsigned char *buffer);

typedef int (* ISO15693_WriteDSFID_Func)(unsigned char flags, unsigned char DSFID, unsigned char *uid, unsigned char *buffer);

typedef int (* ISO15693_LockDSFID_Func)(unsigned char flags, unsigned char *uid, unsigned char *buffer);

typedef int (* ISO15693_GetMulSecurity_Func)(unsigned char flag, unsigned char blkAddr, unsigned char blkNum, const unsigned char *uid, unsigned char *pBuffer);


#endif