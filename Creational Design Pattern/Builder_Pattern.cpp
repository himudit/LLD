#include <bits/stdc++.h>
using namespace std;

enum Method
{
    POST,
    GET,
    PUT,
    DELETE
};
// HTTP Request Builder
class HTTP
{
private:
    Method method;
    string headers;
    string query_params;
    string body;

public:
    HTTP(const Method &m, const string &headers, const string &query_params, const string &body) : method(m), headers(headers), query_params(query_params), body(body) {}

    void showDetails()
    {
        cout << method << endl;
        cout << headers << endl;
        cout << query_params << endl;
        cout << body << "FINISH" << endl;
    }
    friend class HTTPBuilder;
};
class HTTPBuilder
{
private:
    Method method;
    bool hasMethod = false;

    string headers;
    string query_params;
    string body;

public:
    HTTPBuilder(Method m)
    {
        method = m;
    }
    HTTPBuilder &setHeaders(string h)
    {
        headers = h;
        return *this;
    }
    HTTPBuilder &setQueryParams(string qp)
    {
        query_params = qp;
        return *this;
    }
    HTTPBuilder &setBody(string b)
    {
        body = b;
        return *this;
    }
    HTTP build()
    {
        return HTTP(method, headers, query_params, body);
    }
};
int main()
{
    HTTP http1 = HTTPBuilder(Method::POST)
                     .setBody("id:3930,name:mudit")
                     .setHeaders("application/json")
                     .setQueryParams("page=4")
                     .build();
    http1.showDetails();
}

// friend class HTTPBuilder -> helps HTTPBuilder to access Private/Protected Data Members.
// Never make Builder in Abstract class it must be in Concrete class.
// Builder should not mutate the Object directly.