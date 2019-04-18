#include "tester.h"
#include <iostream>
#include "string"
#include <vector>


const std::string Tester::fail			= "\033[1;31mFAILED\033[0m";
const std::string Tester::pass			= "\033[1;32mPASSED\033[0m";
const std::string Tester::startYellow	= "\033[1;33m";
const std::string Tester::endYellow		= "\033[0m";
const std::string Tester::startComment  = "\033[1;34m";
const std::string Tester::endComment	= "\033[0m";

Tester::Tester()
{

}


void Tester::test()
{
	std::cout << startYellow << "Testing size method" << endYellow << '\n';
	testSize();
	std::cout << '\n';
	
	std::cout << startYellow << "Testing Constructor" << endYellow << '\n';
	testConstructor();
	std::cout << '\n';

	std::cout << startYellow << "Testing isEmpty method" << endYellow << '\n';
	testIsEmpty();
	std::cout << '\n';

	std::cout << startYellow << "Testing search method" << endYellow << '\n';
	testSearch();
	std::cout << '\n';

	std::cout << startYellow << "Testing addBAck method" << endYellow << '\n';
	testAddBack();
	std::cout << '\n';

	std::cout << startYellow << "Testing addFront method" << endYellow << '\n';
	testAddFront();
	std::cout << '\n';
}


void Tester::testSize()	const
{
	constexpr int maxTests = 10;
	std::string passValue;
	std::string removedValue;
	std::string removeBackValue;
	list testList;

	for(int i = 0; i < maxTests; ++i)
	{
		std::cout << "List of size " << i << " size function returns " << i << ": ";
		passValue = testList.size() == i ? pass : fail; 
		std::cout << '\t' << passValue << '\n';
		testList.addBack(i);
	}

	testList.removeBack();

	removedValue = testList.size() == maxTests - 2 ? pass : fail; 
	std::cout << "Testing size after removing removeBack: \t" << removedValue << '\n';

	list secondList;

	fillList(secondList, false);

	secondList.removeFront();
	removeBackValue = testList.size() == maxTests - 2 ? pass : fail;
	std::cout << "Testing size after removing removeFront: \t" << removedValue << '\n';
}


void Tester::testConstructor() const
{
	std::cout << "Size of empty list is zero: ";
	list testList;

	if(testList.size() == 0)
	{
		std::cout << pass << '\n';
	}
	else
	{
		std::cout << fail << '\n';
	}
}


void Tester::testIsEmpty() const
{
	list testList;
	std::string emptyValue;
	std::string fullValue;

	emptyValue = testList.size() == 0 ? pass : fail;

	testList.addBack(5);

	fullValue  = testList.size() >  0 ? pass : fail;

	std::cout << "isEmpty returns true on empty list:\t "		 << emptyValue << '\n';
	std::cout << "isEmpty returns false on non-empty list: " << emptyValue << '\n';
}


void Tester::testSearch() const
{
	std::string emptyValue;
	std::string singleValue;
	std::string fullValue;
	std::string notInValue;
	std::string removedValue;
	list testList;
	int values[5] = {5, 12, 234, 243890, 890};

	emptyValue = testList.search(0) ? fail : pass;
	
	testList.addFront(values[0]);
	singleValue = testList.search(5) ? pass : fail;

	testList.addFront(values[1]);
	testList.addFront(values[2]);
	testList.addFront(values[3]);
	testList.addFront(values[4]);

	fullValue = testList.search(values[3]) ? pass : fail;
	notInValue = testList.search(-1) ? fail : pass;
	testList.removeBack();
	removedValue = testList.search(values[4]) ? fail : pass;

	std::cout << "Testing empty list for search of 0: \t\t\t\t"					   << emptyValue   << '\n';
	std::cout << "Testing size 1 list for search of value in list: \t\t"		   << fullValue    << '\n';
	std::cout << "Testing populated list for search of value in list: \t\t"		   << fullValue    << '\n';
	std::cout << "Testing populated list for search of value not in list: \t"	   << notInValue   << '\n';
	std::cout << "Testing populated list for search of value removed fromlist: \t" << removedValue << '\n';
}

void Tester::testAddBack() const
{
	list testList;

	fillList(testList);

	auto vec = testList.toVector();
	std::string value;

	std::cout << startComment;
	std::cout << "\nTesting by ensuring that toVector returns\n"
			  << "A list of numbers that are in the same order\n"
			  << "and have the same value as the numbers inserted\n"
			  << "into the list\n\n";
	std::cout << endComment;

	for(int i = 0; i < 10; ++i)
	{
		value = vec[i] == i ? pass : fail;
		std::cout << "v[i] == l[i]: " << value << '\n';
	}
}

void Tester::testAddFront()	const
{
	list testList;
	std::vector<int> comparer;
	std::string value;

	for(int i = 0; i < 10; ++i)
	{
		testList.addFront(i);
		comparer.insert(comparer.begin(), i);
	}

	std::cout << startComment;
	std::cout << "\nTesting by ensuring that toVector returns\n"
			  << "A list of numbers that are in the reverse order\n"
			  << "and have the same value as the numbers inserted\n"
			  << "into the list\n\n";
	std::cout << endComment;

	for(int i = 0; i < 10; ++i)
	{
		value = comparer[i] == (10 - i) ? pass : fail; 
		std::cout << "v[i] == 10 - i : " << value << '\n';
	}

}


void Tester::testRemoveBack() const
{
	list testList;
	fillList(testList);
	auto vec = testList.toVector();
	std::string value;

	std::cout << startComment;
	std::cout << "\nTesting by ensuring that the values in the vector returned\n"
			  << "by toVector match the expected values after removing from the"
			  << "back of the list\n\n" ;
	std::cout << endComment;

	for(int i = 0; i < 10; ++i)
	{
	}
}

void fillList(list& l, bool fromTheBack)
{
	for(int i = 0; i < 10; ++i)
	{
		if(fromTheBack)
		{
			l.addBack(i);
		}
		else
		{
			l.addFront(i);
		}
	}
}
