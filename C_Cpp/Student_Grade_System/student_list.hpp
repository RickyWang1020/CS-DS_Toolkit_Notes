//
//  student_list.hpp
//  Student_Grade_System
//
//  Created by Ricky Lahm Wang on 2020/6/24.
//  Copyright © 2020 Ricky Lahm Wang. All rights reserved.
//

#ifndef student_list_hpp
#define student_list_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <exception>
#include "student.hpp"

class Student_list{
    public:
        // the class receives a string: file path
        Student_list(std::string file_path);
        // class methods
        Student get_top_student();
        std::vector <Student> get_excellent_students();
        std::vector <Student> get_fail_students();
    
    private:
        // the list of students
        std::vector <Student> _students;
};

class NoTopStudentException: public std::exception
{
    public:
        const char *what() const throw(){
            return "No top student";
        }
};

class NoExcellentStudentsException: public std::exception
{
    public:
        const char *what() const throw(){
            return "No excellent student(s)";
        }
};

class NoFailStudentsException: public std::exception
{
    public:
        const char *what() const throw(){
            return "No failed student(s)";
        }
};

#endif /* student_list_hpp */
