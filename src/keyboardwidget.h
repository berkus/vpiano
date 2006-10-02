#include <QWidget>
#include <QPixmap>

class KeyboardWidget : public QWidget
{
	Q_OBJECT

	public:
		KeyboardWidget(QWidget *parent = 0);

	protected:
		virtual void paintEvent(QPaintEvent *);
		void paintOctave(QPainter *painter);

	signals:
		void highlightOctaves(int start, int count);

	public slots:
		void octaveSelected(int);
		void midiChannelSelected(int);

	private:
		QPixmap whiteKey;
		QPixmap blackKey;
		int octaves;
};
