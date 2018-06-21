# Fillit
Fillit is a project about optimization, where you must fill a certain amount of tetriminos into the smaller square possible, without taking too much time.

Recursivity can go very far in this project, wich will make a huge difference between non optimized algorithm and those that are optimized. 

But it's not only about the algorythm, but also how you manage the methods, the number of verification that happen in each loop, and even in wich order they happen. Some fillit can take 10 min to find the smaller square possible where to fill 5 shape. Some can take hours, and some a few seconds.


**Usage**

To build:
```
$ make
```
To execute:
```
$ ./fillit sample_example
```
A sample look like this:
```
###.
..#.
....
....

####
....
....
....

#...
#...
#...
#...

##..
.##.
....
....
```

Each shape is displayed on a 4x4 square, the shape has to be a valid one (only tetriminos are valid).
The programm will attemp to assemble the, into the smaller square possible, by using recursivity. 
Feel free to create your own map, you have create simple file, where you put each shape in a 4x4 square, the shape has to be a tetriminos, and not be more than 25.

Output:
```
AAAFFC
DDAFFC
.DD..C
BBBBHC
.GEEHH
GGGEEH
```
The letter stand for each shape in the sample. So you can see where they went. A sample with 26 shape or more is invalid.

Note :

Some of the more complex sample can take severals minutes.
It may look long but without optimization, it can even take years, as the time can be exponential.
For more information, see in the pdf subject.
