#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;


// Component
class FilesystemItem
{
public:
    virtual void ls() const = 0;
};


// Leaf
class File : public FilesystemItem
{
public:
    File(const char * n): name(n) {}
    virtual void ls() const
    {
        cout << "-rw-r--r-- 1 user users 4096 Nov 11 1971 " << name << endl;
    }

protected:
    const char * name;

};


// Composite
class Directory: public FilesystemItem
{
public:
    Directory(const char * name, FilesystemItem ** items, int size): name(name), content(items, items + size)
    {
    }

    // So, here composite can be a leaf as well
    Directory(const char * name, FilesystemItem * item  = 0): name(name)
    {
        if(item)
            content.push_back(item);
    }

    virtual void ls() const
    {
        cout << name << "/ " << endl;
        for(list<FilesystemItem *>::const_iterator it = content.begin(); it != content.end(); ++it)
        {
            cout << " ";
            (*it)->ls();
        }
    }

    ~Directory()
    {
        for(list<FilesystemItem *>::iterator it = content.begin(); it != content.end(); ++it)
            delete *it;
    }

protected:
    const char * name;

    // This can be a single reference
    list<FilesystemItem *> content;
};

int main(int argc, char const *argv[])
{
    // Client code goes here
    // 
    // 

    FilesystemItem * bin = new Directory("bin", new File("bash"));
    bin->ls();

    cout << "Creating full filesystem" << endl;
    FilesystemItem * items[] = {new Directory("opt"), new Directory("mnt"), new Directory("etc"), bin};
    int size = sizeof(items)/sizeof(FilesystemItem *);
    FilesystemItem * root = new Directory("/", items, size);
    root->ls();


    return 0;
}