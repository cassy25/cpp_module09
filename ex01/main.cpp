#include "RPN.hpp"

int main(int argc, char **argv)
{
    try
    {
        RPN rpn;
        if (argc != 2)
            std::cerr << "Only one parameter" << std::endl;
        int result = rpn.result(argv[1]);
        std::cout << result << std::endl;
    }
    catch (std::exception const& mess)
    {
        std::cerr << "ERROR : " << mess.what() << std::endl;
    }
    return 0;
}
