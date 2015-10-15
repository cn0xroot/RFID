using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using CSharpDEMO;
using System.Text.RegularExpressions;

namespace CSharpDEMO
{
    public partial class Form1 : Form
    {
        //数值串转化为十六进制字符串
        private byte[] StrToByetArray(string hexValues)
        {
            string[] hexValuesSplit = hexValues.Split(' ');
            byte[] retBytes = new byte[hexValuesSplit.Length];

            for (int nLoop = 0; nLoop < retBytes.Length; nLoop++)
            {
                retBytes[nLoop] = Convert.ToByte(hexValuesSplit[nLoop], 16);
            }

            return retBytes;
        }
        //字符数组转化为十六进制数组
        private byte[] StrToByetArray(string[] hexValues, int nLen)
        {
            byte[] retBytes = new byte[nLen];

            for (int nLoop = 0; nLoop < retBytes.Length; nLoop++)
            {
                retBytes[nLoop] = Convert.ToByte(hexValues[nLoop], 16);
            }

            return retBytes;
        }
        //十六进制字符串转化为数值串
        private string ByteArrayToStr(byte[] byteArray, bool bNeedFormat, int nStart, int nEnd)
        {
            //nEnd传递为0，转换到数组最后；

            string strReturn = "";

            if (bNeedFormat)
            {
                strReturn = "\r\nHEX RESULT:";
            }

            int nLoop = 0;
            nLoop += nStart;
            if (nEnd == 0)
            {
                nEnd = byteArray.GetLength(0);
            }
            else if (nEnd > byteArray.GetLength(0))
            {
                nEnd = byteArray.GetLength(0);
            }


            for (; nLoop < nEnd; nLoop++)
            {
                string strHex = "";

                if (bNeedFormat)
                {
                    if (nLoop % 16 != 0)
                    {
                        strHex = string.Format(" {0:X2}", byteArray[nLoop]);
                    }
                    else
                    {
                        strHex = string.Format("\r\n  {0:X2}...{1:X2}", nLoop / 16, byteArray[nLoop]);
                    }
                }
                else
                {
                    strHex = string.Format(" {0:X2}", byteArray[nLoop]);
                }

                strReturn += strHex;
            }

            return strReturn;
        }
        //转换错误代码
        private string FormatErrorCode(byte[] byteArray)
        {
            string strErrorCode = "";
            switch (byteArray[0])
            {
                case 0x80:
                    strErrorCode = "Success";
                    break;

                case 0x81:
                    strErrorCode = "Parameter Error";
                    break;

                case 0x82:
                    strErrorCode = "communication TimeOut";
                    break;

                case 0x83:
                    strErrorCode = "Couldn't Find Card ";
                    break;

                default:
                    strErrorCode = "Commond Error";
                    break;
            }

            return strErrorCode;
        }
        //字符截取，即不区分输入字符是否输入空格，均以两个字符处理为一个串
        private string[] strCutLength(string str, int iLength)
        {
            string[] reslut = null;
            if (!string.IsNullOrEmpty(str))
            {
                int iTemp = 0;
                string strTemp = null;
                System.Collections.ArrayList strArr = new System.Collections.ArrayList();
                for (int i = 0; i < str.Length; i++)
                {
                    if (str[i] == ' ')
                    {
                        continue;
                    }
                    else
                    {
                        iTemp++;
                        strTemp += str.Substring(i, 1);
                    }

                    //校验截取的字符是否在A~F、0~9区间
                    System.Text.RegularExpressions.Regex reg = new System.Text.RegularExpressions.Regex(@"^(([A-F])*(\d)*)$");
                    if (!reg.IsMatch(strTemp))
                    {
                        return reslut;
                    }

                    if ((iTemp == iLength) || (i == str.Length - 1 && !string.IsNullOrEmpty(strTemp)))
                    {
                        strArr.Add(strTemp);
                        iTemp = 0;
                        strTemp = null;
                    }
                }
                if (strArr.Count > 0)
                {
                    reslut = new string[strArr.Count];
                    strArr.CopyTo(reslut);
                }
            }
            return reslut;
        }
        //输出日志文本
        private void WriteLog(string strText, int nRet, string strErrcode)
        {
            if (nRet != 0)
            {

                textResponse.Text += System.DateTime.Now.ToLocalTime().ToString() + " " + strText + "\r\n" + strErrcode + "\r\n";
            }
            else
            {
                textResponse.Text += System.DateTime.Now.ToLocalTime().ToString() + " " + strText + " " + "\r\n";
            }

            textResponse.Select(textResponse.TextLength, 0);//光标定位到文本最后
            textResponse.ScrollToCaret();//滚动到光标处
        }

        //转换卡号专用
        private byte[] convertSNR(string str, int keyN)
        {
            string regex = "[^a-fA-F0-9]";
            string tmpJudge = Regex.Replace(str,regex,"");    
       
            //长度不对，直接退回错误
            if (tmpJudge.Length != 12) return null;

            string[] tmpResult= Regex.Split(str,regex);
            byte[] result = new byte[keyN];
            int i = 0;
            foreach (string tmp in tmpResult)
            {
                result[i] = Convert.ToByte(tmp,16);
                i++;
            }
            return result;
        }

        //数据输入判断函数2个
        private string formatStr(string str, int num_blk)
        {
            
            string tmp=Regex.Replace(str,"[^a-fA-F0-9]","");
            //长度不对直接报错
            //num_blk==-1指示不用检查位数
            if (num_blk == -1) return tmp;
            //num_blk==其它负数，为-1/num_blk
            if (num_blk < -1)
            {
                if (tmp.Length != -16 / num_blk * 2) return null;
                else return tmp;
            }
            if (tmp.Length != 16*num_blk*2) return null;
            else return tmp;
        }
        private void convertStr(byte[] after, string before, int length)
        {
            for (int i = 0; i < length; i++)
            {
                after[i] = Convert.ToByte(before.Substring(2 * i, 2), 16);
            }
        }

        //显示结果
        private void showData(string text, byte[] data, int s, int e)
        {
            //非负转换
            for (int i = 0; i < e; i++)
            {
                if (data[s + i] < 0)
                    data[s + i] = Convert.ToByte(Convert.ToInt32(data[s + i]) + 256);
            }
            textResponse.Text += text;

            //for (int i = s; i < e; i++)
            //{
            //    textResponse.Text += data[i].ToString("X2")+" ";
            //}
            //textResponse.Text += "\r\n";

            for (int i = 0; i < e; i++)
            {
                textResponse.Text += data[s + i].ToString("X2")+" ";
            }
            textResponse.Text += "\r\n\r\n";

        }
        //显示命令执行结果
        private void showStatue(int Code)
        {
            string msg="";
            switch (Code)
            {
                case 0x00:
                    msg = "Command succeed.....";
                    break;
                case 0x01:
                    msg = "Command failed.....";
                    break;
                case 0x02:
                    msg = "Checksum error.....";
                    break;
                case 0x03:
                    msg = "Not selected COM port.....";
                    break;
                case 0x04:
                    msg = "Reply time out.....";
                    break;
                case 0x05:
                    msg = "Check sequence error.....";
                    break;
                case 0x07:
                    msg = "Check sum error.....";
                    break;
                case 0x0A:
                    msg = "The parameter value out of range.....";
                    break;
                case 0x80:
                    msg = "Command OK.....";
                    break;
                case 0x81:
                    msg = "Command FAILURE.....";
                    break;
                case 0x82:
                    msg = "Reader reply time out error.....";
                    break;
                case 0x83:
                    msg = "The card does not exist.....";
                    break;
                case 0x84:
                    msg = "The data is error.....";
                    break;
                case 0x85:
                    msg = "Reader received unknown command.....";
                    break;
                case 0x87:
                    msg = "Error.....";
                    break;
                case 0x89:
                    msg = "The parameter of the command or the format of the command error.....";
                    break;
                case 0x8A:
                    msg = "Some error appear in the card InitVal process.....";
                    break;
                case 0x8B:
                    msg = "Get the wrong snr during anticollison loop.....";
                    break;
                case 0x8C:
                    msg = "The authentication failure.....";
                    break;
                case 0x8F:
                    msg = "Reader received unknown command.....";
                    break;
                case 0x90:
                    msg = "The card do not support this command.....";
                    break;
                case 0x91:
                    msg = "The foarmat of the command error.....";
                    break;
                case 0x92:
                    msg = "Do not support option mode.....";
                    break;
                case 0x93:
                    msg = "The block do not exist.....";
                    break;
                case 0x94:
                    msg = "The object have been locked.....";
                    break;
                case 0x95:
                    msg = "The lock operation do not success.....";
                    break;
                case 0x96:
                    msg = "The operation do not success.....";
                    break;
            }
            textResponse.Text += msg + "\r\n";
        }

        public Form1()
        {
            InitializeComponent();
            UL_readBlock.SelectedIndex = 0;
            UL_writeBlock.SelectedIndex = 0;
        }

        /*读取读卡器版本号*/
        private void btn_GetVersionNum_Click(object sender, EventArgs e)
        {
            byte[] byteArry = new byte[12];
            int nRet = Reader.GetVersionNum(byteArry);
            if (nRet != 0)
            {
                showStatue(byteArry[0]);
            }
            else
            {
                /*-----------------------BUG标记：数组越界，11改为12----------------------*/
                showData("VersionNum：", byteArry, 1, 11);
            }
        }

        /*读取读卡器序列号*/
        private void btn_GetSerNum_Click(object sender, EventArgs e)
        {
            byte[] buffer = new byte[9];
            int nRet = Reader.GetSerNum(buffer);
            //if (nRet != 0)
            //{
            //    showStatue(nRet);
            //}
            //else
            //{
            //    showData("读卡器序列号：", buffer, 1, 8);
            //}
            showStatue(nRet);
            showData("SerialNum：", buffer, 1, 8);
        }

        /*设置读卡器序列号*/
        private void btn_SetSerNum_Click(object sender, EventArgs e)
        {
            byte[] byteRet = new byte[1];
            //string strErrorCode = "";
            string[] reslut = strCutLength(txt_SetSerNum.Text.ToUpper(), 2);

            if (reslut == null)
            {
                MessageBox.Show("The input is not valid！");
                return;
            }
            else if (reslut.GetLength(0) < 8)
            {
                MessageBox.Show("Please input 8 bytes！");
                return;
            }

            byte[] byteBuffer = StrToByetArray(reslut, 8);

            int nRet = Reader.SetSerNum(byteBuffer, byteRet);

            //if (nRet != 0)
            //{
            //    showStatue(nRet);
            //}
            //else
            //{
            //    string strText = "";
            //    for (int nLoop = 0; nLoop < 8; nLoop++)
            //    {
            //        if (reslut[nLoop].Length == 1)
            //        {
            //            strText += "0" + reslut[nLoop] + " ";
            //        }
            //        else
            //        {
            //            strText += reslut[nLoop] + " ";
            //        }
            //    }
            //    WriteLog("设置读卡器序列号：" + strText, nRet, strErrorCode);
            //}
            showStatue(nRet);
            showStatue(byteRet[0]);
        }

        /*setLED*/
        private void btn_ControlLED_Click(object sender, EventArgs e)
        {
            //string strRet = "";
            byte[] buffer=new byte[1];
            //string strErrorCode = "";
            int nRet = Reader.ControlLED(int.Parse(txt_LEDFREQ.Text),int.Parse(txt_LEDDURATION.Text),buffer);
            //if (nRet != 0)
            //{
            //    showStatue(nRet);
            //    //strErrorCode = FormatErrorCode(buffer);
            //    //WriteLog("Mistake Hints Error", nRet, strErrorCode);
            //}
            //else
            //{
            //    showStatue(buffer[0]);
            //    //WriteLog("Mistake Hints", nRet, "");
            //}          
            showStatue(nRet);
            showStatue(buffer[0]);
        }

        /*setBUZZER*/
        private void btn_ControlBuzzer_Click(object sender, EventArgs e)
        {
            byte[] buffer = new byte[1];
            //string strErrorCode = "";

            int nRet = Reader.ControlBuzzer(int.Parse(txt_BUZZERFREQ.Text),int.Parse(txt_BUZZERDURATION.Text),buffer);

            //if (nRet != 0)
            //{
            //    strErrorCode = FormatErrorCode(buffer);

            //    WriteLog("Succeed Hints Error", nRet, strErrorCode);
            //}
            //else
            //{
            //    WriteLog("Succeed Hints", nRet, strErrorCode);
            //}
            showStatue(nRet);
            showStatue(buffer[0]);
        }

        //14443A-MF

        /*MF_Read_Func*/
        private void btn_MF_Read_Click(object sender, EventArgs e)
        {
            byte mode1 = (readKeyB.Checked) ? (byte)0x01 : (byte)0x00;
            byte mode2 = (readAll.Checked) ? (byte)0x01 : (byte)0x00;
            byte mode = (byte)((mode1<<1)|mode2);
            byte blk_add = Convert.ToByte(readStart.Text,16);
            byte num_blk = Convert.ToByte(readNum.Text,16);

            byte[] snr = new byte[6];
            snr = convertSNR(readKey.Text, 6);
            if (snr == null)
            {
                MessageBox.Show("Invalid Serial Number!", "ERROR");
                return;
            }

            byte[] buffer = new byte[16 * num_blk];

            int nRet = Reader.MF_Read(mode, blk_add, num_blk, snr, buffer);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(buffer);
                //WriteLog("Failed: ", nRet, strErrorCode);
                showStatue(buffer[0]);
            }
            else
            {
                showData("CardNumber: ", snr, 0, 4);
                showData("Data: ", buffer, 0, 16 * num_blk);
            }

        }

        /*MF_Write_Func*/
        private void btn_MF_Write_Click(object sender, EventArgs e)
        {
            byte mode1 = (writeKeyB.Checked) ? (byte)0x01 : (byte)0x00;
            byte mode2 = (writeAll.Checked) ? (byte)0x01 : (byte)0x00;
            byte mode = (byte)((mode1 << 1) | mode2);
            byte blk_add = Convert.ToByte(writeStart.Text,16);
            byte num_blk = Convert.ToByte(writeNum.Text, 16);

            byte[] snr = new byte[6];
            snr = convertSNR(writeKey.Text, 16);
            if (snr == null)
            {
                MessageBox.Show("Invalid Serial Number!","ERROR");
                return;
            }

            byte[] buffer = new byte[16 * num_blk];
            string bufferStr = formatStr(writeData.Text,num_blk);
            if (bufferStr == null)
            {
                MessageBox.Show("Invalid Serial Number!","ERROR");
                return;
            }
            convertStr(buffer, bufferStr, 16 * num_blk);

            int nRet = Reader.MF_Write(mode,blk_add,num_blk,snr, buffer);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(buffer);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(buffer[0]);
            }
            else
            {
                showData("CardNumber:",snr,0,4);
            }
        }

        private void btn_MF_InitValue_Click(object sender, EventArgs e)
        {
            byte mode1 = (initKeyB.Checked) ? (byte)0x01 : (byte)0x00;
            byte mode2=(initAll.Checked)?(byte)0x01:(byte)0x00;
            byte mode = (byte)((mode1 << 1) | mode2);
            byte SectNum = Convert.ToByte(initSector.Text, 16);

            byte[] snr = new byte[6];
            snr = convertSNR(initKey.Text, 16);
            if (snr == null)
            {
                MessageBox.Show("Invalid Serial Number!", "ERROR");
                return;
            }

            byte[] value = new byte[4];
            string valueStr = formatStr(initValue.Text,-1);
            convertStr(value, valueStr, 4);

            int nRet = Reader.MF_InitValue(mode, SectNum, snr, value);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(value);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(snr[0]);
            }
            else
            {
                showData("CardNumber:", snr, 0, 4);
            }

        }

        private void btn_MF_Dec_Click(object sender, EventArgs e)
        {
            byte mode1 = (decKeyB.Checked) ? (byte)0x01 : (byte)0x00;
            byte mode2 = (decAll.Checked) ? (byte)0x01 : (byte)0x00;
            byte mode = (byte)((mode1 << 1) | mode2);
            byte SectNum = Convert.ToByte(decSector.Text, 16);

            byte[] snr = new byte[6];
            snr = convertSNR(decKey.Text, 16);
            if (snr == null)
            {
                MessageBox.Show("Invalid Serial Number!", "ERROR");
                return;
            }

            byte[] value = new byte[4];

            string valueStr = formatStr(decValue.Text, -1);
            convertStr(value, valueStr, 4);

            int nRet=Reader.MF_Dec(mode,SectNum,snr,value);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(value);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(snr[0]);
            }
            else
            {
                showData("CardNumber: ", snr, 0, 4);
            }

        }

        private void btn_MF_Inc_Click(object sender, EventArgs e)
        {
            byte mode1 = (incKeyB.Checked) ? (byte)0x01 : (byte)0x00;
            byte mode2 = (incAll.Checked) ? (byte)0x01 : (byte)0x00;
            byte mode = (byte)((mode1 << 1) | mode2);
            byte SectNum = Convert.ToByte(incSector.Text, 16);

            byte[] snr = new byte[6];
            snr = convertSNR(incKey.Text, 16);
            if (snr == null)
            {
                MessageBox.Show("Invalid Serial Number!", "ERROR");
                return;
            }

            byte[] value = new byte[4];

            string valueStr = formatStr(incValue.Text, -1);
            convertStr(value, valueStr, 4);

            int nRet = Reader.MF_Inc(mode, SectNum, snr, value);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(value);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(snr[0]);
            }
            else
            {
                showData("CardNumber: ", snr, 0, 4);
            }
        }

        private void btn_MF_Getsnr_Click(object sender, EventArgs e)
        {
            byte mode = (snrAll.Checked) ? (byte)0x52 : (byte)0x26;
            byte halt = (snrHalt.Checked) ? (byte)0x01 : (byte)0x00;

            byte[] snr = new byte[1];

            byte[] value = new byte[4];
            string valueStr = formatStr(incValue.Text, -1);
            convertStr(value, valueStr, 4);

            int nRet = Reader.MF_Getsnr(mode, halt, snr, value);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(value);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(snr[0]);
            }
            else
            {
                if (snr[0] == 0x00)
                    textResponse.Text += "Only ONE Card...\r\n";
                else
                    textResponse.Text += "Multiple Cards...\r\n";
                showData("Card Number: ", value, 0, 4);
            }

        }

        private void btn_UL_Request_Click(object sender, EventArgs e)
        {
            byte[] snr = new byte[7];
            byte mode = (UL_snreadAll.Checked) ? (byte)0x01 : (byte)0x00;

            int nRet = Reader.UL_Request(mode, snr);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(snr);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(snr[0]);
            }
            else
            {
                showData("Card Number: ", snr, 0, 7);
            }
        }

        private void btn_UL_Halt_Click(object sender, EventArgs e)
        {
            int nRet = Reader.MF_Halt();

            //textResponse.Text += "命令执行成功。\r\n";
            showStatue(nRet);
        }

        private void btn_UL_HLRead_Click(object sender, EventArgs e)
        {
            byte mode = (UL_readAll.Checked) ? (byte)0x01 : (byte)0x01;
            byte blk_add = Convert.ToByte(UL_readBlock.SelectedItem.ToString(), 16);

            byte[] snr = new byte[7];
            byte[] buffer = new byte[16];

            int nRet = Reader.UL_HLRead(mode, blk_add, snr, buffer);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(buffer);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(buffer[0]);
            }
            else
            {
                showData("Card Number: ",snr,0,7);
                showData("Data: ", buffer, 0, 16);
            }

        }

        private void btn_UL_HLWrite_Click(object sender, EventArgs e)
        {
            byte mode = (UL_writeAll.Checked) ? (byte)0x01 : (byte)0x00;
            byte blk_add = Convert.ToByte(UL_writeBlock.SelectedItem.ToString(), 16);

            byte[] snr = new byte[7] { 0, 0, 0, 0, 0, 0, 0 };
            byte[] buffer = new byte[4];

            string bufferStr = formatStr(UL_writeData.Text, -1);
            convertStr(buffer, bufferStr, 4);

            int nRet = Reader.UL_HLWrite(mode, blk_add, snr, buffer);
            string strErrorCode;

            if (nRet != 0)
            {
                if (nRet == 10)
                {
                    //Something Different
                    strErrorCode = FormatErrorCode(buffer);
                    WriteLog("Error: ",nRet,strErrorCode);
                    showStatue(nRet);
                }
                else
                {
                    //textResponse.Text += "命令执行成功。\r\n";
                    showStatue(snr[0]);
                }
            }
            else
            {
                showData("Card Number: ",snr,0,7);
            }

        }

        private void btn_TypeB_Request_Click(object sender, EventArgs e)
        {
            byte[] buffer=new byte[256];

            int nRet = Reader.TypeB_Request(buffer);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(buffer);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(buffer[0]);
            }
            else
            {
                showData("Data Length: ", buffer, 0, 1);
                showData("Data: ", buffer, 1, buffer[0]);
            }
        }

        private void btn_TypeB_TransCOS_Click(object sender, EventArgs e)
        {
            int cmdSize = int.Parse(B_Length.Text);
            byte[] buffer = new byte[256];
            //for (int i = 0; i < 256; i++)
            //{
            //    Console.WriteLine(buffer[i].ToString());
            //}
            byte[] cmd = new byte[cmdSize];

            string cmdStr = formatStr(B_Data.Text, -1);

            int nRet = Reader.TypeB_TransCOS(cmd, cmdSize, buffer);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(buffer);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(buffer[0]);
            }
            else
            {
                showData("Data: ",buffer,0,8);
            }
        }

        private void btn_TYPEB_SFZSNR_Click(object sender, EventArgs e)
        {
            byte mode = 0x26;
            byte halt = 0x00;
            byte[] value = new byte[8];
            byte[] snr=new byte[1];

            int nRet = Reader.TYPEB_SFZSNR(mode, halt, snr, value);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(snr);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(snr[0]);
            }
            else
            {
                if (snr[0] == 0x00)
                    textResponse.Text += "Only One Card...\r\n";
                else
                    textResponse.Text += "Multiple Cards...\r\n";
                showData("", value, 0, 8);
            }


        }

        private void btn_ISO15693_Inventory_Click(object sender, EventArgs e)
        {
            byte[] Cardnumber=new byte[1];
            byte[] pBuffer = new byte[256];

            int nRet = Reader.ISO15693_Inventory(Cardnumber, pBuffer);
            //string strErrorcode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorcode = FormatErrorCode(pBuffer);
                //WriteLog("Failed:", nRet, strErrorcode);
                showStatue(Cardnumber[0]);
            }
            else
            {
                textResponse.Text += "Card Number: \r\n";
                textResponse.Text += Convert.ToInt32(Cardnumber[0]).ToString("X2")+"\r\n";
                showData("Data Read: ", pBuffer, 0, 10 * Cardnumber[0]);
                for (int i = 0; i < Convert.ToInt32(Cardnumber[0]); i++)
                {
                    textResponse.Text += "Data of the " + i.ToString() + "th Card: \r\n";
                    string cardData="";
                    for (int j = 0; j < 8; j++)
                    {
                        cardData += pBuffer[Convert.ToInt32(Cardnumber[0]) * 10 - (i * 10 + j) - 1].ToString("X2")+" ";
                    }
                    textResponse.Text += cardData + "\r\n";
                }
            }
        }

        private void btn_ISO15693_Read_Click(object sender, EventArgs e)
        {
            byte flags = Convert.ToByte(isoreadFlag.Text);
            byte blk_add = Convert.ToByte(isoreadStart.Text);
            byte num_blk = Convert.ToByte(isoreadNum.Text);
            byte[] uid = new byte[8];
            string uidStr = formatStr(isoreadUID.Text, -2);
            if (uidStr == null)
            {
                MessageBox.Show("Invalid UID", "ERROR");
                return;
            }
            convertStr(uid, uidStr, 8);

            byte[] buffer = new byte[256];
            int n;
            if (flags == 0x42)
                n = 5;
            else
                n = 4;

            int nRet = Reader.ISO15693_Read(flags, blk_add, num_blk, uid, buffer);
            //string strErrorCode;

            showStatue(nRet);
            if (nRet != 0)
            {
                //strErrorCode = FormatErrorCode(buffer);
                //WriteLog("Failed:", nRet, strErrorCode);
                showStatue(buffer[0]);
            }
            else
            {
                showData("Flag: ", buffer, 0, 1);
                showData("Data: ", buffer, 1, n * num_blk);
            }

        }

        private void btn_ISO15693_Write_Click(object sender, EventArgs e)
        {
            byte flags = Convert.ToByte(isowriteFlag.Text);
            byte blk_add = Convert.ToByte(isowriteStart.Text);
            byte num_blk = Convert.ToByte(isowriteNum.Text);

            

            byte[] uid = new byte[8];
            string uidStr = formatStr(isoreadUID.Text,-2);
            if (uidStr == null)
            {
                MessageBox.Show("Invalid UID!","ERROR");
                return;
            }
            convertStr(uid, uidStr, 8);

            byte[] data = new byte[256];
            int n;
            if (flags == 0x42)
                n = 5;
            else
                n = 4;
            //讨论
            string dataStr;
            if ((double)num_blk * (double)n / (double)16 < 1)
                dataStr = formatStr(isowriteData.Text, (int)((double)-1/((double)num_blk * (double)n / (double)16)));
            else
                dataStr = formatStr(isowriteData.Text, num_blk * n / 16);

            convertStr(data, dataStr, num_blk * n);

            int nRet = Reader.ISO15693_Write(flags, blk_add, num_blk, uid, data);
            //string strErrorCode;

            showStatue(nRet);
            //if (nRet != 0)
            //{
            //    strErrorCode = FormatErrorCode(data);
            //    WriteLog("Failed:", nRet, strErrorCode);
            //}
            //else
            //{
            //    textResponse.Text += "Succeed!";
            //}
            if (nRet != 0)
            {
                showStatue(data[0]);
            }
        }

        private void btn_ISO15693_Lock_Click(object sender, EventArgs e)
        {
            byte flags = Convert.ToByte(blklockFlag.Text);
            byte blk_add = Convert.ToByte(blklockStart.Text);
            byte[] uid = new byte[8];
            string uidStr = formatStr(blklockUID.Text, -2);
            if (uidStr == null)
            {
                MessageBox.Show("Invalid UID!", "ERROR");
                return;
            }
            convertStr(uid, uidStr, 8);

            byte[] buffer = new byte[1];
            int nRet = Reader.ISO15693_Lock(flags, blk_add, uid, buffer);
            //string strErrorCode;

            //if (nRet != 0)
            //{
            //    strErrorCode = FormatErrorCode(buffer);
            //    WriteLog("Failed:", nRet, strErrorCode);
            //}
            //else
            //{
            //    showStatue(nRet);
            //    showStatue(buffer[0]);
            //}
            showStatue(nRet);
            showStatue(buffer[0]);
        }

        private void btn_ISO15693_Select_Click(object sender, EventArgs e)
        {
            byte flags = Convert.ToByte(cardselectFlag.Text);
            byte[] uid = new byte[8];
            string uidStr = formatStr(cardselectUID.Text, -2);
            if (uidStr == null)
            {
                MessageBox.Show("Invalid UID!", "ERROR");
                return;
            }
            convertStr(uid, uidStr, 8);

            byte[] buffer = new byte[1];
            int nRet = Reader.ISO15693_Select(flags, uid, buffer);
            //string strErrorCode;

            //if (nRet != 0)
            //{
            //    strErrorCode = FormatErrorCode(buffer);
            //    WriteLog("Failed:", nRet, strErrorCode);
            //}
            //else
            //{
            //    showStatue(nRet);
            //    showStatue(buffer[0]);
            //}
            showStatue(nRet);
            showStatue(buffer[0]);
        }

        private void btn_ISO15693_WriteAFI_Click(object sender, EventArgs e)
        {
            byte flags = Convert.ToByte(afiwriteFlag.Text);
            byte[] uid = new byte[8];
            string uidStr = formatStr(afiwriteUID.Text, -2);
            if (uidStr == null)
            {
                MessageBox.Show("Invalid UID1", "ERROR");
                return;
            }
            convertStr(uid, uidStr, 8);
            byte afi = Convert.ToByte(afiwriteAFI.Text);
            byte[] buffer = new byte[1];

            int nRet = Reader.ISO15693_WriteAFI(flags, afi, uid, buffer);
            //string strErrorCode;

            //if (nRet != 0)
            //{
            //    strErrorCode = FormatErrorCode(buffer);
            //    WriteLog("Failed:", nRet, strErrorCode);
            //}
            //else
            //{
            //    showStatue(nRet);
            //    showStatue(buffer[0]);
            //}
            showStatue(nRet);
            showStatue(buffer[0]);
        }

        private void btn_ISO15693_LockAFI_Click(object sender, EventArgs e)
        {
            byte flags = Convert.ToByte(afilockFlag.Text);
            byte[] uid = new byte[8];
            string uidStr = formatStr(afilockUID.Text, -2);
            if (uidStr == null)
            {
                MessageBox.Show("Invalid UID!", "ERROR");
                return;
            }
            convertStr(uid, uidStr, 8);

            byte[] buffer = new byte[1];
            int nRet = Reader.ISO15693_LockAFI(flags, uid, buffer);

            showStatue(nRet);
            showStatue(buffer[0]);
        }

        private void btn_ISO15693_WriteDSFID_Click(object sender, EventArgs e)
        {
            byte flags = Convert.ToByte(dsfidwriteFlag.Text);
            byte[] uid = new byte[8];
            string uidStr = formatStr(dsfidwriteUID.Text, -2);
            if (uidStr == null)
            {
                MessageBox.Show("Invalid UID!", "ERROR");
                return;
            }
            convertStr(uid, uidStr, 8);

            byte DSFID = Convert.ToByte(dsfidwriteDSFID.Text);
            byte[] buffer = new byte[1];

            int nRet = Reader.ISO15693_WriteDSFID(flags, DSFID, uid, buffer);
            showStatue(nRet);
            showStatue(buffer[0]);
        }

        private void btn_ISO15693_LockDSFID_Click(object sender, EventArgs e)
        {
            byte flags = Convert.ToByte(lockdsfidFlag.Text);
            byte[] uid = new byte[8];
            string uidStr = formatStr(lockdsfidUID.Text, -2);
            if (uidStr == null)
            {
                MessageBox.Show("Invalid UID!", "ERROR");
                return;
            }
            convertStr(uid, uidStr, 8);

            byte[] buffer = new byte[1];
            int nRet = Reader.ISO15693_LockDSFID(flags, uid, buffer);
            showStatue(nRet);
            showStatue(buffer[0]);

        }

        private void btn_ISO15693_GetSysInfo_Click(object sender, EventArgs e)
        {
            byte flag = Convert.ToByte(getsysFlag.Text);
            byte[] uid = new byte[8];
            byte[] Buffer = new byte[255];
            string uidStr = formatStr(getsysUID.Text, -2);
            if (uidStr == null)
            {
                MessageBox.Show("Invalid UID!", "ERROR");
                return;
            }
            convertStr(uid, uidStr, 8);

            int nRet = Reader.ISO15693_GetSysInfo(flag, uid, Buffer);
            showStatue(nRet);
            if (nRet != 0)
            {
                showStatue(Buffer[0]);
            }
            else
            {
                showData("FLAG: ",Buffer,0,1);
                showData("INFO Flags:", Buffer, 1, 1);
                showData("UID:", Buffer, 2, 8);
                showData("DSFID:", Buffer, 10, 1);
                showData("AFI", Buffer, 11, 11);
                showData("Other fields:", Buffer, 12, 5);
            }

        }

        private void btn_ISO15693_GetMulSecurity_Click(object sender, EventArgs e)
        {
            byte flags = Convert.ToByte(blksecgetFlag.Text);
            byte blkAddr = Convert.ToByte(blksecgetStart.Text);
            byte blkNum = Convert.ToByte(blksecgetNum.Text);
            byte[] uid = new byte[8];
            string uidStr = formatStr(blklockUID.Text, -2);
            if (uidStr == null)
            {
                MessageBox.Show("Invalid UID!", "ERROR");
                return;
            }
            convertStr(uid, uidStr, 8);

            byte[] pBuffer = new byte[blkNum + 1];

            int nRet = Reader.ISO15693_GetMulSecurity(flags, blkAddr, blkNum, uid, pBuffer);
            showStatue(nRet);
            if (nRet == 0)
            {
                showData("Flag: ", pBuffer, 0, 1);
                showData("Block Security Bit: ", pBuffer, 1, blkNum);
            }
            else
            {
                showStatue(pBuffer[0]);
            }
        }





    }
}

