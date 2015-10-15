import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import com.syc.function.Function;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import javax.swing.JRadioButton;
import javax.swing.ButtonGroup;
import javax.swing.border.LineBorder;
import java.awt.Color;
import javax.swing.BoxLayout;
import javax.swing.JSeparator;
import javax.swing.JScrollPane;
import javax.swing.JList;
import javax.swing.AbstractListModel;

import org.xvolks.jnative.exceptions.NativeException;
import org.xvolks.jnative.pointers.Pointer;
import org.xvolks.jnative.pointers.memory.MemoryBlockFactory;

public class mainWindow {

	private JFrame frame;
	private JTextField sysSerNum;
	private JTextField ledCycle;
	private JTextField ledTimes;
	private JTextField bzrCycle;
	private JTextField bzrTimes;
	private int commHandle = 0;
	private int DeviceAddress = 0;
	private String baudRate[] = { "9600", "19200", "38400", "57600", "115200" };
	private final ButtonGroup buttonGroup = new ButtonGroup();
	private final ButtonGroup buttonGroup_1 = new ButtonGroup();
	private final ButtonGroup buttonGroup_2 = new ButtonGroup();
	private final ButtonGroup buttonGroup_3 = new ButtonGroup();
	private JTextField mfwriteData;
	private final ButtonGroup buttonGroup_4 = new ButtonGroup();
	private final ButtonGroup buttonGroup_5 = new ButtonGroup();
	private JTextField initKey;
	private JTextField initValue;
	private JTextField initSect;
	private JTextField deValue;
	private JTextField deKey;
	private JTextField deSector;
	private JTextField inKey;
	private JTextField inValue;
	private JTextField inSector;
	private final ButtonGroup buttonGroup_6 = new ButtonGroup();
	private final ButtonGroup buttonGroup_7 = new ButtonGroup();
	private final ButtonGroup buttonGroup_8 = new ButtonGroup();
	private final ButtonGroup buttonGroup_9 = new ButtonGroup();
	private final ButtonGroup buttonGroup_10 = new ButtonGroup();
	private final ButtonGroup buttonGroup_11 = new ButtonGroup();
	private JTextField ulwriteData;
	private JTextField bDataLen;
	private JTextField bData;
	private JTextField isoreadFlag;
	private JTextField isoreadAdd;
	private JTextField isoNum;
	private JTextField isoUID;
	private JTextField isoWriteUID;
	private JTextField isowriteAdd;
	private JTextField isowriteFlag;
	private JTextField isoWriteNum;
	private JTextField isowriteData;
	private JTextField isolbBlock;
	private JTextField isolbFlag;
	private JTextField isoblUID;
	private JTextField isoscUID;
	private JTextField isoscFlag;
	private JTextField isowaUID;
	private JTextField isowaAFI;
	private JTextField isowaFlag;
	private JTextField isolaUID;
	private JTextField isolaFlag;
	private JTextField isosiUID;
	private JTextField isosiFlag;
	private JTextField isobsNum;
	private JTextField isobsUID;
	private JTextField isobsAdd;
	private JTextField isobsFlag;
	private JTextField isoldUID;
	private JTextField isoldFlag;
	private JTextField isowdUID;
	private JTextField isowdDSFID;
	private JTextField isowdFlag;
	
	JTextArea dataArea = new JTextArea();
	String s100 = "";
	private final ButtonGroup buttonGroup_12 = new ButtonGroup();
	private final ButtonGroup buttonGroup_13 = new ButtonGroup();
	private final ButtonGroup buttonGroup_14 = new ButtonGroup();

	/**
	 * Launch the application.
	 */
	
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					mainWindow window = new mainWindow();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public mainWindow() {
		initialize();
	}

	private byte[] getByteArray(String str) {
		str = str.replaceAll("[^0-9A-F]", "");
		byte[] ans = new byte[str.length() / 2];
		for (int i = 0; i < str.length(); i += 2) {
			ans[i / 2] = (byte) Integer.parseInt(str.substring(i, i + 2), 16);
		}
		return ans;
	}

	private void showData(JTextArea dataArea, byte[] data, String str, int pos,
			int len) {
		String dStr = "";
		for (int i = 0; i < len; i++) {
			dStr += String.format("%02x ", data[i + pos]);
		}
		dataArea.append(str + dStr.toUpperCase() + '\n');
	}

	private void showData(JTextArea dataArea, byte[] data, String str) {
		String dStr = "";
		for (byte b : data) {
			dStr += String.format("%02x ", b);
		}
		dataArea.append(str + dStr.toUpperCase() + '\n');
	}

	private void showStatue(JTextArea dataArea, byte Code) {
		int code = Code;
		if (code < 0)
			code += 256;
		showStatue(dataArea, code);
	}

	private void showStatue(JTextArea dataArea, int Code) {
		String msg = null;
		switch (Code) {
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
		msg += '\n';
		dataArea.append(msg);
	}

	/**
	 * Initialize the contents of the frame.
	 */
	
	public void output(String s)
	{
		dataArea.setText(dataArea.getText()+s);
	}
	
	public void checkdata(String s)
	{
		String t0 = "";
		for ( int i = 0 ; i < s.length() ; i ++ )
		{
			char t1 = s.charAt(i);
			if ( (t1 >= '0' && t1 <='9') || (t1 >= 'A' && t1 <= 'Z') || (t1 >= 'a' && t1 <='z'))
			{
				t0 = t0 + t1;
			}
		}
		s100 = t0;
	}
	private void initialize() {
		
		
	/**
	 * The MainWindow UI.
	 */
	frame = new JFrame();
	frame.setBounds(100, 100, 908, 608);
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.getContentPane().setLayout(new GridLayout(0, 2, 0, 0));

	JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
	frame.getContentPane().add(tabbedPane);
	
	JPanel panel = new JPanel();
	tabbedPane.addTab("\u7CFB\u7EDF\u8BBE\u7F6E", null, panel, null);
	panel.setLayout(null);
			
	JLabel label_5 = new JLabel("\u8BBE\u7F6E\u673A\u5668\u5E8F\u5217\u53F7:");
	label_5.setBounds(10, 15, 95, 15);
	panel.add(label_5);
					
	sysSerNum = new JTextField();
	sysSerNum.setText("AA BB AA BB AA BB AA BB");
	sysSerNum.setBounds(98, 13, 170, 19);
	panel.add(sysSerNum);
	sysSerNum.setColumns(10);
							
	JButton btnSetSernum = new JButton("\u8BBE\u7F6E");
									
	btnSetSernum.setBounds(302, 10, 131, 25);
	panel.add(btnSetSernum);
											
	JLabel lblReadSernum = new JLabel("\u8BFB\u53D6\u673A\u5668\u5E8F\u5217\u53F7:");
	lblReadSernum.setBounds(10, 42, 113, 15);
	panel.add(lblReadSernum);
													
	JButton btnReadSernum = new JButton("\u8BFB\u53D6");
															
	btnReadSernum.setBounds(302, 37, 131, 25);
	panel.add(btnReadSernum);
																	
	JLabel lblLed = new JLabel("Led:");
	lblLed.setBounds(10, 69, 70, 15);
	panel.add(lblLed);
																			
	ledCycle = new JTextField();
	ledCycle.setText("18");
	ledCycle.setBounds(94, 69, 26, 19);
	panel.add(ledCycle);
	ledCycle.setColumns(10);
																					
	JLabel lblNewLabel = new JLabel("Cycle");
	lblNewLabel.setBounds(126, 69, 46, 15);
	panel.add(lblNewLabel);
																							
	ledTimes = new JTextField();
	ledTimes.setText("09");
	ledTimes.setColumns(10);
	ledTimes.setBounds(186, 67, 26, 19);
	panel.add(ledTimes);
																									
	JLabel lblTimes = new JLabel("Times");
	lblTimes.setBounds(222, 69, 46, 15);
	panel.add(lblTimes);
																											
	JButton btnSetLed = new JButton("\u8BBE\u7F6E");
																													
	btnSetLed.setBounds(302, 64, 131, 25);
	panel.add(btnSetLed);
																															
	JLabel lblBuzzer = new JLabel("Buzzer:");
	lblBuzzer.setBounds(10, 96, 70, 15);
	panel.add(lblBuzzer);
																																	
	bzrCycle = new JTextField();
	bzrCycle.setText("18");
	bzrCycle.setColumns(10);
	bzrCycle.setBounds(94, 94, 26, 19);
	panel.add(bzrCycle);
																																			
	JLabel label_6 = new JLabel("Cycle");
	label_6.setBounds(126, 96, 46, 15);
	panel.add(label_6);
																																					
	bzrTimes = new JTextField();
	bzrTimes.setText("09");
	bzrTimes.setColumns(10);
	bzrTimes.setBounds(186, 94, 26, 19);
	panel.add(bzrTimes);
																																							
	JLabel label_7 = new JLabel("Times");
	label_7.setBounds(222, 96, 46, 15);
	panel.add(label_7);
																																									
	JButton btnSetBuzzer = new JButton("\u8BBE\u7F6E");
																																											
	btnSetBuzzer.setBounds(302, 91, 131, 25);
	panel.add(btnSetBuzzer);
																																													
	JLabel lblGetVersionnum = new JLabel("\u8BFB\u53D6\u7248\u672C\u53F7:");
	lblGetVersionnum.setBounds(10, 123, 131, 15);
	panel.add(lblGetVersionnum);
																																															
	JButton btnGetversion = new JButton("\u8BFB\u53D6");
																																																	
	btnGetversion.setBounds(302, 118, 131, 25);
	panel.add(btnGetversion);

	
	JPanel panel_2 = new JPanel();
	tabbedPane.addTab("14443A-MF", null, panel_2, null);
	panel_2.setLayout(null);

	JLabel lblTypeA = new JLabel("Type A");
	lblTypeA.setBounds(12, 12, 57, 15);
	panel_2.add(lblTypeA);

	JPanel panel_3 = new JPanel();
	panel_3.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_3.setBounds(12, 30, 95, 25);
	panel_2.add(panel_3);
	panel_3.setLayout(new BoxLayout(panel_3, BoxLayout.X_AXIS));

	final JRadioButton readIdle = new JRadioButton("Idle");
	buttonGroup.add(readIdle);
	panel_3.add(readIdle);
	readIdle.setSelected(true);

	JRadioButton rdbtnAll = new JRadioButton("All");
	buttonGroup.add(rdbtnAll);
	panel_3.add(rdbtnAll);

	JPanel panel_4 = new JPanel();
	panel_4.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_4.setBounds(108, 30, 130, 25);
	panel_2.add(panel_4);
	panel_4.setLayout(new BoxLayout(panel_4, BoxLayout.X_AXIS));

	final JRadioButton readKeyA = new JRadioButton("Key A");
	buttonGroup_1.add(readKeyA);
	panel_4.add(readKeyA);
	readKeyA.setSelected(true);

	JRadioButton radioButton_1 = new JRadioButton("Key B");
	buttonGroup_1.add(radioButton_1);
	panel_4.add(radioButton_1);

	final JComboBox mfreadAdd = new JComboBox();
	mfreadAdd.setEditable(true);
	mfreadAdd.setModel(new DefaultComboBoxModel(new String[] { "00", "01",
			"02", "03", "04", "05", "06", "07", "08", "09", "0A", "0B",
			"0C", "0D", "0E", "0F", "10", "11", "12", "13", "14", "15",
			"16", "17", "18", "19", "1A", "1B", "1C", "1D", "1E", "1F",
			"20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
			"2A", "2B", "2C", "2D", "2E", "2F", "30", "31", "32", "33",
			"34", "35", "36", "37", "38", "39", "3A", "3B", "3C", "3D",
			"3E", "3F" }));
	mfreadAdd.setSelectedIndex(16);
	mfreadAdd.setBounds(12, 59, 46, 25);
	panel_2.add(mfreadAdd);

	JLabel lblStartAddress = new JLabel("\u8D77\u59CB\u5757");
	lblStartAddress.setBounds(61, 64, 106, 15);
	panel_2.add(lblStartAddress);

	final JComboBox mfreadNum = new JComboBox();
	mfreadNum.setEditable(true);
	mfreadNum.setModel(new DefaultComboBoxModel(new String[] { "01", "02",
			"03", "04" }));
	mfreadNum.setSelectedIndex(0);
	mfreadNum.setBounds(179, 59, 46, 25);
	panel_2.add(mfreadNum);

	JLabel label_8 = new JLabel("\u5757\u7684\u6570\u91CF");
	label_8.setBounds(228, 64, 62, 15);
	panel_2.add(label_8);

	final JComboBox mfreadKey = new JComboBox();
	mfreadKey.setEditable(true);
	mfreadKey
			.setModel(new DefaultComboBoxModel(new String[] {
					"FF FF FF FF FF FF", "A0 A1 A2 A3 A4 A5",
					"B0 B1 B2 B3 B4 B5" }));
	mfreadKey.setBounds(12, 88, 150, 24);
	panel_2.add(mfreadKey);

	JLabel lblKey = new JLabel("\u5BC6\u94A5");
	lblKey.setBounds(166, 91, 31, 15);
	panel_2.add(lblKey);

	JButton mfRead = new JButton("\u8BFB\u5361");

	mfRead.setBounds(318, 30, 117, 25);
	panel_2.add(mfRead);

	JSeparator separator = new JSeparator();
	separator.setBounds(12, 120, 423, 2);
	panel_2.add(separator);

	JLabel label_9 = new JLabel("\u5BC6\u94A5");
	label_9.setBounds(166, 185, 31, 15);
	panel_2.add(label_9);

	final JComboBox mfwriteKey = new JComboBox();
	mfwriteKey.setEditable(true);
	mfwriteKey
			.setModel(new DefaultComboBoxModel(new String[] {
					"FF FF FF FF FF FF", "A0 A1 A2 A3 A4 A5",
					"B0 B1 B2 B3 B4 B5" }));
	mfwriteKey.setBounds(12, 182, 150, 24);
	panel_2.add(mfwriteKey);

	final JComboBox mfwriteAdd = new JComboBox();
	mfwriteAdd.setModel(new DefaultComboBoxModel(new String[] { "00", "01",
			"02", "03", "04", "05", "06", "07", "08", "09", "0A", "0B",
			"0C", "0D", "0E", "0F", "10", "11", "12", "13", "14", "15",
			"16", "17", "18", "19", "1A", "1B", "1C", "1D", "1E", "1F",
			"20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
			"2A", "2B", "2C", "2D", "2E", "2F", "30", "31", "32", "33",
			"34", "35", "36", "37", "38", "39", "3A", "3B", "3C", "3D",
			"3E", "3F" }));
	mfwriteAdd.setSelectedIndex(16);
	mfwriteAdd.setEditable(true);
	mfwriteAdd.setBounds(12, 153, 46, 25);
	panel_2.add(mfwriteAdd);

	JLabel label_10 = new JLabel("\u8D77\u59CB\u5757");
	label_10.setBounds(61, 158, 106, 15);
	panel_2.add(label_10);

	JLabel label_11 = new JLabel("\u5757\u7684\u6570\u91CF");
	label_11.setBounds(228, 158, 62, 15);
	panel_2.add(label_11);

	final JComboBox mfwriteNum = new JComboBox();
	mfwriteNum.setModel(new DefaultComboBoxModel(new String[] { "01", "02",
			"03", "04" }));
	mfwriteNum.setSelectedIndex(0);
	mfwriteNum.setEditable(true);
	mfwriteNum.setBounds(179, 153, 46, 25);
	panel_2.add(mfwriteNum);

	JButton mfWrite = new JButton("\u5199\u5361");

	mfWrite.setBounds(318, 124, 117, 25);
	panel_2.add(mfWrite);

	JSeparator separator_1 = new JSeparator();
	separator_1.setBounds(12, 235, 423, 2);
	panel_2.add(separator_1);

	JPanel panel_5 = new JPanel();
	panel_5.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_5.setBounds(12, 124, 95, 25);
	panel_2.add(panel_5);
	panel_5.setLayout(new BoxLayout(panel_5, BoxLayout.X_AXIS));

	final JRadioButton writeIdle = new JRadioButton("Idle");
	buttonGroup_2.add(writeIdle);
	panel_5.add(writeIdle);
	writeIdle.setSelected(true);

	JRadioButton radioButton_2 = new JRadioButton("All");
	buttonGroup_2.add(radioButton_2);
	panel_5.add(radioButton_2);

	JPanel panel_6 = new JPanel();
	panel_6.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_6.setBounds(108, 124, 130, 25);
	panel_2.add(panel_6);
	panel_6.setLayout(new BoxLayout(panel_6, BoxLayout.X_AXIS));

	final JRadioButton writeKeyA = new JRadioButton("Key A");
	panel_6.add(writeKeyA);
	buttonGroup_3.add(writeKeyA);
	writeKeyA.setSelected(true);

	JRadioButton radioButton_5 = new JRadioButton("Key B");
	panel_6.add(radioButton_5);
	buttonGroup_3.add(radioButton_5);

	mfwriteData = new JTextField();
	mfwriteData.setText("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF");
	mfwriteData.setBounds(12, 209, 213, 19);
	panel_2.add(mfwriteData);
	mfwriteData.setColumns(10);

	JLabel lblDataToWrite = new JLabel("\u9700\u8981\u5F55\u5165\u7684\u6570\u636E");
	lblDataToWrite.setBounds(227, 211, 95, 15);
	panel_2.add(lblDataToWrite);

	JLabel label_12 = new JLabel("\u5BC6\u94A5");
	label_12.setBounds(131, 270, 31, 15);
	panel_2.add(label_12);

	JSeparator separator_2 = new JSeparator();
	separator_2.setBounds(12, 297, 423, 2);
	panel_2.add(separator_2);

	JPanel panel_7 = new JPanel();
	panel_7.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_7.setBounds(12, 240, 95, 25);
	panel_2.add(panel_7);
	panel_7.setLayout(new BoxLayout(panel_7, BoxLayout.X_AXIS));

	final JRadioButton initIdle = new JRadioButton("Idle");
	buttonGroup_4.add(initIdle);
	panel_7.add(initIdle);
	initIdle.setSelected(true);

	JRadioButton radioButton_7 = new JRadioButton("All");
	buttonGroup_4.add(radioButton_7);
	panel_7.add(radioButton_7);

	JPanel panel_8 = new JPanel();
	panel_8.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_8.setBounds(108, 240, 130, 25);
	panel_2.add(panel_8);
	panel_8.setLayout(new BoxLayout(panel_8, BoxLayout.X_AXIS));

	final JRadioButton initKeyA = new JRadioButton("Key A");
	buttonGroup_5.add(initKeyA);
	panel_8.add(initKeyA);
	initKeyA.setSelected(true);

	JRadioButton radioButton_9 = new JRadioButton("Key B");
	buttonGroup_5.add(radioButton_9);
	panel_8.add(radioButton_9);

	initKey = new JTextField();
	initKey.setText("FF FF FF FF FF FF");
	initKey.setBounds(12, 268, 117, 19);
	panel_2.add(initKey);
	initKey.setColumns(10);

	initValue = new JTextField();
	initValue.setText("64 00 00 00");
	initValue.setBounds(166, 268, 87, 19);
	panel_2.add(initValue);
	initValue.setColumns(10);

	JLabel lblValue = new JLabel("\u521D\u59CB\u503C");
	lblValue.setBounds(255, 270, 51, 15);
	panel_2.add(lblValue);

	initSect = new JTextField();
	initSect.setText("04");
	initSect.setBounds(245, 244, 25, 19);
	panel_2.add(initSect);
	initSect.setColumns(10);

	JLabel label_13 = new JLabel("\u6247\u533A");
	label_13.setBounds(274, 245, 51, 15);
	panel_2.add(label_13);

	JButton mfInit = new JButton("\u521D\u59CB\u5316");

	mfInit.setBounds(329, 240, 106, 25);
	panel_2.add(mfInit);

	JSeparator separator_3 = new JSeparator();
	separator_3.setBounds(12, 363, 423, 2);
	panel_2.add(separator_3);

	JLabel label_14 = new JLabel("\u521D\u59CB\u503C");
	label_14.setBounds(255, 336, 51, 15);
	panel_2.add(label_14);

	deValue = new JTextField();
	deValue.setText("01 00 00 00");
	deValue.setColumns(10);
	deValue.setBounds(166, 334, 87, 19);
	panel_2.add(deValue);

	deKey = new JTextField();
	deKey.setText("FF FF FF FF FF FF");
	deKey.setColumns(10);
	deKey.setBounds(12, 334, 117, 19);
	panel_2.add(deKey);

	JLabel label_15 = new JLabel("\u5BC6\u94A5");
	label_15.setBounds(131, 336, 31, 15);
	panel_2.add(label_15);

	deSector = new JTextField();
	deSector.setText("04");
	deSector.setColumns(10);
	deSector.setBounds(245, 310, 25, 19);
	panel_2.add(deSector);

	JLabel label_16 = new JLabel("\u6247\u533A");
	label_16.setBounds(274, 311, 51, 15);
	panel_2.add(label_16);

	JButton mfDeValue = new JButton("\u51CF\u503C");

	mfDeValue.setBounds(329, 306, 106, 25);
	panel_2.add(mfDeValue);

	JPanel panel_9 = new JPanel();
	panel_9.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_9.setBounds(12, 305, 95, 25);
	panel_2.add(panel_9);
	panel_9.setLayout(new BoxLayout(panel_9, BoxLayout.X_AXIS));

	final JRadioButton deIdle = new JRadioButton("Idle");
	buttonGroup_7.add(deIdle);
	panel_9.add(deIdle);
	deIdle.setSelected(true);

	JRadioButton radioButton_10 = new JRadioButton("All");
	buttonGroup_7.add(radioButton_10);
	panel_9.add(radioButton_10);

	JPanel panel_10 = new JPanel();
	panel_10.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_10.setBounds(108, 305, 130, 25);
	panel_2.add(panel_10);
	panel_10.setLayout(new BoxLayout(panel_10, BoxLayout.X_AXIS));

	final JRadioButton deKeyA = new JRadioButton("Key A");
	buttonGroup_6.add(deKeyA);
	panel_10.add(deKeyA);
	deKeyA.setSelected(true);

	JRadioButton radioButton_13 = new JRadioButton("Key B");
	buttonGroup_6.add(radioButton_13);
	panel_10.add(radioButton_13);

	inKey = new JTextField();
	inKey.setText("FF FF FF FF FF FF");
	inKey.setColumns(10);
	inKey.setBounds(12, 399, 117, 19);
	panel_2.add(inKey);

	inValue = new JTextField();
	inValue.setText("01 00 00 00");
	inValue.setColumns(10);
	inValue.setBounds(166, 399, 87, 19);
	panel_2.add(inValue);

	JLabel label_17 = new JLabel("\u5BC6\u94A5");
	label_17.setBounds(131, 401, 31, 15);
	panel_2.add(label_17);

	JLabel label_18 = new JLabel("\u521D\u59CB\u503C");
	label_18.setBounds(255, 401, 51, 15);
	panel_2.add(label_18);

	JLabel label_19 = new JLabel("\u6247\u533A");
	label_19.setBounds(274, 376, 51, 15);
	panel_2.add(label_19);

	inSector = new JTextField();
	inSector.setText("04");
	inSector.setColumns(10);
	inSector.setBounds(245, 375, 25, 19);
	panel_2.add(inSector);

	JButton mfInValue = new JButton("\u52A0\u503C");

	mfInValue.setBounds(329, 371, 106, 25);
	panel_2.add(mfInValue);

	JSeparator separator_4 = new JSeparator();
	separator_4.setBounds(12, 428, 423, 2);
	panel_2.add(separator_4);

	JPanel panel_11 = new JPanel();
	panel_11.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_11.setBounds(12, 370, 95, 25);
	panel_2.add(panel_11);
	panel_11.setLayout(new BoxLayout(panel_11, BoxLayout.X_AXIS));

	final JRadioButton inIdle = new JRadioButton("Idle");
	buttonGroup_9.add(inIdle);
	panel_11.add(inIdle);
	inIdle.setSelected(true);

	JRadioButton radioButton_15 = new JRadioButton("All");
	buttonGroup_9.add(radioButton_15);
	panel_11.add(radioButton_15);

	JPanel panel_12 = new JPanel();
	panel_12.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_12.setBounds(108, 370, 130, 25);
	panel_2.add(panel_12);
	panel_12.setLayout(new BoxLayout(panel_12, BoxLayout.X_AXIS));

	final JRadioButton inKeyA = new JRadioButton("Key A");
	buttonGroup_8.add(inKeyA);
	panel_12.add(inKeyA);
	inKeyA.setSelected(true);

	JRadioButton radioButton_17 = new JRadioButton("Key B");
	buttonGroup_8.add(radioButton_17);
	panel_12.add(radioButton_17);

	JPanel panel_13 = new JPanel();
	panel_13.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_13.setBounds(12, 433, 95, 25);
	panel_2.add(panel_13);
	panel_13.setLayout(new BoxLayout(panel_13, BoxLayout.X_AXIS));

	final JRadioButton snrIdle = new JRadioButton("Idle");
	buttonGroup_11.add(snrIdle);
	panel_13.add(snrIdle);
	snrIdle.setSelected(true);

	JRadioButton radioButton_19 = new JRadioButton("All");
	buttonGroup_11.add(radioButton_19);
	panel_13.add(radioButton_19);

	JPanel panel_14 = new JPanel();
	panel_14.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_14.setBounds(108, 433, 130, 25);
	panel_2.add(panel_14);
	panel_14.setLayout(new BoxLayout(panel_14, BoxLayout.X_AXIS));

	final JRadioButton snrHalt = new JRadioButton("halt");
	buttonGroup_10.add(snrHalt);
	panel_14.add(snrHalt);
	snrHalt.setSelected(true);

	JRadioButton radioButton_21 = new JRadioButton("no halt");
	buttonGroup_10.add(radioButton_21);
	panel_14.add(radioButton_21);

	JButton button_2 = new JButton("\u8BFB\u5361\u53F7");

	button_2.setBounds(274, 433, 161, 25);
	panel_2.add(button_2);

	JPanel panel_15 = new JPanel();
	tabbedPane.addTab("Ultralight", null, panel_15, null);
	panel_15.setLayout(null);

	JPanel panel_16 = new JPanel();
	panel_16.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_16.setBounds(8, 8, 99, 23);
	panel_15.add(panel_16);
	panel_16.setLayout(new BoxLayout(panel_16, BoxLayout.X_AXIS));

	final JRadioButton ulsnrIdle = new JRadioButton("Idle");
	buttonGroup_12.add(ulsnrIdle);
	panel_16.add(ulsnrIdle);
	ulsnrIdle.setSelected(true);

	JRadioButton radioButton_3 = new JRadioButton("All");
	buttonGroup_12.add(radioButton_3);
	panel_16.add(radioButton_3);

	JButton ulSnr = new JButton("\u5E8F\u5217\u53F7");

	ulSnr.setBounds(281, 7, 154, 25);
	panel_15.add(ulSnr);

	JSeparator separator_5 = new JSeparator();
	separator_5.setBounds(8, 43, 427, 2);
	panel_15.add(separator_5);

	JButton ulHalt = new JButton("Halt");

	ulHalt.setBounds(364, 57, 71, 25);
	panel_15.add(ulHalt);

	JLabel lblHalt = new JLabel("Halt:");
	lblHalt.setBounds(8, 62, 70, 15);
	panel_15.add(lblHalt);

	JSeparator separator_6 = new JSeparator();
	separator_6.setBounds(8, 94, 427, 2);
	panel_15.add(separator_6);

	JLabel lblUltralightCard = new JLabel("Ultralight Card");
	lblUltralightCard.setBounds(8, 108, 118, 15);
	panel_15.add(lblUltralightCard);

	JLabel lblRead = new JLabel("\u8BFB\u5361");
	lblRead.setBounds(8, 135, 70, 15);
	panel_15.add(lblRead);

	JLabel lblBlock = new JLabel("\u6247\u533A:");
	lblBlock.setBounds(8, 162, 70, 15);
	panel_15.add(lblBlock);

	JScrollPane scrollPane_1 = new JScrollPane();
	scrollPane_1.setBounds(8, 189, 99, 220);
	panel_15.add(scrollPane_1);

	final JList ulreadBlock = new JList();
	ulreadBlock.setModel(new AbstractListModel() {
		String[] values = new String[] { "00", "01", "02", "03", "04",
				"05", "06", "07", "08", "09", "10", "11", "12", "13", "14",
				"15" };

		public int getSize() {
			return values.length;
		}

		public Object getElementAt(int index) {
			return values[index];
		}
	});
	ulreadBlock.setSelectedIndex(0);
	scrollPane_1.setViewportView(ulreadBlock);

	JPanel panel_17 = new JPanel();
	panel_17.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_17.setBounds(8, 415, 99, 23);
	panel_15.add(panel_17);
	panel_17.setLayout(new BoxLayout(panel_17, BoxLayout.X_AXIS));

	final JRadioButton ulreadIdle = new JRadioButton("Idle");
	buttonGroup_13.add(ulreadIdle);
	panel_17.add(ulreadIdle);
	ulreadIdle.setSelected(true);

	JRadioButton radioButton_4 = new JRadioButton("All");
	buttonGroup_13.add(radioButton_4);
	panel_17.add(radioButton_4);

	JButton ulRead = new JButton("\u8BFB\u5361");
	ulRead.setBounds(111, 415, 87, 23);
	panel_15.add(ulRead);

	JButton ulWrite = new JButton("\u5199\u5361");

	ulWrite.setBounds(325, 415, 87, 23);
	panel_15.add(ulWrite);

	JScrollPane scrollPane_2 = new JScrollPane();
	scrollPane_2.setBounds(222, 189, 99, 220);
	panel_15.add(scrollPane_2);

	final JList ulwriteBlock = new JList();
	ulwriteBlock.setModel(new AbstractListModel() {
		String[] values = new String[] { "00", "01", "02", "03", "04",
				"05", "06", "07", "08", "09", "10", "11", "12", "13", "14",
				"15" };

		public int getSize() {
			return values.length;
		}

		public Object getElementAt(int index) {
			return values[index];
		}
	});
	ulwriteBlock.setSelectedIndex(0);
	scrollPane_2.setViewportView(ulwriteBlock);

	JLabel label_20 = new JLabel("\u6247\u533A:");
	label_20.setBounds(222, 162, 70, 15);
	panel_15.add(label_20);

	JLabel lblWrite = new JLabel("\u5199\u5361");
	lblWrite.setBounds(222, 135, 70, 15);
	panel_15.add(lblWrite);

	JPanel panel_18 = new JPanel();
	panel_18.setBorder(new LineBorder(new Color(0, 0, 0)));
	panel_18.setBounds(223, 415, 99, 23);
	panel_15.add(panel_18);
	panel_18.setLayout(new BoxLayout(panel_18, BoxLayout.X_AXIS));

	final JRadioButton ulwriteIdle = new JRadioButton("Idle");
	buttonGroup_14.add(ulwriteIdle);
	panel_18.add(ulwriteIdle);
	ulwriteIdle.setSelected(true);

	JRadioButton radioButton_8 = new JRadioButton("All");
	buttonGroup_14.add(radioButton_8);
	panel_18.add(radioButton_8);

	ulwriteData = new JTextField();
	ulwriteData.setText("00 00 00 00");
	ulwriteData.setBounds(325, 390, 87, 19);
	panel_15.add(ulwriteData);
	ulwriteData.setColumns(10);
	
	JPanel panel_19 = new JPanel();
	tabbedPane.addTab("14443B", null, panel_19, null);
	panel_19.setLayout(null);
	
	JLabel lblbCommands = new JLabel("14443B \u547D\u4EE4");
	lblbCommands.setBounds(12, 12, 130, 15);
	panel_19.add(lblbCommands);
	
	JButton bRequest = new JButton("\u5361\u8BF7\u6C42");
	
	bRequest.setBounds(342, 32, 93, 25);
	panel_19.add(bRequest);
	
	JSeparator separator_7 = new JSeparator();
	separator_7.setBounds(8, 69, 427, 2);
	panel_19.add(separator_7);
	
	JLabel lblDataLength = new JLabel("\u8981\u53D1\u9001\u7684\u6570\u636E\u957F\u5EA6:");
	lblDataLength.setBounds(12, 83, 109, 15);
	panel_19.add(lblDataLength);
	
	bDataLen = new JTextField();
	bDataLen.setText("08");
	bDataLen.setBounds(120, 81, 34, 19);
	panel_19.add(bDataLen);
	bDataLen.setColumns(10);
	
	JLabel lblData_1 = new JLabel("\u8981\u53D1\u9001\u7684\u6570\u636E\u957F\u5EA6:");
	lblData_1.setBounds(12, 110, 109, 15);
	panel_19.add(lblData_1);
	
	bData = new JTextField();
	bData.setText("00 00 05 00 84 00 00 08");
	bData.setBounds(118, 108, 317, 19);
	panel_19.add(bData);
	bData.setColumns(10);
	
	JButton bTrans = new JButton("\u53D1\u9001\u6570\u636E");
	
	bTrans.setBounds(280, 78, 155, 25);
	panel_19.add(bTrans);
	
	JSeparator separator_8 = new JSeparator();
	separator_8.setBounds(12, 139, 427, 2);
	panel_19.add(separator_8);
	
	JLabel lblChinaIdenty = new JLabel("\u7B2C\u4E8C\u4EE3\u5C45\u6C11\u8EAB\u4EFD\u8BC1");
	lblChinaIdenty.setBounds(12, 153, 209, 15);
	panel_19.add(lblChinaIdenty);
	
	JButton bUID = new JButton("\u83B7\u53D6\u8EAB\u4EFD\u8BC1\u53F7");
	//bUID.setEnabled(false);
	bUID.setBounds(318, 193, 117, 25);
	panel_19.add(bUID);
	
	JPanel panel_20 = new JPanel();
	tabbedPane.addTab("15693", null, panel_20, null);
	panel_20.setLayout(null);
	
	JLabel lblCommands = new JLabel("15693 \u547D\u4EE4");
	lblCommands.setBounds(12, 12, 119, 15);
	panel_20.add(lblCommands);
	
	JButton btnInventory = new JButton("\u9632\u51B2\u7A81");
	//btnInventory.setEnabled(false);
	btnInventory.setBounds(334, 25, 101, 25);
	panel_20.add(btnInventory);
	
	JSeparator separator_9 = new JSeparator();
	separator_9.setBounds(12, 55, 427, 2);
	panel_20.add(separator_9);
	
	isoreadFlag = new JTextField();
	isoreadFlag.setText("02");
	isoreadFlag.setBounds(12, 65, 27, 19);
	panel_20.add(isoreadFlag);
	isoreadFlag.setColumns(10);
	
	JLabel lblFlag = new JLabel("\u6807\u5FD7\u4F4D");
	lblFlag.setBounds(46, 67, 54, 15);
	panel_20.add(lblFlag);
	
	isoreadAdd = new JTextField();
	isoreadAdd.setText("05");
	isoreadAdd.setColumns(10);
	isoreadAdd.setBounds(100, 65, 27, 19);
	panel_20.add(isoreadAdd);
	
	JLabel lblStartArea = new JLabel("\u8D77\u59CB\u5757");
	lblStartArea.setBounds(134, 67, 67, 15);
	panel_20.add(lblStartArea);
	
	isoNum = new JTextField();
	isoNum.setText("01");
	isoNum.setColumns(10);
	isoNum.setBounds(201, 65, 27, 19);
	panel_20.add(isoNum);
	
	JLabel lblNumber = new JLabel("\u5757\u6570\u91CF");
	lblNumber.setBounds(235, 67, 54, 15);
	panel_20.add(lblNumber);
	
	JButton isoRead = new JButton("\u5361\u7247\u8BFB");
	
	isoRead.setBounds(316, 62, 119, 25);
	panel_20.add(isoRead);
	
	isoUID = new JTextField();
	isoUID.setBounds(12, 87, 170, 19);
	panel_20.add(isoUID);
	isoUID.setColumns(10);
	
	JLabel lblUid = new JLabel("UID");
	lblUid.setBounds(190, 89, 27, 15);
	panel_20.add(lblUid);
	
	JSeparator separator_10 = new JSeparator();
	separator_10.setBounds(8, 113, 427, 2);
	panel_20.add(separator_10);
	
	JSeparator separator_11 = new JSeparator();
	separator_11.setBounds(8, 190, 427, 2);
	panel_20.add(separator_11);
	
	isoWriteUID = new JTextField();
	isoWriteUID.setColumns(10);
	isoWriteUID.setBounds(12, 143, 170, 19);
	panel_20.add(isoWriteUID);
	
	JLabel label_21 = new JLabel("UID");
	label_21.setBounds(190, 145, 27, 15);
	panel_20.add(label_21);
	
	JLabel label_22 = new JLabel("\u8D77\u59CB\u5757");
	label_22.setBounds(134, 123, 54, 15);
	panel_20.add(label_22);
	
	isowriteAdd = new JTextField();
	isowriteAdd.setText("05");
	isowriteAdd.setColumns(10);
	isowriteAdd.setBounds(104, 121, 27, 19);
	panel_20.add(isowriteAdd);
	
	JLabel label_23 = new JLabel("\u6807\u5FD7\u4F4D");
	label_23.setBounds(46, 123, 54, 15);
	panel_20.add(label_23);
	
	isowriteFlag = new JTextField();
	isowriteFlag.setText("02");
	isowriteFlag.setColumns(10);
	isowriteFlag.setBounds(12, 121, 27, 19);
	panel_20.add(isowriteFlag);
	
	isoWriteNum = new JTextField();
	isoWriteNum.setText("01");
	isoWriteNum.setColumns(10);
	isoWriteNum.setBounds(201, 121, 27, 19);
	panel_20.add(isoWriteNum);
	
	JLabel label_24 = new JLabel("\u5757\u6570\u91CF");
	label_24.setBounds(235, 123, 54, 15);
	panel_20.add(label_24);
	
	JButton btnWriteCard = new JButton("\u5361\u7247\u5199");
	
	btnWriteCard.setBounds(316, 118, 119, 25);
	panel_20.add(btnWriteCard);
	
	isowriteData = new JTextField();
	isowriteData.setText("11 11 11 11");
	isowriteData.setColumns(10);
	isowriteData.setBounds(58, 165, 231, 19);
	panel_20.add(isowriteData);
	
	JLabel lblData_2 = new JLabel("\u6570\u636E:");
	lblData_2.setBounds(12, 165, 47, 15);
	panel_20.add(lblData_2);
	
	JLabel lblBlock_1 = new JLabel("\u8D77\u59CB\u5757");
	lblBlock_1.setBounds(128, 199, 37, 15);
	panel_20.add(lblBlock_1);
	
	isolbBlock = new JTextField();
	isolbBlock.setText("01");
	isolbBlock.setColumns(10);
	isolbBlock.setBounds(100, 197, 27, 19);
	panel_20.add(isolbBlock);
	
	JLabel label_27 = new JLabel("\u6807\u5FD7\u4F4D");
	label_27.setBounds(40, 199, 60, 15);
	panel_20.add(label_27);
	
	isolbFlag = new JTextField();
	isolbFlag.setText("02");
	isolbFlag.setColumns(10);
	isolbFlag.setBounds(12, 197, 27, 19);
	panel_20.add(isolbFlag);
	
	isoblUID = new JTextField();
	isoblUID.setColumns(10);
	isoblUID.setBounds(164, 197, 125, 19);
	panel_20.add(isoblUID);
	
	JLabel lblUid_1 = new JLabel("UID");
	lblUid_1.setBounds(291, 199, 27, 15);
	panel_20.add(lblUid_1);
	
	JButton isoLockBlock = new JButton("\u9501\u5B9A\u5757");
	
	isoLockBlock.setBounds(328, 194, 107, 25);
	panel_20.add(isoLockBlock);
	
	JSeparator separator_12 = new JSeparator();
	separator_12.setBounds(8, 226, 427, 2);
	panel_20.add(separator_12);
	
	JSeparator separator_13 = new JSeparator();
	separator_13.setBounds(8, 267, 427, 2);
	panel_20.add(separator_13);
	
	isoscUID = new JTextField();
	isoscUID.setColumns(10);
	isoscUID.setBounds(135, 238, 125, 19);
	panel_20.add(isoscUID);
	
	JLabel label_26 = new JLabel("\u6807\u5FD7\u4F4D");
	label_26.setBounds(40, 240, 54, 15);
	panel_20.add(label_26);
	
	isoscFlag = new JTextField();
	isoscFlag.setText("02");
	isoscFlag.setColumns(10);
	isoscFlag.setBounds(12, 238, 27, 19);
	panel_20.add(isoscFlag);
	
	JLabel label_28 = new JLabel("UID");
	label_28.setBounds(270, 242, 27, 15);
	panel_20.add(label_28);
	
	JButton isoSelCard = new JButton("\u9009\u62E9\u5757");
	
	isoSelCard.setBounds(304, 235, 131, 25);
	panel_20.add(isoSelCard);
	
	JSeparator separator_14 = new JSeparator();
	separator_14.setBounds(8, 305, 427, 2);
	panel_20.add(separator_14);
	
	isowaUID = new JTextField();
	isowaUID.setColumns(10);
	isowaUID.setBounds(145, 276, 125, 19);
	panel_20.add(isowaUID);
	
	JLabel lblAfi = new JLabel("AFI");
	lblAfi.setBounds(120, 280, 27, 15);
	panel_20.add(lblAfi);
	
	isowaAFI = new JTextField();
	isowaAFI.setText("02");
	isowaAFI.setColumns(10);
	isowaAFI.setBounds(84, 276, 27, 19);
	panel_20.add(isowaAFI);
	
	JLabel label_29 = new JLabel("\u6807\u5FD7\u4F4D");
	label_29.setBounds(40, 278, 47, 15);
	panel_20.add(label_29);
	
	isowaFlag = new JTextField();
	isowaFlag.setText("02");
	isowaFlag.setColumns(10);
	isowaFlag.setBounds(12, 276, 27, 19);
	panel_20.add(isowaFlag);
	
	JLabel label_30 = new JLabel("UID");
	label_30.setBounds(270, 278, 27, 15);
	panel_20.add(label_30);
	
	JButton isoWriteAfi = new JButton("\u5199AFI");
	
	isoWriteAfi.setBounds(328, 273, 107, 25);
	panel_20.add(isoWriteAfi);
	
	JSeparator separator_15 = new JSeparator();
	separator_15.setBounds(8, 343, 427, 2);
	panel_20.add(separator_15);
	
	isolaUID = new JTextField();
	isolaUID.setColumns(10);
	isolaUID.setBounds(86, 312, 125, 19);
	panel_20.add(isolaUID);
	
	JLabel label_31 = new JLabel("\u6807\u5FD7\u4F4D");
	label_31.setBounds(40, 316, 47, 15);
	panel_20.add(label_31);
	
	isolaFlag = new JTextField();
	isolaFlag.setText("02");
	isolaFlag.setColumns(10);
	isolaFlag.setBounds(12, 314, 27, 19);
	panel_20.add(isolaFlag);
	
	JLabel label_32 = new JLabel("UID");
	label_32.setBounds(211, 314, 27, 15);
	panel_20.add(label_32);
	
	JButton isoLockAfi = new JButton("\u9501\u5B9AAFI");
	
	isoLockAfi.setBounds(328, 311, 107, 25);
	panel_20.add(isoLockAfi);
	
	JSeparator separator_16 = new JSeparator();
	separator_16.setBounds(8, 456, 427, 2);
	panel_20.add(separator_16);
	
	isosiUID = new JTextField();
	isosiUID.setColumns(10);
	isosiUID.setBounds(86, 425, 125, 19);
	panel_20.add(isosiUID);
	
	JLabel label_33 = new JLabel("\u6807\u5FD7\u4F4D");
	label_33.setBounds(40, 429, 47, 15);
	panel_20.add(label_33);
	
	isosiFlag = new JTextField();
	isosiFlag.setText("02");
	isosiFlag.setColumns(10);
	isosiFlag.setBounds(12, 427, 27, 19);
	panel_20.add(isosiFlag);
	
	JLabel label_34 = new JLabel("UID");
	label_34.setBounds(211, 427, 27, 15);
	panel_20.add(label_34);
	
	JButton isoSysInfo = new JButton("\u7CFB\u7EDF\u4FE1\u606F");
	
	isoSysInfo.setBounds(256, 424, 179, 25);
	panel_20.add(isoSysInfo);
	
	JButton isoBS = new JButton("\u5757\u5B89\u5168\u4F4D");
	
	isoBS.setBounds(283, 483, 152, 25);
	panel_20.add(isoBS);
	
	JLabel label_25 = new JLabel("\u5757\u7684\u6570\u91CF");
	label_25.setBounds(231, 466, 54, 15);
	panel_20.add(label_25);
	
	isobsNum = new JTextField();
	isobsNum.setText("01");
	isobsNum.setColumns(10);
	isobsNum.setBounds(201, 464, 27, 19);
	panel_20.add(isobsNum);
	
	JLabel label_35 = new JLabel("UID");
	label_35.setBounds(186, 488, 27, 15);
	panel_20.add(label_35);
	
	isobsUID = new JTextField();
	isobsUID.setColumns(10);
	isobsUID.setBounds(8, 486, 170, 19);
	panel_20.add(isobsUID);
	
	JLabel label_36 = new JLabel("\u8D77\u59CB\u5757");
	label_36.setBounds(116, 466, 81, 15);
	panel_20.add(label_36);
	
	isobsAdd = new JTextField();
	isobsAdd.setText("05");
	isobsAdd.setColumns(10);
	isobsAdd.setBounds(84, 464, 27, 19);
	panel_20.add(isobsAdd);
	
	JLabel label_37 = new JLabel("\u6807\u5FD7\u4F4D");
	label_37.setBounds(40, 466, 37, 15);
	panel_20.add(label_37);
	
	isobsFlag = new JTextField();
	isobsFlag.setText("02");
	isobsFlag.setColumns(10);
	isobsFlag.setBounds(8, 464, 27, 19);
	panel_20.add(isobsFlag);
	
	JSeparator separator_17 = new JSeparator();
	separator_17.setBounds(8, 419, 427, 2);
	panel_20.add(separator_17);
	
	JButton btnLockDsfid = new JButton("\u9501\u5B9ADSFID");
	
	btnLockDsfid.setBounds(304, 387, 131, 25);
	panel_20.add(btnLockDsfid);
	
	JLabel label_38 = new JLabel("UID");
	label_38.setBounds(211, 390, 27, 15);
	panel_20.add(label_38);
	
	isoldUID = new JTextField();
	isoldUID.setColumns(10);
	isoldUID.setBounds(86, 388, 125, 19);
	panel_20.add(isoldUID);
	
	JLabel label_39 = new JLabel("\u6807\u5FD7\u4F4D");
	label_39.setBounds(40, 392, 47, 15);
	panel_20.add(label_39);
	
	isoldFlag = new JTextField();
	isoldFlag.setText("02");
	isoldFlag.setColumns(10);
	isoldFlag.setBounds(12, 390, 27, 19);
	panel_20.add(isoldFlag);
	
	JSeparator separator_18 = new JSeparator();
	separator_18.setBounds(8, 381, 427, 2);
	panel_20.add(separator_18);
	
	isowdUID = new JTextField();
	isowdUID.setColumns(10);
	isowdUID.setBounds(145, 352, 125, 19);
	panel_20.add(isowdUID);
	
	JLabel label_40 = new JLabel("UID");
	label_40.setBounds(270, 352, 27, 15);
	panel_20.add(label_40);
	
	JButton btnWriteDs = new JButton("\u5199DSFID");
	
	btnWriteDs.setBounds(304, 349, 131, 25);
	panel_20.add(btnWriteDs);
	
	JLabel lblDsfid = new JLabel("DSFID");
	lblDsfid.setBounds(110, 355, 37, 15);
	panel_20.add(lblDsfid);
	
	isowdDSFID = new JTextField();
	isowdDSFID.setText("08");
	isowdDSFID.setColumns(10);
	isowdDSFID.setBounds(84, 355, 27, 19);
	panel_20.add(isowdDSFID);
	
	JLabel label_42 = new JLabel("\u6807\u5FD7\u4F4D");
	label_42.setBounds(40, 354, 47, 15);
	panel_20.add(label_42);
	
	isowdFlag = new JTextField();
	isowdFlag.setText("02");
	isowdFlag.setColumns(10);
	isowdFlag.setBounds(12, 352, 27, 19);
	panel_20.add(isowdFlag);

	JPanel panel_1 = new JPanel();
	frame.getContentPane().add(panel_1);
	panel_1.setLayout(new BorderLayout(0, 0));

	JLabel lblData = new JLabel("\u8F93\u51FA:");
	panel_1.add(lblData, BorderLayout.NORTH);

	JScrollPane scrollPane = new JScrollPane();
	panel_1.add(scrollPane, BorderLayout.CENTER);

	dataArea = new JTextArea();
	scrollPane.setViewportView(dataArea);
	btnSetSernum.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			String s0 = sysSerNum.getText();
			checkdata(s0);
			Pointer p = null;
			try {
				p = new Pointer(MemoryBlockFactory.createMemoryBlock(8));
			} catch (NativeException e2) {
				// TODO Auto-generated catch block
				e2.printStackTrace();
			}
			for (int  i = 0 ; i < 8 ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
					try {
						p.setByteAt(i, value);
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
			}
			int ret = Function.SetSerNum(p);
			if (ret == 0)
			{
				output("success\n");
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason+"\n");
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
																																																					
	btnReadSernum.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			int ret = Function.GetSerNum();
			if (ret == 0)
			{
				output("success\n");
				for(int i = 1 ; i <=8 ; i ++)
				{
					byte t0 = 0;
					try {
						t0 = Function.a.getAsByte(i);
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
					String t1 = String.format("%02X", t0);
					output(t1+" ");
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.reason = "";
			}
		}
	});
																																																							
	btnSetLed.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			int int0 = Integer.parseInt(ledCycle.getText());
			int int1 = Integer.parseInt(ledTimes.getText());
			int ret = Function.ControlLED(int0,int1);
			if (ret == 0)
			{
				output("success\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
			}
	});
																																																									
	btnSetBuzzer.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			int int0 = Integer.parseInt(bzrCycle.getText());
			int int1 = Integer.parseInt(bzrTimes.getText());
			int ret = Function.ControlBuzzer(int0,int1);
			if (ret == 0)
			{
				output("success\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
																																																											
	btnGetversion.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			int ret = Function.GetVersionNum();
			if (ret == 0)
			{
				output("success\n");
				for(int i = 1 ; i <=11 ; i ++)
				{
					byte t0 = 0;
					try {
						t0 = Function.a.getAsByte(i);
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
					String t1 = String.format("%02X", t0);
					output(t1+" ");
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.reason = "";
			}
		}
	});
	
	// 14443B-MF
	mfRead.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte mode,t0,t1;
			if (readIdle.isSelected())
			{
				if(readKeyA.isSelected())
					mode = 0x00;
				else
					mode = 0x02;
			}
			else
			{
				if(readKeyA.isSelected())
					mode = 0x01;
				else
					mode = 0x03;
			}
			//System.out.println("mode="+mode+"\n");
			byte add_blk = (byte) Integer.parseInt((String) mfreadAdd.getSelectedItem(),16);
			byte num_blk = (byte) Integer.parseInt((String) mfreadNum.getSelectedItem(),16);
			
			String t2 = (String) mfreadKey.getSelectedItem();
			checkdata(t2);
			Pointer p = null ;
			try {
				p = new Pointer(MemoryBlockFactory.createMemoryBlock(6));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < 6 ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					p.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.MF_Read(mode, add_blk, num_blk, p);
			if(ret == 0)
			{
				output("success\n");
				output("Card Number:\n");
				for ( int i = 0 ; i < 4 ; i ++)
				{
					try {
						output(String.format("%02X", Function.b.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\nCard Data:\n");
				for ( int i = 0 ; i < 16*num_blk ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	mfWrite.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte mode,t0,t1;
			if (writeIdle.isSelected())
			{
				if(writeKeyA.isSelected())
					mode = 0x00;
				else
					mode = 0x02;
			}
			else
			{
				if(writeKeyA.isSelected())
					mode = 0x01;
				else
					mode = 0x03;
			}
			//System.out.println("mode="+mode+"\n");
			byte add_blk = (byte) Integer.parseInt((String) mfwriteAdd.getSelectedItem(),16);
			byte num_blk = (byte) Integer.parseInt((String) mfwriteNum.getSelectedItem(),16);

			String t2 = (String) mfwriteKey.getSelectedItem();
			checkdata(t2);
			Pointer p = null ;
			try {
				p = new Pointer(MemoryBlockFactory.createMemoryBlock(6));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < 6 ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					p.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			String t3 = (String) mfwriteData.getText();
			checkdata(t3);
			if(s100.length() != num_blk * 32)
			{
				output("input error,the data length is not accord,please checkout again.. \n");
				return;
			}
			else
			{
			Pointer data = null ;
			try {
				data = new Pointer(MemoryBlockFactory.createMemoryBlock(16*num_blk));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < 16 * num_blk ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					data.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.MF_Write(mode, add_blk, num_blk, p, data);
			if(ret == 0)
			{
				output("success\n");
				output("Card Number:\n");
				for ( int i = 0 ; i < 4 ; i ++)
				{
					try {
						output(String.format("%02X", Function.b.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
				
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
		}
	});

	mfInit.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte mode,t0,t1;
			if (initIdle.isSelected())
			{
				if(initKeyA.isSelected())
					mode = 0x00;
				else
					mode = 0x02;
			}
			else
			{
				if(initKeyA.isSelected())
					mode = 0x01;
				else
					mode = 0x03;
			}
			//System.out.println("mode="+mode+"\n");
			byte secNum = (byte)Integer.parseInt(initSect.getText(),16);
			String t2 = (String) initKey.getText();
			checkdata(t2);
			Pointer p = null ;
			try {
				p = new Pointer(MemoryBlockFactory.createMemoryBlock(6));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < 6 ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					p.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			String t3 = (String) initValue.getText();
			checkdata(t3);
			Pointer v = null ;
			try {
				v = new Pointer(MemoryBlockFactory.createMemoryBlock(4));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < 4 ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					v.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.MF_InitValue(mode, secNum, p, v);
			if(ret == 0)
			{
				output("success\n");
				output("Card Number:\n");
				for ( int i = 0 ; i < 4 ; i ++)
				{
					try {
						output(String.format("%02X", Function.b.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
				
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});

	mfDeValue.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte mode,t0,t1;
			if (deIdle.isSelected())
			{
				if(deKeyA.isSelected())
					mode = 0x00;
				else
					mode = 0x02;
			}
			else
			{
				if(deKeyA.isSelected())
					mode = 0x01;
				else
					mode = 0x03;
			}
			//System.out.println("mode="+mode+"\n");
			byte secNum = (byte)Integer.parseInt(deSector.getText(),16);
			String t2 = (String) deKey.getText();
			checkdata(t2);
			Pointer p = null ;
			try {
				p = new Pointer(MemoryBlockFactory.createMemoryBlock(6));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < 6 ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					p.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			String t3 = (String) deValue.getText();
			checkdata(t3);
			Pointer v = null ;
			try {
				v = new Pointer(MemoryBlockFactory.createMemoryBlock(4));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < 4 ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					v.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.MF_Dec(mode, secNum, p, v);
			if(ret == 0)
			{
				output("success\n");
				output("Card Number:\n");
				for ( int i = 0 ; i < 4 ; i ++)
				{
					try {
						output(String.format("%02X", Function.b.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
				
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});

	mfInValue.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte mode,t0,t1;
			if (inIdle.isSelected())
			{
				if(inKeyA.isSelected())
					mode = 0x00;
				else
					mode = 0x02;
			}
			else
			{
				if(inKeyA.isSelected())
					mode = 0x01;
				else
					mode = 0x03;
			}
			//System.out.println("mode="+mode+"\n");
			byte secNum = (byte)Integer.parseInt(inSector.getText(),16);
			String t2 = (String) inKey.getText();
			checkdata(t2);
			Pointer p = null ;
			try {
				p = new Pointer(MemoryBlockFactory.createMemoryBlock(6));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < 6 ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					p.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			String t3 = (String) inValue.getText();
			checkdata(t3);
			Pointer v = null ;
			try {
				v = new Pointer(MemoryBlockFactory.createMemoryBlock(4));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < 4 ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					v.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.MF_Inc(mode, secNum, p, v);
			if(ret == 0)
			{
				output("success\n");
				output("Card Number:\n");
				for ( int i = 0 ; i < 4 ; i ++)
				{
					try {
						output(String.format("%02X", Function.b.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
				
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});

	button_2.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte mode,halt,t0,t1;
			if (snrIdle.isSelected())
			{
				mode = 0x26;
			}
			else
			{
				mode = 0x52;
			}
			if(snrHalt.isSelected())
			{
				halt = 0x00;
			}
			else
			{
				halt = 0x01;
			}
			Pointer p = null ;
			try {
				p = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			Pointer v = null ;
			try {
				v = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int ret = Function.MF_Getsnr(mode, halt, p, v);
			if ( ret == 0)
			{
				output("success\n");
				if(Function.byte0 == 0)
				{
					output("It is only one card...\n");
				}
				else
				{
					output("It is more than one card...\n");
				}
				output("Card Number:\n");
				for ( int i = 0 ; i < 4 ; i ++)
				{
					try {
						output(String.format("%02X", Function.b.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});

	// ultralight
	ulSnr.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte mode;
			if(ulsnrIdle.isSelected())
				mode = 0x00;
			else
				mode = 0x01;
			int ret = Function.UL_Request(mode);
			if (ret == 0)
			{
				output("success\n");
				output("The Card Number:\n");
				for ( int i = 0 ; i < 7 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});

	ulHalt.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			int ret = Function.MF_Halt();
			if (ret == 0)
			{
				output("success\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});

	ulRead.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte mode,blk_add,t0,t1;
			if(ulreadIdle.isSelected())
			{
				mode = 0x00;
			}
			else
			{
				mode = 0x01;
			}
			blk_add = (byte)ulreadBlock.getSelectedIndex();
			int ret = Function.UL_HLRead(mode, blk_add);
			if ( ret == 0)
			{
				output("success\n");
				output("Card Number:\n");
				for ( int i = 0 ; i < 7 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\nCard Data:\n");
				for ( int i = 0 ; i < 16 ; i ++)
				{
					try {
						output(String.format("%02X", Function.b.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});

	ulWrite.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte mode,blk_add,t0,t1;
			if(ulwriteIdle.isSelected())
			{
				mode = 0x00;
			}
			else
			{
				mode = 0x01;
			}
			String s = ulwriteData.getText();
			checkdata(s);
			blk_add = (byte)ulwriteBlock.getSelectedIndex();
			Pointer p = null;
			try {
				p = new Pointer(MemoryBlockFactory.createMemoryBlock(4));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < 4 ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					p.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.UL_HLWrite(mode, blk_add,p);
			System.out.println(ret);
			if ( ret == 0)
			{
				output("success\n");
				output("Card Number:\n");
				for ( int i = 0 ; i < 7 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	//14443B
	bRequest.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			int ret = Function.TypeB_Request();
			if ( ret == 0)
			{
				output("success\n");
				output("Data length:\n");
				for ( int i = 0 ; i < 1 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("Data:\n");
				for ( int i = 1 ; i < Function.byte0 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
			
			
		}
	});
	
	bTrans.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			int cmdSize = Integer.parseInt(bDataLen.getText(),16);
			String t3 = (String) bData.getText();
			checkdata(t3);
			Pointer cmd = null;
			try {
				cmd = new Pointer(MemoryBlockFactory.createMemoryBlock(cmdSize));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < cmdSize ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					cmd.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.TypeB_TransCOS(cmd, cmdSize);
			if ( ret == 0)
			{
				output("success\n");
				output("The Data:\n");
				for ( int i = 0 ; i < 8 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	bUID.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte mode = 0x26;
			byte halt = 0x00;
			int ret = Function.TYPEB_SFZSNR(mode, halt);
			if ( ret == 0)
			{
				output("success\n");
				try {
					if(Function.a.getAsByte(0) == 0x00)
					{
						output("Only one card.....\n");
					}
					else
					{
						output("More than one card.....\n");
					}
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				for ( int i = 0 ; i < 8 ; i ++)
				{
					try {
						output(String.format("%02X", Function.b.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	//15693
	btnInventory.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			int ret = Function.ISO15693_Inventory();
			for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
				ret = Function.ISO15693_Inventory();
			if(ret == 0)
			{
				output("success\n");
				output("The card number is :\n");
				output(String.format("%02X", Function.byte0)+" ");
				output("\n");
				output("The receive card datas is :\n");
				for ( int i = 0 ; i < 10*Function.byte0 ; i ++)
				{
					try {
						output(String.format("%02X", Function.b.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n");
				for ( int i = 0 ; i < Function.byte0 ; i ++)
				{
					output("No."+(i+1)+" card data:\n");
					for (int j = 0 ; j < 8 ; j ++)
					{
						try {
							output(String.format("%02X", Function.b.getAsByte(Function.byte0 * 10 - ( i * 10  + j ) - 1 )) +" ");
						} catch (NativeException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}
					}
				}
				output("\n\n");
				
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	isoRead.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte flags,blk_add,num_blk;
			flags = (byte) Integer.parseInt(isoreadFlag.getText(),16);
			blk_add = (byte) Integer.parseInt(isoreadAdd.getText(),16);
			num_blk = (byte) Integer.parseInt(isoNum.getText(),16);
			String s0 = isoUID.getText();
			checkdata(s0);
			Pointer uid = null ;
			try {
				uid = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int len = s100.length() / 2;
			for (int  i = 0 ; i < len ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					uid.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int n;
			if(flags == 0x42)
				n = 5;
			else
				n = 4;
			int ret = Function.ISO15693_Read(flags, blk_add, num_blk, uid);
			for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
			 	ret = Function.ISO15693_Read(flags, blk_add, num_blk, uid);
			if(ret == 0)
			{
				output("success\n");
				output("Flags:\n");
				output(String.format("%02X", Function.byte0)+" ");
				output("\n");
				output("The card data:\n");
				for ( int i = 1 ; i < n * num_blk + 1 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	btnWriteCard.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte flags,blk_add,num_blk;
			flags = (byte) Integer.parseInt(isowriteFlag.getText(),16);
			blk_add = (byte) Integer.parseInt(isowriteAdd.getText(),16);
			num_blk = (byte) Integer.parseInt(isoNum.getText(),16);
			String s0 = isoWriteUID.getText();
			checkdata(s0);
			Pointer uid = null ;
			try {
				uid = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int len = s100.length() / 2 ;
			for (int  i = 0 ; i < len ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					uid.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int n;
			if(flags == 0x42)
				n = 5;
			else
				n = 4;
			String s1 = isowriteData.getText();
			checkdata(s1);
			Pointer data = null ;
			try {
				data = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			for (int  i = 0 ; i < n * num_blk ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					data.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.ISO15693_Write(flags, blk_add, num_blk, uid,data);
			System.out.println(ret);
			//for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
			 //	ret = Function.ISO15693_Write(flags, blk_add, num_blk, uid, data);
			if(ret == 0)
			{
				output("success\n");
				output("\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	isoLockBlock.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte flags,blk_add;
			flags = (byte) Integer.parseInt(isolbFlag.getText(),16);
			blk_add = (byte) Integer.parseInt(isolbBlock.getText(),16);
			String s0 = isoblUID.getText();
			checkdata(s0);
			Pointer uid = null ;
			try {
				uid = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int len = s100.length() / 2;
			for (int  i = 0 ; i < len ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					uid.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int n;
			if(flags == 0x42)
				n = 5;
			else
				n = 4;
			int ret = Function.ISO15693_Lock(flags, blk_add, uid);
			System.out.println(ret);
			//for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
			 //	ret = Function.ISO15693_Write(flags, blk_add, num_blk, uid, data);
			if(ret == 0)
			{
				output("success\n");
				output("\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	isoSelCard.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte flags;
			flags = (byte) Integer.parseInt(isoscFlag.getText(),16);
			String s0 = isoscUID.getText();
			checkdata(s0);
			Pointer uid = null ;
			try {
				uid = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int len = s100.length() / 2;
			for (int  i = 0 ; i < len ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					uid.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.ISO15693_Select(flags, uid);
			//for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
			 //	ret = Function.ISO15693_Write(flags, blk_add, num_blk, uid, data);
			if(ret == 0)
			{
				output("success\n");
				output("\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	isoWriteAfi.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte flags,afi;
			flags = (byte) Integer.parseInt(isowaFlag.getText(),16);
			afi = (byte) Integer.parseInt(isowaAFI.getText(),16);
			String s0 = isowaUID.getText();
			checkdata(s0);
			Pointer uid = null ;
			try {
				uid = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int len = s100.length() / 2;
			for (int  i = 0 ; i < len ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					uid.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.ISO15693_WriteAFI(flags, afi,uid);
			System.out.println(ret);
			//for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
			 //	ret = Function.ISO15693_Write(flags, blk_add, num_blk, uid, data);
			if(ret == 0)
			{
				output("success\n");
				output("\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	isoLockAfi.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte flags;
			flags = (byte) Integer.parseInt(isolaFlag.getText(),16);
			String s0 = isolaUID.getText();
			checkdata(s0);
			Pointer uid = null ;
			try {
				uid = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int len = s100.length() / 2;
			for (int  i = 0 ; i < len ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					uid.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.ISO15693_LockAFI(flags,uid);
			//System.out.println(ret);
			//for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
			 //	ret = Function.ISO15693_Write(flags, blk_add, num_blk, uid, data);
			if(ret == 0)
			{
				output("success\n");
				output("\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	btnWriteDs.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte flags,DSFID;
			flags = (byte) Integer.parseInt(isowdFlag.getText(),16);
			DSFID = (byte) Integer.parseInt(isowdDSFID.getText(),16);
			String s0 = isowdUID.getText();
			checkdata(s0);
			Pointer uid = null ;
			try {
				uid = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int len = s100.length() / 2;
			for (int  i = 0 ; i < len ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					uid.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.ISO15693_WriteDSFID(flags, DSFID ,uid);
			System.out.println(ret);
			//for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
			 //	ret = Function.ISO15693_Write(flags, blk_add, num_blk, uid, data);
			if(ret == 0)
			{
				output("success\n");
				output("\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	btnLockDsfid.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte flags;
			flags = (byte) Integer.parseInt(isoldFlag.getText(),16);
			String s0 = isoldUID.getText();
			checkdata(s0);
			Pointer uid = null ;
			try {
				uid = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int len = s100.length() / 2;
			for (int  i = 0 ; i < len ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					uid.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.ISO15693_LockDSFID(flags,uid);
			//System.out.println(ret);
			//for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
			 //	ret = Function.ISO15693_Write(flags, blk_add, num_blk, uid, data);
			if(ret == 0)
			{
				output("success\n");
				output("\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	isoSysInfo.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte flags;
			flags = (byte) Integer.parseInt(isosiFlag.getText(),16);
			String s0 = isosiUID.getText();
			checkdata(s0);
			Pointer uid = null ;
			try {
				uid = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int len = s100.length() / 2;
			for (int  i = 0 ; i < len ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					uid.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.ISO15693_GetSysInfo(flags,uid);
			//System.out.println(ret);
			//for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
			 //	ret = Function.ISO15693_Write(flags, blk_add, num_blk, uid, data);
			if(ret == 0)
			{
				output("success\n");
				output("Flags:\n");
				for ( int i = 0 ; i < 1 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n");
				output("INFO FLAGS:\n");
				for ( int i = 1 ; i < 2 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n");
				output("UID:\n");
				for ( int i = 2 ; i < 10 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n");
				output("DSFID:\n");
				for ( int i = 10 ; i < 11 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n");
				output("AFI:\n");
				for ( int i = 11 ; i < 12 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n");
				output("Other fields:\n");
				for ( int i = 12 ; i < 17 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	
	isoBS.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			byte flags,blkAddr,blkNum;
			flags = (byte) Integer.parseInt(isobsFlag.getText(),16);
			blkAddr = (byte) Integer.parseInt(isobsAdd.getText(),16);
			blkNum = (byte) Integer.parseInt(isobsNum.getText(),16);
			String s0 = isobsUID.getText();
			checkdata(s0);
			Pointer uid = null ;
			try {
				uid = new Pointer(MemoryBlockFactory.createMemoryBlock(256));
			} catch (NativeException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			int len = s100.length() / 2;
			for (int  i = 0 ; i < len ; i ++)
			{
				byte value = (byte)Integer.parseInt(s100.substring(2 * i , 2 * i + 2), 16);
				try {
					uid.setByteAt(i, value);
				} catch (NativeException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			int ret = Function.ISO15693_GetMulSecurity(flags,blkAddr,blkNum,uid);
			//System.out.println(ret);
			//for(int i = 0 ; ret != 0 && i < 10 ; i ++)//注：这句是需要的，因为发现这个函数执行貌似是一次成功，一次失败
			 //	ret = Function.ISO15693_Write(flags, blk_add, num_blk, uid, data);
			if(ret == 0)
			{
				output("success\n");
				output("Flags:\n");
				for ( int i = 0 ; i < 1 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n");
				output("The Block Security:\n");
				for ( int i = 1 ; i < blkNum + 1 ; i ++)
				{
					try {
						output(String.format("%02X", Function.a.getAsByte(i))+" ");
					} catch (NativeException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				output("\n\n");
			}
			else
			{
				output("false\n");
				Function.falsereason(Integer.toString(ret));
				output(Function.reason);
				Function.falsereason(String.format("%02X", Function.byte0));
				output(Function.reason+"\n\n");
				Function.reason = "";
			}
		}
	});
	}
	
	
}
