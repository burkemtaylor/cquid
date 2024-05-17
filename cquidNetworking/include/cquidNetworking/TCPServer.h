#include <boost/asio.hpp>
#include <cquidNetworking/TCPConnection.h>
#include <functional>
namespace cquid {
    enum class IPV { 
        V4,
        V6
    };

    class TCPServer {
        public:
            TCPServer(IPV ipv, int port);

            int run();

            template <typename T>
            void writeToConnection(int connectionIndex, std::string T);

            template<typename T>
            using listenCallback = std:function<void(int, const T&)>;

            template <typename T>
            void registerListenCallback(int connectionIndex, listenCallback<T> callback);

        private:
            void startAccept();

        private:
            IPV _ipVersion;
            int _port;

            boost::asio::io_context _ioContext;
            boost::asio::ip::tcp::acceptor _acceptor;

            std::vector<TCPConnection::pointer> _connections {};
    };
};