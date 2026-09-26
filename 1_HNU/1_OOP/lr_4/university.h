#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <iostream>

// =========================================================
// БАЗОВИЙ КЛАС: Person 
// =========================================================
class Person {
public: // 3 загальні дані та 3 методи
    std::string name;
    int age;
    std::string email;

    std::string getName() const;
    int getAge() const;
    std::string getEmail() const;

protected: // 3 захищені дані та 3 методи
    int idNumber;
    std::string address;
    std::string phone;

    int getId() const;
    std::string getAddress() const;
    std::string getPhone() const;

private: // 3 приватні дані та 3 методи
    std::string bloodType;
    std::string nationality;
    std::string insuranceNum;

    std::string getBloodType() const;
    std::string getNationality() const;
    std::string getInsuranceNum() const;

public:
    // Конструктор базового класу (приймає понад 5 аргументів)
    Person();
    Person(std::string n, int a, std::string em, int id, std::string addr, std::string ph, std::string blood, std::string nat, std::string ins);
    Person(const Person& other); // Конструктор копіювання
    ~Person();
};


// =========================================================
// ПОХІДНИЙ КЛАС 1: Student (Просте відкрите наслідування)
// =========================================================
class Student : public Person {
public:
    int studentId;
    std::string faculty;
    std::string specialty;
    double avgGrade;
    int courseYear;
    bool isExpelled;
    bool hasScholarship;
    int semester;

    // Використання оператора using для доступу до захищеного поля бази
    using Person::address; 

    Student();
    // Конструктор похідного класу використовує всі передані параметри
    Student(std::string n, int a, std::string em, int id, std::string addr, std::string ph, 
            int sId, std::string fac, std::string spec, double avg);
    ~Student();

    void displayStudentInfo();
    void evaluateScholarship();
};


// =========================================================
// ПОХІДНИЙ КЛАС 2: Dean (Закрите наслідування)
// =========================================================
class Dean : private Person {
public:
    std::string facultyManaged;
    int deanOfficeRoom;
    int yearsInOffice;
    double budgetManaged;
    std::string secretaryName;
    bool isStrict;
    std::string signatureCode;
    double approvalRating;

    Dean();
    Dean(std::string n, int a, std::string em, int id, std::string addr, std::string ph, std::string fac, int room);
    ~Dean();

    void displayDeanInfo();
};


// =========================================================
// 3 ДОДАТКОВІ КЛАСИ ДЛЯ МНОЖИННОГО НАСЛІДУВАННЯ
// =========================================================

// Додатковий клас: Employee
class Employee {
public:
    int empId;
    double salary;
    std::string position;
    std::string department;
    std::string hireDate;
    int officeRoom;
    std::string workPhone;
    std::string taxId;

    Employee();
    Employee(int eId, double sal, std::string pos);
    ~Employee();
};

// Додатковий клас : Researcher
class Researcher {
public:
    std::string researchField;
    int publicationsCount;
    int hIndex;
    std::string labName;
    std::string currentProject;
    double grantAmount;
    int patentCount;
    std::string academicDegree;

    Researcher();
    Researcher(std::string field, int pubs, int h);
    ~Researcher();
};

// Додатковий клас: Professor - МНОЖИННЕ НАСЛІДУВАННЯ
class Professor : public Person, public Employee, public Researcher {
public:
    std::string title;
    int teachingHours;
    std::string subject;
    int supervisedStudents;
    bool isTenured;
    int awardsCount;
    std::string officeHours;
    std::string facultyName;

    Professor();
    Professor(std::string n, int a, std::string em, int id, std::string addr, std::string ph, // Для Person
              int eId, double sal, std::string pos,                                           // Для Employee
              std::string field, int pubs, int h,                                             // Для Researcher
              std::string tit, std::string sub);                                              // Для Professor
    ~Professor();

    void displayProfessorInfo();
    void gradeStudent(Student& s, double grade); // Сценарій взаємодії
};

#endif // UNIVERSITY_H