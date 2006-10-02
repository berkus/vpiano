#include "mainwindow.h"
#include "keyboardwidget.h"
#include <QLayout>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QSignalMapper>

VPiano::VPiano() : QMainWindow()
{
	QWidget *central = new QWidget(this);
	QVBoxLayout *vb = new QVBoxLayout;
	QHBoxLayout *octaves = new QHBoxLayout;

	QLabel *oct = new QLabel(tr("Octave"), central);
	octaves->addWidget(oct);

    QSignalMapper *octaveSignalMapper = new QSignalMapper(this);

	for(int i = 0; i < 9; i++)
	{
		QString title;
		title.setNum(i);
		QPushButton *o = new QPushButton(title, central);
		o->sizePolicy().setHorizontalPolicy(QSizePolicy::Maximum);
// 		qDebug("o sizehint %dx%d", o->sizeHint().width(), o->sizeHint().height());
		QString shortcut;
		shortcut.setNum(i+1);
		o->setShortcut(QKeySequence(QString("F") + shortcut));
		octaves->addWidget(o);

		connect(o, SIGNAL(clicked()), octaveSignalMapper, SLOT(map()));
		octaveSignalMapper->setMapping(o, i);
	}

	QSpinBox *channel = new QSpinBox(central);
	channel->setPrefix(tr("Ch ", "Midi Channel number"));
	channel->setMinimum(0);
	channel->setMaximum(127);
	channel->setValue(0); // TODO: read prev value from config
	channel->setToolTip(tr("Select MIDI channel number to send messages to"));
	octaves->addWidget(channel);

	vb->addLayout(octaves);

	QHBoxLayout *keyarea = new QHBoxLayout;

	KeyboardWidget *kw = new KeyboardWidget(central);
	keyarea->addWidget(kw);

	vb->addLayout(keyarea);

	central->setLayout(vb);
	setCentralWidget(central);

	connect(octaveSignalMapper, SIGNAL(mapped(int)), kw, SLOT(octaveSelected(int)));
	connect(channel, SIGNAL(valueChanged(int)), kw, SLOT(midiChannelSelected(int)));
}

VPiano::~VPiano()
{
}
