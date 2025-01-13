
Author: Çağın Tunç


Background about the project:

	Programming: 
	    C(DEV-C++5.11) and Python( version 3.9.1) programming languages used for this project.
	
	Our approach to the problem:
	    Two mass ratio is a well known fact about Physics and engineering; for this problem, we simulate two 
	bodies to move around a common center of mass. It is known that center of these two body must be have constant 
	velocity, and we also knew that the Newton's law of gravitation; after some calculations we could reach the formula 
	which was shown us on the project pdf, we found them in order to understand the infrastucture of the formula. Two well 
	known numerical ODE's methods can be used for this problem. Euler and Runge-Kutta is used for our project.

Programming in depth:
---------------------------------------------------------------Python:----------------------------------------------------------------------------
	It can be learn which version you are using by command prompt with the following easy algorithm:
	>>Open command prompt. 
	>>Write: >py --version 
	>>Click enter to see your Python version on the screen

	About Python interpreter:
	    Python compilation takes place where the code compiles into a simpler form called bytecode. 
	The byte code is not really interpreted to machine code unless there is some kind of implementation like PyPy. Bytecodes are executed by Python Virtual Machine (PVM) which emulates a simplified execution environment.
	The compilation process to bytecode is entirely implicit. This means that you never invoke the compiler. 
	Instead, you simply run a .py file. The lack of an explicit compile step is why the Python executable is known as 
	the Python interpreter.
	
---------------------------------------------------------------C:---------------------------------------------------------------------------------
	Libraries used:
	   For C implementation: 
            <stdio.h>
        The stdio.h header defines some basic functions to perform input and output. For example, FILE is an object type suitable for storing information for a file stream.  
            <math.h>
        The Math.h header describes various mathematical functions and a macro. All functions in this library define double as values and return double values.
        For example double pow(double x, double y).Returns x raised to the power of y.
            <stdlib.h>
        The stdlib.h header defines four types of variables, several macros, and various functions to perform common functions. This function is used to allocate memory during execution.
        To give an example from the program, du=(float*)malloc(4*sizeof(float)); line is used to reserve space for a variable of type float.
	

	Design:
	    We tried to implement the MVC design pattern in our code.
	In other functions, we have the derivation which work with the Runge-Kutta method and Euler's method back and forth. They constantly address the TwoBodyModel for info about the planets. In MVC, Model should contain all the variables and 
	controller should oversee the funcions and calculations. However, we couldn't use the Controller accordingly, thus we left it empty. In main, we send the program to the funcion called menu. (Menu was supposed to be Controller). And from
	there, the program does the standart calculations according to the user preference.
	
	



   For Python simulation and implementation:
		pygame: 
		    It is used in our visualization. pygame is a free and open-source cross-platform library for the development of multimedia applications like video games using Python. 
		It uses the Simple DirectMedia Layer library and several other popular libraries to abstract the most common functions, making writing these programs a more intuitive task.

		math: 
		    This module provides access to the mathematical functions defined by the C standard.
			math.sqrt(x):
			     Return the square root of x.

			math.pow(x, y):
			     Return x raised to the power y. Exceptional cases follow Annex ‘F’ of the C99 standard as far as possible. 
			In particular, pow(1.0, x) and pow(x, 0.0) always return 1.0, even when x is a zero or a NaN. 
			If both x and y are finite, x is negative, and y is not an integer then pow(x, y) is undefined, and raises ValueError.
			Unlike the built-in ** operator, math.pow() converts both its arguments to type float. Use ** or the built-in pow() function for computing exact integer powers.
		
