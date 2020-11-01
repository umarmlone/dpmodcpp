#pragma once
#include <cstdio>
#include <string>

class Logger
{
	FILE *m_pStream{} ;
	std::string m_Tag{} ;
	Logger() ;
	//Eager instance
	//static Logger m_Instance ;
	
	//Lazy instance
	//inline static Logger *m_pInstance{} ;
public:
	Logger(const Logger &) = delete ;
	Logger & operator=(const Logger &) = delete; 
	static Logger & GetInstance() ;
	~Logger() ;
	void Log(const std::string &message) ;
	void SetTag(std::string tag) ;
};

