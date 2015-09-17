# CPSC210 -- Programming Methodology Labs

This is the home page for all **lab sections** of Computer Science 210, Programming 
Methodology, at Clemson University

# Abstract

In learning any new concept, there are few (if any) real substitutes for putting into
practice the ideas posed in the classroom. This holds especially true for an intermediate 
computer science course in which you're often expected to learn new languages and 
concepts in parallel.

This lab therefore exists to provide you with a weekly means of practicing and building
upon some of the ideas that might've only briefly seen in the lecture portion of the 
course. This will allow you to gain some much needed experience 'at the keyboard' so to 
speak and should help prepare you for the course's (more challenging) future 
projects and exams.

Here is a tentative, high level ordering -- at a roughly month-by-month level of 
granularity -- indicating where we're headed over the course of the semester:

* unix introduction, lower level C datatypes

* pointers: void & function, basic linked data structures

* raytracer related functions and object oriented programming in C++


Finally, as with most things, some of the labs we'll be doing over the course of the 
semester will require a certain level of knowledge and patience to understand and 
complete. Therefore, please make an effort to attend the lecture portion of the course 
to ensure that you are on track for each week's lab. It hurts both your classmates 
(and you!) when you come in knowingly unprepared.

# Administrivia

* Section 1: Monday 4:00pm - 5:50pm pm McAdams 110D 

* Section 2: Wednesday 2:00pm - 3:50pm McAdams 110D 

* Section 3: Thursday 6:00pm - 7:50pm McAdams 110D 

* Section 4: Tuesday 2:00pm - 3:50pm McAdams 110E

|Fall 2015 Lab TAs|
|-------------|
|*Daniel Welch         (dtwelch@g.clemson.edu)* 
 *Takumi Bolte          (tbolte@g.clemson.edu)*|

## Instruction format

All lab sections will last approximately one hour and fifty minutes 
(depending on the speed at which people finish the lab, and whether or not the room is 
needed directly afterwards) one day a week. All programming will be performed in the C 
language, unless otherwise specified. 

## Books and references:

While there are of course no prescribed refs/textbooks for the lab, I'll recommend some 
regardless:

#### C language reference
* [The C Programming Language - Brian Kernighan & Dennis Ritchie]
(http://www.amazon.com/The-Programming-Language-Brian-Kernighan/dp/0131103628)
	
* [The C Library Reference](http://www.cplusplus.com/reference/clibrary/)

#### Unix reference

* [Terminal command cheatsheet](http://www.cs.clemson.edu/course/cpsc210/Links/unix.html)

* [Compiling and executing](http://www.cs.clemson.edu/course/cpsc210/Links/compiling.html)

## Grading

Of the ~13 labs (one for each week of the semester), each is weighted equally and graded 
on a 100 point scale. *Note that since there is no final exam for lab, your grade rests 
entirely on your performance and mastery of the weekly labs*.

An "A" grade on each lab is expected of each student. This entails attending the lab 
(on time!), completing the lab according to the specifications given, and code quality. 
Even if you have perfect functionality, points will be deducted for blantantly sloppy, 
partially correct solutions and/or poorly commented code. If you are absent 
(and it's not cleared with one of the TAs), you get a zero for that week's lab: This is 
non-negotiable.

The labs are not designed to be nearly as taxing as weekly homework assignments 
(if your instructor indeed gives these) and *should* be entirely doable within the 2 
hours provided each week -- though we do give a whole 24 hour window to complete
and submit the lab.

The weekly labs will be posted and downloadable here on Github (so bookmark this page).
When completed, each lab should be submitted electronically through the 
CS [handin system](https://handin.cs.clemson.edu/). 

If you have a problem with a lab grade, come talk to a TA within at most a week of the
grade's posting. You can view your lab grades through 
[Blackboard](https://bb.clemson.edu/).

## Some do's and don'ts

* do ask questions if you are confused

* don't simply throw up your hands and say 'I have no idea what to do'; this is not 
productive and moreover, isn't terribly helpful to the TAs

* don't ask: 'is this right?'; what does the compiler tell you? have you even tried 
compiling??

* *please* don't comment every single line of code; so none of this please:
	```c
	//libraries
	#include <stdio.h> ...
	```
	or even more egregious:
	```c
	int i; //declare an integer variable 
	//check if i is not equal to 0
	if (i != 0) { ... } ..
	```
	this isn't intelligent commenting and, frankly, will only serve to annoy and exhaust 
	those who have to read your code. Instead, write meaningful, informative comments for
	the parts of your code that genuinely require some commentary -- the place(s) where 
	the core logic of your program is carried out. Effective commenting like anything is 
	a skill that must be developed over time. For more, refer to [this]().

## The fine print

### Disability access

It is university policy to provide, on a flexible and individualized basis, reasonable
accommodations to students who have disabilities. Students with disabilities are
encouraged to contact Dr. Arlene Stewart (656-6848), Director of Student Disability 
Services, within the first month of classes, to discuss their individual needs for 
accommodation. Students should present a Faculty Accommodation Letter from Student 
Disability Services when they meet with instructors. Student Disability Services 
(656-6468; sds-l@clemson.edu) is located in the Academic Success Building, Suite 239.
Please be aware that accommodations are not retroactive and new Faculty Accommodation
Letters must be presented each semester.

### Title IX (sexual harassment) statement

Clemson University is committed to a policy of equal opportunity for all persons and does
not discriminate on the basis of race, color, religion, sex, sexual orientation, gender,
pregnancy, national origin, age, disability, veteran's status, genetic information or 
protected activity (e.g.: opposition to prohibited discrimination or participation in any 
compliant process, etc) in employment, education programs and activities, admissions and 
financial aid. This includes a prohibition against sexual harassment and sexual violence 
as mandated by Title IX of the Education Amendments of 1972