#define print_var(x) printf(#x " is %d", x )
#include <stdio.h>

int main() {     
    int z = 10;
    print_var(z);                                                                                            
}

//пишется
// int main() {   
// int z = 10;
// printf("z" " is %d", z );
// }