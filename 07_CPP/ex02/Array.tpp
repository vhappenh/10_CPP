/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:08:14 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/17 10:54:44 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array() : sz(0), arr(new T[sz]) {
}

template <typename T>
Array<T>::Array(const unsigned int n) : sz(n) {
	arr = new T[sz];
}

template <typename T>
Array<T>::Array(const Array& other) {
	sz = other.sz;
	arr = new T[sz];
    for (unsigned int i = 0; i < sz; ++i) {
        arr[i] = other.arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other)
	{
		delete arr;
		sz = other.sz;
		arr = new T[sz];
	    for (unsigned int i = 0; i < sz; ++i) {
    	    arr[i] = other.arr[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array() {
	delete []arr;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const {
    if (index >= sz) {
        throw std::out_of_range("Index out of bounds");
    }
    return arr[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return sz;
}