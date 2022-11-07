#ifndef CONTACT_HPP  // include guard
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
   private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _secret;

   public:
    Contact();

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getSecret();

    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setNickname(std::string nickname);
    void setPhoneNumber(std::string phoneNumber);
    void setSecret(std::string secret);

    ~Contact();
};
#endif