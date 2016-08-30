#ifndef FORMULASHOW_H
#define FORMULASHOW_H

#include <QtWidgets>
#include "ui_formulashow.h"

#include <string>
using namespace std;

class FormulaView;

class FormulaShow : public QWidget, public Ui::FormulaShowClass
{
	Q_OBJECT

public:
	FormulaShow(QWidget *parent = 0);
	~FormulaShow();

	bool parse(const string &str, string &result);
	string strtommls;
	QString qstrtommls;

private:
	FormulaView *d_view;

	private slots:
	void on_plainTextEdit_textChanged();
	void refreshFormulaView();
	void on_plainTextEdit2_textChanged();



};

#endif // FORMULASHOW_H
