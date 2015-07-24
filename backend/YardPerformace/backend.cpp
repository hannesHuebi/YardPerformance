#include <QtQml>
#include <QtQml/QQmlContext>
#include "backend.h"
#include "mytype.h"
#include "parsecsv.h"


void BackendPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("YardPerformace"));

    qmlRegisterType<MyType>(uri, 1, 0, "MyType");
    qmlRegisterType<ParseCSV>(uri, 1, 0, "ParseCSV");
}

void BackendPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQmlExtensionPlugin::initializeEngine(engine, uri);
}

