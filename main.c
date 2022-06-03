#include "http-client-c/src/http-client-c.h"

int main(){
    struct parsed_url *purl = parse_url("http://www.google.com/");
    struct http_response *hrep = http_req("GET / HTTP/1.1\r\nHostname:www.google.com\r\nConnection:close\r\n\r\n", purl);
}