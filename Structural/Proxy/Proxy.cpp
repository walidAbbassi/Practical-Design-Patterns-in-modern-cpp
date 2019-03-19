/*
* C++ Design Patterns: Proxy
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <memory>
#include <regex>
#include <set>
#include <string>

/*
 * Internet  ==>  Subject
 * defines the common interface for RealSubject and Proxy
 * so that a Proxy can be used anywhere a RealSubject is expected
 */
class Internet {
public:
	virtual ~Internet() { /* ... */ }

	virtual void connectTo (const std::string &serverHost) const = 0;
};

/*
 * RealInternet  ==>  Real Subject
 * defines the real object that the proxy represents
 */
class RealInternet : public Internet {
public:
	RealInternet() = default;
	void connectTo(const std::string &serverHost) const override 
	{
		std::cout << "Connecting to " << serverHost << std::endl;
	}
};

/*
 * ProxyInternet  ==>  Proxy
 * maintains a reference that lets the proxy access the real subject
 */
class ProxyInternet : public Internet {
public:
	ProxyInternet() : realInternet (std::make_unique<RealInternet>()){}

	void connectTo(const std::string &serverHost) const override 
	{
		std::smatch matches;
		std::regex_search(serverHost, matches, urlRegex);
		if (bannedSite.find(matches[3]) != bannedSite.end())
		{
			// throw(" Access Denied ");
			std::cout << serverHost << " : Access Denied "<<std::endl;
			return;
		}
		realInternet->connectTo(serverHost);
	}

private:
	const std::set<std::string> bannedSite { "www.first.com" , "www.second.com" , "www.third.com" };
	const std::regex urlRegex{ R"(((http|ftp|https):\/\/)?(([\w.-]*)\.([\w]*)))" };
	std::unique_ptr<RealInternet> realInternet;
};


int main()
{
	std::unique_ptr<ProxyInternet> proxy = std::make_unique<ProxyInternet>();
	proxy->connectTo("www.first.com");
	proxy->connectTo("http://www.second.com");
	proxy->connectTo("http://www.google.com");
	system("pause");
	return 0;
}
