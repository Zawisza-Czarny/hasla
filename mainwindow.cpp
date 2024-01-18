#include "mainwindow.h"

#include <QFileDialog>
#include <QTableView>
MainWindow::MainWindow()
{
    table = new TableView;
    setWindowTitle(tr("Hasła"));
    setCentralWidget(table);
    createMenus();
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Pliki"));
    toolsMenu = menuBar()->addMenu(tr("&Hasła"));
    loadAct = new QAction(tr("Otwórz plik z hasłami"), this);
    fileMenu->addAction(loadAct);
    connect(loadAct, SIGNAL(triggered()), this, SLOT(loadFile()));
    saveAct = new QAction(tr("Zapisz hasła do pliku"), this);
    fileMenu->addAction(saveAct);
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveFile()));
    exit = new QAction(tr("Exit"), this);
    fileMenu->addAction(exit);
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));

    addAct = new QAction(tr("Dodaj hasło"), this);
    toolsMenu->addAction(addAct);
    connect(addAct, SIGNAL(triggered()), table, SLOT(addAction()));
    modAct = new QAction(tr("modyfikuj hasło"), this);
    toolsMenu->addAction(modAct);
    connect(modAct, SIGNAL(triggered()), table, SLOT(modAction()));
    delAct = new QAction(tr("Usuń hasło"), this);
    toolsMenu->addAction(delAct);
    connect(delAct, SIGNAL(triggered()), table, SLOT(delAction()));

    infoMenu = menuBar()->addMenu(tr("&Informacje"));
    infoAct = new QAction(tr("Informacje"), this);
    infoMenu->addAction(infoAct);
    connect(infoAct, SIGNAL(triggered()), table, SLOT(infoAction()));

    wipeMenu = menuBar()->addMenu(tr("&Inne"));
    wipeAct = new QAction(tr("Usuń wszystko"), this);
    wipeMenu->addAction(wipeAct);
    connect(wipeAct, SIGNAL(triggered()), table, SLOT(clearAction()));
}

void MainWindow::loadFile()
{
    QString filename = QFileDialog::getOpenFileName(this);
    if (!filename.isEmpty())
        table->readFromFile(filename);
}

void MainWindow::saveFile()
{
    QString filename = QFileDialog::getSaveFileName(this);
    if (!filename.isEmpty())
        table->saveToFile(filename);
}
