#include "Logger.h"
void Init() {
	Logger &lg = Logger::GetInstance() ;
	lg.Log("Initializing") ;
}
int main() {
	Logger &lg = Logger::GetInstance() ;
	lg.Log("Application has started") ;
	Init() ;
	lg.Log("Application is terminating") ;
}
