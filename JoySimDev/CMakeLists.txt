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

      # wm
      wm/pose.cpp
      wm/pose.h

      # widgets
      widgets/widget_base.cpp
      widgets/widget_base.h
      widgets/playground.cpp
      widgets/playground.h
      widgets/robot.cpp
      widgets/robot.h
      widgets/robo_traj.cpp
      widgets/robo_traj.h
      widgets/odom_config.cpp
      widgets/odom_config.h

      # sim
      sim/simulator.cpp
      sim/simulator.h
      sim/sim_config.cpp
      sim/sim_config.h
      sim/sim_state.cpp
      sim/sim_state.h
      sim/engine.cpp
      sim/engine.h
      sim/robot.cpp
      sim/robot.h
      sim/odometer.cpp
      sim/odometer.h
      sim/robot_base.cpp
      sim/robot_base.h
      sim/engine_config.cpp
      sim/engine_config.h
      sim/odom_config.cpp
      sim/odom_config.h
      sim/odometry.cpp
      sim/odometry.h
      sim/odom_primitive.cpp
      sim/odom_primitive.h
      sim/trajectory_estimate.cpp
      sim/trajectory_estimate.h

      # viz
      viz/visualizer.cpp
      viz/visualizer.h
      viz/viz_config.cpp
      viz/viz_config.h
)

target_link_libraries(
  JoySimDev
    Qt5::Widgets
    # Eigen3::Eigen
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
