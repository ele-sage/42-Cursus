/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:20:04 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/29 18:20:04 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Animal is an abstract class so we can't create an instance of it
    //const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    cout << endl << "Animal:" << endl;
	//cout << meta->getType() << endl;
    cout << j->getType() << endl;
    cout << i->getType() << endl << endl;

    i->makeSound();
    j->makeSound();
    //meta->makeSound();
    cout << endl;

    //delete meta;
    delete j;
    delete i;
    cout << endl;

    return 0;
}
