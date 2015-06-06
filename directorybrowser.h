#ifndef DIRECTORYBROWSER_H
#define DIRECTORYBROWSER_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
	class DirectoryBrowser;
}

class DirectoryBrowser : public QDialog
{
		Q_OBJECT

	public:
        explicit DirectoryBrowser(QWidget *parent = 0);
        explicit DirectoryBrowser(QWidget *parent = 0, QString Caption = QString());
		~DirectoryBrowser();
		QString getDirectory();

	private slots:
		void on_treeView_clicked(const QModelIndex &index);
		void on_buttonBox_accepted();
		void on_buttonBox_rejected();

    private:
		Ui::DirectoryBrowser *ui;
		QFileSystemModel *dirModel;
        QString mDirectory, mCaption;

};

#endif // DIRECTORYBROWSER_H
