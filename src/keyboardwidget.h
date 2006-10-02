#include <QWidget>

class QPixmap;

class KeyboardWidget : public QWidget
{
	Q_OBJECT

	public:
		KeyboardWidget(QWidget *parent = 0);

	protected:
		virtual void paintEvent(QPaintEvent *);
		void paintOctave(QPainter *painter);

	public slots:
		void octaveSelected(int);
		void midiChannelSelected(int);

	private:
		QPixmap *whiteKey;
		QPixmap *blackKey;
		int octaves;
};
