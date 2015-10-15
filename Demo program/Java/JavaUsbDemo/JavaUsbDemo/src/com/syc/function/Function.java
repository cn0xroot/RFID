package com.syc.function;
import org.xvolks.jnative.JNative;
import org.xvolks.jnative.Type;
import org.xvolks.jnative.pointers.Pointer;
import org.xvolks.jnative.pointers.memory.MemoryBlockFactory;

public class Function {
	public static Pointer a,b;
	public static String reason="";
	public static int int0,int1;
	public static byte byte0,byte1;
	public static void falsereason(String s)
	{
		 //System.out.println(s);
		 if( s.equals(""   ) ) {  reason=""; return;}
	     if( s.equals("00" ) ) {  reason=""; return;} 
	     if( s.equals("1"  ) ) {  reason="Command false.....";   return;}
	     if( s.equals("2"  ) ) {  reason="checksum error.....";  return;}
	     if( s.equals("3"  ) ) {  reason="Not selected COM port.....";  return;}
	     if( s.equals("4"  ) ) {  reason="time out reply.....";       return;}
	     if( s.equals("5"  ) ) {  reason="check sequence error.....";    return;}
	     if( s.equals("7"  ) ) {  reason="check sum error.....";   return;}
	     if( s.equals("10" ) ) {  reason="the parameter value out of range.....";  return;}
	     if( s.equals("80" ) ) {  reason="Command OK.....";    return;}
	     if( s.equals("81" ) ) {  reason="Command FAILURE....";   return;}
	     if( s.equals("82" ) ) {  reason="Reader reply time out error....";  return;}
	     if( s.equals("83" ) ) {  reason="The card is not exist....";     return;}
	     if( s.equals("84" ) ) {  reason="the data is error....";   return;}
	     if( s.equals("85" ) ) {  reason="Reader received unknown command....";      return;}
	     if( s.equals("87" ) ) {  reason="error....";    return;}
	     if( s.equals("89" ) ) {  reason="The parameter of the command or the Format of the command Erro...";   return;}
	     if( s.equals("8A" ) ) {  reason="Some Erro appear in the card InitVal process...";      return;}
	     if( s.equals("8B" ) ) {  reason="Get The Wrong Snr during anticollison loop....";       return;}
	     if( s.equals("8C" ) ) {  reason="The authentication failure....";    return;}
	     if( s.equals("8F" ) ) {  reason="Reader received unknown command....";   return;}
	     if( s.equals("90" ) ) {  reason="The Card do not support this command....";   return;}
	     if( s.equals("91" ) ) {  reason="The Foarmat Of  The Command Erro....";        return;}
	     if( s.equals("92" ) ) {  reason="Do not support Option mode....";     return;}
	     if( s.equals("93" ) ) {  reason="The Block Do Not Exist....";   return;}
	     if( s.equals("94" ) ) {  reason="The Object have been locked....";   return;}
	     if( s.equals("95" ) ) {  reason="The lock Operation Do Not Success....";  return;}
	     if( s.equals("96" ) ) {  reason="The Operation Do Not Success....";   return;}
	}
	public static int MF_Read()
	{
		return 1;
	}
	public static int MF_Halt()
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "MF_Halt");   
            n.setRetVal(Type.INT);
            n.invoke();
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int GetVersionNum()
	{
		
		JNative n = null;
		try{
			n = new JNative("function.dll","GetVersionNum");
			n.setRetVal(Type.INT);
			a = new Pointer(MemoryBlockFactory.createMemoryBlock(64));
			n.setParameter(0, a);
			n.invoke();
			return Integer.parseInt(n.getRetVal());
		}catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
		}
	}
	public static int GetSerNum()
	{
		
		JNative n = null;
		try{
			n = new JNative("function.dll","GetSerNum");
			n.setRetVal(Type.INT);
			a = new Pointer(MemoryBlockFactory.createMemoryBlock(64));
			n.setParameter(0, a);
			n.invoke();
			return Integer.parseInt(n.getRetVal());
		}catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
		}
	}
	public static int SetSerNum(Pointer p)
	{
		
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "SetSerNum");   
            n.setRetVal(Type.INT);
            n.setParameter(0,p);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(1));
            n.setParameter(1,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ControlLED(int arg0 , int arg1)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ControlLED");   
            n.setRetVal(Type.INT);
            n.setParameter(0,arg0);
            n.setParameter(1, arg1);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
            n.setParameter(2,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ControlBuzzer(int arg0 , int arg1)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ControlBuzzer");   
            n.setRetVal(Type.INT);
            n.setParameter(0,arg0);
            n.setParameter(1,arg1);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(1));
            n.setParameter(2,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int MF_Read(byte mode,byte add_blk,byte num_blk,Pointer p)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "MF_Read");   
            n.setRetVal(Type.INT);
            n.setParameter(0,mode);
            n.setParameter(1, add_blk);
            n.setParameter(2, num_blk);
            n.setParameter(3, p);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(16*num_blk));
            n.setParameter(4,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            b = p;
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int MF_Write(byte mode,byte add_blk,byte num_blk,Pointer p,Pointer p2)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "MF_Write");   
            n.setRetVal(Type.INT);
            n.setParameter(0,mode);
            n.setParameter(1, add_blk);
            n.setParameter(2, num_blk);
            n.setParameter(3, p);
            n.setParameter(4, p2);
            n.invoke();
            byte0 = p2.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int MF_InitValue(byte mode,byte secNum,Pointer p,Pointer v)
	{
		
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "MF_InitValue");   
            n.setRetVal(Type.INT);
            n.setParameter(0,mode);
            n.setParameter(1,secNum);
            n.setParameter(2, p);
            n.setParameter(3, v);
            n.invoke();
            byte0 = p.getAsByte(0);
            b = p;
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int MF_Dec(byte mode,byte secNum,Pointer p,Pointer v)
	{
		
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "MF_Dec");   
            n.setRetVal(Type.INT);
            n.setParameter(0,mode);
            n.setParameter(1,secNum);
            n.setParameter(2, p);
            n.setParameter(3, v);
            n.invoke();
            byte0 = p.getAsByte(0);
            b = p;
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int MF_Inc(byte mode,byte secNum,Pointer p,Pointer v)
	{
		
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "MF_Inc");   
            n.setRetVal(Type.INT);
            n.setParameter(0,mode);
            n.setParameter(1,secNum);
            n.setParameter(2, p);
            n.setParameter(3, v);
            n.invoke();
            byte0 = p.getAsByte(0);
            b = p;
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int MF_Getsnr(byte mode,byte halt,Pointer p,Pointer v)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "MF_Getsnr");   
            n.setRetVal(Type.INT);
            n.setParameter(0,mode);
            n.setParameter(1,halt);
            n.setParameter(2, p);
            n.setParameter(3, v);
            n.invoke();
            byte0 = p.getAsByte(0);
            b = v;
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int UL_Request(byte mode)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "UL_Request");   
            n.setRetVal(Type.INT);
            n.setParameter(0,mode);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(64));
            n.setParameter(1,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int UL_HLRead(byte mode,byte blk_add)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "UL_HLRead");   
            n.setRetVal(Type.INT);
            n.setParameter(0,mode);
            n.setParameter(1,blk_add);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
            b = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
            n.setParameter(2, a);
            n.setParameter(3, b);
            n.invoke();
            byte0 = b.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int UL_HLWrite(byte mode,byte blk_add,Pointer p)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "UL_HLWrite");   
            n.setRetVal(Type.INT);
            n.setParameter(0,mode);
            n.setParameter(1,blk_add);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(7));
            n.setParameter(2, a);
            n.setParameter(3, p);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int TypeB_Request()
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "TypeB_Request");   
            n.setRetVal(Type.INT);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
            n.setParameter(0, a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int TypeB_TransCOS(Pointer cmd,int cmdSize)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "TypeB_TransCOS");   
            n.setRetVal(Type.INT);
            n.setParameter(0,cmd);
            n.setParameter(1,cmdSize);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
            n.setParameter(2, a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
		
	}
	public static int TYPEB_SFZSNR(byte mode,byte halt)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "TYPEB_SFZSNR");   
            n.setRetVal(Type.INT);
            n.setParameter(0,mode);
            n.setParameter(1, halt);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(1));
            n.setParameter(2,a);
            b = new Pointer(MemoryBlockFactory.createMemoryBlock(8));
            n.setParameter(3,b);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_Inventory()
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_Inventory");   
            n.setRetVal(Type.INT);
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(1));
            n.setParameter(0,a);
            b = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
            n.setParameter(1,b);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_Read(byte flags,byte blk_add,byte num_blk,Pointer uid)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_Read");   
            n.setRetVal(Type.INT);
            n.setParameter(0,flags);
            n.setParameter(1,blk_add);
            n.setParameter(2,num_blk);
            //unsigned char uid[256]
            n.setParameter(3,uid);
            //unsigned char buffer[256]
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
            n.setParameter(4,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            b = uid;
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_Write(byte flags,byte blk_add,byte num_blk,Pointer uid,Pointer data)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_Write");   
            n.setRetVal(Type.INT);
            n.setParameter(0,flags);
            n.setParameter(1,blk_add);
            n.setParameter(2,num_blk);
            //unsigned char uid[256]
            n.setParameter(3,uid);
            //unsigned char data[256]
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
            n.setParameter(4,data);
            n.invoke();
            byte0 = data.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_Lock(byte flags,byte num_blk,Pointer uid)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_Lock");   
            n.setRetVal(Type.INT);
            n.setParameter(0,flags);
            n.setParameter(1,num_blk);
            //unsigned char uid[256]
            n.setParameter(2,uid);
            //unsigned char data[256]
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(1));
            n.setParameter(3,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_Select(byte flags,Pointer uid)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_Select");   
            n.setRetVal(Type.INT);
            n.setParameter(0,flags);
            n.setParameter(1,uid);
            //unsigned char data[256]
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(1));
            n.setParameter(2,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_WriteAFI(byte flags,byte afi,Pointer uid)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_WriteAFI");   
            n.setRetVal(Type.INT);
            n.setParameter(0,flags);
            n.setParameter(1,afi);
            n.setParameter(2,uid);
            //unsigned char data[256]
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(1));
            n.setParameter(3,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_LockAFI(byte flags,Pointer uid)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_LockAFI");   
            n.setRetVal(Type.INT);
            n.setParameter(0,flags);
            n.setParameter(1,uid);
            //unsigned char data[256]
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(1));
            n.setParameter(2,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_WriteDSFID(byte flags,byte DSFID,Pointer uid)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_WriteDSFID");   
            n.setRetVal(Type.INT);
            n.setParameter(0,flags);
            n.setParameter(1,DSFID);
            n.setParameter(2,uid);
            //unsigned char data[256]
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(1));
            n.setParameter(3,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_LockDSFID(byte flags,Pointer uid)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_LockDSFID");   
            n.setRetVal(Type.INT);
            n.setParameter(0,flags);
            n.setParameter(1,uid);
            //unsigned char data[256]
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(1));
            n.setParameter(2,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_GetSysInfo(byte flags,Pointer uid)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_GetSysInfo");   
            n.setRetVal(Type.INT);
            n.setParameter(0,flags);
            n.setParameter(1,uid);
            //unsigned char data[256]
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(255));
            n.setParameter(2,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
	public static int ISO15693_GetMulSecurity(byte flags,byte blkAddr,byte blkNum,Pointer uid)
	{
		JNative n = null;   
        try {              
            n = new JNative("function.dll", "ISO15693_GetMulSecurity");   
            n.setRetVal(Type.INT);
            n.setParameter(0,flags);
            n.setParameter(1,blkAddr);
            n.setParameter(2,blkNum);
            n.setParameter(3,uid);
            
            //unsigned char data[256]
            a = new Pointer(MemoryBlockFactory.createMemoryBlock(blkNum + 1));
            n.setParameter(4,a);
            n.invoke();
            byte0 = a.getAsByte(0);
            return Integer.parseInt(n.getRetVal());
        } catch(Exception e) {
        	System.out.print("Failed");
        	return 1;
        }
	}
}