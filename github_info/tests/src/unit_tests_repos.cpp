#include <gmock/gmock.h>

#include "github_info_impl.h"
#include "github_repository.h"
#include "github_user.h"
#include "mock_requester.h"

using namespace testing;
using namespace jjfp::github_info;

class GithubReposTests : public Test {
 public:
  const std::shared_ptr<tests::MockRequester> mock_requester{
      std::make_shared<tests::MockRequester>()};

  std::string test_token{"fake_token"};

  GithubInfoImpl github_info{mock_requester, test_token};
};

TEST_F(GithubReposTests, CompareSameReposEqual) {
  GitUser me{446496, "Juanjofp", "Juanjofp",
             "https://avatars.githubusercontent.com/u/446496?v=4",
             "https://api.github.com/users/Juanjofp"};

  GitUser other{446496, "Juanjofp", "Juanjofp",
                "https://avatars.githubusercontent.com/u/446496?v=4",
                "https://api.github.com/users/Juanjofp"};

  ASSERT_THAT(me, Eq(other));
}

TEST_F(GithubReposTests, CompareDifferentReposNotEqual) {
  GitUser me{446496, "Juanjofp", "Juanjofp",
             "https://avatars.githubusercontent.com/u/446496?v=4",
             "https://api.github.com/users/Juanjofp"};

  GitUser other{99999, "Juanjofp2", "Juanjofp2",
                "https://avatars.githubusercontent.com/u/446496?v=4",
                "https://api.github.com/users/Juanjofp"};

  ASSERT_THAT(me, Ne(other));
}

TEST_F(GithubReposTests, GetInformationAboutUserRepositoriesFails) {
  ASSERT_THAT(github_info.repositories("juanjofp").has_value(), false);
  const auto response = RequesterResponse{404, std::nullopt};

  mock_requester->set_response(response);

  const auto repositories = github_info.repositories("juanjofp");

  ASSERT_THAT(repositories.has_value(), false);

  const auto error = repositories.error();

  ASSERT_THAT(error.kind(), Eq(GitError::ErrorKind::ElementNotFound));
}

TEST_F(GithubReposTests, GetInformationAboutUserRepositoriesOk) {
  const auto response =
      RequesterResponse{200, mock_requester->get_response("repositories")};

  mock_requester->set_response(response);

  const auto expected_repos =
      GitRepository::from_json(mock_requester->get_response("repositories"));

  const auto repositories = github_info.repositories("octokit");

  ASSERT_THAT(repositories.has_value(), Eq(true));

  ASSERT_THAT(repositories.value(), Eq(expected_repos));
}