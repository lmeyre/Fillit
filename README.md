# Fillit
Fillit is a project about optimization, where you must fill a certain amount of tetriminos into the smaller square possible, without taking month.


**Usage**

To build:
```
$ make
```
To execute:
```
$ ./fillit sample
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
