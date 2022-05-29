int main()
{
    int count;
    std::cin >> count;
    Holder *arr = new Holder[count];
    for (int i = 0; i < count/2; ++i) {
        arr[i].swap(arr[count - i - 1]);
    }
    delete[] arr;
}