#include "singleton.h"


void Singleton::setUsername(std::string username){ _username =username; }
void Singleton::setPassword(std::string password){_password =password;}
std::string Singleton::getUsername() { return _username; }
std::string Singleton::getPassword() { return _password; }







