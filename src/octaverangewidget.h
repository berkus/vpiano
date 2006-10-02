#include <QWidget>
#include <QPixmap>

class OctaveRangeWidget : public QWidget
{
	Q_OBJECT

	public:
		OctaveRangeWidget(QWidget *parent = 0);

	protected:
		virtual void paintEvent(QPaintEvent *);
		void paintOctave(QPainter *painter, bool highlight);

	public slots:
		void highlightOctaves(int start, int count);

	private:
		QPixmap octave;
		QPixmap inverse;
		int start, count;
};
