#include "keyboardwidget.h"
#include <QPainter>

KeyboardWidget::KeyboardWidget(QWidget *parent)
	: QWidget(parent)
{
	octaves = 3;
	whiteKey = QPixmap(":/white-key.png");
	blackKey = QPixmap(":/black-key.png");
	setMinimumHeight(whiteKey.height());
	setMinimumWidth(whiteKey.width() * 7 * octaves);
}

void KeyboardWidget::octaveSelected(int oct)
{
	qDebug("Selected octave %d", oct);
	emit highlightOctaves(oct, octaves);
}

void KeyboardWidget::midiChannelSelected(int ch)
{
	qDebug("Selected midi channel %d", ch);
}

void KeyboardWidget::paintOctave(QPainter *painter)
{
	int ww = whiteKey.width();
	int of = ww - blackKey.width() / 2;

	// paint 7 white keys
	for(int i = 0; i < 7; i++)
		painter->drawPixmap(i*ww, 0, whiteKey);
	// paint 5 black keys
	painter->drawPixmap(of+0*ww, 0, blackKey);
	painter->drawPixmap(of+1*ww, 0, blackKey);
	painter->drawPixmap(of+3*ww, 0, blackKey);
	painter->drawPixmap(of+4*ww, 0, blackKey);
	painter->drawPixmap(of+5*ww, 0, blackKey);
}

/* paint the keyboard */
void KeyboardWidget::paintEvent(QPaintEvent *)
{
	QPainter painter;
	painter.begin(this);
	for(int i = 0; i < octaves; i++)
	{
		paintOctave(&painter);
		painter.translate(whiteKey.width() * 7, 0);
	}
	painter.end();
}
