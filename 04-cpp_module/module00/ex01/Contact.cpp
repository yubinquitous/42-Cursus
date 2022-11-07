/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:20:03 by yubin             #+#    #+#             */
/*   Updated: 2022/11/06 22:46:58 by yubin            ###   ########.fr       */
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

std::string Contact::getFirstName(void) { return (_firstName); }

std::string Contact::getLastName(void) { return (_lastName); }

std::string Contact::getNickname(void) { return (_nickname); }

std::string Contact::getPhoneNumber(void) { return (_phoneNumber); }

std::string Contact::getSecret(void) { return (_secret); }

void Contact::setFirstName(std::string firstName) { _firstName = firstName; }

void Contact::setLastName(std::string lastName) { _lastName = lastName; }

void Contact::setNickname(std::string nickname) { _nickname = nickname; }

void Contact::setPhoneNumber(std::string phoneNumber) {
    _phoneNumber = phoneNumber;
}

void Contact::setSecret(std::string secret) { _secret = secret; }
