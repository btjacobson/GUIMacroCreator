#include "ListWidget.h"

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/qinputdialog.h>

ListWidget::ListWidget(QWidget* parent) : QWidget(parent)
{
	QVBoxLayout* vBox = new QVBoxLayout();
	vBox->setSpacing(10);

	QHBoxLayout* hBox = new QHBoxLayout(this);

	m_ListWidget = new QListWidget(this);
	m_ListWidget->addItem("Test1");

	m_AddButton = new QPushButton("Add", this);
	m_RenameButton = new QPushButton("Rename", this);
	m_RemoveButton = new QPushButton("Remove", this);
	m_RemoveAllButton = new QPushButton("Remove All", this);

	vBox->setSpacing(3);
	vBox->addStretch(1);

	vBox->addWidget(m_AddButton);
	vBox->addWidget(m_RenameButton);
	vBox->addWidget(m_RemoveButton);
	vBox->addWidget(m_RemoveAllButton);
	vBox->addStretch(1);

	hBox->addWidget(m_ListWidget);
	hBox->addSpacing(15);
	hBox->addLayout(vBox);

	connect(m_AddButton, &QPushButton::clicked, this, &ListWidget::AddItem);
	connect(m_RenameButton, &QPushButton::clicked, this, &ListWidget::RenameItem);
	connect(m_RemoveButton, &QPushButton::clicked, this, &ListWidget::RemoveItem);
	connect(m_RemoveAllButton, &QPushButton::clicked, this, &ListWidget::ClearItems);

	setLayout(hBox);
}

void ListWidget::AddItem()
{
	QString c_text = QInputDialog::getText(this, "Item", "Enter new item");
	QString s_text = c_text.simplified();

	if (!s_text.isEmpty())
	{
		m_ListWidget->addItem(s_text);
		int r = m_ListWidget->count() - 1;
		m_ListWidget->setCurrentRow(r);
	}
}

void ListWidget::RenameItem()
{

}

void ListWidget::RemoveItem()
{

}

void ListWidget::ClearItems()
{

}
