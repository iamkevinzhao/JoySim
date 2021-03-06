add_library(
  CPFDev
    SHARED
      export.h
      CPFDev.h
      CPFDev.cpp

      # cpf
      CPF/cpf.h
      CPF/cpf.cpp
      CPF/odom_fusion.h
      CPF/odom_fusion.cpp
      CPF/cpf_core.cpp
      CPF/cpf_core.h
      CPF/source.cpp
      CPF/source.h
      CPF/result.cpp
      CPF/result.h

      # common
      common/math.cpp
      common/math.h
      common/chi_square_table.cpp
      common/chi_square_table.h
      common/utils.cpp
      common/utils.h
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
