#ifndef SINGLETON_H
#define SINGLETON_H
#include <string>


class Singleton
{
        static Singleton* _instance;
        std::string _username;
        std::string _password;
 public:
        Singleton(){_username = "user";_password = "1234";}

        static Singleton* getInstance()
        {
           if (_instance == NULL)
                _instance = new Singleton();
                return _instance;
        }
        void setUsername(std::string username);
        void setPassword(std::string password);
        std::string getUsername();
        std::string getPassword();
};

#endif // SINGLETON_H
