/// Homework 5: irrelevant!
/*
● Imagine we have 4 classes, each with 20 function
● There is a need for a new class that has a relationship of “has-a” with the 4 classes to a good extent
    ○ What is the problem we will face?
    ○ As more motivation, imagine we wanna Create a RobotDog from the classes

■ It is a robot, so it does what robots does
■ It looks like a dog and do its most of its functionalities
■ But it is not real dog, it is a made one
*/


#include<iostream>
using namespace std;

class Robot
{
public:
    void Drive();
    void Clean();
    void do_funny_moves();
};

// Represent Real Animal
class Animal
{
public:
    void go_toeilt();
    void make_sound();
};

class Cat
{
public:
    void make_sound();
};

class Dog
{
    void make_sound();
};

/// Dr's NOTEs
/*
- If we extended from the 4 classes, we will end up with a lot of functions that are irrelevant to the current class
- Usually, we do mistakes in design and even with a reasonable has-a relationship, a lot of functions just are in our new class that has no use!

- In the example, A robot dog won't go toilet, it is a made dog, not a real one. Sometimes the has-a relationship is not as strong as we wish
*/

int main() {


	return 0;
}
