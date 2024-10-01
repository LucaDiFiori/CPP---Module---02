# CPP---Module---02
This module is designed to help you understand Ad-hoc polymorphism, overloads and orthodox canonical classes in CPP.

***

# NEW RULES
From now on, all your classes must be designed in the Orthodox Canonical Form,
unless explicitely stated otherwise. Then, they will implement the four required member
functions below:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor
Split your class code into two files. The header file (.hpp/.h) contains the class
definition whereas the source file (.cpp) contains the implementation.

***

# C++ BASICS 02

***

# Table of Contents
- [AD HOC POLYMORPHISM (FUNCTION OVERLOAD)](#ad-hoc-polymorphism-(function-overload))
- [OPERATOR OVERLOAD](#operator-overload)
- [CANONICAL FORM OF A CLASS](#canonical-form-of-a-class)

***
***

## AD HOC POLYMORPHISM (FUNCTION OVERLOAD)
Ad-hoc polymorphism, also known as function overloading, is a feature in C++ where **two or more functions can have the same name but differ in the type or number of their parameters**. This allows functions to handle different types of input without needing unique names. This is a form of compile-time polymorphism because the decision on which function to call is made at compile time based on the argument types or number of arguments provided.

## Key Points:
- **Same Function Name**: All overloaded functions must share the same name.
- **Different Signatures**: Functions are distinguished by their **parameter types and number of parameters**. This difference is referred to as the function's signature.
- **Return Type Doesn't Matter**: Overloading is not based on return type, meaning you cannot overload functions by return type alone.
- **Resolved at Compile Time**: The compiler decides which function to call based on the arguments passed to the function.
```C++
#include <iostream>
using namespace std;

// Overloaded functions with the same name but different parameter types and numbers
void print(int i) {
    cout << "Printing int: " << i << endl;
}

void print(double d) {
    cout << "Printing double: " << d << endl;
}

void print(string s) {
    cout << "Printing string: " << s << endl;
}

void print(int i, double d) {
    cout << "Printing int and double: " << i << " and " << d << endl;
}

int main() {
    print(10);            // Calls the print(int) function
    print(10.5);          // Calls the print(double) function
    print("Hello, World"); // Calls the print(string) function
    print(5, 2.5);        // Calls the print(int, double) function

    return 0;
}
```

## Rules for Function Overloading:
#### 1.Overloaded functions must differ in the number or types of parameters
- Valid: print(int), print(double), print(string)
- Invalid: Two functions like print(int) and print(int) cannot coexist because they have the same signature.

#### 2.Return type alone is not enough for overloading.
- Invalid: You cannot have two functions like int print(int) and double print(int) because they only differ in return type.

#### 3.Default arguments can complicate overloading.
- If a function has default arguments, its signature can overlap with other functions, potentially leading to ambiguity.


***
***

## OPERATOR OVERLOAD
## 1. OVERLOADING OPERATOR USING THE MEMBER FUNCTION SYNTAX
Operator overloading in C++ allows you to define how operators (like +, -, *, ==, etc.) behave for user-defined types such as classes and structures. By overloading operators, you can extend their functionality to work with objects in the same way they do with primitive data types (like integers or floats). This is a form of polymorphism that makes custom classes more intuitive and usable, aligning them closer to native types.

C++ provides many operators that can be overloaded, but there are some operators that cannot be overloaded:
- :: (scope resolution)
- . (member access)
- .* (pointer-to-member access)
- ?: (ternary conditional)

## Syntax
```C++
return_type operator op (/*istance of the current class (implicit),*/ parameter_list) 
{
    // function body
}
```
- **return_type**: The return type of the overloaded operator function (it can be any type, including user-defined types).
- **op**: The operator being overloaded, such as +, -, =, ==, <<, etc.
- **parameter_list**: The list of parameters that the operator takes. For unary operators, no additional parameters are needed (apart from the object itself, which is implicit). For binary operators, at least one parameter is required (in addition to the object being operated on).

## Parameter list
The parameter list in operator overloading defines **what arguments the overloaded operator function will take**. The exact number and type of parameters depend on the operator you're overloading.
### 1. Unary Operators:
Unary operators only operate on one object, so they don’t take any additional parameters. The object on which the operator is called is implicit (the object itself).

Example of a Unary Operator Overload (e.g., -):
For unary operators like - (negation), the parameter list is empty because the operator only works on one object (the current instance of the class).
```C++
class Number {
private:
    int value;

public:
    Number(int v) : value(v) {}

    // Overloading the unary minus (-) operator
    Number operator-() {
        return Number(-value);  // Negates the value
    }
};
```
In this case, operator-() has no parameters in its parameter list because it is a unary operator that only works on one object (the object invoking the operator).
### 2. Binary Operators:
Binary operators operate on two objects, so they need one parameter in the parameter list for the second operand (the first operand is the object invoking the operator).
**Example**
For binary operators like +, the parameter list contains one parameter, which is the other object you’re adding to the current object.
```C++
class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overloading the binary + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
};
```
In this case, operator+() takes one parameter: const Complex& other, which is the second operand in the addition.

### To better understand the parameter list
Let's start by considering the addition operation between two integers:
1 + 1. This notation is called infix notation because the operator "+" is placed between the two operands.

However, we can rewrite this expression using a different notation: "functional notation": +(1,1).
Written this way, our expression looks much more like a general function.

Now, let’s assume that "+" is a method of a class.
In this case, I could write:
```C++
1.+(1)
```
Where:
- 1 = an instance of the class
- + = a method of the class
- (1) = the method's parameter

Let now consider the **operator+** example. In particular:
```C++
// ...
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
// ...
```
In this code snippet, **other** is a parameter of the function **operator+**. It represents the second operand in the addition of two Complex objects.

**Context**:
You are overloading the + operator to add two Complex numbers, which are represented by the class Complex. When you write an expression like:
```C++
Complex c1(3, 4);
Complex c2(1, 2);

Complex result = c1 + c2;
```

This statement is equivalent to calling the overloaded operator+ like this:
```C++
Complex result = c1.operator+(c2);
```

In this function call, the object c1 (the object on the left-hand side of +) is the implicit object, and the object c2 (the right-hand side of +) is passed as the parameter to operator+.

So, in this case:
- **this**: Refers to the object on the left-hand side of the + operator (c1 in this case).
- **other**: Refers to the object on the right-hand side of the + operator (c2 in this case).


## Key Points:
- **Overloading applies to user-defined types**: You cannot change the behavior of operators for built-in types, but you can for objects (such as classes or structs).
- **Syntax**: Operator overloading is done by defining a special function using the **operator** keyword followed by the symbol of the operator you wish to overload.
- **Functionality**: The overloaded operator must have at least one operand that is a user-defined type (class or struct).
- **Overloaded as functions**: Operators can be overloaded as member functions or non-member functions.
- **Return types**: Overloaded operators can return any type, often returning the result of the operation.
- **Arity**: Operators such as **+** or **-** are binary operators (require two operands) and can be overloaded to perform operations between objects.

## Types of Operators that Can Be Overloaded:
- Arithmetic operators: +, -, *, /, %
- Relational (comparison) operators: ==, !=, <, >, <=, >=
- Assignment operators: =, +=, -=, etc.
- Increment and decrement operators: ++, --
- Bitwise operators: &, |, ^, <<, >>
- Logical operators: &&, ||, !
- Subscript operator: []
- Dereference and pointer operators: *, ->
- Function call operator: ()
- Stream insertion and extraction operators: <<, >>

#### Example: Overloading the + Operator
Let's overload the + operator for a Complex class, so that we can add two complex numbers.
```C++
#include <iostream>
using namespace std;

// Class to represent a complex number
class Complex {
private:
    double real, imag;
    
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the '+' operator
    Complex operator + (const Complex& other) 
	{
        return Complex(real + other.real, imag + other.imag);
    }

    // Function to display the complex number
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2.5, 3.5), c2(1.5, 2.5);

    // Add two complex numbers using overloaded '+' operator
    Complex c3 = c1 + c2;

    c1.display(); // Output: 2.5 + 3.5i
    c2.display(); // Output: 1.5 + 2.5i
    c3.display(); // Output: 4.0 + 6.0i

    return 0;
}
```

#### Example: Overloading Comparison Operators (== Operator)
We want to compare two Complex objects for equality using the == operator.
```C++
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor to initialize complex number
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload the '==' operator
    bool operator == (const Complex& other) const 
	{
        return (real == other.real && imag == other.imag);
    }

    // Function to display the complex number
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 2.0);  // First complex number
    Complex c2(3.0, 2.0);  // Second complex number with the same values

    if (c1 == c2) {  // Overloaded '==' is used here
        cout << "The complex numbers are equal." << endl;
    } else {
        cout << "The complex numbers are not equal." << endl;
    }

    return 0;
}
```


#### Example: Overloading Comparison Operators (= Operator)
```C++
//--------------------------------Integer.hpp
#ifndef INTEGER_CLASS_H
# define INTEGER_CLASS_H

# include <iostream>

class Integer {

	public:
		Integer( int const n);
		~Intiger ( void );

		int getValue (void) const;

        //'=' overload
        // Non-const: Modifies the current object during assignment.
        Integer& operator=(Integer const & rhs);
        
        //'+' overload
        // Const: Does not modify the object, returns a new one with the result.
        Integer operator+(Integer const & rhs) const;

	private:
		int _n;
}


#endif


//--------------------------------Integer.cpp
Integer::Integer( int const n ) : _n(n) {
	std::cout << "Costructor called with value " << n << std::endl;
	return;
}

~Integer::Integer( int const n ) : _n(n) {
	std::cout << "Destructor called with value " << this->_n << std::endl;
	return;
}

int Integer::getValue(void) const {
	return this->_n;
}

//'=' overload
Integer& Integer::operator=(Integer const & rhs) {
	std::cout << "Assignation operator called form " << this->_n;
	std::cout << "to " << ths.getValue() << std::endl;

	this->_n = rhs.getValue();

    //'this' is a pointer so i need to use '*' to recover my reference
	return (*this);
}

//'+' overload
Integer Integer::operator+(Integer const & rhs) const {
	std::cout << "Addition operator called with " << this->_n;
	std::cout << "and " << ths.getValue() << std::endl;

    /*The reason we're using 'Integer' in the return type of the operator+ method is because we're creating and returning a new Integer object that represents the result of the addition.
    
    we cannot simply return this->_n + rhs.getValue() because this->_n and rhs.getValue() are of type int, and the return type of the function is expected to be an Integer object, not an int and we need to return an Integer object (not just an int) to support operator chaining (a + b + c)*/
	return Integer( this->_n + rhs.getValue());
}


```

**Notes**
- **'=' overload**
    - In **Integer& operator=(Integer const& rhs);**, the return type **Integer&** indicates that the assignment operator returns a reference to the current object.
    - In C++, the assignment operator (=) is typically designed to return a reference to the object that was assigned a new value. This allows chaining of assignments, like this:

    ```C++
    Integer a(5);
    Integer b(10);
    Integer c(15);

    a = b = c;  // Assign `c` to `b` and then `b` to `a`
    ```
    For this to work, b = c must return a reference to b (i.e., the object on the left-hand side), so that the result of b = c can be used as the left-hand side of a = (b = c).






## 2. OVERLOADING OPERATOR USING THE NON-MEMBER FUNCTION (FRIEND FUNCTION) SYNTAX
For some operators (like << and >>), overloading as a friend function is more common

***

### FRIEND FUNCTION
A friend function in C++ is a function that is **not a member of a class but has access to its private and protected members**. This allows the friend function to manipulate the internal state of the class, which is generally restricted from outside access. Friend functions are useful for providing functionality that involves multiple classes or when a non-member function needs to access the private members of a class.

### Key Points About Friend Functions
- **1.Access Privileges**:
    - Friend functions can access private and protected members of the class they are friends with.
    - They can be declared in a class, but they are defined outside the class scope.
- **2.Declaration**:
    - To declare a friend function, use the keyword friend before the function prototype inside the class definition.
    ```C++
    class MyClass {
        private:
        int value;

    public:
        MyClass(int v) : value(v) {}

        // Declaration of friend function
        friend void displayValue(const MyClass& obj);
    };
    ```
- **3.Definition**:
    - The actual implementation of the friend function is done outside the class. Since it's not a member function, it does not have access to the this pointer.
    ```C++
    void displayValue(const MyClass& obj) {
    std::cout << "Value: " << obj.value << std::endl;
    }
     ```
**Example**
```C++
#include <iostream>

class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    // Friend function declaration
    friend void printWidth(const Box& b);
};

// Friend function definition
void printWidth(const Box& b) {
    std::cout << "Width: " << b.width << std::endl;
}

int main() {
    Box box(10.0);
    printWidth(box);  // Accesses private member width
    return 0;
}
```

***

## Parameter list in friend function operator overloading
The key difference between normal operator overloading and special cases, such as the << operator, lies in the parameter list. In friend function operator overloading, the parameter list typically consists of references to the operands being manipulated, allowing for efficient access to their internal state without copying.

## Characteristics of the Parameter List in Friend Function Operator Overloading:

- ### 1. Number of Parameters:
    - For most binary operators, the friend function will take two parameters: one for the left-hand operand (lhs) and one for the right-hand operand (rhs). This differs from normal member function overloads, which generally only require one parameter because the left-hand operand is implicitly represented by the this pointer.
- ### 2. Type of Parameters:
    - The parameters are commonly declared as const references (e.g., const ClassName&). This ensures that the function does not modify the original objects and avoids unnecessary copying, making it more efficient, especially for large objects. In normal operator overloads, while you may also use const references, the left operand is handled through the this pointer.
- ### 3. Access to Class Members:
    - Friend functions can directly access private and protected members of the class for both parameters, since they are declared as friends. In contrast, member functions can access their own class members directly through this, but they do not have access to the private members of other instances unless they are friends.
- ### 4.Const Correctness:
    - Similar to normal overloads, parameters in friend function overloads are often marked as const to protect the original objects from modification.

#### Example: Overloading '<<' Operators
(riprende da spiegare questo esempio)

```C++
//--------------------------------Integer.hpp
#ifndef INTEGER_CLASS_H
# define INTEGER_CLASS_H

# include <iostream>

class Integer {

	public:
		Integer( int const n);
		~Intiger ( void );

		int getValue (void) const;

	private:
		int _n;
}

//'<<' overload
std::ostream& operator <<( std::ostream & o, Integer const & ths);

#endif


//--------------------------------Integer.cpp
Integer::Integer( int const n ) : _n(n) {
	std::cout << "Costructor called with value " << n << std::endl;
	return;
}

~Integer::Integer( int const n ) : _n(n) {
	std::cout << "Destructor called with value " << this->_n << std::endl;
	return;
}

int Integer::getValue(void) const {
	return this->_n;
}


//'<<' overload
std::ostream & operato<<( std::ostream & o, Integer const & ths) {
	o << rhs.getValue();
	return o;
}
```

- **'<<' overload**
    - With operator overloading for + and =, we had the current instance that allowed us to perform the operation:
    ```C++
    return_type operator op (/*instance of the current class (implicit),*/ parameter_list) 
    {
    // function body
    }
    ```
    The left-hand operator was the current instance, and the right-hand one was the passed parameter. Therefore, I cannot use the syntax for operator overloading of member functions written above.