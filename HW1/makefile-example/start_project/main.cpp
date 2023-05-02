#include <iostream>
extern int lib_hello();
extern int square(int i);

int main() {
    std::cout << "Hello World!\n";
    lib_hello();
    std::cout << "ARI: square 5 * 5 = "
	      << square(5) << "\n";
    return 0;
}
