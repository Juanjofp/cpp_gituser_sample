#include <gmock/gmock.h>

#include "github_info_impl.h"
#include "github_repositories.h"
#include "github_repository.h"
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
  GitRepository one{"one", "description"};

  GitRepository two{"one", "description"};

  ASSERT_THAT(one, Eq(two));
}

TEST_F(GithubReposTests, CompareDifferentReposNotEqual) {
  GitRepository one{"one", "description"};

  GitRepository two{"two", "description"};

  ASSERT_THAT(one, Ne(two));
}

TEST_F(GithubReposTests, GetInformationAboutRepositoriesFails) {
  const auto response = RequesterResponse{404, std::nullopt};

  mock_requester->set_response(response);

  const auto repositories = github_info.repositories("juanjofp");

  ASSERT_THAT(repositories.has_value(), false);

  const auto error = repositories.error();

  ASSERT_THAT(error.kind(), Eq(GitError::ErrorKind::ElementNotFound));
}

TEST_F(GithubReposTests, GetInformationAboutRepositoriesOk) {
  const auto response =
      RequesterResponse{200, mock_requester->get_response("repositories")};

  mock_requester->set_response(response);

  const auto expected_repos =
      GitRepositories::from_json(mock_requester->get_response("repositories"));

  const auto repositories = github_info.repositories("octokit");

  ASSERT_THAT(repositories.has_value(), Eq(true));

  ASSERT_THAT(repositories->size(), Eq(1));

  const auto repo = repositories->at(0);

  ASSERT_THAT(repo.has_value(), Eq(true));

  const auto expected_repo = expected_repos->at(0).value().get();

  const auto actual_repo = repo.value().get();

  ASSERT_THAT(*expected_repo, Eq(*actual_repo));
}