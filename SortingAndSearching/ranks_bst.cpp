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
    m_root = new Vertex;
    m_root = NULL;
}

// -----------------------------------------------------------------------------

findRanks::~findRanks()
{
    delete m_root;
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
            return root->rank + find_rank( root->rightChild, x ) + 1;
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
        Vertex *newVertex = new Vertex;       
        newVertex->value = x;
        newVertex->rank = 0;
        m_root = newVertex;
    }
    else
    {
        Vertex *root = m_root;
        Vertex *newVertex = new Vertex;
        newVertex->value = x;
        newVertex->rank = 0;
        newVertex->leftChild = NULL;
        newVertex->rightChild = NULL;

        while (root!=NULL)
        {
            if (root->value < x)
            {
                if (root->rightChild == NULL)
                {
                    root->rightChild = newVertex;
                    
                    break;
                }
                root = root->rightChild;
            }
            else
            {
                if (root->leftChild == NULL)
                {
                    
                    root->leftChild = newVertex;
                    root->rank++;
                    
                    break;
                }
                root->rank++;
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
    test.track(4);
    test.track(4);
    test.track(5);
    test.track(9);
    test.track(7);
    test.track(13);
    test.track(3);
    
    cout << "Rank of 1: " << test.getRankOfNumber(1) << endl;
    cout << "Rank of 3: " << test.getRankOfNumber(3) << endl;
    cout << "Rank of 4: " << test.getRankOfNumber(4) << endl;
    cout << "Rank of 5: " << test.getRankOfNumber(5) << endl;
    cout << "Rank of 7: " << test.getRankOfNumber(7) << endl;
    cout << "Rank of 9: " << test.getRankOfNumber(9) << endl;
    cout << "Rank of 13: " << test.getRankOfNumber(13) << endl;

    return 0;
}

// -----------------------------------------------------------------------------
