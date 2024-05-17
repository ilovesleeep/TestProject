# TestProject

## Set user info
	$ git config --global user.name "xxx"
	$ git config --global user.email "xxx@xxx"

	$ ssh-keygen -t rsa -C "xxx@xxx"        // 一路 Enter

	$ cat ~/.ssh/id_rsa.pub			// 复制公钥

在 Github 上点击个人头像，Settings -> SSH and GPG keys -> New SSH key

Title 随便写，将公钥粘贴到 Key 中，点击 Add SSH key 确认

	// 测试
	$ ssh -T git@github.com

键入 yes，出现 successfully 内容即可

## Fork and Clone
	// 在 Github 上 Fork 本项目，然后将 Fork 的项目 Clone 到本地
	$ git clone git@github.com:xxx/TestProject.git

	// 写代码 ...

	// 提交代码变化到缓存区（-A 选项：包括修改、添加和删除）
	$ git add -A

	// 将缓存区内容提交到当前本地分支，并附上提交说明 "xxx"
	$ git commit -m "xxx"

	// 将代码提交到远程 main 分支
	$ git push origin main

## Pull requests

...

===========================================================================

## 合并到 main 分支（未完善...）
如果从克隆项目到本地到准备合并 a 分支的这个过程中都没有人提交过代码到 main 分支

那么可以在 GitHub 上发起 Pull requests 请求将 a 分支的代码合并到 main 分支

否则：
 
        // 将本地项目切换到 main 分支
        git checkout main

        // 将最新的远程 main 分支代码拉取到本地
        git pull origin main

        // 切换到本地 a 分支
        git checkout a

        // 将本地 main 分支合并到当前分支
        git merge main

        （如果合并过程有冲突，根据提示信息去查看冲突的代码，处理冲突，选择要保留的代码）

        // 合并完成后，将本地 a 分支提交到远程 a 分支
        git add -A
        git commit -m "xxx"
        git push origin a

然后可以在 Github 上发起 Pull requests 请求将 a 分支合并到 main 分支
