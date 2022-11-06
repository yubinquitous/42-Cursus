/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:20:03 by yubin             #+#    #+#             */
/*   Updated: 2022/11/06 21:55:57 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
    _firstName = "";
    _lastName = "";
    _nickname = "";
    _phoneNumber = "";
    _secret = "";
}

Contact::~Contact() {}

std::string Contact::get_first_name(void) { return (_firstName); }

std::string Contact::get_last_name(void) { return (_lastName); }

std::string Contact::get_nickname(void) { return (_nickname); }

std::string Contact::get_phone_number(void) { return (_phoneNumber); }

std::string Contact::get_secret(void) { return (_secret); }

void Contact::set_first_name(std::string firstName) { _firstName = firstName; }

void Contact::set_last_name(std::string lastName) { _lastName = lastName; }

void Contact::set_nickname(std::string nickname) { _nickname = nickname; }

void Contact::set_phone_number(std::string phoneNumber) {
    _phoneNumber = phoneNumber;
}

void Contact::set_secret(std::string secret) { _secret = secret; }
