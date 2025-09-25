#include <iostream>
#include <chrono>
#include <thread>  
#include <string>
#include <math.h>
#include <windows.h>  
using namespace std;
int score = 0; // Global score counter
void printCenter(string text, int width = 100) {
    //int len = text.length();
    int spaces = width / 2;
    if (spaces > 0) {
        cout << string(spaces, ' '); // طباعة مسافات
    }
    cout << text << endl;
}
void _printCenter(string text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int rows, cols;

    // الحصول على حجم الشاشة (الكونسول)
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;   // عدد السطور
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;   // عدد الأعمدة

    // حساب النص عموديًا
    int verticalSpaces = rows / 2;
    for (int i = 0; i < verticalSpaces; i++) {
        cout << endl;
    }

    // حساب النص أفقيًا
    int len = text.length();
    int spaces = (cols - len) / 2;
    if (spaces > 0) {
        cout << string(spaces, ' ');
    }

    cout << text << endl;
}
void startWindow() {
    string Welcome = "Welcom", _dot = ".";
    for (short i = 0; i < 4; i++)
    {
        _printCenter(Welcome);
        this_thread::sleep_for(chrono::seconds(2));
        Welcome += _dot;
        system("cls");
    }
}
bool validateInput(char answer) {
    answer = tolower(answer);
    return (answer >= 'a' && answer <= 'd');
}
char getValidatedAnswer() {
    char answer;
    while (true) {
        cin >> answer;
        if (validateInput(answer)) {
            return tolower(answer); // نخليها كلها lowercase
        }
        else {
            cout << "❌ Invalid input! Please enter a, b, c, or d: ";
        }
    }
}
void scoreScreen()
{
    // cout << "\nYour total score: " << score << "\nGoodbye!\n";
    system("cls");
    if (score < ceil(score / 2)) {
        printCenter("congratulation!");
        this_thread::sleep_for(chrono::seconds(5));
        cout << "\nYour total score: " << score << "\nGoodbye!\n";
    }
    else
    {
        printCenter("fail");
        cout << "\nYour total score: " << score << "\nGoodbye!\n";
        this_thread::sleep_for(chrono::seconds(5));

    }
}


void explainVar() {
    printCenter("=== Variables in C++ ===");
    cout << "Variables are used to store data in memory.\n";
    cout << "Example: int age = 20;\n";
    cout << "=================================================\n\n";
}
void quizVariables() {
    char answer;

    printCenter("===Quiz: Variables===");

    cout << "1) Which keyword is used to declare a variable in C++?\n";
    cout << "a) var\nb) let\nc) int\nd) dim\n";
    answer = getValidatedAnswer();
    if (answer == 'c') score++;

    cout << "2) What is the correct way to assign 10 to variable x?\n";
    cout << "a) x = 10;\nb) int x = 10;\nc) let x = 10;\nd) var x = 10;\n";
    answer = getValidatedAnswer();
    if (answer == 'a' || answer == 'b') score++;

    cout << "3) Which data type is used for decimal values?\n";
    cout << "a) int\nb) double\nc) char\nd) bool\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "4) What happens if you use an uninitialized variable?\n";
    cout << "a) Garbage value\nb) Zero\nc) Compilation error\nd) None\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "5) Which symbol assigns a value?\n";
    cout << "a) ==\nb) =\nc) :=\nd) =>\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;
}

void explainDataTypes() {
    printCenter("===Data Types in C++===");
    cout << "1) Basic Data Types:\n";
    cout << "   - int: Stores whole numbers (e.g., 10, -5)\n";
    cout << "   - float: Stores decimal numbers with single precision (e.g., 3.14)\n";
    cout << "   - double: Stores decimal numbers with double precision\n";
    cout << "   - char: Stores a single character (e.g., 'A')\n";
    cout << "   - bool: Stores true or false values\n\n";

    cout << "2) Derived Data Types:\n";
    cout << "   - Arrays, Strings, Pointers, References\n\n";

    cout << "3) Example:\n";
    cout << "      int age = 20;\n";
    cout << "      float pi = 3.14;\n";
    cout << "      char grade = 'A';\n";
    cout << "      bool isStudent = true;\n";
    cout << "      cout << age << \" \" << pi << \" \" << grade;\n\n";

    cout << "=================================================\n\n";


}
void quizDataTypes() {
    char answer;
    printCenter("===Quiz: Data Types===");

    cout << "1) Which data type stores whole numbers?\n";
    cout << "a) int\nb) float\nc) char\nd) bool\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "2) Which data type stores true/false values?\n";
    cout << "a) int\nb) bool\nc) double\nd) string\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "3) Which type is used for single characters?\n";
    cout << "a) int\nb) char\nc) string\nd) word\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "4) Which data type stores decimal numbers?\n";
    cout << "a) int\nb) float\nc) bool\nd) char\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "5) Which data type is larger: float or double?\n";
    cout << "a) float\nb) double\nc) same\nd) depends\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;
}

void explainInputOutput() {
    printCenter("===Input and Output in C++===");

    cout << "1) Output (cout):\n";
    cout << "   - Used to display text or values on the console.\n";
    cout << "   Example:\n";
    cout << "      cout << \"Hello World\";\n\n";

    cout << "2) Input (cin):\n";
    cout << "   - Used to take input from the user.\n";
    cout << "   Example:\n";
    cout << "      int age;\n";
    cout << "      cin >> age;\n";
    cout << "      cout << \"Your age is: \" << age;\n\n";

    cout << "3) getline for strings:\n";
    cout << "   - Used to read full lines (including spaces).\n";
    cout << "   Example:\n";
    cout << "      string name;\n";
    cout << "      getline(cin, name);\n";
    cout << "      cout << \"Hello, \" << name;\n\n";

    cout << "4) Chaining:\n";
    cout << "   - We can combine multiple inputs/outputs.\n";
    cout << "   Example:\n";
    cout << "      int x, y;\n";
    cout << "      cin >> x >> y;\n";
    cout << "      cout << \"Sum = \" << x + y;\n\n";

    cout << "=================================================\n\n";

}
void quizInputOutput() {
    char answer;
    printCenter("===Input and Output===");

    cout << "1) Which operator is used for output in C++?\n";
    cout << "a) <<\nb) >>\nc) :=\nd) <--\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "2) Which operator is used for input in C++?\n";
    cout << "a) <<\nb) >>\nc) =\nd) scanf\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "3) Which header file is needed for cin and cout?\n";
    cout << "a) <stdio.h>\nb) <iostream>\nc) <string>\nd) <input.h>\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "4) Which function is used to print text in C++?\n";
    cout << "a) printf\nb) echo\nc) cout\nd) display\n";
    answer = getValidatedAnswer();
    if (answer == 'c') score++;

    cout << "5) Which function is used to read input from user?\n";
    cout << "a) cin\nb) scanf\nc) input\nd) getline\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;
}

void explainConstants() {
    printCenter("===Constants in C++===");

    cout << "1) What is a Constant?\n";
    cout << "   - A constant is a value that cannot be changed during program execution.\n\n";

    cout << "2) Types of Constants:\n";
    cout << "   - Literal constants: numbers, characters, strings (e.g., 10, 'A', \"Hello\")\n";
    cout << "   - const keyword: makes a variable unchangeable.\n";
    cout << "   - #define: preprocessor directive to define constants.\n\n";

    cout << "3) Using const:\n";
    cout << "   Example:\n";
    cout << "      const float PI = 3.14;\n";
    cout << "      cout << PI;\n";
    cout << "   // PI cannot be modified later.\n\n";

    cout << "4) Using #define:\n";
    cout << "   Example:\n";
    cout << "      #define MAX 100\n";
    cout << "      cout << MAX;\n";
    cout << "   // MAX acts as a constant throughout the program.\n\n";

    cout << "=================================================\n\n";

}
void quizConstants() {
    char answer;
    printCenter("===Quiz: Constants===");

    cout << "1) Which keyword defines a constant in C++?\n";
    cout << "a) const\nb) final\nc) static\nd) define\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "2) Which preprocessor is used to define constants?\n";
    cout << "a) #define\nb) #include\nc) #const\nd) #static\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "3) Can a const variable be changed after initialization?\n";
    cout << "a) Yes\nb) No\nc) Sometimes\nd) Only for int\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "4) What is the output of: const int x=5; cout<<x;\n";
    cout << "a) Error\nb) Garbage\nc) 5\nd) 0\n";
    answer = getValidatedAnswer();
    if (answer == 'c') score++;

    cout << "5) Which is better for constants in modern C++?\n";
    cout << "a) const\nb) #define\nc) var\nd) static\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;
}

void expOp() {
    cout << "\n=== Operators in C++ ===\n";
    cout << "Arithmetic (+,-,*,/,% )\nRelational (==, !=, >, < )\nLogical (&&, ||, !)\n";
    cout << "=================================================\n\n";
}
void quizOperators() {
    char answer;
    printCenter("===Quiz: Operators===");

    cout << "1) Which operator is used for addition?\n";
    cout << "a) -\nb) +\nc) *\nd) /\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "2) Which operator compares equality?\n";
    cout << "a) =\nb) ==\nc) !=\nd) <=\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "3) Which is a logical operator?\n";
    cout << "a) &&\nb) ++\nc) %\nd) --\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "4) Which operator finds remainder?\n";
    cout << "a) /\nb) %\nc) *\nd) -\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "5) Which operator increases a value by 1?\n";
    cout << "a) ++\nb) --\nc) +=\nd) ==\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;
}

void explainControlFlow() {
    printCenter("===Control Flow in C++===");

    cout << "1) if / else statement:\n";
    cout << "   - Used to make decisions based on a condition.\n";
    cout << "   Example:\n";
    cout << "      int x = 10;\n";
    cout << "      if (x > 5) {\n";
    cout << "          cout << \"x is greater than 5\";\n";
    cout << "      } else {\n";
    cout << "          cout << \"x is less or equal to 5\";\n";
    cout << "      }\n\n";

    cout << "2) switch statement:\n";
    cout << "   - Used to select one case from multiple options.\n";
    cout << "   Example:\n";
    cout << "      int day = 2;\n";
    cout << "      switch (day) {\n";
    cout << "          case 1: cout << \"Monday\"; break;\n";
    cout << "          case 2: cout << \"Tuesday\"; break;\n";
    cout << "          default: cout << \"Other\";\n";
    cout << "      }\n\n";


    cout << "3) for loop:\n";
    cout << "   - Used when the number of iterations is known.\n";
    cout << "   Example:\n";
    cout << "      for (int i = 0; i < 5; i++) {\n";
    cout << "          cout << i << \" \";\n";
    cout << "      }\n\n";

    cout << "4) while loop:\n";
    cout << "   - Checks the condition first before executing.\n";
    cout << "   Example:\n";
    cout << "      int n = 3;\n";
    cout << "      while (n > 0) {\n";
    cout << "          cout << n;\n";
    cout << "          n--;\n";
    cout << "      }\n\n";

    cout << "5) do-while loop:\n";
    cout << "   - Executes the block at least once before checking the condition.\n";
    cout << "   Example:\n";
    cout << "      int n = 0;\n";
    cout << "      do {\n";
    cout << "          cout << n;\n";
    cout << "          n++;\n";
    cout << "      } while (n < 3);\n\n";


    cout << "6) break & continue:\n";
    cout << "   - break: Immediately stops the loop.\n";
    cout << "   - continue: Skips the current iteration and moves to the next.\n";
    cout << "   Example:\n";
    cout << "      for (int i = 0; i < 5; i++) {\n";
    cout << "          if (i == 2) continue; // skips 2\n";
    cout << "          if (i == 4) break;    // stops at 4\n";
    cout << "          cout << i << \" \";\n";
    cout << "      }\n\n";

    cout << "=================================================\n\n";

}
void quizControlFlow() {
    char answer;
    printCenter("===Quiz: Control Flow===");

    cout << "1) Which statement is used for decision making?\n";
    cout << "a) loop\nb) if\nc) case\nd) break\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "2) Which statement chooses between many options?\n";
    cout << "a) if-else\nb) switch\nc) loop\nd) return\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "3) Which loop executes at least once?\n";
    cout << "a) for\nb) while\nc) do-while\nd) none\n";
    answer = getValidatedAnswer();
    if (answer == 'c') score++;

    cout << "4) Which keyword stops a loop?\n";
    cout << "a) stop\nb) return\nc) break\nd) exit\n";
    answer = getValidatedAnswer();
    if (answer == 'c') score++;

    cout << "5) Which keyword skips the current loop iteration?\n";
    cout << "a) skip\nb) continue\nc) pass\nd) break\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;
}

void explainFunctions() {
    printCenter("===Functions in C++===");

    cout << "1) What is a Function?\n";
    cout << "   - A function is a block of code that performs a specific task.\n";
    cout << "   - It helps to organize code, reduce repetition, and improve readability.\n\n";

    cout << "2) Structure of a Function:\n";
    cout << "   returnType functionName(parameters) {\n";
    cout << "       // body of function\n";
    cout << "   }\n\n";

    cout << "3) Example:\n";
    cout << "   int add(int a, int b) {\n";
    cout << "       return a + b;\n";
    cout << "   }\n\n";
    cout << "   int main() {\n";
    cout << "       cout << add(3, 4); // Output: 7\n";
    cout << "   }\n\n";

    cout << "4) Types of Functions:\n";
    cout << "   - Library functions: built-in (e.g., sqrt(), pow()).\n";
    cout << "   - User-defined functions: created by the programmer.\n\n";

    cout << "5) Advantages:\n";
    cout << "   - Code reusability.\n";
    cout << "   - Easier debugging.\n";
    cout << "   - Better readability.\n\n";

    cout << "=================================================\n\n";

}
void quizFunctions() {
    char answer;
    printCenter("===Quiz: Functions===");

    cout << "1) Which keyword is used to define a function in C++?\n";
    cout << "a) func\nb) function\nc) void\nd) def\n";
    answer = getValidatedAnswer();
    if (answer == 'c') score++;

    cout << "2) What must every C++ program have?\n";
    cout << "a) print()\nb) main()\nc) start()\nd) run()\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "3) What is the return type of a function that does not return anything?\n";
    cout << "a) int\nb) void\nc) null\nd) none\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "4) How can we pass a value to a function?\n";
    cout << "a) Parameters\nb) Variables\nc) Return\nd) Call\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "5) Which statement ends a function and sends back a value?\n";
    cout << "a) stop\nb) end\nc) return\nd) break\n";
    answer = getValidatedAnswer();
    if (answer == 'c') score++;
}

void explainArrays() {
    printCenter("===Arrays in C++===");

    cout << "1) What is an Array?\n";
    cout << "   - An array is a collection of elements of the SAME data type.\n";
    cout << "   - Stored in contiguous (continuous) memory locations.\n";
    cout << "   - Each element is accessed using an INDEX starting from 0.\n\n";

    cout << "2) Declaring an Array:\n";
    cout << "   Example:\n";
    cout << "      int numbers[5]; // declares an array of 5 integers\n\n";

    cout << "3) Initializing an Array:\n";
    cout << "   Example:\n";
    cout << "      int arr[5] = {10, 20, 30, 40, 50};\n";
    cout << "      cout << arr[0]; // prints 10\n\n";

    cout << "4) Iterating through an Array:\n";
    cout << "   Example:\n";
    cout << "      for (int i = 0; i < 5; i++) {\n";
    cout << "          cout << arr[i] << \" \";\n";
    cout << "      }\n\n";

    cout << "5) Multi-Dimensional Arrays:\n";
    cout << "   Example (2D Array):\n";
    cout << "      int matrix[2][3] = {{1,2,3},{4,5,6}};\n";
    cout << "      cout << matrix[1][2]; // prints 6\n\n";

    cout << "=================================================\n\n";

}
void quizArrays() {
    char answer;

    printCenter("===Quiz: Arrays===");

    cout << "1) Which index does an array start with in C++?\n";
    cout << "a) 0\nb) 1\nc) -1\nd) depends\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "2) What is the correct way to declare an array of 5 ints?\n";
    cout << "a) int arr[5];\nb) int arr;\nc) array arr(5);\nd) int arr{5};\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "3) Which operator is used to access array elements?\n";
    cout << "a) ()\nb) []\nc) {}\nd) ->\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "4) What is the last valid index of arr[10]?\n";
    cout << "a) 10\nb) 9\nc) 11\nd) 0\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "5) Which is true about arrays?\n";
    cout << "a) Fixed size\nb) Dynamic by default\nc) Can resize anytime\nd) Stores mixed types\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;
}

void explainString() {
    printCenter("===Strings in C++===");
    cout << "1) Definition:\n";
    cout << "   - A string is a sequence of characters used to store text.\n";
    cout << "   - In C++, we use the <string> library.\n";
    cout << "   Example:\n";
    cout << "      string name = \"Ahmed\";\n\n";

    cout << "2) Common Operations:\n";
    cout << "   - Access characters: name[0]\n";
    cout << "   - Get length: name.length()\n";
    cout << "   - Concatenation: name + \" Mohamed\"\n";
    cout << "   - Input from user: getline(cin, name)\n\n";

    cout << "3) Example:\n";
    cout << "      string text = \"Hello\";\n";
    cout << "      cout << text + \" World\";  // Output: Hello World\n\n";

    cout << "=================================================\n\n";

}
void quizStrings() {
    char answer;

    printCenter("===Quiz: Strings===");

    cout << "1) Which header file is required for std::string?\n";
    cout << "a) <string>\nb) <cstring>\nc) <iostream>\nd) <stdlib.h>\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "2) How to find the length of a string `s`?\n";
    cout << "a) s.length()\nb) s.size()\nc) Both a & b\nd) strlen(s)\n";
    answer = getValidatedAnswer();
    if (answer == 'c') score++;

    cout << "3) Which operator is used to concatenate strings?\n";
    cout << "a) +\nb) &\nc) .\nd) ,\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "4) How to access the first character of string `s`?\n";
    cout << "a) s[0]\nb) s(0)\nc) first(s)\nd) s{0}\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "5) What does s.empty() return?\n";
    cout << "a) Length of s\nb) true if empty\nc) false if empty\nd) Deletes string\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;
}

void explainFileHandling() {
    printCenter("===File Handling in C++ ===");

    cout << "In C++, files are used to store data permanently on disk.\n";
    cout << "The <fstream> header provides three main classes:\n\n";

    cout << "1) ifstream (Input File Stream)\n";
    cout << "   - Used to read data from a file.\n";
    cout << "   Example:\n";
    cout << "      ifstream inFile(\"data.txt\");\n";
    cout << "      string text;\n";
    cout << "      inFile >> text;\n";
    cout << "      inFile.close();\n\n";

    cout << "2) ofstream (Output File Stream)\n";
    cout << "   - Used to write data to a file.\n";
    cout << "   Example:\n";
    cout << "      ofstream outFile(\"data.txt\");\n";
    cout << "      outFile << \"Hello File!\";\n";
    cout << "      outFile.close();\n\n";

    cout << "3) fstream (File Stream)\n";
    cout << "   - Can be used for both reading and writing.\n";
    cout << "   Example:\n";
    cout << "      fstream file(\"data.txt\", ios::in | ios::out);\n";
    cout << "      file << \"Update data\";\n";
    cout << "      file.close();\n\n";

    cout << "File Opening Modes:\n";
    cout << "   ios::in     → Open for reading.\n";
    cout << "   ios::out    → Open for writing (overwrite existing).\n";
    cout << "   ios::app    → Append new data at the end.\n";
    cout << "   ios::binary → Open in binary mode.\n\n";

    cout << "Important:\n";
    cout << "   - Always close the file using close().\n";
    cout << "   - Check if a file opened successfully using is_open().\n\n";

    cout << "Example with check:\n";
    cout << "   ifstream file(\"data.txt\");\n";
    cout << "   if (file.is_open()) {\n";
    cout << "       cout << \"File opened successfully!\";\n";
    cout << "   } else {\n";
    cout << "       cout << \"Error opening file!\";\n";
    cout << "   }\n\n";

    cout << "=================================================\n\n";

}
void quizFiles() {
    char answer;
    printCenter("===Quiz: File Handling in C++===");

    cout << "1) Which header file is required for file handling?\n";
    cout << "a) <fstream>\nb) <file.h>\nc) <iostream>\nd) <stdio.h>\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "2) Which class is used for writing to files?\n";
    cout << "a) ifstream\nb) ofstream\nc) fstream\nd) FileWriter\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;

    cout << "3) Which class is used for reading from files?\n";
    cout << "a) ifstream\nb) ofstream\nc) fstream\nd) FileReader\n";
    answer = getValidatedAnswer();
    if (answer == 'a') score++;

    cout << "4) Which mode opens a file in append mode?\n";
    cout << "a) ios::in\nb) ios::out\nc) ios::app\nd) ios::binary\n";
    answer = getValidatedAnswer();
    if (answer == 'c') score++;

    cout << "5) What happens if you open a file with ios::out without ios::app?\n";
    cout << "a) Appends data\nb) Overwrites existing data\nc) Creates error\nd) Reads file only\n";
    answer = getValidatedAnswer();
    if (answer == 'b') score++;
}

void explainEncapsulation() {
    printCenter("===Encapsulation in C++===");
    cout << "Encapsulation means hiding data and controlling access to it.\n";
    cout << "We use private attributes and public methods.\n\n";
    cout << "Example:\n";
    cout << "class BankAccount {\n";
    cout << "  private:\n";
    cout << "    double balance;\n";
    cout << "  public:\n";
    cout << "    BankAccount(double b) { balance = b; }\n";
    cout << "    void deposit(double amount) { balance += amount; }\n";
    cout << "    double getBalance() { return balance; }\n";
    cout << "};\n";
    cout << "=================================================\n\n";
}
void quizEncapsulation() {
    printCenter("===Encapsulation Quiz===");

    cout << "Q1) What is encapsulation in C++?\n";
    cout << "a) Hiding data and methods inside a class\n";
    cout << "b) Using functions outside a class\n";
    cout << "c) Storing data in arrays\n";
    cout << "d) Multiple inheritance\n";
    char ans1 = getValidatedAnswer();
    if (ans1 == 'a') score++;

    cout << "Q2) Which keyword is used to restrict access to class members?\n";
    cout << "a) public\nb) private\nc) global\nd) const\n";
    char ans2 = getValidatedAnswer();
    if (ans2 == 'b') score++;
}

void explainInheritance() {
    printCenter("===Inheritance in C++===");
    cout << "Inheritance allows one class to inherit properties and methods from another.\n\n";
    cout << "Example:\n";
    cout << "class Animal {\n";
    cout << "  public:\n";
    cout << "    void eat() { cout << \"Eating...\\n\"; }\n";
    cout << "};\n";
    cout << "class Dog : public Animal {\n";
    cout << "  public:\n";
    cout << "    void bark() { cout << \"Woof!\\n\"; }\n";
    cout << "};\n\n";
    cout << "Dog d;\n";
    cout << "d.eat();   // from Animal\n";
    cout << "d.bark();  // from Dog\n";
    cout << "=================================================\n\n";
}
void quizInheritance() {
    printCenter("===Inheritance Quiz===");

    cout << "Q1) Which symbol is used for inheritance in C++?\n";
    cout << "a) ->\nb) :\nc) ::\nd) =>\n";
    char ans1 = getValidatedAnswer();
    if (ans1 == 'b') score++;

    cout << "Q2) Inheritance helps in?\n";
    cout << "a) Code reusability\nb) Memory allocation\nc) Operator overloading\nd) File handling\n";
    char ans2 = getValidatedAnswer();
    if (ans2 == 'a') score++;
}

void explainPolymorphism() {
    printCenter("===Polymorphism in C++===");
    cout << "Polymorphism allows the same function to behave differently depending on the object.\n\n";
    cout << "Example:\n";
    cout << "class Animal {\n";
    cout << "  public:\n";
    cout << "    virtual void sound() { cout << \"Animal sound\\n\"; }\n";
    cout << "};\n";
    cout << "class Cat : public Animal {\n";
    cout << "  public:\n";
    cout << "    void sound() override { cout << \"Meow\\n\"; }\n";
    cout << "};\n\n";
    cout << "Animal* a = new Cat();\n";
    cout << "a->sound();  // Meow\n";
    cout << "=================================================\n\n";

}
void quizPolymorphism() {
    printCenter("===Polymorphism Quiz===");

    cout << "Q1) What does polymorphism mean?\n";
    cout << "a) One function with many forms\n";
    cout << "b) Hiding data\n";
    cout << "c) Code reuse\n";
    cout << "d) Multiple classes\n";
    char ans1 = getValidatedAnswer();
    if (ans1 == 'a') score++;

    cout << "Q2) Which is an example of compile-time polymorphism?\n";
    cout << "a) Virtual functions\nb) Function overloading\nc) Abstract classes\nd) Private members\n";
    char ans2 = getValidatedAnswer();
    if (ans2 == 'b') score++;
}

void explainAbstraction() {
    printCenter("=== Abstraction in C++===");
    cout << "Abstraction means showing only essential features and hiding details.\n";
    cout << "It is achieved using abstract classes and pure virtual functions.\n\n";
    cout << "Example:\n";
    cout << "class Shape {\n";
    cout << "  public:\n";
    cout << "    virtual void draw() = 0; // Pure virtual function\n";
    cout << "};\n";
    cout << "class Circle : public Shape {\n";
    cout << "  public:\n";
    cout << "    void draw() override { cout << \"Drawing Circle\\n\"; }\n";
    cout << "};\n";
    cout << "=================================================\n\n";

}
void quizAbstraction() {
    printCenter("===Abstraction Quiz===");

    cout << "Q1) What is abstraction?\n";
    cout << "a) Showing only essential details and hiding implementation\n";
    cout << "b) Reusing code from another class\n";
    cout << "c) Creating multiple objects\n";
    cout << "d) Using templates\n";
    char ans1 = getValidatedAnswer();
    if (ans1 == 'a') score++;

    cout << "Q2) Which keyword is used to declare an abstract function?\n";
    cout << "a) virtual = 0\nb) const\nc) static\nd) override\n";
    char ans2 = getValidatedAnswer();
    if (ans2 == 'a') score++;
}

void explainClassObject() {
    printCenter("===Class & Object in C++===");
    cout << "A class is a blueprint that defines attributes and behaviors.\n";
    cout << "An object is an instance of a class.\n\n";
    cout << "Example:\n";
    cout << "class Car {\n";
    cout << "  public:\n";
    cout << "    string brand;\n";
    cout << "    void drive() { cout << \"Car is driving!\"; }\n";
    cout << "};\n\n";
    cout << "int main() {\n";
    cout << "  Car myCar;\n";
    cout << "  myCar.brand = \"BMW\";\n";
    cout << "  myCar.drive();\n";
    cout << "}\n\n";
    cout << "=================================================\n\n";

}
void quizClassObject() {
    printCenter("===Class & Object Quiz===");

    cout << "Q1) A class is?\n";
    cout << "a) An instance of an object\n";
    cout << "b) A blueprint for creating objects\n";
    cout << "c) A built-in function\n";
    cout << "d) A loop structure\n";
    char ans1 = getValidatedAnswer();
    if (ans1 == 'b') score++;

    cout << "Q2) An object is?\n";
    cout << "a) A function\n";
    cout << "b) A variable of a class type\n";
    cout << "c) A constructor\n";
    cout << "d) A keyword\n";
    char ans2 = getValidatedAnswer();
    if (ans2 == 'b') score++;
}

void explainandPracticeFunctionalprogramming()
{

    explainVar();
    explainDataTypes();

    quizVariables();
    quizDataTypes();

    explainInputOutput();
    quizInputOutput();

    explainConstants();
    quizConstants();

    expOp();
    quizOperators();

    explainControlFlow();
    quizControlFlow();

    explainFunctions();
    quizFunctions();

    explainArrays();
    quizArrays();

    explainString();
    quizStrings();

    explainFileHandling();
    quizFiles();

    scoreScreen();

};
void explainandPracticeOOP()
{

    explainClassObject();
    quizClassObject();

    explainEncapsulation();
    quizEncapsulation();

    explainInheritance();
    quizInheritance();

    explainPolymorphism();
    quizPolymorphism();

    explainAbstraction();
    quizAbstraction();

    scoreScreen();
}
void exitFuncion()
{

}

void Menu()
{

    printCenter("[1]:fundamentals topics");
    printCenter("[2]:OOP topics");
    printCenter("[3]:exit");
    short choise;
    cin >> choise;
    while (choise > 3)
    {
        cout << "Invalid choice try again \n";
        cin >> choise;
    }
    switch (choise)
    {
    case 1:explainandPracticeFunctionalprogramming(); break;
    case 2:explainandPracticeOOP(); break;
    case 3:exitFuncion(); break;
    default:break;
    }

}
void program() {
    startWindow();
    Menu();
}

int main() {



    program();

    return 0;
}
