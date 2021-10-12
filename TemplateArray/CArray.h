#pragma once

#include <iostream>
const int standartCapacity = 10;

template <typename TData>
class CArray
{
public: // Interface
 // Конструктор по умолчанию
    CArray()
    {
      _size = 0;
      _capacity = standartCapacity;
      _CArrayPtr = new TData[_capacity];
    }
    // Копирующий конструктор
    CArray(
        const CArray& _array
    )
    {
      _array._size = _size;
      _array._capacity = _capacity;
      _array._CArrayPtr = new TData[_capacity];
      memcpy(_array._CArrayPtr, _CArrayPtr, sizeof(TData) * _size);
    }
    CArray& operator=(
        const CArray& _array
    )
    {
      if (_size > 0)  
        delete[] _CArrayPtr;
      _size = _array._size;
      _capacity = _array._capacity;
      _CArrayPtr = new TData[_capacity];  
      memcpy(_CArrayPtr, _array._CArrayPtr, sizeof(TData) * _size);
    }

    // Деструктор
    ~CArray()
    {
      if (_size > 0)
        delete[] _CArrayPtr;
    }
    // Добавить элемент в конец массива
    void push_back(
        const TData& _value
    )
    {
      if (_size == _capacity)
      {
        _capacity *= 2;
        updateCapacityArray();
      }
      
      _CArrayPtr[_size] = _value;
      ++_size;
    }
    // Добавить элемент в массив по заданному индексу
    void insert(
        unsigned int _index,
        const TData& _value
    )
    {
      if (_index < 0 || _index > _size)
        return;

      if (_size == _capacity)
      {
        _capacity *= 2;
        updateCapacityArray();
      }

      TData* newArray = new TData[_capacity];
      for (int i = 0; i < _index; ++i)
        newArray[i] = _CArrayPtr[i];
      newArray[_index] = _value;
      for (int i = _index + 1; i < _size + 1; ++i)
        newArray[i] = _CArrayPtr[i - 1];
      delete[] _CArrayPtr;
      ++_size;
      _CArrayPtr = newArray;
    }
    // Удалить элемент массива по заданному индексу
    void erase(
        unsigned int _index
    )
    {
      if (_index < 0 || _index > _size)
        return;
      
      for (int i = _index; i < _size - 1; ++i)
        _CArrayPtr[i] = _CArrayPtr[i + 1];

      _size--;

      updateCapacityArray();
    }
    // Очистить массив
    void clear()
    {
      if (_size > 0)
        delete[] _CArrayPtr;
      _size = 0;
    }
    // Получить размер массива
    unsigned int size() const
    {
      return _size;
    }
    // Получить размер выделенной памяти для массива с учетом размера элементов
    unsigned int capacity() const
    {
      return _capacity;
    }
    // Получить элемент массива по заданному индексу
    TData& operator[](
        unsigned int _index
      )
    {
      return _CArrayPtr[_index];
    }


protected: // Attributes

    void updateCapacityArray()
    {
        TData* updateCapacityArray = new TData[_capacity];
        //memcpy(updateCapacityArray, _CArrayPtr, sizeof(TData) * _size);
        for (int i = 0; i < _size; ++i)
          updateCapacityArray[i] = _CArrayPtr[i];
        if (_size > 0 )
          delete[] _CArrayPtr;
        _CArrayPtr = updateCapacityArray;
    }

    TData* _CArrayPtr;
    unsigned int _size;
    unsigned int _capacity;
};