#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;


// Abstract Strategy
class QueueStrategy
{
public:
    virtual void add(int) = 0;
    virtual void execute() = 0;
};

// Concrete Strategy A
class NormalStrategy: public QueueStrategy
{
    virtual void add(int jobid) {pjobs.push(jobid); }
    virtual void execute()
    {
        cout << "Size of jobs " << pjobs.size() << endl;
        while (!pjobs.empty())
        {
            cout << "Processing job id #" << pjobs.front() << ".\n";
            pjobs.pop();
        }
    }

public:
    std::queue<int> pjobs;
};

// Concrete Strategy B
class FairStrategy: public QueueStrategy
{
    virtual void add(int jobid) { pjobs.push_back(jobid); }
    virtual void execute()
    {
        // Using built-in random generator:
        // 

        std::random_shuffle(pjobs.begin(), pjobs.end());

        cout << "Size of jobs " << pjobs.size() << endl;
        for (std::vector<int>::iterator i = pjobs.begin(); i != pjobs.end(); ++i)
            cout << "Processing job id #" << *i << ".\n";
    }

public:
    std::vector<int> pjobs;
};

// The context class
class Printer
{
public:
    Printer(QueueStrategy * q): queue(q) {}
    ~Printer()
    {
        delete queue;
    }

    void submit(int jobid)
    {
        // Some code
        //

        queue->add(jobid);
    }

    void print()
    {
        // Some code for configuration
        // ....
        // Some code for printing
        // ....
        cout << "Preparing for printing" <<  endl;
        queue->execute();
        cout << "Done" <<  endl;
    }

    QueueStrategy * queue;
};


int main(int argc, char const *argv[])
{
    // Try strategy A
    Printer pnorm(new NormalStrategy());

    for (int documentid = 0; documentid < 10; ++documentid)
        pnorm.submit(documentid);
    pnorm.print();

    // Now try another strategy
    cout << "\n\n\nTrying another strategy .. \n\n\n";


    // Try strategy B for the same conditions
    Printer pfair(new FairStrategy());

    for (int documentid = 0; documentid < 10; ++documentid)
        pfair.submit(documentid);

    pfair.print();

    return 0;
}