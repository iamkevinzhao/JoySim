#ifndef CPFDEV_EXPORT_H
#define CPFDEV_EXPORT_H

#ifdef _WIN32
#	ifdef CPFDev_EXPORTS
#		define API __declspec(dllexport)
#	else
#		define API __declspec(dllimport)
#	endif
#else
#	define API
#endif // WIN32

#endif // CPFDEV_EXPORT_H
