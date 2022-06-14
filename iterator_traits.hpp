#ifndef FT_ITERATOR_TRAITS_HPP
# define FT_ITERATOR_TRAITS_HPP

#include <cstddef>

namespace ft
{
	struct	input_iterator_tag {};
	// marks input iterators -> can only read values and can only be incremented or derefferenced

	struct	output_iterator_tag {};
	// marks output iterators -> can only change values and can only be incremented or derefferenced

	struct	forward_iterator_tag : public input_iterator_tag {};
	// marks forward iterators -> can read and write and can only be incremented or derefferenced

	struct	bidirectional_iterator_tag : public forward_iterator_tag {};
	// marks the bidirectional iterators -> can read and write, can be incremented or decremented and derferenced

	struct	random_acces_iterator_tag : public bidirectional_iterator_tag {};
	// marks the random access iterators -> can read and write, can be incremented or decremented, dereferenced and offset dereferenced operator

	// std::iterator_traits is the type trait class that provides uniform interface to the properties of LegacyIterator types. This makes it possible to implement algorithms only in terms of iterators.
	// The template can be specialized for user-defined iterators so that the information about the iterator can be retrieved even if the type does not provide the usual typedefs.

	template<class Iterator>
		struct iterator_traits
		{
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
		};

	template<typename T>
		struct iterator_traits<T*>
		{
			typedef	random_acces_iterator_tag	iterator_category;
			typedef	T							value_type;
			typedef	std::ptrdiff_t				difference_type;
			typedef	T*							pointer;
			typedef	T&							reference;
		};

	template<typename T>
		struct iterator_traits<const T*>
		{
			typedef	random_acces_iterator_tag	iterator_category;
			typedef	T							value_type;
			typedef	std::ptrdiff_t				difference_type;
			typedef	T*							pointer;
			typedef	T&							reference;
		};
}

#endif