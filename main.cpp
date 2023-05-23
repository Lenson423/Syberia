
#include "windows/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);

    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    if (settings.value("Language") == "Russian") {
        QLocale::setDefault(QLocale("ru_RU"));
    } else if (settings.value("Language") == "English") {
        QLocale::setDefault(QLocale("en_EN"));
    }

    MainWindow w;
    w.setFixedSize(880, 580);
    w.show();
    return a.exec();
}
