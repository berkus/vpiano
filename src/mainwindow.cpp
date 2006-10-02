#include "mainwindow.h"
#include "keyboardwidget.h"
#include <QLayout>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QCheckBox>
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
		o->setFixedSize(fontMetrics().width(title)*6, o->height());
		QString shortcut;
		shortcut.setNum(i+1);
		o->setShortcut(QKeySequence(QString("F") + shortcut));
		octaves->addWidget(o);

		connect(o, SIGNAL(clicked()), octaveSignalMapper, SLOT(map()));
		octaveSignalMapper->setMapping(o, i);
	}

	QSlider *velocity = new QSlider(Qt::Horizontal, central);
	velocity->setMinimum(1);
	velocity->setMaximum(127);
	velocity->setValue(96); // TODO: read prev value from config
	velocity->setToolTip(tr("Velocity"));
	octaves->addWidget(velocity);

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

	QVBoxLayout *rightside = new QVBoxLayout;

	QSlider *pitchWheel = new QSlider(Qt::Vertical, central);
	pitchWheel->setMinimum(-64);
	pitchWheel->setMaximum(63);
	pitchWheel->setValue(0); // TODO: read prev value from config
	pitchWheel->setToolTip(tr("Pitch wheel"));

	rightside->addWidget(pitchWheel);

	QCheckBox *porta = new QCheckBox(central);
	porta->setToolTip(tr("Enable portamento"));

	rightside->addWidget(porta);
	keyarea->addLayout(rightside);

	vb->addLayout(keyarea);

	central->setLayout(vb);
	setCentralWidget(central);
	setWindowTitle(tr("Virtual MIDI keyboard"));

	// TODO: connect pitchWheel
	connect(octaveSignalMapper, SIGNAL(mapped(int)), kw, SLOT(octaveSelected(int)));
	connect(channel, SIGNAL(valueChanged(int)), kw, SLOT(midiChannelSelected(int)));
}

VPiano::~VPiano()
{
}
