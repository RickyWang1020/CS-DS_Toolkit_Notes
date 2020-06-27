//
//  main.cpp
//  Student_Grade_System
//
//  Created by Ricky Lahm Wang on 2020/6/23.
//  Copyright © 2020 Ricky Lahm Wang. All rights reserved.
//

#include <iostream>
#include "student.hpp"
#include "student_list.hpp"

using namespace std;

void printstudent(Student student){
    cout << "Name: " << student.get_name() << endl;
    cout << "Grade: " << student.get_grade() << endl;
    cout << "Email: " << student.get_email() << endl;
    cout << endl;
}

void read_mode(Student_list stu_list){
    while (true){
        char choice;
        cout << "Reading Mode:\nType in:\n'1' - Check the top student;\n'2' - Check excellent student(s);\n'3' - Check failed student(s);\n'b' - Back to the main menu" << endl;
        cin >> choice;
        switch (choice){
            case '1':
                try {
                    cout << "The Top Student:" << endl;
                    printstudent(stu_list.get_top_student());
                } catch (NoTopStudentException &e) {
                    cout << "An Exception was Caught:\n" << e.what() << endl;
                }
                break;
            case '2':
                try {
                    cout << "The Excellent Student(s) List:" << endl;
                    for (Student s: stu_list.get_excellent_students())
                        printstudent(s);
                } catch (NoExcellentStudentsException &e) {
                    cout << "An Exception was Caught:\n" << e.what() << endl;
                }
                break;
            case '3':
                try {
                    cout << "The Failed Student(s) List:" << endl;
                    for (Student s: stu_list.get_fail_students())
                        printstudent(s);
                } catch (NoFailStudentsException &e) {
                    cout << "An Exception was Caught:\n" << e.what() << endl;
                }
                break;
            case 'b':
                return;
                break;
            default:
                cout << "Invalid input, try again" << endl;
                read_mode(stu_list);
                break;
        }
    }
}

void main_loop(){
    while (true){
        char output;
        cout << "Student Grade System\nType in:\n'r' - Read a student grade file;\n'w' - Write on a student grade file;\n'q' - Quit the system" << endl;
        cin >> output;
        switch (output){
            case 'r':
            {
                cout << "Type in the full path of the student grade file in your computer: " << endl;
                string path;
                // balance out the '\n' typed in the previous output
                getchar();
                getline(cin, path);
                Student_list stu_list(path);
                read_mode(stu_list);
                break;
            }
            case 'w':
            {   cout << "ok" << endl;
                break;
            }
            case 'q':
            {    cout << "See you next time!" << endl;
                return;
                break;
            }
            default:
            {   cout << "Invalid input, try again" << endl;
                main_loop();
                break;
            }
        }
    }
}

int main() {
    // the path of the file must be the full directory of the file on computer
//    Student_list list("/Users/lahmwang/Desktop/C Practice/Student_Grade_System/Student_Grade_System/students.txt");
//
    main_loop();
    
    return 0;
}
