/***
* ==++==
*
* Copyright (c) Microsoft Corporation. All rights reserved. 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* ==--==
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* http_asserts.h - Utility class to help verify assertions about http requests and responses.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/

#pragma once

#include "test_http_server.h"
#include "test_http_client.h"

#include "http_test_utilities_public.h"

namespace tests { namespace functional { namespace http { namespace utilities {

/// <summary>
/// Helper function to do percent encoding of just the '#' character, when running under WinRT.
/// The WinRT http client implementation performs percent encoding on the '#'.
/// </summary>
TEST_UTILITY_API utility::string_t __cdecl percent_encode_pound(utility::string_t str);

/// <summary>
/// Static class containing various http request and response asserts.
/// </summary>
class http_asserts
{
public:

    /// <summary>
    /// Asserts that the specified request is equal to given arguments.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_request_equals(
        web::http::http_request request, 
        const web::http::method &mtd,
        const utility::string_t & relative_uri);

    TEST_UTILITY_API static void __cdecl assert_request_equals(
        web::http::http_request request, 
        const web::http::method &mtd,
        const utility::string_t &relative_uri,
        const std::map<utility::string_t, utility::string_t> &headers);

    TEST_UTILITY_API static void __cdecl assert_request_equals(
        web::http::http_request request, 
        const web::http::method &mtd,
        const utility::string_t & relative_uri,
        const utility::string_t & body);

    /// <summary>
    /// Asserts that the specified response is equal to given arguments.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_response_equals(
        web::http::http_response response,
        const web::http::status_code &code);

    TEST_UTILITY_API static void __cdecl assert_response_equals(
        web::http::http_response response,
        const web::http::status_code &code,
        const utility::string_t &reason);

    TEST_UTILITY_API static void __cdecl assert_response_equals(
        web::http::http_response response,
        const web::http::status_code &code,
        const std::map<utility::string_t, utility::string_t> &headers);

    /// <summary>
    /// Asserts the given http_headers contains the given values.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_http_headers_equals(
        const web::http::http_headers &actual,
        const web::http::http_headers &expected);

    /// <summary>
    /// Asserts the specified test_request is equal to its arguments.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_test_request_equals(
        const test_request *const p_request,
        const web::http::method &mtd,
        const utility::string_t &path);

    /// <summary>
    /// Asserts the specified test_request is equal to its arguments.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_test_request_equals(
        const test_request *const p_request,
        const web::http::method &mtd,
        const utility::string_t &path,
        const utility::string_t &content_type);

    /// <summary>
    /// Asserts the specified test_request is equal to its arguments.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_test_request_contains_headers(
        const test_request *const p_request,
        const web::http::http_headers &headers);

    /// <summary>
    /// Asserts the specified test_request is equal to its arguments.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_test_request_contains_headers(
        const test_request *const p_request,
        const std::map<utility::string_t, utility::string_t> &headers);

    /// <summary>
    /// Asserts the given HTTP request string is equal to its arguments.
    /// NOTE: this function only makes sure the specified headers exist, not that they are the only ones.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_request_string_equals(
        const utility::string_t &request,
        const web::http::method &mtd,
        const utility::string_t &path,
        const utility::string_t &version,
        const std::map<utility::string_t, utility::string_t> &headers,
        const utility::string_t &body);

    /// <summary>
    /// Asserts the given HTTP response string is equal to its arguments.
    /// NOTE: this function only makes sure the specified headers exist, not that they are the only ones.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_response_string_equals(
        const utility::string_t &response,
        const utility::string_t &version,
        const web::http::status_code &code,
        const utility::string_t &phrase,
        const std::map<utility::string_t, utility::string_t> &headers,
        const utility::string_t &body);

    /// <summary>
    /// Asserts the specified test_request is equal to its arguments.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_test_request_equals(
        const test_request *const p_request,
        const web::http::method &mtd,
        const utility::string_t &path,
        const utility::string_t &content_type,
        const utility::string_t &body);

    /// <summary>
    /// Asserts the specified test_response is equal to its arguments.
    /// </summary>
    TEST_UTILITY_API static void __cdecl assert_test_response_equals(
        const test_response * const p_response,
        const web::http::status_code &code);

    TEST_UTILITY_API static void __cdecl assert_test_response_equals(
        const test_response * const p_response,
        const web::http::status_code &code,
        const std::map<utility::string_t, utility::string_t> &headers);

    TEST_UTILITY_API static void __cdecl assert_test_response_equals(
        const test_response * const p_response,
        const web::http::status_code &code,
        const web::http::http_headers &headers);

    TEST_UTILITY_API static void __cdecl assert_test_response_equals(
        test_response * p_response,
        const web::http::status_code &code,
        const utility::string_t &content_type);

    TEST_UTILITY_API static void __cdecl assert_test_response_equals(
        test_response * p_response,
        const web::http::status_code &code,
        const utility::string_t &content_type,
        const utility::string_t data);

private:
    http_asserts() {}
    ~http_asserts() {}
};

#if defined(_WIN32)
#if _MSC_VER >= 1900
#include <winapifamily.h>
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
// For IXMLHttpRequest with Windows 10, the error codes don't directly compare equal anymore.
// Relax verification for now.
#define HTTP_ERROR_CHECK_IMPL(__code)
#else
#define HTTP_ERROR_CHECK_IMPL(__code) if(__code != _exc.error_code()) { VERIFY_IS_TRUE(false, "Unexpected error code encountered."); }
#endif
#else
// The reason we can't directly compare with the given std::errc code is because
// on Windows the STL implementation of error categories are NOT unique across        
// dll boundaries, until VS2015.
#define HTTP_ERROR_CHECK_IMPL(__code) VERIFY_ARE_EQUAL(static_cast<int>(__code), _exc.error_code().default_error_condition().value()); 
#endif
#else
#define HTTP_ERROR_CHECK_IMPL(__code) if(__code != _exc.error_code()) { VERIFY_IS_TRUE(false, "Unexpected error code encountered."); }
#endif


// Helper function to verify http_exception is thrown with correct error code
#define VERIFY_THROWS_HTTP_ERROR_CODE(__expression, __code)                             \
    UNITTEST_MULTILINE_MACRO_BEGIN                                                      \
        try                                                                             \
        {                                                                               \
            __expression;                                                               \
            VERIFY_IS_TRUE(false, "Expected http_exception not thrown");                \
        }                                                                               \
        catch (const web::http::http_exception& _exc)                                   \
        {                                                                               \
            VERIFY_IS_TRUE(std::string(_exc.what()).size() > 0);                        \
            HTTP_ERROR_CHECK_IMPL(__code);                                              \
        }                                                                               \
        catch(...)                                                                      \
        {                                                                               \
            VERIFY_IS_TRUE(false, "Exception other than http_exception thrown");        \
        }                                                                               \
    UNITTEST_MULTILINE_MACRO_END

}}}}
