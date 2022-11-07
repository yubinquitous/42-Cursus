/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:27:48 by yubin             #+#    #+#             */
/*   Updated: 2022/11/07 12:03:11 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
class PhoneBook {
   private:
    Contact _contacts[8];
    int _idx;

    bool _readLine(std::string msg, std::string &str, std::string constraint);
    void _add();
    void _search();
    std::string _shorten(std::string str);
    bool _isValidInputIdx(std::string str, int &num);

   public:
    PhoneBook();
    ~PhoneBook();

    void run();
};

#endif