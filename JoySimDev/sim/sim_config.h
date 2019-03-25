#ifndef SIM_SIM_CONFIG_H
#define SIM_SIM_CONFIG_H

#include <JoySimDev/export.h>
#include <JoySimDev/config.h>
#include <QString>


namespace sim {
struct API SimConfig
{
  int playground_width = 400;
  int playground_height = 400;
  bool construct_viz = false;

  bool ReadINI(const QString& name = JOYSIM_INI_FILE_NAME);
  SimConfig();
};
}

#endif // SIM_SIM_CONFIG_H
