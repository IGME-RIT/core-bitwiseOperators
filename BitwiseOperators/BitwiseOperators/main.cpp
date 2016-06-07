/*
Title: Bitwise Operations
File Name: main.cpp
Copyright © 2016
Original authors: Luna Meier
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Description:
In this example we go over how to doing basic bitwise operations.  We show off
how bitwise operations can be used with any form of data.
*/

#include <stdio.h>
#include <conio.h>

int main(){
	/////////////////////////////////
	//  Intro                      //
	/////////////////////////////////
	//  When you store a variable on the computer, the value itself is stored in binary.
	//  We then parse that binary into a more understandable form, like an integer or a character.
	//  Sometimes you need to manipulate that binary in order to accomplish more complex tasks.
	//
	//  Before we continue, you should be aware that it's rare for programmers to fully write out
	//  the binary when talking about it.  Most of the time they convert it into hexadecimal since
	//  it plays nicely with binary.
	//
	//  This tutorial will write most of everything out in binary so it's easy to understand, but we encourage
	//  you to try to use hexadecimal when you are manipulating binary yourself.
	//
	//  Just in case you haven't seen it, here is some hexadecimal with the binary representation.
	//  The 0x means the following number is in hexadecimal.
	//
	//  0x00 = 00000000
	//  0x0F = 00001111
	//  0xF0 = 11110000
	//  0xFF = 11111111
	//
	//  So as you can see, to read hexadecimal as binary it's really easy.  You just convert each hex digit into
	//  the four digit binary equivalent, and concatenate them together.
	//
	/////////////////////////////////
	//  Operations                 //
	/////////////////////////////////
	//
	//  So let's go over what each operation does now.
	//
	//  These are the bitwise operators:
	//
	//  & is AND
	//  | is inclusive OR (usually known just as OR)
	//  ^ is exclusive OR (usually known just as XOR)
	//  ~ is the complement
	// << is left shift
	// >> is right shift
	//
	/////////////////////////////////
	//  & (AND)                    //
	/////////////////////////////////
	//
	//  & will take two sets of bits, and go through bit by bit and compare if they are both true.
	//  So if both bits are true (1), then the AND is true.  So for example:
	//
	//     0110 
	//   & 1100
	//  == 0100 (since only the second digit of the first and second digit of the second were both 1)
	//
	/////////////////////////////////
	//  | (OR)                     //
	/////////////////////////////////
	//
	//  | will be true if either bit is true.  For example:
	//     0110 
	//   | 1100 
	//  == 1110 (note that it was only false (0) when both were 0)
	//
	/////////////////////////////////
	//  ^ (XOR)                    //
	/////////////////////////////////
	//
	//  ^ is true only if the two bits are unequal.
	//     0110 
	//   ^ 1100
	//  == 1010 (note that 1 ^ 1 is 0, and 0 ^ 0 is 0.
	//
	/////////////////////////////////
	//  ~ (Complement or Toggle)   //
	/////////////////////////////////
	//
	//  The other 3 operators only take one set of bits.
	//  ~ will "flip" every bit.  So ~0110 == 1001.
	//
	/////////////////////////////////
	//  << and >> (Shifting)       //
	/////////////////////////////////
	//
	//  The other two, the bit-shifting operators, are a little more complex.
	//  >> and << will "shift" the bits over in data.
	//  For example:
	//  
	//	0100 << 1 == 1000
	//  0100 << 2 == 0000
	//  0100 >> 1 == 0010
	//  0100 >> 2 == 0001
	//
	//  Because binary is in base 2, it's important to note that left shifting is
	//  actually multiplying by a power of 2, and right shifting is dividing by a power
	//  of two.
	//
	//  0001 == 1
	//  0010 == 2
	//  0100 == 4
	//  1000 == 8
	//  
	//  We do have to be careful though.  Be aware that right shifting
	//  is undefined behaviour on signed integers.  Sometimes it carries
	//  the 1 that is the leftmost bit used for negative numbers, sometimes
	//  it doesn't.
	//
	/////////////////////////////////
	//  Applying to actual data    //
	/////////////////////////////////
	//
	//  So let's look at some data with bit shifting.
	//

	unsigned int foo = 8;
	int bar = 8;

	printf("Foo: %i\nBar: %i\n\n", foo, bar);

	foo = foo >> 1;
	bar = bar >> 1;

	printf("Foo: %i\nBar: %i\n\n", foo, bar);
	
	// Everything seems to make sense so far.
	
	foo = foo >> 10;
	bar = bar >> 10;

	printf("Foo: %i\nBar: %i\n\n", foo, bar);

	// Let's try something else.
	foo = 8;
	bar = -8;

	foo = foo >> 1;
	bar = bar >> 1; //On my computer this divides it by two. On yours it might not.
	// So generally don't do that.

	printf("Foo: %i\nBar: %i\n\n", foo, bar);

	//  We can also happen to set a specific bit of some data if we want.
	//  Let's set a bit to 1.

	foo = 0;  //so everything is zeroed out.

	foo = foo | (1<<3); //8 is 00000100
	//Because it's an or, foo will now be 8.

	bar = 8;
	bar = bar | (1<<3); //this makes no difference.

	printf("Foo: %i\nBar: %i\n\n", foo, bar);

	// Let's set that same bit to zero without affecting
	// the other bits.

	foo = 9;//0000101
	foo = foo & ~(1<<3);

	bar = 1;//0000001
	bar = bar & ~(1<<3);

	printf("Foo: %i\nBar: %i\n\n", foo, bar);


	//Let's check if the third bit from the right is true.
	foo = 9;

	if (foo & 1<<3){
		printf("True!\n\n");
	}
	else{
		printf("False!\n\n");
	}
	// Let's toggle a specific bit.

	foo = foo ^ (1 << 3);
	bar = foo ^ (1 << 3);

	printf("Foo: %i\nBar: %i\n\n", foo, bar);

	// Let's use bitwise operators to mask a string!

	char myString[13] = "Hello World!";

	printf(myString);
	printf("\n\n");

	// This is a xor mask.  It's simple to crack, but nice
	// for basic data transfer if you don't REALLY care about it
	// being opened.
	for (int i = 0; i < 13; ++i){
		// We'll use 11010001 as the mask.  No particular reason.
		myString[i] = myString[i] ^ 0xD1; //11010001 (it's easier to use hex for this)
	}

	printf(myString);
	printf("\n\n");

	for (int i = 0; i < 13; ++i){
		// To undo it just xor all the bits again!
		myString[i] = myString[i] ^ 0xD1;
	}

	printf(myString);
	printf("\n\n");

	// Those are the main uses of bitwise operators.  Most often you'll see them used for
	// flags on objects in games "Is it Tall, is it red, is it a vampire".  
	printf("Press enter to exit.");
	_getch();

	return 1;
}