#include <iostream>
#include <boost/asio.hpp>
#include <array>
using boost::asio::ip::tcp;

int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("127.0.0.1", "8080");

        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        while (true)
        {
            // Listen for messages
            std::array<char, 128> buffer{};
            boost::system::error_code error;

            size_t length = socket.read_some(boost::asio::buffer(buffer), error);

            if (error == boost::asio::error::eof)
            {
                // Clean connection cutoff
                break;
            }
            else if (error)
            {
                throw boost::system::system_error(error);
            }

            std::cout.write(buffer.data(), length);
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}