/**
 *  You are reading a stream of integers and periodically you want to find 
 *  the rank of a number X (the number of values that are smaller or equal to x)
 * 
 *  Need two methods to be implemented: track (int x) which is called when each 
 *  number is generated and getRankOfNumber (int x) which returns the number of
 *  values less or equal to x.
 *
 *  Task: Implement a data structure and algortihms for these operations.
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

// -----------------------------------------------------------------------------

struct Vertex
{
    Vertex *rightChild;
    Vertex *leftChild;
    int value;
    int rank;
};

// -----------------------------------------------------------------------------

class findRanks
{
public:
    findRanks();

    ~findRanks();

    void track( int x );

    int getRankOfNumber( int x );

private:
    Vertex *m_root;
};

// -----------------------------------------------------------------------------

findRanks::findRanks()
{
    cout << "Constructor called!" << endl;
    m_root = new Vertex;
    m_root = NULL;
}

// -----------------------------------------------------------------------------

findRanks::~findRanks()
{
    cout << "Destructor called!" << endl;
    delete m_root;
}

// -----------------------------------------------------------------------------

void insert_vertex( Vertex* root, int x )
{
    if ( root == NULL )
    {
        Vertex *newVertex = new Vertex;
        newVertex->value = x;
        newVertex->rank = 0;
        newVertex->leftChild = NULL;
        newVertex->rightChild = NULL;
        root = newVertex;
        cout << "Here 1 " << root->rank << endl;
    }
    else
    {
        if ( root->value < x )
        {
            insert_vertex( root->rightChild, x );
            cout << "Here 2" << endl;
        }
        else
        {
            root->rank++;
            insert_vertex( root->leftChild, x );
            cout << "Here 3" << endl;
        }
    }
}

// -----------------------------------------------------------------------------

int find_rank( Vertex* root, int x )
{
    if ( root == NULL ) return -1;
    if ( root->value == x )
    {
        return root->rank;
    }
    else
    {
        if (root->value < x)
        {
            return find_rank( root->rightChild, x );
        }
        else
        {
            return find_rank( root->leftChild, x );
        }
    }
}

// -----------------------------------------------------------------------------

void findRanks::track( int x )
{
    if (m_root == NULL)
    {       
        m_root->value = x;
        m_root->rank = 0;
        m_root->leftChild = NULL;
        m_root->rightChild = NULL;
        cout << "ok" << endl;
    }
    else
    {
        Vertex *root = m_root;
        while (root!=NULL)
        {
            cout << "1" << endl;
            if (root->value < x)
            {
                if (root->rightChild == NULL)
                {
                    Vertex *newVertex = new Vertex;
                    newVertex->value = x;
                    newVertex->rank = 0;
                    newVertex->leftChild = NULL;
                    newVertex->rightChild = NULL;
                    root->rightChild = newVertex;
                    break;
                }
                root = root->rightChild;
            }
            else
            {
                if (root->leftChild == NULL)
                {
                    Vertex *newVertex = new Vertex;
                    newVertex->value = x;
                    newVertex->rank = 0;
                    newVertex->leftChild = NULL;
                    newVertex->rightChild = NULL;
                    root->leftChild = newVertex;
                    break;
                }
                root = root->leftChild;
            }
        }
    }
}

// -----------------------------------------------------------------------------

int findRanks::getRankOfNumber( int x )
{
    return find_rank( m_root, x );
}

// -----------------------------------------------------------------------------

int main()
{
    findRanks test;

    test.track(5);
    test.track(1);
    test.track(6);
    
    cout << test.getRankOfNumber(6) << endl;
    
    return 0;
}

// -----------------------------------------------------------------------------
