/**
 * @file mainwindow.h
 * @brief class MainWindow
 * @author xiangxw xiangxw5689@126.com
 * @date 2012-04-01
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mupdf-qt.h"
#include <QMainWindow>
#include <QLabel>

class QScrollArea;
class QToolBar;
class QAction;
class Page;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void openDocument();
	void previousPage();
	void nextPage();
	void zoomIn();
	void zoomOut();

private:
	void createActions();
	void createToolBars();
	void openPage(int index);

	QScrollArea *scrollArea;
	Page *label;
	QToolBar *toolBar;
	QAction *openAction;
	QAction *previousPageAction;
	QAction *nextPageAction;
	QAction *zoomInAction;
	QAction *zoomOutAction;
	MuPDF::Document *m_doc;
	MuPDF::Page *m_page;
	QString m_title;
	int m_numPages;
	int m_index;
	float m_scale;
};

class Page : public QLabel
{
public:
	Page(QWidget *parent = 0);
	void setPage(MuPDF::Page *page, float scale = 1.0f);
	void setScale(float scale);

protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

private:
	void updatePage();

	MuPDF::Page *m_page;
	float m_scale;
	QPointF m_pressPoint;
};

#endif // end MAINWINDOW_H
