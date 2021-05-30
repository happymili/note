# 冷门操作

## git 的科学操作

- 实际产品开发过程中，至少要有三类分支，一类用于产品 release，比如通常叫 master 分支；一类用于开发过程中的合并和测试，通常叫 develop 分支；另外一类分支是即将要解决的各种 issue，通常按照 issue 命名
- issue 分支从 JIRA 的实际 issue 的页面创建，JIRA 和 git 集成在一起的好处是会将该 issue 名作为分支名，方便管理，也为后续的代码 review 提供参考信息
- develop 分支接受各个 issue 分支的合并，如果解决的 issue 需要 release 到 master，那么需要在 develop 分支先做完集成测试，然后 Create pull request，代码 review 后，由负责人合并到 master
- master 分支的代码更新后，会触发 bamboo 编译及打包发布

## 为什么要有 develop 分支

- 根据实际经验，develop 存在的一个目的是接收各个 issue 的合并，然后在需要 release 之前，做完集成测试，然后再合并到 master
- 如果各个 issue 之间是有关联的，需要合并到一起才能做测试，这时候，合并到 develop 做测试是比较不错的选择
- 如果 master 分支测试出了 issue，对比测试发现次新的版本没有 issue，这时候将最近合并的 develop 分支进行一次 revert 操作即可快速回退

## SonarQube 扫描的分支

- 用于代码静态扫描

## Pull Request 冲突如何解决

### 场景一

- 如果 Pull Request 冲突，那么先取消 Pull Request
- 假设将 issue 分支合并到 develop 分支出现冲突
- 本地先将 develop 合并到 issue 分支，本地 commit and merge，然后 Undo，合并的代码会保留在 issue 分支，将冲突解决，仅将冲突的文件 Push 到 issue 分支
- 再发起 Pull Request

### 场景二

- 如果 Pull Request 冲突，那么先取消 Pull Request
- 假设将 issue 分支合并到 develop 分支出现冲突
- 本地先将 develop 合并到 issue 分支，将冲突解决，Merge 到 issue 分支
- 再发起 Pull Request

## IAR 配置换行符

windows，换行符是 0d 0a "\r\n"，UNIX 标准，换行符是 0a "\n"，如果系统当前配置与已有代码的换行符不统一，会导致修改代码后，出现大量的差异，下面是 IAR 环境配置换行符的方法

- Editor
  - File Encoding
    - EOL characters
      - PC 如果 PC 是 windows，换行符是 0d 0a "\r\n"
      - UNIX 按照 UNIX 标准，换行符是 0a "\n"
      - Preserve

如果出现某些文件的换行符不统一，可以通过 IAR 的编辑功能对文件进行编辑，然后根据配置的换行符类型，切换换行符

## IAR 要提交的文件类型

- ewd 调式器相关的配置
- ewp 工程相关的配置
- eww 工作空间相关的配置

## CCS 要提交的文件类型

- .cproject 工程相关的配置

## 用 git 清理垃圾文件

### 方法一

- 将当前分支 Reset 到最早的提交（Hard-discard all changes）
- 然后会产生很多多余的文件
- stash
- delete stash

### 方法二（这种方法更安全快速）

- 删除.gitignore 文件
- stash
- delete stash
