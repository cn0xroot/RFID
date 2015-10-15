package com.syc.function;

import org.xvolks.jnative.JNative;
import org.xvolks.jnative.Type;
import org.xvolks.jnative.pointers.Pointer;
import org.xvolks.jnative.pointers.memory.MemoryBlockFactory;

/**
 * 
 * @author Snail
 * @version v1.0
 *
 */

/**
 *RFID读卡器USB接口，Linux下的Java接口类。使用该包时，请将Function.jar,jNative.jar,libfunction.so,libJNativeCpp.so复制到工程目录下。导入 Function.jar,jNative.jar接口包。<br/> <br/>
 *<b>函数返回值代码表：</b><br/>
 *0x00 命令执行成功  <br/>
 *0x01 命令操作失败（失败原因请参考底层单片机上传代码表）<br/>
 *0x02 地址校验错误<br/>
 *0x03 没有选择COM口<br/>
 *0x04 读写器返回超时<br/>
 *0x05 数据包流水号不正确 <br/>
 *0x07 接收异常<br/>
 *0x0A  参数值超出范围 <br/> <br/>
 *<b>底层单片机上传代码表：</b><br/>
 *0x80 参数设置成功<br/>
 *0x81 参数设置失败<br/>
 *0x82 通讯超时 <br/>
 *0x83 卡不存在<br/>
 *0x84 接收卡数据出错<br/>
 *0x87 未知的错误<br/>
 *0x85 输入参数或者输入命令格式错误<br/>
 *0x8f 输入的指令代码不存在<br/>
 *0x8A 在对于卡块初始化命令中出现错误（仅用于14443命令）<br/>
 *0x8B 在防冲突过程中得到错误的序列号（仅用于14443命令）<br/>
 *0x8C 密码认证没通过（仅用于14443命令）<br/>
 *0x90 卡不支持这个命令（仅用于15693命令）<br/>
 *0x91 命令格式有错误（仅用于15693命令）<br/>
 *0x92 在命令的FLAG参数中，不支持OPTION 模式（仅用于15693命令）<br/>
 *0x93 要操作的BLOCK不存在（仅用于15693命令）<br/>
 *0x94 要操作的对象已经别锁定，不能进行修改（仅用于15693命令）<br/>
 *0x95 锁定操作不成功（仅用于15693命令）<br/>
 *0x96 写操作不成功（仅用于15693命令）<br/>
 */

public class Function {
	private static String functionLib = "libfunction.so";

	private static Pointer getPointer(byte[] s) {
		try {
			Pointer pointer = new Pointer(
					MemoryBlockFactory.createMemoryBlock(s.length));
			for (int i = 0; i < s.length; i++) {
				pointer.setByteAt(i, s[i]);
			}
			return pointer;
		} catch (Exception e) {
			System.out.print("Failed to get Pointer Data!");
			return null;
		}
	}

	private static void getPointerData(Pointer p, byte[] s) {
		try {
			for (int i = 0; i < p.getSize(); i++) {
				s[i] = p.getAsByte(i);
			}
		} catch (Exception e) {
			System.out.print("Failed to get Pointer Data!");
		}
	}

	private static int loadCommand(String functionName, int... parameter) {
		JNative n = null;
		try {
			n = new JNative(functionLib, functionName);
			n.setRetVal(Type.INT);
			int i = 0;
			for (int p : parameter) {
				n.setParameter(i++, p);
			}
			n.invoke();
			return Integer.parseInt(n.getRetVal());
		} catch (Exception e) {
			System.out.print("Failed to load libfunction.so");
			return 1;
		}
	}

	/**
	 * 系统命令：设置 8个字节的产品序列号。
	 * @param newValue 8个字节的读写器序列号.
	 * @param buffer 用来返回接收到的数据.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 设置成功：<br/>
	 * buffer=0x80<br/>
	 * 设置失败：<br/>
	 * 则buffer为底层（读卡器单片机）上传的错误代码。
	 */
	public static int API_SetSerNum(byte[] newValue, byte[] buffer) {
		Pointer newValuePtr = getPointer(newValue);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_SetSerNum", newValuePtr.getPointer(),
				bufferPtr.getPointer());
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * 系统命令：读取由厂家预设的1个字节的读卡器地址和8个字节序列号。
	 * @param buffer 用来返回接收到的数据。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * buffer[0] 读写器地址。<br/>
	 * buffer[1...8] 8个字节的读写器序列号。
	 */
	public static int API_GetSerNum(byte[] buffer) {
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_GetSerNum", bufferPtr.getPointer());
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * 系统命令：读卡器提供4个块（每个块不能大于120个字节），共480个字节空间的用户数据区。用户可以根据需要，储存相应的用户信息到读写器中。
	 * @param num_blk 区域号。
	 * @param num_length 数据长度。
	 * @param user_info 用户数据。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.
	 */
	public static int WriteUserInfo(int num_blk, int num_length,
			byte[] user_info) {
		Pointer user_infoPtr = getPointer(user_info);
		int result = loadCommand("WriteUserInfo", num_blk, num_length,
				user_infoPtr.getPointer());
		getPointerData(user_infoPtr, user_info);
		return result;
	}

	/**
	 * 系统命令：读取读卡器中提供4个块（每个块不能大于120个字节）的数据。
	 * @param num_blk 区域号。
	 * @param num_length 读取的数据长度。
	 * @param user_info 待读入的用户数据 。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.
	 */
	public static int ReadUserInfo(int num_blk, int num_length, byte[] user_info) {
		Pointer user_infoPtr = getPointer(user_info);
		int result = loadCommand("ReadUserInfo", num_blk, num_length,
				user_infoPtr.getPointer());
		getPointerData(user_infoPtr, user_info);
		return result;
	}

	/**
	 * 系统命令：读取读写器的版本号.
	 * @param VersionNum 待读入的版本号。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.
	 */
	public static int GetVersionNum(byte[] VersionNum) {
		Pointer VersionNumPtr = getPointer(VersionNum);
		int result = loadCommand("GetVersionNum", VersionNumPtr.getPointer());
		getPointerData(VersionNumPtr, VersionNum);
		return result;
	}

	/**
	 * 系统命令：设置灯的工作状态，包括，灯亮的周期以及循环的次数。
	 * @param freq 周期数。
	 * @param duration 次数。
	 * @param buffer 待返回的参数。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作失败，  则buffer[0]为 错误代码。<br/>
	 * 操作成功，  则buffer[0]为成功标志 ，即为0x80。
	 */
	public static int API_ControlLED(byte freq, byte duration, byte[] buffer) {
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_ControlLED", freq, duration,
				bufferPtr.getPointer());
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * 系统命令：设置蜂鸣器的工作状态，包括，蜂鸣器的工作周期以及循环的次数。
	 * @param freq 周期数。
	 * @param duration 次数。
	 * @param buffer 待返回的参数。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作失败，  则buffer[0]为 错误代码。<br/>
	 * 操作成功，  则buffer[0]为成功标志 ，即为0x80。
	 */
	public static int API_ControlBuzzer(byte freq, byte duration, byte[] buffer) {
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_ControlBuzzer", freq, duration,
				bufferPtr.getPointer());
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO14443A命令：发送ISO14443 A 寻卡指令。
	 * @param inf_mode 寻卡模式。<br/>
	 * 0x52–Idle模式（一次只对一张卡操作）。<br/>
	 * 0x26–All模式（一次可对多张卡操作）。
	 * @param buffer
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作失败，  则snr[0]为 错误代码。<br/>
	 * 操作成功，  则buffer[0..1]返回2个字节的数据串。
	 */
	public static int MF_Request(byte inf_mode, byte[] buffer) {
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("MF_Request", inf_mode, bufferPtr.getPointer());
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO14443A命令：检测卡片数量，单卡或多卡，并返回4个字节的卡号。（如果有多张卡，就返回其中一张卡的卡号）。
	 * @param snr 返回4个字节的卡号。
	 * @param status 返回卡片的数量。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功：<br/>
	 * status[0] 检测到的卡片的数量(0x00表示检测到单卡,0x01表示检测到多卡)。<br/>
	 * snr 4个字节的卡号（snr[0..3]）。 <br/>
	 * 操作失败：<br/>
	 * snr[0] 错误代码。
	 */
	public static int MF_Anticoll(byte[] snr, byte[] status) {
		Pointer snrPtr = getPointer(snr);
		Pointer statusPtr = getPointer(status);
		int result = loadCommand("MF_Anticoll", snrPtr.getPointer(),
				statusPtr.getPointer());
		getPointerData(snrPtr, snr);
		getPointerData(statusPtr, status);
		return result;
	}

	/**
	 * ISO14443A命令：使卡进入被选择的状态.
	 * @param snr 传入4个字节卡号，并且返回4个字节的卡号.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * snr 4个字节的卡号（snr[0..3]） 
	 */
	public static int MF_Select(byte[] snr) {
		Pointer snrPtr = getPointer(snr);
		int result = loadCommand("MF_Select", snrPtr.getPointer());
		getPointerData(snrPtr, snr);
		return result;
	}

	/**
	 * ISO14443A命令：选择卡，使卡进入被中断的状态.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.
	 */
	public static int MF_Halt() {
		int result = loadCommand("MF_Halt");
		return result;
	}

	/**
	 * ISO14443A命令：在指定位置读取指定长度的数据.
	 * @param mode 读取模式<br/>
	 * Idle+KeyA mode=00<br/>
	 * Idle+KeyB mode=02<br/>
	 * All+KeyA mode=01<br/>
	 * All+KeyB mode=03<br/>
	 * @param blk_add 读取块地址.
	 * @param num_blk 读取块数目.
	 * @param snr 六个字节的密钥.
	 * @param buffer 等待接受输出变量.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功:<br/>
	 * snr 4个字节的卡号.<br/>
	 * buffer 读取到的数据(具体数量为：num_blk*16).<br/>
	 * 操作失败:<br/>
	 * snr[0] 错误代码.
	 */
	public static int API_PCDRead(byte mode, byte blk_add, byte num_blk,
			byte[] snr, byte[] buffer) {
		Pointer snrPtr = getPointer(snr);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_PCDRead", mode, blk_add, num_blk,
				snrPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(snrPtr, snr);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO14443A命令：在指定位置写入数据.
	 * @param mode 读取模式<br/>
	 * Idle+KeyA mode=00<br/>
	 * Idle+KeyB mode=02<br/>
	 * All+KeyA mode=01<br/>
	 * All+KeyB mode=03<br/>
	 * @param blk_add 要写块地址.
	 * @param num_blk 要写块数目.
	 * @param snr 6字节密码.
	 * @param buffer 待写入的数据.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功:<br/>
	 * snr[0..3] 4个字节的卡号.<br/>
	 * 操作失败:<br/>
	 * snr[0] 错误代码.
	 */
	public static int API_PCDWrite(byte mode, byte blk_add, byte num_blk,
			byte[] snr, byte[] buffer) {
		Pointer snrPtr = getPointer(snr);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_PCDWrite", mode, blk_add, num_blk,
				snrPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(snrPtr, snr);
		return result;
	}

	/**
	 * ISO14443A命令：初始化卡.
	 * @param mode 读取模式<br/>
	 * Idle+KeyA mode=00<br/>
	 * Idle+KeyB mode=02<br/>
	 * All+KeyA mode=01<br/>
	 * All+KeyB mode=03<br/>
	 * @param SectNum 要初始化的扇区号00-0F.
	 * @param snr 6字节密钥.
	 * @param value  4 字节的要初始化的数据.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功:<br/>
	 * snr[0..3] 4个字节的卡号.<br/>
	 * 操作失败:<br/>
	 * snr[0] 错误代码.
	 */
	public static int API_PCDInitVal(byte mode, byte SectNum, byte[] snr,
			byte[] value) {
		Pointer snrPtr = getPointer(snr);
		Pointer valuePtr = getPointer(value);
		int result = loadCommand("API_PCDInitVal", mode, SectNum,
				snrPtr.getPointer(), valuePtr.getPointer());
		getPointerData(snrPtr, snr);
		return result;
	}

	/**
	 * ISO14443A命令：对卡的指定扇区进行减值操作。
	 * @param mode 读取模式<br/>
	 * Idle+KeyA mode=00<br/>
	 * Idle+KeyB mode=02<br/>
	 * All+KeyA mode=01<br/>
	 * All+KeyB mode=03<br/>
	 * @param SectNum 要写值的扇区号00-0F.
	 * @param snr 6字节密钥.
	 * @param value 要减的值，4个字节长度.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功:<br/>
	 * snr[0..3] 4个字节的卡号.<br/>
	 * value[0..3] 4个字节操作后的数据串.<br/>
	 * 操作失败:<br/>
	 * snr[0] 错误代码.
	 */
	public static int API_PCDDec(byte mode, byte SectNum, byte[] snr,
			byte[] value) {
		Pointer snrPtr = getPointer(snr);
		Pointer valuePtr = getPointer(value);
		int result = loadCommand("API_PCDDec", mode, SectNum,
				snrPtr.getPointer(), valuePtr.getPointer());
		getPointerData(snrPtr, snr);
		return result;
	}

	/**
	 * ISO14443A命令：对卡的指定扇区进行加值操作。
	 * @param mode 读取模式<br/>
	 * Idle+KeyA mode=00<br/>
	 * Idle+KeyB mode=02<br/>
	 * All+KeyA mode=01<br/>
	 * All+KeyB mode=03<br/>
	 * @param SectNum 要加值的扇区号00-0F.
	 * @param snr 6字节密钥.
	 * @param value 要加的值，4个字节长度.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功:<br/>
	 * snr[0..3] 4个字节的卡号.<br/>
	 * value[0..3] 4个字节操作后的数据串.<br/>
	 * 操作失败:<br/>
	 * snr[0] 错误代码.
	 */
	public static int API_PCDInc(byte mode, byte SectNum, byte[] snr,
			byte[] value) {
		Pointer snrPtr = getPointer(snr);
		Pointer valuePtr = getPointer(value);
		int result = loadCommand("API_PCDInc", mode, SectNum,
				snrPtr.getPointer(), valuePtr.getPointer());
		getPointerData(snrPtr, snr);
		return result;
	}

	/**
	 * ISO14443A命令：返回1个字节的单卡或多卡标识，4个字节的卡号。
	 * @param mode 模式控制.<br/>
	 * 0x26–Idle模式（一次只对一张卡操作）.<br/>
	 * 0x52–All模式（一次可对多张卡操作).
	 * @param API_halt
	 * @param snr
	 * @param value
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功:<br/>
	 * snr[0] 1个字节的单卡或多卡标识.<br/>
	 * value[0..3] 返回的4个字节的卡号.<br/>
	 * 操作失败:<br/>
	 * snr[0] 错误代码.
	 */
	public static int GET_SNR(byte mode, byte API_halt, byte[] snr, byte[] value) {
		Pointer snrPtr = getPointer(snr);
		Pointer valuePtr = getPointer(value);
		int result = loadCommand("GET_SNR", mode, API_halt,
				snrPtr.getPointer(), valuePtr.getPointer());
		getPointerData(snrPtr, snr);
		getPointerData(valuePtr, value);
		return result;
	}

	/**
	 * ISO14443A命令：按照选择的模式，进行数据的发送.
	 * @param mode 模式控制.<br/>
	 * 0x00—不需要进行CRC校验.<br/>
	 * 0x01—需要进行CRC校验.
	 * @param cardlength
	 * @param carddata
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功：<br/>
	 * carddata[0..N] 接收返回数据。<br/>
	 * 操作失败：<br/>
	 * carddata[0] 错误代码.
	 */
	public static int MF_Restore(byte mode, int cardlength, byte[] carddata) {
		Pointer carddataPtr = getPointer(carddata);
		int result = loadCommand("MF_Restore", mode, cardlength,
				carddataPtr.getPointer());
		getPointerData(carddataPtr, carddata);
		return result;
	}

	/**
	 * ISO14443B命令：该命令执行ISO14443B中的REQB命令，获取卡片的PUPI代码。
	 * @param buffer 卡片复位后的数据串 （ATQB）。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功：<br/>
	 * buffer 卡片复位后的数据串（ATQB）.<br/>
	 * buffer[0] 卡片复位数据的长度.<br/>
	 * buffer[1..N] 操作后的数据串（ATQB）.<br/>
	 * 操作失败：<br/>
	 * buffer[0] 错误代码.
	 */
	public static int RequestType_B(byte[] buffer) {
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("RequestType_B", bufferPtr.getPointer());
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO14443B命令：该命令执行ISO14443B中的AnticollB命令.
	 * @param buffer 卡片返回的数据串（ATQB）.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 如果操作成功：<br/>
	 * buffer[0..N] 卡片返回的数据串（ATQB）.<br/>
	 * 如果操作失败：<br/>
	 * buffer[0] 错误代码.
	 */
	public static int AntiType_B(byte[] buffer) {
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("AntiType_B", bufferPtr.getPointer());
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO14443B命令：该命令执行ISO14443B中的ATTRIB命令，给已知PUPI的卡片分配一个识别号CID.
	 * @param SerialNum 卡的序列号.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.
	 */
	public static int SelectType_B(byte[] SerialNum) {
		Pointer SerialNumPtr = getPointer(SerialNum);
		int result = loadCommand("SelectType_B", SerialNumPtr.getPointer());
		getPointerData(SerialNumPtr, SerialNum);
		return result;
	}

	/**
	 * ISO14443B命令：该命令执行几集成了ISO14443B中的，REQUEST和ATTRIB命令，通过一个命令使卡复位。
	 * @param buffer 返回操作后的卡的序列号4个字节.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 如果操作成功：<br/>
	 * buffer[0..3] 返回操作后的卡的序列号4个字节.<br/>
	 * 如果操作失败：<br/>
	 * buffer[0] 错误代码.
	 */
	public static int Request_AB(byte[] buffer) {
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("Request_AB", bufferPtr.getPointer());
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO14443B命令：ISO14443传送命令，可以通过此命令向卡发任意有效的命令，数据.
	 * @param cmd 待发送的数据.
	 * @param cmdSize 数据长度.
	 * @param buffer 回收的数据.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功，则buffer[0..N] 为从卡返回的数据.<br/>
	 * 操作失败，则buffer[0] 为错误代码.
	 */
	public static int API_ISO14443TypeBTransCOSCmd(byte[] cmd, int cmdSize,
			byte[] buffer) {
		Pointer cmdPtr = getPointer(cmd);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_ISO14443TypeBTransCOSCmd",
				cmdPtr.getPointer(), cmdSize, bufferPtr.getPointer());
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：此命令通过防冲突用于得到读卡区域内所有卡片的序列号（能得到的卡片数量与模块天线的输出功率有关，一般能对2~6卡进行防冲突）.
	 * @param flag 标识字节1个字节.
	 * @param afi AFI就是数据长度.
	 * @param pData 发送的数据.
	 * @param nrOfCard 返回的卡的数量.
	 * @param pBuffer 返回的数据（包括FLAG和DSFID和8[]n个字节的卡号）.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功:<br/>
	 * nrOfCard 返回的卡的数量（一个字节）.<br/>
	 * pBuffer 返回的数据（包括FLAG和DSFID和8*n个字节的卡号）.<br/>
	 * 操作失败:<br/>
	 * nrOfCard 错误代码.
	 */
	public static int API_ISO15693_Inventory(byte flag, byte afi, byte[] pData,
			byte[] nrOfCard, byte[] pBuffer) {
		Pointer pDataPtr = getPointer(pData);
		Pointer nrOfCardPtr = getPointer(nrOfCard);
		Pointer pBufferPtr = getPointer(pBuffer);
		int result = loadCommand("API_ISO15693_Inventory", flag, afi,
				pDataPtr.getPointer(), nrOfCardPtr.getPointer(),
				pBufferPtr.getPointer());
		getPointerData(pDataPtr, pData);
		getPointerData(nrOfCardPtr, nrOfCard);
		getPointerData(pBufferPtr, pBuffer);
		return result;
	}

	/**
	 * ISO15693命令：用来读取1个或多个扇区的值，如果要读每个块的安全位，将FLAGS中Option_flag置为1，即FLAG = 0X42，每个扇区将返回5个字节，包括1个表示安全状态字节和4个字节的块内容，这时候每次最多能读12个块。如果FLAG = 02，将只返回4字节的块内容，这时候每次最多能读63个块。
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param blk_add 要读的起始块号。
	 * @param num_blk 块的数量。
	 * @param uid UID信息。
	 * @param buffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功：<br/>
	 * buffer[0] 返回的flag。<br/>
	 * buffer[1..N] Data。<br/>
	 * 操作失败：<br/>
	 * buffer[0]为错误代码。
	 */
	public static int API_ISO15693Read(byte flags, byte blk_add, byte num_blk,
			byte[] uid, byte[] buffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_ISO15693Read", flags, blk_add, num_blk,
				uidPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：对一个块进行写操作（每次只能写一个块）。
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param blk_add 要写的起始块号。
	 * @param num_blk 写的块的数量。
	 * @param uid UID信息。
	 * @param data 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作失败，则data[0]为错误代码
	 */
	public static int API_ISO15693Write(byte flags, byte blk_add, byte num_blk,
			byte[] uid, byte[] data) {
		Pointer uidPtr = getPointer(uid);
		Pointer dataPtr = getPointer(data);
		int result = loadCommand("API_ISO15693Write", flags, blk_add, num_blk,
				uidPtr.getPointer(), dataPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(dataPtr, data);
		return result;
	}

	/**
	 * ISO15693命令：用于锁定块内容。注意：此过程不可逆（不能解锁）块锁定后内容不能在修改。
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param num_blk 要锁的块号。
	 * @param uid UID信息。
	 * @param buffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功，则buffer[0]值为0x80。 <br/>
	 * 操作失败，则buffer[0]为错误代码。
	 */
	public static int API_ISO15693Lock(byte flags, byte num_blk, byte[] uid,
			byte[] buffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_ISO15693Lock", flags, num_blk,
				uidPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：此命令用于将卡置于静止的状态, 必须用地址模式，如果发送的数据与被操作的卡的序列号相同，操作成功后，卡将进入静止状态，否则状态不变。
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param uid UID信息。
	 * @param buffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功，则buffer[0]值为0x80。 <br/>
	 * 操作失败，则buffer[0]为错误代码。
	 */
	public static int API_ISO15693StayQuiet(byte flags, byte[] uid,
			byte[] buffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_ISO15693StayQuiet", flags,
				uidPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：此命令必须用地址模式，如果发送的数据与被操作的卡的序列号相同，操作成功后，卡将进入被选择状态，否则状态不变。
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param uid UID信息。
	 * @param buffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功，则buffer[0]值为0x80。 <br/>
	 * 操作失败，则buffer[0]为错误代码。
	 */
	public static int API_ISO15693Select(byte flags, byte[] uid, byte[] buffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_ISO15693Select", flags,
				uidPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：操作成功后，卡回到Ready状态。
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param uid UID信息。
	 * @param buffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功，则buffer[0]值为0x80。 <br/>
	 * 操作失败，则buffer[0]为错误代码
	 */
	public static int API_ResetToReady(byte flags, byte[] uid, byte[] buffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_ResetToReady", flags,
				uidPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：对卡进行写AFI操作。
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param afi 待写的AFI.
	 * @param uid UID信息。
	 * @param buffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功，则buffer[0]值为0x80。 <br/>
	 * 操作失败，则buffer[0]为错误代码
	 */
	public static int API_WriteAFI(byte flags, byte afi, byte[] uid,
			byte[] buffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_WriteAFI", flags, afi,
				uidPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：用于锁定卡的AFI，锁定后AFI不可以更改。
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param uid UID信息。
	 * @param buffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功，则buffer[0]值为0x80。 <br/>
	 * 操作失败，则buffer[0]为错误代码
	 */
	public static int API_LockAFI(byte flags, byte[] uid, byte[] buffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_LockAFI", flags, uidPtr.getPointer(),
				bufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：对卡的进行写DSFID操作.
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param DSFID 要写的DSFID字节，长度为1个字节.
	 * @param uid UID信息。
	 * @param buffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功，则buffer[0]值为0x80。 <br/>
	 * 操作失败，则buffer[0]为错误代码
	 */
	public static int API_WriteDSFID(byte flags, byte DSFID, byte[] uid,
			byte[] buffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_WriteDSFID", flags, DSFID,
				uidPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：用于锁定卡的DSFID，锁定后DSFID不可以更改.
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param uid UID信息。
	 * @param buffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功，则buffer[0]值为0x80。 <br/>
	 * 操作失败，则buffer[0]为错误代码
	 */
	public static int API_LockDSFID(byte flags, byte[] uid, byte[] buffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_LockDSFID", flags, uidPtr.getPointer(),
				bufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：用于得到卡的详细信息，具体内容请参考，ISO15693协议资料。
	 * @param flags 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param uid UID信息。
	 * @param buffer 返回值.
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功：<br/>
	 * Buffer [0]:	Flags<br/>
	 * Buffer [1]:	INFO Flags<br/>
	 * Buffer [2..9]:	UID<br/>
	 * Buffer [10]:	DSFID<br/>
	 * Buffer [11]:	AFI<br/>
	 * Buffer [12..N]: Other fields<br/>
	 * 操作失败，则Buffer[0] 返回 为错误代码。
	 */
	public static int API_ISO15693_GetSysInfo(byte flags, byte[] uid,
			byte[] buffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_ISO15693_GetSysInfo", flags,
				uidPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * ISO15693命令：用于获取卡的各个块的安全状态位的数据
	 * @param flag 标志位。<br/>
	 * 0x02  不带uid。<br/>
	 * 0x22    带uid。<br/>
	 * 0x42  不带uid但是要读安全位。
	 * @param blkAddr 要读的起始块号。
	 * @param blkNum 读的块的数量。
	 * @param uid UID信息。
	 * @param pBuffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功：<br/>
	 * pBuffer 返回的数据。<br/>
	 * pBuffer[0]  返回的flags。<br/>
	 * pBuffer [1..N]  Block security status (块的安全状态)。 <br/>
	 * 操作失败，则pBuffer[0]为错误代码。
	 */
	public static int API_ISO15693_GetMulSecurity(byte flags, byte blkAddr,
			byte blkNum, byte[] uid, byte[] pBuffer) {
		Pointer uidPtr = getPointer(uid);
		Pointer pBufferPtr = getPointer(pBuffer);
		int result = loadCommand("API_ISO15693_GetMulSecurity", flags, blkAddr,
				blkNum, uidPtr.getPointer(), pBufferPtr.getPointer());
		getPointerData(uidPtr, uid);
		getPointerData(pBufferPtr, pBuffer);
		return result;
	}

	/**
	 * ISO15693命令：一个通用命令，用户可以通过此命令，对卡进行各种操作。
	 * @param cmd 需要发送的数据。
	 * @param cmdSize 数据长度。
	 * @param buffer 返回值。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功：<br/>
	 * buffer 返回的数据。<br/>
	 * buffer[0..N] 从卡返回的数据。<br/>
	 * 操作失败，则buffer[0]为错误代码。
	 */
	public static int API_ISO15693TransCOSCmd(byte[] cmd, int cmdSize,
			byte[] buffer) {
		Pointer cmdPtr = getPointer(cmd);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("API_ISO15693TransCOSCmd",
				cmdPtr.getPointer(), cmdSize, bufferPtr.getPointer());
		getPointerData(cmdPtr, cmd);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * Ultralight命令：发送Ultralight读卡命令。
	 * @param mode 寻卡模式 。<br/>
	 * 0x00–Idle模式。<br/>
	 * 0x01–All模式。
	 * @param blk_add 写卡扇区号。
	 * @param snr 返回7个字节的卡号。
	 * @param buffer 返回16个字节的卡数据。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 如果操作成功：<br/>
	 * snr 7个字节的卡号.<br/>
	 * buffer 16个字节的卡数据.<br/>
	 * 如果操作失败：<br/>
	 * buffer[0] 错误代码。
	 */
	public static int UL_HLRead(byte mode, byte blk_add, byte[] snr,
			byte[] buffer) {
		Pointer snrPtr = getPointer(snr);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("UL_HLRead", mode, blk_add,
				snrPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(snrPtr, snr);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * Ultralight命令：发送Ultralight写卡命令。
	 * @param mode 寻卡模式 。<br/>
	 * 0x00–Idle模式。<br/>
	 * 0x01–All模式。
	 * @param blk_add 写卡扇区号。
	 * @param snr 返回7个字节的卡号。
	 * @param buffer 四个字节的写入卡扇区的数据。
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 如果操作成功：<br/>
	 * snr 7个字节的卡号.<br/>
	 * buffer 16个字节的卡数据.<br/>
	 * 如果操作失败：<br/>
	 * buffer[0] 错误代码。
	 */
	public static int UL_HLWrite(byte mode, byte blk_add, byte[] snr,
			byte[] buffer) {
		Pointer snrPtr = getPointer(snr);
		Pointer bufferPtr = getPointer(buffer);
		int result = loadCommand("UL_HLWrite", mode, blk_add,
				snrPtr.getPointer(), bufferPtr.getPointer());
		getPointerData(snrPtr, snr);
		getPointerData(bufferPtr, buffer);
		return result;
	}

	/**
	 * Ultralight命令：发送Ultralight寻卡指令。
	 * @param mode 寻卡模式 。<br/>
	 * 0x00–Idle模式。<br/>
	 * 0x01–All模式。
	 * @param snr 待返回的参数 
	 * @return 0x00	设置成功.<br/>
	 * 0x01	设置失败.<br/><br/>
	 * 操作成功，  则snr [0..6]，返回7个字节的数据串。<br/>
	 * 操作失败，  则snr [0] 为 错误代码。
	 */
	public static int UL_Request(byte mode, byte[] snr) {
		Pointer snrPtr = getPointer(snr);
		int result = loadCommand("UL_Request", mode, snrPtr.getPointer());
		getPointerData(snrPtr, snr);
		return result;
	}

}