# CP386 Assignment 4
## Project title
CP386 A04 - Final Assignment
## Motivation
Assignment to practice the concept of deadlock avoidance for CP386 (Wilfrid Laurier University)
## Installation
**Required:** Linux or Linux Virutal Machine
1. Download or clone Github repository
2. Transfer the folder to your Virtual Machine if needed
3. Run on Linux by changing the directory to the folder
```
cd FOLDER_NAME
```
*replace FOLDER_NAME with the name of the folder*
4. To run, use makefile
To compile your program:
```
make
```
```
make warnings_OK
```
To run your program:
``` 
./Assignment_4 10 5 7 8
```
*replace '10 5 7 8' with 4 ints to represent the number of resources available*

## Screenshots
![Image 1](https://github.com/ChristineAu-yeung/CP386/blob/master/Screenshot%20of%20Code.jpg)</p>
![Image 2](https://github.com/ChristineAu-yeung/CP386/blob/master/Screenshot%20of%20Code%202.jpg)
## Individual contribution (Function-wise)
```c
int request_resources() Brian
int release_resources() Brian
int * safety_algorithm() Chrsitine/Brian
void current_state() Christine
int readfile() Christine
int main() Christine/Brian
```
## Features
RQ - request resources
RL -  release resources
* - print out the current state
run - find the safe sequence
q - exit
## Tests
See screenshots
## Code Example
See screenshots
## Authors
Brian Chan 171884160 [Github](https://github.com/Brian-Chan98)</p>
Christine Au-yeung 160634760 [Github](https://github.com/ChristineAu-yeung)
## Credits 
Brian Chan</p>
Christine Au-yeung
## License
MIT License

Copyright (c) [2020] [Brian Chan] and [2020] [Christine Au-yeung]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
