/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:05:06 by yubin             #+#    #+#             */
/*   Updated: 2022/11/07 13:50:56 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char *av[]) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }

    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j]; j++) {
            std::cout << static_cast<char>(std::toupper(av[i][j]));
        }
    }
    std::cout << std::endl;
    return (0);
}
