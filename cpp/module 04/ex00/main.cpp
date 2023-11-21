#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    cout << endl << "Animal:" << endl;
    cout << meta->getType() << endl;
    cout << j->getType() << endl;
    cout << i->getType() << endl << endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();
    cout << endl;

    delete meta;
    delete j;
    delete i;
    cout << endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    cout << "WrongAnimal:" << endl;
    cout << wrongMeta->getType() << endl;
    cout << wrongCat->getType() << endl << endl;

    wrongMeta->makeSound();
	wrongCat->makeSound(); // will output the wrong sound because the function is not virtual
    cout << endl;

    delete wrongMeta;
    delete wrongCat;
    cout << endl;

    return 0;
}
