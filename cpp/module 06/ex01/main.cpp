#include "Data.hpp"

int main()
{
    Data*   data = new Data;

    data->serialize = "Hello World!";
    data->raw = serialize(data);
    cout << "data->serialize = " << data->serialize << endl;
    cout << "data->raw = " << data->raw << endl << endl;
    cout << "deserialize(data->raw)->serialize = " << deserialize(data->raw)->serialize << endl;
    cout << "deserialize(data->raw)->raw = " << deserialize(data->raw)->raw << endl;
    delete data;

    return 0;
}

// int main()
// {
//     Data data;
//     uintptr_t raw = serialize(&data);
//     Data* ptr = deserialize(raw);

//     cout << "data: " << &data << endl;
//     cout << "raw: " << raw << endl;
//     cout << "ptr: " << ptr << endl;

//     if (&data == ptr)
//         cout << "data == ptr" << endl;
//     else
//         cout << "data != ptr" << endl;

//     return 0;
// }