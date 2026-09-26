#include "university.h"

// ==========================================
// РЕАЛІЗАЦІЯ Person
// ==========================================
Person::Person() : name("Анонім"), age(0), email(""), idNumber(0), address(""), phone(""), bloodType(""), nationality(""), insuranceNum("") {
    std::cout << "\t[+] Person: Конструктор без параметрів (" << name << ")\n";
}

Person::Person(std::string n, int a, std::string em, int id, std::string addr, std::string ph, std::string blood, std::string nat, std::string ins)
    : name(n), age(a), email(em), idNumber(id), address(addr), phone(ph), bloodType(blood), nationality(nat), insuranceNum(ins) {
    std::cout << "\t[+] Person: Конструктор з параметрами (" << name << ")\n";
}

Person::Person(const Person& other) 
    : name(other.name + " (Копія)"), age(other.age), email(other.email), idNumber(other.idNumber), address(other.address) {
    std::cout << "\t[+] Person: Конструктор копіювання (" << name << ")\n";
}

Person::~Person() {
    std::cout << "\t[~] Person: Деструктор знищив (" << name << ")\n";
}

// Методи Person
std::string Person::getName() const { return name; }
int Person::getAge() const { return age; }
std::string Person::getEmail() const { return email; }
int Person::getId() const { return idNumber; }
std::string Person::getAddress() const { return address; }
std::string Person::getPhone() const { return phone; }
std::string Person::getBloodType() const { return bloodType; }
std::string Person::getNationality() const { return nationality; }
std::string Person::getInsuranceNum() const { return insuranceNum; }


// ==========================================
// РЕАЛІЗАЦІЯ Student (Просте наслідування)
// ==========================================
Student::Student() : Person(), studentId(0), avgGrade(0.0) {
    std::cout << "\t[+] Student: Конструктор без параметрів\n";
}

// Передача параметрів конструктору базового класу (перші 6 аргументів йдуть у Person)
Student::Student(std::string n, int a, std::string em, int id, std::string addr, std::string ph, 
                 int sId, std::string fac, std::string spec, double avg)
    : Person(n, a, em, id, addr, ph, "I+", "Українець", "IN123"), // Виклик бази
      studentId(sId), faculty(fac), specialty(spec), avgGrade(avg), courseYear(1), isExpelled(false), hasScholarship(false), semester(1) {
    std::cout << "\t[+] Student: Конструктор з параметрами (" << name << ")\n";
}

Student::~Student() {
    std::cout << "\t[~] Student: Деструктор знищив студента (" << name << ")\n";
}

void Student::displayStudentInfo() {
    // Використання оператора глобального доступу до методів бази
    std::cout << "\t[*] Студент: " << Person::getName() << " | Факультет: " << faculty 
              << " | Адреса (через using): " << address << " | Бал: " << avgGrade << "\n";
}

void Student::evaluateScholarship() {
    if (avgGrade >= 4.5) hasScholarship = true;
    else hasScholarship = false;
}


// ==========================================
// РЕАЛІЗАЦІЯ Dean (Закрите наслідування)
// ==========================================
Dean::Dean() : Person(), deanOfficeRoom(0) {
    std::cout << "\t[+] Dean: Конструктор без параметрів\n";
}

Dean::Dean(std::string n, int a, std::string em, int id, std::string addr, std::string ph, std::string fac, int room)
    : Person(n, a, em, id, addr, ph, "II+", "Українець", "IN999"), facultyManaged(fac), deanOfficeRoom(room) {
    std::cout << "\t[+] Dean: Конструктор з параметрами (" << name << ")\n";
}

Dean::~Dean() {
    std::cout << "\t[~] Dean: Деструктор знищив декана\n";
}

void Dean::displayDeanInfo() {
    // Всі public/protected члени Person стали private у Dean. Ми маємо доступ до них ТІЛЬКИ зсередини класу.
    std::cout << "\t[*] Декан: " << getName() << " | Керує факультетом: " << facultyManaged 
              << " | ID (з бази): " << getId() << "\n";
}


// ==========================================
// РЕАЛІЗАЦІЯ Employee та Researcher
// ==========================================
Employee::Employee() : empId(0), salary(0.0) { std::cout << "\t[+] Employee створено\n"; }
Employee::Employee(int eId, double sal, std::string pos) : empId(eId), salary(sal), position(pos) {
    std::cout << "\t[+] Employee з параметрами створено\n";
}
Employee::~Employee() { std::cout << "\t[~] Employee знищено\n"; }

Researcher::Researcher() : publicationsCount(0) { std::cout << "\t[+] Researcher створено\n"; }
Researcher::Researcher(std::string field, int pubs, int h) : researchField(field), publicationsCount(pubs), hIndex(h) {
    std::cout << "\t[+] Researcher з параметрами створено\n";
}
Researcher::~Researcher() { std::cout << "\t[~] Researcher знищено\n"; }


// ==========================================
// РЕАЛІЗАЦІЯ Professor (Множинне наслідування)
// ==========================================
Professor::Professor() : Person(), Employee(), Researcher() {
    std::cout << "\t[+] Professor: Конструктор без параметрів\n";
}

// Передача параметрів ОДРАЗУ ТРЬОМ базовим класам!
Professor::Professor(std::string n, int a, std::string em, int id, std::string addr, std::string ph, 
                     int eId, double sal, std::string pos, 
                     std::string field, int pubs, int h, 
                     std::string tit, std::string sub)
    : Person(n, a, em, id, addr, ph, "III+", "Українець", "PR001"),
      Employee(eId, sal, pos),
      Researcher(field, pubs, h),
      title(tit), subject(sub) {
    std::cout << "\t[+] Professor: Конструктор з параметрами (" << name << ")\n";
}

Professor::~Professor() {
    std::cout << "\t[~] Professor: Деструктор знищив професора (" << name << ")\n";
}

void Professor::displayProfessorInfo() {
    std::cout << "\t[*] Професор: " << getName() << " | Посада: " << position 
              << " | Галузь: " << researchField << " | Зарплата: " << salary << "\n";
}

void Professor::gradeStudent(Student& s, double grade) {
    s.avgGrade = grade;
    std::cout << "\t[!] Професор " << getName() << " поставив оцінку " << grade << " студенту " << s.getName() << ".\n";
    s.evaluateScholarship();
}