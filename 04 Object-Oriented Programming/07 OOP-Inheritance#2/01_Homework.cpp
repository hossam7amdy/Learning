#include <string>
#include <iostream>

class Fruit
{
private:
	std::string m_name;
	std::string m_color;

public:
	Fruit(const std::string& name, const std::string& color)
		: m_name{ name }, m_color{ color }
	{
	}

	const std::string& getName() const { return m_name; }
	const std::string& getColor() const { return m_color; }

};

class Apple : public Fruit
{
private:
	double m_fiber;

public:
	Apple(const std::string& name, const std::string& color, double fiber)
		:Fruit{ name, color },
		m_fiber{ fiber }
	{
	}

	double getFiber() const { return m_fiber; }

};

std::ostream& operator<<(std::ostream& out, const Apple& a)
{
	out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ')';
	return out;
}

class Banana : public Fruit
{
public:
	Banana(const std::string& name, const std::string& color)
		:Fruit{ name, color }
	{
	}
};

std::ostream& operator<<(std::ostream& out, const Banana& b)
{
	out << "Banana(" << b.getName() << ", " << b.getColor() << ')';
	return out;
}

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}

/*
====================
In C++, Friendship is neither inherited nor transitive.
Why functions are not inherited?

https://stackoverflow.com/questions/3561648/why-does-c-not-allow-inherited-friendship/24304490

====================
Comparing, the set of objects of a base class with its derived classes, which one is bigger?

Yhe set of objects represented by a base class typically is larger than the set of objects represented by any of its derived classes.
For example, the base class Vehicle represents all vehicles, including cars, trucks, boats, airplanes, bicycles and so on.

By contrast, derived class Car represents a smaller, more specific subset of all vehicles.


========================
We know that we don’t access private variables, but are they still inherited?

Sure. They are they still in the memory. The base class has its own functions that works on its private variables & functions

Inheritance != Access


=========================
Think: Making variable protected vs public getter/setter for it?

- The rule of thumb is simple: make each class or member as inaccessible as possible. In other words,
	use the lowest possible access level consistent with the proper functioning of the software that you are writing.
- Use the most restrictive access level that makes sense for a particular member. Use private unless you have a good reason not to.
	- Public fields tend to link you to a particular implementation and limit your flexibility in changing your code.
- If you are not sure why you need a protected class member, then declare it private. If you wish to set it from outside the class, then make a public setter.

- A protected field allows the subclass to modify parent class state directly.
	This means a subclass may be able to violate the parent's "invariants" or validations (e.g. setter has validations).
	In other words, this approach might cause a class to behave inconsistently


	Side note, what are invariants in previous answer?
		In OOP, an invariant is a set of assertions that must always hold true during the life of an object for the program to be valid.
		It should hold true from the end of the constructor to the start of the destructor whenever the object is not currently executing a method that changes its state.

		An example of invariant could be that exactly one of two member variables should be null. +
		Or that if one has a given value, then the set of allowed values for the other is this or that...

		I sometime use a member function of the object to check that the invariant holds. If this is not the case, an assert is raised.
		And the method is called at the start and exit of each method that changes the object

		https://softwareengineering.stackexchange.com/questions/32727/what-are-invariants-how-can-they-be-used-and-have-you-ever-used-it-in-your-pro

Coupling:
- With using protected data members is that derived, class member functions are more likely to be written so that they depend on the base-class implementation.
- Derived classes should depend only on the base-class services (i.e., non- private member functions) and not on the base-class implementation.
- With protected data members in the base class, if the base-class implementation changes, we may need to modify all derived classes of that base class.
- For example, if for some reason we were to change the names of data members firstName and lastName to first and last,
- then we’d have to do so for all occurrences in which a derived class references these base-class data members directly.
- Such software is said to be fragile or brittle, because a small change in the base class can “break” derived-class implementation.
- You should be able to change the base-class implementation while still providing the same services to derived classes.
- Of course, if the base-class services change, we must reimplement our derived classes—good object-oriented design attempts to prevent this.
- From: C++ How to program
*/
