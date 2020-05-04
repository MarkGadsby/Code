#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <mysql/mysql.h>
#include <linux/limits.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                            ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the number of columns in the tree
    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setColumnWidth(0,300);
    ui->treeWidget->setColumnWidth(1,300);

    // Set the headers
    ui->treeWidget->setHeaderLabels(QStringList() << "Artist" << "Albums");

    // Set up signal
    QObject::connect(ui->treeWidget,
                     SIGNAL(itemActivated(QTreeWidgetItem*,int)),
                     this,
                     SLOT(PlayTitle(QTreeWidgetItem*, int)));
    // Fill control
    MYSQL* pConnection = mysql_init(nullptr);

    if (!mysql_real_connect(pConnection, "localhost" , "root" , "root", "Albums", 0 , nullptr, 0))
    {
        printf("%s\n", mysql_error(pConnection));
        mysql_close(pConnection);
    }

    char QueryString[PATH_MAX] = {"SELECT DISTINCT Artist FROM Albums;"};

    if (mysql_query(pConnection, QueryString))
    {
        printf("%s\n", mysql_error(pConnection));
        mysql_close(pConnection);
    }

    MYSQL_RES* result = mysql_store_result(pConnection);

    if (!result)
    {
        printf("%s\n", mysql_error(pConnection));
        mysql_close(pConnection);
    }

    MYSQL_ROW row;
    QStringList artists;
    QString artist;

    while ((row = mysql_fetch_row(result)))
        artists.append(*row);

    foreach (artist, artists)
    {
        QString firstTitle;

        strcpy(QueryString, "SELECT Title FROM Albums WHERE Artist = '");
        strcat(QueryString, artist.toStdString().c_str());
        strcat(QueryString, "';");

        if (mysql_query(pConnection, QueryString))
        {
            printf("%s\n", mysql_error(pConnection));
            mysql_close(pConnection);
        }

        result = mysql_store_result(pConnection);

        if (!result)
        {
            printf("%s\n", mysql_error(pConnection));
            mysql_close(pConnection);
        }

        firstTitle = *mysql_fetch_row(result);

        QTreeWidgetItem* pArtistRoot = addTreeRoot(artist, firstTitle);

        while ((row = mysql_fetch_row(result)))
            addTreeChild(pArtistRoot, "", *row);
    }
    mysql_free_result(result);
    mysql_close(pConnection);

    ui->treeWidget->sortItems(0,Qt::AscendingOrder);
}

QTreeWidgetItem* MainWindow::addTreeRoot(QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem* treeItem = new QTreeWidgetItem(ui->treeWidget);

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);

    return treeItem;
}

void MainWindow::addTreeChild(QTreeWidgetItem *parent, QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    parent->addChild(treeItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PlayTitle(QTreeWidgetItem *item, int)
{
    QString program = "ssh";
    QString Title = item->text(1);
    Title.insert(0,"\"");
    Title.append("\"");
    QStringList arguments;
    arguments << "pi@192.168.1.5" << "Code/MusicPlayer/Player/MusicPlayer" << Title;

    QProcess *myProcess = new QProcess(this);
    myProcess->start(program, arguments);
}
