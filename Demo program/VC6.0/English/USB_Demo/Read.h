#if !defined(AFX_Read_H__4D8E026C_6490_49EE_B102_4885B7AABF1F__INCLUDED_)
#define AFX_Read_H__4D8E026C_6490_49EE_B102_4885B7AABF1F__INCLUDED_

class CReader
{
    HINSTANCE m_hInstMaster;

public:
	CReader();
	~CReader();

	int LoadDll();
	int CloseDll();
	
	/******************* System Functions ******************************/
	int (WINAPI * ControlBuzzer)(int freq, int duration, BYTE *buffer);

	int (WINAPI * ControlLED)(int freq, int duration, BYTE *buffer);

	int (WINAPI * GetVersionNum)(char *VersionNum);

	int (WINAPI * SetSerNum)(BYTE *newValue, BYTE *buffer);

	int (WINAPI * GetSerNum)(BYTE *buffer);



	/******************* MIFARE High Level Functions ******************************/
	int (WINAPI * MF_Read)(int mode, int blk_add, int num_blk, BYTE *buf, BYTE *buffer);

	int (WINAPI * MF_Write)(int mode, int blk_add, int num_blk, BYTE *buf, BYTE *buffer);

	int (WINAPI * MF_InitValue)(int mode, int SectNum, BYTE *snr, BYTE *value);
      
	int (WINAPI * MF_Dec)(int mode, int SectNum, BYTE *snr, BYTE *value);

	int (WINAPI * MF_Inc)(int mode, int SectNum, BYTE *snr, BYTE *value);

	int (WINAPI * MF_Halt)();

	int (WINAPI * MF_Getsnr)(int mode, int halt, BYTE *snr, BYTE *value); 


	/******************* ISO14443 TYPE-B Functions ******************************/
	int (WINAPI * TypeB_Request)(BYTE *buffer);

	int (WINAPI * TypeB_TransCOS)(unsigned char  *cmd, int cmdSize, unsigned char *buffer);

	int (WINAPI * TYPEB_SFZSNR)(int mode, int halt, BYTE *snr, BYTE *value); 

	/******************* Ultralight Functions ******************************/
	int (WINAPI * UL_Request)(int mode, BYTE *snr);

	int (WINAPI * UL_HLRead)(int mode, int blk_add, BYTE *snr, BYTE *buffer);

	int (WINAPI *UL_HLWrite)(int mode, int blk_add, BYTE *snr, BYTE *buffer); 

	/******************* ISO15693 Functions ******************************/
	int (WINAPI * ISO15693_Inventory)(BYTE *Cardnumber, BYTE *pBuffer);

	int (WINAPI * ISO15693_Read)(int flags, int blk_add, int num_blk, BYTE *uid, BYTE *buffer);

	int (WINAPI * ISO15693_Write)(int flags, int blk_add, int num_blk, BYTE *uid, BYTE *data);
};

#endif // !defined(AFX_Read_H__4D8E026C_6490_49EE_B102_4885B7AABF1F__INCLUDED_)