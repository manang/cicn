/*
 * Copyright (c) 2017 Cisco and/or its affiliates.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "icnet_utils_sharable_vector.h"
#include "icnet_http_message.h"

#include <sstream>
#include <vector>
#include <map>

#define HTTP_VERSION "1.0"

namespace icnet {

namespace http {

class HTTPRequest : public HTTPMessage {
 public:

  HTTPRequest(HTTPMethod method,
              const std::string &url, const HTTPHeaders &headers, const HTTPPayload &payload);

  std::string &getQueryString();

  std::string &getPath();

  std::string &getProtocol();

  std::string &getLocator();

  std::string &getPort();

  std::string &getRequestString();

  HTTPHeaders &getHeaders() override;

  HTTPPayload &getPayload() override;

  std::string &getHttpVersion() override;

 private:
  std::string query_string_, path_, protocol_, locator_, port_;
  std::string request_string_;
  HTTPHeaders headers_;
  HTTPPayload payload_;
};

} // end namespace http

} // end namespace icnet