#pragma once

#include <string>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

namespace bling { namespace core { namespace service {

	class HTTPClientService
	{
	public:
		HTTPClientService();
		~HTTPClientService();
		bool send(const std::string& server, const std::string& port, const std::string&, std::map<std::string, std::string>& headers, std::string& content, unsigned int& status_code);
	private:
		bool receive(std::map<std::string, std::string>& headers, std::string& content, unsigned int& status_code);
	private:
		boost::asio::io_service m_io_service;
		std::string m_root;
		std::auto_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>> m_socket;
		boost::asio::ssl::context context_;
	};
}}}