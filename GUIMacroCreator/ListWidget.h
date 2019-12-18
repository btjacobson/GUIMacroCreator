#pragma once

#include <QtWidgets/qwidget.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlistwidget.h>

class ListWidget : public QWidget
{

	Q_OBJECT

public:
	ListWidget(QWidget* parent = 0);
	
private slots:
	void AddItem();
	void RenameItem();
	void RemoveItem();
	void ClearItems();

private:
	QListWidget* m_ListWidget;
	QPushButton* m_AddButton;
	QPushButton* m_RenameButton;
	QPushButton* m_RemoveButton;
	QPushButton* m_RemoveAllButton;
};

