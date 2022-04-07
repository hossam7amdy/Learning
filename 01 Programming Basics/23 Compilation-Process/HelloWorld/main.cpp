#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0)
        return 1;

    int ret = factorial(n-1);
    ret *= n;
    return ret;
}

int main(int argc, char* argv[])
{
    if(argc<3){
        cout << "ERROR: Please pass string an iteger\n";
        return 0;
    }

    string path = argv[1];
    int limit = atoi(argv[2]);
    //cout << path << "\n" << limit << endl;

    /// Debug it
    int fact5 = factorial(5);
    cout << fact5 << endl;

    return 0;
}
