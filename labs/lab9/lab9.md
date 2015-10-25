## Objectives

So far this semester we've done our programming in the C language, meaning the bulk of
the programs we've written have been written in a *procedural* style. That is, the various 
chunks composing and guiding the overall logic of our programs was (hopefully!) 
decomposed into various separate functions. And when we wanted to execute these various 
parts in some larger sequence, we'd simply call our functions in a certain order. And 
when we wanted to group data together, we'd simply pack it into a struct. 

The outward objective of today's lab is give you a taste of C++ by having you 
read, understand, and implement a simple `Person` class, then instantiate several 
`Person` objects using a main driver that you will also write. 

However, more than just introducing you to yet another language (they are, after all, 
just tools for executing your logic), the actual objective here is to give you 
some idea as to what programming with objects entails -- *and hopefully, 
by extension: why it's so useful, and how it differs from the procedural approach 
discussed above.*

In short, you'll want to pay attention and ask questions since this might very well
be your first foray into **object oriented programming** -- which will (hopefully) 
change the way you design, structure, and write your code from here on out. 
So as usual, be patient. 

## Task: understand and implement `Person`

The `Person` class is simply designed to be some representation 
('abstraction' if you like) of a person like your or me. 

```c++
//person.h

class Person {
public:
    Person(); 
    Person(string firstname, string lastname, int age, char gender);	

    string getFirstName();	
	void setFirstName(string new_name);
	...

    ~Person();
private:
    string first_name;
    string last_name;
    int age;
    char gender;
};
```

Specifically, we've defined a 
`Person` as something having a `first_name`, `last_name`, `age`, and `gender`. These 
member variables are defined in `person.h`, which, as usual for header files, also 
declares prototypes for the various *methods the `Person` class supports.

|*aside: methods vs. functions|
|-------------|
| *A method is distinguished as an operation that is associated with an object. As such, they are typically declared in the `.h` file for a class and can access any (even private) member variables for the class (`first_name`, `last_name`, `age`, etc). Since C inherently lacks objects, there can be no notion of a 'method' and so everything should be referred to as a function.* |

### "What makes a `Person` anyways?"

To use a `Person` object, it must first be made (instantiated) via a class *constructor*. 
In this case, there are actually two to choose from. The first is declared like this:
```c++
Person(string firstname, string lastname, int age, char gender)
```
meaning in order to 'make' a new `Person`, you must provide all necessary name, age,
and gender information at the time of creation like this:

```c++
Person *p = new Person("lawrence", "welk", 102, 'M');
```



### Methods 

## Testing


## Handin


## Starter kit
