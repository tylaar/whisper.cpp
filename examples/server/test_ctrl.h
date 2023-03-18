//
// Created by Yifeng Yu on 2023/3/18.
//

#ifndef WHISPER_CPP_TEST_CTRL_H
#define WHISPER_CPP_TEST_CTRL_H

/// The TestCtrl.h file
#pragma once
#include <drogon/HttpSimpleController.h>
using namespace drogon;
class TestCtrl:public drogon::HttpSimpleController<TestCtrl>
{
public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
        PATH_ADD("/test",Get);
    PATH_LIST_END
};

/// The TestCtrl.cc file
void TestCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req,
                                      std::function<void (const HttpResponsePtr &)> &&callback)
{
    //write your application logic here
    auto resp = HttpResponse::newHttpResponse();
    resp->setBody("<p>Hello, world!</p>");
    resp->setExpiredTime(0);
    callback(resp);
}
#endif //WHISPER_CPP_TEST_CTRL_H
