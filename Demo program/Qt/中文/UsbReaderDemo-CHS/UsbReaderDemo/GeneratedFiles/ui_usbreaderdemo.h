/********************************************************************************
** Form generated from reading UI file 'usbreaderdemo.ui'
**
** Created: Sun Oct 7 01:16:53 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USBREADERDEMO_H
#define UI_USBREADERDEMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsbReaderDemoClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *systemTab;
    QGroupBox *commandBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *ledcycleEdit;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *ledtimesEdit;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *setledButton;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *bzrcycleEdit;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *bzrtimesEdit;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *setbuzzerButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *readsernumButton;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *getverButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *sernumEdit;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *setsernumButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_13;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *readIdl;
    QRadioButton *readAll;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *readKeyA;
    QRadioButton *readKeyB;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *mfRead;
    QHBoxLayout *horizontalLayout_15;
    QComboBox *readStart;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_22;
    QComboBox *readNum;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_16;
    QComboBox *readKey;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_14;
    QFrame *line;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_18;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_19;
    QRadioButton *writeIdl;
    QRadioButton *writeAll;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_20;
    QRadioButton *writeKeyA;
    QRadioButton *writeKeyB;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *mfWrite;
    QHBoxLayout *horizontalLayout_21;
    QComboBox *writeStart;
    QLabel *label_17;
    QComboBox *writeNum;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_22;
    QComboBox *writeKey;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_23;
    QLineEdit *writeData;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_36;
    QFrame *line_2;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_28;
    QLineEdit *initKey;
    QLabel *label_23;
    QSpacerItem *horizontalSpacer_25;
    QLineEdit *initValue;
    QLabel *label_24;
    QSpacerItem *horizontalSpacer_26;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout_25;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_26;
    QRadioButton *initIdl;
    QRadioButton *initAll;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_27;
    QRadioButton *initKeyA;
    QRadioButton *initKeyB;
    QLineEdit *initSector;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_23;
    QPushButton *mfInit;
    QFrame *line_3;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_29;
    QHBoxLayout *horizontalLayout_30;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_31;
    QRadioButton *decIdl;
    QRadioButton *decAll;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_32;
    QRadioButton *decKeyA;
    QRadioButton *decKeyB;
    QLineEdit *decSector;
    QLabel *label_26;
    QSpacerItem *horizontalSpacer_27;
    QPushButton *mfDeval;
    QHBoxLayout *horizontalLayout_33;
    QLineEdit *decKey;
    QLabel *label_27;
    QSpacerItem *horizontalSpacer_29;
    QLineEdit *decValue;
    QLabel *label_28;
    QSpacerItem *horizontalSpacer_30;
    QFrame *line_4;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_34;
    QHBoxLayout *horizontalLayout_35;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_36;
    QRadioButton *incIdl;
    QRadioButton *incAll;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_37;
    QRadioButton *incKeyA;
    QRadioButton *incKeyB;
    QLineEdit *incSector;
    QLabel *label_30;
    QSpacerItem *horizontalSpacer_31;
    QPushButton *mfInval;
    QHBoxLayout *horizontalLayout_38;
    QLineEdit *incKey;
    QLabel *label_31;
    QSpacerItem *horizontalSpacer_33;
    QLineEdit *incValue;
    QLabel *label_32;
    QSpacerItem *horizontalSpacer_34;
    QHBoxLayout *horizontalLayout_39;
    QHBoxLayout *horizontalLayout_40;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_41;
    QRadioButton *snrIdl;
    QRadioButton *snrAll;
    QFrame *frame_12;
    QHBoxLayout *horizontalLayout_42;
    QRadioButton *snrNoHalt;
    QRadioButton *snrHalt;
    QSpacerItem *horizontalSpacer_35;
    QPushButton *mfCardNum;
    QSpacerItem *verticalSpacer;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_13;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_43;
    QLabel *label_34;
    QFrame *frame_14;
    QGridLayout *gridLayout_11;
    QRadioButton *utsnIdle;
    QRadioButton *utsnAll;
    QSpacerItem *horizontalSpacer_38;
    QPushButton *utsnRead;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_35;
    QSpacerItem *horizontalSpacer_37;
    QPushButton *utHalt;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_16;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_15;
    QLabel *label_36;
    QListWidget *utreadBlock;
    QSpacerItem *verticalSpacer_3;
    QFrame *frame_15;
    QGridLayout *gridLayout_13;
    QRadioButton *utreadIdle;
    QRadioButton *utreadAll;
    QPushButton *utblockRead;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_14;
    QLabel *label_37;
    QVBoxLayout *verticalLayout;
    QListWidget *utwriteBlock;
    QFrame *frame_16;
    QRadioButton *utwriteIdle;
    QRadioButton *utwriteAll;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *utwriteData;
    QPushButton *utwriteWrite;
    QWidget *tab_3;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_17;
    QHBoxLayout *horizontalLayout_47;
    QLabel *label_40;
    QSpacerItem *horizontalSpacer_41;
    QHBoxLayout *horizontalLayout_46;
    QLabel *label_39;
    QLineEdit *Blength;
    QSpacerItem *horizontalSpacer_40;
    QHBoxLayout *horizontalLayout_45;
    QLabel *label_38;
    QSpacerItem *horizontalSpacer_39;
    QPushButton *BRequest;
    QFrame *line_6;
    QLineEdit *BData;
    QHBoxLayout *horizontalLayout_48;
    QSpacerItem *horizontalSpacer_42;
    QPushButton *BTransfer;
    QSpacerItem *verticalSpacer_6;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_18;
    QSpacerItem *horizontalSpacer_43;
    QPushButton *BUid;
    QSpacerItem *verticalSpacer_5;
    QWidget *tab_4;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_19;
    QHBoxLayout *horizontalLayout_60;
    QLineEdit *afilockFlag;
    QLabel *label_86;
    QLineEdit *afilockUID;
    QLabel *label_67;
    QSpacerItem *horizontalSpacer_55;
    QPushButton *afiLock;
    QHBoxLayout *horizontalLayout_59;
    QLineEdit *afiwriteFlag;
    QLabel *label_66;
    QLineEdit *writeAFI;
    QLabel *label_63;
    QLineEdit *afiwriteUID;
    QLabel *label_64;
    QSpacerItem *horizontalSpacer_54;
    QPushButton *afiWrite;
    QHBoxLayout *horizontalLayout_49;
    QLabel *label_41;
    QSpacerItem *horizontalSpacer_44;
    QPushButton *isoInventory;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_50;
    QLineEdit *isoreadFlag;
    QLabel *label_43;
    QLineEdit *isoreadStart;
    QLabel *label_44;
    QLineEdit *isoreadNum;
    QLabel *label_45;
    QSpacerItem *horizontalSpacer_45;
    QPushButton *isoRead;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_55;
    QLineEdit *isoreadUID;
    QLabel *label_54;
    QSpacerItem *horizontalSpacer_48;
    QHBoxLayout *horizontalLayout_56;
    QLineEdit *isowriteUID;
    QLabel *label_55;
    QSpacerItem *horizontalSpacer_51;
    QHBoxLayout *horizontalLayout_58;
    QLineEdit *cardselFlag;
    QLabel *label_61;
    QLineEdit *cardselUID;
    QLabel *label_58;
    QSpacerItem *horizontalSpacer_53;
    QPushButton *cardSelect;
    QHBoxLayout *horizontalLayout_65;
    QLineEdit *dsfidlockFlag;
    QLabel *label_88;
    QLineEdit *lockdsfidUID;
    QLabel *label_82;
    QSpacerItem *horizontalSpacer_60;
    QPushButton *dsfidLock;
    QHBoxLayout *horizontalLayout_66;
    QLineEdit *dsfidwriteFlag;
    QLabel *label_87;
    QLineEdit *writeDSFID;
    QLabel *label_84;
    QLineEdit *dsfidwriteUID;
    QLabel *label_85;
    QSpacerItem *horizontalSpacer_61;
    QPushButton *dsfidWrite;
    QHBoxLayout *horizontalLayout_82;
    QLineEdit *blksecFlag;
    QLabel *label_125;
    QLineEdit *blksecStart;
    QLabel *label_126;
    QLineEdit *blksecNum;
    QLabel *label_127;
    QSpacerItem *horizontalSpacer_80;
    QPushButton *blksecGet;
    QHBoxLayout *horizontalLayout_51;
    QLineEdit *isowriteFlag;
    QLabel *label_47;
    QLineEdit *isowriteStart;
    QLabel *label_48;
    QLineEdit *isowriteNum;
    QLabel *label_49;
    QSpacerItem *horizontalSpacer_46;
    QPushButton *isoWrite;
    QHBoxLayout *horizontalLayout_52;
    QLabel *label_50;
    QLineEdit *isowriteData;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout_53;
    QLineEdit *isogetFlag;
    QLabel *label_52;
    QLineEdit *isogetUID;
    QLabel *label_53;
    QSpacerItem *horizontalSpacer_47;
    QPushButton *isoGet;
    QFrame *line_10;
    QHBoxLayout *horizontalLayout_57;
    QLineEdit *blklockFlag;
    QLabel *label_57;
    QLineEdit *lockBlock;
    QLabel *label_59;
    QLineEdit *blklockUID;
    QLabel *label_68;
    QSpacerItem *horizontalSpacer_52;
    QPushButton *blockLock;
    QFrame *line_12;
    QFrame *line_14;
    QFrame *line_11;
    QFrame *line_13;
    QFrame *line_15;
    QHBoxLayout *horizontalLayout_81;
    QSpacerItem *horizontalSpacer_78;
    QLineEdit *blksecUID;
    QLabel *label_123;
    QSpacerItem *horizontalSpacer_79;
    QFrame *line_25;
    QGroupBox *dataBox;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *dataEdit;

    void setupUi(QMainWindow *UsbReaderDemoClass)
    {
        if (UsbReaderDemoClass->objectName().isEmpty())
            UsbReaderDemoClass->setObjectName(QString::fromUtf8("UsbReaderDemoClass"));
        UsbReaderDemoClass->resize(1036, 635);
        centralWidget = new QWidget(UsbReaderDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        systemTab = new QWidget();
        systemTab->setObjectName(QString::fromUtf8("systemTab"));
        commandBox = new QGroupBox(systemTab);
        commandBox->setObjectName(QString::fromUtf8("commandBox"));
        commandBox->setGeometry(QRect(9, 9, 431, 181));
        gridLayout_3 = new QGridLayout(commandBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(commandBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        ledcycleEdit = new QLineEdit(commandBox);
        ledcycleEdit->setObjectName(QString::fromUtf8("ledcycleEdit"));
        ledcycleEdit->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_5->addWidget(ledcycleEdit);

        label_4 = new QLabel(commandBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);


        horizontalLayout_7->addLayout(horizontalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ledtimesEdit = new QLineEdit(commandBox);
        ledtimesEdit->setObjectName(QString::fromUtf8("ledtimesEdit"));
        ledtimesEdit->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_6->addWidget(ledtimesEdit);

        label_5 = new QLabel(commandBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        setledButton = new QPushButton(commandBox);
        setledButton->setObjectName(QString::fromUtf8("setledButton"));

        horizontalLayout_7->addWidget(setledButton);


        gridLayout_3->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(commandBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        bzrcycleEdit = new QLineEdit(commandBox);
        bzrcycleEdit->setObjectName(QString::fromUtf8("bzrcycleEdit"));
        bzrcycleEdit->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_9->addWidget(bzrcycleEdit);

        label_7 = new QLabel(commandBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);


        horizontalLayout_8->addLayout(horizontalLayout_9);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        bzrtimesEdit = new QLineEdit(commandBox);
        bzrtimesEdit->setObjectName(QString::fromUtf8("bzrtimesEdit"));
        bzrtimesEdit->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_10->addWidget(bzrtimesEdit);

        label_8 = new QLabel(commandBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_10->addWidget(label_8);


        horizontalLayout_8->addLayout(horizontalLayout_10);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        setbuzzerButton = new QPushButton(commandBox);
        setbuzzerButton->setObjectName(QString::fromUtf8("setbuzzerButton"));

        horizontalLayout_8->addWidget(setbuzzerButton);


        gridLayout_3->addLayout(horizontalLayout_8, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(commandBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        readsernumButton = new QPushButton(commandBox);
        readsernumButton->setObjectName(QString::fromUtf8("readsernumButton"));

        horizontalLayout_4->addWidget(readsernumButton);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_9 = new QLabel(commandBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_11->addWidget(label_9);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);

        getverButton = new QPushButton(commandBox);
        getverButton->setObjectName(QString::fromUtf8("getverButton"));

        horizontalLayout_11->addWidget(getverButton);


        gridLayout_3->addLayout(horizontalLayout_11, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(commandBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        sernumEdit = new QLineEdit(commandBox);
        sernumEdit->setObjectName(QString::fromUtf8("sernumEdit"));
        sernumEdit->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(sernumEdit);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        setsernumButton = new QPushButton(commandBox);
        setsernumButton->setObjectName(QString::fromUtf8("setsernumButton"));

        horizontalLayout_3->addWidget(setsernumButton);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 5, 0, 1, 1);

        tabWidget->addTab(systemTab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_10 = new QGridLayout(groupBox);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(100, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        readIdl = new QRadioButton(frame);
        readIdl->setObjectName(QString::fromUtf8("readIdl"));
        readIdl->setChecked(true);

        horizontalLayout_2->addWidget(readIdl);

        readAll = new QRadioButton(frame);
        readAll->setObjectName(QString::fromUtf8("readAll"));

        horizontalLayout_2->addWidget(readAll);


        horizontalLayout_13->addWidget(frame);

        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(120, 16777215));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_2);
        horizontalLayout_12->setSpacing(5);
        horizontalLayout_12->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        readKeyA = new QRadioButton(frame_2);
        readKeyA->setObjectName(QString::fromUtf8("readKeyA"));
        readKeyA->setChecked(true);

        horizontalLayout_12->addWidget(readKeyA);

        readKeyB = new QRadioButton(frame_2);
        readKeyB->setObjectName(QString::fromUtf8("readKeyB"));

        horizontalLayout_12->addWidget(readKeyB);


        horizontalLayout_13->addWidget(frame_2);


        horizontalLayout_14->addLayout(horizontalLayout_13);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_11);

        mfRead = new QPushButton(groupBox);
        mfRead->setObjectName(QString::fromUtf8("mfRead"));

        horizontalLayout_14->addWidget(mfRead);


        gridLayout_5->addLayout(horizontalLayout_14, 0, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        readStart = new QComboBox(groupBox);
        readStart->setObjectName(QString::fromUtf8("readStart"));
        readStart->setEditable(true);

        horizontalLayout_15->addWidget(readStart);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_15->addWidget(label_12);

        horizontalSpacer_22 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_22);

        readNum = new QComboBox(groupBox);
        readNum->setObjectName(QString::fromUtf8("readNum"));
        readNum->setEditable(true);

        horizontalLayout_15->addWidget(readNum);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_15->addWidget(label_13);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_17);


        gridLayout_5->addLayout(horizontalLayout_15, 1, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        readKey = new QComboBox(groupBox);
        readKey->setObjectName(QString::fromUtf8("readKey"));
        readKey->setEditable(true);

        horizontalLayout_16->addWidget(readKey);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_16->addWidget(label_14);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_14);


        gridLayout_5->addLayout(horizontalLayout_16, 2, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_5, 0, 0, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_10->addWidget(line, 1, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        frame_3 = new QFrame(groupBox);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMaximumSize(QSize(100, 16777215));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_19 = new QHBoxLayout(frame_3);
        horizontalLayout_19->setSpacing(5);
        horizontalLayout_19->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setSizeConstraint(QLayout::SetMinimumSize);
        writeIdl = new QRadioButton(frame_3);
        writeIdl->setObjectName(QString::fromUtf8("writeIdl"));
        writeIdl->setChecked(true);

        horizontalLayout_19->addWidget(writeIdl);

        writeAll = new QRadioButton(frame_3);
        writeAll->setObjectName(QString::fromUtf8("writeAll"));

        horizontalLayout_19->addWidget(writeAll);


        horizontalLayout_18->addWidget(frame_3);

        frame_4 = new QFrame(groupBox);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMaximumSize(QSize(120, 16777215));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_20 = new QHBoxLayout(frame_4);
        horizontalLayout_20->setSpacing(5);
        horizontalLayout_20->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        writeKeyA = new QRadioButton(frame_4);
        writeKeyA->setObjectName(QString::fromUtf8("writeKeyA"));
        writeKeyA->setChecked(true);

        horizontalLayout_20->addWidget(writeKeyA);

        writeKeyB = new QRadioButton(frame_4);
        writeKeyB->setObjectName(QString::fromUtf8("writeKeyB"));

        horizontalLayout_20->addWidget(writeKeyB);


        horizontalLayout_18->addWidget(frame_4);


        horizontalLayout_17->addLayout(horizontalLayout_18);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_15);

        mfWrite = new QPushButton(groupBox);
        mfWrite->setObjectName(QString::fromUtf8("mfWrite"));

        horizontalLayout_17->addWidget(mfWrite);


        gridLayout_6->addLayout(horizontalLayout_17, 0, 0, 1, 1);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        writeStart = new QComboBox(groupBox);
        writeStart->setObjectName(QString::fromUtf8("writeStart"));
        writeStart->setEditable(true);

        horizontalLayout_21->addWidget(writeStart);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_21->addWidget(label_17);

        writeNum = new QComboBox(groupBox);
        writeNum->setObjectName(QString::fromUtf8("writeNum"));
        writeNum->setEditable(true);

        horizontalLayout_21->addWidget(writeNum);

        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_21->addWidget(label_18);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_18);


        gridLayout_6->addLayout(horizontalLayout_21, 1, 0, 1, 1);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        writeKey = new QComboBox(groupBox);
        writeKey->setObjectName(QString::fromUtf8("writeKey"));
        writeKey->setEditable(true);

        horizontalLayout_22->addWidget(writeKey);

        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_22->addWidget(label_19);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_20);


        gridLayout_6->addLayout(horizontalLayout_22, 2, 0, 1, 1);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        writeData = new QLineEdit(groupBox);
        writeData->setObjectName(QString::fromUtf8("writeData"));
        writeData->setMinimumSize(QSize(300, 0));

        horizontalLayout_23->addWidget(writeData);

        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_23->addWidget(label_20);

        horizontalSpacer_36 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_36);


        gridLayout_6->addLayout(horizontalLayout_23, 3, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_6, 2, 0, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_10->addWidget(line_2, 3, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        initKey = new QLineEdit(groupBox);
        initKey->setObjectName(QString::fromUtf8("initKey"));

        horizontalLayout_28->addWidget(initKey);

        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_28->addWidget(label_23);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_25);

        initValue = new QLineEdit(groupBox);
        initValue->setObjectName(QString::fromUtf8("initValue"));

        horizontalLayout_28->addWidget(initValue);

        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_28->addWidget(label_24);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_26);


        gridLayout_7->addLayout(horizontalLayout_28, 1, 0, 1, 1);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(0);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        frame_5 = new QFrame(groupBox);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMaximumSize(QSize(100, 16777215));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_26 = new QHBoxLayout(frame_5);
        horizontalLayout_26->setSpacing(5);
        horizontalLayout_26->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalLayout_26->setSizeConstraint(QLayout::SetMinimumSize);
        initIdl = new QRadioButton(frame_5);
        initIdl->setObjectName(QString::fromUtf8("initIdl"));
        initIdl->setChecked(true);

        horizontalLayout_26->addWidget(initIdl);

        initAll = new QRadioButton(frame_5);
        initAll->setObjectName(QString::fromUtf8("initAll"));

        horizontalLayout_26->addWidget(initAll);


        horizontalLayout_25->addWidget(frame_5);

        frame_6 = new QFrame(groupBox);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMaximumSize(QSize(120, 16777215));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_27 = new QHBoxLayout(frame_6);
        horizontalLayout_27->setSpacing(5);
        horizontalLayout_27->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        initKeyA = new QRadioButton(frame_6);
        initKeyA->setObjectName(QString::fromUtf8("initKeyA"));
        initKeyA->setChecked(true);

        horizontalLayout_27->addWidget(initKeyA);

        initKeyB = new QRadioButton(frame_6);
        initKeyB->setObjectName(QString::fromUtf8("initKeyB"));

        horizontalLayout_27->addWidget(initKeyB);


        horizontalLayout_25->addWidget(frame_6);


        horizontalLayout_24->addLayout(horizontalLayout_25);

        initSector = new QLineEdit(groupBox);
        initSector->setObjectName(QString::fromUtf8("initSector"));
        initSector->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_24->addWidget(initSector);

        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_24->addWidget(label_22);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_23);

        mfInit = new QPushButton(groupBox);
        mfInit->setObjectName(QString::fromUtf8("mfInit"));

        horizontalLayout_24->addWidget(mfInit);


        gridLayout_7->addLayout(horizontalLayout_24, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_7, 4, 0, 1, 1);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_10->addWidget(line_3, 5, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(0);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        frame_7 = new QFrame(groupBox);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setMaximumSize(QSize(100, 16777215));
        frame_7->setFrameShape(QFrame::Box);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_31 = new QHBoxLayout(frame_7);
        horizontalLayout_31->setSpacing(5);
        horizontalLayout_31->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalLayout_31->setSizeConstraint(QLayout::SetMinimumSize);
        decIdl = new QRadioButton(frame_7);
        decIdl->setObjectName(QString::fromUtf8("decIdl"));
        decIdl->setChecked(true);

        horizontalLayout_31->addWidget(decIdl);

        decAll = new QRadioButton(frame_7);
        decAll->setObjectName(QString::fromUtf8("decAll"));

        horizontalLayout_31->addWidget(decAll);


        horizontalLayout_30->addWidget(frame_7);

        frame_8 = new QFrame(groupBox);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setMaximumSize(QSize(120, 16777215));
        frame_8->setFrameShape(QFrame::Box);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_32 = new QHBoxLayout(frame_8);
        horizontalLayout_32->setSpacing(5);
        horizontalLayout_32->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        decKeyA = new QRadioButton(frame_8);
        decKeyA->setObjectName(QString::fromUtf8("decKeyA"));
        decKeyA->setChecked(true);

        horizontalLayout_32->addWidget(decKeyA);

        decKeyB = new QRadioButton(frame_8);
        decKeyB->setObjectName(QString::fromUtf8("decKeyB"));

        horizontalLayout_32->addWidget(decKeyB);


        horizontalLayout_30->addWidget(frame_8);


        horizontalLayout_29->addLayout(horizontalLayout_30);

        decSector = new QLineEdit(groupBox);
        decSector->setObjectName(QString::fromUtf8("decSector"));
        decSector->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_29->addWidget(decSector);

        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_29->addWidget(label_26);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_27);

        mfDeval = new QPushButton(groupBox);
        mfDeval->setObjectName(QString::fromUtf8("mfDeval"));

        horizontalLayout_29->addWidget(mfDeval);


        gridLayout_8->addLayout(horizontalLayout_29, 0, 0, 1, 1);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        decKey = new QLineEdit(groupBox);
        decKey->setObjectName(QString::fromUtf8("decKey"));

        horizontalLayout_33->addWidget(decKey);

        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_33->addWidget(label_27);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_29);

        decValue = new QLineEdit(groupBox);
        decValue->setObjectName(QString::fromUtf8("decValue"));

        horizontalLayout_33->addWidget(decValue);

        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_33->addWidget(label_28);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_30);


        gridLayout_8->addLayout(horizontalLayout_33, 1, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_8, 6, 0, 1, 1);

        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_10->addWidget(line_4, 7, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(0);
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        frame_9 = new QFrame(groupBox);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setMaximumSize(QSize(100, 16777215));
        frame_9->setFrameShape(QFrame::Box);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_36 = new QHBoxLayout(frame_9);
        horizontalLayout_36->setSpacing(5);
        horizontalLayout_36->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        horizontalLayout_36->setSizeConstraint(QLayout::SetMinimumSize);
        incIdl = new QRadioButton(frame_9);
        incIdl->setObjectName(QString::fromUtf8("incIdl"));
        incIdl->setChecked(true);

        horizontalLayout_36->addWidget(incIdl);

        incAll = new QRadioButton(frame_9);
        incAll->setObjectName(QString::fromUtf8("incAll"));

        horizontalLayout_36->addWidget(incAll);


        horizontalLayout_35->addWidget(frame_9);

        frame_10 = new QFrame(groupBox);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setMaximumSize(QSize(120, 16777215));
        frame_10->setFrameShape(QFrame::Box);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_37 = new QHBoxLayout(frame_10);
        horizontalLayout_37->setSpacing(5);
        horizontalLayout_37->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        incKeyA = new QRadioButton(frame_10);
        incKeyA->setObjectName(QString::fromUtf8("incKeyA"));
        incKeyA->setChecked(true);

        horizontalLayout_37->addWidget(incKeyA);

        incKeyB = new QRadioButton(frame_10);
        incKeyB->setObjectName(QString::fromUtf8("incKeyB"));

        horizontalLayout_37->addWidget(incKeyB);


        horizontalLayout_35->addWidget(frame_10);


        horizontalLayout_34->addLayout(horizontalLayout_35);

        incSector = new QLineEdit(groupBox);
        incSector->setObjectName(QString::fromUtf8("incSector"));
        incSector->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_34->addWidget(incSector);

        label_30 = new QLabel(groupBox);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_34->addWidget(label_30);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_31);

        mfInval = new QPushButton(groupBox);
        mfInval->setObjectName(QString::fromUtf8("mfInval"));

        horizontalLayout_34->addWidget(mfInval);


        gridLayout_9->addLayout(horizontalLayout_34, 0, 0, 1, 1);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        incKey = new QLineEdit(groupBox);
        incKey->setObjectName(QString::fromUtf8("incKey"));

        horizontalLayout_38->addWidget(incKey);

        label_31 = new QLabel(groupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_38->addWidget(label_31);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_33);

        incValue = new QLineEdit(groupBox);
        incValue->setObjectName(QString::fromUtf8("incValue"));

        horizontalLayout_38->addWidget(incValue);

        label_32 = new QLabel(groupBox);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_38->addWidget(label_32);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_34);


        gridLayout_9->addLayout(horizontalLayout_38, 1, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 8, 0, 1, 1);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setSpacing(6);
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setSpacing(0);
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        frame_11 = new QFrame(groupBox);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setMaximumSize(QSize(100, 16777215));
        frame_11->setFrameShape(QFrame::Box);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_41 = new QHBoxLayout(frame_11);
        horizontalLayout_41->setSpacing(5);
        horizontalLayout_41->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        horizontalLayout_41->setSizeConstraint(QLayout::SetMinimumSize);
        snrIdl = new QRadioButton(frame_11);
        snrIdl->setObjectName(QString::fromUtf8("snrIdl"));
        snrIdl->setChecked(true);

        horizontalLayout_41->addWidget(snrIdl);

        snrAll = new QRadioButton(frame_11);
        snrAll->setObjectName(QString::fromUtf8("snrAll"));

        horizontalLayout_41->addWidget(snrAll);


        horizontalLayout_40->addWidget(frame_11);

        frame_12 = new QFrame(groupBox);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setMaximumSize(QSize(120, 16777215));
        frame_12->setFrameShape(QFrame::Box);
        frame_12->setFrameShadow(QFrame::Raised);
        horizontalLayout_42 = new QHBoxLayout(frame_12);
        horizontalLayout_42->setSpacing(20);
        horizontalLayout_42->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        snrNoHalt = new QRadioButton(frame_12);
        snrNoHalt->setObjectName(QString::fromUtf8("snrNoHalt"));
        snrNoHalt->setMinimumSize(QSize(100, 0));
        snrNoHalt->setChecked(true);

        horizontalLayout_42->addWidget(snrNoHalt);

        snrHalt = new QRadioButton(frame_12);
        snrHalt->setObjectName(QString::fromUtf8("snrHalt"));

        horizontalLayout_42->addWidget(snrHalt);


        horizontalLayout_40->addWidget(frame_12);


        horizontalLayout_39->addLayout(horizontalLayout_40);

        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_39->addItem(horizontalSpacer_35);

        mfCardNum = new QPushButton(groupBox);
        mfCardNum->setObjectName(QString::fromUtf8("mfCardNum"));

        horizontalLayout_39->addWidget(mfCardNum);


        gridLayout_10->addLayout(horizontalLayout_39, 9, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 114, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 471, 521));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_13 = new QFrame(layoutWidget);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setFrameShape(QFrame::Box);
        frame_13->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_13);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        label_34 = new QLabel(frame_13);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_43->addWidget(label_34);

        frame_14 = new QFrame(frame_13);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setFrameShape(QFrame::Box);
        frame_14->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_14);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        utsnIdle = new QRadioButton(frame_14);
        utsnIdle->setObjectName(QString::fromUtf8("utsnIdle"));
        utsnIdle->setChecked(true);

        gridLayout_11->addWidget(utsnIdle, 0, 0, 1, 1);

        utsnAll = new QRadioButton(frame_14);
        utsnAll->setObjectName(QString::fromUtf8("utsnAll"));

        gridLayout_11->addWidget(utsnAll, 0, 1, 1, 1);


        horizontalLayout_43->addWidget(frame_14);

        horizontalSpacer_38 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_43->addItem(horizontalSpacer_38);

        utsnRead = new QPushButton(frame_13);
        utsnRead->setObjectName(QString::fromUtf8("utsnRead"));

        horizontalLayout_43->addWidget(utsnRead);


        gridLayout_12->addLayout(horizontalLayout_43, 0, 0, 1, 1);

        line_5 = new QFrame(frame_13);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_12->addWidget(line_5, 1, 0, 1, 1);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(6);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        label_35 = new QLabel(frame_13);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_44->addWidget(label_35);

        horizontalSpacer_37 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_37);

        utHalt = new QPushButton(frame_13);
        utHalt->setObjectName(QString::fromUtf8("utHalt"));

        horizontalLayout_44->addWidget(utHalt);


        gridLayout_12->addLayout(horizontalLayout_44, 2, 0, 1, 1);


        verticalLayout_3->addWidget(frame_13);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_16 = new QGridLayout(groupBox_2);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_15 = new QGridLayout(groupBox_3);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_36 = new QLabel(groupBox_3);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_15->addWidget(label_36, 0, 0, 1, 1);

        utreadBlock = new QListWidget(groupBox_3);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        new QListWidgetItem(utreadBlock);
        utreadBlock->setObjectName(QString::fromUtf8("utreadBlock"));

        gridLayout_15->addWidget(utreadBlock, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 288, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_15->addItem(verticalSpacer_3, 1, 1, 1, 1);

        frame_15 = new QFrame(groupBox_3);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setFrameShape(QFrame::Box);
        frame_15->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frame_15);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        utreadIdle = new QRadioButton(frame_15);
        utreadIdle->setObjectName(QString::fromUtf8("utreadIdle"));
        utreadIdle->setChecked(true);

        gridLayout_13->addWidget(utreadIdle, 0, 0, 1, 1);

        utreadAll = new QRadioButton(frame_15);
        utreadAll->setObjectName(QString::fromUtf8("utreadAll"));

        gridLayout_13->addWidget(utreadAll, 0, 1, 1, 1);


        gridLayout_15->addWidget(frame_15, 2, 0, 1, 1);

        utblockRead = new QPushButton(groupBox_3);
        utblockRead->setObjectName(QString::fromUtf8("utblockRead"));

        gridLayout_15->addWidget(utblockRead, 2, 1, 1, 1);


        gridLayout_16->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_14 = new QGridLayout(groupBox_4);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        label_37 = new QLabel(groupBox_4);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_14->addWidget(label_37, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        utwriteBlock = new QListWidget(groupBox_4);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        new QListWidgetItem(utwriteBlock);
        utwriteBlock->setObjectName(QString::fromUtf8("utwriteBlock"));

        verticalLayout->addWidget(utwriteBlock);

        frame_16 = new QFrame(groupBox_4);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setMinimumSize(QSize(0, 32));
        frame_16->setFrameShape(QFrame::Box);
        frame_16->setFrameShadow(QFrame::Raised);
        utwriteIdle = new QRadioButton(frame_16);
        utwriteIdle->setObjectName(QString::fromUtf8("utwriteIdle"));
        utwriteIdle->setGeometry(QRect(10, 10, 47, 16));
        utwriteIdle->setChecked(true);
        utwriteAll = new QRadioButton(frame_16);
        utwriteAll->setObjectName(QString::fromUtf8("utwriteAll"));
        utwriteAll->setGeometry(QRect(63, 10, 41, 16));

        verticalLayout->addWidget(frame_16);


        gridLayout_14->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        utwriteData = new QLineEdit(groupBox_4);
        utwriteData->setObjectName(QString::fromUtf8("utwriteData"));

        verticalLayout_2->addWidget(utwriteData);

        utwriteWrite = new QPushButton(groupBox_4);
        utwriteWrite->setObjectName(QString::fromUtf8("utwriteWrite"));

        verticalLayout_2->addWidget(utwriteWrite);


        gridLayout_14->addLayout(verticalLayout_2, 1, 1, 1, 1);


        gridLayout_16->addWidget(groupBox_4, 0, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 20, 421, 221));
        gridLayout_17 = new QGridLayout(groupBox_5);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setSpacing(6);
        horizontalLayout_47->setObjectName(QString::fromUtf8("horizontalLayout_47"));
        label_40 = new QLabel(groupBox_5);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_47->addWidget(label_40);

        horizontalSpacer_41 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_47->addItem(horizontalSpacer_41);


        gridLayout_17->addLayout(horizontalLayout_47, 5, 0, 1, 1);

        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setSpacing(6);
        horizontalLayout_46->setObjectName(QString::fromUtf8("horizontalLayout_46"));
        label_39 = new QLabel(groupBox_5);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        horizontalLayout_46->addWidget(label_39);

        Blength = new QLineEdit(groupBox_5);
        Blength->setObjectName(QString::fromUtf8("Blength"));
        Blength->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_46->addWidget(Blength);

        horizontalSpacer_40 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_46->addItem(horizontalSpacer_40);


        gridLayout_17->addLayout(horizontalLayout_46, 3, 0, 1, 2);

        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setSpacing(6);
        horizontalLayout_45->setObjectName(QString::fromUtf8("horizontalLayout_45"));
        label_38 = new QLabel(groupBox_5);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_45->addWidget(label_38);

        horizontalSpacer_39 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_45->addItem(horizontalSpacer_39);

        BRequest = new QPushButton(groupBox_5);
        BRequest->setObjectName(QString::fromUtf8("BRequest"));

        horizontalLayout_45->addWidget(BRequest);


        gridLayout_17->addLayout(horizontalLayout_45, 0, 0, 1, 2);

        line_6 = new QFrame(groupBox_5);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_6, 2, 0, 1, 1);

        BData = new QLineEdit(groupBox_5);
        BData->setObjectName(QString::fromUtf8("BData"));

        gridLayout_17->addWidget(BData, 6, 0, 1, 1);

        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setSpacing(6);
        horizontalLayout_48->setObjectName(QString::fromUtf8("horizontalLayout_48"));
        horizontalSpacer_42 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_48->addItem(horizontalSpacer_42);

        BTransfer = new QPushButton(groupBox_5);
        BTransfer->setObjectName(QString::fromUtf8("BTransfer"));

        horizontalLayout_48->addWidget(BTransfer);


        gridLayout_17->addLayout(horizontalLayout_48, 7, 0, 1, 2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_17->addItem(verticalSpacer_6, 1, 0, 1, 1);

        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(23, 253, 421, 171));
        gridLayout_18 = new QGridLayout(groupBox_6);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        horizontalSpacer_43 = new QSpacerItem(317, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_43, 0, 0, 1, 1);

        BUid = new QPushButton(groupBox_6);
        BUid->setObjectName(QString::fromUtf8("BUid"));

        gridLayout_18->addWidget(BUid, 0, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 107, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_18->addItem(verticalSpacer_5, 1, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        groupBox_7 = new QGroupBox(tab_4);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 20, 561, 571));
        gridLayout_19 = new QGridLayout(groupBox_7);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        horizontalLayout_60 = new QHBoxLayout();
        horizontalLayout_60->setSpacing(6);
        horizontalLayout_60->setObjectName(QString::fromUtf8("horizontalLayout_60"));
        afilockFlag = new QLineEdit(groupBox_7);
        afilockFlag->setObjectName(QString::fromUtf8("afilockFlag"));
        afilockFlag->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_60->addWidget(afilockFlag);

        label_86 = new QLabel(groupBox_7);
        label_86->setObjectName(QString::fromUtf8("label_86"));

        horizontalLayout_60->addWidget(label_86);

        afilockUID = new QLineEdit(groupBox_7);
        afilockUID->setObjectName(QString::fromUtf8("afilockUID"));

        horizontalLayout_60->addWidget(afilockUID);

        label_67 = new QLabel(groupBox_7);
        label_67->setObjectName(QString::fromUtf8("label_67"));

        horizontalLayout_60->addWidget(label_67);

        horizontalSpacer_55 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_60->addItem(horizontalSpacer_55);

        afiLock = new QPushButton(groupBox_7);
        afiLock->setObjectName(QString::fromUtf8("afiLock"));

        horizontalLayout_60->addWidget(afiLock);


        gridLayout_19->addLayout(horizontalLayout_60, 17, 0, 1, 1);

        horizontalLayout_59 = new QHBoxLayout();
        horizontalLayout_59->setSpacing(6);
        horizontalLayout_59->setObjectName(QString::fromUtf8("horizontalLayout_59"));
        afiwriteFlag = new QLineEdit(groupBox_7);
        afiwriteFlag->setObjectName(QString::fromUtf8("afiwriteFlag"));
        afiwriteFlag->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_59->addWidget(afiwriteFlag);

        label_66 = new QLabel(groupBox_7);
        label_66->setObjectName(QString::fromUtf8("label_66"));

        horizontalLayout_59->addWidget(label_66);

        writeAFI = new QLineEdit(groupBox_7);
        writeAFI->setObjectName(QString::fromUtf8("writeAFI"));
        writeAFI->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_59->addWidget(writeAFI);

        label_63 = new QLabel(groupBox_7);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        horizontalLayout_59->addWidget(label_63);

        afiwriteUID = new QLineEdit(groupBox_7);
        afiwriteUID->setObjectName(QString::fromUtf8("afiwriteUID"));

        horizontalLayout_59->addWidget(afiwriteUID);

        label_64 = new QLabel(groupBox_7);
        label_64->setObjectName(QString::fromUtf8("label_64"));

        horizontalLayout_59->addWidget(label_64);

        horizontalSpacer_54 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_59->addItem(horizontalSpacer_54);

        afiWrite = new QPushButton(groupBox_7);
        afiWrite->setObjectName(QString::fromUtf8("afiWrite"));

        horizontalLayout_59->addWidget(afiWrite);


        gridLayout_19->addLayout(horizontalLayout_59, 15, 0, 1, 1);

        horizontalLayout_49 = new QHBoxLayout();
        horizontalLayout_49->setSpacing(6);
        horizontalLayout_49->setObjectName(QString::fromUtf8("horizontalLayout_49"));
        label_41 = new QLabel(groupBox_7);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_49->addWidget(label_41);

        horizontalSpacer_44 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_49->addItem(horizontalSpacer_44);

        isoInventory = new QPushButton(groupBox_7);
        isoInventory->setObjectName(QString::fromUtf8("isoInventory"));

        horizontalLayout_49->addWidget(isoInventory);


        gridLayout_19->addLayout(horizontalLayout_49, 0, 0, 1, 1);

        line_7 = new QFrame(groupBox_7);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_7, 1, 0, 1, 1);

        horizontalLayout_50 = new QHBoxLayout();
        horizontalLayout_50->setSpacing(6);
        horizontalLayout_50->setObjectName(QString::fromUtf8("horizontalLayout_50"));
        isoreadFlag = new QLineEdit(groupBox_7);
        isoreadFlag->setObjectName(QString::fromUtf8("isoreadFlag"));
        isoreadFlag->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_50->addWidget(isoreadFlag);

        label_43 = new QLabel(groupBox_7);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        horizontalLayout_50->addWidget(label_43);

        isoreadStart = new QLineEdit(groupBox_7);
        isoreadStart->setObjectName(QString::fromUtf8("isoreadStart"));
        isoreadStart->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_50->addWidget(isoreadStart);

        label_44 = new QLabel(groupBox_7);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        horizontalLayout_50->addWidget(label_44);

        isoreadNum = new QLineEdit(groupBox_7);
        isoreadNum->setObjectName(QString::fromUtf8("isoreadNum"));
        isoreadNum->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_50->addWidget(isoreadNum);

        label_45 = new QLabel(groupBox_7);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        horizontalLayout_50->addWidget(label_45);

        horizontalSpacer_45 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_50->addItem(horizontalSpacer_45);

        isoRead = new QPushButton(groupBox_7);
        isoRead->setObjectName(QString::fromUtf8("isoRead"));

        horizontalLayout_50->addWidget(isoRead);


        gridLayout_19->addLayout(horizontalLayout_50, 2, 0, 1, 1);

        line_8 = new QFrame(groupBox_7);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_8, 4, 0, 1, 1);

        horizontalLayout_55 = new QHBoxLayout();
        horizontalLayout_55->setSpacing(6);
        horizontalLayout_55->setObjectName(QString::fromUtf8("horizontalLayout_55"));
        isoreadUID = new QLineEdit(groupBox_7);
        isoreadUID->setObjectName(QString::fromUtf8("isoreadUID"));

        horizontalLayout_55->addWidget(isoreadUID);

        label_54 = new QLabel(groupBox_7);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        horizontalLayout_55->addWidget(label_54);

        horizontalSpacer_48 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_55->addItem(horizontalSpacer_48);


        gridLayout_19->addLayout(horizontalLayout_55, 3, 0, 1, 1);

        horizontalLayout_56 = new QHBoxLayout();
        horizontalLayout_56->setSpacing(6);
        horizontalLayout_56->setObjectName(QString::fromUtf8("horizontalLayout_56"));
        isowriteUID = new QLineEdit(groupBox_7);
        isowriteUID->setObjectName(QString::fromUtf8("isowriteUID"));

        horizontalLayout_56->addWidget(isowriteUID);

        label_55 = new QLabel(groupBox_7);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        horizontalLayout_56->addWidget(label_55);

        horizontalSpacer_51 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_56->addItem(horizontalSpacer_51);


        gridLayout_19->addLayout(horizontalLayout_56, 6, 0, 1, 1);

        horizontalLayout_58 = new QHBoxLayout();
        horizontalLayout_58->setSpacing(6);
        horizontalLayout_58->setObjectName(QString::fromUtf8("horizontalLayout_58"));
        cardselFlag = new QLineEdit(groupBox_7);
        cardselFlag->setObjectName(QString::fromUtf8("cardselFlag"));
        cardselFlag->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_58->addWidget(cardselFlag);

        label_61 = new QLabel(groupBox_7);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        horizontalLayout_58->addWidget(label_61);

        cardselUID = new QLineEdit(groupBox_7);
        cardselUID->setObjectName(QString::fromUtf8("cardselUID"));

        horizontalLayout_58->addWidget(cardselUID);

        label_58 = new QLabel(groupBox_7);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        horizontalLayout_58->addWidget(label_58);

        horizontalSpacer_53 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_58->addItem(horizontalSpacer_53);

        cardSelect = new QPushButton(groupBox_7);
        cardSelect->setObjectName(QString::fromUtf8("cardSelect"));

        horizontalLayout_58->addWidget(cardSelect);


        gridLayout_19->addLayout(horizontalLayout_58, 13, 0, 1, 1);

        horizontalLayout_65 = new QHBoxLayout();
        horizontalLayout_65->setSpacing(6);
        horizontalLayout_65->setObjectName(QString::fromUtf8("horizontalLayout_65"));
        dsfidlockFlag = new QLineEdit(groupBox_7);
        dsfidlockFlag->setObjectName(QString::fromUtf8("dsfidlockFlag"));
        dsfidlockFlag->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_65->addWidget(dsfidlockFlag);

        label_88 = new QLabel(groupBox_7);
        label_88->setObjectName(QString::fromUtf8("label_88"));

        horizontalLayout_65->addWidget(label_88);

        lockdsfidUID = new QLineEdit(groupBox_7);
        lockdsfidUID->setObjectName(QString::fromUtf8("lockdsfidUID"));

        horizontalLayout_65->addWidget(lockdsfidUID);

        label_82 = new QLabel(groupBox_7);
        label_82->setObjectName(QString::fromUtf8("label_82"));

        horizontalLayout_65->addWidget(label_82);

        horizontalSpacer_60 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_65->addItem(horizontalSpacer_60);

        dsfidLock = new QPushButton(groupBox_7);
        dsfidLock->setObjectName(QString::fromUtf8("dsfidLock"));

        horizontalLayout_65->addWidget(dsfidLock);


        gridLayout_19->addLayout(horizontalLayout_65, 21, 0, 1, 1);

        horizontalLayout_66 = new QHBoxLayout();
        horizontalLayout_66->setSpacing(6);
        horizontalLayout_66->setObjectName(QString::fromUtf8("horizontalLayout_66"));
        dsfidwriteFlag = new QLineEdit(groupBox_7);
        dsfidwriteFlag->setObjectName(QString::fromUtf8("dsfidwriteFlag"));
        dsfidwriteFlag->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_66->addWidget(dsfidwriteFlag);

        label_87 = new QLabel(groupBox_7);
        label_87->setObjectName(QString::fromUtf8("label_87"));

        horizontalLayout_66->addWidget(label_87);

        writeDSFID = new QLineEdit(groupBox_7);
        writeDSFID->setObjectName(QString::fromUtf8("writeDSFID"));
        writeDSFID->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_66->addWidget(writeDSFID);

        label_84 = new QLabel(groupBox_7);
        label_84->setObjectName(QString::fromUtf8("label_84"));

        horizontalLayout_66->addWidget(label_84);

        dsfidwriteUID = new QLineEdit(groupBox_7);
        dsfidwriteUID->setObjectName(QString::fromUtf8("dsfidwriteUID"));

        horizontalLayout_66->addWidget(dsfidwriteUID);

        label_85 = new QLabel(groupBox_7);
        label_85->setObjectName(QString::fromUtf8("label_85"));

        horizontalLayout_66->addWidget(label_85);

        horizontalSpacer_61 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_66->addItem(horizontalSpacer_61);

        dsfidWrite = new QPushButton(groupBox_7);
        dsfidWrite->setObjectName(QString::fromUtf8("dsfidWrite"));
        dsfidWrite->setEnabled(false);

        horizontalLayout_66->addWidget(dsfidWrite);


        gridLayout_19->addLayout(horizontalLayout_66, 19, 0, 1, 1);

        horizontalLayout_82 = new QHBoxLayout();
        horizontalLayout_82->setSpacing(6);
        horizontalLayout_82->setObjectName(QString::fromUtf8("horizontalLayout_82"));
        blksecFlag = new QLineEdit(groupBox_7);
        blksecFlag->setObjectName(QString::fromUtf8("blksecFlag"));
        blksecFlag->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_82->addWidget(blksecFlag);

        label_125 = new QLabel(groupBox_7);
        label_125->setObjectName(QString::fromUtf8("label_125"));

        horizontalLayout_82->addWidget(label_125);

        blksecStart = new QLineEdit(groupBox_7);
        blksecStart->setObjectName(QString::fromUtf8("blksecStart"));
        blksecStart->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_82->addWidget(blksecStart);

        label_126 = new QLabel(groupBox_7);
        label_126->setObjectName(QString::fromUtf8("label_126"));

        horizontalLayout_82->addWidget(label_126);

        blksecNum = new QLineEdit(groupBox_7);
        blksecNum->setObjectName(QString::fromUtf8("blksecNum"));
        blksecNum->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_82->addWidget(blksecNum);

        label_127 = new QLabel(groupBox_7);
        label_127->setObjectName(QString::fromUtf8("label_127"));

        horizontalLayout_82->addWidget(label_127);

        horizontalSpacer_80 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_82->addItem(horizontalSpacer_80);

        blksecGet = new QPushButton(groupBox_7);
        blksecGet->setObjectName(QString::fromUtf8("blksecGet"));
        blksecGet->setEnabled(false);

        horizontalLayout_82->addWidget(blksecGet);


        gridLayout_19->addLayout(horizontalLayout_82, 25, 0, 1, 1);

        horizontalLayout_51 = new QHBoxLayout();
        horizontalLayout_51->setSpacing(6);
        horizontalLayout_51->setObjectName(QString::fromUtf8("horizontalLayout_51"));
        isowriteFlag = new QLineEdit(groupBox_7);
        isowriteFlag->setObjectName(QString::fromUtf8("isowriteFlag"));
        isowriteFlag->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_51->addWidget(isowriteFlag);

        label_47 = new QLabel(groupBox_7);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        horizontalLayout_51->addWidget(label_47);

        isowriteStart = new QLineEdit(groupBox_7);
        isowriteStart->setObjectName(QString::fromUtf8("isowriteStart"));
        isowriteStart->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_51->addWidget(isowriteStart);

        label_48 = new QLabel(groupBox_7);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        horizontalLayout_51->addWidget(label_48);

        isowriteNum = new QLineEdit(groupBox_7);
        isowriteNum->setObjectName(QString::fromUtf8("isowriteNum"));
        isowriteNum->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_51->addWidget(isowriteNum);

        label_49 = new QLabel(groupBox_7);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        horizontalLayout_51->addWidget(label_49);

        horizontalSpacer_46 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_51->addItem(horizontalSpacer_46);

        isoWrite = new QPushButton(groupBox_7);
        isoWrite->setObjectName(QString::fromUtf8("isoWrite"));

        horizontalLayout_51->addWidget(isoWrite);


        gridLayout_19->addLayout(horizontalLayout_51, 5, 0, 1, 1);

        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setSpacing(6);
        horizontalLayout_52->setObjectName(QString::fromUtf8("horizontalLayout_52"));
        label_50 = new QLabel(groupBox_7);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        horizontalLayout_52->addWidget(label_50);

        isowriteData = new QLineEdit(groupBox_7);
        isowriteData->setObjectName(QString::fromUtf8("isowriteData"));

        horizontalLayout_52->addWidget(isowriteData);


        gridLayout_19->addLayout(horizontalLayout_52, 8, 0, 1, 1);

        line_9 = new QFrame(groupBox_7);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_9, 9, 0, 1, 1);

        horizontalLayout_53 = new QHBoxLayout();
        horizontalLayout_53->setSpacing(6);
        horizontalLayout_53->setObjectName(QString::fromUtf8("horizontalLayout_53"));
        isogetFlag = new QLineEdit(groupBox_7);
        isogetFlag->setObjectName(QString::fromUtf8("isogetFlag"));
        isogetFlag->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_53->addWidget(isogetFlag);

        label_52 = new QLabel(groupBox_7);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        horizontalLayout_53->addWidget(label_52);

        isogetUID = new QLineEdit(groupBox_7);
        isogetUID->setObjectName(QString::fromUtf8("isogetUID"));

        horizontalLayout_53->addWidget(isogetUID);

        label_53 = new QLabel(groupBox_7);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        horizontalLayout_53->addWidget(label_53);

        horizontalSpacer_47 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_53->addItem(horizontalSpacer_47);

        isoGet = new QPushButton(groupBox_7);
        isoGet->setObjectName(QString::fromUtf8("isoGet"));
        isoGet->setEnabled(false);

        horizontalLayout_53->addWidget(isoGet);


        gridLayout_19->addLayout(horizontalLayout_53, 23, 0, 1, 1);

        line_10 = new QFrame(groupBox_7);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_10, 14, 0, 1, 1);

        horizontalLayout_57 = new QHBoxLayout();
        horizontalLayout_57->setSpacing(6);
        horizontalLayout_57->setObjectName(QString::fromUtf8("horizontalLayout_57"));
        blklockFlag = new QLineEdit(groupBox_7);
        blklockFlag->setObjectName(QString::fromUtf8("blklockFlag"));
        blklockFlag->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_57->addWidget(blklockFlag);

        label_57 = new QLabel(groupBox_7);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        horizontalLayout_57->addWidget(label_57);

        lockBlock = new QLineEdit(groupBox_7);
        lockBlock->setObjectName(QString::fromUtf8("lockBlock"));
        lockBlock->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_57->addWidget(lockBlock);

        label_59 = new QLabel(groupBox_7);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        horizontalLayout_57->addWidget(label_59);

        blklockUID = new QLineEdit(groupBox_7);
        blklockUID->setObjectName(QString::fromUtf8("blklockUID"));

        horizontalLayout_57->addWidget(blklockUID);

        label_68 = new QLabel(groupBox_7);
        label_68->setObjectName(QString::fromUtf8("label_68"));

        horizontalLayout_57->addWidget(label_68);

        horizontalSpacer_52 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_57->addItem(horizontalSpacer_52);

        blockLock = new QPushButton(groupBox_7);
        blockLock->setObjectName(QString::fromUtf8("blockLock"));

        horizontalLayout_57->addWidget(blockLock);


        gridLayout_19->addLayout(horizontalLayout_57, 11, 0, 1, 1);

        line_12 = new QFrame(groupBox_7);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_12, 16, 0, 1, 1);

        line_14 = new QFrame(groupBox_7);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_14, 22, 0, 1, 1);

        line_11 = new QFrame(groupBox_7);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_11, 12, 0, 1, 1);

        line_13 = new QFrame(groupBox_7);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_13, 18, 0, 1, 1);

        line_15 = new QFrame(groupBox_7);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_15, 20, 0, 1, 1);

        horizontalLayout_81 = new QHBoxLayout();
        horizontalLayout_81->setSpacing(6);
        horizontalLayout_81->setObjectName(QString::fromUtf8("horizontalLayout_81"));
        horizontalSpacer_78 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_81->addItem(horizontalSpacer_78);

        blksecUID = new QLineEdit(groupBox_7);
        blksecUID->setObjectName(QString::fromUtf8("blksecUID"));

        horizontalLayout_81->addWidget(blksecUID);

        label_123 = new QLabel(groupBox_7);
        label_123->setObjectName(QString::fromUtf8("label_123"));

        horizontalLayout_81->addWidget(label_123);

        horizontalSpacer_79 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_81->addItem(horizontalSpacer_79);


        gridLayout_19->addLayout(horizontalLayout_81, 26, 0, 1, 1);

        line_25 = new QFrame(groupBox_7);
        line_25->setObjectName(QString::fromUtf8("line_25"));
        line_25->setFrameShape(QFrame::HLine);
        line_25->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_25, 24, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout->addWidget(tabWidget);

        dataBox = new QGroupBox(centralWidget);
        dataBox->setObjectName(QString::fromUtf8("dataBox"));
        gridLayout_2 = new QGridLayout(dataBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        dataEdit = new QPlainTextEdit(dataBox);
        dataEdit->setObjectName(QString::fromUtf8("dataEdit"));
        dataEdit->setReadOnly(true);

        gridLayout_2->addWidget(dataEdit, 0, 0, 1, 1);


        horizontalLayout->addWidget(dataBox);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 2);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        UsbReaderDemoClass->setCentralWidget(centralWidget);

        retranslateUi(UsbReaderDemoClass);

        tabWidget->setCurrentIndex(0);
        readStart->setCurrentIndex(16);
        readNum->setCurrentIndex(0);
        readKey->setCurrentIndex(2);
        writeStart->setCurrentIndex(15);
        writeKey->setCurrentIndex(2);
        utreadBlock->setCurrentRow(0);
        utwriteBlock->setCurrentRow(0);


        QMetaObject::connectSlotsByName(UsbReaderDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *UsbReaderDemoClass)
    {
        UsbReaderDemoClass->setWindowTitle(QApplication::translate("UsbReaderDemoClass", "UsbReaderDemo", 0, QApplication::UnicodeUTF8));
        commandBox->setTitle(QApplication::translate("UsbReaderDemoClass", "\347\263\273\347\273\237\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UsbReaderDemoClass", "Led:   ", 0, QApplication::UnicodeUTF8));
        ledcycleEdit->setText(QApplication::translate("UsbReaderDemoClass", "18", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("UsbReaderDemoClass", "Cycle", 0, QApplication::UnicodeUTF8));
        ledtimesEdit->setText(QApplication::translate("UsbReaderDemoClass", "09", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("UsbReaderDemoClass", "Times", 0, QApplication::UnicodeUTF8));
        setledButton->setText(QApplication::translate("UsbReaderDemoClass", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("UsbReaderDemoClass", "Buzzer:", 0, QApplication::UnicodeUTF8));
        bzrcycleEdit->setText(QApplication::translate("UsbReaderDemoClass", "18", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("UsbReaderDemoClass", "Cycle", 0, QApplication::UnicodeUTF8));
        bzrtimesEdit->setText(QApplication::translate("UsbReaderDemoClass", "09", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("UsbReaderDemoClass", "Times", 0, QApplication::UnicodeUTF8));
        setbuzzerButton->setText(QApplication::translate("UsbReaderDemoClass", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\217\226\346\234\272\345\231\250\345\272\217\345\210\227\345\217\267:", 0, QApplication::UnicodeUTF8));
        readsernumButton->setText(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\217\226\347\211\210\346\234\254\345\217\267:", 0, QApplication::UnicodeUTF8));
        getverButton->setText(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UsbReaderDemoClass", "\350\256\276\347\275\256\346\234\272\345\231\250\345\272\217\345\210\227\345\217\267:", 0, QApplication::UnicodeUTF8));
        sernumEdit->setText(QApplication::translate("UsbReaderDemoClass", "AA BB AA BB AA BB AA BB", 0, QApplication::UnicodeUTF8));
        setsernumButton->setText(QApplication::translate("UsbReaderDemoClass", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(systemTab), QApplication::translate("UsbReaderDemoClass", "\347\263\273\347\273\237\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("UsbReaderDemoClass", "Type A", 0, QApplication::UnicodeUTF8));
        readIdl->setText(QApplication::translate("UsbReaderDemoClass", "Idle", 0, QApplication::UnicodeUTF8));
        readAll->setText(QApplication::translate("UsbReaderDemoClass", "All", 0, QApplication::UnicodeUTF8));
        readKeyA->setText(QApplication::translate("UsbReaderDemoClass", "Key A", 0, QApplication::UnicodeUTF8));
        readKeyB->setText(QApplication::translate("UsbReaderDemoClass", "Key B", 0, QApplication::UnicodeUTF8));
        mfRead->setText(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\215\241", 0, QApplication::UnicodeUTF8));
        readStart->clear();
        readStart->insertItems(0, QStringList()
         << QApplication::translate("UsbReaderDemoClass", "00", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "03", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "04", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "05", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "06", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "07", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "08", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "09", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "28", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3F", 0, QApplication::UnicodeUTF8)
        );
        label_12->setText(QApplication::translate("UsbReaderDemoClass", "\350\265\267\345\247\213\345\235\227    ", 0, QApplication::UnicodeUTF8));
        readNum->clear();
        readNum->insertItems(0, QStringList()
         << QApplication::translate("UsbReaderDemoClass", "01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "03", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "04", 0, QApplication::UnicodeUTF8)
        );
        label_13->setText(QApplication::translate("UsbReaderDemoClass", "\345\235\227\347\232\204\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        readKey->clear();
        readKey->insertItems(0, QStringList()
         << QApplication::translate("UsbReaderDemoClass", "A0 A1 A2 A3 A4 A5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "B0 B1 B2 B3 B4 B5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "FF FF FF FF FF FF", 0, QApplication::UnicodeUTF8)
        );
        label_14->setText(QApplication::translate("UsbReaderDemoClass", "\345\257\206\351\222\245", 0, QApplication::UnicodeUTF8));
        writeIdl->setText(QApplication::translate("UsbReaderDemoClass", "Idle", 0, QApplication::UnicodeUTF8));
        writeAll->setText(QApplication::translate("UsbReaderDemoClass", "All", 0, QApplication::UnicodeUTF8));
        writeKeyA->setText(QApplication::translate("UsbReaderDemoClass", "Key A", 0, QApplication::UnicodeUTF8));
        writeKeyB->setText(QApplication::translate("UsbReaderDemoClass", "Key B", 0, QApplication::UnicodeUTF8));
        mfWrite->setText(QApplication::translate("UsbReaderDemoClass", "\345\206\231\345\215\241", 0, QApplication::UnicodeUTF8));
        writeStart->clear();
        writeStart->insertItems(0, QStringList()
         << QApplication::translate("UsbReaderDemoClass", "00", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "03", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "04", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "05", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "06", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "07", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "08", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "09", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "0F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "1F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "28", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "2A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "2B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "2C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "2D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "2E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "2F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "31", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "33", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "34", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "35", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "36", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "37", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "38", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "39", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "3F", 0, QApplication::UnicodeUTF8)
        );
        label_17->setText(QApplication::translate("UsbReaderDemoClass", "\350\265\267\345\247\213\345\235\227     ", 0, QApplication::UnicodeUTF8));
        writeNum->clear();
        writeNum->insertItems(0, QStringList()
         << QApplication::translate("UsbReaderDemoClass", "01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "03", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "04", 0, QApplication::UnicodeUTF8)
        );
        label_18->setText(QApplication::translate("UsbReaderDemoClass", "\345\235\227\347\232\204\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        writeKey->clear();
        writeKey->insertItems(0, QStringList()
         << QApplication::translate("UsbReaderDemoClass", "A0 A1 A2 A3 A4 A5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "B0 B1 B2 B3 B4 B5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UsbReaderDemoClass", "FF FF FF FF FF FF", 0, QApplication::UnicodeUTF8)
        );
        label_19->setText(QApplication::translate("UsbReaderDemoClass", "\345\257\206\351\222\245", 0, QApplication::UnicodeUTF8));
        writeData->setText(QApplication::translate("UsbReaderDemoClass", "FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("UsbReaderDemoClass", "\351\234\200\350\246\201\345\275\225\345\205\245\347\232\204\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        initKey->setText(QApplication::translate("UsbReaderDemoClass", "FF FF FF FF FF FF", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("UsbReaderDemoClass", "\345\257\206\351\222\245", 0, QApplication::UnicodeUTF8));
        initValue->setText(QApplication::translate("UsbReaderDemoClass", "64 00 00 00", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("UsbReaderDemoClass", "\345\210\235\345\247\213\345\200\274", 0, QApplication::UnicodeUTF8));
        initIdl->setText(QApplication::translate("UsbReaderDemoClass", "Idle", 0, QApplication::UnicodeUTF8));
        initAll->setText(QApplication::translate("UsbReaderDemoClass", "All", 0, QApplication::UnicodeUTF8));
        initKeyA->setText(QApplication::translate("UsbReaderDemoClass", "Key A", 0, QApplication::UnicodeUTF8));
        initKeyB->setText(QApplication::translate("UsbReaderDemoClass", "Key B", 0, QApplication::UnicodeUTF8));
        initSector->setText(QApplication::translate("UsbReaderDemoClass", "04", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("UsbReaderDemoClass", "\346\211\207\345\214\272", 0, QApplication::UnicodeUTF8));
        mfInit->setText(QApplication::translate("UsbReaderDemoClass", "\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        decIdl->setText(QApplication::translate("UsbReaderDemoClass", "Idle", 0, QApplication::UnicodeUTF8));
        decAll->setText(QApplication::translate("UsbReaderDemoClass", "All", 0, QApplication::UnicodeUTF8));
        decKeyA->setText(QApplication::translate("UsbReaderDemoClass", "Key A", 0, QApplication::UnicodeUTF8));
        decKeyB->setText(QApplication::translate("UsbReaderDemoClass", "Key B", 0, QApplication::UnicodeUTF8));
        decSector->setText(QApplication::translate("UsbReaderDemoClass", "04", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("UsbReaderDemoClass", "\346\211\207\345\214\272", 0, QApplication::UnicodeUTF8));
        mfDeval->setText(QApplication::translate("UsbReaderDemoClass", "\345\207\217\345\200\274", 0, QApplication::UnicodeUTF8));
        decKey->setText(QApplication::translate("UsbReaderDemoClass", "FF FF FF FF FF FF", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("UsbReaderDemoClass", "\345\257\206\351\222\245", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("UsbReaderDemoClass", "\345\207\217\345\200\274", 0, QApplication::UnicodeUTF8));
        incIdl->setText(QApplication::translate("UsbReaderDemoClass", "Idle", 0, QApplication::UnicodeUTF8));
        incAll->setText(QApplication::translate("UsbReaderDemoClass", "All", 0, QApplication::UnicodeUTF8));
        incKeyA->setText(QApplication::translate("UsbReaderDemoClass", "Key A", 0, QApplication::UnicodeUTF8));
        incKeyB->setText(QApplication::translate("UsbReaderDemoClass", "Key B", 0, QApplication::UnicodeUTF8));
        incSector->setText(QApplication::translate("UsbReaderDemoClass", "04", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("UsbReaderDemoClass", "\346\211\207\345\214\272", 0, QApplication::UnicodeUTF8));
        mfInval->setText(QApplication::translate("UsbReaderDemoClass", "\345\212\240\345\200\274", 0, QApplication::UnicodeUTF8));
        incKey->setText(QApplication::translate("UsbReaderDemoClass", "FF FF FF FF FF FF", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("UsbReaderDemoClass", "\345\257\206\351\222\245", 0, QApplication::UnicodeUTF8));
        incValue->setText(QApplication::translate("UsbReaderDemoClass", "01 00 00 00", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("UsbReaderDemoClass", "\345\212\240\345\200\274", 0, QApplication::UnicodeUTF8));
        snrIdl->setText(QApplication::translate("UsbReaderDemoClass", "Idle", 0, QApplication::UnicodeUTF8));
        snrAll->setText(QApplication::translate("UsbReaderDemoClass", "All", 0, QApplication::UnicodeUTF8));
        snrNoHalt->setText(QApplication::translate("UsbReaderDemoClass", "no halt", 0, QApplication::UnicodeUTF8));
        snrHalt->setText(QApplication::translate("UsbReaderDemoClass", "halt", 0, QApplication::UnicodeUTF8));
        mfCardNum->setText(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\215\241\345\217\267", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("UsbReaderDemoClass", "14443A-MF", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\217\226\345\215\241\347\211\207\345\272\217\345\210\227\345\217\267:", 0, QApplication::UnicodeUTF8));
        utsnIdle->setText(QApplication::translate("UsbReaderDemoClass", "Idle", 0, QApplication::UnicodeUTF8));
        utsnAll->setText(QApplication::translate("UsbReaderDemoClass", "All", 0, QApplication::UnicodeUTF8));
        utsnRead->setText(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("UsbReaderDemoClass", "Halt:", 0, QApplication::UnicodeUTF8));
        utHalt->setText(QApplication::translate("UsbReaderDemoClass", "Halt", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("UsbReaderDemoClass", "Ultralight\345\215\241\350\257\273\345\206\231", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\215\241", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("UsbReaderDemoClass", "\346\211\207\345\214\272\357\274\232", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = utreadBlock->isSortingEnabled();
        utreadBlock->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = utreadBlock->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("UsbReaderDemoClass", "00", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = utreadBlock->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("UsbReaderDemoClass", "01", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = utreadBlock->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = utreadBlock->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("UsbReaderDemoClass", "03", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = utreadBlock->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("UsbReaderDemoClass", "04", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem5 = utreadBlock->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("UsbReaderDemoClass", "05", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem6 = utreadBlock->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("UsbReaderDemoClass", "06", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem7 = utreadBlock->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("UsbReaderDemoClass", "07", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem8 = utreadBlock->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("UsbReaderDemoClass", "08", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem9 = utreadBlock->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("UsbReaderDemoClass", "09", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem10 = utreadBlock->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("UsbReaderDemoClass", "10", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem11 = utreadBlock->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("UsbReaderDemoClass", "11", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem12 = utreadBlock->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("UsbReaderDemoClass", "12", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem13 = utreadBlock->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("UsbReaderDemoClass", "13", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem14 = utreadBlock->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("UsbReaderDemoClass", "14", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem15 = utreadBlock->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("UsbReaderDemoClass", "15", 0, QApplication::UnicodeUTF8));
        utreadBlock->setSortingEnabled(__sortingEnabled);

        utreadIdle->setText(QApplication::translate("UsbReaderDemoClass", "Idle", 0, QApplication::UnicodeUTF8));
        utreadAll->setText(QApplication::translate("UsbReaderDemoClass", "All", 0, QApplication::UnicodeUTF8));
        utblockRead->setText(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\215\241", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("UsbReaderDemoClass", "\345\206\231\345\215\241", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("UsbReaderDemoClass", "\346\211\207\345\214\272:", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = utwriteBlock->isSortingEnabled();
        utwriteBlock->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem16 = utwriteBlock->item(0);
        ___qlistwidgetitem16->setText(QApplication::translate("UsbReaderDemoClass", "00", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem17 = utwriteBlock->item(1);
        ___qlistwidgetitem17->setText(QApplication::translate("UsbReaderDemoClass", "01", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem18 = utwriteBlock->item(2);
        ___qlistwidgetitem18->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem19 = utwriteBlock->item(3);
        ___qlistwidgetitem19->setText(QApplication::translate("UsbReaderDemoClass", "03", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem20 = utwriteBlock->item(4);
        ___qlistwidgetitem20->setText(QApplication::translate("UsbReaderDemoClass", "04", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem21 = utwriteBlock->item(5);
        ___qlistwidgetitem21->setText(QApplication::translate("UsbReaderDemoClass", "05", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem22 = utwriteBlock->item(6);
        ___qlistwidgetitem22->setText(QApplication::translate("UsbReaderDemoClass", "06", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem23 = utwriteBlock->item(7);
        ___qlistwidgetitem23->setText(QApplication::translate("UsbReaderDemoClass", "07", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem24 = utwriteBlock->item(8);
        ___qlistwidgetitem24->setText(QApplication::translate("UsbReaderDemoClass", "08", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem25 = utwriteBlock->item(9);
        ___qlistwidgetitem25->setText(QApplication::translate("UsbReaderDemoClass", "09", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem26 = utwriteBlock->item(10);
        ___qlistwidgetitem26->setText(QApplication::translate("UsbReaderDemoClass", "10", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem27 = utwriteBlock->item(11);
        ___qlistwidgetitem27->setText(QApplication::translate("UsbReaderDemoClass", "11", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem28 = utwriteBlock->item(12);
        ___qlistwidgetitem28->setText(QApplication::translate("UsbReaderDemoClass", "12", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem29 = utwriteBlock->item(13);
        ___qlistwidgetitem29->setText(QApplication::translate("UsbReaderDemoClass", "13", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem30 = utwriteBlock->item(14);
        ___qlistwidgetitem30->setText(QApplication::translate("UsbReaderDemoClass", "14", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem31 = utwriteBlock->item(15);
        ___qlistwidgetitem31->setText(QApplication::translate("UsbReaderDemoClass", "15", 0, QApplication::UnicodeUTF8));
        utwriteBlock->setSortingEnabled(__sortingEnabled1);

        utwriteIdle->setText(QApplication::translate("UsbReaderDemoClass", "Idle", 0, QApplication::UnicodeUTF8));
        utwriteAll->setText(QApplication::translate("UsbReaderDemoClass", "All", 0, QApplication::UnicodeUTF8));
        utwriteData->setText(QApplication::translate("UsbReaderDemoClass", "00 00 00 00", 0, QApplication::UnicodeUTF8));
        utwriteWrite->setText(QApplication::translate("UsbReaderDemoClass", "\345\206\231\345\215\241", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("UsbReaderDemoClass", "Ultralight", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("UsbReaderDemoClass", "14443B", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("UsbReaderDemoClass", "\350\246\201\345\217\221\351\200\201\347\232\204\346\225\260\346\215\256:", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("UsbReaderDemoClass", "\350\246\201\345\217\221\351\200\201\347\232\204\346\225\260\346\215\256\351\225\277\345\272\246:", 0, QApplication::UnicodeUTF8));
        Blength->setText(QApplication::translate("UsbReaderDemoClass", "08", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("UsbReaderDemoClass", "\345\215\241\350\257\267\346\261\202:", 0, QApplication::UnicodeUTF8));
        BRequest->setText(QApplication::translate("UsbReaderDemoClass", "\345\215\241\350\257\267\346\261\202", 0, QApplication::UnicodeUTF8));
        BData->setText(QApplication::translate("UsbReaderDemoClass", "00 00 05 00 84 00 00 08", 0, QApplication::UnicodeUTF8));
        BTransfer->setText(QApplication::translate("UsbReaderDemoClass", "\345\217\221\351\200\201\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("UsbReaderDemoClass", "\347\254\254\344\272\214\344\273\243\345\261\205\346\260\221\350\272\253\344\273\275\350\257\201", 0, QApplication::UnicodeUTF8));
        BUid->setText(QApplication::translate("UsbReaderDemoClass", "\350\257\273\345\217\226\350\272\253\344\273\275\350\257\201\345\217\267", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("UsbReaderDemoClass", "14443 B", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("UsbReaderDemoClass", "ISO15693", 0, QApplication::UnicodeUTF8));
        afilockFlag->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_86->setText(QApplication::translate("UsbReaderDemoClass", "\346\240\207\345\277\227\344\275\215  ", 0, QApplication::UnicodeUTF8));
        label_67->setText(QApplication::translate("UsbReaderDemoClass", "UID", 0, QApplication::UnicodeUTF8));
        afiLock->setText(QApplication::translate("UsbReaderDemoClass", "\351\224\201\345\256\232AFI", 0, QApplication::UnicodeUTF8));
        afiwriteFlag->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_66->setText(QApplication::translate("UsbReaderDemoClass", "\346\240\207\345\277\227\344\275\215  ", 0, QApplication::UnicodeUTF8));
        writeAFI->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("UsbReaderDemoClass", "AFI", 0, QApplication::UnicodeUTF8));
        label_64->setText(QApplication::translate("UsbReaderDemoClass", "UID", 0, QApplication::UnicodeUTF8));
        afiWrite->setText(QApplication::translate("UsbReaderDemoClass", "\345\206\231AFI", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("UsbReaderDemoClass", "\351\230\262\345\206\262\347\252\201:", 0, QApplication::UnicodeUTF8));
        isoInventory->setText(QApplication::translate("UsbReaderDemoClass", "\351\230\262\345\206\262\347\252\201", 0, QApplication::UnicodeUTF8));
        isoreadFlag->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("UsbReaderDemoClass", "\346\240\207\345\277\227\344\275\215  ", 0, QApplication::UnicodeUTF8));
        isoreadStart->setText(QApplication::translate("UsbReaderDemoClass", "01", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("UsbReaderDemoClass", "\350\265\267\345\247\213\345\235\227  ", 0, QApplication::UnicodeUTF8));
        isoreadNum->setText(QApplication::translate("UsbReaderDemoClass", "05", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("UsbReaderDemoClass", "\345\235\227\346\225\260\351\207\217  ", 0, QApplication::UnicodeUTF8));
        isoRead->setText(QApplication::translate("UsbReaderDemoClass", "\345\215\241\347\211\207\350\257\273", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("UsbReaderDemoClass", "UID", 0, QApplication::UnicodeUTF8));
        label_55->setText(QApplication::translate("UsbReaderDemoClass", "UID", 0, QApplication::UnicodeUTF8));
        cardselFlag->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_61->setText(QApplication::translate("UsbReaderDemoClass", "\346\240\207\345\277\227\344\275\215  ", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("UsbReaderDemoClass", "UID", 0, QApplication::UnicodeUTF8));
        cardSelect->setText(QApplication::translate("UsbReaderDemoClass", "\351\200\211\346\213\251\345\215\241", 0, QApplication::UnicodeUTF8));
        dsfidlockFlag->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_88->setText(QApplication::translate("UsbReaderDemoClass", "\346\240\207\345\277\227\344\275\215  ", 0, QApplication::UnicodeUTF8));
        label_82->setText(QApplication::translate("UsbReaderDemoClass", "UID", 0, QApplication::UnicodeUTF8));
        dsfidLock->setText(QApplication::translate("UsbReaderDemoClass", "\351\224\201\345\256\232DSFID", 0, QApplication::UnicodeUTF8));
        dsfidwriteFlag->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_87->setText(QApplication::translate("UsbReaderDemoClass", "\346\240\207\345\277\227\344\275\215  ", 0, QApplication::UnicodeUTF8));
        writeDSFID->setText(QApplication::translate("UsbReaderDemoClass", "08", 0, QApplication::UnicodeUTF8));
        label_84->setText(QApplication::translate("UsbReaderDemoClass", "DSFID", 0, QApplication::UnicodeUTF8));
        label_85->setText(QApplication::translate("UsbReaderDemoClass", "UID", 0, QApplication::UnicodeUTF8));
        dsfidWrite->setText(QApplication::translate("UsbReaderDemoClass", "\345\206\231DSFID", 0, QApplication::UnicodeUTF8));
        blksecFlag->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_125->setText(QApplication::translate("UsbReaderDemoClass", "\346\240\207\345\277\227\344\275\215  ", 0, QApplication::UnicodeUTF8));
        blksecStart->setText(QApplication::translate("UsbReaderDemoClass", "01", 0, QApplication::UnicodeUTF8));
        label_126->setText(QApplication::translate("UsbReaderDemoClass", "\350\265\267\345\247\213\345\235\227  ", 0, QApplication::UnicodeUTF8));
        blksecNum->setText(QApplication::translate("UsbReaderDemoClass", "05", 0, QApplication::UnicodeUTF8));
        label_127->setText(QApplication::translate("UsbReaderDemoClass", "\345\235\227\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        blksecGet->setText(QApplication::translate("UsbReaderDemoClass", "\345\235\227\345\256\211\345\205\250\344\275\215", 0, QApplication::UnicodeUTF8));
        isowriteFlag->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("UsbReaderDemoClass", "\346\240\207\345\277\227\344\275\215  ", 0, QApplication::UnicodeUTF8));
        isowriteStart->setText(QApplication::translate("UsbReaderDemoClass", "05", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("UsbReaderDemoClass", "\350\265\267\345\247\213\345\235\227  ", 0, QApplication::UnicodeUTF8));
        isowriteNum->setText(QApplication::translate("UsbReaderDemoClass", "01", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("UsbReaderDemoClass", "\345\235\227\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        isoWrite->setText(QApplication::translate("UsbReaderDemoClass", "\345\215\241\347\211\207\345\206\231", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("UsbReaderDemoClass", "\350\246\201\345\206\231\347\232\204\346\225\260\346\215\256:", 0, QApplication::UnicodeUTF8));
        isowriteData->setText(QApplication::translate("UsbReaderDemoClass", "11 11 11 11", 0, QApplication::UnicodeUTF8));
        isogetFlag->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("UsbReaderDemoClass", "\346\240\207\345\277\227\344\275\215  ", 0, QApplication::UnicodeUTF8));
        label_53->setText(QApplication::translate("UsbReaderDemoClass", "UID", 0, QApplication::UnicodeUTF8));
        isoGet->setText(QApplication::translate("UsbReaderDemoClass", "\347\263\273\347\273\237\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        blklockFlag->setText(QApplication::translate("UsbReaderDemoClass", "02", 0, QApplication::UnicodeUTF8));
        label_57->setText(QApplication::translate("UsbReaderDemoClass", "\346\240\207\345\277\227\344\275\215  ", 0, QApplication::UnicodeUTF8));
        lockBlock->setText(QApplication::translate("UsbReaderDemoClass", "01", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("UsbReaderDemoClass", "\350\265\267\345\247\213\345\235\227  ", 0, QApplication::UnicodeUTF8));
        label_68->setText(QApplication::translate("UsbReaderDemoClass", "UID", 0, QApplication::UnicodeUTF8));
        blockLock->setText(QApplication::translate("UsbReaderDemoClass", "\351\224\201\345\256\232\345\235\227", 0, QApplication::UnicodeUTF8));
        label_123->setText(QApplication::translate("UsbReaderDemoClass", "UID", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("UsbReaderDemoClass", "15693", 0, QApplication::UnicodeUTF8));
        dataBox->setTitle(QApplication::translate("UsbReaderDemoClass", "\350\276\223\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UsbReaderDemoClass: public Ui_UsbReaderDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USBREADERDEMO_H
