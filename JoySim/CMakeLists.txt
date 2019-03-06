add_executable(JoySim main.cpp)

target_link_libraries(
  JoySim
    JoySimDev
    Qt5::Widgets
)

install(TARGETS JoySim
  # IMPORTANT: Add the JoySim executable to the "export-set"
  EXPORT JoySimTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
