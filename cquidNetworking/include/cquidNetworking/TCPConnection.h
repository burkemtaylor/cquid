#pragma once
#include <boost/asio.hpp>
#include <memory>

namespace cquid {
    using boost::asio::ip::tcp;

    class TCPConnection : public std::enable_shared_from_this<TCPConnection>{
        public:
            using pointer = std::shared_ptr<TCPConnection>;
            static pointer create(boost::asio::io_context& ioContext) {
                return pointer(new TCPConnection(ioContext));
            }

            tcp::socket& socket() {
                return  _socket;
            }
            
            void start();

        
        private: 
            explicit TCPConnection(boost::asio::io_context& ioContext);

        private: 
            tcp::socket _socket;
            std::string _message {"Hello, beautiful client!\n"};
    };
}