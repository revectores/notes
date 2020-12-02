# Python Library GitPython

`GitPython` provides a python interface to interact with git repositories.



##### # `GitPython` Basic Usage

To connect to the repository:

```python
import git
repo = git.Repo(git_repo_path)
```

where `git_repo_path` shall be a 

Iterate commits on `master` branch:

```python
commits = list(repo.iter_commits("master"))
for commit in commits:
    print(commit)
```

Check the `stats` (file modification log) of each commit:

```python
last_commit = commits[0]
print(last_commit.stats.files)
```



##### # Low Level Command Execution

`GitPython` also provides low-level interface to execute git command by a more gentle approach. For instance, to execute `git show` command:

```python
repo.git.show(numstat=True, summary=True)
```

This would be interpretd as the shell command

```shell
git show --numstat --summary
```



