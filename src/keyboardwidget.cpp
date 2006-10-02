#include "keyboardwidget.h"
#include <QPixmap>
#include <QPainter>

KeyboardWidget::KeyboardWidget(QWidget *parent)
	: QWidget(parent)
{
	whiteKey = new QPixmap(":/white-key.png");
	blackKey = new QPixmap(":/black-key.png");
}

void KeyboardWidget::octaveSelected(int oct)
{
	qDebug("Selected octave %d", oct);
}

void KeyboardWidget::midiChannelSelected(int ch)
{
	qDebug("Selected midi channel %d", ch);
}

/* paint the keyboard */
void KeyboardWidget::paintEvent(QPaintEvent *e)
{
	int ww = whiteKey->width();
	int of = ww - blackKey->width() / 2;

	QPainter painter;
	painter.begin(this);
	// paint 7 white keys
	for(int i = 0; i < 7; i++)
		painter.drawPixmap(i*ww, 0, *whiteKey);
	// paint 5 black keys
	painter.drawPixmap(of+0*ww, 0, *blackKey);
	painter.drawPixmap(of+1*ww, 0, *blackKey);
	painter.drawPixmap(of+3*ww, 0, *blackKey);
	painter.drawPixmap(of+4*ww, 0, *blackKey);
	painter.drawPixmap(of+5*ww, 0, *blackKey);
	painter.end();
}
