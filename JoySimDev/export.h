#ifndef JOYSIMDEV_EXPORT_H
#define JOYSIMDEV_EXPORT_H

#ifdef _WIN32
#	ifdef JoySimDev_EXPORTS
#		define API __declspec(dllexport)
#	else
#		define API __declspec(dllimport)
#	endif
#else
#	define API
#endif // WIN32

#endif // JOYSIMDEV_EXPORT_H
