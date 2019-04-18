#ifndef TESTER_H
#define TESTER_H

#include <vector>

#include "LinkedListOfInts.h"

using list = LinkedListOfInts; 

class Tester
{
	public:
		Tester();
		void test();

	private:
		void testSize()			const;
		void testConstructor()	const;
		void testIsEmpty()		const;
		void testSearch()		const;
		void testAddBack()		const;
		void testAddFront()		const;
		void testRemoveBack()	const;
		void testRemoveFront()	const;

		static const std::string fail; 
		static const std::string pass;
		static const std::string startYellow;
		static const std::string endYellow;
		static const std::string startComment;
		static const std::string endComment;
};

void fillList(list& l, bool fromTheBack = true);

#endif //TESTER_H
