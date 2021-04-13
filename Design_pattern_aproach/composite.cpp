/**
    Project     : Composite Pattern Example

    Authors     : Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides
**/

///////////////////////////////////////////ICOMPONENT-INTERFACE///////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>

class IFileSystemComponent //Interface, clase abstracta pura
{
    public:
        virtual ~IFileSystemComponent(){};
        virtual void list(int depth) = 0; //operation
        virtual void add(IFileSystemComponent* component) = 0;
        virtual void remove(IFileSystemComponent* component) = 0;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////COMPOSITE///////////////////////////////////////////////////////
class Folder : public IFileSystemComponent //Clase, implementacion de la herencia [IFileSystemComponent], debe implementar todos los metodos
{
    private:
        std::string m_nodeName;
        std::vector<IFileSystemComponent*> m_children;

    public:
        Folder(std::string nodeName)
        {
            m_nodeName = nodeName;
        }

        virtual ~Folder(){}
        
        void list(int depth)//operation
        {
            std::string newStr(depth, '-');
            std::cout << newStr << m_nodeName << " depth: " << depth << std::endl;
            for(IFileSystemComponent* currentChild : m_children)
            {
                if(currentChild != 0)
                {
                    currentChild->list(depth + 1);
                }
            }
        }

        void add(IFileSystemComponent* component)
        {
            m_children.push_back(component);
        }

        void remove(IFileSystemComponent* component)
        {
            m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
        }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////LEAF////////////////////////////////////////////////////////
class File : public IFileSystemComponent //Clase, implementacion de la herencia [IFileSystemComponent], debe implementar todos los metodos
{
    private: 
        std::string m_nodeName;
        std::vector<IFileSystemComponent*> m_children;

    public:
        File(std::string nodeName)
        {
            m_nodeName = nodeName;
        }

        virtual ~File(){}

        void list(int depth)//operation
        {
            std::string newStr(depth, '-');
            std::cout << newStr << m_nodeName << " depth: " << depth << std::endl;
            for(IFileSystemComponent* currentChild : m_children)
            {
                if(currentChild != 0)
                {
                    currentChild->list(depth + 1);
                }
            }
        }

        void add(IFileSystemComponent* component)
        {
            m_children.push_back(component);
        }

        void remove(IFileSystemComponent* component)
        {
            m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
        }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////
int main()
{
    IFileSystemComponent* folder_01 = new Folder("folder_01");

    IFileSystemComponent* folder_02 = new Folder("folder_02");
    folder_01->add(folder_02);

    IFileSystemComponent* folder_03 = new Folder("folder_03");
    IFileSystemComponent* fileA = new File("file A");
    IFileSystemComponent* fileC = new File("file C");
    folder_03->add(fileA);
    folder_03->add(new File("file B"));
    folder_02->add(folder_03);
    fileA->add(fileC);
    folder_01->list(1);
   

    delete folder_03;
    delete folder_02;
    delete folder_01;
    return 0;

    //No se deletean los files, pero si las carpetas?
    //File y Folder actuan igual?
    //FileSystemComponent tiene una relacion de agregacion con carpeta, pero no con file?
    
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////