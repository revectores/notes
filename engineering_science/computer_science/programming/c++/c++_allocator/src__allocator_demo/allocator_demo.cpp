#include <memory>
#include <string>
#include <iostream>


int main(){
	std::allocator<std::string> alloc;
	auto const p = alloc.allocate(5);

	auto q = p;
	alloc.construct(q++);
	alloc.construct(q++, 10, '0');
	alloc.construct(q++, "Hi");

	for (int i = 0; i < 5; i++){
		std::cout << p[i] << std::endl;
	}

	while (q != p) alloc.destroy(--q);
	alloc.deallocate(p, 5);

	for (int i = 0; i < 5; i++){
		std::cout << p[i] << std::endl;
	}
}