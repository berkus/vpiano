#include "octaverangewidget.h"
#include <QPainter>
#include <QImage>

OctaveRangeWidget::OctaveRangeWidget(QWidget *parent)
	: QWidget(parent)
	, start(0)
	, count(0)
{
	octave = QPixmap(":/octave.png");
	QImage src(":/octave.png");
	src.invertPixels();
	inverse = QPixmap::fromImage(src);
	setFixedSize(octave.width() * 9, octave.height());
}

void OctaveRangeWidget::paintOctave(QPainter *painter, bool highlight)
{
	if(highlight)
		painter->drawPixmap(0,0, inverse);
	else
		painter->drawPixmap(0,0, octave);
}

void OctaveRangeWidget::paintEvent(QPaintEvent *)
{
	QPainter painter;
	painter.begin(this);
	for(int i = 0; i < 9; i++)
	{
		bool hi = count && (i >= start) && (i < start + count);
		paintOctave(&painter, hi);
		painter.translate(octave.width(), 0);
	}
	painter.end();
}

void OctaveRangeWidget::highlightOctaves(int s, int c)
{
	start = s;
	count = c;
	update();
}
