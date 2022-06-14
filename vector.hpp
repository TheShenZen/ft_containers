#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

//	<vector> container implementation

# include <memory>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T>>
		class vector
		{
		private:

			// Private members

		public:

			// Member types
			typedef T												value_type; // First template parameter
			typedef Alloc											allocator_type; // Second template parameter
			typedef typename allocator_type::reference				reference; // Reference to value_type
			typedef typename allocator_type::const_reference		const_reference; // Const reference to value_type
			typedef typename allocator_type::pointer				pointer; // Pointer to value_type
			typedef typename allocator_type::const_pointer			const_pointer; // Const pointer to value_type

			typedef 

			// Constructors
			explicit vector(const ); // Default constructor
			explicit vector()

			// Destructor
			~vector();

		};

		vector::vector(/* args */)
		{
		}

		vector::~vector()
		{
		}

}

#endif