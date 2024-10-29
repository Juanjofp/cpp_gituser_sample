#include <iostream>

#include "githubapp.h"

using namespace jjfp::githubapp;

int main() {
  std::cout << "Sample app for GithubInfo lib!" << std::endl;

  std::string test_token{
      "github_pat_11AADNAIA0QGIRUBk4D49H_"
      "ZlkXNNFFq2yaKdh4j74OqkxrPSN8dTCg2xHWFrikQQmSWAFZEXGmH4kNbZt"};

  auto app = GithubApp{test_token};

  app.show_user_info();

  return 0;
}