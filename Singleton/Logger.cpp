#include "Logger.h"



#include <iostream>
#include <ostream>
#include <stdexcept>
//Eager instance initialization
//Logger Logger::m_Instance ;
Logger::Logger() {
	fopen_s(&m_pStream, "applog.txt", "w") ;
	if(!m_pStream) {
		throw std::runtime_error{"Could not open log file for writing"} ;
	}
	std::cout << __FUNCSIG__ << '\n' ;
	//Lazy instance destruction
	/*std::atexit([]() {
		delete m_pInstance ;
	}) ;*/
}

Logger& Logger::GetInstance() {
	//Meyer's singleton
	static Logger instance ;
	return instance ;

	//Lazy instance
	//if(!m_pInstance) {
	//	m_pInstance = new Logger{} ;
	//}
	//return *m_pInstance ;
}

Logger::~Logger() {
	fclose(m_pStream) ;
	std::cout << __FUNCSIG__ << '\n' ;
}

void Logger::Log(const std::string& message) {
	fprintf_s(m_pStream, "[%s]%s\n", m_Tag.c_str(),
		message.c_str()) ;
	fflush(m_pStream) ;
}

void Logger::SetTag(std::string tag) {
	m_Tag = std::move(tag) ;
}
