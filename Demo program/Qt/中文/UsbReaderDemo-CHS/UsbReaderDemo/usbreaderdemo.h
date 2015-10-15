#ifndef USBREADERDEMO_H
#define USBREADERDEMO_H

#include <QtGui/QMainWindow>
#include <QDebug>
#include "ui_usbreaderdemo.h"
#include "reader.h"
#include <QRegExp>
#include <QChar>
#include <QPlainTextEdit>

class UsbReaderDemo : public QMainWindow
{
	Q_OBJECT

public:
	UsbReaderDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~UsbReaderDemo();
	QString formatStr(QString str);
	void convertStr(unsigned char *after, QString before, int length);
	static void showStatue(QPlainTextEdit *text, int Code);
	static void showData(QPlainTextEdit *text, unsigned char *data,int position,int length);
	static void showData(QPlainTextEdit *text, char *data,int position,int length);
public slots:
	//System Setting
	void on_setsernumButton_clicked();
	void on_readsernumButton_clicked();
	void on_setledButton_clicked();
	void on_setbuzzerButton_clicked();
	void on_getverButton_clicked();

	//14443A-MF
	void on_mfRead_clicked();
	void on_mfWrite_clicked();
	void on_mfInit_clicked();
	void on_mfDeval_clicked();
	void on_mfInval_clicked();
	void on_mfCardNum_clicked();

	//Ultralight
	void on_utsnRead_clicked();
	void on_utHalt_clicked();
	void on_utblockRead_clicked();
	void on_utwriteWrite_clicked();

	//14443B
	void on_BRequest_clicked();
	void on_BTransfer_clicked();
	void on_BUid_clicked();

	//15693
	void on_isoInventory_clicked();
	void on_isoRead_clicked();
	void on_isoWrite_clicked();
	void on_isoGet_clicked();
	void on_blockLock_clicked();
	void on_cardSelect_clicked();
	void on_afiWrite_clicked();
	void on_afiLock_clicked();
	void on_dsfidWrite_clicked();
	void on_dsfidLock_clicked();
	void on_blksecGet_clicked();
private:
	Ui::UsbReaderDemoClass ui;
	Reader *cardReader;
};

#endif