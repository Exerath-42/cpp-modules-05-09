#include "Struct.hpp"

uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t ui)
{
	return reinterpret_cast<Data *>(ui);
}

int	main()
{
	Data		*ptr = new Data;
	Data		*new_ptr;
	uintptr_t	ui;

	ptr->data = "Some string";
	ui = serialize(ptr);
	new_ptr = deserialize(ui);
	std::cout << "new_ptr->data = " << new_ptr->data << std::endl;
}
