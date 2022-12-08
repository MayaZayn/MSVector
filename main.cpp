#include "MSVector.h"
#include "MSVector.cpp"

//Last thing after we're done with everything is to check if anything in the code could be implemented
//in a better different more efficient way and add comments if necessary

int main() {
    //Cases

    int *arr = new int[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    MSVector<int> vec;
    MSVector<int> vec2(3);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout << vec[0] << endl;
    cout << vec[1] << endl;
    cout << vec[2] << endl;
    cout << endl;

    MSVector<int> vec3(vec), vec4;
    vec4 = vec3;
    MSVector<int> vec5(arr, 3);
    cout << vec5[2] << endl;
    MSVector<int> vec6;
    vec6 = move(vec5);
    cout << vec6[0] << endl;
    cout << vec6.empty() << endl;
    cout << *vec6.begin() << endl;
    cout << endl;

    vec6.clear();
    vec6.push_back(1);
    vec6.push_back(2);
    cout << vec6[0] << endl;
    cout << vec6[1] << endl;
    cout << vec6.pop_back() << endl;
    vec6.push_back(3);
    cout << vec6[1] << endl;
    cout << endl;

    vec6 = vec4;
    vec6.push_back(3);
    vec4.push_back(2);
    cout << (vec6 < vec4) << endl;
    cout << vec6.size() << endl << vec6.capacity();
    vec6.push_back(5);
    cout << endl << vec6.capacity() << endl << vec6.size() << endl;
    cout << vec6 << endl;

    cout << vec6[100];
    return 0;
}
