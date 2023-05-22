#include "datatime.h"

using namespace std;


int main()
{ 
    Time begin(8, 8, 8);
    Time end(17, 17, 17);
    cout << begin << "\n";

    
    cout << "seconds have passed = " << Timer(begin, end) << " second" << "\n";

    cout << end << "\n";
    end.add_sec(20);
    cout << end << "\n";

    end.back_sec(20);
    cout << end << "\n";


    cout << "new = " << end - begin << "\n";

    
}