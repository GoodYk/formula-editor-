#include "formulashow.h"
#include "formulaview.h"
#include <Python.h> // this is in <python-install-path>/include folder 


FormulaShow::FormulaShow(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	/*QString tmp = R"(sum_(i = 1)^n i^3 = ((n * (n + 1)) / 2)^2;
		int_0 ^ 1 f(x)dx;
	f^'(x) = alpha * x + beta * x^2 + delta * x^3;
		)";*/
	
	//plainTextEdit->setPlainText("tmp");


	d_view = new FormulaView(this);

	d_view->setGeometry(QRect(360, 300, 571, 261));
	d_view->setFontSize(16);
	d_view->setColors(false);
	
	refreshFormulaView();


	QHBoxLayout *layout1 = new QHBoxLayout;

	layout1->addWidget(plainTextEdit);
	layout1->addWidget(d_view);
	//setLayout(layout1);
//	layout1->addWidget(label);


}

FormulaShow::~FormulaShow()
{
}


void FormulaShow::on_plainTextEdit_textChanged()
{
	refreshFormulaView();
	qstrtommls = QString::fromStdString(strtommls);
	plainTextEdit2->setPlainText(qstrtommls);
}

void FormulaShow::on_plainTextEdit2_textChanged()
{
	d_view->setFormula(plainTextEdit2->toPlainText());
}


void FormulaShow::refreshFormulaView()
{
	/*if (parse(plainTextEdit->toPlainText().toStdString(), strtommls))
		d_view->setFormula(QString::fromStdString(strtommls));*/
	auto strlist = plainTextEdit->toPlainText().split('\n');
#if 0
#include <qdebug.h>
	
//	qDebug() << strlist;

#endif
	strtommls=R"(<math><mtable>)";
	string strtomml;
	for (auto i : strlist)
	{
		
		//strtommls.append("<mtr><mtd>");
		//auto iStr = i.split('\'');
	/*	for (auto j = 0; j < iStr.length() - 1; j++)
		{
			strtommls.append("<msup>");
			if (parse(iStr[j].toStdString(), strtomml))
			{
				strtommls.append(strtomml);
			}
			strtommls.append("</msup>");
		}*/
		if (parse(i.toStdString(), strtomml))
		{
			strtommls.append(strtomml);
		}
		//strtommls.append("</mtr></mtd>");	

	}

	strtommls.append("</mtable></math>");
#if 0

	strtommls=R"(<math xmlns="http://www.w3.org/1998/Math/MathML"><mi>a</mi><mi>2</mi><mi>b</mi><mspace linebreak="newline"/><mo>2</mo><mi>c</mi></math>)";
	qDebug() << QString::fromStdString(strtommls);
#endif

}




bool FormulaShow::parse(const string &str, string &result)
{
	Py_NoSiteFlag = 1;

	Py_Initialize();

	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('.\')");

	if (!Py_IsInitialized())
	{
		return false;
	}


	string filename = "asciimathmll";
	string methodname = "parse";
	PyObject *pyFileName = PyString_FromString(filename.c_str());
	PyErr_Clear();
	PyObject *pyMod = PyImport_Import(pyFileName); //打包时调用失败,返回为空  
	if (pyMod) //if OK  
	{
		//load function  
		PyObject *pyFunc = PyObject_GetAttrString(pyMod, methodname.c_str());
		if (pyFunc && PyCallable_Check(pyFunc))
		{
			PyObject *pyParams = PyTuple_New(1);
			PyObject *pyUserid = PyString_FromString(str.c_str());
			//	PyObject *pyPassword = PyString_FromString(password.c_str());
			PyTuple_SetItem(pyParams, 0, pyUserid);
			//	PyTuple_SetItem(pyParams, 1, pyPassword);
			// ok, call the function    
			PyObject *pyResult = PyObject_CallObject(pyFunc, pyParams);

			if (pyResult)
			{
				result = PyString_AsString(pyResult);

				// last fini!    
				Py_Finalize();
				return true;
			}
		}
	}
	// last fini!    
	Py_Finalize();
	return false;
}





