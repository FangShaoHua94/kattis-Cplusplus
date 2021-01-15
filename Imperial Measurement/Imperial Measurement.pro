TEMPLATE = app

QT += qml quick
CONFIG += c++11

RESOURCES += Imperial Measurement.qrc

qml.files = Imperial Measurement.qml

launch_modeall {
	CONFIG(debug, debug|release) {
	    DESTDIR = debug
	} else {
	    DESTDIR = release
	}
}

SOURCES += Imperial Measurement.cpp \
           main.cpp
