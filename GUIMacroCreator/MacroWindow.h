#pragma once

#include <qwidget.h>
#include <QVBoxLayout>
#include <qlabel.h>
#include <qpushbutton.h>

#include "Macro.h"

class MacroWindow : public QWidget
{
public:
	MacroWindow(QWidget* parent = 0);
	~MacroWindow();

	void Play();
	void Record();
	void Save();
	void Load();
	void Clear();

private:
	QVBoxLayout* vBox;

	QPushButton* playButton;
	QPushButton* recordButton;
	QPushButton* saveButton;
	QPushButton* loadButton;
	QPushButton* clearButton;

	QLabel* statusLabel;

	Macro m_Macro;
};
