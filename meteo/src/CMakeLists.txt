qt5_add_resources(meteo_SRCS resources.qrc)
add_executable(meteo main.cpp ${meteo_SRCS})
target_link_libraries(meteo Qt5::Qml Qt5::Gui)

