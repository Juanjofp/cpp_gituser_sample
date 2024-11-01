#include "mock_requester.h"

#include <iostream>
#include <unordered_map>

namespace jjfp::github_info::tests {
MockRequester::MockRequester() : response_{std::nullopt} {
  std::cout << "?????? Constructing MockRequester " << std::endl;
}

MockRequester::~MockRequester() {
  std::cout << "?????? Destroying MockRequester" << std::endl;
}

void MockRequester::init(std::string) {}

RequesterResponse MockRequester::get(
    const std::string&, const std::unordered_map<std::string, std::string>) {
  if (response_) {
    return *response_;
  }

  return RequesterResponse{0, std::nullopt};
}

RequesterResponse MockRequester::post(const std::string&, const std::string&) {
  if (response_) {
    return *response_;
  }

  return RequesterResponse{0, std::nullopt};
}

std::string MockRequester::get_response(std::string url) {
  std::string me =
      R"({"login":"Juanjofp","id":446496,"node_id":"MDQ6VXNlcjQ0NjQ5Ng==","avatar_url":"https://avatars.githubusercontent.com/u/446496?v=4","gravatar_id":"","url":"https://api.github.com/users/Juanjofp","html_url":"https://github.com/Juanjofp","followers_url":"https://api.github.com/users/Juanjofp/followers","following_url":"https://api.github.com/users/Juanjofp/following{/other_user}","gists_url":"https://api.github.com/users/Juanjofp/gists{/gist_id}","starred_url":"https://api.github.com/users/Juanjofp/starred{/owner}{/repo}","subscriptions_url":"https://api.github.com/users/Juanjofp/subscriptions","organizations_url":"https://api.github.com/users/Juanjofp/orgs","repos_url":"https://api.github.com/users/Juanjofp/repos","events_url":"https://api.github.com/users/Juanjofp/events{/privacy}","received_events_url":"https://api.github.com/users/Juanjofp/received_events","type":"User","site_admin":false,"name":"Juanjo","company":"Digio","blog":"http://juanjofp.com","location":"Murcia, Spain","email":"juanjo@juanjofp.com","hireable":null,"bio":null,"twitter_username":null,"notification_email":"juanjo@juanjofp.com","public_repos":59,"public_gists":5,"followers":35,"following":73,"created_at":"2010-10-20T07:04:01Z","updated_at":"2024-09-07T10:33:10Z"})";

  std::string octokit =
      R"({"login":"octokit","id":3430433,"node_id":"MDEyOk9yZ2FuaXphdGlvbjM0MzA0MzM=","avatar_url":"https://avatars.githubusercontent.com/u/3430433?v=4","gravatar_id":"","url":"https://api.github.com/users/octokit","html_url":"https://github.com/octokit","followers_url":"https://api.github.com/users/octokit/followers","following_url":"https://api.github.com/users/octokit/following{/other_user}","gists_url":"https://api.github.com/users/octokit/gists{/gist_id}","starred_url":"https://api.github.com/users/octokit/starred{/owner}{/repo}","subscriptions_url":"https://api.github.com/users/octokit/subscriptions","organizations_url":"https://api.github.com/users/octokit/orgs","repos_url":"https://api.github.com/users/octokit/repos","events_url":"https://api.github.com/users/octokit/events{/privacy}","received_events_url":"https://api.github.com/users/octokit/received_events","type":"Organization","user_view_type":"public","site_admin":false,"name":"Octokit","company":null,"blog":"http://octokit.github.io","location":null,"email":null,"hireable":null,"bio":"Official clients for the GitHub API","twitter_username":"octokit","public_repos":71,"public_gists":0,"followers":792,"following":0,"created_at":"2013-01-30T18:13:42Z","updated_at":"2023-09-11T20:37:55Z"})";

  std::string repositories = R"(
[
  {
    "id": 1296269,
    "node_id": "MDEwOlJlcG9zaXRvcnkxMjk2MjY5",
    "name": "Hello-World",
    "full_name": "octocat/Hello-World",
    "owner": {
      "login": "octocat",
      "id": 1,
      "node_id": "MDQ6VXNlcjE=",
      "avatar_url": "https://github.com/images/error/octocat_happy.gif",
      "gravatar_id": "",
      "url": "https://api.github.com/users/octocat",
      "html_url": "https://github.com/octocat",
      "followers_url": "https://api.github.com/users/octocat/followers",
      "following_url": "https://api.github.com/users/octocat/following{/other_user}",
      "gists_url": "https://api.github.com/users/octocat/gists{/gist_id}",
      "starred_url": "https://api.github.com/users/octocat/starred{/owner}{/repo}",
      "subscriptions_url": "https://api.github.com/users/octocat/subscriptions",
      "organizations_url": "https://api.github.com/users/octocat/orgs",
      "repos_url": "https://api.github.com/users/octocat/repos",
      "events_url": "https://api.github.com/users/octocat/events{/privacy}",
      "received_events_url": "https://api.github.com/users/octocat/received_events",
      "type": "User",
      "site_admin": false
    },
    "private": false,
    "html_url": "https://github.com/octocat/Hello-World",
    "description": "This your first repo!",
    "fork": false,
    "url": "https://api.github.com/repos/octocat/Hello-World",
    "archive_url": "https://api.github.com/repos/octocat/Hello-World/{archive_format}{/ref}",
    "assignees_url": "https://api.github.com/repos/octocat/Hello-World/assignees{/user}",
    "blobs_url": "https://api.github.com/repos/octocat/Hello-World/git/blobs{/sha}",
    "branches_url": "https://api.github.com/repos/octocat/Hello-World/branches{/branch}",
    "collaborators_url": "https://api.github.com/repos/octocat/Hello-World/collaborators{/collaborator}",
    "comments_url": "https://api.github.com/repos/octocat/Hello-World/comments{/number}",
    "commits_url": "https://api.github.com/repos/octocat/Hello-World/commits{/sha}",
    "compare_url": "https://api.github.com/repos/octocat/Hello-World/compare/{base}...{head}",
    "contents_url": "https://api.github.com/repos/octocat/Hello-World/contents/{+path}",
    "contributors_url": "https://api.github.com/repos/octocat/Hello-World/contributors",
    "deployments_url": "https://api.github.com/repos/octocat/Hello-World/deployments",
    "downloads_url": "https://api.github.com/repos/octocat/Hello-World/downloads",
    "events_url": "https://api.github.com/repos/octocat/Hello-World/events",
    "forks_url": "https://api.github.com/repos/octocat/Hello-World/forks",
    "git_commits_url": "https://api.github.com/repos/octocat/Hello-World/git/commits{/sha}",
    "git_refs_url": "https://api.github.com/repos/octocat/Hello-World/git/refs{/sha}",
    "git_tags_url": "https://api.github.com/repos/octocat/Hello-World/git/tags{/sha}",
    "git_url": "git:github.com/octocat/Hello-World.git",
    "issue_comment_url": "https://api.github.com/repos/octocat/Hello-World/issues/comments{/number}",
    "issue_events_url": "https://api.github.com/repos/octocat/Hello-World/issues/events{/number}",
    "issues_url": "https://api.github.com/repos/octocat/Hello-World/issues{/number}",
    "keys_url": "https://api.github.com/repos/octocat/Hello-World/keys{/key_id}",
    "labels_url": "https://api.github.com/repos/octocat/Hello-World/labels{/name}",
    "languages_url": "https://api.github.com/repos/octocat/Hello-World/languages",
    "merges_url": "https://api.github.com/repos/octocat/Hello-World/merges",
    "milestones_url": "https://api.github.com/repos/octocat/Hello-World/milestones{/number}",
    "notifications_url": "https://api.github.com/repos/octocat/Hello-World/notifications{?since,all,participating}",
    "pulls_url": "https://api.github.com/repos/octocat/Hello-World/pulls{/number}",
    "releases_url": "https://api.github.com/repos/octocat/Hello-World/releases{/id}",
    "ssh_url": "git@github.com:octocat/Hello-World.git",
    "stargazers_url": "https://api.github.com/repos/octocat/Hello-World/stargazers",
    "statuses_url": "https://api.github.com/repos/octocat/Hello-World/statuses/{sha}",
    "subscribers_url": "https://api.github.com/repos/octocat/Hello-World/subscribers",
    "subscription_url": "https://api.github.com/repos/octocat/Hello-World/subscription",
    "tags_url": "https://api.github.com/repos/octocat/Hello-World/tags",
    "teams_url": "https://api.github.com/repos/octocat/Hello-World/teams",
    "trees_url": "https://api.github.com/repos/octocat/Hello-World/git/trees{/sha}",
    "clone_url": "https://github.com/octocat/Hello-World.git",
    "mirror_url": "git:git.example.com/octocat/Hello-World",
    "hooks_url": "https://api.github.com/repos/octocat/Hello-World/hooks",
    "svn_url": "https://svn.github.com/octocat/Hello-World",
    "homepage": "https://github.com",
    "language": null,
    "forks_count": 9,
    "stargazers_count": 80,
    "watchers_count": 80,
    "size": 108,
    "default_branch": "master",
    "open_issues_count": 0,
    "is_template": false,
    "topics": [
      "octocat",
      "atom",
      "electron",
      "api"
    ],
    "has_issues": true,
    "has_projects": true,
    "has_wiki": true,
    "has_pages": false,
    "has_downloads": true,
    "has_discussions": false,
    "archived": false,
    "disabled": false,
    "visibility": "public",
    "pushed_at": "2011-01-26T19:06:43Z",
    "created_at": "2011-01-26T19:01:12Z",
    "updated_at": "2011-01-26T19:14:43Z",
    "permissions": {
      "admin": false,
      "push": false,
      "pull": true
    },
    "security_and_analysis": {
      "advanced_security": {
        "status": "enabled"
      },
      "secret_scanning": {
        "status": "enabled"
      },
      "secret_scanning_push_protection": {
        "status": "disabled"
      },
      "secret_scanning_non_provider_patterns": {
        "status": "disabled"
      }
    }
  }
])";

  std::unordered_map<std::string, std::string> responses{
      {"me", me}, {"octokit", octokit}, {"repositories", repositories}};

  return responses[url];
}

void MockRequester::set_response(const RequesterResponse& response) {
  response_ = response;
}

}  // namespace jjfp::github_info::tests