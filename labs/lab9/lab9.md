## Objectives

So far this semester we've done our programming in the C language, meaning all of 
the programs we've seen have been written in a *procedural* style. That is, the various 
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
member variables/instance variables are defined in `person.h`, which, as usual for header 
files, also declares prototypes for the various *methods the `Person` class supports.

|*aside: methods vs. functions|
|-------------|
| *A method is distinguished as an operation that is associated with an object. As such, they are typically declared in the `.h` file for a class and can access any (even private) member variables for the class (`first_name`, `last_name`, `age`, etc). Since C inherently lacks objects, there can be no notion of a 'method' and so everything in that language should be referred to as a function.* |

This is a pretty typical organization for a C++ class. That is, you declare a collection
of available methods and some number of private, *instance variables* that the methods 
either use or alter.

With this in mind, methods usually fall into two broad categories:

* **Mutator methods**: Usually these methods names start with `set..`. 
These are methods that allow clients (users of a class) to change the 
*state* of the object. So in our `Person` example, `setFirstName(String new_name)` is
a mutator (sometimes called a 'setter') method that allows users to change the name
of a `Person`. If `setFirstName(..)` was not provided as a method, then users would 
have no means of changing the name of a `Person`, since it's stored as a `private`
 variable -- which means it's inaccesible from outside the class. 

* **Accessor methods**: These methods have names that are usually prefixed by `get..`.
In short, these methods return allow you to access/'get-at' some (potentially private) 
data stored within a class. For instance `getFirstName()` declares a string returning 
the first name of the `Person`. 

### "What makes a `Person` anyways?"

To use a `Person` object, it must first be made (instantiated) via a class *constructor*. 
In this case, there are actually two to choose from. 

#### Parameterized constructors

The first is declared like this in the header:
```c++
Person(std::string, std::string, int, char)
```
meaning in order to 'make' and use a `Person` in some client context, you must provide 
all necessary name, age, and gender information at the time of creation like this:

```c++
Person *p = new Person("lawrence", "welk", 102, 'M');
```

Then I can pull this information out or manipulate it by calling the available 
methods:

```c++
std::cout << p->getFirstName(); // prints: lawrence
std::cout << p->getAge(); // prints: 102
std::cout << p->setAge(116); // sets the private int variable 'age' to 116
```
As you might've guessed, internally the class constructor for `Person` is just setting
various instance variables to the values appearing within the `(` ... `)` parts:

```c++
Person::Person(string firstname, string lastname, int age, char gender) :
    first_name(firstname), 
    last_name(lastname), 
    age(age), 
    gender(gender) {}
```

#### Default constructors 

The second constructor is referred to as a *default constructor*. A default constructor,
while simple to instantiate, will automatically set the instance variables to some 
preselected default values, like so:

```c++
Person::Person() {
    first_name = " "; 
    last_name = " "; 
    age = 0; 
    gender = 'N'; 	
}
```


requires a combination of additional calls to initialize
the class's data fields.
For example:

```c++
Person *p = new Person();
p->setFirstName("lawrence");
p->setLastName("welk");
p->setAge("
```

### Methods 

## Testing


## Handin


## Starter kit
