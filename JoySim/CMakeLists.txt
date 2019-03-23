set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(
  JoySim
    main.cpp
    main_window.cpp
    main_window.h
    main_window.ui
)

target_link_libraries(
  JoySim
    JoySimDev
    CPFDev
    Qt5::Widgets
)

install(TARGETS JoySim
  # IMPORTANT: Add the JoySim executable to the "export-set"
  EXPORT JoySimTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
