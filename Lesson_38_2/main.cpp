#include <QApplication>
#include <QPushButton>
#include <QWebEngineView>
#include <QPlainTextEdit>
#include <QHBoxLayout>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto* widget = new QWidget;
    auto* layout = new QHBoxLayout(widget);

    auto* editor = new QPlainTextEdit();
    auto* view = new QWebEngineView();

    editor->setMinimumSize(500, 800);
    view->setMinimumSize(500, 800);

    layout->addWidget(editor);
    layout->addWidget(view);

    widget->setWindowTitle("WebView html redactor");

    QObject::connect(editor, &QPlainTextEdit::textChanged, [&editor, &view]() {
        view->setHtml(editor->toPlainText());
    });

    widget->show();
    return QApplication::exec();
}
