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
        reason = " ";
		return;
	}

	if(s == "01")   
    {
        reason = "Command false.....";   
		return;
	}

	if(s == "02")   
	{
        reason = "checksum error.....";  
		return;
	}

	if(s == "03")   
	{ 
        reason = "Not selected COM port.....";
		return;
	}

	if(s == "04")   
	{
		reason = "time out reply.....";  
		return;
	}

	if(s == "05")  
	{
		reason = "check sequence error....."; 
		return;
	}

	if(s == "07")   
	{
        reason = "check sum error.....";
		return;
	}

	if(s == "10") 
	{ 
        reason = "the parameter value out of range.....";  
		return;
	}

	if(s == "80")  
    {
        reason = "Command OK.....";    
		return;
	}
	
	if(s == "81")
	{
	    reason = "Command FAILURE....";   
		return;
	}

	if(s == "82") 
	{
        reason = "Reader reply time out error...."; 
		return;
	}

	if(s == "83") 
	{
		reason = "The card is not exist....";   
		return;
    }

	if(s == "84")  
	{
        reason = "the data is error....";
		return;
	}

	if(s == "85") 
	{
		reason = "Reader received unknown command....";   
		return;
    }

	if(s == "87") 
	{
        reason = "error....";    
		return;
    }

	if(s == "89")  
	{
         reason = "The parameter of the command or the Format of the command Erro..."; 
		 return;
	}

	if(s == "8A") 
	{
		reason = "Some Erro appear in the card InitVal process...";      
		return;
    } 

	if(s == "8B") 
	{
         reason = "Get The Wrong Snr during anticollison loop...."; 
		 return;
    }

	if(s == "8C")
	{
		reason = "The authentication failure....";  
		return;
    }

	if(s == "8F")
	{
		reason = "Reader received unknown command....";  
		return;
    }

	if(s == "90") 
	{
		reason = "The Card do not support this command....";   
		return;
    }

	if(s == "91")
	{
		reason = "The Foarmat Of The Command Erro....";   
		return;
    }

	if(s == "92")  
	{
        reason = "Do not support Option mode....";   
		return;
    }

	if(s == "93")
	{
		reason = "The Block Do Not Exist....";   
		return;
    }

	if(s == "94")
	{
		reason = "The Object have been locked....";  
		return;
    }

	if(s == "95")  
	{
		reason = "The lock Operation Do Not Success...."; 
		return;
    }

    if(s == "96")
	{
		reason = "The Operation Do Not Success....";   
		return;
	}
}