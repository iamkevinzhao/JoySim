set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

configure_file(config.h.in "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)

add_library(
  JoySimDev
    SHARED
      JoySimDev.cpp
      JoySimDev.h
      config.h.in

      # widgets
      widgets/widget_base.cpp
      widgets/widget_base.h
      widgets/playground.cpp
      widgets/playground.h
)

target_link_libraries(
  JoySimDev
    Qt5::Widgets
)

set_target_properties(JoySimDev PROPERTIES
  PUBLIC_HEADER "JoySimDev.h;${CMAKE_CURRENT_BINARY_DIR}/config.h")

install(TARGETS JoySimDev
  # IMPORTANT: Add the JoySimDev library to the "export-set"
  EXPORT JoySimTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/JoySimDev"
    COMPONENT dev)
