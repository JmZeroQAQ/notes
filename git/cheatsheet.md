- `git branch <banch>` Create a new branch `branch`
- `git checkout <branch>` Switch to the branch `branch`
- `git checkout -b <branch>` Create a new branch `branch` and switch to it.


### Rebase
`git rebase main`
将当前分支(假设是`bugFix`)所做的提交全部应用到`main`分支上,此时`bugFix`分支既有`main`分支的提交,也有自己在 rebase 前的提交。

### Checkout
`git checkout [<commit>, <branch>]`
如果是`branch`,则切换到这个分支,否则将`HEAD`指向到这个`commit`。

- `git checkout main~`  `HEAD` 指向 `main` 前一个 `commit`.
- `git checkout main~~` `HEAD` 指向 `main` 前两个 `commit`.
- `git checkout main~2` `HEAD` 指向 `main` 前两个 `commit`.

### Branch
- `git branch -f main HEAD~3`
将`main`分支的指向向上移动3个`commit`.

- `git branch -f main xxx`
将`main`分支的指向设置为 `xxx commit`.

- `git reset HEAD^`
将当前分支(假设是`main`)的指向向上移动一个`commit`.

- `git revert HEAD`
引入一个新的`commit`,这个`commit`所做的更改和`HEAD`节点所在`commit`的更改相反.

- `git cherry-pick <commit1> <commit2>`
将所选`commit`引入当前分支.

- `git rebase -i main`
进入交互`rebase`模式,可对当前分支(假设是`feat`)到`main`内所有commit进行操作,如重新排序,去掉某次`commit`.

- `git rebase bugFix main`
将`main`分支rebase到`bugFix`分支上,如果只有一个参数就是将当前分支rebase到指定`branch`上.
类似于 `git rebase <dest_branch> <current_branch>`


### Tags
- `git tag v1 <commit>`
给指定`commit`打上标签.

- `git describe <commit>`
Describe where you are relative to the closest `Tag`.
The output of the command looks like:
`<tag>_<num_commits>_g<hash>`

If not `commit` is specified, use the `commit` where the `HEAD` is located.


### Remote
远程分支,远程分支只在本地仓库中存在,反映出远程仓库的状态,我们无法对远程分支进行提交.

- `git fetch`
更新远程分支,让远程分支反映所绑定远程仓库分支的最新状态.

- `git pull`
实际上就是先执行`git fetch`,然后再执行`git merge o/main`

- `git pull --rebase`
实际上就是先 `git fetch` 然后再 `git rebase o/main`.

- `git push`
假设当前在`main`分支,领先远程仓库的`main`分支两个`commit`,执行这个命令后会同步本地和远程仓库的`main`分支,并让`o/main`反映远程仓库的最新状态.

- `git checkout -b <branch> <commit>`
在指定的`commit`上创建新分支`branch`

- `git push origin <branch>`
将`branch`分支推送到远程仓库,并在本地创建一个对应的`o/branch`远程分支.

- `git checkout -b totally-not-main o/main`

Another way to set remote tracking on a branch is to simply use the `git branch -u` option. Running:
- `git branch -u o/main foo`
will set the `foo` branch to rack `o/main`. If `foo` is currently checked out you can even leave it off:
`git branch -u o/main`


- `git push origin <branch>`
将分支`branch`推送到他追踪的远程仓库分支中.

- `git fetch origin <branch>`

`git commit`
`git commit --amend`
`git branch`
`git switch`
`git checkout`
`git checkout -b`
`git rebase`
`git rebase -i`
`git merge`
`git cherry-pick`
`git clone`
`git fetch`
`git pull`
`git pull --rebse`
`git push`
