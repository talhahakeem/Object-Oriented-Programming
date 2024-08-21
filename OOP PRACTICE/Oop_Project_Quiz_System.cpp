#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Class to store student information
class Student {
private:
    string name;
    int rollNo;
    int marks;

public:
    Student() : marks(0) {}

    void setStudentInfo(const string& studentName, const int& studentRollNo) {
        name = studentName;
        rollNo = studentRollNo;
    }

    string getName() const { return name; }
    int getRollNo() const { return rollNo; }
    int getMarks() const { return marks; }
    void addMarks(int score) { marks += score; }
};

// Abstract base class for quizzes
class Quiz {
protected:
    Student student;
    int totalQuestions;
    bool askedQuestions[5]; // Array to keep track of asked questions
    string subject; // Variable to store the subject of the quiz

public:
    Quiz(int numQuestions, const string& subjectName) : totalQuestions(numQuestions), subject(subjectName) {
        for (int i = 0; i < 5; ++i) {
            askedQuestions[i] = false;
        }
    }

    virtual void AskQuestions() = 0; // Pure virtual function

    void ShowResult() {
        int percentage = (student.getMarks() * 100) / totalQuestions;
        cout << "STUDENT NAME: " << student.getName() << endl;
        cout << "ROLL NO: " << student.getRollNo() << endl;
        cout << "SUBJECT: " << subject << endl;
        cout << "MARKS: " << student.getMarks() << " OUT OF " << totalQuestions << endl;
        cout << "PERCENTAGE: " << percentage << "%" << endl;
        if (percentage >= 50) {
            cout << "CONGRATS YOU HAVE PASSED" << endl;
        } else {
            cout << "OOPS YOU HAVE FAILED" << endl;
        }
    }

    bool IsQuestionAsked(int question) {
        return askedQuestions[question];
    }

    void MarkQuestionAsAsked(int question) {
        askedQuestions[question] = true;
    }

    void SetStudent(const Student& s) {
        student = s;
    }

    void SaveResult(const string& filename) {
        ofstream file;
        file.open("result.txt", ios::trunc);
        if (file.is_open()) {
            int percentage = (student.getMarks() * 100) / totalQuestions;
            file << "STUDENT NAME: " << student.getName() << endl;
            file << "ROLL NO: " << student.getRollNo() << endl;
            file << "SUBJECT: " << subject << endl;
            file << "MARKS: " << student.getMarks() << " OUT OF " << totalQuestions << endl;
            file << "PERCENTAGE: " << percentage << "%" << endl;
            if (percentage >= 50) {
                file << "CONGRATS YOU HAVE PASSED" << endl;
            } else {
                file << "OOPS YOU HAVE FAILED" << endl;
            }
            file << "----------------------------------------" << endl;
            file.close();
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }
};

// Derived class for C++ quiz
class CPPQuiz : public Quiz {
public:
    CPPQuiz() : Quiz(5, "C++") {}

    void AskQuestions() override {
        char answer;
        int question;
        for (int i = 0; i < totalQuestions; ++i) {
            do {
                question = rand() % totalQuestions;
            } while (IsQuestionAsked(question));
            MarkQuestionAsAsked(question);

            switch (question) {
            case 0:
                cout << i + 1 << ". WHICH IS INSERTION OPERATOR?\n";
                cout << "A) >>\nB) <<\nC) >\nD) <\n";
                cin >> answer;
                if (answer == 'B' || answer == 'b') student.addMarks(1);
                break;
            case 1:
                cout << i + 1 << ". WHICH IS EXTRACTION OPERATOR?\n";
                cout << "A) >>\nB) <<\nC) >\nD) <\n";
                cin >> answer;
                if (answer == 'A' || answer == 'a') student.addMarks(1);
                break;
            case 2:
                cout << i + 1 << ". WHAT IS USED IN CPP FOR DISPLAYING OUTPUT?\n";
                cout << "A) COUT\nB) CIN\nC) PRINT\nD) READ\n";
                cin >> answer;
                if (answer == 'A' || answer == 'a') student.addMarks(1);
                break;
            case 3:
                cout << i + 1 << ". WHICH OF THE FOLLOWING IS MODULUS OPERATOR?\n";
                cout << "A) %\nB) /\nC) *\nD) $\n";
                cin >> answer;
                if (answer == 'A' || answer == 'a') student.addMarks(1);
                break;
            case 4:
                cout << i + 1 << ". WHICH OF THE FOLLOWING IS USED FOR COMMENT?\n";
                cout << "A) \\\nB) //\nC) */\nD) /&\n";
                cin >> answer;
                if (answer == 'B' || answer == 'b') student.addMarks(1);
                break;
            }
        }
    }
};

// Derived class for Java quiz
class JavaQuiz : public Quiz {
public:
    JavaQuiz() : Quiz(5, "Java") {}

    void AskQuestions() override {
        char answer;
        int question;
        for (int i = 0; i < totalQuestions; ++i) {
            do {
                question = rand() % totalQuestions;
            } while (IsQuestionAsked(question));
            MarkQuestionAsAsked(question);

            switch (question) {
            case 0:
                cout << i + 1 << ". WHICH OF THE FOLLOWING IS NOT JAVA FEATURE?\n";
                cout << "A) dynamic\nB) architecture neutral\nC) use of pointers\nD) object-oriented\n";
                cin >> answer;
                if (answer == 'C' || answer == 'c') student.addMarks(1);
                break;
            case 1:
                cout << i + 1 << ". WHICH OF THE FOLLOWING CANNOT BE USED AS MODIFIER?\n";
                cout << "A) public\nB) private\nC) protected\nD) static\n";
                cin >> answer;
                if (answer == 'D' || answer == 'd') student.addMarks(1);
                break;
            case 2:
                cout << i + 1 << ". WHAT WILL BE RETURN TYPE FOR RETURNING NO VALUE?\n";
                cout << "A) void\nB) int\nC) char\nD) none of these\n";
                cin >> answer;
                if (answer == 'A' || answer == 'a') student.addMarks(1);
                break;
            case 3:
                cout << i + 1 << ". WHICH IS USED TO FIND AND FIX BUGS IN JAVA?\n";
                cout << "A) JVM\nB) JRE\nC) JDK\nD) none of these\n";
                cin >> answer;
                if (answer == 'A' || answer == 'a') student.addMarks(1);
                break;
            case 4:
                cout << i + 1 << ". WHO INVENTED JAVA PROGRAMMING?\n";
                cout << "A) Guido van Rossum\nB) James Gosling\nC) Dennis Ritchie\nD) Bjarne Stroustrup\n";
                cin >> answer;
                if (answer == 'B' || answer == 'b') student.addMarks(1);
                break;
            }
        }
    }
};

// Derived class for HTML quiz
class HTMLQuiz : public Quiz {
public:
    HTMLQuiz() : Quiz(5, "HTML") {}

    void AskQuestions() override {
        char answer;
        int question;
        for (int i = 0; i < totalQuestions; ++i) {
            do {
                question = rand() % totalQuestions;
            } while (IsQuestionAsked(question));
            MarkQuestionAsAsked(question);

            switch (question) {
            case 0:
                cout << i + 1 << ". CHOOSE CORRECT HTML ELEMENT FOR LARGEST HEADING?\n";
                cout << "A) <heading>\nB) <h6>\nC) <head>\nD) <h1>\n";
                cin >> answer;
                if (answer == 'D' || answer == 'd') student.addMarks(1);
                break;
            case 1:
                cout << i + 1 << ". WHO IS MAKING WEB STANDARDS?\n";
                cout << "A) Google\nB) Mozilla\nC) Microsoft\nD) The World Wide Web Consortium\n";
                cin >> answer;
                if (answer == 'D' || answer == 'd') student.addMarks(1);
                break;
            case 2:
                cout << i + 1 << ". WHICH CHARACTER IS USED TO END AN END TAG?\n";
                cout << "A) <\nB) /\nC) *\nD) none of these\n";
                cin >> answer;
                if (answer == 'B' || answer == 'b') student.addMarks(1);
                break;
            case 3:
                cout << i + 1 << ". CORRECT HTML TAG TO DEFINE IMPORTANT TEXT IS\n";
                cout << "A) <important>\nB) <strong>\nC) <h>\nD) none of these\n";
                cin >> answer;
                if (answer == 'B' || answer == 'b') student.addMarks(1);
                break;
            case 4:
                cout << i + 1 << ". WHICH LANGUAGE IS USED TO CREATE WEB PAGES?\n";
                cout << "A) HTML\nB) C\nC) Java\nD) none of these\n";
                cin >> answer;
                if (answer == 'A' || answer == 'a') student.addMarks(1);
                break;
            }
        }
    }
};

// Class to manage the quiz system
class QuizSystem {
private:
    Quiz* quiz;

public:

    bool Login() {
        string username, password;
        while (true) {
            cout << "ENTER YOUR USERNAME: ";
            cin >> username;
            cout << "ENTER YOUR PASSWORD: ";
            cin >> password;
            if (username == "User" && password == "Password") {
                return true;

            } else {
                cout << "Invalid login. Please enter valid login credentials." << endl;

            }
        }
    }

     void Start() {
        if (!Login()) {
            return;
        }

        Student student;
        string name;
        int rollNo;
        char subjectChoice, proceed;

        do {
            system("CLS");

            cout << "\n\t*******************" << endl;
            cout << "\t\tQUIZ  " << endl;
            cout << "\t*******************\n";
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter roll number: ";
            cin >> rollNo;
            student.setStudentInfo(name, rollNo);

            cout << "Select which subject quiz you want to take: " << endl;
            cout << "1) C++" << endl;
            cout << "2) JAVA" << endl;
            cout << "3) HTML" << endl;
            cout << "Enter your choice: ";
            cin >> subjectChoice;
            system("CLS");

            switch (subjectChoice) {
            case '1':
                quiz = new CPPQuiz();
                cout << "\n\n\t********* YOU CHOSE C++ QUIZ *********** " << endl;
                break;
            case '2':
                quiz = new JavaQuiz();
                cout << "\n\n\t********* YOU CHOSE JAVA QUIZ *********** " << endl;
                break;
            case '3':
                quiz = new HTMLQuiz();
                cout << "\n\n\t********* YOU CHOSE HTML QUIZ *********** " << endl;
                break;
            default:
                cout << "Your choice is invalid" << endl;
                continue;

            }

            quiz->SetStudent(student);
            quiz->AskQuestions();
            system("CLS");
            quiz->ShowResult();
            quiz->SaveResult("QuizResults.txt");
            delete quiz;

            cout << "\nPRESS Y TO CONTINUE OR ANY KEY TO TERMINATE " << endl;
            proceed = getch();
        } while (proceed == 'Y' || proceed == 'y');
    }
};

int main() {
    QuizSystem quizSystem;
    quizSystem.Start();
    return 0;
}

