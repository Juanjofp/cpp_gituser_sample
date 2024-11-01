#include <gmock/gmock.h>

#include "github_info_impl.h"
#include "github_repository.h"
#include "github_user.h"
#include "mock_requester.h"

using namespace testing;
using namespace jjfp::github_info;

class GithubTests : public Test {
 public:
  const std::shared_ptr<tests::MockRequester> mock_requester{
      std::make_shared<tests::MockRequester>()};

  std::string test_token{"fake_token"};

  GithubInfoImpl github_info{mock_requester, test_token};
};

TEST_F(GithubTests, ContainsVersion) {
  ASSERT_THAT(github_info.print_version(), StartsWith("v"));
}

TEST_F(GithubTests, PrintVersion) {
  ASSERT_THAT(github_info.print_version(), Eq("v0.1.0"));
}

TEST_F(GithubTests, PrintVersionNotEqual) {
  ASSERT_THAT(github_info.print_version(), Ne("v0.1.1"));
}

TEST_F(GithubTests, CompareSameUsersEqual) {
  GitUser me{446496, "Juanjofp", "Juanjofp",
             "https://avatars.githubusercontent.com/u/446496?v=4",
             "https://api.github.com/users/Juanjofp"};

  GitUser other{446496, "Juanjofp", "Juanjofp",
                "https://avatars.githubusercontent.com/u/446496?v=4",
                "https://api.github.com/users/Juanjofp"};

  ASSERT_THAT(me, Eq(other));
}

TEST_F(GithubTests, CompareDifferentUsersNotEqual) {
  GitUser me{446496, "Juanjofp", "Juanjofp",
             "https://avatars.githubusercontent.com/u/446496?v=4",
             "https://api.github.com/users/Juanjofp"};

  GitUser other{99999, "Juanjofp2", "Juanjofp2",
                "https://avatars.githubusercontent.com/u/446496?v=4",
                "https://api.github.com/users/Juanjofp"};

  ASSERT_THAT(me, Ne(other));
}

TEST_F(GithubTests, GetInformationAboutMeFails) {
  const auto response = RequesterResponse{0, std::nullopt};

  mock_requester->set_response(response);

  const auto user = github_info.me();

  ASSERT_THAT(user.has_value(), Eq(false));

  const auto error = user.error();

  ASSERT_THAT(error.kind(), Eq(GitError::ErrorKind::ServerError));
}

TEST_F(GithubTests, GetInformationAboutMeNotFound) {
  const auto response = RequesterResponse{404, std::nullopt};

  mock_requester->set_response(response);

  const auto user = github_info.me();

  ASSERT_THAT(user.has_value(), Eq(false));

  const auto error = user.error();

  ASSERT_THAT(error.kind(), Eq(GitError::ErrorKind::ElementNotFound));
}

TEST_F(GithubTests, GetInformationAboutMe) {
  const auto response =
      RequesterResponse{200, mock_requester->get_response("me")};

  mock_requester->set_response(response);

  auto me = GitUser::from_json(mock_requester->get_response("me"));

  ASSERT_THAT(github_info.me().value(), Eq(me));
}

TEST_F(GithubTests, GetInformationAboutUserFails) {
  const auto response = RequesterResponse{404, std::nullopt};

  mock_requester->set_response(response);

  const auto user = github_info.user("octokit");

  ASSERT_THAT(user.has_value(), false);

  const auto error = user.error();

  ASSERT_THAT(error.kind(), Eq(GitError::ErrorKind::ElementNotFound));
}

TEST_F(GithubTests, GetInformationAboutUser) {
  const auto response =
      RequesterResponse{200, mock_requester->get_response("octokit")};

  mock_requester->set_response(response);

  auto user = GitUser::from_json(mock_requester->get_response("octokit"));

  ASSERT_THAT(github_info.user("octokit").value(), Eq(user));
}

TEST_F(GithubTests, GetInformationAboutUserRepositoriesFails) {
  ASSERT_THAT(github_info.repositories("juanjofp").has_value(), false);
  const auto response = RequesterResponse{404, std::nullopt};

  mock_requester->set_response(response);

  const auto repositories = github_info.repositories("juanjofp");

  ASSERT_THAT(repositories.has_value(), false);

  const auto error = repositories.error();

  ASSERT_THAT(error.kind(), Eq(GitError::ErrorKind::ElementNotFound));
}

TEST_F(GithubTests, GetInformationAboutUserRepositoriesOk) {
  const auto response =
      RequesterResponse{200, mock_requester->get_response("repositories")};

  mock_requester->set_response(response);

  const auto repositories =
      GitRepository::from_json(mock_requester->get_response("repositories"));

  ASSERT_THAT(github_info.repositories("octokit").value(), Eq(repositories));
}