#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

	void setState(bool state)
	{
		this->state = state;
	}

	bool getState()
	{
		return this->state;
	}
};

class AssitanceManagerMapper
{
private:
	std::vector<AssistanceManager*> assistanceManagers;
public:
	AssitanceManagerMapper()
	{
	}
		
	~AssitanceManagerMapper(){};

	void add(AssistanceManager* assistanceManager)
	{
		assistanceManagers.push_back(assistanceManager);
	}

	void deleteAssitanceRegistry(AssistanceManager* assistanceManager)
	{
		assistanceManagers.erase(std::remove(assistanceManagers.begin(), assistanceManagers.end(), assistanceManager), assistanceManagers.end());
	}

	void updateAssitanceRegistry(AssistanceManager* assistanceManagerToUpdate,bool state)
	{
		for(AssistanceManager* assistanceManager : assistanceManagers)
            	{
                	if(assistanceManager != 0)
                	{
	                   if((assistanceManager->getStudent().getName() == assistanceManagerToUpdate->getStudent().getName())
	                   	&&(assistanceManager->getStudent().getSurname() == assistanceManagerToUpdate->getStudent().getSurname())
	                   	&&(assistanceManager->getCourse().getName() == assistanceManagerToUpdate->getCourse().getName())
	                   	&&(assistanceManager->getDate()==assistanceManagerToUpdate->getDate()))
	                   {
	                   	assistanceManager->setState(state);
	                   }
                	}
           		}
    }

	void insertToFile()
	{
		std::ofstream saveFile;
    	saveFile.open("assistance_registry.txt", std::ios::in | std::ios::out | std::ios::app);
	    if(saveFile.is_open())
	    {
	    	for(AssistanceManager* assistanceManager : assistanceManagers)
            	{
                	if(assistanceManager != 0)
                	{
	                   saveFile << assistanceManager->getStudent().getName() <<" "<< assistanceManager->getStudent().getSurname() <<" "<< assistanceManager->getCourse().getName() <<" "<<
		               assistanceManager->getDate() <<" "<< assistanceManager->getState() << std::endl;
                	}
           		}
	             
	    }
	    saveFile.close();
	}

};



int main()
{
	Student* student1 = new Student("Thiago","Cabrera");

	Student* student2 = new Student("Javier","Cabrera");

	Student* student3 = new Student("Laureano","Cabrera");

	Student* student4 = new Student("Gabriela","Bosco");

	Course* course1 = new Course("Practicas Profesionalizantes");

	Course* course2 = new Course("Analisis Matematico");

	AssistanceManager* assistance1 = new AssistanceManager(student1,course1,"20210422",false);

	AssistanceManager* assistance2 = new AssistanceManager(student2,course2,"20210422",false);

	AssistanceManager* assistance3 = new AssistanceManager(student3,course2,"20210422",false);

	AssistanceManager* assistance4 = new AssistanceManager(student4,course1,"20210422",false);

	AssitanceManagerMapper* assistanceMapper = new AssitanceManagerMapper();

	assistanceMapper->add(assistance1);

	assistanceMapper->add(assistance2);

	assistanceMapper->add(assistance3);

	assistanceMapper->add(assistance4);

	assistanceMapper->updateAssitanceRegistry(assistance2,true);

	assistanceMapper->updateAssitanceRegistry(assistance4,true);

	assistanceMapper->deleteAssitanceRegistry(assistance2);

	assistanceMapper->insertToFile();


	delete student1;
	delete student2;
	delete student3;
	delete student4;
	delete course1;
	delete course2;
	delete assistance1;
	delete assistance2;
	delete assistance3;
	delete assistance4;
	delete assistanceMapper;

	return 0;
}


