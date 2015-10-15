import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.AbstractListModel;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JTabbedPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.LineBorder;

import com.syc.function.Function;

public class mainWindow {

	private JFrame frame;
	private JTextField sysID;
	private JTextField sysSerNum;
	private JTextField ledCycle;
	private JTextField ledTimes;
	private JTextField bzrCycle;
	private JTextField bzrTimes;
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
	private void initialize() {

		/**
		 * The MainWindow UI.
		 */
		frame = new JFrame();
		frame.setBounds(100, 100, 906, 602);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(new GridLayout(0, 2, 0, 0));

		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		frame.getContentPane().add(tabbedPane);

		JPanel panel = new JPanel();
		tabbedPane.addTab("System Setting", null, panel, null);
		panel.setLayout(null);

		JLabel label_2 = new JLabel("System Commands");
		label_2.setBounds(12, 18, 179, 15);
		panel.add(label_2);

		JLabel label_5 = new JLabel("Set SerNum:");
		label_5.setBounds(12, 49, 95, 15);
		panel.add(label_5);

		sysSerNum = new JTextField();
		sysSerNum.setText("AA BB AA BB AA BB AA BB");
		sysSerNum.setBounds(100, 47, 170, 19);
		panel.add(sysSerNum);
		sysSerNum.setColumns(10);

		JButton btnSetSernum = new JButton("Set SerNum");

		btnSetSernum.setBounds(304, 44, 131, 25);
		panel.add(btnSetSernum);

		JLabel lblReadSernum = new JLabel("Read SerNum:");
		lblReadSernum.setBounds(12, 76, 113, 15);
		panel.add(lblReadSernum);

		JButton btnReadSernum = new JButton("Read SerNum");

		btnReadSernum.setBounds(304, 71, 131, 25);
		panel.add(btnReadSernum);

		JLabel lblLed = new JLabel("Led:");
		lblLed.setBounds(12, 113, 40, 15);
		panel.add(lblLed);

		ledCycle = new JTextField();
		ledCycle.setText("18");
		ledCycle.setBounds(96, 113, 26, 19);
		panel.add(ledCycle);
		ledCycle.setColumns(10);

		JLabel lblNewLabel = new JLabel("Cycle");
		lblNewLabel.setBounds(128, 113, 46, 15);
		panel.add(lblNewLabel);

		ledTimes = new JTextField();
		ledTimes.setText("09");
		ledTimes.setColumns(10);
		ledTimes.setBounds(188, 111, 26, 19);
		panel.add(ledTimes);

		JLabel lblTimes = new JLabel("Times");
		lblTimes.setBounds(224, 113, 46, 15);
		panel.add(lblTimes);

		JButton btnSetLed = new JButton("Set Led");

		btnSetLed.setBounds(304, 108, 131, 25);
		panel.add(btnSetLed);

		JLabel lblBuzzer = new JLabel("Buzzer:");
		lblBuzzer.setBounds(12, 140, 70, 15);
		panel.add(lblBuzzer);

		bzrCycle = new JTextField();
		bzrCycle.setText("18");
		bzrCycle.setColumns(10);
		bzrCycle.setBounds(96,138, 26, 19);
		panel.add(bzrCycle);

		JLabel label_6 = new JLabel("Cycle");
		label_6.setBounds(128, 140, 46, 15);
		panel.add(label_6);

		bzrTimes = new JTextField();
		bzrTimes.setText("09");
		bzrTimes.setColumns(10);
		bzrTimes.setBounds(188, 138, 26, 19);
		panel.add(bzrTimes);

		JLabel label_7 = new JLabel("Times");
		label_7.setBounds(224, 140, 46, 15);
		panel.add(label_7);

		JButton btnSetBuzzer = new JButton("Set Buzzer");

		btnSetBuzzer.setBounds(304, 135, 131, 25);
		panel.add(btnSetBuzzer);

		JLabel lblGetVersionnum = new JLabel("Get VersionNum:");
		lblGetVersionnum.setBounds(12, 167, 131, 15);
		panel.add(lblGetVersionnum);

		JButton btnGetversion = new JButton("GetVersion");

		btnGetversion.setBounds(304, 162, 131, 25);
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

		JLabel lblStartAddress = new JLabel("Start Address");
		lblStartAddress.setBounds(61, 64, 106, 15);
		panel_2.add(lblStartAddress);

		final JComboBox mfreadNum = new JComboBox();
		mfreadNum.setEditable(true);
		mfreadNum.setModel(new DefaultComboBoxModel(new String[] { "01", "02",
				"03", "04" }));
		mfreadNum.setSelectedIndex(0);
		mfreadNum.setBounds(179, 59, 46, 25);
		panel_2.add(mfreadNum);

		JLabel label_8 = new JLabel("Number");
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

		JLabel lblKey = new JLabel("Key");
		lblKey.setBounds(166, 91, 31, 15);
		panel_2.add(lblKey);

		JButton mfRead = new JButton("Read Card");

		mfRead.setBounds(318, 30, 117, 25);
		panel_2.add(mfRead);

		JSeparator separator = new JSeparator();
		separator.setBounds(12, 120, 423, 2);
		panel_2.add(separator);

		JLabel label_9 = new JLabel("Key");
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

		JLabel label_10 = new JLabel("Start Address");
		label_10.setBounds(61, 158, 106, 15);
		panel_2.add(label_10);

		JLabel label_11 = new JLabel("Number");
		label_11.setBounds(228, 158, 62, 15);
		panel_2.add(label_11);

		final JComboBox mfwriteNum = new JComboBox();
		mfwriteNum.setModel(new DefaultComboBoxModel(new String[] { "01", "02",
				"03", "04" }));
		mfwriteNum.setSelectedIndex(0);
		mfwriteNum.setEditable(true);
		mfwriteNum.setBounds(179, 153, 46, 25);
		panel_2.add(mfwriteNum);

		JButton mfWrite = new JButton("Write Card");

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

		JLabel lblDataToWrite = new JLabel("Data to write");
		lblDataToWrite.setBounds(227, 211, 95, 15);
		panel_2.add(lblDataToWrite);

		JLabel label_12 = new JLabel("Key");
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

		JLabel lblValue = new JLabel("Value");
		lblValue.setBounds(255, 270, 51, 15);
		panel_2.add(lblValue);

		initSect = new JTextField();
		initSect.setText("04");
		initSect.setBounds(245, 244, 25, 19);
		panel_2.add(initSect);
		initSect.setColumns(10);

		JLabel label_13 = new JLabel("Sector");
		label_13.setBounds(274, 245, 51, 15);
		panel_2.add(label_13);

		JButton mfInit = new JButton("InitValue");

		mfInit.setBounds(329, 240, 106, 25);
		panel_2.add(mfInit);

		JSeparator separator_3 = new JSeparator();
		separator_3.setBounds(12, 363, 423, 2);
		panel_2.add(separator_3);

		JLabel label_14 = new JLabel("Value");
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

		JLabel label_15 = new JLabel("Key");
		label_15.setBounds(131, 336, 31, 15);
		panel_2.add(label_15);

		deSector = new JTextField();
		deSector.setText("04");
		deSector.setColumns(10);
		deSector.setBounds(245, 310, 25, 19);
		panel_2.add(deSector);

		JLabel label_16 = new JLabel("Sector");
		label_16.setBounds(274, 311, 51, 15);
		panel_2.add(label_16);

		JButton mfDeValue = new JButton("DeValue");

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

		JLabel label_17 = new JLabel("Key");
		label_17.setBounds(131, 401, 31, 15);
		panel_2.add(label_17);

		JLabel label_18 = new JLabel("Value");
		label_18.setBounds(255, 401, 51, 15);
		panel_2.add(label_18);

		JLabel label_19 = new JLabel("Sector");
		label_19.setBounds(274, 376, 51, 15);
		panel_2.add(label_19);

		inSector = new JTextField();
		inSector.setText("04");
		inSector.setColumns(10);
		inSector.setBounds(245, 375, 25, 19);
		panel_2.add(inSector);

		JButton mfInValue = new JButton("InValue");

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

		JButton button_2 = new JButton("GetCardNumber");

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
		panel_16.add(ulsnrIdle);
		ulsnrIdle.setSelected(true);

		JRadioButton radioButton_3 = new JRadioButton("All");
		panel_16.add(radioButton_3);

		JButton ulSnr = new JButton("Series Number");

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

		JLabel lblRead = new JLabel("Read");
		lblRead.setBounds(8, 135, 70, 15);
		panel_15.add(lblRead);

		JLabel lblBlock = new JLabel("Block:");
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
		panel_17.add(ulreadIdle);
		ulreadIdle.setSelected(true);

		JRadioButton radioButton_4 = new JRadioButton("All");
		panel_17.add(radioButton_4);

		JButton ulRead = new JButton("Read");
		ulRead.setBounds(111, 415, 87, 23);
		panel_15.add(ulRead);

		JButton ulWrite = new JButton("Write");

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

		JLabel label_20 = new JLabel("Block:");
		label_20.setBounds(222, 162, 70, 15);
		panel_15.add(label_20);

		JLabel lblWrite = new JLabel("Write");
		lblWrite.setBounds(222, 135, 70, 15);
		panel_15.add(lblWrite);

		JPanel panel_18 = new JPanel();
		panel_18.setBorder(new LineBorder(new Color(0, 0, 0)));
		panel_18.setBounds(223, 415, 99, 23);
		panel_15.add(panel_18);
		panel_18.setLayout(new BoxLayout(panel_18, BoxLayout.X_AXIS));

		final JRadioButton ulwriteIdle = new JRadioButton("Idle");
		panel_18.add(ulwriteIdle);
		ulwriteIdle.setSelected(true);

		JRadioButton radioButton_8 = new JRadioButton("All");
		panel_18.add(radioButton_8);

		ulwriteData = new JTextField();
		ulwriteData.setText("00 00 00 00");
		ulwriteData.setBounds(325, 390, 87, 19);
		panel_15.add(ulwriteData);
		ulwriteData.setColumns(10);

		JPanel panel_19 = new JPanel();
		tabbedPane.addTab("14443B", null, panel_19, null);
		panel_19.setLayout(null);

		JLabel lblbCommands = new JLabel("14443B Commands");
		lblbCommands.setBounds(12, 12, 130, 15);
		panel_19.add(lblbCommands);

		JButton bRequest = new JButton("Request");

		bRequest.setBounds(342, 32, 93, 25);
		panel_19.add(bRequest);

		JSeparator separator_7 = new JSeparator();
		separator_7.setBounds(8, 69, 427, 2);
		panel_19.add(separator_7);

		JLabel lblDataLength = new JLabel("Data length:");
		lblDataLength.setBounds(12, 83, 98, 15);
		panel_19.add(lblDataLength);

		bDataLen = new JTextField();
		bDataLen.setText("08");
		bDataLen.setBounds(108, 81, 34, 19);
		panel_19.add(bDataLen);
		bDataLen.setColumns(10);

		JLabel lblData_1 = new JLabel("Data:");
		lblData_1.setBounds(12, 110, 48, 15);
		panel_19.add(lblData_1);

		bData = new JTextField();
		bData.setText("00 00 05 00 84 00 00 08");
		bData.setBounds(57, 108, 378, 19);
		panel_19.add(bData);
		bData.setColumns(10);

		JButton bTrans = new JButton("TypeB_Transfer");

		bTrans.setBounds(280, 78, 155, 25);
		panel_19.add(bTrans);

		JSeparator separator_8 = new JSeparator();
		separator_8.setBounds(12, 139, 427, 2);
		panel_19.add(separator_8);

		JLabel lblChinaIdenty = new JLabel("China Identify card UID");
		lblChinaIdenty.setBounds(12, 153, 209, 15);
		panel_19.add(lblChinaIdenty);

		JButton bUID = new JButton("SFZ UID");
		bUID.setEnabled(false);
		bUID.setBounds(318, 193, 117, 25);
		panel_19.add(bUID);

		JPanel panel_20 = new JPanel();
		tabbedPane.addTab("15693", null, panel_20, null);
		panel_20.setLayout(null);

		JLabel lblCommands = new JLabel("15693 commands");
		lblCommands.setBounds(12, 12, 119, 15);
		panel_20.add(lblCommands);

		JButton btnInventory = new JButton("Inventory");
		btnInventory.setEnabled(false);
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

		JLabel lblFlag = new JLabel("flag");
		lblFlag.setBounds(46, 67, 34, 15);
		panel_20.add(lblFlag);

		isoreadAdd = new JTextField();
		isoreadAdd.setText("05");
		isoreadAdd.setColumns(10);
		isoreadAdd.setBounds(86, 65, 27, 19);
		panel_20.add(isoreadAdd);

		JLabel lblStartArea = new JLabel("Start area");
		lblStartArea.setBounds(120, 67, 81, 15);
		panel_20.add(lblStartArea);

		isoNum = new JTextField();
		isoNum.setText("01");
		isoNum.setColumns(10);
		isoNum.setBounds(201, 65, 27, 19);
		panel_20.add(isoNum);

		JLabel lblNumber = new JLabel("number");
		lblNumber.setBounds(235, 67, 54, 15);
		panel_20.add(lblNumber);

		JButton isoRead = new JButton("Read Card");

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

		JLabel label_22 = new JLabel("Start area");
		label_22.setBounds(120, 123, 81, 15);
		panel_20.add(label_22);

		isowriteAdd = new JTextField();
		isowriteAdd.setText("05");
		isowriteAdd.setColumns(10);
		isowriteAdd.setBounds(86, 121, 27, 19);
		panel_20.add(isowriteAdd);

		JLabel label_23 = new JLabel("flag");
		label_23.setBounds(46, 123, 34, 15);
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

		JLabel label_24 = new JLabel("number");
		label_24.setBounds(235, 123, 54, 15);
		panel_20.add(label_24);

		JButton btnWriteCard = new JButton("Write Card");

		btnWriteCard.setBounds(316, 118, 119, 25);
		panel_20.add(btnWriteCard);

		isowriteData = new JTextField();
		isowriteData.setText("11 11 11 11");
		isowriteData.setColumns(10);
		isowriteData.setBounds(58, 165, 231, 19);
		panel_20.add(isowriteData);

		JLabel lblData_2 = new JLabel("Data:");
		lblData_2.setBounds(12, 165, 47, 15);
		panel_20.add(lblData_2);

		JLabel lblBlock_1 = new JLabel("Block");
		lblBlock_1.setBounds(100, 199, 37, 15);
		panel_20.add(lblBlock_1);

		isolbBlock = new JTextField();
		isolbBlock.setText("01");
		isolbBlock.setColumns(10);
		isolbBlock.setBounds(73, 197, 27, 19);
		panel_20.add(isolbBlock);

		JLabel label_27 = new JLabel("flag");
		label_27.setBounds(40, 199, 34, 15);
		panel_20.add(label_27);

		isolbFlag = new JTextField();
		isolbFlag.setText("02");
		isolbFlag.setColumns(10);
		isolbFlag.setBounds(12, 197, 27, 19);
		panel_20.add(isolbFlag);

		isoblUID = new JTextField();
		isoblUID.setColumns(10);
		isoblUID.setBounds(145, 197, 125, 19);
		panel_20.add(isoblUID);

		JLabel lblUid_1 = new JLabel("UID");
		lblUid_1.setBounds(270, 199, 27, 15);
		panel_20.add(lblUid_1);

		JButton isoLockBlock = new JButton("Lock Block");

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
		isoscUID.setBounds(86, 236, 125, 19);
		panel_20.add(isoscUID);

		JLabel label_26 = new JLabel("flag");
		label_26.setBounds(40, 240, 34, 15);
		panel_20.add(label_26);

		isoscFlag = new JTextField();
		isoscFlag.setText("02");
		isoscFlag.setColumns(10);
		isoscFlag.setBounds(12, 238, 27, 19);
		panel_20.add(isoscFlag);

		JLabel label_28 = new JLabel("UID");
		label_28.setBounds(211, 238, 27, 15);
		panel_20.add(label_28);

		JButton isoSelCard = new JButton("Select Card");

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
		lblAfi.setBounds(100, 278, 37, 15);
		panel_20.add(lblAfi);

		isowaAFI = new JTextField();
		isowaAFI.setText("02");
		isowaAFI.setColumns(10);
		isowaAFI.setBounds(73, 276, 27, 19);
		panel_20.add(isowaAFI);

		JLabel label_29 = new JLabel("flag");
		label_29.setBounds(40, 278, 34, 15);
		panel_20.add(label_29);

		isowaFlag = new JTextField();
		isowaFlag.setText("02");
		isowaFlag.setColumns(10);
		isowaFlag.setBounds(12, 276, 27, 19);
		panel_20.add(isowaFlag);

		JLabel label_30 = new JLabel("UID");
		label_30.setBounds(270, 278, 27, 15);
		panel_20.add(label_30);

		JButton isoWriteAfi = new JButton("Write AFI");

		isoWriteAfi.setBounds(328, 273, 107, 25);
		panel_20.add(isoWriteAfi);

		JSeparator separator_15 = new JSeparator();
		separator_15.setBounds(8, 343, 427, 2);
		panel_20.add(separator_15);

		isolaUID = new JTextField();
		isolaUID.setColumns(10);
		isolaUID.setBounds(86, 312, 125, 19);
		panel_20.add(isolaUID);

		JLabel label_31 = new JLabel("flag");
		label_31.setBounds(40, 316, 34, 15);
		panel_20.add(label_31);

		isolaFlag = new JTextField();
		isolaFlag.setText("02");
		isolaFlag.setColumns(10);
		isolaFlag.setBounds(12, 314, 27, 19);
		panel_20.add(isolaFlag);

		JLabel label_32 = new JLabel("UID");
		label_32.setBounds(211, 314, 27, 15);
		panel_20.add(label_32);

		JButton isoLockAfi = new JButton("Lock AFI");

		isoLockAfi.setBounds(328, 311, 107, 25);
		panel_20.add(isoLockAfi);

		JSeparator separator_16 = new JSeparator();
		separator_16.setBounds(8, 456, 427, 2);
		panel_20.add(separator_16);

		isosiUID = new JTextField();
		isosiUID.setColumns(10);
		isosiUID.setBounds(86, 425, 125, 19);
		panel_20.add(isosiUID);

		JLabel label_33 = new JLabel("flag");
		label_33.setBounds(40, 429, 34, 15);
		panel_20.add(label_33);

		isosiFlag = new JTextField();
		isosiFlag.setText("02");
		isosiFlag.setColumns(10);
		isosiFlag.setBounds(12, 427, 27, 19);
		panel_20.add(isosiFlag);

		JLabel label_34 = new JLabel("UID");
		label_34.setBounds(211, 427, 27, 15);
		panel_20.add(label_34);

		JButton isoSysInfo = new JButton("System Information");

		isoSysInfo.setBounds(256, 424, 179, 25);
		panel_20.add(isoSysInfo);

		JButton isoBS = new JButton("Block Security");

		isoBS.setBounds(283, 483, 152, 25);
		panel_20.add(isoBS);

		JLabel label_25 = new JLabel("number");
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

		JLabel label_36 = new JLabel("Start area");
		label_36.setBounds(116, 466, 81, 15);
		panel_20.add(label_36);

		isobsAdd = new JTextField();
		isobsAdd.setText("05");
		isobsAdd.setColumns(10);
		isobsAdd.setBounds(82, 464, 27, 19);
		panel_20.add(isobsAdd);

		JLabel label_37 = new JLabel("flag");
		label_37.setBounds(42, 466, 34, 15);
		panel_20.add(label_37);

		isobsFlag = new JTextField();
		isobsFlag.setText("02");
		isobsFlag.setColumns(10);
		isobsFlag.setBounds(8, 464, 27, 19);
		panel_20.add(isobsFlag);

		JSeparator separator_17 = new JSeparator();
		separator_17.setBounds(8, 419, 427, 2);
		panel_20.add(separator_17);

		JButton btnLockDsfid = new JButton("Lock DSFID");

		btnLockDsfid.setBounds(304, 387, 131, 25);
		panel_20.add(btnLockDsfid);

		JLabel label_38 = new JLabel("UID");
		label_38.setBounds(211, 390, 27, 15);
		panel_20.add(label_38);

		isoldUID = new JTextField();
		isoldUID.setColumns(10);
		isoldUID.setBounds(86, 388, 125, 19);
		panel_20.add(isoldUID);

		JLabel label_39 = new JLabel("flag");
		label_39.setBounds(40, 392, 34, 15);
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

		JButton btnWriteDs = new JButton("Write DSFID");

		btnWriteDs.setBounds(304, 349, 131, 25);
		panel_20.add(btnWriteDs);

		JLabel lblDsfid = new JLabel("DSFID");
		lblDsfid.setBounds(100, 354, 47, 15);
		panel_20.add(lblDsfid);

		isowdDSFID = new JTextField();
		isowdDSFID.setText("08");
		isowdDSFID.setColumns(10);
		isowdDSFID.setBounds(73, 352, 27, 19);
		panel_20.add(isowdDSFID);

		JLabel label_42 = new JLabel("flag");
		label_42.setBounds(40, 354, 34, 15);
		panel_20.add(label_42);

		isowdFlag = new JTextField();
		isowdFlag.setText("02");
		isowdFlag.setColumns(10);
		isowdFlag.setBounds(12, 352, 27, 19);
		panel_20.add(isowdFlag);

		JPanel panel_1 = new JPanel();
		frame.getContentPane().add(panel_1);
		panel_1.setLayout(new BorderLayout(0, 0));

		JLabel lblData = new JLabel("Data:");
		panel_1.add(lblData, BorderLayout.NORTH);

		JScrollPane scrollPane = new JScrollPane();
		panel_1.add(scrollPane, BorderLayout.CENTER);

		final JTextArea dataArea = new JTextArea();
		scrollPane.setViewportView(dataArea);

		/**
		 * The Button Action Listener.
		 */
		// System Setting

		btnSetSernum.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte[] buffer = new byte[1];
				buffer[0] = 0;
				byte[] newValue = getByteArray(sysSerNum.getText().toString());
				int result = Function.API_SetSerNum(newValue, buffer);
				String a = String.format("%02x", buffer[0]);
				showStatue(dataArea, result);
				showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		btnReadSernum.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte[] buffer = new byte[9];
				int result = Function.API_GetSerNum(buffer);
				showStatue(dataArea, result);
				showData(dataArea, buffer, "SerNum: \n", 1, 8);
				dataArea.append("\n");
			}
		});

		btnSetLed.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte freq = (byte) Integer.parseInt(ledCycle.getText()
						.toString(), 16);
				byte duration = (byte) Integer.parseInt(ledTimes.getText()
						.toString(), 16);
				byte[] buffer = new byte[1];
				int result = Function.API_ControlLED(freq, duration, buffer);
				showStatue(dataArea, result);
				showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		btnSetBuzzer.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte freq = (byte) Integer.parseInt(bzrCycle.getText()
						.toString(), 16);
				byte duration = (byte) Integer.parseInt(bzrTimes.getText()
						.toString(), 16);
				byte[] buffer = new byte[1];
				int result = Function.API_ControlBuzzer(freq, duration, buffer);
				showStatue(dataArea, result);
				showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		btnGetversion.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte[] VersionNum = new byte[256]; // version number
				int result = Function.GetVersionNum(VersionNum);
				showStatue(dataArea, result);
				if (result == 0)
					showData(dataArea, VersionNum, "Version: ");
				else
					showStatue(dataArea, VersionNum[0]);
				dataArea.append("\n");
			}
		});

		// 14443B-MF
		mfRead.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte mode1 = (byte) (readKeyA.isSelected() ? 0 : 1);
				byte mode2 = (byte) (readIdle.isSelected() ? 0 : 1);
				byte mode = (byte) ((mode1 << 1) | mode2); // reading model
				byte blk_add = (byte) Integer.parseInt(mfreadAdd
						.getSelectedItem().toString(), 16); // block address
				byte num_blk = (byte) Integer.parseInt(mfreadNum
						.getSelectedItem().toString(), 16); // block number
				byte[] snr = getByteArray(mfreadKey.getSelectedItem()
						.toString()); // key
				byte[] buffer = new byte[16 * num_blk]; // data read

				int result = Function.API_PCDRead(mode, blk_add, num_blk, snr,
						buffer);

				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, snr, "The card number:\n", 0, 4);
					showData(dataArea, buffer, "The card data:\n", 0,
							16 * num_blk);
				} else
					showStatue(dataArea, snr[0]);
				dataArea.append("\n");
			}
		});
		mfWrite.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte mode1 = (byte) (writeKeyA.isSelected() ? 0 : 1);
				byte mode2 = (byte) (writeIdle.isSelected() ? 0 : 1);
				byte mode = (byte) ((mode1 << 1) | mode2); // model
				byte blk_add = (byte) Integer.parseInt(mfwriteAdd
						.getSelectedItem().toString(), 16); // block address
				byte num_blk = (byte) Integer.parseInt(mfwriteNum
						.getSelectedItem().toString(), 16); // block number
				byte[] snr = getByteArray(mfwriteKey.getSelectedItem()
						.toString()); // data write
				byte[] buffer = getByteArray(mfwriteData.getText().toString());
				int result = Function.API_PCDWrite(mode, blk_add, num_blk, snr,
						buffer);

				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, snr, "The card number:\n", 0, 4);
				} else
					showStatue(dataArea, snr[0]);
				dataArea.append("\n");
			}
		});

		mfInit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte mode1 = (byte) (initKeyA.isSelected() ? 0 : 1);
				byte mode2 = (byte) (initIdle.isSelected() ? 0 : 1);
				byte mode = (byte) ((mode1 << 1) | mode2); // model
				byte SectNum = (byte) Integer.parseInt(initSect.getText()
						.toString(), 16); // sector
				byte[] snr = getByteArray(initKey.getText().toString()); // data
																			// write
				byte[] value = getByteArray(initValue.getText().toString()); // initialize
																				// value

				int result = Function.API_PCDInitVal(mode, SectNum, snr, value);

				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, snr, "The card number:\n", 0, 4);
				} else
					showStatue(dataArea, snr[0]);
				dataArea.append("\n");
			}
		});

		mfDeValue.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte mode1 = (byte) (deKeyA.isSelected() ? 0 : 1);
				byte mode2 = (byte) (deIdle.isSelected() ? 0 : 1);
				byte mode = (byte) ((mode1 << 1) | mode2); // model
				byte SectNum = (byte) Integer.parseInt(deSector.getText()
						.toString(), 16); // sector
				byte[] snr = getByteArray(deKey.getText().toString()); // data
																		// write
				byte[] value = getByteArray(deValue.getText().toString()); // initialize
																			// value

				int result = Function.API_PCDDec(mode, SectNum, snr, value);

				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, snr, "The card number:\n", 0, 4);
				} else
					showStatue(dataArea, snr[0]);
				dataArea.append("\n");
			}
		});

		mfInValue.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte mode1 = (byte) (inKeyA.isSelected() ? 0 : 1);
				byte mode2 = (byte) (inIdle.isSelected() ? 0 : 1);
				byte mode = (byte) ((mode1 << 1) | mode2); // model
				byte SectNum = (byte) Integer.parseInt(inSector.getText()
						.toString(), 16); // sector
				byte[] snr = getByteArray(inKey.getText().toString()); // data
																		// write
				byte[] value = getByteArray(inValue.getText().toString()); // initialize
																			// value

				int result = Function.API_PCDInc(mode, SectNum, snr, value);

				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, snr, "The card number:\n", 0, 4);
				} else
					showStatue(dataArea, snr[0]);
				dataArea.append("\n");
			}
		});

		button_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte mode;
				if (!snrIdle.isSelected())
					mode = 0x52;
				else
					mode = 0x26;
				byte halt = (byte) (snrHalt.isSelected() ? 1 : 0);
				byte[] snr = new byte[1];
				byte[] value = new byte[5]; // card number
				int result = Function.GET_SNR(mode, halt, snr, value);
				showStatue(dataArea, result);
				if (result == 0) {
					if (snr[0] == 0x00)
						dataArea.append("Only one card.....\n");
					else
						dataArea.append("More than one card......\n");
					showData(dataArea, value, "The card number:\n", 0, 4);
				} else
					showStatue(dataArea, snr[0]);
				dataArea.append("\n");
			}
		});

		// ultralight
		ulSnr.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte[] snr = new byte[7];
				byte mode = (byte) (ulsnrIdle.isSelected() ? 0 : 1);
				int result = Function.UL_Request(mode, snr);
				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, snr, "The card number:\n", 0, 7);
				} else
					showStatue(dataArea, snr[0]);
				dataArea.append("\n");
			}
		});

		ulHalt.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int result = Function.MF_Halt();
				showStatue(dataArea, result);
				dataArea.append("\n");
			}
		});

		ulRead.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte mode = (byte) (ulreadIdle.isSelected() ? 0 : 1);
				byte blk_add = (byte) Integer.parseInt(ulreadBlock
						.getSelectedValue().toString());
				byte[] snr = new byte[7];
				byte[] buffer = new byte[16];
				int result = Function.UL_HLRead(mode, blk_add, snr, buffer);
				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, snr, "The card number:\n", 0, 7);
					showData(dataArea, buffer, "The card data:\n", 0, 16);
				} else
					showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		ulWrite.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte mode = (byte) (ulwriteIdle.isSelected() ? 0 : 1);
				byte blk_add = (byte) Integer.parseInt(ulwriteBlock
						.getSelectedValue().toString());
				byte[] snr = new byte[7];
				byte[] buffer = getByteArray(ulwriteData.getText().toString());
				int result = Function.UL_HLWrite(mode, blk_add, snr, buffer);
				if (result == 0) {
					showStatue(dataArea, result);
					showData(dataArea, snr, "The card number:\n", 0, 7);
				} else if (result == 10) {
					dataArea.append("False\n");
					showStatue(dataArea, result);
				}// something different
				else
					showStatue(dataArea, snr[0]);
				dataArea.append("\n");
			}
		});

		// 14443B
		bRequest.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte[] buffer = new byte[300];
				int result = Function.RequestType_B(buffer);
				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, buffer, "The datalength:\n", 0, 1);
					showData(dataArea, buffer, "The data:\n", 1, buffer[0]);
				} else
					showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		bTrans.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int cmdSize = Integer.parseInt(bDataLen.getText().toString(),
						16);
				byte[] buffer = new byte[256];
				byte[] cmd = getByteArray(bData.getText().toString());
				int result = Function.API_ISO14443TypeBTransCOSCmd(cmd,
						cmdSize, buffer);
				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, buffer, "The Data:\n", 0, 8);
				} else
					showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		// 15693
		isoRead.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte flags = (byte) Integer.parseInt(isoreadFlag.getText()
						.toString(), 16);
				byte blk_add = (byte) Integer.parseInt(isoreadAdd.getText()
						.toString(), 16);
				byte num_blk = (byte) Integer.parseInt(isoNum.getText()
						.toString(), 16);
				byte[] uid = getByteArray(isoUID.getText().toString());
				byte[] buffer = new byte[256];
				int n;
				if (flags == 0x42)
					n = 5;
				else
					n = 4;
				int result = Function.API_ISO15693Read(flags, blk_add, num_blk,
						uid, buffer);
				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, buffer, "Flags:\n", 0, 1);
					showData(dataArea, buffer, "The card data:\n", 1, n
							* num_blk);
				} else
					showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		btnWriteCard.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte flags = (byte) Integer.parseInt(isowriteFlag.getText()
						.toString(), 16);
				byte blk_add = (byte) Integer.parseInt(isowriteAdd.getText()
						.toString(), 16);
				byte num_blk = (byte) Integer.parseInt(isoWriteNum.getText()
						.toString(), 16);
				byte[] uid = getByteArray(isoWriteUID.getText().toString());
				byte[] data = getByteArray(isowriteData.getText().toString());
				int n;
				if (flags == 0x42)
					n = 5;
				else
					n = 4;
				int result = Function.API_ISO15693Write(flags, blk_add,
						num_blk, uid, data);
				showStatue(dataArea, result);
				if (result != 0)
					showStatue(dataArea, data[0]);
				dataArea.append("\n");
			}
		});

		isoLockBlock.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte flags = (byte) Integer.parseInt(isolbFlag.getText()
						.toString(), 16);
				byte blk_add = (byte) Integer.parseInt(isolbBlock.getText()
						.toString(), 16);
				byte[] uid = getByteArray(isoblUID.getText().toString());
				byte[] buffer = new byte[1];
				int result = Function.API_ISO15693Lock(flags, blk_add, uid,
						buffer);
				showStatue(dataArea, result);
				showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		isoSelCard.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte flags = (byte) Integer.parseInt(isoscFlag.getText()
						.toString(), 16);
				byte[] uid = getByteArray(isoscUID.getText().toString());
				byte[] buffer = new byte[1];
				int result = Function.API_ISO15693Select(flags, uid, buffer);
				showStatue(dataArea, result);
				showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		isoWriteAfi.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte flags = (byte) Integer.parseInt(isowaFlag.getText()
						.toString(), 16);
				byte[] uid = getByteArray(isowaUID.getText().toString());
				byte afi = (byte) Integer.parseInt(isowaAFI.getText()
						.toString(), 16);
				byte[] buffer = new byte[1];
				int result = Function.API_WriteAFI(flags, afi, uid, buffer);
				showStatue(dataArea, result);
				showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		isoLockAfi.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte flags = (byte) Integer.parseInt(isolaFlag.getText()
						.toString(), 16);
				byte[] uid = getByteArray(isolaUID.getText().toString());
				byte[] buffer = new byte[1];
				int result = Function.API_LockAFI(flags, uid, buffer);
				showStatue(dataArea, result);
				showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		btnWriteDs.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte flags = (byte) Integer.parseInt(isowdFlag.getText()
						.toString(), 16);
				byte[] uid = getByteArray(isowdUID.getText().toString());
				byte DSFID = (byte) Integer.parseInt(isowdDSFID.getText()
						.toString(), 16);
				byte[] buffer = new byte[1];
				int result = Function.API_WriteDSFID(flags, DSFID, uid, buffer);
				showStatue(dataArea, result);
				showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		btnLockDsfid.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte flags = (byte) Integer.parseInt(isoldFlag.getText()
						.toString(), 16);
				byte[] uid = getByteArray(isoldUID.getText().toString());
				byte[] buffer = new byte[1];
				int result = Function.API_LockDSFID(flags, uid, buffer);
				showStatue(dataArea, result);
				showStatue(dataArea, buffer[0]);
				dataArea.append("\n");
			}
		});

		isoSysInfo.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte flag = (byte) Integer.parseInt(isosiFlag.getText()
						.toString(), 16);
				byte[] uid = getByteArray(isosiUID.getText().toString());
				byte[] Buffer = new byte[255];
				int result = Function
						.API_ISO15693_GetSysInfo(flag, uid, Buffer);
				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, Buffer, "Flags:", 0, 1);
					showData(dataArea, Buffer, "INFO Flags:", 1, 1);
					showData(dataArea, Buffer, "UID:\n", 2, 8);
					showData(dataArea, Buffer, "DSFID:", 10, 1);
					showData(dataArea, Buffer, "AFI:", 11, 1);
					showData(dataArea, Buffer, "Other fields:\n", 12, 5);
				} else
					showStatue(dataArea, Buffer[0]);
				dataArea.append("\n");
			}
		});

		isoBS.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				byte flags = (byte) Integer.parseInt(isobsFlag.getText()
						.toString(), 16);
				byte blkAddr = (byte) Integer.parseInt(isobsAdd.getText()
						.toString(), 16);
				byte blkNum = (byte) Integer.parseInt(isobsNum.getText()
						.toString(), 16);
				byte[] uid = getByteArray(isobsUID.getText().toString());
				byte[] pBuffer = new byte[blkNum + 1];
				int result = Function.API_ISO15693_GetMulSecurity(flags,
						blkAddr, blkNum, uid, pBuffer);
				showStatue(dataArea, result);
				if (result == 0) {
					showData(dataArea, pBuffer, "Flags:", 0, 1);
					showData(dataArea, pBuffer, "The Block Security:", 1,
							blkNum);
				} else
					showStatue(dataArea, pBuffer[0]);
				dataArea.append("\n");
			}
		});
	}
}
