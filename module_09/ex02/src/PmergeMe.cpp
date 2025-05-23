/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:47:16 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/23 10:38:10 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

PmergeMe::PmergeMe() :
	_vectorTime(0.0),
	_dequeTime(0.0)
{}

/* ******************************* destructor ****************************** */

PmergeMe::~PmergeMe()
{}

/* ***************************** copy constructor *************************** */

PmergeMe::PmergeMe( const PmergeMe& other ) :
	_vector(other._vector),
	_deque(other._deque),
	_vectorTime(other._vectorTime),
	_dequeTime(other._dequeTime)
{}

/* ********************** copy assignment operator ************************** */

PmergeMe& PmergeMe::operator=( const PmergeMe& other )
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
		_vectorTime = other._vectorTime;
		_dequeTime =other._dequeTime;
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructors ***************************** */

PmergeMe::PmergeMe(char **argv)
{
	size_t n_arg = 0;
	while (argv[n_arg])
		n_arg++;
	if (n_arg < 2)
		throw InvalidInputException();
	parseInput(argv);
}

/* ******************************** getters ********************************* */

void PmergeMe::displaySortVectorDuration()
{
	std::cout << "Time to process a range of " << _vector.size()
	<< " elements with std::vector : "
	<< std::fixed << _vectorTime << " ms"
	<< std::endl;
}

/* ******************************** setters ********************************* */

/* ******************************** exceptions ****************************** */

const char * PmergeMe::InvalidInputException::what() const throw()
{
	return ("Error");
}

/* ************************* other public methods *************************** */

void PmergeMe::displayVector()
{
	std::vector<int>::iterator it = _vector.begin();
	for (; it != _vector.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void PmergeMe::displayDeque()
{
	std::deque<int>::iterator it =  _deque.begin();
	for (; it != _deque.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void PmergeMe::sort()
{
	sortVector(_vector);
	// sortDeque(_deque);
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

void PmergeMe::parseInput(char **argv)
{
	size_t i = 1;
	while (argv[i]) {
		if (!isValidPositiveInt(argv[i]))
			throw InvalidInputException();
		int n = std::atoi(argv[i++]);
		_vector.push_back(n);
		_deque.push_back(n);
	}
}

bool PmergeMe::isValidPositiveInt(char *arg)
{
	if (!arg)
		return (false);

	char *end;
	long l = std::strtol(arg, &end, 10);
	if (l < 1 || l > static_cast<long>(std::numeric_limits<int>::max()) || *end != '\0')
		return (false);
	return (true);
}

void PmergeMe::sortVector(std::vector<int> & vector)
{
	if (vector.size() <= 1)
		return ;

	clock_t start = clock();

	std::vector<int> small, big;
	for (size_t i = 1; i < vector.size(); i+=2) {
		if (vector[i] > vector[i - 1]) {
			small.push_back(vector[i - 1]);
			big.push_back(vector[i]);
		}
		else {
			small.push_back(vector[i]);
			big.push_back(vector[i - 1]);
		}
	}
	if (vector.size() % 2 == 1)
		big.push_back(vector.back());

	sortVector(big);

	for (size_t i = 0; i  < small.size(); i++) {
		std::vector<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[i]);
		big.insert(it, small[i]);
	}
	vector = big;

	clock_t end = clock();
	_vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */

/* ******************************** overloads ******************************* */

/* *********************** other non-member functions *********************** */

