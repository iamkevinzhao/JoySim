cmake_minimum_required(VERSION 2.8)
project(JoySim CXX)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-D_USE_MATH_DEFINES)

set(JOYSIM_MAJOR_VERSION 1)
set(JOYSIM_MINOR_VERSION 2)
set(JOYSIM_PATCH_VERSION 0)
set(JOYSIM_VERSION
  ${JOYSIM_MAJOR_VERSION}.${JOYSIM_MINOR_VERSION}.${JOYSIM_PATCH_VERSION})

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH
  "Installation directory for header files")
if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/CMake/JoySim)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH
  "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

# set up include-directories
include_directories(
  "${PROJECT_SOURCE_DIR}"   # to find JoySimDev/JoySimDev.h
  "${PROJECT_BINARY_DIR}")  # to find JoySimDev/config.h

find_package(Qt5Widgets REQUIRED)
find_package(Eigen3)
include_directories(${Eigen3_INCLUDE_DIRS})

# Add sub-directories
add_subdirectory(JoySimDev)
add_subdirectory(JoySim)
add_subdirectory(CPFDev)

# The interesting stuff goes here
# ===============================

# Add all targets to the build-tree export set
export(TARGETS JoySimDev JoySim CPFDev
  FILE "${PROJECT_BINARY_DIR}/JoySimTargets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE JoySim)

# Create the JoySimConfig.cmake and JoySimConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
   "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(JoySimConfig.cmake.in
  "${PROJECT_BINARY_DIR}/JoySimConfig.cmake" @ONLY)
# ... for the install tree
set(CONF_INCLUDE_DIRS "\${JOYSIM_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(JoySimConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/JoySimConfig.cmake" @ONLY)
# ... for both
configure_file(JoySimConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/JoySimConfigVersion.cmake" @ONLY)

# Install the JoySimConfig.cmake and JoySimConfigVersion.cmake
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/JoySimConfig.cmake"
  "${PROJECT_BINARY_DIR}/JoySimConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# Install the export set for use with the install-tree
install(EXPORT JoySimTargets DESTINATION
  "${INSTALL_CMAKE_DIR}" COMPONENT dev)
