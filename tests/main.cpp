#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

/*****************************/

#include "color.hpp"
#include <iostream>
#include <typeinfo>
#include <iterator>

/*****************************/
//	Iterator traits tests
/*****************************/
void	iterator_traits_test(void)
{
	typedef ft::iterator_traits<int*> traits;
	std::cout << color("Testing ft::iterator_traits against the std version", YELLOW) << std::endl << std::endl;
	std::cout << color("typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag", BLACK) << " : ";
	if (typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag))
		std::cout << color("SUCCESS", GREEN);
	else
		std::cout << color("FAIL", RED);
}
int		main(void)
{
	iterator_traits_test();
}