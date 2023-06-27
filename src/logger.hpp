#pragma once

#include <string>
#include <iostream>

#if defined (WIN32)
#include <Windows.h>
#endif

namespace logger
{
struct Logger
{
	/////////////////////////////////////////////////////////
	/// This function will print your log message to the terminal.
	/// 
	/// @param msg: String parameter containing an output message.
	/// 
	/// @return Type: void
	/////////////////////////////////////////////////////////
	void print_log(std::string msg);

	/////////////////////////////////////////////////////////
	/// This function will print your log message to the debug window based on your OS.
	/// 
	/// @param msg: String parameter containing an output message.
	/// 
	/// @return Type: void
	/////////////////////////////////////////////////////////
	void debug_log(std::string msg);
};
}