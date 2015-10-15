#include "stdafx.h"
#include "ErrorReason.h"

void FalseReason(CString s, CString &reason)
{
	if(s == " ") 
	{
		reason = " ";
		return;
	}

	if(s == "00")
    {
        reason = "命令执行成功.....";
		return;
	}

	if(s == "01")   
    {
        reason = "命令操作失败 .....";   
		return;
	}

	if(s == "02")   
	{
        reason = "地址校验错误 .....";  
		return;
	}

	if(s == "03")   
	{ 
        reason = "没有选择COM口 .....";
		return;
	}

	if(s == "04")   
	{
		reason = "读写器返回超时 .....";  
		return;
	}

	if(s == "05")  
	{
		reason = "数据包流水号不正确 ....."; 
		return;
	}

	if(s == "07")   
	{
        reason = "接收异常 .....";
		return;
	}

	if(s == "10") 
	{ 
        reason = "参数值超出范围 .....";  
		return;
	}

	if(s == "80")  
    {
        reason = "参数设置成功 .....";    
		return;
	}
	
	if(s == "81")
	{
	    reason = "参数设置失败 .....";   
		return;
	}

	if(s == "82") 
	{
        reason = "通讯超时....."; 
		return;
	}

	if(s == "83") 
	{
		reason = "卡不存在.....";   
		return;
    }

	if(s == "84")  
	{
        reason = "接收卡数据出错.....";
		return;
	}

	if(s == "85") 
	{
		reason = "未知的错误.....";   
		return;
    }

	if(s == "87") 
	{
        reason = "输入参数或者输入命令格式错误.....";    
		return;
    }

	if(s == "89")  
	{
         reason = "输入的指令代码不存在....."; 
		 return;
	}

	if(s == "8A") 
	{
		reason = "在对于卡块初始化命令中出现错误.....";      
		return;
    } 

	if(s == "8B") 
	{
         reason = "在防冲突过程中得到错误的序列号....."; 
		 return;
    }

	if(s == "8C")
	{
		reason = "密码认证没通过.....";  
		return;
    }

	if(s == "8F")
	{
		reason = "输入的指令代码不存在.....";  
		return;
    }

	if(s == "90") 
	{
		reason = "卡不支持这个命令.....";   
		return;
    }

	if(s == "91")
	{
		reason = "命令格式有错误.....";   
		return;
    }

	if(s == "92")  
	{
        reason = "在命令的FLAG参数中，不支持OPTION 模式.....";   
		return;
    }

	if(s == "93")
	{
		reason = "要操作的BLOCK不存在.....";   
		return;
    }

	if(s == "94")
	{
		reason = "要操作的对象已经别锁定，不能进行修改.....";  
		return;
    }

	if(s == "95")  
	{
		reason = "锁定操作不成功....."; 
		return;
    }

    if(s == "96")
	{
		reason = "写操作不成功.....";   
		return;
	}
}