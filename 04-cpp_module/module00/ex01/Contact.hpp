#ifndef CONTACT_HPP // include guard
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _secret;

public:
	Contact();

	std::string get_first_name(void) const;
	std::string get_last_name(void) const;
	std::string get_nickname(void) const;
	std::string get_phone_number(void) const;
	std::string get_secret(void) const;

	void set_first_name(std::string firstName);
	void set_last_name(std::string lastName);
	void set_nickname(std::string nickname);
	void set_phone_number(std::string phoneNumber);
	void set_secret(std::string secret);

	~Contact();
};
#endif