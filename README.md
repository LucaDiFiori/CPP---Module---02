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
    - [1.OVERLOADING OPERATOR USING THE MEMBER FUNCTION SYNTAX](#1overloading-operator-using-the-member-function-syntax)
    - [2.OVERLOADING OPERATOR USING THE NON-MEMBER FUNCTION (FRIEND FUNCTION) SYNTAX](#2overloading-operator-using-the-non-member-function-friend-function-syntax)
- [CANONICAL FORM OF A CLASS](#canonical-form-of-a-class)
    - [RVALUE, LVALUE, AND RVALUE REFERENCE](#rvalue-lvalue-and-rvalue-reference)
- [WHAT ARE FIXED POINT NUMBERS?](#What-are-Fixed-Point-Numbers?)

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
## 1.OVERLOADING OPERATOR USING THE MEMBER FUNCTION SYNTAX
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
- '+' = a method of the class
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

    /*The reason we're using 'Integer' in the return type of the operator+
      method is because we're creating and returning a new Integer object
      that represents the result of the addition.
    
    we cannot simply return this->_n + rhs.getValue() because this->_n 
    and rhs.getValue() are of type int, and the return type of the function
    is expected to be an Integer object, not an int and we need to return 
    an Integer object (not just an int) to support operator chaining 
    (a + b + c)*/
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






## 2.OVERLOADING OPERATOR USING THE NON-MEMBER FUNCTION (FRIEND FUNCTION) SYNTAX
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

## Parameter list in friend function (operator overloading)
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

### Remeber
If you overload an operator with a member function, the first operand will by default be of the same class type (the current instance).
If you need to overload an operator with a different type as the first operand, you will need to use a free (non-member) function.

#### Example: Overloading '<<' Operators
With operator overloading for + and =, we had the current instance that allowed us to perform the operation:
```C++
return_type operator op (/*instance of the current class (implicit),*/ parameter_list) 
{
// function body
}
```
Now, we have to specify the left operand explicitly.

You need to overload the << operator as a non-member (friend or free) function because the left operand of the << operator is an std::ostream object, which is not part of your Integer class.

If you were to define << as a member function of Integer, it would be called on an Integer object, but in the case of std::ostream << Integer, the left operand (std::ostream) is external to the Integer class.

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

/*'<<' overload
This line declares the overload for the '<<' operator to allow output of Integer objects.
- 'std::ostream & o': The output stream (e.g., std::cout) that will be the left operand.
- 'Integer const & ths': A constant reference to the Integer object to be printed.
This is a free function (non-member) that allows us to use 'std::cout << obj' where 'obj' is an Integer instance.*/
std::ostream& operator<<(std::ostream & o, Integer const & ths);

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


/*'<<' overload
This is the definition of the '<<' operator overload for outputting Integer objects.
- 'std::ostream & o': The output stream (e.g., std::cout) to which data will be sent.
- 'Integer const & ths': A constant reference to the Integer object.
Inside the function:
- 'o << ths.getValue()' calls the getValue() method of the Integer class, which returns the private '_n' value.
- This value is sent to the output stream 'o'.
The function returns 'o' to allow chaining of '<<' operations (e.g., 'std::cout << a << b << c').

This overload in the code allows you to use the std::ostream (like std::cout) to output an Integer object in a way that looks natural, like:
Integer a(42);
std::cout << a << std::endl;*/
std::ostream & operato<<( std::ostream & o, Integer const & ths) {
	o << rhs.getValue();
	return (o); // Returns the output stream (std::ostream) to enable chaining of '<<' operations.
}
```

***
***

## CANONICAL FORM OF A CLASS
The canonical form of a class in C++ is essential for ensuring proper resource management, especially when dealing with dynamic memory. It typically involves implementing five special member functions known as the Rule of Five. Here's a detailed breakdown of each component:

## 1. Destructor
A destructor is a special member function that is called when an object goes out of scope or is explicitly deleted. Its main purpose is to release resources that the object may have acquired during its lifetime.

## 2. Copy Constructor
A copy constructor initializes a new object as a copy of an existing object. It is called when an object is passed by value, returned from a function, or explicitly copied.
```C++
class MyClass {
public:
    MyClass(const MyClass& other) {
        // Copy constructor logic (e.g., deep copy)
    }
};

/*Note: in'const MyClass& other' const keyword guarantees that the object you are copying from will not be altered during the process.*/
```

## 3. Copy Assignment Operator
The copy assignment operator assigns the values from one existing object to another existing object. It is called when an object is assigned a value from another object of the same type.
```C++
class MyClass {
public:
    MyClass& operator=(const MyClass& other) {
        // Check for self-assignment
        if (this != &other) {
            // Copy assignment logic (e.g., deep copy)
        }
        return *this;
    }
};
```

## 4. Move Constructor
A move constructor transfers resources from a temporary object to a new object. It is used to optimize performance by avoiding unnecessary copies, especially for classes that manage dynamic resources.
```C++
class MyClass {
public:
    MyClass(MyClass&& other) noexcept {
        // Move constructor logic (e.g., transfer ownership)
    }
};
```

## 5. Move Assignment Operator
The move assignment operator transfers resources from a temporary object to an existing object. Similar to the move constructor, it helps in managing resources more efficiently.
```C++
class MyClass {
public:
    MyClass& operator=(MyClass&& other) noexcept {
        // Check for self-assignment
        if (this != &other) {
            // Move assignment logic (e.g., transfer ownership)
        }
        return *this;
    }
};
```

### Complete Example
```C++
#include <iostream>
#include <cstring>

class String {
private:
    char* data; // Pointer to hold the character array for the string
public:
    // Constructor: Initializes the String object with the given C-string
    // If no argument is provided, it defaults to an empty string
    String(const char* str = "") {
        data = new char[strlen(str) + 1]; // Allocate memory for the string
        strcpy(data, str); // Copy the input string into the allocated memory
    }

    // Destructor: Cleans up the allocated memory when the String object is destroyed
    ~String() {
        delete[] data; // Deallocate memory for the character array
    }

    // Copy Constructor: Creates a new String object as a copy of an existing one
    String(const String& other) {
        data = new char[strlen(other.data) + 1]; // Allocate memory for the new string
        strcpy(data, other.data); // Copy the data from the existing object
    }

    // Copy Assignment Operator: Assigns values from one String object to another existing one
    String& operator=(const String& other) {
        if (this != &other) { // Check for self-assignment
            delete[] data; // Free existing resource to avoid memory leak
            data = new char[strlen(other.data) + 1]; // Allocate new memory
            strcpy(data, other.data); // Copy data from the other object
        }
        return *this; // Return the current object
    }

    // Move Constructor: Transfers ownership of resources from a temporary object to a new one
    String(String&& other) noexcept : data(other.data) {
        other.data = nullptr; // Leave the moved-from object in a valid state (nullptr)
    }


    // Move Assignment Operator: Transfers ownership of resources from a temporary object to an existing one

    //See: rvalue, lvalue and rvalue reference at the end of the example
    String& operator=(String&& other) noexcept {
        if (this != &other) { // Check for self-assignment
            delete[] data; // Free existing resource to avoid memory leak
            data = other.data; // Transfer ownership of the resource
            other.data = nullptr; // Leave the moved-from object in a valid state (nullptr)
        }
        return *this; // Return the current object
    }

    // Function to display the string
    void display() const {
        std::cout << data << std::endl; // Print the stored string to the console
    }
};

int main() {
    String str1("Hello"); // Create a String object initialized with "Hello"
    String str2 = str1; // Calls copy constructor to create str2 as a copy of str1
    str2.display(); // Output: Hello

    String str3("World"); // Create another String object initialized with "World"
    str3 = str1; // Calls copy assignment operator to assign str1's value to str3
    str3.display(); // Output: Hello

    String str4 = std::move(str1); // Calls move constructor to transfer ownership from str1 to str4
    str4.display(); // Output: Hello
    str1.display(); // Output: (undefined behavior, str1 is moved-from and has been set to nullptr)

    return 0;
}
```
- **Destructor**: Always release resources to prevent memory leaks.
- **Copy Constructor**: Make a deep copy of resources to ensure each object has its own copy.
- **Copy Assignment Operator**: Handle self-assignment and release existing resources before copying.
- **Move Constructor**: Efficiently transfer resources from temporary objects.
- **Move Assignment Operator**: Similar to the move constructor but for existing objects.

***

## RVALUE, LVALUE, AND RVALUE REFERENCE
- **Definition** :In the line String& operator=(String&& other) noexcept, the String&& syntax represents an rvalue (short for "right value) reference. An rvalue is a term used in C++ to refer to temporary objects or values that do not have a persistent memory address.
    - **Temporary Objects**: Rvalues are typically the result of expressions that yield temporary values. For example, literals, temporary objects returned from functions, and the results of operations (like addition or function calls) are considered rvalues.
    - **No Identifiable Location**: Rvalues cannot be assigned to directly because they do not have a memory address that can be referenced for an extended period. Instead, they exist only during the evaluation of an expression.

    **example**
    ```C++
    int a = 5;
    int b = 10;
    int sum = a + b; // The result of `a + b` is an rvalue

    //------------------------------

    String createString() {
    return String("Hello, World!"); // This returns a temporary String object
    }

    String str = createString(); // `createString()` returns an rvalue
    ```

- **RVALUE VS LVALUE**:
    - **Lvalues**:
        - An lvalue (locator value) refers to an object that occupies a specific location in memory and has a persistent address. Lvalues can be assigned values.
        - Example: Variables like int x = 5; (where x is an lvalue).
    - **Rvalues**:
        - As mentioned, rvalues are temporary and do not have a persistent address. You cannot take the address of an rvalue using the address-of operator (&).
        - Example: The expression 5 + 10 is an rvalue because it produces a temporary result.

- **RVALUE REFERENCE**: 
    - In the line String& operator=(String&& other) noexcept, the String&& syntax represents an rvalue reference.
    - **Definition**: An rvalue reference is a type of reference that can bind to temporary objects (rvalues). It allows you to differentiate between lvalues (objects with a persistent address) and rvalues (temporary objects that can be moved from).
    - **Syntax of an Rvalue Reference**: 
        - **Declaration**: To declare an rvalue reference, you simply append && to the type name
        ```C++
        int&& myRvalueRef = 5; // myRvalueRef is an rvalue reference to the temporary integer 5
        // int&& indicates that myRvalueRef can bind to an rvalue of type int.
        ```
    - **Purpose**: The main purpose of rvalue references is to enable move semantics. Move semantics allow you to transfer resources (like dynamic memory) from one object to another without copying, which can improve performance and reduce unnecessary resource allocation and deallocation.
    - **Usage in Move Assignment**: In the context of the move assignment operator
        - The other parameter is an rvalue reference, meaning it can bind to a temporary String object.
        - When you call std::move(str1) in your code, it casts str1 to an rvalue, allowing the move assignment operator to take ownership of its resources (like the data pointer) without copying them.

***

From now on, our classes will be equipped with:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor"

**Example: Canonical form class**
```C++
//---------------------------------Sample.class.hpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

# include <iostream>

class Sample {
    public:
        Sample (void); //Canonical: Default constuctor
        Sample (int const n); //Canonical: Parametric Constructor
        Sample (Sample const & src); //Canonical: Copy constructor 
        Sample & operator=(Sample const & rhs); //Canonical: Copy assignment operator
        /* Copy constructor vs Copy assignment operator:
            - Copy constructor: A new instance is created
            - Copy assignment operator: Update of the current instance
        */
        ~Sample (void); //Canonical: Destructor

        int getFoo(void) const;

    private:
        int _foo;
};

//This overloading is non canonical but usefull
std::ostream & operator<<(std::ostream& o, Sample const& i);

#endif

//------------------------------------Sample.cpp
#include <iostream
#include "Sample.class.h>

//Canonical: Default constuctor
Sample::sample(void) : _foo(0)
{
    std::cout << "Default Constructor called" << std::endl;
    return;
}

// Canonical: Parametric Constructor
Sample::Sample(int const n) : _foo(n)
{
    std::cout << "Parametric Constructor called" << std::endl;  
    return;
}

// Canonical: Copy Constructor
Sample::Sample(Sample const & src)
{
    std::cout << "Copy Constructor called" << std::endl;
    // Uses the copy assignment operator to copy the content of src into the current object
    *this = src;
    return;

    /*Note: '*this = src;'
    this is a pointer that refers to the object on which the method was called. 
    By dereferencing this with *, you get a reference to the current object. 
    So, *this = src; assigns the state of src to the current object 
    (which this points to).*/
}

// Canonical: Copy Assignment Operator
Sample& Sample::operator=(Sample const& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    // Avoid self-assignment by checking if the current object and rhs are different
    if (this != &rhs)
        this->_foo = rhs.getFoo(); /* Assigns the value of _foo from rhs
                                  (right-hand side) to the current object*/
    return (*this);

    /*Note: The return type is Sample& :
            - To allow assignment chaining
            -  Ensures that the modified object is returned, Since the purpose
               of the assignment operator is to modify the left-hand side
              object
              
      Note: 'if (this != &rhs)'
            this is a pointer to the current object, so you use this != &rhs 
            to compare memory addresses. Infact, when you have a reference, 
            like Sample const& rhs, &rhs gives you the memory address of 
            the object
    */
}   

// Canonical: Destructor
Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

// Getter function
//declared as const since it doesn't modify the object
int Sample::getFoo(void) const
{
    return this->_foo;
}

//-------------------------------main.cpp
#include <iostream
#include "Sample.class.h>

int main()
{
    Sample instance1;
    Sample instance2(42)
    Sample instance1(instance1);

    std::cout << intance1 << std::endl;
    std::cout << intance2 << std::endl;
    std::cout << intance3 << std::endl;

    //istance3 is updated with the content of instance2
    instance3 = instance2;
    std::cout << intance3 << std::endl;
}
```

**Output**
```BASH
Default Constructor called
Parametric Constructor called
copy Constructor called
Assignement operator called
The value of _foo is : 0
The value of _foo is : 42
The value of _foo is : 0
Assignement operator called
The value of _foo is : 42
Destructor called
Destructor called
Destructor called
```

*Note:* There are cases where the default constructor is unnecessary. In these cases, it is sufficient to include it as a private method


***
***

## WHAT ARE FIXED POINT NUMBERS?
Fixed-point numbers are a way to represent real numbers (like 3.14, -2.5, etc.) using integers. They offer a simpler and more efficient alternative to floating-point numbers, especially in systems with limited resources (such as embedded systems, graphics, or sound processing).

Unlike floating-point numbers, which allow for a floating decimal point (hence the name), fixed-point numbers have a fixed number of bits used for the fractional part. The position of the "decimal point" is fixed and doesn't move, which is why they are called fixed-point.

## Integer Representation of Real Numbers
Fixed-point numbers are stored as integers, but they represent real numbers by scaling the integer. The scaling is determined by how many bits are used to represent the fractional part.
- The "integer part" is stored in the upper bits.
- The "fractional part" is stored in the lower bits.
To make the real number fit into an integer, we scale it by multiplying by some power of 2. This way, the fractional part of the number is represented using integer arithmetic.

## Why Scaling?
Scaling is needed because a real number can’t be stored directly as an integer. To store the fractional part, we scale the number (essentially shifting the decimal point to the right) so that it becomes a whole number (integer). Then, when we need to use the real value again, we can "scale it back" by dividing.

## Example of Scaling
Suppose we want to represent the real number 3.75 in fixed-point format with 8 fractional bits.
### 1: Scale the real number
We multiply the real number 3.75 by 2^8 = 256 (because we have 8 fractional bits). This gives:
```BASH
3.75 * 256 = 960
```
The scaled value is 960. This is what we store as an integer in memory.

### 2: Storing the value
Now, we store 960 in an integer variable. This integer represents the real number 3.75 in fixed-point format.

### 3: Scaling back to the real number
To get the original real number back, we divide the stored integer (960) by 256:
```BASH
960 / 256 = 3.75
```
This gives us the real number 3.75 again.

## Bit Shifting Overview:
- **Left shift (<<)**: Multiplies the number by powers of 2 (shifting bits to the left).
- **Right shift (>>)**: Divides the number by powers of 2 (shifting bits to the right).

## Convert an intiger to fixed-point
To convert an integer number to a fixed-point representation, you need to scale the integer by the appropriate power of 2, based on the number of fractional bits. Here's a step-by-step explanation of how to do it:
- **Choose the number of fractional bits**: This determines how much precision you want for the fractional part. In your case, let’s assume you are using 8 fractional bits.
- **Scale the integer**: To convert an integer to its fixed-point representation, you need to scale it by multiplying the integer by 2^fractional_bits. For 8 fractional bits, this means multiplying by 2^8 = 256

#### Example
Let’s say you want to convert the integer 5 into a fixed-point number with 8 fractional bits.
- Integer: The number you want to convert is 5.à
- Scaling: You multiply the integer by 2^8. It means shifting 8 beats to the left
```C++
int value = 5;
const int fractional_bits = 8
fixed_point_value = value << fractional_bits;  // Equivalent to 5 * 256 = 1280;
```

## Convert a fixed-point number back to a real number
When you want to convert a fixed-point number back to a real number (from its scaled integer form), you divide (couse the fixed-point is stored as an int) by 2^8 which is equivalent to a right shift by 8 bits.

For instance, dividing by 2^8 (256) can be written as:
```C++
int realValue = fixedPointValue >> 8;
```

## Convert a floating-point number to a fixed-point
Converting a floating-point number to a fixed-point number involves a few straightforward steps. You need to scale the floating-point value into an integer representation using a fixed number of fractional bits. Let’s go through the steps in detail.
- **Choose the Number of Fractional Bits**: Determine how many bits you will use for the fractional part. For example, let’s say you use 8 fractional bits.
- **Determine the Scaling Factor**: The scaling factor is 2^fractional bits
- **Multiply the Floating-Point Number by the Scaling Factor**: This will convert the floating-point number into an integer representation. The formula looks like this:
fixed-point value = floating-point number × 256
- **Store the Result**: Store the resulting integer as the fixed-point representation.
- **Handle Rounding (optional)**: Depending on your needs, you may want to round the result to the nearest integer instead of just truncating it.

**Code Example for Conversion**
```C++
class Fixed 
{
private:
    int _value;  // Fixed-point value (scaled)
    static const int _fractionalBits = 8;  // Number of fractional bits

public:
    // Constructor that takes a floating-point number and converts it to fixed-point
    Fixed(float floatValue) {
        _value = static_cast<int>(round(floatValue * (1 << _fractionalBits)));  // Scale and round
        std::cout << "Floating-point converted to fixed-point: " << _value << std::endl;
    }
}
```
**Code explanation**
```C++
_value = static_cast<int>(round(floatValue * (1 << _fractionalBits)));
```
- **floatValue * (1 << _fractionalBits)**:
    - 1 << _fractionalBits: This uses the left shift operator to calculate 2 ^ fractionalbits
    - 1 << 8 is equivalent to 2^8 which equals 256.
    - This operation converts the floating-point number into a scaled integer value.
- **round(...)**:
    - This function rounds the scaled value to the nearest integer. This step is crucial because it helps avoid truncation errors, which could occur if you simply converted the floating-point number to an integer without rounding.
- **static_cast<int>(...)**:
    - **Overview of static_cast**:
        - static_cast<Type>(expression) converts the expression to the specified Type.
        - It can be used to convert between compatible types, such as Primitive types and User-defined types
        - static_cast performs checks at compile time. If the conversion is not valid, it generates a compilation error, reducing the risk of runtime errors associated with invalid conversions.
    - After rounding, we use static_cast<int>() to convert the rounded value from a floating-point type (which could be a float or double) back to an integer.
    - This is necessary because _value is defined as an int, and we need to ensure that the data type matches.

### scaling intiger vs float
The use of shifting in the integer and floating-point conversions reflects the differences in how fixed-point representation is typically implemented and how integer values are handled compared to floating-point values.
```C++
//Intiger to fixed
fixed_point_value = value << fractional_bits;

//float to fixed
fixed_point_value = static_cast<int>(round(value * (1 << fractional_bits)));
```
- **Intiger conversion**: When converting an integer to a fixed-point number, you often directly scale the integer value by shifting:
    - **Bit Shifting**: The expression value << fractional_bits shifts the bits of value to the left by fractional_bits positions.
    - **Effect of Left Shift**: Left shifting by n bits is equivalent to multiplying by 2^n. In this case, shifting by 8 bits multiplies the integer value by 2^8 = 256
    - **Fixed-point Representation**: This approach directly converts the integer to its fixed-point representation by scaling it. For example, if value is 5, the result of 5 << 8 is 1280 which represents 5.0 in fixed-point format with 8 fractional bits.

- **Floating-point Conversion**: When converting a floating-point number to a fixed-point representation, the scaling is done differently
    - **Scaling Factor**: The expression (1 << _fractionalBits) calculates the scaling factor, which is 2^8 = 256 when _fractionalBits is 8
    - **Why Multiply Instead of Shift**: When you multiply a floating-point value by this scaling factor, you are effectively scaling the float into the fixed-point range. This conversion needs to account for fractional values, so you cannot simply shift the float; instead, you multiply.

#### Summary
- **Integer Conversion**: Uses left shifting (*value << fractional_bits*) to efficiently scale the integer value to fixed-point format. 
- **Floating-point Conversion**: Uses multiplication (*value * (1 << fractional_bits)*) with the scaling factor derived from a left shift to convert the float into a fixed-point representation. The use of multiplication is necessary to account for possible fractional parts in floating-point numbers, which do not apply to integer values.


## Convert fixed-point back to floating-point
To convert a fixed-point number back to a floating-point number, you need to reverse the scaling process that was done when converting from floating-point to fixed-point. This is achieved by dividing the fixed-point value by the same scaling factor that was used during the initial conversion.
```C++
float float_value = fixed_point_value / static_cast<float>(1 << fractional_bits);
```