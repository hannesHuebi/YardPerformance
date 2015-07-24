TEMPLATE = aux
TARGET = YardPerformace

RESOURCES += YardPerformace.qrc

QML_FILES += $$files(*.qml,true) \
             $$files(*.js,true)

CONF_FILES +=  YardPerformace.apparmor \
               YardPerformace.desktop \
               YardPerformace.png

AP_TEST_FILES += tests/autopilot/run \
                 $$files(tests/*.py,true)

OTHER_FILES += $${CONF_FILES} \
               $${QML_FILES} \
               $${AP_TEST_FILES}\
               $$files(*.csv,true) \
                resources/2015Jul19_0.csv

#specify where the qml/js files are installed to
qml_files.path = /YardPerformace
qml_files.files += $${QML_FILES}

#specify where the config files are installed to
config_files.path = /YardPerformace
config_files.files += $${CONF_FILES}

INSTALLS+=config_files qml_files

