#include "Lab1213.h"
#include <qmessagebox.h>
#include <qdesktopservices.h>
#include <qurl.h>
Lab1213::Lab1213(Controller& c,QWidget *parent): ctrl(c),QWidget(parent)
{
	this->initGUI();
	this->currentTutorialsInRepoList = ctrl.getRepo().getTutorials();
	this->populateRepoList();
}

Lab1213::~Lab1213()
{
}

void Lab1213::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };


	// Prepare left side components - vertical layout with: 
	// - list
	// - form layout with the tutorial data
	// - grid layout with buttons: add, delete, update

	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	this->repoList = new QListWidget{};
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	QWidget* tutorialDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ tutorialDataWidget };
	this->titleEdit = new QLineEdit{};
	this->presenterEdit = new QLineEdit{};
	this->minutesEdit = new QLineEdit{};
	this->secondsEdit = new QLineEdit{};
	this->likesEdit = new QLineEdit{};
	this->linkEdit = new QLineEdit{};
	
	formLayout->addRow("&Title", titleEdit);
	formLayout->addRow("&Presenter", presenterEdit);
	formLayout->addRow("&Minutes", minutesEdit);
	formLayout->addRow("&Seconds", secondsEdit);
	formLayout->addRow("&Likes", likesEdit);
	formLayout->addRow("&Link", linkEdit);

	//buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton{ "Add" };
	this->deleteButton = new QPushButton{ "Delete" };
	this->updateButton = new QPushButton{ "Update" };

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 0, 2);

	leftSide->addWidget(new QLabel{ "All tutorials" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(tutorialDataWidget);
	leftSide->addWidget(buttonsWidget);

	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->moveOneTutorialButton = new QPushButton{ ">> Move tutorial" };
	this->playButton = new QPushButton{ "Play" };
	this->likeButton = new QPushButton{ "Like" };
	QWidget* upperPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	vLayoutUpperPart->addWidget(this->moveOneTutorialButton);
	vLayoutUpperPart->addWidget(this->playButton);
	vLayoutUpperPart->addWidget(this->likeButton);
	vLayoutMiddle->addWidget(upperPart);

	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };

	this->watchlist = new QListWidget{};
	rightSide->addWidget(new QLabel{ "WatchList" });
	rightSide->addWidget(watchlist);

	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	this->connectSignalsAndSlots();
}

void Lab1213::populateRepoList()
{
	if (this->repoList->count() > 0)
		this->repoList->clear();

	for (auto tutorial : this->currentTutorialsInRepoList)
	{
		QString itemInList = QString::fromStdString(tutorial.getTitle() + "-" + tutorial.getPresenter() + "-" + tutorial.getLink());
		QListWidgetItem* item3 = new QListWidgetItem(itemInList);
		this->repoList->addItem(item3);

	}

	if (this->currentTutorialsInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}

int Lab1213::getRepoListSelectedIndex()
{
	if (this->repoList->count() > 0)
		return -1;

	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();

	if (index.size() == 0)
	{
		this->titleEdit->clear();
		this->presenterEdit->clear();
		this->minutesEdit->clear();
		this->secondsEdit->clear();
		this->likesEdit->clear();
		this->linkEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;

}

void Lab1213::connectSignalsAndSlots()
{
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewTutorial()));

	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteTutorial()));

	QObject::connect(this-> updateButton, SIGNAL(clicked()), this, SLOT(updateTutorial()));

	QObject::connect(this->moveOneTutorialButton, SIGNAL(clicked()), this, SLOT(moveTutorial()));

	QObject::connect(this->playButton, SIGNAL(clicked()), this, SLOT(playTutorial()));

	QObject::connect(this->likeButton, SIGNAL(clicked()), this, SLOT(likeTutorial()));
}

void Lab1213::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Tutorial> tutorials = this->currentTutorialsInRepoList;

	if (idx >= tutorials.size())
		return;

	Tutorial t = tutorials[idx];

	this->titleEdit->setText(QString::fromStdString(t.getTitle()));
	this->presenterEdit->setText(QString::fromStdString(t.getPresenter()));
	this->minutesEdit->setText(QString::fromStdString(to_string(t.getMinutes())));
	this->secondsEdit->setText(QString::fromStdString(to_string(t.getSeconds())));
	this->likesEdit->setText(QString::fromStdString(to_string(t.getLikes())));
	this->linkEdit->setText(QString::fromStdString(t.getLink()));
}


void Lab1213::addNewTutorial()
{
	std::string title = this->titleEdit->text().toStdString();
	std::string presenter = this->presenterEdit->text().toStdString();
	std::string minutes = this->minutesEdit->text().toStdString();
	std::string seconds = this->secondsEdit->text().toStdString();
	std::string likes = this->likesEdit->text().toStdString();
	std::string link = this->linkEdit->text().toStdString();

	try
	{
		this->ctrl.addTutorialToRepo(title, presenter, std::stoi(minutes), std::stoi(seconds), std::stoi(likes), link);

		this->currentTutorialsInRepoList = this->ctrl.getRepo().getTutorials();

		this->populateRepoList();
	}
	catch (TutorialExceptions& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch(DuplicateException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void Lab1213::deleteTutorial()
{
	std::string link = this->linkEdit->text().toStdString();
	try
	{
		this->ctrl.delTutorialRepo(link);

		this->currentTutorialsInRepoList = this->ctrl.getRepo().getTutorials();

		this->populateRepoList();
	}
	catch (DeleteException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void Lab1213::updateTutorial()
{
	std::string title = this->titleEdit->text().toStdString();
	std::string presenter = this->presenterEdit->text().toStdString();
	std::string minutes = this->minutesEdit->text().toStdString();
	std::string seconds = this->secondsEdit->text().toStdString();
	std::string likes = this->likesEdit->text().toStdString();
	std::string link = this->linkEdit->text().toStdString();

	try
	{
		this->ctrl.updateTutorialRepo(title, presenter, std::stoi(minutes), std::stoi(seconds), std::stoi(likes), link);

		this->currentTutorialsInRepoList = this->ctrl.getRepo().getTutorials();

		this->populateRepoList();
	}
	catch (UpdateException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}

}

void Lab1213::moveTutorial()
{
	this->watchlist->addItem(this->repoList->takeItem(repoList->currentRow()));
}

void Lab1213::playTutorial()
{
	QListWidgetItem* item = this->repoList->currentItem();
	string text = item->text().toStdString();
	int pos = text.find("http");
	string link;
	for (int i = pos; i < text.size(); ++i)
	{
		link += text[i];
	}
	QDesktopServices::openUrl(QUrl(QString::fromStdString(link)));
}

void Lab1213::likeTutorial()
{
	QListWidgetItem* item = this->repoList->currentItem();
	string text = item->text().toStdString();
	int pos = text.find("http");
	string link;
	for (int i = pos; i < text.size(); ++i)
	{
		link += text[i];
	}
	this->ctrl.updateLikesTutorialRepo(link);
}
