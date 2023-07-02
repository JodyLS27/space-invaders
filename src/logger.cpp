#include <logger.hpp>


void logger::Logger::print_log(std::string msg)
{
	msg += "\n";
	std::cout << msg;
}

void logger::Logger::debug_log(std::string msg)
{
	msg += "\n";

#if defined(_WIN32)
	OutputDebugStringA(msg.c_str());
#endif
}