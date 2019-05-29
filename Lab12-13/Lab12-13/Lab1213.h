#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
//#include "ui_Lab1213.h"
#include "controller.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <string>
#include "exceptions.h"
#include <playlist.h>

class Lab1213 : public QWidget
{
	Q_OBJECT

public:
	Lab1213(Controller& c,QWidget *parent = Q_NULLPTR);
	~Lab1213();
private:
	//Ui::Lab1213Class ui;
	Controller ctrl;
	std::vector<Tutorial> currentTutorialsInRepoList;
	QListWidget* repoList;
	QLineEdit* titleEdit;
	QLineEdit* presenterEdit;
	QLineEdit* minutesEdit;
	QLineEdit* secondsEdit;
	QLineEdit* likesEdit;
	QLineEdit* linkEdit;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* moveOneTutorialButton;
	QPushButton* playButton;

	QListWidget* watchlist;

	void initGUI();
	void populateRepoList();
	int getRepoListSelectedIndex();

	void connectSignalsAndSlots();

private slots:

	void listItemChanged();

	void addNewTutorial();
	void deleteTutorial();
	void updateTutorial();
	void moveTutorial();
	void playTutorial();

};