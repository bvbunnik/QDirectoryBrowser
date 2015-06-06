#include "directorybrowser.h"
#include "ui_directorybrowser.h"

DirectoryBrowser::DirectoryBrowser(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DirectoryBrowser)
{
	ui->setupUi(this);

    mDirectory = "c:/";
    dirModel = new QFileSystemModel(this);
	dirModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
	dirModel->setRootPath(dirModel->myComputer().toString());

	ui->treeView->setModel(dirModel);
	ui->treeView->hideColumn(1);
	ui->treeView->hideColumn(2);
	ui->treeView->hideColumn(3);
    ui->treeView->setCurrentIndex(dirModel->setRootPath(mDirectory));
    ui->pathEdit->setText(mDirectory);
}

DirectoryBrowser::~DirectoryBrowser()
{
	delete ui;
}

QString DirectoryBrowser::getDirectory()
{
	return mDirectory;
}

void DirectoryBrowser::on_treeView_clicked(const QModelIndex &index)
{
	mDirectory = dirModel->fileInfo(index).absoluteFilePath();
	ui->pathEdit->setText(mDirectory);
}

void DirectoryBrowser::on_buttonBox_accepted()
{
	this->close();
}

void DirectoryBrowser::on_buttonBox_rejected()
{
	mDirectory = "";
	this->close();
}
