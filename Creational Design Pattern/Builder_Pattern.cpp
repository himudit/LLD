#include <bits/stdc++.h>
#include <iostream>
#include <string>
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
    HTTP()
    {
    }
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
    HTTP http;

public:
    HTTPBuilder &setMethod(Method m)
    {
        http.method = m;
        return *this;
    }
    HTTPBuilder &setHeaders(string h)
    {
        http.headers = h;
        return *this;
    }
    HTTPBuilder &setQueryParams(string qp)
    {
        http.query_params = qp;
        return *this;
    }
    HTTPBuilder &setBody(string b)
    {
        http.body = b;
        return *this;
    }
    HTTP build()
    {
        return http;
    }
};
int main()
{
    HTTP http1 = HTTPBuilder()
                     .setBody("id:3930,name:mudit")
                     .setHeaders("application/json")
                     .setQueryParams("page=4")
                     .setMethod(Method::POST)
                     .build();
    http1.showDetails();

    HTTP http2 = HTTPBuilder()
                     .setBody("id:600,name:garg")
                     .setHeaders("json")
                     .setQueryParams("page=1")
                     .setMethod(Method::GET)
                     .build();
    http2.showDetails();
}

// friend class HTTPBuilder -> helps HTTPBuilder to access Private/Protected Data Members.
// Never make Builder in Abstract class it must be in Concrete class.
