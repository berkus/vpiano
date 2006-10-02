#include <QWidget>

class QPixmap;

class KeyboardWidget : public QWidget
{
	Q_OBJECT

	public:
		KeyboardWidget(QWidget *parent = 0);

	protected:
		virtual void paintEvent(QPaintEvent *);

	public slots:
		void octaveSelected(int);
		void midiChannelSelected(int);

	private:
		QPixmap *whiteKey;
		QPixmap *blackKey;
};
