# git 基本操作

## 相关网页

- [git home page](https://git-scm.com/)
  - [中文学习网页](https://git-scm.com/book/zh/v2)
  - [git 软件下载链接](https://git-scm.com/downloads)

## git 常用命令

### git clone

```shell
git clone <Git 仓库 url>
```

将 http 或 ssh 链接指向的 Git 仓库拷贝到本地。

### git add

```shell
git add <file>
```

将文件添加到缓存区，该文件被标记为被追踪

```shell
git add .
```

缓存当前目录下所有文件，不包括已删除的文件

### git diff

```shell
git diff
```

不加参数即默认比较工作区与暂存区

### git commit

```shell
git commit -m <comment>
```

一次性将缓存区所有文件修改提交到仓库的当前分支

```shell
git commit -am <comment>
```

自动把所有已经跟踪过的文件缓存，并提交到仓库。常用于跳过 git add 步骤快速提交

```shell
git commit -F commit.txt
```

文件中包含 comment 信息，会比较规范

### git push

```shell
git push <remote-repo-shortname> <local-branch>
```

将本地分支推送到远程仓库。

```shell
git push origin master --force
```

将本地分支强制推到远程分支

### git pull

```shell
git pull <remote-shortname> <local-branch>
```

拉取远程仓库最新提交，并合并到指定的本地分支上。

### git fetch

```shell
git fetch
```

拉取远程仓库最新提交，但不会自动合并分支。

### git reset

```shell
git reset --hard
```

重置所有文件到上次 commit 的状态。

```shell
git reset --hard <commit>
```

将当前分支重置为指定版本。

```shell
git reset --hard HEAD~1
```

将当前分支重置为倒数第 2 个版本。

### git status

```shell
git status
```

显示当前仓库的最新状态。

### git stash

```shell
git stash
```

保存当前工作进度，会把暂存区和工作区的改动保存起来。执行完这个命令后，在运行 git status 命令，就会发现当前是一个干净的工作区，没有任何改动。

```shell
git stash list
```

显示保存进度的列表。也就意味着，git stash 命令可以多次执行。

```shell
git stash pop stash@{1}
```

恢复指定的进度到工作区。stash_id 是通过 git stash list 命令得到的,通过 git stash pop 命令恢复进度后，会删除当前进度。

```shell
git stash clear
```

删除所有存储的进度。

### git log

```shell
git log
```

查看 log

```shell
git log --author="jack"
```

根据用户过滤
