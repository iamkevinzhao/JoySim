add_library(
  CPFDev
    SHARED
      CPFDev.h
      CPFDev.cpp

      # cpf
      CPF/cpf.h
      CPF/cpf.cpp
      CPF/odom_fusion.h
      CPF/odom_fusion.cpp

      # math
      common/math.cpp
      common/math.h
)

target_link_libraries(
  CPFDev
    # Eigen3::Eigen
)

set_target_properties(CPFDev PROPERTIES
  PUBLIC_HEADER "CPFDev.h;${CMAKE_CURRENT_BINARY_DIR}/config.h")

install(TARGETS CPFDev
  # IMPORTANT: Add the CPFDev library to the "export-set"
  EXPORT JoySimTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/CPFDev"
    COMPONENT dev)
