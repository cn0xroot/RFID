using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace CSharpDEMO
{
    class Reader
    {

        /*System Setting*/
        [DllImport("function.dll")]

        public static extern int SetSerNum(byte[] newValue, [In]byte[] buffer);
        /*
            函数功能：设置 8个字节的产品序列号。

            输入参数：　　　　　　描述
                newValue    8个字节的读写器序列号
                buffer      用来返回接收到的数据的指针    

            输出参数：

                buffer      返回STATUS后的状态
     *                      如果设置成功，则*buffer=0x 80
                            如果设置失败，则*buffer为底层（读卡器单片机）上传的错误代码

            返回值：
                0x00，设置成功
                0x01，设置失败
         */

        [DllImport("function.dll")]

        public static extern int GetSerNum([In]byte[] buffer);
        /*
            函数功能：
                读取由厂家预设的1个字节的读卡器地址和8个字节序列号. 

            输入参数：
               buffer          传入一个指针，用来返回接收到的数据     

            输出参数：

                buffer         buffer[0]   读写器地址
                               buffer[1...8]   8个字节的读写器序列号

            返回值：
                0x00，操作成功
                0x01，操作失败
         */

        [DllImport("function.dll")]

        public static extern int GetVersionNum([In]byte[] strVersionNum);
        /*
         函数功能：
                读取读写器的版本号.

        输入参数：
                VersionNum      待读入的版本号    
          
        输出参数：
                *VersionNum       
         *                      如果 ：操作失败，  则VersionNum [0] 为 错误代码
                                如果 ：操作成功，  则VersionNum [0..N] 为读入的版本号
        返回值：
             0x00，操作成功
             0x01，操作失败
         */

        [DllImport("function.dll")]

        public static extern int ControlLED(int freq,int duration,[In]byte[] buffer);
        /*
         函数功能： 设置读卡器的错误提示

        输入参数：
            buffer          待返回的参数 
          
        输出参数：
            buffer          如果 ：操作失败，  则buffer [0] 为 错误代码（参考2.2）
                            如果 ：操作成功，  则buffer [0] 为成功标志 ，即为0x80

        返回值：
             0x00，操作成功，  
             0x01，操作失败 
         */

        [DllImport("function.dll")]

        public static extern int ControlBuzzer(int freq, int duration,[In]byte[] buffer);
        /*
         函数功能： 控制读卡器的正确提示

        输入参数：
            buffer        待返回的参数 
          
        输出参数：
            buffer          如果 ：操作失败，  则buffer [0] 为 错误代码（参考2.2）
                             如果 ：操作成功，  则buffer [0] 为成功标志 ，即为0x80

        返回值：
             0x00，操作成功，  
             0x01，操作失败 
         */

        /*14443A-MF*/
        [DllImport("function.dll")]
        public static extern int MF_Read(byte mode, byte blk_add, byte num_blk, [In]byte[] snr, [In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int MF_Write(byte mode, byte blk_add, byte num_blk, [In]byte[] snr, [In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int MF_InitValue(byte mode, byte SectNum, [In]byte[] snr, [In]byte[] value);

        [DllImport("function.dll")]
        public static extern int MF_Dec(byte mode, byte SectNum, [In]byte[] snr, [In]byte[] value);

        [DllImport("function.dll")]
        public static extern int MF_Inc(byte mode, byte SectNum, [In]byte[] snr, [In]byte[] value);

        [DllImport("function.dll")]
        public static extern int MF_Request([In]byte[] commHandle, int DeviceAdddress, byte inf_mode, [In]byte[] Buffer);

        [DllImport("function.dll")]
        public static extern int MF_Select([In]byte[] commHandle, int DeviiceAddress, byte inf_mode, [In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int MF_Halt();

        [DllImport("function.dll")]
        public static extern int MF_Anticoll([In]byte[] commHandle, int DeviceAddress, [In]byte[] snr, [In]byte[] status);

        [DllImport("function.dll")]
        public static extern int MF_Restore([In]byte[] commHandle, int DeviceAddress, byte mode, byte cardlength, [In]byte[] carddata);

        [DllImport("function.dll")]
        public static extern int MF_Getsnr(int mode, int halt, [In]byte[] snr, [In]byte[] value);


        /*Ultralight*/
        [DllImport("function.dll")]
        public static extern int UL_Request(byte mode, [In]byte[] snr);

        [DllImport("function.dll")]
        public static extern int UL_HLRead(byte mode, byte blk_add, [In]byte[] snr, [In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int UL_HLWrite(byte mode, byte blk_add, [In]byte[] snr, [In]byte[] buffer);


        /*ISO14443TypeB*/
        [DllImport("function.dll")]
        public static extern int TypeB_Request([In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int TYPEB_SFZSNR(byte mode, byte halt, [In]byte[] snr, [In]byte[] value);

        [DllImport("function.dll")]
        public static extern int TypeB_TransCOS([In]byte[] cmd, int cmdSize, [In]byte[] buffer);



        /*ISO15693*/
        
        [DllImport("function.dll")]
        public static extern int ISO15693_Inventory([In]byte[] Cardnumber, [In]byte[] pBuffer);
        /*
           函数功能：此命令通过防冲突用于得到读卡区域内所有卡片的序列号（能得到的卡片数量与模块天线的输出功率有关，一般能对2~6卡进行防冲突）

           输入参数：
               Cardnumber       返回的卡的数量（一个字节）
               pBuffer          返回的数据（包括FLAG和DSFID和8*n个字节的卡号）

           输出参数：
               如果：操作成功
                   Cardnumber       返回的卡的数量（一个字节）
                   pBuffer          返回的数据（包括FLAG和DSFID和8*n个字节的卡号）
                        
               如果：操作失败，则*nrOfCard为错误代码

           返回值：
               0x00，操作成功，  
               0x01，操作失败
        */

        [DllImport("function.dll")]
        public static extern int ISO15693_Read(byte flags, byte blk_add, byte num_blk, [In]byte[] uid, [In]byte[] buffer);
        /*
            函数功能：
	            用来读取1个或多个扇区的值，如果要读每个块的安全位，
                将FLAGS中Option_flag置为1，即FLAG = 0X42，每个扇区将返回5个字节，包括1个表示安全状态字节和4个字节的块内容，这时候每次最多能读12个块。
                如果FLAG = 02，将只返回4字节的块内容，这时候每次最多能读63个块。

            输入参数：
                flags          0x02  不带uid
                               0x22    带uid
                               0x42  不带uid但是要读安全位
                blk_add,       要读的起始块号
                num_blk,       块的数量
                *uid           UID信息
                *buffer        返回值

            输出参数：
                操作成功,buffer[0]  返回的flag   buffer[1..N]  Data   
                操作失败，buffer[0]为错误代码

            返回值：
                0x00，操作成功，  
                0x01，操作失败
         */

        [DllImport("function.dll")]
        public static extern int ISO15693_Write(byte flag, byte blk_add, byte num_blk, [In]byte[] uid, [In]byte[] data);
        /*
            函数功能：  对一个块进行写操作（每次只能写一个块）

            输入参数：
                flags         0x02  不带uid
                              0x22    带uid
                              0x42  不带uid但是要读安全位
                blk_add,      要写的起始块号
                num_blk,      写的块的数量
                *uid          UID信息
                *data         返回值

            输出参数：
                如果：操作失败，则data[0]为错误代码

            返回值：
                0x00，操作成功，  
                0x01，操作失败
         */

        [DllImport("function.dll")]
        public static extern int ISO15693_GetSysInfo(byte flag, [In]byte[] uid, [In]byte[] Buffer);

        [DllImport("function.dll")]
        public static extern int ISO15693_Lock(byte flags, byte num_blk, [In]byte[] uid, [In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int ISO15693_Select(byte flags, [In]byte[] uid, [In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int ISO15693_WriteAFI(byte flags, byte afi, [In]byte[] uid, [In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int ISO15693_LockAFI(byte flags, [In]byte[] uid, [In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int ISO15693_WriteDSFID(byte flags, byte DSFID, [In]byte[] uid, [In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int ISO15693_LockDSFID(byte flags, [In]byte[] uid, [In]byte[] buffer);

        [DllImport("function.dll")]
        public static extern int ISO15693_GetMulSecurity(byte flag, byte blkAddr, byte blkNum, [In]byte[] uid, [In]byte[] pBuffer);
    }
}
