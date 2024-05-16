#include <boost/asio.hpp>

namespace cquid {
    enum class IPV {
        V4,
        V6
    };

    class TCPServer {
        public:
            TCPServer(IPV ipv, int port);

            int run();

        private:
            void startAccept();

        private:
            IPV _ipVersion;
            int _port;

            boost::asio::io_context _ioContext;
            boost::asio::ip::tcp::acceptor _acceptor;
    };
};