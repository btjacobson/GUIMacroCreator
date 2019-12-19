#include "MacroWindow.h"

MacroWindow::MacroWindow(QWidget* parent) : QWidget(parent)
{
	short buttonWidth = 175;
	short buttonHeight = 28;

	// Setup the verticalbox
	vBox = new QVBoxLayout(this);
	vBox->setSpacing(1);
	vBox->setAlignment(Qt::AlignCenter);

	// Setup each button
	playButton = new QPushButton("Play", this);
	playButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	playButton->setFixedSize(QSize(buttonWidth, buttonHeight));

	recordButton = new QPushButton("Record", this);
	recordButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	recordButton->setFixedSize(QSize(buttonWidth, buttonHeight));

	saveButton = new QPushButton("Save", this);
	saveButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	saveButton->setFixedSize(QSize(buttonWidth, buttonHeight));

	loadButton = new QPushButton("Load", this);
	loadButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	loadButton->setFixedSize(QSize(buttonWidth, buttonHeight));

	clearButton = new QPushButton("Clear", this);
	clearButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	clearButton->setFixedSize(QSize(buttonWidth, buttonHeight));

	// Setup the label
	statusLabel = new QLabel(this);
	statusLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	statusLabel->setText(" ");
	statusLabel->setAlignment(Qt::AlignBottom | Qt::AlignLeft);

	// Attach each button to a function
	connect(playButton, &QPushButton::clicked, this, &MacroWindow::Play);
	connect(recordButton, &QPushButton::clicked, this, &MacroWindow::Record);
	connect(saveButton, &QPushButton::clicked, this, &MacroWindow::Save);
	connect(loadButton, &QPushButton::clicked, this, &MacroWindow::Load);
	connect(clearButton, &QPushButton::clicked, this, &MacroWindow::Clear);

	// Add each button to the widget
	vBox->addWidget(playButton);
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
	delete recordButton;
	delete saveButton;
	delete loadButton;
	delete clearButton;
	delete statusLabel;
}

void MacroWindow::Play()
{
	statusLabel->setText("Play");

	m_Macro.Execute();
}

void MacroWindow::Record()
{
	statusLabel->setText("Press RMB to stop recording");

	bool hasFinished = false;
	double elapsedTime = 0;

	std::thread timeThread(&Timer::StartTime, &m_Macro.timer);

	while (!hasFinished)
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (!m_Macro.timer.recordingTime)
			{
				m_Macro.timer.recordingTime = true;
			}
			else
			{
				elapsedTime = m_Macro.timer.ResetTime();
			}

			POINT p;
			GetCursorPos(&p);
			m_Macro.AddPoint(p, elapsedTime);
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_RBUTTON))
		{
			hasFinished = true;
			m_Macro.timer.recordingTime = false;
		}
	}
	timeThread.detach();

	statusLabel->setText("Successfully recorded points");
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
	m_Macro.Clear();
	statusLabel->setText("Macro Cleared");
}
