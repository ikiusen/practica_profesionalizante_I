#include <iostream>
#include <fstream>
#include <vector>

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
private:
	int numberOfRegistries;

public:
	AssitanceManagerMapper()
	{
		getInitialNumberOfRegistriesOnFile();
	}

	~AssitanceManagerMapper(){};

	void getInitialNumberOfRegistriesOnFile()
	{
		std::ifstream inputFile;
		std::string line;
		int line_count = 0;
		inputFile.open("assistance_registry_v2.txt", std::ios::in | std::ios::out | std::ios::app);

		while(std::getline(inputFile,line))
		{
			++line_count;
		}

		this->numberOfRegistries = line_count;

		inputFile.close();
	}

	void setNumberOfRegistries(int value)
	{
		this->numberOfRegistries = this->numberOfRegistries + value;
	}

	int getNumberOfRegistries()
	{
		return this->numberOfRegistries;
	}

	/*void select()
	{
		std::ifstream readFile;
		std::string name,c_name,surname,date;
		bool state;
    	readFile.open("assistance_registry.txt", std::ios::in);
	    if(readFile.is_open())
	    {
	        while (!readFile.eof())
	        {

	           readFile >> name;
	           readFile.get( );
	           readFile >> surname;
	           readFile.get( );
	           readFile >> c_name;
	           readFile.get( );
	           readFile >> date;
	           readFile.get( );
	           readFile >> state;

	           AssistanceManager *auxAssistanceManager = new AssistanceManager( new Student(name,surname),new Course(c_name),date,state);

	           assitanceManagers.push_back(auxAssistanceManager);

	           delete auxAssistanceManager;
	        }

    }
    readFile.close();
	}*/

	void insert(AssistanceManager* assitanceManager)
	{
		std::ofstream saveFile;
    	saveFile.open("assistance_registry_v2.txt", std::ios::in | std::ios::out | std::ios::app);
	    if(saveFile.is_open())
	    {
	             saveFile << assitanceManager->getStudent().getName() <<" "<< assitanceManager->getStudent().getSurname() <<" "<< assitanceManager->getCourse().getName() <<" "<<
	             assitanceManager->getDate() <<" "<< assitanceManager->getState() << std::endl;
	    }
	    saveFile.close();

	    setNumberOfRegistries(1);
	}

	void update(AssistanceManager* assitanceManager,bool state)
	{

	}

	void deleteAssitanceRegistry(AssistanceManager* assitanceManager)
	{

	}
};



int main()
{
	//Student* student1 = new Student("Thiago","Cabrera");
	Student* student1 = new Student("Javier","Cabrera");

	//Student* student2 = new Student("Laureano","Cabrera");
	Student* student2 = new Student("Gabriela","Bosco");
	//Course* course1 = new Course("Practicas Profesionalizantes");
	Course* course1 = new Course("Analisis Matematico");

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


