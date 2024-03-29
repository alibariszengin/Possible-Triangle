﻿
# Possible Triangle


We have a problem to be solved in a triangle of numbers. From top of the triangle, problem wants us to find the maximum sum of the way to bottom. 

Developed in 2021.

## Table of contents
* [General info](#general-info)
* [Technologies-Tools](#technologies-tools)
* [Setup](#setup)
* [Contact](#contact)


## General Info
You will have an orthogonal triangle input from a file and you need to find the maximum sum of the numbers according to given rules below;

1. You will start from the top and move downwards to an adjacent number as in below.
2. You are only allowed to walk downwards and diagonally.
3. You can only walk over NON PRIME NUMBERS.
4. You have to reach at the end of the pyramid as much as possible.
5. You have to treat your input as pyramid.

According to above rules the maximum sum of the numbers from top to bottom in below example is 24.

	      *1
	     *8 4
	    2 *6 9
	   8 5 *9 3

As you can see this has several paths that fits the rule of NOT PRIME NUMBERS; 1>8>6>9, 1>4>6>9, 1>4>9>9
1 + 8 + 6 + 9 = 24.  As you see 1, 8, 6, 9 are all NOT PRIME NUMBERS and walking over these yields the maximum sum.

Problem solved with using linked lists.
## Technologies-Tools
Project is created with:
* C
* Dev-C++
* Linked-List


## Setup
To run this project, run from the IDE or after change directory to project folder, run 'pi' on the terminal.

```
$ cd .\Possible-Triangle
$ pi
```

## Contact

Ali Barış Zengin  -  [alibariszengin@gmail.com](mailto:alibariszengin@gmail.com)

Project Link:  [https://github.com/alibariszengin/Possible-Triangle](https://github.com/alibariszengin/Possible-Triangle)
