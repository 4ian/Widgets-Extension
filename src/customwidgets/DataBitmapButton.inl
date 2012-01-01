template <class T>
const T& DataBitmapButton<T>::GetDataStored()
{
    return dataStorage;
}

template <class T>
void DataBitmapButton<T>::SetDataStored(const T data)
{
    dataStorage = data;
}
