# TestProject

## Set user info
	git config --global user.name "your_name"
	git config --global user.email "your_email@xxx.xxx"

## 在分支 a 上开发模块 a
	// 克隆到本地
	git clone https://github.com/ilovesleeep/TestProject.git

	// 建立并切换到新分支 a
	git branch a
	git checkout a

	// 写代码 ...

	// 提交代码变化到缓存区（-A 选项：包括修改、添加和删除）
	git add -A

	// 将缓存区内容提交到当前本地分支，并附上提交说明 "xxx"
	git commit -m "xxx"

	// 将代码提交到远程 a 分支
	git push origin a

## 合并到 main 分支
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
