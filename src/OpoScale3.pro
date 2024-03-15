TEMPLATE = app

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    maindialog.cpp \
    oposcalesdk.cpp \
    oposdk/cpp/OnePlusOneAndroidSDK/Printer/label_printer.cpp \
    oposdk/cpp/OnePlusOneAndroidSDK/Printer/pos_printer.cpp \
    oposdk/cpp/OnePlusOneAndroidSDK/ScalesOS/scales_s_d_k.cpp \
    oposdk/cpp/OnePlusOneAndroidSDK/ScalesOS/weight_info.cpp \
    oposdk/cpp/OnePlusOneAndroidSDK/build_config.cpp \
    oposdk/cpp/OnePlusOneAndroidSDK/o_p_o_util.cpp \
    oposdk/cpp/OnePlusOneAndroidSDK/u_s_b_interface.cpp \
    oposdk/cpp/android/content/broadcast_receiver.cpp \
    oposdk/cpp/android/content/context.cpp \
    oposdk/cpp/android/content/intent.cpp \
    oposdk/cpp/android/graphics/bitmap.cpp \
    oposdk/cpp/android/os/parcel.cpp \
    oposdk/cpp/android/os/parcelable.cpp \
    oposdk/cpp/java/io/file.cpp \
    oposdk/cpp/java/lang/string.cpp \
    weightdata.cpp

HEADERS += \
    maindialog.h \
    oposcalesdk.h \
    oposdk/cpp/OnePlusOneAndroidSDK/Printer/label_printer.hpp \
    oposdk/cpp/OnePlusOneAndroidSDK/Printer/pos_printer.hpp \
    oposdk/cpp/OnePlusOneAndroidSDK/ScalesOS/scales_s_d_k.hpp \
    oposdk/cpp/OnePlusOneAndroidSDK/ScalesOS/weight_info.hpp \
    oposdk/cpp/OnePlusOneAndroidSDK/build_config.hpp \
    oposdk/cpp/OnePlusOneAndroidSDK/o_p_o_util.hpp \
    oposdk/cpp/OnePlusOneAndroidSDK/u_s_b_interface.hpp \
    oposdk/cpp/android/content/broadcast_receiver.hpp \
    oposdk/cpp/android/content/context.hpp \
    oposdk/cpp/android/content/intent.hpp \
    oposdk/cpp/android/graphics/bitmap.hpp \
    oposdk/cpp/android/os/parcel.hpp \
    oposdk/cpp/android/os/parcelable.hpp \
    oposdk/cpp/java/io/file.hpp \
    oposdk/cpp/java/lang/string.hpp \
    oposdk/gni/common/interface_proxy.h \
    oposdk/gni/common/logger.h \
    oposdk/gni/common/scoped_local_ref.h \
    oposdk/gni/gni.h \
    oposdk/gni/gni.hpp \
    oposdk/gni/object.hpp \
    weightdata.h

FORMS += \
    maindialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += $$PWD/libs/arm64-v8a/libgni_static.a
INCLUDEPATH += $$PWD/libs/arm64-v8a/

ANDROID_EXTRA_LIBS += $$PWD/libs/arm64-v8a/liboposcalessdk.so
ANDROID_LIB_DEPENDENCIES += $$PWD/libs/arm64-v8a/liboposcalessdk.so \
ANDROID_BUNDLED_JAR_DEPENDENCIES += $$PWD/libs/opoandroidsdk_v2.016.jar
ANDROID_PACKAGE_SOURCE_DIR = $$PWD

INCLUDEPATH += $$PWD/libs/opoandroidsdk_v2.016.jar
DEPENDPATH += $$PWD/libs/opoandroidsdk_v2.016.jar
INCLUDEPATH += $$PWD/oposdk
INCLUDEPATH += $$PWD/oposdk/cpp

RESOURCES += \
    resource.qrc
