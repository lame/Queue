using namespace cop4530;

template <typename T>
Queue<T>::Queue(){
    
}
template <typename T>
Queue<T>::~Queue(){
    array.clear();
}
template <typename T>
Queue<T>::Queue(const Queue &rhs){
    array = NULL;
    operator=(rhs);
}
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue &rhs){
    return array = rhs.array;
}
template <typename T>
Queue<T>& Queue<T>::operator[](int index){
    return array[index];
}
template <typename T>
T& Queue<T>::back(){   
    return array.back();
}
template <typename T>
const T& Queue<T>::back() const{
    return array.back();
}
template <typename T>
T& Queue<T>::front(){   
    return array.front();
}
template <typename T>
const T& Queue<T>::front() const{
    return array.front();
}
template <typename T>
bool Queue<T>::empty() const{    
    return array.size() == 0;
}
template <typename T>
void Queue<T>::pop(){
    array.pop_front();
}
template <typename T>
void Queue<T>::push(const T& val){
    array.push_back(val);
}
template <typename T>
int Queue<T>::size(){
    return array.size();
}





