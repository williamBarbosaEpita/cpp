#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    int res = 0;
    std::ifstream file(argv[1]);
    std::string word;

    if (argc != 3)
        return EXIT_FAILURE;
    if (file.fail())
    {
        std::cout << "The file " << argv[1] << " could not be opened.\n";
        return EXIT_FAILURE;
    }
    while (file >> word)
        if (word.find(argv[2]) != std::string::npos)
            res++;
    std::cout << "The file " << argv[1] << " contains " << res << " words containing the motive " << argv[2] << "\n";
    return EXIT_SUCCESS;
}
