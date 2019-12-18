#include "MacroWindow.h"

MacroWindow::MacroWindow(QWidget* parent) : QWidget(parent)
{
	// Setup the verticalbox
	vBox = new QVBoxLayout(this);
	vBox->setSpacing(1);

	// Setup each button
	playButton = new QPushButton("Play", this);
	playButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	stopButton = new QPushButton("Stop", this);
	stopButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	recordButton = new QPushButton("Record", this);
	recordButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	saveButton = new QPushButton("Save", this);
	saveButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	loadButton = new QPushButton("Load", this);
	loadButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	clearButton = new QPushButton("Clear", this);
	clearButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	// Setup the label
	statusLabel = new QLabel(this);
	statusLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	statusLabel->setText(" ");
	statusLabel->setAlignment(Qt::AlignBottom | Qt::AlignCenter);

	// Attach each button to a function
	connect(playButton, &QPushButton::clicked, this, &MacroWindow::Play);
	connect(stopButton, &QPushButton::clicked, this, &MacroWindow::Stop);
	connect(recordButton, &QPushButton::clicked, this, &MacroWindow::Record);
	connect(saveButton, &QPushButton::clicked, this, &MacroWindow::Save);
	connect(loadButton, &QPushButton::clicked, this, &MacroWindow::Load);
	connect(clearButton, &QPushButton::clicked, this, &MacroWindow::Clear);

	// Add each button to the widget
	vBox->addWidget(playButton);
	vBox->addWidget(stopButton);
	vBox->addWidget(recordButton);
	vBox->addWidget(saveButton);
	vBox->addWidget(loadButton);
	vBox->addWidget(clearButton);
	vBox->addWidget(statusLabel);

	setLayout(vBox);
}

MacroWindow::~MacroWindow()
{
	delete vBox;
	delete playButton;
	delete stopButton;
	delete recordButton;
	delete saveButton;
	delete loadButton;
	delete clearButton;
	delete statusLabel;
}

void MacroWindow::Play()
{
	statusLabel->setText("Play");
}

void MacroWindow::Stop()
{
	statusLabel->setText("Stop");
}

void MacroWindow::Record()
{
	statusLabel->setText("Record");
}

void MacroWindow::Save()
{
	statusLabel->setText("Save");
}

void MacroWindow::Load()
{
	statusLabel->setText("Load");
}

void MacroWindow::Clear()
{
	statusLabel->setText("Clear");
}
