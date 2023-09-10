/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:13:53 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/09 16:44:48 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


static void print_to_upper(char **argv, int argc)
{
    std::string str = argv[1];

    for (int i = 2; i < argc; i++)
        str = str + " " + argv[i];
        
    for (size_t i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);

    std::cout << str << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        print_to_upper(argv, argc);
    return (0);
}