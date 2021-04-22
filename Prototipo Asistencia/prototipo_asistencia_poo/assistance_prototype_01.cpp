#include <iostream>
#include <fstream>

class Student
{
private:
	std::string name;
	std::string surname;

public:
	Student(std::string name,std::string surname)
	{
		this->name = name;
		this->surname = surname;
	}
	~Student(){};

	void setName(std::string name)
	{
		this->name = name;
	}

	void setSurame(std::string surname)
	{
		this->surname = surname;
	}

	std::string getName()
	{
		return this->name;
	}

	std::string getSurname()
	{
		return this->surname;
	}
};

class Course
{
private:
	std::string name;

public:
	Course(std::string name)
	{
		this->name = name;
	}
	~Course(){};

	void setName(std::string name)
	{
		this->name = name;
	}

	std::string getName()
	{
		return this->name;
	}
};

class AssistanceManager
{
private:
	Student* student;
	Course* course;
	std::string date;
	bool state;

public:
	AssistanceManager(Student* student, Course* course,std::string date,bool state)
	{
		this->student = student;
		this->course = course;
		this->date = date;
		this->state = state;
	}
	~AssistanceManager(){};
	
	Student getStudent()
	{
		return *student;
	}

	Course getCourse()
	{
		return *course;
	}

	std::string getDate()
	{
		return this->date;
	}

	bool getState()
	{
		return this->state;
	}
};

class AssitanceManagerMapper
{

public:
	AssitanceManagerMapper(){};
	~AssitanceManagerMapper(){};

	void insert(AssistanceManager* assitanceManager)
	{
		std::ofstream sFile;
    	sFile.open("assistance_registry.txt", std::ios::in | std::ios::out | std::ios::app);
	    if(sFile.is_open())
	    {
	             sFile << assitanceManager->getStudent().getName() << " " << assitanceManager->getStudent().getSurname() << " " << assitanceManager->getCourse().getName() << " " <<
	             assitanceManager->getDate() << " " << assitanceManager->getState() << std::endl;
	    }
	    sFile.close();
	}
};



int main()
{
	Student* student1 = new Student("Thiago","Cabrera");

	Student* student2 = new Student("Laureano","Cabrera");

	Course* course1 = new Course("Practicas Profesionalizantes");

	AssistanceManager* assistance = new AssistanceManager(student1,course1,"20210422",true);

	AssistanceManager* assistance2 = new AssistanceManager(student2,course1,"20210422",false);

	AssitanceManagerMapper* assistanceMapper = new AssitanceManagerMapper();

	assistanceMapper->insert(assistance);

	assistanceMapper->insert(assistance2);

	delete student1;
	delete student2;
	delete course1;
	delete assistance;
	delete assistanceMapper;

	return 0;
}


