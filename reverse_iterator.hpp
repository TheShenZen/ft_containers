#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename Iterator>
		class reverse_iterator
	{
		public:

			typedef					Iterator												iterator_type;
			typedef typename		ft::iterator_traits<Iterator>::iterator_category		iterator_category;
			typedef typename		ft::iterator_traits<Iterator>::value_type				value_type;
			typedef typename		ft::iterator_traits<Iterator>::difference_type			difference_type;
			typedef typename 		ft::iterator_traits<Iterator>::pointer					pointer;
			typedef typename 		ft::iterator_traits<Iterator>::reference				reference;

			reverse_iterator() : _current() {}; // Default constructor

			explicit reverse_iterator(iterator_type x) : _current(x) {};

			template<class U>
			reverse_iterator(const reverse_iterator<U> &x) : _current(x._current) {}; 

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

			reference				operator[](difference_type n) const
			{
				return *(*this + n);
			};

			reverse_iterator&		operator++()
			{
				--(this->_current);
				return *this;
			};

			reverse_iterator&		operator--()
			{
				++(this->_current);
				return *this;
			};

			reverse_iterator		operator++( int )
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

			reverse_iterator		operator+( difference_type n ) const
			{
				return reverse_iterator(this->_current - n);
			};

			reverse_iterator		operator-( difference_type n ) const
			{
				return reverse_iterator(this->_current + n);
			};

			reverse_iterator&		operator+=( difference_type n )
			{
				this->_current -= n;
				return *this;
			};

			reverse_iterator&		operator-=( difference_type n )
			{
				this->_current += n;
				return *this;
			};

			virtual ~reverse_iterator() {}; // Default destructor

		protected:
			iterator_type			_current;
	};
}

#endif