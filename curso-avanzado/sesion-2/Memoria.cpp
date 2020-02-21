// Memoria

unsigned char c = 'a'; // 1 byte = 8 bits = 256 valores distintos
                       //          0101 1111


unsigned int x = 5;    // 4 bytes = 32 bits
                       // 4,294,967,296‬ valores distintos
                       // Desde 0 hasta 4,294,967,296

int x = 5;             // 4 bytes = 32 bit
                       // 4,294,967,296‬ valores distintos
                       // Desde -2,147,483,647 hasta 2,147,483,647

unsigned long long int x = 5; // 8 bytes = 64 bits
                              // ‭18,446,744,073,709,551,616‬

 
vector<int> v(10);        // 10 * sizeof(int) = 10 * 4 bytes = 40 bytes
vector<int> v(1000000);   // 1M * 4 bytes = 4 MB
vector<int> v(1000000000) // 1G * 4 bytes = 4 GB