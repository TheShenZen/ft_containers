#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename Iterator>
		class reverse_iterator
	{
		protected:
			iterator_type			_current;

		public:

			typedef					Iterator												iterator_type;
			typedef typename		ft::iterator_traits<Iterator>::iterator_category		iterator_category;
			typedef typename		ft::iterator_traits<Iterator>::value_type				value_type;
			typedef typename		ft::iterator_traits<Iterator>::difference_type			difference_type;
			typedef typename 		ft::iterator_traits<Iterator>::pointer					pointer;
			typedef typename 		ft::iterator_traits<Iterator>::reference				reference;

			reverse_iterator() {}; // Default constructor

			template<class U>
			reverse_iterator&		operator=(const reverse_iterator<U> &rhs)
			{
				if (this == &rhs)
					return *this;
				this->_current = rhs.base();
			};

			iterator_type			base(void)
			{
				return this->_current;
			};

			reference				operator*() const
			{
				Iterator tmp = this->_current;
				return *--tmp;
			};

			pointer					operator->() const
			{
				return &(operator*());
			};

			/*unspecified*/			operator[](difference_type n) const
			{
				return *(*this + n);
			};

			reverse_iterator&		operator++()
			{
				--current;
				return *this;
			};

			reverse_iterator&		operator--()
			{
				++current;
				return *this;
			};

			reverse_iterator		operator++( int );
			{
				reverse_iterator	tmp;
				operator++();
				return tmp;
			}

			reverse_iterator		operator--( int )
			{
				reverse_iterator	tmp;
				operator--();
				return tmp;
			};

			reverse_iterator		operator+( difference_type n ) const;
			reverse_iterator		operator-( difference_type n ) const;
			reverse_iterator&		operator+=( difference_type n );
			reverse_iterator&		operator-=( difference_type n );

			virtual ~reverse_iterator() {}; // Default destructor

	};
}

#endif